#ifndef __DRIVER_USART_H
#define __DRIVER_USART_H

#include "Driver_Common.h"

//------------------------------------------------------------------------------
// USART Control Codes
#define DRV_USART_CONTROL_POS                0
#define DRV_USART_CONTROL_MSK               (0xFFUL << DRV_USART_CONTROL_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode
// UART (Asynchronous); arg = Baudrate
#define DRV_USART_MODE_ASYNCHRONOUS         (0x01UL << DRV_USART_CONTROL_POS)
// Synchronous Master (generates clock signal); arg = Baudrate
#define DRV_USART_MODE_SYNCHRONOUS_MASTER   (0x02UL << DRV_USART_CONTROL_POS)
// Synchronous Slave (external clock signal)
#define DRV_USART_MODE_SYNCHRONOUS_SLAVE    (0x03UL << DRV_USART_CONTROL_POS)
// UART Single-wire (half-duplex); arg = Baudrate
#define DRV_USART_MODE_SINGLE_WIRE          (0x04UL << DRV_USART_CONTROL_POS)
// UART IrDA; arg = Baudrate
#define DRV_USART_MODE_IRDA                 (0x05UL << DRV_USART_CONTROL_POS)
// UART Smart Card; arg = Baudrate
#define DRV_USART_MODE_SMART_CARD           (0x06UL << DRV_USART_CONTROL_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode Parameters: Data Bits
#define DRV_USART_DATA_BITS_POS              8
#define DRV_USART_DATA_BITS_MSK             (7UL << DRV_USART_DATA_BITS_POS)
// 5 Data bits
#define DRV_USART_DATA_BITS_5               (5UL << DRV_USART_DATA_BITS_POS)
// 6 Data bit
#define DRV_USART_DATA_BITS_6               (6UL << DRV_USART_DATA_BITS_POS)
// 7 Data bits
#define DRV_USART_DATA_BITS_7               (7UL << DRV_USART_DATA_BITS_POS)
// 8 Data bits (default)
#define DRV_USART_DATA_BITS_8               (0UL << DRV_USART_DATA_BITS_POS)
// 9 Data bits
#define DRV_USART_DATA_BITS_9               (1UL << DRV_USART_DATA_BITS_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode Parameters: Parity
#define DRV_USART_PARITY_POS                 12
#define DRV_USART_PARITY_MSK                (3UL << DRV_USART_PARITY_POS)
// No Parity (default)
#define DRV_USART_PARITY_NONE               (0UL << DRV_USART_PARITY_POS)
// Even Parity
#define DRV_USART_PARITY_EVEN               (1UL << DRV_USART_PARITY_POS)
// Odd Parity
#define DRV_USART_PARITY_ODD                (2UL << DRV_USART_PARITY_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode Parameters: Stop Bits
#define DRV_USART_STOP_BITS_POS              14
#define DRV_USART_STOP_BITS_MSK             (3UL << DRV_USART_STOP_BITS_POS)
// 1 Stop bit (default)
#define DRV_USART_STOP_BITS_1               (0UL << DRV_USART_STOP_BITS_POS)
// 2 Stop bits
#define DRV_USART_STOP_BITS_2               (1UL << DRV_USART_STOP_BITS_POS)
// 1.5 Stop bits
#define DRV_USART_STOP_BITS_1_5             (2UL << DRV_USART_STOP_BITS_POS)
// 0.5 Stop bits
#define DRV_USART_STOP_BITS_0_5             (3UL << DRV_USART_STOP_BITS_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode Parameters: Flow Control
#define DRV_USART_FLOW_CONTROL_POS           16
#define DRV_USART_FLOW_CONTROL_MSK          (3UL << DRV_USART_FLOW_CONTROL_POS)
// No Flow Control (default)
#define DRV_USART_FLOW_CONTROL_NONE         (0UL << DRV_USART_FLOW_CONTROL_POS)
// RTS Flow Control
#define DRV_USART_FLOW_CONTROL_RTS          (1UL << DRV_USART_FLOW_CONTROL_POS)
// CTS Flow Control
#define DRV_USART_FLOW_CONTROL_CTS          (2UL << DRV_USART_FLOW_CONTROL_POS)
// RTS/CTS Flow Control
#define DRV_USART_FLOW_CONTROL_RTS_CTS      (3UL << DRV_USART_FLOW_CONTROL_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode Parameters: Clock Polarity (Synchronous mode)
#define DRV_USART_CPOL_POS                   18
#define DRV_USART_CPOL_MSK                  (1UL << DRV_USART_CPOL_POS)
// CPOL = 0 (default)
#define DRV_USART_CPOL0                     (0UL << DRV_USART_CPOL_POS)
// CPOL = 1
#define DRV_USART_CPOL1                     (1UL << DRV_USART_CPOL_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Mode Parameters: Clock Phase (Synchronous mode)
#define DRV_USART_CPHA_POS                   19
#define DRV_USART_CPHA_MSK                  (1UL << DRV_USART_CPHA_POS)
// CPHA = 0 (default)
#define DRV_USART_CPHA0                     (0UL << DRV_USART_CPHA_POS)
// CPHA = 1
#define DRV_USART_CPHA1                     (1UL << DRV_USART_CPHA_POS)

//------------------------------------------------------------------------------
// USART Control Codes: Miscellaneous Controls
// Set default Transmit value (Synchronous Receive only); arg = value
#define DRV_USART_SET_DEFAULT_TX_VALUE      (0x10UL << DRV_USART_CONTROL_POS)
// Set IrDA Pulse in ns; arg: 0=3/16 of bit period
#define DRV_USART_SET_IRDA_PULSE            (0x11UL << DRV_USART_CONTROL_POS)
// Set Smart Card Guard Time; arg = number of bit periods
#define DRV_USART_SET_SMART_CARD_GUARD_TIME (0x12UL << DRV_USART_CONTROL_POS)
// Set Smart Card Clock in Hz; arg: 0=Clock not generated
#define DRV_USART_SET_SMART_CARD_CLOCK      (0x13UL << DRV_USART_CONTROL_POS)
// Smart Card NACK generation; arg: 0=disabled, 1=enabled
#define DRV_USART_CONTROL_SMART_CARD_NACK   (0x14UL << DRV_USART_CONTROL_POS)
// Transmitter; arg: 0=disabled, 1=enabled
#define DRV_USART_CONTROL_TX                (0x15UL << DRV_USART_CONTROL_POS)
// Receiver; arg: 0=disabled, 1=enabled
#define DRV_USART_CONTROL_RX                (0x16UL << DRV_USART_CONTROL_POS)
// Continuous Break transmission; arg: 0=disabled, 1=enabled
#define DRV_USART_CONTROL_BREAK             (0x17UL << DRV_USART_CONTROL_POS)
// Abort \ref DRV_USART_Send
#define DRV_USART_ABORT_SEND                (0x18UL << DRV_USART_CONTROL_POS)
// Abort \ref DRV_USART_Receive
#define DRV_USART_ABORT_RECEIVE             (0x19UL << DRV_USART_CONTROL_POS)
// Abort \ref DRV_USART_Transfer
#define DRV_USART_ABORT_TRANSFER            (0x1AUL << DRV_USART_CONTROL_POS)

//------------------------------------------------------------------------------
// USART specific error codes
// Specified Mode not supported
#define DRV_USART_ERROR_MODE                (DRIVER_ERROR_SPECIFIC - 1)
// Specified baudrate not supported
#define DRV_USART_ERROR_BAUDRATE            (DRIVER_ERROR_SPECIFIC - 2)
// Specified number of Data bits not supported
#define DRV_USART_ERROR_DATA_BITS           (DRIVER_ERROR_SPECIFIC - 3)
// Specified Parity not supported
#define DRV_USART_ERROR_PARITY              (DRIVER_ERROR_SPECIFIC - 4)
// Specified number of Stop bits not supported
#define DRV_USART_ERROR_STOP_BITS           (DRIVER_ERROR_SPECIFIC - 5)
// Specified Flow Control not supported
#define DRV_USART_ERROR_FLOW_CONTROL        (DRIVER_ERROR_SPECIFIC - 6)
// Specified Clock Polarity not supported
#define DRV_USART_ERROR_CPOL                (DRIVER_ERROR_SPECIFIC - 7)
// Specified Clock Phase not supported
#define DRV_USART_ERROR_CPHA                (DRIVER_ERROR_SPECIFIC - 8)

//------------------------------------------------------------------------------
// USART Event
//
// Send completed; however USART may still transmit data
#define DRV_USART_EVENT_SEND_COMPLETE       (1UL << 0)
// Receive completed
#define DRV_USART_EVENT_RECEIVE_COMPLETE    (1UL << 1)
// Transfer completed
#define DRV_USART_EVENT_TRANSFER_COMPLETE   (1UL << 2)

//------------------------------------------------------------------------------
// Transmit completed (optional)
#define DRV_USART_EVENT_TX_COMPLETE         (1UL << 3)
// Transmit data not available (Synchronous Slave)
#define DRV_USART_EVENT_TX_UNDERFLOW        (1UL << 4)

//------------------------------------------------------------------------------
// Receive data overflow
#define DRV_USART_EVENT_RX_OVERFLOW         (1UL << 5)
// Receive character timeout (optional)
#define DRV_USART_EVENT_RX_TIMEOUT          (1UL << 6)
// Break detected on receive
#define DRV_USART_EVENT_RX_BREAK            (1UL << 7)
// Framing error detected on receive
#define DRV_USART_EVENT_RX_FRAMING_ERROR    (1UL << 8)
// Parity error detected on receive
#define DRV_USART_EVENT_RX_PARITY_ERROR     (1UL << 9)

//------------------------------------------------------------------------------
// CTS state changed (optional)
#define DRV_USART_EVENT_CTS                 (1UL << 10)
// DSR state changed (optional)
#define DRV_USART_EVENT_DSR                 (1UL << 11)
// DCD state changed (optional)
#define DRV_USART_EVENT_DCD                 (1UL << 12)
// RI  state changed (optional)
#define DRV_USART_EVENT_RI                  (1UL << 13)

typedef void (*DRV_USART_EventHandler_TypeDef)( uint32_t event );

//------------------------------------------------------------------------------
// USART Modem Control
typedef enum
{
  DRV_USART_RTS_CLEAR,    // Deactivate RTS
  DRV_USART_RTS_SET,      // Activate RTS
  DRV_USART_DTR_CLEAR,    // Deactivate DTR
  DRV_USART_DTR_SET       // Activate DTR
} DRV_USART_ModemControl_TypeDef;

//------------------------------------------------------------------------------
// USART Modem Status
typedef struct
{
  uint32_t cts :1;        // CTS state: 1=Active, 0=Inactive
  uint32_t dsr :1;        // DSR state: 1=Active, 0=Inactive
  uint32_t dcd :1;        // DCD state: 1=Active, 0=Inactive
  uint32_t ri :1;         // RI  state: 1=Active, 0=Inactive
} DRV_USART_ModemStatus_TypeDef;

//------------------------------------------------------------------------------
// USART Status
typedef struct
{
  // Transmitter busy flag
  uint32_t tx_busy :1;
  // Receiver busy flag
  uint32_t rx_busy :1;
  // Transmit data underflow detected (cleared on start of next send operation)
  uint32_t tx_underflow :1;
  // Receive data overflow detected (cleared on start of next receive operation)
  uint32_t rx_overflow :1;
  // Break detected on receive (cleared on start of next receive operation)
  uint32_t rx_break :1;
  // Framing error detected on receive (cleared on start of next receive operation)
  uint32_t rx_framing_error :1;
  // Parity error detected on receive (cleared on start of next receive operation)
  uint32_t rx_parity_error :1;
} DRV_USART_Status_TypeDef;

//------------------------------------------------------------------------------
// USART Device Driver Capabilities.
typedef struct
{
  // supports UART (Asynchronous) mode
  uint32_t asynchronous :1;
  // supports Synchronous Master mode
  uint32_t synchronous_master :1;
  // supports Synchronous Slave mode
  uint32_t synchronous_slave :1;
  // supports UART Single-wire mode
  uint32_t single_wire :1;
  // supports UART IrDA mode
  uint32_t irda :1;
  // supports UART Smart Card mode
  uint32_t smart_card :1;
  // Smart Card Clock generator available
  uint32_t smart_card_clock :1;
  // RTS Flow Control available
  uint32_t flow_control_rts :1;
  // CTS Flow Control available
  uint32_t flow_control_cts :1;
  // Transmit completed event: DRV_USART_EVENT_TX_COMPLETE
  uint32_t event_tx_complete :1;
  // Signal receive character timeout event: DRV_USART_EVENT_RX_TIMEOUT
  uint32_t event_rx_timeout :1;
  // RTS Line: 0=not available, 1=available
  uint32_t rts :1;
  // CTS Line: 0=not available, 1=available
  uint32_t cts :1;
  // DTR Line: 0=not available, 1=available
  uint32_t dtr :1;
  // DSR Line: 0=not available, 1=available
  uint32_t dsr :1;
  // DCD Line: 0=not available, 1=available
  uint32_t dcd :1;
  // RI Line: 0=not available, 1=available
  uint32_t ri :1;
  // Signal CTS change event: DRV_USART_EVENT_CTS
  uint32_t event_cts :1;
  // Signal DSR change event: DRV_USART_EVENT_DSR
  uint32_t event_dsr :1;
  // Signal DCD change event: DRV_USART_EVENT_DCD
  uint32_t event_dcd :1;
  // Signal RI change event: DRV_USART_EVENT_RI
  uint32_t event_ri :1;
} DRV_USART_Capabilities_TypeDef;

typedef struct
{
  int32_t (*Initialize)( void * v, DRV_USART_EventHandler_TypeDef cb_event );
  int32_t (*Uninitialize)( void * v );
  int32_t (*PowerControl)( void * v, uint32_t state );

  int32_t (*Send)( void * v, void * data, uint32_t num );
  int32_t (*Receive)( void * v, void * data, uint32_t num );
  int32_t (*Transfer)( void * v, void * data_out, void * data_in, uint32_t num );

  uint32_t (*GetTxCount)( void * v );
  uint32_t (*GetRxCount)( void * v );

  int32_t (*Control)( void * v, uint32_t control, uint32_t arg );
  DRV_USART_Status_TypeDef (*GetStatus)( void * v );

  int32_t (*SetModemControl)( void * v, DRV_USART_ModemControl_TypeDef control );
  DRV_USART_ModemStatus_TypeDef (*GetModemStatus)( void * v );
} USART_Driver_TypeDef;

#endif /*  __DRIVER_USART_H  */
