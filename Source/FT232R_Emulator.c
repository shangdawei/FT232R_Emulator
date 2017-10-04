#include "FT232R_Emulator.h"
#include "FT232R_Emulator_Type.h"
#include "FT232R_Emulator_Conf.h"
#include "FT232R_Emulator_BSP.h"
#include "FT232R_Emulator_Eeprom.h"
#include "FT232R_Emulator_Descriptor.h"
#include "FT232R_Emulator_VendorRequest.h"

#include "EEPROM_Emulator.h"

WORD FT232R_Emulator_DummyData = 0xFFFF;

const UCHAR FT232R_Emulator_ChipId[ 32 ] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, };

const UCHAR FT232R_Emulator_Eeprom[ FT232R_EMULATOR_EEPROM_SIZE ] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    //
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, };

static const EEPROM_Configuration_TypeDef EEPROM_Configuration = {
  FT232R_EMULATOR_EEPROM_FLASH_BASE_ADDR,     //
  FT232R_EMULATOR_EEPROM_FLASH_PAGE_COUNT,    //
  FT232R_EMULATOR_EEPROM_FLASH_PAGE_SIZE,     //
  FT232R_EMULATOR_EEPROM_SIZE };

static uint8_t EEPROM_Cache[ FT232R_EMULATOR_EEPROM_SIZE ];

void FT232R_Emulator_Initialize( void );
void FT232R_Emulator_Uninitialize( void );
void FT232R_Emulator_EventReset( void );
void FT232R_Emulator_EventSOF( void );
void FT232R_Emulator_EventEndpoint( uint8_t ep_addr, uint32_t event );
void FT232R_Emulator_EventConfigured( uint8_t index );

const USBD_ClassCallbacks_TypeDef FT232R_Emulator_ClassCallbacks = {
  0 };

const USBD_DeviceCallbacks_TypeDef FT232R_Emulator_DeviceCallbacks = {
  .USBD_Device_StringDescriptor = FT232R_Emulator_StringDescriptor,  //
  .USBD_Device_Initialize = FT232R_Emulator_Initialize,  //
  .USBD_Device_Uninitialize = FT232R_Emulator_Uninitialize,  //
  .USBD_Device_EventReset = FT232R_Emulator_EventReset,  //
  .USBD_Device_EventConfigured = FT232R_Emulator_EventConfigured,  //
  .USBD_Device_EventSOF = FT232R_Emulator_EventSOF,  //
  .USBD_Device_EventEndpoint = FT232R_Emulator_EventEndpoint,  //
  .USBD_Device_Endpoint0_SetupPacketReceived = FT232R_Emulator_Endpoint0_SetupPacketReceived,  //
  .USBD_Device_Endpoint0_InDataSent = FT232R_Emulator_Endpoint0_InDataSent,  //
  .USBD_Device_Endpoint0_OutDataReceived = FT232R_Emulator_Endpoint0_OutDataReceived,  //
  };

USBD_Class_TypeDef FT232R_Emulator_Class = {
  &FT232R_Emulator_ClassCallbacks, 0, 0 };

USBD_Class_TypeDef * FT232R_Emulator_Classes[ ] = {
  &FT232R_Emulator_Class, 0 };

USBD_Device_TypeDef FT232R_Emulator_Device = {
  &FT232R_Emulator_DeviceCallbacks,   //
  &FT232R_Emulator_Descriptor,        //
  &FT232R_Emulator_Classes[ 0 ], };

USBD_Device_TypeDef * USBD_Device = &FT232R_Emulator_Device;

FT232R_Property_TypeDef FT232R_Property;
FT232R_Context_TypeDef FT232R_Context;

static void Halt( void )
{
  for ( ;; )
    ;
}

void FT232R_Emulator_BuildProperty( FT232R_Property_TypeDef * FT232R_Property )
{
  USB_DEVICE_DESCRIPTOR * DeviceDescriptor = (USB_DEVICE_DESCRIPTOR *) &FT232R_Emulator_DeviceDescriptor;
  USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptor =
    (USB_CONFIGURATION_DESCRIPTOR *) FT232R_Emulator_ConfigurationDescriptor;

  DeviceDescriptor->bcdUSB = FT232R_Property->USBVersion;
  DeviceDescriptor->idVendor = FT232R_Property->VendorID;
  DeviceDescriptor->idProduct = FT232R_Property->ProductID;
  DeviceDescriptor->bcdDevice = FT232R_Property->bcdDevice;

  // DeviceDescriptor->bMaxPacketSize0 = FT232R_EMULATOR_ENDPOINT0_SIZE;

  EEPROM_ReadBytes( FT232R_Property->ManufactureStrAddr, FT232R_Property->ManufactureStrSize,
    FT232R_Emulator_StringManufacturer );

  EEPROM_ReadBytes( FT232R_Property->ProductStrAddr, FT232R_Property->ProductStrSize, FT232R_Emulator_StringProduct );

  DeviceDescriptor->iSerialNumber = 0;
  if ( FT232R_Property->SerNumEnable && FT232R_Property->SerialNumberStrSize )
  {
    DeviceDescriptor->iSerialNumber = 3;
    EEPROM_ReadBytes( FT232R_Property->SerialNumberStrAddr, FT232R_Property->SerialNumberStrSize,
      FT232R_Emulator_StringSerialNumber );
  }

  // ConfigurationDescriptor->wTotalLength = 32;
  // ConfigurationDescriptor->bNumInterfaces = 1;

  // ConfigurationDescriptor->bmAttributes = 0x80;
  if ( FT232R_Property->SelfPowered )
  {
    ConfigurationDescriptor->bmAttributes |= 0x40;    // Self Powered
    ConfigurationDescriptor->bMaxPower = 0;
  }

  if ( 1 == FT232R_Property->RemoteWakeup )
    ConfigurationDescriptor->bmAttributes |= 0x20;    // Remote Wakeup

  ConfigurationDescriptor->bMaxPower = FT232R_Property->MaxPower;
}

// Receive 1..N bytes before Timeout < LatencyTimerValue >
void FT232R_Emulator_OnRxCompleted( FT232R_Context_TypeDef * FT232R_Context )
{
  FT232R_Context->RxCompleted = 1;
}

void FT232R_Emulator_Transmit( FT232R_Context_TypeDef * FT232R_Context )
{
  uint32_t Transferred = FT232R_Emulator_BSP_Transmit( FT232R_Context,
    FT232R_Context->OutEndpBuffer + FT232R_Context->OutEndpBufferOffset, FT232R_Context->OutEndpBufferRemaining );
  FT232R_Context->OutEndpBufferOffset += Transferred;
  FT232R_Context->OutEndpBufferRemaining -= Transferred;
  if ( 0 == FT232R_Context->OutEndpBufferRemaining )
    USBD_EndpointRead( 0, FT232R_EMULATOR_OUT_ENDPOINT_ADDR, FT232R_Context->OutEndpBuffer,
    FT232R_EMULATOR_ENDPOINT_SIZE );
}

void FT232R_Emulator_OnTxCompleted( FT232R_Context_TypeDef * FT232R_Context )
{
  if ( FT232R_Context->OutEndpBufferRemaining )
    FT232R_Emulator_Transmit( FT232R_Context );
}

void FT232R_Emulator_BuildContext( FT232R_Context_TypeDef * FT232R_Context )
{
  FT232R_Context->InEndpoint = FT232R_EMULATOR_IN_ENDPOINT_ADDR;
  FT232R_Context->OutEndpoint = FT232R_EMULATOR_OUT_ENDPOINT_ADDR;
  FT232R_Context->InEndpointSize = FT232R_EMULATOR_ENDPOINT_SIZE;
  FT232R_Context->OutEndpointSize = FT232R_EMULATOR_ENDPOINT_SIZE;
  FT232R_Context->OnRxCompleted = FT232R_Emulator_OnRxCompleted;
  FT232R_Context->OnTxCompleted = FT232R_Emulator_OnTxCompleted;

  FT232R_Context->LatencyTimerValue = 16;
  FT232R_Context->LatencyTimerCount = 0;
  FT232R_Context->EventChar = 0x0D;
  FT232R_Context->ErrorChar = 0x00;

  FT232R_Context->BaudRate = 9600;
  FT232R_Context->FlowControl = FT232R_SET_FLOW_CTRL_NONE;
  FT232R_Context->LineCoding = FT232R_SET_LINE_DATA_BITS_8 | FT232R_SET_LINE_STOP_BITS_1 | FT232R_SET_LINE_PARITY_NONE;
}

void FT232R_Emulator_Initialize( void )
{
  int32_t RetValue;

  RetValue = EEPROM_Init( &EEPROM_Emulator_Driver, &EEPROM_Configuration, EEPROM_Cache );
  if ( EEPROM_VIRGIN == RetValue )
    RetValue = EEPROM_Format( (uint8_t *) FT232R_Emulator_Eeprom, sizeof( FT232R_Emulator_Eeprom ) );

  if ( EEPROM_SUCCESS == RetValue )
  {
    RetValue = FT232R_Emulator_EepromDecode( &FT232R_Property );
    if ( EEPROM_SUCCESS == RetValue )
    {
      FT232R_Emulator_BuildProperty( &FT232R_Property );
      FT232R_Emulator_BuildContext( &FT232R_Context );

      FT232R_Emulator_BSP_Init( &FT232R_Context );

      FT232R_Context.BaudRate = 9600;
      FT232R_Emulator_BSP_SetBaudrate( &FT232R_Context );

      FT232R_Context.FlowControl = FT232R_SET_FLOW_CTRL_NONE;
      FT232R_Emulator_BSP_SetFlowCtrl( &FT232R_Context );

      FT232R_Context.LineCoding = FT232R_SET_LINE_DATA_BITS_8 | FT232R_SET_LINE_STOP_BITS_1 | FT232R_SET_LINE_PARITY_NONE;
      FT232R_Emulator_BSP_SetLineCoding( &FT232R_Context );
    }
  }

  if ( EEPROM_SUCCESS != RetValue )
    Halt( );
}

void FT232R_Emulator_Uninitialize( void )
{
  FT232R_Emulator_BSP_Uninit( &FT232R_Context );
}

void FT232R_Emulator_EventReset( void )
{
}

void FT232R_Emulator_EventSOF( void )
{
  if ( USBD_Configured( 0 ) )
  {
    if ( FT232R_Context.LatencyTimerCount < FT232R_Context.LatencyTimerValue )
      FT232R_Context.LatencyTimerCount++;

    if ( FT232R_Context.LatencyTimerCount == FT232R_Context.LatencyTimerValue )
      FT232R_Context.LatencyTimerCount = 0;
  }
}

// index == 0 : Clear Configuration
// index != 0 : Select Configuration
void FT232R_Emulator_EventConfigured( uint8_t index )
{
  if ( 0 == index )
  {
    USBD_EndpointUnconfigure( 0, FT232R_EMULATOR_IN_ENDPOINT_ADDR );
    USBD_EndpointUnconfigure( 0, FT232R_EMULATOR_OUT_ENDPOINT_ADDR );
  }
  else
  {
    USBD_EndpointConfigure( 0, FT232R_EMULATOR_IN_ENDPOINT_ADDR, FT232R_EMULATOR_ENDPOINT_SIZE,
    USB_ENDPOINT_TYPE_BULK );

    /* Ready to Send ModemStatus and LineStatus */
    FT232R_Emulator_EventEndpoint( FT232R_EMULATOR_IN_ENDPOINT_ADDR, ARM_USBD_EVENT_IN );

    USBD_EndpointConfigure( 0, FT232R_EMULATOR_OUT_ENDPOINT_ADDR, FT232R_EMULATOR_ENDPOINT_SIZE,
    USB_ENDPOINT_TYPE_BULK );

    /* Prepare Out endpoint to receive next packet */
    USBD_EndpointRead( 0, FT232R_EMULATOR_OUT_ENDPOINT_ADDR, FT232R_Context.OutEndpBuffer,
    FT232R_EMULATOR_ENDPOINT_SIZE );
  }
}

void FT232R_Emulator_EventEndpoint( uint8_t ep_addr, uint32_t event )
{
  int32_t USB_ReceiveCount;
  int32_t UART_ReceiveCount;
  if ( ep_addr == FT232R_EMULATOR_IN_ENDPOINT_ADDR )              // ARM_USBD_EVENT_IN
  {
    /* B0 Reserved - must be 1
     * B1 Reserved - must be 0
     * B2 Reserved - must be 0
     * B3 Reserved - must be 0
     * B4 Clear to Send (CTS)
     * B5 Data Set Ready (DSR)
     * B6 Ring Indicator (RI)
     * B7 Receive Line Signal Detect (RLSD)
     *
     * B0 Data Ready (Receive RDR)
     * B1 Overrun Error (Receive OE)
     * B2 Parity Error (Receive PE)
     * B3 Framing Error (Receive FE)
     * B4 Break Interrupt (Receive Break BI)
     * B5 Transmitter Holding Register (THRE)
     * B6 Transmitter Empty (TEMT)
     *
     * B7 Error in RCVR FIFO
     */
    FT232R_Emulator_BSP_GetModemLineStatus( &FT232R_Context );
    FT232R_Context.InEndpBuffer[ 0 ] = FT232R_Context.ModemStatus;
    FT232R_Context.InEndpBuffer[ 1 ] = FT232R_Context.LineStatus;

    UART_ReceiveCount = FT232R_Emulator_BSP_Receive( &FT232R_Context, &FT232R_Context.InEndpBuffer[ 2 ],
    FT232R_EMULATOR_ENDPOINT_SIZE - 2 );

    USBD_EndpointWrite( 0, FT232R_EMULATOR_IN_ENDPOINT_ADDR, FT232R_Context.InEndpBuffer, 2 + UART_ReceiveCount );
  }
  else if ( ep_addr == FT232R_EMULATOR_OUT_ENDPOINT_ADDR )        // ARM_USBD_EVENT_OUT
  {
    USB_ReceiveCount = USBD_EndpointReadGetResult( 0, FT232R_EMULATOR_OUT_ENDPOINT_ADDR );
    FT232R_Context.OutEndpBufferOffset = 0;
    FT232R_Context.OutEndpBufferRemaining = USB_ReceiveCount;
    FT232R_Emulator_Transmit( &FT232R_Context );
  }
}
