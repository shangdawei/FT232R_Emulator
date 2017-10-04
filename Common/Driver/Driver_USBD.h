#ifndef __DRIVER_USBD_H__
#define __DRIVER_USBD_H__

#include "Driver_USB.h"

//------------------------------------------------------------------------------
// USB Device Event
#define DRV_USBD_EVENT_VBUS_ON    (1UL << 0)  // USB Device VBUS On
#define DRV_USBD_EVENT_VBUS_OFF   (1UL << 1)  // USB Device VBUS Off
#define DRV_USBD_EVENT_RESET      (1UL << 2)  // USB Reset occurred
#define DRV_USBD_EVENT_HIGH_SPEED (1UL << 3)  // USB Switch High Speed occurred
#define DRV_USBD_EVENT_SUSPEND    (1UL << 4)  // USB Suspend occurred
#define DRV_USBD_EVENT_RESUME     (1UL << 5)  // USB Resume occurred

//------------------------------------------------------------------------------
// USB Endpoint Event
#define DRV_USBD_EVENT_SETUP      (1UL << 0)  // SETUP Xfer
#define DRV_USBD_EVENT_OUT        (1UL << 1)  // OUT Xfer(s)
#define DRV_USBD_EVENT_IN         (1UL << 2)  // IN Xfer(s)

// Signal USB Device Event.
typedef void (*DRV_USBD_DeviceEventHandler_TypeDef)( uint32_t Event );

// Signal USB Endpoint Event.
typedef void (*DRV_USBD_EndpointEventHandler_TypeDef)( uint8_t Addr,
  uint32_t Event );

//------------------------------------------------------------------------------
// USB Device State
typedef struct
{
  uint32_t Speed :2;              // Speed setting (USB_SPEED_xxx)
  uint32_t VBus :1;               // VBUS flag
  uint32_t Active :1;             // Active flag
} DRV_USBD_State_TypeDef;

// USB Device Driver Capabilities.
typedef struct
{
  uint32_t VBusDetection :1;      // VBUS detection
  uint32_t EventVbusOn :1;        // Signal VBUS On event
  uint32_t EventVbusOff :1;       // Signal VBUS Off event
} DRV_USBD_Capabilities_TypeDef;

//------------------------------------------------------------------------------
// Access structure of USB Device Driver.
// DRV_USBD_TypeDef * ctrl = ( DRV_USBD_TypeDef *)v;
//
typedef struct
{
  const DRV_USBD_Capabilities_TypeDef * (*GetCapabilities)( const void * v );

  // Initialize USB Device Interface.
  int32_t (*Initialize)( const void * v,
    DRV_USBD_DeviceEventHandler_TypeDef DeviceEventHandler,
    DRV_USBD_EndpointEventHandler_TypeDef EndpointEventHandler );

  //De-initialize USB Device Interface.
  int32_t (*Uninitialize)( const void * v );

  // Control USB Device Interface Power.
  int32_t (*PowerControl)( const void * v, uint32_t State );

  // Connect USB Device.
  int32_t (*Connect)( const void * v );

  // Disconnect USB Device.
  int32_t (*Disconnect)( const void * v );

  // Get current USB Device State.
  DRV_USBD_State_TypeDef (*GetState)( const void * v );

  //Get current USB Frame Number.
  uint16_t (*GetFrameNumber)( const void * v );

  // Trigger USB Remote Wakeup.
  int32_t (*RemoteWakeup)( const void * v );

  // Set USB Device Address.
  int32_t (*SetAddress)( const void * v, uint8_t Address );

  // Read setup packet received over Control Endpoint.
  int32_t (*ReadSetupPacket)( const void * v, uint8_t * SetupPacket );

  // Configure USB Endpoint.
  int32_t (*EndpointConfigure)( const void * v, uint8_t Addr, uint8_t Type,
    uint16_t MaxPacketSize );

  // Unconfigure USB Endpoint.
  int32_t (*EndpointUnconfigure)( const void * v, uint8_t Addr );

  // Set/Clear Stall for USB Endpoint.
  int32_t (*EndpointStall)( const void * v, uint8_t Addr, uint32_t Stall );

  // Read data from or Write data to USB Endpoint.
  int32_t (*EndpointTransfer)( const void * v, uint8_t Addr, uint8_t * Buffer,
    uint32_t Count );

  // Get result of USB Endpoint transfer.
  int32_t (*EndpointTransferGetResult)( const void * v, uint8_t Addr );

  // Abort current USB Endpoint transfer.
  int32_t (*EndpointTransferAbort)( const void * v, uint8_t Addr );

} USBD_Driver_TypeDef;

#endif /* __DRIVER_USBD_H__ */
