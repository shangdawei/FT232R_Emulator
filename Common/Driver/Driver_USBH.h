#ifndef __USBH_DRIVER_H__
#define __USBH_DRIVER_H__

#include "Driver_USB.h"

//------------------------------------------------------------------------------
// USB Host Xfer Information : Packet for DRV_USBH_DriverPipeTransfer()
// SSPLIT CSPLIT END START :: 0 0 DATA1 DATA0 : < PINT/IN/OUT/SETUP >
// <   8, 9, A, B, C     >
//
#define DRV_USBH_PACKET_TOKEN_POS             0
#define DRV_USBH_PACKET_DATA_POS              4
#define DRV_USBH_PACKET_SPLIT_POS             8
//
#define DRV_USBH_PACKET_TOKEN_MSK             (0x0FUL << DRV_USBH_PACKET_TOKEN_POS)
#define DRV_USBH_PACKET_DATA_MSK              (0x0FUL << DRV_USBH_PACKET_DATA_POS)
#define DRV_USBH_PACKET_SPLIT_MSK             (0x0FUL << DRV_USBH_PACKET_SPLIT_POS)
//
#define DRV_USBH_PACKET_SETUP                 (0x01UL << DRV_USBH_PACKET_TOKEN_POS)
#define DRV_USBH_PACKET_OUT                   (0x02UL << DRV_USBH_PACKET_TOKEN_POS)
#define DRV_USBH_PACKET_IN                    (0x03UL << DRV_USBH_PACKET_TOKEN_POS)
#define DRV_USBH_PACKET_PING                  (0x04UL << DRV_USBH_PACKET_TOKEN_POS)
//
#define DRV_USBH_PACKET_DATA0                 (0x01UL << DRV_USBH_PACKET_DATA_POS)
#define DRV_USBH_PACKET_DATA1                 (0x02UL << DRV_USBH_PACKET_DATA_POS)
//
#define DRV_USBH_PACKET_SSPLIT                (0x08UL << DRV_USBH_PACKET_SPLIT_POS)
#define DRV_USBH_PACKET_SSPLIT_S              (0x09UL << DRV_USBH_PACKET_SPLIT_POS)
#define DRV_USBH_PACKET_SSPLIT_E              (0x0AUL << DRV_USBH_PACKET_SPLIT_POS)
#define DRV_USBH_PACKET_SSPLIT_S_E            (0x0BUL << DRV_USBH_PACKET_SPLIT_POS)
#define DRV_USBH_PACKET_CSPLIT                (0x0CUL << DRV_USBH_PACKET_SPLIT_POS)
//
#define DRV_USBH_PACKET_PRE                   (1UL << 12)

//------------------------------------------------------------------------------
// USB Host Port Event
//
#define DRV_USBH_EVENT_CONNECT                ( 1UL << 0 )
#define DRV_USBH_EVENT_DISCONNECT             ( 1UL << 1 )
#define DRV_USBH_EVENT_OVERCURRENT            ( 1UL << 2 )
#define DRV_USBH_EVENT_RESET                  ( 1UL << 3 )
#define DRV_USBH_EVENT_SUSPEND                ( 1UL << 4 )
#define DRV_USBH_EVENT_RESUME                 ( 1UL << 5 )
#define DRV_USBH_EVENT_REMOTE_WAKEUP          ( 1UL << 6 )
//
#define DRV_USBH_EVENT_DEBOUNCED              ( 1UL << 8 )
#define DRV_USBH_EVENT_RECOVER_DEVICE         ( 1UL << 9 )
#define DRV_USBH_SIGNAL_PORT_EVENT            ( 1UL << 15 )   // 0x8000

//------------------------------------------------------------------------------
// USB Host Pipe Event
//
#define DRV_USBH_EVENT_TRANSFER_COMPLETE      ( 1UL << 0 )
#define DRV_USBH_EVENT_HANDSHAKE_NAK          ( 1UL << 1 )
#define DRV_USBH_EVENT_HANDSHAKE_NYET         ( 1UL << 2 )
#define DRV_USBH_EVENT_HANDSHAKE_MDATA        ( 1UL << 3 )
#define DRV_USBH_EVENT_HANDSHAKE_STALL        ( 1UL << 4 )
#define DRV_USBH_EVENT_HANDSHAKE_ERR          ( 1UL << 5 )
#define DRV_USBH_EVENT_BUS_ERROR              ( 1UL << 6 )
//
#define DRV_USBH_EVENT_TRANSFER_ABORT         ( 1UL << 7 )    // 0x0080
//
//------------------------------------------------------------------------------
// USB Host Recover Event --> USBH_RecoverDevice()
//
#define DRV_USBH_EVENT_RECOVER_SUCCESS        ( 1UL << 10 )   // 0x0400
#define DRV_USBH_EVENT_RECOVER_FAILED         ( 1UL << 11 )   // 0x0800

//------------------------------------------------------------------------------
// Structure containing transfer information
typedef struct
{
  uint32_t * Transfer;                    // pointer to transfer structure
  uint32_t * Pipe;                        // pointer to pipe structure
  uint32_t Packet;                        // packet : PID, SETUP, PING, DATAx
  uint8_t * Data;                         // pointer to data
  uint32_t Size;                          // number of bytes to transfer
  uint32_t Transferred;                   // total number of bytes Transferred
  uint32_t NumPerTransfer;      // number of bytes to trasfer in single transfer
  uint32_t Active;                        // activity flag
} DRV_USBH_TransferInfo_TypeDef;

//------------------------------------------------------------------------------
// Structure containing Configuration values for OHCI Compliant Controller
typedef struct
{
  uint32_t * OHCI;          // pointer to memory mapped reg base address
  uint16_t MaxED;           // maximum Endpoint Descriptors
  uint16_t MaxTD;           // maximum Transfer Descriptors
  uint16_t MaxITD;          // maximum Isochronous Transfer Descriptors
  uint32_t * HCCA;          // pointer to HCCA memory start
  uint32_t * ED;            // pointer to ED memory start
  uint32_t * TD;            // pointer to TD memory start
  uint32_t * ITD;           // pointer to ITD memory start
  // pointer to Transfer Info (TI) array start
  DRV_USBH_TransferInfo_TypeDef * TransferInfo;
} DRV_USBH_OHCI_TypeDef;

//------------------------------------------------------------------------------
// Structure containing Configuration values for EHCI Compliant Controller
typedef struct
{
  uint32_t * EHCI;          // pointer to memory mapped reg base address
  uint16_t MaxqH;           // maximum queue Heads
  uint16_t MaxqTD;          // maximum queue Transfer Descriptors
  uint16_t MaxiTD;          // maximum Isochronous Transfer Descriptors
  uint16_t MaxsiTD;         // maximum split Isochronous Transfer Descriptors
  uint16_t MaxFSTN;         // maximum periodic Frame Span Traversal Nodes
  uint32_t * PFL;           // pointer to Periodic Frame List memory
  uint32_t * qH;            // pointer to qH memory start
  uint32_t * qTD;           // pointer to qTD memory start
  uint32_t * iTD;           // pointer to iTD memory start
  uint32_t * siTD;          // pointer to siTD memory start
  uint32_t * FSTN;          // pointer to FSTN memory start
  // pointer to Transfer Info (TI) array start
  DRV_USBH_TransferInfo_TypeDef * TransferInfo;
} DRV_USBH_EHCI_TypeDef;

//------------------------------------------------------------------------------
// USB Host Port State
typedef struct
{
  uint32_t Connected :1;            // USB Host Port connected flag
  uint32_t Overcurrent :1;          // USB Host Port overcurrent flag
  uint32_t Speed :2;                // USB Host Port speed (USB_SPEED_xxx)
} DRV_USBH_PortState_TypeDef;

//------------------------------------------------------------------------------
// USB Host PipeHandle Handle
typedef void * DRV_USBH_PipeHandle_TypeDef;

#define INVALID_PIPE_HANDLE         \
  ( ( DRV_USBH_PipeHandle_TypeDef )( 0xFFFFFFFF ) )

// Signal Root HUB Port Event.
typedef void (*DRV_USBH_PortEventHandler_TypeDef)( uint32_t Port,
  uint32_t Event );

//Signal PipeHandle Event.
typedef void (*DRV_USBH_PipeEventHandler_TypeDef)(
  DRV_USBH_PipeHandle_TypeDef Pipe, uint32_t Event );

// USB Host HCI (OHCI/EHCI) Interrupt Handler.
typedef void (*DRV_USBH_HCI_EventHandler_TypeDef)( void );

// USB Host HCI (OHCI/EHCI) Driver Capabilities.
typedef struct
{
  // Root HUB available Ports Mask
  uint32_t PortMask :15;
} DRV_USBH_HCI_Capabilities_TypeDef;

//------------------------------------------------------------------------------
// USB Host Driver Capabilities.
typedef struct
{
  uint32_t PortMask :15;            // Root HUB available Ports Mask
  uint32_t AutoSplit :1;            // Automatic SPLIT packet handling
  uint32_t EventConnect :1;         // Signal Connect event
  uint32_t EventDisconnect :1;      // Signal Disconnect event
  uint32_t EventOvercurrent :1;     // Signal Overcurrent event
} DRV_USBH_Capabilities_TypeDef;

// Access structure of USB Host HCI (OHCI/EHCI) Driver.
typedef struct
{
  const DRV_USBH_HCI_Capabilities_TypeDef * (*GetCapabilities)( const void * v );

  // Initialize USB Host HCI (OHCI/EHCI) Interface.
  int32_t (*Initialize)( DRV_USBH_HCI_EventHandler_TypeDef EventHandler );

  // De-initialize USB Host HCI (OHCI/EHCI) Interface.
  int32_t (*Uninitialize)( void );

  // Control USB Host HCI (OHCI/EHCI) Interface Power.
  int32_t (*PowerControl)( uint32_t State );

  // USB Host HCI (OHCI/EHCI) Root HUB Port VBUS on/off.
  int32_t (*PortVbusOnOff)( uint8_t Port, uint32_t VBus );
} USBH_HCI_Driver_TypeDef;

//------------------------------------------------------------------------------
// Access structure of USB Host Driver.
// DRV_USBH_TypeDef * ctrl = ( DRV_USBH_TypeDef *)v;
//
typedef struct
{
  const DRV_USBH_Capabilities_TypeDef * (*GetCapabilities)( const void * v );

  // Initialize USB Host Interface.
  int32_t (*Initialize)( const void * v,
    DRV_USBH_PortEventHandler_TypeDef PortEventHandler,
    DRV_USBH_PipeEventHandler_TypeDef PipeEventHandler );

  // De-initialize USB Host Interface.
  int32_t (*Uninitialize)( const void * v );

  // Control USB Host Interface Power.
  int32_t (*PowerControl)( const void * v, uint32_t State );

  // Root HUB Port VBUS on/off.
  int32_t (*PortVbusOnOff)( const void * v, uint8_t Port, uint32_t VBus );

  // Get current USB Frame Number.
  uint16_t (*GetFrameNumber)( const void * v );

  // Get current Root HUB Port State.
  DRV_USBH_PortState_TypeDef (*PortGetState)( const void * v, uint8_t Port );

  // Do Root HUB Port Reset.
  int32_t (*PortReset)( const void * v, uint8_t Port );

  // Suspend Root HUB Port (stop generating SOFs).
  int32_t (*PortSuspend)( const void * v, uint8_t Port );

  // Resume Root HUB Port (start generating SOFs).
  int32_t (*PortResume)( const void * v, uint8_t Port );

  // Create Pipe in System.
  DRV_USBH_PipeHandle_TypeDef (*PipeCreate)( const void * v, uint8_t DevAddr,
    uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort, uint8_t EndpAddr,
    uint8_t EndpType, uint16_t MaxPacketSize, uint8_t EndpInterval );

  // Modify Pipe in System.
  int32_t (*PipeModify)( const void * v, DRV_USBH_PipeHandle_TypeDef PipeHandle,
    uint8_t DevAddr, uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort,
    uint16_t MaxPacketSize );

  // Delete Pipe from System.
  int32_t (*PipeDelete)( const void * v,
    DRV_USBH_PipeHandle_TypeDef PipeHandle );

  // Reset Pipe.
  int32_t (*PipeReset)( const void * v, DRV_USBH_PipeHandle_TypeDef PipeHandle );

  // Transfer packets through USB Pipe.
  int32_t (*PipeTransfer)( const void * v,
    DRV_USBH_PipeHandle_TypeDef PipeHandle, uint32_t Packet, uint8_t *Data,
    uint32_t Size );

  // Abort current USB Pipe transfer.
  int32_t (*PipeTransferAbort)( const void * v,
    DRV_USBH_PipeHandle_TypeDef PipeHandle );

  // Get result of USB Pipe transfer.
  uint32_t (*PipeTransferGetResult)( const void * v,
    DRV_USBH_PipeHandle_TypeDef PipeHandle );

} USBH_Driver_TypeDef;

#endif /* __USBH_DRIVER_H__ */
