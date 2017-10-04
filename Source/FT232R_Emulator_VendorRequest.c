#include "FT232R_Emulator_VendorRequest.h"
#include "FT232R_Emulator.h"
#include "FT232R_Emulator_BSP.h"
#include "EEPROM_Emulator.h"

// -------------------------------------------------------------------------------------------------
// 40 00 00 00  00 00 00 00 : Reset UART
// 40 00 01 00  00 00 00 00 : Purge Rx Buffer Only
// 40 00 02 00  00 00 00 00 : Purge Tx Buffer Only
// Reset UART:
//  Sets flow control set to 'none'
//  Sets Event char = $0D
//  Sets Event trigger = disabled
//  Clear DTR
//  Clear RTS
//  Purge TX buffer
//  Purge RX buffer
//
//  baud and data format *NOT* reset
//
USBD_RequestStatus_TypeDef FT232R_Emulator_ResetRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  uint8_t wValuLow = USB_SETUP_PACKET_VALUE_LOW( setup_packet );
  if ( FT232R_RESET_SIO == wValuLow )
  {
    FT232R_Context.EventChar = 0x0D;
    FT232R_Context.EventCharEnabled = 0;

    FT232R_Context.FlowControl = FT232R_SET_FLOW_CTRL_NONE;
    FT232R_Emulator_BSP_SetFlowCtrl( &FT232R_Context );

    FT232R_Context.ModemControl =  // Mask and Value
      ( ( ( 1 << FT232R_SET_MODEM_CTRL_DTR ) | ( 1 << FT232R_SET_MODEM_CTRL_RTS ) ) << 8 )
        | ( ( ( 0 << FT232R_SET_MODEM_CTRL_DTR ) | ( 0 << FT232R_SET_MODEM_CTRL_RTS ) ) << 0 );
    FT232R_Emulator_BSP_SetModemCtrl( &FT232R_Context );
  }

  if ( ( FT232R_RESET_SIO == wValuLow ) || ( FT232R_RESET_RX == wValuLow ) )
    FT232R_Emulator_BSP_CancelReceive( &FT232R_Context );

  if ( ( FT232R_RESET_SIO == wValuLow ) || ( FT232R_RESET_TX == wValuLow ) )
    FT232R_Emulator_BSP_CancelTransmit( &FT232R_Context );

  return usbdRequestOK;
}

/*
 * ReqType -- ReqNum -- USBwValues.bw.bb0 -- USBwValues.bw.bb1
 * USBwIndexs.bw.bb0 -- USBwIndexs.bw.bb1 -- USBwLengths.bw.bb0 -- USBwLengths.bw.bb1
 *
 * bb0 is low byte, bb1 is high byte
 *
 * 40 01 00 01  00 00 00 00 : Clear DTR
 * 40 01 00 02  00 00 00 00 : Clear RTS
 *
 * If the device is in RTS/CTS flow control, the RTS set by this command will
 * be IGNORED without an error being returned.
 *
 * You can *NOT* set DTR and RTS with one control message
 *
 * wValue
 * B0    DTR state
 *          0 = reset
 *          1 = set
 * B1    RTS state
 *          0 = reset
 *          1 = set
 * B2..7 Reserved
 *
 * B8    DTR state enable
 *          0 = ignore
 *          1 = use DTR state
 * B9    RTS state enable
 *          0 = ignore
 *          1 = use RTS state
 * B10..15 Reserved
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetModemCtrlRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  if ( ( FT232R_SET_FLOW_CTRL_RTSCTS == FT232R_Context.FlowControl )
    && ( USB_SETUP_PACKET_VALUE_LOW( setup_packet ) & ( 1 << FT232R_SET_MODEM_CTRL_RTS ) ) )
    return usbdRequestOK;

  FT232R_Context.ModemControl = setup_packet->wValue;
  FT232R_Emulator_BSP_SetModemCtrl( &FT232R_Context );
  return usbdRequestOK;
}

/*
 * BmRequestType:  0100 0000b -----------------> 0x40
 * bRequest:       FT232R_SIO_SET_FLOW_CTRL -----> 0x02
 * wValue:         Xoff/Xon
 * wIndex:         Protocol/Port - wIndexH is protocol / wIndexL is port
 * wLength:        0
 * Data:           None
 *
 * wIndexH protocol is:
 *   B0 Output handshaking using RTS/CTS
 *       0 = disabled
 *       1 = enabled
 *   B1 Output handshaking using DTR/DSR
 *       0 = disabled
 *       1 = enabled
 *   B2 Xon/Xoff handshaking
 *       0 = disabled
 *       1 = enabled
 *
 * A value of zero in the wIndexH field disables handshaking
 *
 * If Xon/Xoff handshaking is specified,
 * the hValue field should contain the XOFF character
 * and the lValue field contains the XON character.
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetFlowCtrlRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  FT232R_Context.FlowControl = USB_SETUP_PACKET_INDEX_HIGH( setup_packet );
  FT232R_Context.FlowControlXON = USB_SETUP_PACKET_VALUE_LOW( setup_packet );
  FT232R_Context.FlowControlXOFF = USB_SETUP_PACKET_VALUE_HIGH( setup_packet );
  FT232R_Emulator_BSP_SetFlowCtrl( &FT232R_Context );
  return usbdRequestOK;
}

/*
 * FT8U232AM
 *
 *  Clock = 3MHz
 *  {              wIndex[7:0] } : Port
 *  {             wValue[13:0] } : BaudRateDivisorMantissa
 *  {            wValue[15:14] } : BaudRateDivisorFraction
 *                               : 0.000, 0.500, 0.250, 0.125
 *                               : 00     01     10     11
 *
 * FT232BM and FT232R : 3000000 / 2.875 = 1043478 : 40 03 : 02 C0 : 01 00 : 00 00
 *
 *  Clock = 3MHz               0 : Port
 *  {             wValue[13:0] } : BaudRateDivisorMantissa
 *  { wIndex[0], wValue[15:14] } : BaudRateDivisorFraction
 *                               : 0.000, 0.125, 0.250, 0.375, 0.500, 0.625, 0.750, 0.875
 *                               : 000    001    010    011    100    101    110    111
 * FT2232C, FT2232D and FT2232L
 *
 *  Clock = 3MHz
 *  {              wIndex[7:0] } : Port
 *  {             wValue[13:0] } : BaudRateDivisorMantissa
 *  { wIndex[8], wValue[15:14] } : BaudRateDivisorFraction
 *                               : 0.000, 0.125, 0.250, 0.375, 0.500, 0.625, 0.750, 0.875
 *                               : 000    001    010    011    100    101    110    111
 * clk/1   <-> 0 <-> 3.0 MBaud
 * clk/1.5 <-> 1 <-> 2.0 MBaud
 * clk/2   <-> 2 <-> 1.5 MBaud
 *
 * FT2232H, FT4232H and FT232H
 *
 *  {              wIndex[7:0] } : Port
 *  {                wIndex[9] } : 0 - 3MHz Clock, 1 = 12MHz Clock
 *  {             wValue[13:0] } : BaudRateDivisorMantissa
 *  { wIndex[8], wValue[15:14] } : BaudRateDivisorFraction
 *                               : 0.000, 0.125, 0.250, 0.375, 0.500, 0.625, 0.750, 0.875
 *                               : 000    001    010    011    100    101    110    111
 *
 * The FT2232H does not support the baud rates of 7 Mbaud 9 Mbaud 10 Mbaud and 11 Mbaud.
 * Support the baud rates of 3 Mbaud 4 Mbaud 6 Mbaud 8 Mbaud 12 Mbaud
 *
 * 000 - add .000 to divisor
 * 001 - add .500 to divisor
 * 010 - add .250 to divisor
 * 011 - add .125 to divisor
 * 100 - add .375 to divisor
 * 101 - add .625 to divisor
 * 110 - add .750 to divisor
 * 111 - add .875 to divisor
 *
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetBaudrateRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  float DivisorFraction, Clock;
  uint32_t DivisorMantissa, FractionIndex;

  const float table[ 8 ] = {
    0.0, 0.5, 0.25, 0.125, 0.375, 0.625, 0.75, 0.875 };

  Clock = 3000000;
  DivisorMantissa = setup_packet->wValue & 0x3FFF;
  FractionIndex = setup_packet->wValue >> 14;
  if ( USB_SETUP_PACKET_INDEX_LOW( setup_packet ) & ( 1 << 0 ) )
    FractionIndex |= ( 1 << 2 );

  DivisorFraction = table[ FractionIndex ];
  FT232R_Context.BaudRate = (uint32_t) ( Clock / ( DivisorMantissa + DivisorFraction ) );
  FT232R_Emulator_BSP_SetBaudrate( &FT232R_Context );

  return usbdRequestOK;
}

/*
 * BmRequestType:  0100 0000B ----------> 0x40
 * bRequest:       FT232R_SIO_SET_DATA ---> 0x04
 * wValue:         Data characteristics (see below)
 * wIndex:         Port
 * wLength:        0
 * Data:           No
 *
 * Data characteristics
 *
 *   B0..7   Number of data bits < 7 or 8 >
 *   B8..10  Parity
 *           0 = None
 *           1 = Odd
 *           2 = Even
 *           3 = Mark
 *           4 = Space
 *   B11..13 Stop Bits
 *           0 = 1
 *           1 = 1.5
 *           2 = 2
 *   B14
 *           1 = TX ON (break)
 *           0 = TX OFF (normal state)
 *   B15 Reserved
 *
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetLineCodingRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  FT232R_Context.LineCoding = setup_packet->wValue;
  FT232R_Emulator_BSP_SetLineCoding( &FT232R_Context );
  return usbdRequestOK;
}

/*
 * Get the current values of the modem and line status registers.
 *
 * C0 05 00 00 00 00 01 00 -- ModemSatus : 01
 * C0 05 00 00 00 00 02 00 -- ModemSatus and LineStatus : 01 60
 *
 * Byte 0: Modem Status
 *
 * Offset Description
 * B0 Reserved - must be 1 ------------------------ 1
 * B1 Reserved - must be 0 ------------------------ 0
 * B2 Reserved - must be 0 ------------------------ 0
 * B3 Reserved - must be 0 ------------------------ 0
 * B4 Clear to Send (CTS) ------------------------- 0
 * B5 Data Set Ready (DSR) ------------------------ 0
 * B6 Ring Indicator (RI) ------------------------- 0
 * B7 Receive Line Signal Detect (RLSD) ----------- 0
 *
 * Byte 1: Line Status
 *
 * Offset Description
 * B0 Data Ready (Receive RDR) -------------------- 0
 * B1 Overrun Error (Receive OE) ------------------ 0
 * B2 Parity Error (Receive PE) ------------------- 0
 * B3 Framing Error (Receive FE) ------------------ 0
 * B4 Break Interrupt (Receive Break BI) ---------- 0
 * B5 Transmitter Holding Register (THRE) --------- 1
 * B6 Transmitter Empty (TEMT) -------------------- 1
 * B7 Error in RCVR FIFO -------------------------- 0
 *
 * 01 60 --> 0x6001 --> 0110 0000 0000 0001
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_GetModemStatusRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  FT232R_Emulator_BSP_GetModemLineStatus( &FT232R_Context );
  *len = ( setup_packet->wLength > 2 ) ? 2 : setup_packet->wLength;
  *buf = &FT232R_Context.ModemStatus;

  return usbdRequestOK;
}

/*
 * Set the special event character for the specified communications port.
 * If the device sees this character it will immediately return the data read so far -
 * rather than wait 16ms or until 62 bytes are read which is what normally happens.
 *
 *  BmRequestType:   0100 0000b ---------------> 0x40
 *  bRequest:        FT232R_SIO_SET_EVENT_CHAR --> 0x06
 *  wValue:          EventChar
 *  wIndex:          Port
 *  wLength:         0
 *  Data:            None
 *
 * wValue:
 *   B0..7   Event Character
 *   B8      Event Character Processing
 *             0 = disabled
 *             1 = enabled
 *   B9..15  Reserved
 *
 * MS LS XX YY ZZ EVT ---> write FIFO to send
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetEventCharRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  FT232R_Context.EventChar = USB_SETUP_PACKET_VALUE_LOW( setup_packet );
  FT232R_Context.EventCharEnabled = USB_SETUP_PACKET_VALUE_HIGH( setup_packet ) & 1;
  return usbdRequestOK;
}

/*
 * Set the parity error replacement character for the specified communications
 *
 *  BmRequestType:  0100 0000b ----------------> 0x40
 *  bRequest:       FT232R_SIO_SET_EVENT_CHAR ---> 0x07
 *  wValue:         Error Char
 *  wIndex:         Port
 *  wLength:        0
 *  Data:           None
 *
 *Error Char
 *  B0..7  Error Character
 *  B8     Error Character Processing
 *           0 = disabled
 *           1 = enabled
 *  B9..15 Reserved
 *
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetErrorCharRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  FT232R_Context.ErrorChar = USB_SETUP_PACKET_VALUE_LOW( setup_packet );
  FT232R_Context.ErrorCharEnabled = USB_SETUP_PACKET_VALUE_HIGH( setup_packet ) & 1;
  return usbdRequestOK;
}

/*
 * Set the timeout interval.
 * The FTDI collects data from the slave device, transmitting it to the host when either
 *
 * A) 62 bytes are received, or
 * B) the timeout interval has elapsed and the buffer contains at least 1 byte.
 *
 * Setting this value to a small number can dramatically improve performance
 * for applications which send small packets, since the default value is 16ms.
 *
 *  BmRequestType:   0100 0000b -------------------> 0x40
 *  bRequest:        FT232R_SIO_SET_LATENCY_TIMER ---> 0x09
 *  wValue:          Latency (milliseconds)
 *  wIndex:          Port
 *  wLength:         0
 *  Data:            None
 *
 * wValue:
 *   B0..7   Latency timer
 *   B8..15  0
 *
 */
USBD_RequestStatus_TypeDef FT232R_Emulator_SetLatencyTimerRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  FT232R_Context.LatencyTimerValue = USB_SETUP_PACKET_VALUE_LOW( setup_packet );
  return usbdRequestOK;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_GetLatencyTimerRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  *len = 1;
  *buf = &FT232R_Context.LatencyTimerValue;
  return usbdRequestOK;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_SetBitModeRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  return usbdRequestOK;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_ReadPinsRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  return usbdRequestOK;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_EraseEepromRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  return usbdRequestOK;
}

// c0 90 00 00  5f 00 02 00
USBD_RequestStatus_TypeDef FT232R_Emulator_ReadEepormRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  uint16_t Addr = setup_packet->wIndex;

  if ( Addr >= ( 0xA0 >> 1 ) )
  {
    FT232R_Emulator_DummyData = 0xFFFF;
  }
  else if ( Addr >= ( 0x80 >> 1 ) )
  {
    Addr -= ( 0x80 >> 1 );
    FT232R_Emulator_DummyData = *( (uint16_t *) &FT232R_Emulator_ChipId[ Addr << 1 ] );
  }
  else
  {
    EEPROM_ReadWord( Addr << 1, (uint16_t*) &FT232R_Emulator_DummyData );
  }

  *len = 2;
  *buf = (uint8_t*) &FT232R_Emulator_DummyData;
  return usbdRequestOK;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_WriteEepromRequest( USB_SetupPacket_TypeDef *setup_packet, uint8_t **buf,
  uint16_t *len )
{
  uint16_t Addr = setup_packet->wIndex;
  uint16_t Data = setup_packet->wValue;

  if ( EEPROM_SUCCESS == EEPROM_WriteWord( Addr << 1, Data ) )
    return usbdRequestOK;

  return usbdRequestStall;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_Endpoint0_SetupPacketReceived( USB_SetupPacket_TypeDef *setup_packet,
  uint8_t **buf, uint16_t *len )
{
  USBD_RequestStatus_TypeDef RetValue = usbdRequestNotProcessed;
  if ( setup_packet->bmRequestType.Type != USB_REQUEST_VENDOR )
    return RetValue;

  *buf = 0;
  *len = 0;

  uint8_t RequestNo = setup_packet->bRequest;
  switch ( RequestNo )
  {
    case FT232R_RESET_REQUEST:
      RetValue = FT232R_Emulator_ResetRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_MODEM_CTRL_REQUEST:
      RetValue = FT232R_Emulator_SetModemCtrlRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_FLOW_CTRL_REQUEST:
      RetValue = FT232R_Emulator_SetFlowCtrlRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_BAUDRATE_REQUEST:
      RetValue = FT232R_Emulator_SetBaudrateRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_LINE_CODING_REQUEST:
      RetValue = FT232R_Emulator_SetLineCodingRequest( setup_packet, buf, len );
      break;
    case FT232R_GET_MODEM_STATUS_REQUEST:
      RetValue = FT232R_Emulator_GetModemStatusRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_EVENT_CHAR_REQUEST:
      RetValue = FT232R_Emulator_SetEventCharRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_ERROR_CHAR_REQUEST:
      RetValue = FT232R_Emulator_SetErrorCharRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_LATENCY_TIMER_REQUEST:
      RetValue = FT232R_Emulator_SetLatencyTimerRequest( setup_packet, buf, len );
      break;
    case FT232R_GET_LATENCY_TIMER_REQUEST:
      RetValue = FT232R_Emulator_GetLatencyTimerRequest( setup_packet, buf, len );
      break;
    case FT232R_SET_BITMODE_REQUEST:
      RetValue = FT232R_Emulator_SetBitModeRequest( setup_packet, buf, len );
      break;
    case FT232R_READ_PINS_REQUEST:
      RetValue = FT232R_Emulator_ReadPinsRequest( setup_packet, buf, len );
      break;
    case FT232R_READ_EEPROM_REQUEST:
      RetValue = FT232R_Emulator_ReadEepormRequest( setup_packet, buf, len );
      break;
    case FT232R_WRITE_EEPROM_REQUEST:
      RetValue = FT232R_Emulator_WriteEepromRequest( setup_packet, buf, len );
      break;
    case FT232R_ERASE_EEPROM_REQUEST:
      RetValue = FT232R_Emulator_EraseEepromRequest( setup_packet, buf, len );
      break;
    default:
      break;
  }

  return RetValue;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_Endpoint0_OutDataReceived( uint32_t len )
{
  return usbdRequestOK;
}

USBD_RequestStatus_TypeDef FT232R_Emulator_Endpoint0_InDataSent( uint32_t len )
{
  return usbdRequestOK;
}
