#ifndef __DRIVER_CAN_H__
#define __DRIVER_CAN_H__

#include "Driver_Common.h"

//------------------------------------------------------------------------------
// CAN Timing
//
typedef struct
{
  //char name[ 16 ];                // Name of the CAN controller hardware
  //uint32_t ref_clk;               // CAN system clock frequency in Hz
  //uint32_t sjw_max;               // Synchronisation jump width
  uint32_t brp_min;                 // Bit-rate prescaler
  uint32_t brp_max;
  uint32_t brp_inc;
  uint32_t tseg1_min;               // Time segement 1 = prop_seg + phase_seg1
  uint32_t tseg1_max;
  uint32_t tseg2_min;               // Time segement 2 = phase_seg2
  uint32_t tseg2_max;
} CAN_BitTimingConst_TypeDef;

typedef struct
{
  uint32_t ref_clk;                 // CAN system clock frequency in Hz
  uint32_t bitrate;                 // Bit-rate in bits/second
  uint32_t sample_point;            // Sample point in one-tenth of a percent
  uint32_t brp;                     // Bit-rate prescaler
  uint32_t tq;                      // Time quanta ( TQ )  in nanoseconds
  uint32_t tseg1;                   // Time segement 1 = prop_seg + phase_seg1
  uint32_t tseg2;                   // Time segement 2 = phase_seg2
  uint32_t sjw;                     // Synchronisation jump width in TQs
//uint32_t prop_seg;                // Propagation segment in TQs
//uint32_t phase_seg1;              // Phase buffer segment 1 in TQs
//uint32_t phase_seg2;              // Phase buffer segment 2 in TQs
} CAN_BitTiming_TypeDef;

int32_t CAN_CalcBitTiming( CAN_BitTimingConst_TypeDef *btc,
  CAN_BitTiming_TypeDef *bt );

//------------------------------------------------------------------------------
// CAN_SET_SPEED/CAN_GET_SPEED
#define DRV_CAN_SPEED_AUTO               ( 0 )
#define DRV_CAN_SPEED_10K                ( 10000 )
#define DRV_CAN_SPEED_20K                ( 20000 )
#define DRV_CAN_SPEED_33K3               ( 33300 )
#define DRV_CAN_SPEED_50K                ( 500000 )
#define DRV_CAN_SPEED_62K5               ( 62500 )
#define DRV_CAN_SPEED_83K3               ( 83300 )
#define DRV_CAN_SPEED_100K               ( 100000 )
#define DRV_CAN_SPEED_125K               ( 125000 )
#define DRV_CAN_SPEED_250K               ( 250000 )
#define DRV_CAN_SPEED_500K               ( 500000 )
#define DRV_CAN_SPEED_800K               ( 800000 )
#define DRV_CAN_SPEED_1000K              ( 1000000 )

//------------------------------------------------------------------------------
// CAN Event
//
// Speed Detect completed
#define DRV_CAN_EVENT_SPEED_DETECTED     ( 1UL << 0 )
// Message Receive completed
#define DRV_CAN_EVENT_RX_COMPLETED       ( 1UL << 1 )
// Message Transfer completed, everything is OK
#define DRV_CAN_EVENT_TX_COMPLETED       ( 1UL << 2 )
// Message Transfer Error : No Ack or Arbitration lost
#define DRV_CAN_EVENT_TX_FAILED          ( 1UL << 3 )
// Bus Off
#define DRV_CAN_EVENT_BUS_OFF            ( 1UL << 4 )
// Error Warning
#define DRV_CAN_EVENT_ERROR_WARNING      ( 1UL << 5 )
// Error Passive
#define DRV_CAN_EVENT_ERROR_PASSIVE      ( 1UL << 6 )
// Error Code -- LEC
#define DRV_CAN_EVENT_ERROR_CODE         ( 1UL << 7 )
// Wake Up
#define DRV_CAN_EVENT_WAKEUP             ( 1UL << 8 )
// Sleep
#define DRV_CAN_EVENT_SLEEP              ( 1UL << 9 )

typedef void (*DRV_CAN_EventHandler_TypeDef)( uint32_t event );

//------------------------------------------------------------------------------
// CAN Control Code
#define DRV_CAN_CONTROL_POS              (  0UL  )
#define DRV_CAN_CONTROL_MSK              ( 0xFFUL << DRV_CAN_CONTROL_POS )

//------------------------------------------------------------------------------
// CAN Control Codes
//
// Set CAN Mode
#define DRV_CAN_SET_MODE                 ( 0x00UL << DRV_CAN_CONTROL_POS )
// Set CAN Speed
#define DRV_CAN_SET_SPEED                ( 0x01UL << DRV_CAN_CONTROL_POS )
// Set CAN Filter
#define DRV_CAN_SET_FILTER               ( 0x02UL << DRV_CAN_CONTROL_POS )
// Abort transmission
#define DRV_CAN_ABORT_TRANSMIT           ( 0x03UL << DRV_CAN_CONTROL_POS )
// Time Trigger Communication
#define DRV_CAN_TIME_TRIGGER             ( 0x04UL << DRV_CAN_CONTROL_POS )
//
// Speed Detect : CAN_Capabilities.detect_speed = 1
#define DRV_CAN_DETECT_SPEED             ( 0x05UL << DRV_CAN_CONTROL_POS )
//
// Set Reply for Remote Frame : CAN_Capabilities.auto_reply = 1
#define DRV_CAN_SET_REPLY_MESSAGE        ( 0x06UL << DRV_CAN_CONTROL_POS )

//------------------------------------------------------------------------------
// CAN_SET_MODE
//
#define DRV_CAN_MODE_INIT                0       // Initialization mode
#define DRV_CAN_MODE_SLEEP               1       // Sleep mode
#define DRV_CAN_MODE_NORMAL              2       // Normal mode
// Test Mode -------------------------------------------------------------------
#define DRV_CAN_MODE_LISTEN              3       // Silent mode
#define DRV_CAN_MODE_LOOPBACK            4       // Loopback mode
#define DRV_CAN_MODE_LISTEN_LOOPBACK     5       // Loopback + Silent mode

//------------------------------------------------------------------------------
#define DRV_CAN_PARAMETER_POS            (  8UL  )
#define DRV_CAN_PARAMETER_MSK            ( 0xFFFFFFUL << DRV_CAN_PARAMETER_POS )

#define DRV_CAN_SET_FILTER_GET_COUNT( v )            \
(  v >> DRV_CAN_PARAMETER_POS  )

#define DRV_CAN_SET_FILTER_CTRL_COUNT( v, cnt )      \
(  DRV_CAN_SET_FILTER | cnt << DRV_CAN_PARAMETER_POS  )

//------------------------------------------------------------------------------
// CAN error code : STM32F4xx ESR.LEC[2:0]
//
#define DRV_CAN_ERROR_NONE               (  0 << 0  )
//
// More than 5 equal bits in a sequence have occurred
// in a part of a received message where this is not allowed
#define DRV_CAN_ERROR_STUFF              (  1 << 1  )

// A fixed format part of a received frame has the wrong format.
#define DRV_CAN_ERROR_FORM               (  1 << 2  )

// AckError: The message this CAN core transmitted was not acknowledged.
#define DRV_CAN_ERROR_NO_ACK             (  1 << 3  )

// During the transmission of a message ( with the exception of the arbitration
// field ) , the device wanted to send a HIGH/recessive level ( bit of logical
// value ) , but the monitored bus value was LOW/dominant : Arbitration lost
// During the transmission of a message but Arbitration lost
#define DRV_CAN_ERROR_RECESSIVE          (  1 << 4  )
#define DRV_CAN_ERROR_BIT1               (  1 << 4  )
#define DRV_CAN_ERROR_ALOST              (  1 << 4  )

// During the transmission of a message ( or acknowledge bit, or active error
// flag, or overload flag ) , the device wanted to send a LOW/dominant level
// ( data or identifier bit logical value, but the monitored Bus value was
// HIGH/recessive.
//
// During busoff recovery this status is set each time a sequence of 11
// HIGH/recessive bits has been monitored.
// This enables the CPU to monitor the proceeding of the busoff recovery sequence
// ( indicating the bus is not stuck at LOW/dominant or continuously disturbed ) .
#define DRV_CAN_ERROR_DOMINANT           (  1 << 5  )
#define DRV_CAN_ERROR_BIT0               (  1 << 4  )

// The CRC checksum was incorrect in the message received.
// ERROR_CRC
#define DRV_CAN_ERROR_CRC                (  1 << 6  )

//------------------------------------------------------------------------------
// CAN State Code
//
// sleep state
#define DRV_CAN_STATE_SLEPT              (  1<< 0  )
// the bus-off state
#define DRV_CAN_STATE_BUS_OFF            (  1<< 1  )
// Passive limit has been reached
#define DRV_CAN_STATE_ERROR_PASSIVE      (  1<< 2  )
// warning limit has been reached
#define DRV_CAN_STATE_ERROR_WARNING      (  1<< 3  )

//------------------------------------------------------------------------------
// A filter matches, when rx_id & Mask = Id & Mask
// IdLow  > IdHigh : Any ID               : 1, 0
// IdLow == IdHigh : Only 1 ID            : 1, 1
// IdLow  < IdHigh : from IdLow to IdHigh : 1, 2
//
#define DRV_CAN_IDE_POS                  (  31  )
#define DRV_CAN_RTR_POS                  (  30  )

#define DRV_CAN_IDE_BIT_VAL( id )        \
  (  (  ( id )  >> DRV_CAN_IDE_POS  )  & 1  )

#define DRV_CAN_RTR_BIT_VAL( id )        \
(  (  ( id )  >> DRV_CAN_RTR_POS  )  & 1  )

#define DRV_CAN_STD_ID                   (  0UL << DRV_CAN_IDE_POS  )
#define DRV_CAN_EXT_ID                   (  1UL << DRV_CAN_IDE_POS  )

#define DRV_CAN_DATA_FRAME               (  0UL << DRV_CAN_RTR_POS  )
#define DRV_CAN_REMOTE_FRAME             (  1UL << DRV_CAN_RTR_POS  )

#define DRV_CAN_STD_ID_MASK              (  0x7FFUL  )
#define DRV_CAN_EXT_ID_MASK              (  0x1FFFFFFFUL  )

//------------------------------------------------------------------------------
// A filter matches, when received_id & filter_mask == filter_id & filter_mask
// filter_mask = 1 : received_id bit must match filter_id
// filter_mask = 0 : received_id bit dont care
//
// (  Id, Mask  )     : ( 0x000, 0x000 )  : Any,   Mask Mode
// (  Id, Mask  )     : ( 0x123, 0x000 )  : 0x123, List Mode
// (  Id, Mask  )     : ( 0x123, 0xFFF )  : 0x123, Mask Mode All Bits Must Match
// (  Id, Mask  )     : ( 0x123, 0xFF0 )  : 0x12x, Mask Mode Low 4 Bits Ignore
//
#define DRV_CAN_ANY_MBX            ( 0xFF )

typedef struct
{
  uint32_t Id;                    // ID, 11-Bit or 29-Bit
  uint32_t Mask;                  // 1 = Id Match, 0 = Id Ignore
  uint8_t ExtendedId;             // Extended or Standard ?
  uint8_t RemoteFrame;            // Remote or Data Framae ?
  uint8_t MatchIde;               // Extended or Standard ?
  uint8_t MatchRtr;               // Remote or Data Framae ?
  uint8_t RxMailBox;              // Which mailbox to receive
} DRV_CAN_Filter_TypeDef;

typedef struct
{
  uint8_t state;                  // DRV_CAN_STATE_XXX : bitmap
  uint8_t error;                  // DRV_CAN_ERROR_XXX : bitmap
  uint8_t time_triggered;         // Time Trigger Communication
  uint8_t speed_detected;         // Auto Baud Done in Slient Mode
  uint32_t rx_completed;          // Message Receive completed : bitmap
  uint32_t tx_completed;          // transmission was successful : bitmap
  uint32_t tx_failed;             // transmission with error : bitmap
} DRV_CAN_Status_TypeDef;

typedef struct
{
  uint8_t TxMailBox;              // How many Tx MailBox ?
  uint8_t RxMailBox;              // How many Rx MailBox ?
  uint32_t listen_mdoe :1;        // Support Listen Mode ?
  uint32_t loopback_mdoe :1;      // Support Loopback Mode ?
  uint32_t auto_recovery :1;      // Auto Exit Bus Off ?
  uint32_t auto_wakeup :1;        // Auto wake up ?
  uint32_t auto_retransmit :1;    // Auto Retrans. or Signal Shot Transmit
  uint32_t time_trigger :1;       // Time Trigger Communication mode ?
  uint32_t auto_reply :1;         // Auto Reply Message for REMOTE FRAME ?
  uint32_t detect_speed :1;       // Auto baud rate detect ?
} DRV_CAN_Capabilities_TypeDef;

typedef struct
{
  uint8_t Dlc;                    // Data Length Code
  uint8_t MailBox;                // MailBox = TxMailBox : Any Availabe Mbx
  uint16_t TimeStamp;             // TimeStamp of Rx Message
  uint32_t Id;                    // ID Information, STD/EXT, DATA/REMOTE
  union
  {
    uint8_t Data8[ 8 ];
    uint16_t Data16[ 4 ];
    uint32_t Data32[ 2 ];
  };
} DRV_CAN_Message_TypeDef;

typedef struct
{
  int32_t (*Initialize)( void * v, DRV_CAN_EventHandler_TypeDef handler );
  int32_t (*Uninitialize)( void * v );
  int32_t (*PowerControl)( void * v, uint32_t state );

  // Write one Message to message->MailBox
  // Return used MailBox if ( message->MailBox == DRV_CAN_ANY_MBX )
  int32_t (*Write)( void * v, DRV_CAN_Message_TypeDef * message );

  // Transmit Pending Message in MailBox
  int32_t (*Transmit)( void * v, uint32_t MailBox );

  // Start Receive Message with MailBox < DRV_CAN_ANY_MBX : all >
  int32_t (*Receive)( void * v, uint32_t MailBox );

  // Read Pending Message from MailBox, return message count
  int32_t (*Read)( void * v, uint32_t MailBox, int32_t capacity,
    DRV_CAN_Message_TypeDef * messages );

  int32_t (*Control)( void * v, uint32_t control, uint32_t arg );
  DRV_CAN_Status_TypeDef * (*GetStatus)( void * v );

} CAN_Driver_TypeDef;

#endif /* __DRIVER_CAN_H__ */
