#ifndef __FT232R_EMULATOR_TYPE_H__
#define __FT232R_EMULATOR_TYPE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#define FT232R_INVERT_TXD                 ( 0x01 )
#define FT232R_INVERT_RXD                 ( 0x02 )
#define FT232R_INVERT_RTS                 ( 0x04 )
#define FT232R_INVERT_CTS                 ( 0x08 )
#define FT232R_INVERT_DTR                 ( 0x10 )
#define FT232R_INVERT_DSR                 ( 0x20 )
#define FT232R_INVERT_DCD                 ( 0x40 )
#define FT232R_INVERT_RI                  ( 0x80 )

#define FT232R_FUNCTION_MASK07            ( 0x07 )
#define FT232R_FUNCTION_MASK0F            ( 0x0F )
//
#define FT232R_FUNCTION_232_UART          ( 0x00 )
#define FT232R_FUNCTION_245_FIFO          ( 0x01 )
#define FT232R_FUNCTION_OPTO              ( 0x02 )
#define FT232R_FUNCTION_CPU_FIFO          ( 0x04 )

#define FT232R_USES_EXT_OSC               ( 0x02 )
#define FT232R_HIGH_CURRENT_DRIVE         ( 0x04 )
#define FT232R_DRIVER_VCP                 ( 0x08 )

/* Requests */
#define FT232R_RESET_REQUEST              0x00    /* Reset the port */
#define FT232R_SET_MODEM_CTRL_REQUEST     0x01    /* Set the modem control register */
#define FT232R_SET_FLOW_CTRL_REQUEST      0x02    /* Set flow control register */
#define FT232R_SET_BAUDRATE_REQUEST       0x03    /* Set baud rate */
#define FT232R_SET_LINE_CODING_REQUEST    0x04    /* Set the data characteristics of the port */
#define FT232R_GET_MODEM_STATUS_REQUEST   0x05
#define FT232R_SET_EVENT_CHAR_REQUEST     0x06
#define FT232R_SET_ERROR_CHAR_REQUEST     0x07
#define FT232R_SET_LATENCY_TIMER_REQUEST  0x09
#define FT232R_GET_LATENCY_TIMER_REQUEST  0x0A

#define FT232R_SET_BITMODE_REQUEST        0x0B
#define FT232R_READ_PINS_REQUEST          0x0C
#define FT232R_READ_EEPROM_REQUEST        0x90
#define FT232R_WRITE_EEPROM_REQUEST       0x91
#define FT232R_ERASE_EEPROM_REQUEST       0x92

#define FT232R_LAST_REQUEST               ( 0xFF )

#define FT232R_RESET_SIO                  0x00    /* Reset the device */
#define FT232R_RESET_RX                   0x01    /* Reset Rx Buffer */
#define FT232R_RESET_TX                   0x02    /* Reset Tx Buffer */

#define FT232R_SET_MODEM_CTRL_DTR         0x01    /* Mask <wValueH> and State <wValueL> */
#define FT232R_SET_MODEM_CTRL_RTS         0x02    /* Mask <wValueH> and State <wValueL> */

#define FT232R_SET_FLOW_CTRL_NONE         0x00    /* Set flow control NONE */
#define FT232R_SET_FLOW_CTRL_RTSCTS       0x01    /* Set flow control RTS/CTS  <wIndexH> */
#define FT232R_SET_FLOW_CTRL_DTRDSR       0x02    /* Set flow control DTR/DSR  <wIndexH> */
#define FT232R_SET_FLOW_CTRL_XONXOFF      0x04    /* Set flow control XON/XOFF <wIndexH> :: XON/XOFF : wValueH/wValueL */

#define FT232R_SET_BAUDRATE_DIVISOR       0x3FFF  /* Set baud rate : Divisor[13..0] <wValue[13..0]> */
#define FT232R_SET_BAUDRATE_FRACTIONAL_L  0xC000  /* Set baud rate : Fractional[1..0] <wValue[15..14]> */
#define FT232R_SET_BAUDRATE_FRACTIONAL_H  0x0100  /* Set baud rate : Fractional[2] <wIndex[8]> */
#define FT232R_SET_BAUDRATE_CLOCK_12MHZ   0x0200  /* Set baud rate : Clock 12MHz <wIndex[9]> */

#define FT232R_SET_LINE_DATA_BITS_MASK    0x00FF  /* Set the data characteristics Data Bits : <wValue[7..0]> */
#define FT232R_SET_LINE_DATA_BITS_6       0x0006
#define FT232R_SET_LINE_DATA_BITS_7       0x0007
#define FT232R_SET_LINE_DATA_BITS_8       0x0008
#define FT232R_SET_LINE_DATA_BITS_9       0x0009

#define FT232R_SET_LINE_PARITY_MASK       0x0700  /* Set the data characteristics Parity Bits : <wValue[10..8]> */
#define FT232R_SET_LINE_PARITY_NONE       0x0000
#define FT232R_SET_LINE_PARITY_ODD        0x0100
#define FT232R_SET_LINE_PARITY_EVEN       0x0200
#define FT232R_SET_LINE_PARITY_MARK       0x0300
#define FT232R_SET_LINE_PARITY_SPACE      0x0400

#define FT232R_SET_LINE_STOP_BITS_MASK    0x3800  /* Set the data characteristics Stop Bits : <wValue[13..11]> */
#define FT232R_SET_LINE_STOP_BITS_1       0x0000
#define FT232R_SET_LINE_STOP_BITS_1_5     0x0800
#define FT232R_SET_LINE_STOP_BITS_2       0x1800

#define FT232R_SET_LINE_BREAK_MASK        0x4000  /* Set the data characteristics Break : <wValue[14]> */
#define FT232R_SET_LINE_BREAK_OFF         0x0000  /* 0 = Inactive, 1 = Active */
#define FT232R_SET_LINE_BREAK_ON          0x4000  /* 0 = Inactive, 1 = Active */

#define FT232R_GET_MODEM_STATUS_CTS       0x10    /* 0 = Inactive, 1 = Active */
#define FT232R_GET_MODEM_STATUS_DSR       0x20    /* 0 = Inactive, 1 = Active */
#define FT232R_GET_MODEM_STATUS_RI        0x40    /* 0 = Inactive, 1 = Active */
#define FT232R_GET_MODEM_STATUS_DCD       0x80    /* 0 = Inactive, 1 = Active */

// Set the special event character for the specified communications port
// If the device sees this character it will immediately return the data read so far
// rather than wait 40ms or until 62 bytes are read which is what normally happens.
#define FT232R_SET_EVENT_CHAR_VALUE       0x00FF  /* wValue<7..0> */
#define FT232R_SET_EVENT_CHAR_MASK        0x0100  /* wValue<8> 0 = Disabled, 1 = Enabled */

// Set the parity error replacement character for the specified communications
#define FT232R_SET_ERROR_CHAR_VALUE       0x00FF  /* wValue<7..0> */
#define FT232R_SET_ERROR_CHAR_MASK        0x0100  /* wValue<8> 0 = Disabled, 1 = Enabled */

/* switch off bitbang mode, back to regular serial/FIFO */
#define FT232R_SET_BITMODE_RESET          0x00

/* classical asynchronous bitbang mode, introduced with B-type chips */
#define FT232R_SET_BITMODE_BITBANG        0x01

/* MPSSE mode, available on 2232x chips */
#define FT232R_SET_BITMODE_MPSSE          0x02

/* synchronous bitbang mode, available on 2232x and R-type chips  */
#define FT232R_SET_BITMODE_SYNCBB         0x04

/* MCU Host Bus Emulation mode, available on 2232x chips, CPU-style fifo mode gets set via EEPROM */
#define FT232R_SET_BITMODE_MCU            0x08

/* Fast Opto-Isolated Serial Interface Mode, available on 2232x chips  */
#define FT232R_SET_BITMODE_OPTO           0x10

/* Bitbang on CBUS pins of R-type chips, configure in EEPROM before */
#define FT232R_SET_BITMODE_CBUS           0x20

/* Single Channel Synchronous FIFO mode, available on 2232H chips */
#define FT232R_SET_BITMODE_SYNCFF         0x40

/* FT1284 mode, available on 232H chips */
#define FT232R_SET_BITMODE_FT1284         0x80

#define FT232R_MODEM_STATUS_CTS           0x10    /* 0 = Inactive, 1 = Active */
#define FT232R_MODEM_STATUS_DSR           0x20    /* 0 = Inactive, 1 = Active */
#define FT232R_MODEM_STATUS_RI            0x40    /* 0 = Inactive, 1 = Active */
#define FT232R_MODEM_STATUS_RLSD          0x80    /* 0 = Inactive, 1 = Active */

#define FT232R_LINE_STATUS_DR             0x01    /* Data Ready (Receive RDR) */
#define FT232R_LINE_STATUS_OE             0x02    /* Overrun Error (Receive OE) */
#define FT232R_LINE_STATUS_PE             0x04    /* Parity Error (Receive PE) */
#define FT232R_LINE_STATUS_FE             0x08    /* Framing Error (Receive FE) */
#define FT232R_LINE_STATUS_BI             0x10    /* Break Interrupt (Receive Break BI) */
#define FT232R_LINE_STATUS_THRE           0x20    /* Transmitter Holding Register (THRE) */
#define FT232R_LINE_STATUS_TEMT           0x40    /* Transmitter Empty (TEMT) */
#define FT232R_LINE_STATUS_RXFIFO         0x80    /* Error in RCVR FIFO */

typedef enum
{
  FTDI_DEVICE_UNKNOWN = 0UL,            // bcdDevice = 0x0000
  FTDI_DEVICE_AM,                       // bcdDevice = 0x0200
  FTDI_DEVICE_BM,                       // bcdDevice = 0x0400
  FTDI_DEVICE_2232C,                    // bcdDevice = 0x0500
  FTDI_DEVICE_232R,                     // bcdDevice = 0x0600
  FTDI_DEVICE_2232H,                    // bcdDevice = 0x0700
  FTDI_DEVICE_4232H,                    // bcdDevice = 0x0800
  FTDI_DEVICE_232H,                     // bcdDevice = 0x0900
  FTDI_DEVICE_203X                      // bcdDevice = 0x1000
} FTDI_DeviceType_TypeDef;

typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef uint8_t UCHAR;

typedef struct
{
  union
  {
    uint16_t Coding;
    struct
    {
      uint16_t DataBits :8;
      uint16_t StopBits :3;
      uint16_t Parity :3;
      uint16_t TxBreak :1;
      uint16_t Reserved :1;
    };
  };
} FT232R_LineCoding;

// Cx > FT232R_CBUS_BB_RD : in Synchronous Bit Bang mode
// Running MPROG show that C0..C3 have fixed function in Synchronous Bit Bang mode
// C0 - RXF
// C1 = TXE
// C2 = RD
// C3 = WR
//
// C4 = Dont care whether it is in Synchronous Bit Bang mode
typedef enum
{
  FT232R_CBUS_TXDEN = 0x00,               // Enable transmit data for RS485
  FT232R_CBUS_PWREN = 0x01,               // Output high during USB suspending mode.
  FT232R_CBUS_RXLED = 0x02,               // Receive data LED drive
  FT232R_CBUS_TXLED = 0x03,               // Transmit data LED drive
  FT232R_CBUS_TXRXLED = 0x04,             // LED drive ¨C pulses low when transmitting or receiving data
  FT232R_CBUS_SLEEP = 0x05,               // Goes low during USB suspend mode.
  FT232R_CBUS_CLK48 = 0x06,               // Clock output
  FT232R_CBUS_CLK24 = 0x07,               // Clock output
  FT232R_CBUS_CLK12 = 0x08,               // Clock output
  FT232R_CBUS_CLK6 = 0x09,                // Clock output
  FT232R_CBUS_IOMODE = 0x0A,              // CBUS bit bang mode option
  FT232R_CBUS_BB_WR = 0x0B,               // Synchronous and asynchronous bit bang mode WR# strobe output.
  FT232R_CBUS_BB_RD = 0x0C,               // Synchronous and asynchronous bit bang mode RD# strobe output.
} FT232R_CBUS_Function;

typedef struct FT232R_Property_TypeDef FT232R_Property_TypeDef;
typedef struct FT232R_Context_TypeDef FT232R_Context_TypeDef;

typedef void FTDI_Emulator_RxCallback( FT232R_Context_TypeDef * FT232R_Context );
typedef void FTDI_Emulator_TxCallback( FT232R_Context_TypeDef * FT232R_Context );

#include "FT232R_Emulator_Conf.h"

struct FT232R_Context_TypeDef
{
  FT232R_Property_TypeDef * Device;
  void * UART_Context;

  FTDI_Emulator_RxCallback * OnRxCompleted;
  FTDI_Emulator_TxCallback * OnTxCompleted;

  uint32_t RxCompleted;

  WORD InEndpointSize;
  WORD OutEndpointSize;

  UCHAR InterfaceNumber;
  UCHAR InEndpoint;
  UCHAR OutEndpoint;
  UCHAR EventChar;
  UCHAR EventCharEnabled;
  UCHAR ErrorChar;
  UCHAR ErrorCharEnabled;
  UCHAR LatencyTimerValue;
  UCHAR LatencyTimerCount;

  /* B0 Output handshaking using RTS/CTS
   *     0 = disabled
   *     1 = enabled
   * B1 Output handshaking using DTR/DSR
   *     0 = disabled
   *     1 = enabled
   * B2 Xon/Xoff handshaking
   *     0 = disabled
   *     1 = enabled
   */
  UCHAR FlowControl;
  UCHAR FlowControlXON;
  UCHAR FlowControlXOFF;

  WORD LineCoding;

  DWORD BaudRate;

  /*
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
  WORD ModemControl;

  union
  {
    WORD dummy;
    struct
    {
      /* B0 Reserved - must be 1
       * B1 Reserved - must be 0
       * B2 Reserved - must be 0
       * B3 Reserved - must be 0
       * B4 Clear to Send (CTS)
       * B5 Data Set Ready (DSR)
       * B6 Ring Indicator (RI)
       * B7 Receive Line Signal Detect (RLSD)
       */
      UCHAR ModemStatus;
      /* B0 Data Ready (Receive RDR)
       * B1 Overrun Error (Receive OE)
       * B2 Parity Error (Receive PE)
       * B3 Framing Error (Receive FE)
       * B4 Break Interrupt (Receive Break BI)
       * B5 Transmitter Holding Register (THRE)
       * B6 Transmitter Empty (TEMT)
       * B7 Error in RCVR FIFO
       */
      UCHAR LineStatus;
    };
  };

  uint8_t InEndpBuffer[ FT232R_EMULATOR_ENDPOINT_SIZE ];

  uint8_t OutEndpBuffer[ FT232R_EMULATOR_ENDPOINT_SIZE ];
  uint32_t OutEndpBufferOffset;
  uint32_t OutEndpBufferRemaining;
};

struct FT232R_Property_TypeDef
{
  WORD bcdDevice;                     // To DeviceType
  WORD VendorID;                      // 0x0403
  WORD ProductID;                     // 0x0601
  WORD USBVersion;                    // BCD (0x0200 => USB2)

  UCHAR ManufactureStrAddr;           // "FTDI"
  UCHAR ManufactureStrSize;           //
  UCHAR ProductStrAddr;               // "USB HS Serial Converter"
  UCHAR ProductStrSize;
  UCHAR SerialNumberStrAddr;          // "FT000001" if fixed, or NULL
  UCHAR SerialNumberStrSize;

  UCHAR MaxPower;                     // 0xFA = 500 mA
  UCHAR SelfPowered;                  // 0 = bus powered, 1 = self powered
  UCHAR RemoteWakeup;                 // 0 = not capable, 1 = capable

  UCHAR USBVersionEnable;             // BM and 2232C
  UCHAR PullDownEnable;               // non-zero if pull down enabled
  UCHAR SerNumEnable;                 // non-zero if serial number to be used
  UCHAR PnP;                          // 0 = disabled, 1 = enabled

  UCHAR HighDriveIOs;                 // High Drive I/Os
  UCHAR IsD2XX;                       // non-zero if using D2XX driver
  UCHAR UseExtOsc;                    // Use External Oscillator

  UCHAR EndpointSize;                 // Endpoint size

  UCHAR InvertSet;                    // Bitmap for All, Bit0 : TXD
  UCHAR CbusFunctions[ 5 + 1 ];       // Cbus Mux control
// UCHAR InvertTXD;                   // non-zero if invert TXD
// UCHAR InvertRXD;                   // non-zero if invert RXD
// UCHAR InvertRTS;                   // non-zero if invert RTS
// UCHAR InvertCTS;                   // non-zero if invert CTS
// UCHAR InvertDTR;                   // non-zero if invert DTR
// UCHAR InvertDSR;                   // non-zero if invert DSR
// UCHAR InvertDCD;                   // non-zero if invert DCD
// UCHAR InvertRI;                    // non-zero if invert RI
// WORD EepromSize;                   // 128, 256, 512
// UCHAR EepromType;                  // 0x46, 0x56, 0x66 : 93C46, 93C56, 93C66
// WORD InterfaceNum;                 // 1, 2, 4
};

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_TYPE_H__ */
