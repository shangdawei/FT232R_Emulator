#ifndef __USBH_H__
#define __USBH_H__

#include "board.h"
#include "driver.h"
#include "os.h"

#include "usb.h"

#define USBH_SUPPORT_USE_MULTI_THREAD           ( 0 )
#define USBH_MAX_CONFIGURATION_DESCRIPTOR_SIZE  ( 255 )

//------------------------------------------------------------------------------
// USB Host Port Enumurate State
//
#define ENUM_STATE_CONNECTED                    ( 0 )
#define ENUM_STATE_RESET_PORT                   ( 1 )
#define ENUM_STATE_GET_MAX_PACKET_SIZE0         ( 2 )
#define ENUM_STATE_ENUMERATION                  ( 3 )
#define ENUM_STATE_RECOVER_FIND_RESET           ( 4 )
#define ENUM_STATE_RECOVER_RESET_AGAIN          ( 5 )
#define ENUM_STATE_RECOVER_ENUMERATE            ( 6 )
#define ENUM_STATE_RECOVER_FAILED               ( 7 )
//
#define ENUM_STATE_COMPLETED                    ( 8 )
#define ENUM_STATE_ERROR                        ( 9 )

//------------------------------------------------------------------------------
// Device Descriptor Memory
typedef __packed struct
{
  USB_DEVICE_DESCRIPTOR DeviceDescriptor;
  uint8_t Used;
} HAL_USB_DEVICE_DESCRIPTOR;

//------------------------------------------------------------------------------
// Configuration Descriptor Memory
typedef __packed struct
{
  uint8_t ConfigurationDescriptor[ USBH_MAX_CONFIGURATION_DESCRIPTOR_SIZE ];
  uint8_t Used;
} HAL_USB_CONFIGURATION_DESCRIPTOR;

//------------------------------------------------------------------------------
// USB Host Pipe settings structure
typedef struct
{
  DRV_USBH_PipeHandle_TypeDef Handle;      // handle to hardware resource
  osThreadId TransferThreadId;            // Pipe transfer thread ID
  uint8_t HubAddr;          // Hub communication Address
  uint8_t HubPort;          // Hub communication Port
  uint8_t DevAddr;          // Device communication Address
  uint8_t DevSpeed;         // Device communication Speed
  uint8_t EndpointAddress;  // Endpoint Address + direction
  uint8_t Attributes;       // Endpoint Attributes (type + Isochronous info)
  uint8_t Interval;         // Interval
  uint8_t Active;           // Activity flag
  uint32_t Transferred;     // Last Transferred information
  uint16_t MaxPacketSize;   // Maximum Xfer Size + Isochronous info
} HAL_USBH_Pipe_TypeDef;

//------------------------------------------------------------------------------
// Host Controller Instance (HCI) structure
typedef struct
{
  // 0 = none, 1..128 = locked or reset active port
  uint8_t PortLock;                   // port locked for enumeration
  uint8_t PortReset;                  // port reset for enum or recovery
  uint16_t PortConnected;             // port connected map in software
  uint16_t PortDisconnected;          // port disconnect map in software
  uint16_t PortOvercurrent;           // port over-current
  uint8_t EnumState[ 16 ];            // Enum states (8 bits per port)
  uint16_t PortEvent[ 16 ];           // port events (16 bits per port)
  uint32_t PortRetry;                 // Enum retry counters (2 bits per port)
  uint16_t PortDebounce;              // port debounce active
  uint16_t DebounceCountDown;         // de-bounce countdown counter
  uint16_t DebounceMaxCountDown;      // de-bounce maximum countdown counter
  uint16_t DebounceReload;            // de-bounce restart
  uint8_t LastDevAddr;                // last addressed device address
  uint32_t DevAddrMask[ 4 ];          // mask of used device addresses
  HAL_USBH_Pipe_TypeDef * DefaultPipe;    // Default Pipe
} HAL_USBH_Info_TypeDef;

//------------------------------------------------------------------------------
// USB Host Controller structure
struct _USBH_Class_TypeDef;
//
typedef struct
{
  // Compiler Time
  const uint32_t ClassNum;                      // USBH_(Un)RegisterClass
  const uint32_t DeviceNum;                     // USBH_EnumerateDevice()
  const uint32_t PipeNum;                       // USBH_PipeCreate/Delete
  const uint32_t TransferNum;                   // EHCI/OHCI
  const uint32_t DeviceDescriptorNum;           //
  const uint32_t ConfigurationDescriptorNum;    //
  const uint32_t StackSize;                     // Stack Size In Bytes
  const uint32_t DebounceTime;                  //
  DRV_USBH_PortEventHandler_TypeDef PortEventHandler;
  DRV_USBH_PipeEventHandler_TypeDef PipeEventHandler;
  osTimerId Timer;                              // &USBH_Timer
  osSemaphoreId Semaphore;                      // &USBH_Semaphore
  osThreadId ThreadId;                          // &USBH_Thread
  uint32_t * ThreadStack;                       // uint32_t USBH_ThreadStack[]
  const struct _USBH_Class_TypeDef ** ClassArray;
  HAL_USBH_Pipe_TypeDef * PipeArray;            // USBH_PipeArray[ PipeNum ]
  struct _USBH_Device_TypeDef * DeviceArray;    // USBH_DeviceArray[ClassCount]
  HAL_USB_DEVICE_DESCRIPTOR * DeviceDescriptorArray;
  HAL_USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptorArray;
  HAL_USBH_Info_TypeDef * Info;                 // USBH Controller Information
  const DRV_USBH_TypeDef * Instance;            //
  const USBH_Driver_TypeDef * Driver;           // USBH Controller Driver
  // Run Time
  const DRV_USBH_Capabilities_TypeDef * Capabilities;
  uint32_t TimerCreated;                        //
  uint32_t ThreadCreated;                       //
  uint32_t SemaphoreCreated;                    //
} HAL_USBH_TypeDef;

//------------------------------------------------------------------------------
// USB Host Device Instance (DEV) structure
typedef struct _USBH_Device_TypeDef
{
  HAL_USBH_TypeDef * Parent;      // USB Host Controller
  USB_DEVICE_DESCRIPTOR * DeviceDescriptor;
  USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptor;
  uint32_t DeviceDescriptorSize;
  uint32_t ConfigurationDescriptorSize;
  osThreadId RecoveryThreadId;    // Thread ID of thread that activated Recovery
  uint8_t HubAddr;                // Hub communication Address
  uint8_t HubPort;                // Hub communication Port
  uint8_t DevAddr;                // Device communication Address
  uint8_t DevSpeed;               // Device communication Speed
  uint16_t VID;                   // Vendor ID
  uint16_t PID;                   // Product ID
  uint16_t MaxPacketSize;         // Maximum Xfer Size
  union
  {
    uint16_t State;               // Configured | Initialized
    struct
    {
      uint8_t Initialized;        // Device Initialized status
      uint8_t Configured;         // Device Configured status
    };
  };
  uint32_t Used;
} USBH_Device_TypeDef;

//------------------------------------------------------------------------------
// Class Functions : MSC, CDC, HID, ...
//
#define USBH_CLASS_CONFIGURE              ( 0 )
#define USBH_CLASS_UNCONFIGURE            ( 1 )
#define USBH_CLASS_INITIALIZE             ( 2 )
#define USBH_CLASS_UNINITIALIZE           ( 3 )

typedef int32_t (*ClassFunction)( USBH_Device_TypeDef * Device );

typedef struct _USBH_Class_TypeDef
{
  // Callback function called when custom class device is connected
  // and needs to configure resources used by custom class device instance
  // param[in]     Device              pointer to device structure.
  int32_t (*Configure)( USBH_Device_TypeDef * Device );

  // Callback function called when custom class device is disconnected
  // and needs to de-configure resources used by custom class device instance
  // param[in]     instance Index of custom class device instance.
  int32_t (*Unconfigure)( USBH_Device_TypeDef * Device );

  // Callback function called when custom class device is connected
  // and needs to initialize custom class device instance
  // param[in]     instance Index of custom class device instance.
  int32_t (*Initialize)( USBH_Device_TypeDef * Device );

  // called by USBH_UninitializeDevices() and USBH_EnumerateDevice()
  //
  // Callback function called when custom class device is disconnected
  // and needs to de-initialize custom class device instance
  // param[in]     instance Index of custom class device instance.
  int32_t (*Uninitialize)( USBH_Device_TypeDef * Device );
} USBH_Class_TypeDef;

//------------------------------------------------------------------------------
// USB Host Functions
//------------------------------------------------------------------------------
// Callback Functions for Host Controller Driver
//
// Initialize USB Host stack and controller
int32_t USBH_Initialize( HAL_USBH_TypeDef * USBH );

// Register USB Class to Host Controller
int32_t USBH_RegisterClass( HAL_USBH_TypeDef * USBH,
  const USBH_Class_TypeDef * Class );

int32_t USBH_Start( HAL_USBH_TypeDef * USBH );

int32_t USBH_Stop( HAL_USBH_TypeDef * USBH );

// Unregister USB Class from Host Controller
int32_t USBH_UnregisterClass( HAL_USBH_TypeDef * USBH,
  const USBH_Class_TypeDef * Class );

// De-initialize USB Host stack and controller
int32_t USBH_Uninitialize( HAL_USBH_TypeDef * USBH );

//------------------------------------------------------------------------------
// Create Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     DevAddr              device address.
// param[in]     DevSpeed             device speed.
// param[in]     HubAddr              hub address.
// param[in]     HubPort              hub port.
// param[in]     EndpAddr             endpoint address
//               - EndpAddr.0..3:     address
//               - EndpAddr.7:        direction
// param[in]     EndpType             endpoint type.
// param[in]     MaxPacketSize        endpoint maximum packet size.
// param[in]     ep_interval          endpoint polling interval.
//
// return        pointer to created pipe or pipe creation failed
// - value > 0:  pointer to created pipe
// - value 0:    pipe creation failed
HAL_USBH_Pipe_TypeDef * USBH_PipeCreate( HAL_USBH_TypeDef * USBH,
  uint8_t DevAddr, uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort,
  uint8_t EndpAddr, uint8_t EndpType, uint16_t MaxPacketSize, uint8_t Interval );

//------------------------------------------------------------------------------
// Modify Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
// param[in]     DevAddr              device address.
// param[in]     DevSpeed             device speed.
// param[in]     HubAddr              hub address.
// param[in]     HubPort              hub port.
// param[in]     MaxPacketSize        endpoint maximum packet size.
int32_t USBH_PipeModify( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe,
  uint8_t DevAddr, uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort,
  uint16_t MaxPacketSize );

//------------------------------------------------------------------------------
// Delete Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
int32_t USBH_PipeDelete( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe );

//------------------------------------------------------------------------------
// Reset Pipe (reset data toggle)
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
int32_t USBH_PipeReset( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe );

//------------------------------------------------------------------------------
// Abort send/receive operation on Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
int32_t USBH_PipeAbort( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe );

// Send Setup Xfer on Default Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     SetupPacket         pointer to setup packet.
int32_t USBH_PipeSendSetup( HAL_USBH_TypeDef * USBH,
  HAL_USBH_Pipe_TypeDef * Pipe, USB_SetupPacket_TypeDef * SetupPacket );

//------------------------------------------------------------------------------
// Send data on Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
// param[in]     buf                  buffer containing data bytes to send.
// param[in]     len                  maximum number of bytes to send.
int32_t USBH_PipeSend( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe,
  uint8_t * Data, uint32_t Size );

//------------------------------------------------------------------------------
// Get result of send data operation on Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
// return                             number of successfully sent data bytes.
int32_t USBH_PipeSendGetResult( HAL_USBH_TypeDef * USBH,
  HAL_USBH_Pipe_TypeDef * Pipe );

//------------------------------------------------------------------------------
// Receive data on Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
// param[out]    buf                  buffer that receives data.
// param[in]     len                  maximum number of bytes to receive.
int32_t USBH_PipeReceive( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe,
  uint8_t * Data, uint32_t Size );

//------------------------------------------------------------------------------
// Get result of receive data operation on Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     Pipe             pointer to pipe.
// return        number of successfully received data bytes.
int32_t USBH_PipeReceiveGetResult( HAL_USBH_TypeDef * USBH,
  HAL_USBH_Pipe_TypeDef * Pipe );

//------------------------------------------------------------------------------
// Default Pipe Functions : Call Pipe Functions with Default Pipe
//------------------------------------------------------------------------------
// Abort send/receive operation on Default Pipe
// param[in]     ctrl                 USB Host controller.
int32_t USBH_DefaultPipeAbort( HAL_USBH_TypeDef * USBH );

// Send Setup Xfer on Default Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     SetupPacket         pointer to setup packet.
int32_t USBH_DefaultPipeSendSetup( HAL_USBH_TypeDef * USBH,
  USB_SetupPacket_TypeDef * SetupPacket );

// Send data on Default Pipe
// param[in]     ctrl                 USB Host controller.
// param[in]     buf                  buffer containing data bytes to send.
// param[in]     len                  maximum number of bytes to send.
int32_t USBH_DefaultPipeSend( HAL_USBH_TypeDef * USBH, uint8_t * Data,
  uint32_t Size );

// Get result of send data operation on Default Pipe
// param[in]     ctrl                 USB Host controller.
// return                             number of successfully sent data bytes.
int32_t USBH_DefaultPipeSendGetResult( HAL_USBH_TypeDef * USBH );

// Receive data on Default Pipe
// param[in]     ctrl                 USB Host controller.
// param[out]    buf                  buffer that receives data.
// param[in]     len                  maximum number of bytes to receive.
int32_t USBH_DefaultPipeReceive( HAL_USBH_TypeDef * USBH, uint8_t * Data,
  uint32_t Size );

// Get result of receive data operation on Default Pipe
// param[in]     ctrl                 USB Host controller.
// return        number of successfully received data bytes.
int32_t USBH_DefaultPipeReceiveGetResult( HAL_USBH_TypeDef * USBH );

//------------------------------------------------------------------------------
// Control Transfer and Standard Request
//------------------------------------------------------------------------------
// Do a Control Transfer on Default Pipe
// param[in]     ctrl                USB Host controller.
// param[in]     SetupPacket         pointer to setup packet.
// param[in,out] data                 buffer containing data bytes to send or where data should be received in data stage of Control Transfer.
// param[in]     len                  number of bytes to send or receive in data stage of Control Transfer.
int32_t USBH_ControlTransfer( HAL_USBH_TypeDef * USBH,
  USB_SetupPacket_TypeDef * SetupPacket, uint8_t * Data, uint32_t Size );

// Standard Device Request on Default Pipe - GET_STATUS
// param[in]     ctrl                USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     Index                interface or endpoint Index.
// param[out]    ptr_stat_dat         pointer to where status data should be received.
int32_t USBH_DeviceRequest_GetStatus( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t Index, uint8_t * Status );

// Standard Device Request on Default Pipe - CLEAR_FEATURE
// param[in]     ctrl                USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     Index                interface or endpoint Index.
// param[in]     feature_selector     feature selector.
int32_t USBH_DeviceRequest_ClearFeature( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t Index, uint8_t FeatureSelector );

// Standard Device Request on Default Pipe - SET_FEATURE
// param[in]     ctrl                USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     Index                interface or endpoint Index.
// param[in]     feature_selector     feature selector.
int32_t USBH_DeviceRequest_SetFeature( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t Index, uint8_t FeatureSelector );

// Standard Device Request on Default Pipe - SET_ADDRESS
// param[in]     ctrl                USB Host controller.
// param[in]     Address       device address.
int32_t USBH_DeviceRequest_SetAddress( HAL_USBH_TypeDef * USBH,
  uint8_t Address );

// Standard Device Request on Default Pipe - GET_DESCRIPTOR
// param[in]     ctrl                USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     DescriptorType      descriptor type.
// param[in]     DescriptorIndex     descriptor Index.
// param[in]     LanguageId          language ID.
// param[out]    Descriptor      pointer to where descriptor data will be read.
// param[in]     DescriptorLength    descriptor length.
int32_t USBH_DeviceRequest_GetDescriptor( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t DescriptorType, uint8_t DescriptorIndex,
  uint8_t LanguageId, uint8_t * Descriptor, uint16_t DescriptorLength );

// Standard Device Request on Default Pipe - SET_DESCRIPTOR
// param[in]     ctrl                USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     DescriptorType      descriptor type.
// param[in]     DescriptorIndex     descriptor Index.
// param[in]     LanguageId          language ID.
// param[in]     Descriptor      pointer to descriptor data to be written.
// param[in]     DescriptorLength    descriptor length.
int32_t USBH_DeviceRequest_SetDescriptor( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t DescriptorType, uint8_t DescriptorIndex,
  uint8_t LanguageId, uint8_t * Descriptor, uint16_t DescriptorLength );

// Standard Device Request on Default Pipe - GET_CONFIGURATION
// param[in]     ctrl                USB Host controller.
// param[out]    Configuration    pointer to where Configuration will be read.
int32_t USBH_DeviceRequest_GetConfiguration( HAL_USBH_TypeDef * USBH,
  uint8_t * Configuration );

// Standard Device Request on Default Pipe - SET_CONFIGURATION
// param[in]     ctrl                USB Host controller.
// param[in]     Configuration        Configuration.
int32_t USBH_DeviceRequest_SetConfiguration( HAL_USBH_TypeDef * USBH,
  uint8_t Configuration );

// Standard Device Request on Default Pipe - GET_INTERFACE
// param[in]     ctrl                USB Host controller.
// param[in]     Index                interface Index.
// param[out]    AltSetting        pointer to where AltSetting setting data will be read.
int32_t USBH_DeviceRequest_GetInterface( HAL_USBH_TypeDef * USBH, uint8_t Index,
  uint8_t * AltSetting );

// Standard Device Request on Default Pipe - SET_INTERFACE
// param[in]     ctrl                USB Host controller.
// param[in]     Index                interface Index.
// param[in]     AltSetting            AltSetting setting.
int32_t USBH_DeviceRequest_SetInterface( HAL_USBH_TypeDef * USBH, uint8_t Index,
  uint8_t AltSetting );

// Standard Device Request on Default Pipe - SYNCH_FRAME
// param[in]     ctrl                USB Host controller.
// param[in]     Index                interface or endpoint Index.
// param[out]    ptr_frame_number     pointer to where frame number data will be read.
int32_t USBH_DeviceRequest_SynchFrame( HAL_USBH_TypeDef * USBH, uint8_t Index,
  uint8_t * FrameNumber );

// Get status of USB Device
// param[in]     device               Index of USB Device.
int32_t USBH_GetDeviceStatus( USBH_Device_TypeDef * Device );

int32_t USBH_RecoverDevice( USBH_Device_TypeDef * Device );

extern HAL_USBH_TypeDef HAL_USBH1;
extern HAL_USBH_TypeDef HAL_USBH2;

#endif
