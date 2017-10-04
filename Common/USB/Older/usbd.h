#ifndef __USBD_H__
#define __USBD_H__

#include "board.h"
#include "driver.h"
#include "os.h"

#include "usb.h"

//------------------------------------------------------------------------------
// Start of section using anonymous unions
#pragma language=extended

//------------------------------------------------------------------------------
// USB Device - Endpoint Descriptor Macros
// USBD_EP0(n) : USBD0_MAX_PACKET0
//
#define USBD_EP0( mps0 )        /* Endpoint 0*/         \
  USB_ENDPOINT_DESC_SIZE,       /* bLength*/            \
  USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType*/    \
  0,                            /* bEndpointAddress*/   \
  USB_ENDPOINT_TYPE_CONTROL,    /* bmAttributes*/       \
  mps0,                         /* wMaxPacketSize*/     \
  0                             /* bInterval*/

//------------------------------------------------------------------------------
// USB Device - String Descriptor Macros
#define USBD_STR_VAR(n)                                 \
  StringDescriptor_##n

#define USBD_STR_VAL(n)                                 \
 { sizeof(n), USB_STRING_DESCRIPTOR_TYPE, n }

#define USBD_STR_DEF(n)                                 \
  struct __StringDescriptor_##n                         \
  {                                                     \
    uint8_t  Length;                                    \
    uint8_t  Type;                                      \
    uint16_t Str[sizeof(n)/2-1];                        \
  };                                                    \
  static struct __StringDescriptor_##n StringDescriptor_##n =  \
  USBD_STR_VAL(n)

#define USBD_STR_LANGID_DEF(id)                         \
  struct __StringDescriptor_##id                        \
  {                                                     \
    uint8_t  Length;                                    \
    uint8_t  Type;                                      \
    uint16_t LangId;                                    \
  };                                                    \
  static struct __StringDescriptor_##id StringDescriptor_##id = \
  { 4, USB_STRING_DESCRIPTOR_TYPE, id }

#define USBD_STR_LANGID_VAR(name)                       \
  StringDescriptor_##name

/* The way the USB architecture is designed, the upstream hardware (hosts/hubs)
 * will automatically try to connect at the highest speed possible.
 * On device attachment, the host attempts high-speed signaling.
 * If the device responds, the host communicates at high speed.
 * Otherwise, the host uses full speed.
 * This occurs before the host knows anything about the device.
 *
 * If the device is attached to a USB 1.1 hub, is operating at Full-Speed,
 * and its USB Device Descriptor bcdUSB field is greater than or equal to 0x200,
 * the hub driver will issue a GET_DESCRIPTOR for desc type DEVICE_QUALIFIER (6)
 * The successful completion of the request indicates the device can support
 * USB 2.0 high-speed operation.
 *
 * If a full-speed only device receives a GetDescriptor() request
 * for a device_qualifier, it must respond with a request error.
 *
 * The host must not make a request for an other_speed_configuration descriptor.
 * unless it first successfullyretrieves the device_qualifier descriptor.
 *
 * Device Qualifier Descriptor
 *
 * A high-speed capable device that has different device information for
 * full-speed and high-speed must also have a Device Qualifier Descriptor.
 * For example, if the device is currently operating at full-speed,
 * the Device Qualifier returns information about how it would operate
 * at high-speed and vice-versa.
 * The fields for the vendor, product, device, manufacturer, and serial number
 * are not included. This information is constant for a device regardless of
 * the supported speeds.
 *
 * Other Speed Configuration Descriptor
 *
 * The other_speed_configuration descriptor describes a configuration of
 * a highspeed capabledevice if it were operating at its other possible speed.
 *
 * A USB 2.0 device will _never_ connect as USB 1.1.
 * No matter what speed it operates at, it will always report its bcdUSB value
 * as 0x0200.  This is required by the USB 2.0 spec.
 *
 * Furthermore, you can't rely on the "other speed config" descriptor
 * to tell you what speed a USB 2.0 device is running at.
 * If it's running at full speed then the "other speed config" descriptor
 * will be for a high-speed configuration, and vice versa,
 * if it's running at high speed then the "other speed config" descriptor
 * will be for a full-speed configuration.
 *
 * you just ask for the current configuration descriptor.
 * If the one you get is your high-speed descriptor, then you are
 * running high-speed.  If the one you get is your full-speed descriptor,
 * then you are running full-speed.
 *
 * The most notable distinction is the size of Bulk endpoint maxpacket values.
 *
 */
typedef struct
{
  const USB_DEVICE_DESCRIPTOR * DeviceDescriptor;

  const USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptor;
  // High Speed Device ---------------------------------------------------------
  const USB_DEVICE_QUALIFIER_DESCRIPTOR * DeviceQualifier;
  const USB_OTHER_SPEED_CONFIG_DESCRIPTOR * OtherSpeedConfigurationDescriptor;
  //
  const USB_DEVICE_QUALIFIER_DESCRIPTOR * DeviceQualifierHighSpeed;
  const USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptorHighSpeed;
  const USB_OTHER_SPEED_CONFIG_DESCRIPTOR * OtherSpeedConfigurationDescriptorHighSpeed;
} USBD_Descriptors_TypeDef;

#define USBD_CLASS_ADC          ( 0x01 )
#define USBD_CLASS_CDC          ( 0x02 )
#define USBD_CLASS_HID          ( 0x03 )
#define USBD_CLASS_MSC          ( 0x08 )
#define USBD_CLASS_WINUSB       ( 0xFF )

typedef struct _HAL_USBD_TypeDef HAL_USBD_TypeDef;

typedef struct
{
  uint8_t ClassCode;
  uint32_t StackSize;
  uint32_t * ThreadStack;
  osThreadId ThreadData;
  uint32_t OtherConfig;
} USBD_Class_Config_TypeDef;

typedef struct
{
  HAL_USBD_TypeDef * USBD;
  uint8_t InterfaceNumber;
  uint8_t InEndpoint;
  uint8_t OutEndpoint;
  uint32_t OtherData;
} USBD_Class_Data_TypeDef;

typedef struct
{
  // Called during Class Initialize
  void (*Initialize)( void );
  // Called during Class Uninitialize
  void (*Uninitialize)( void );
  // Called during USB Bus Reset
  void (*Reset)( void );
  // Other Callback for Class
  void (*OtherCallback)( void );
} USBD_Class_Callback_TypeDef;

typedef struct _USBD_Class_TypeDef USBD_Class_TypeDef;

typedef struct
{
  // For All Classes
  void (*Initialize)( const USBD_Class_TypeDef * Class );
  void (*Uninitialize)( const USBD_Class_TypeDef * Class );
  void (*Reset)( const USBD_Class_TypeDef * Class );

  // For Class which EndpAddr Matched
  int32_t (*EndpointStarted)( const USBD_Class_TypeDef * Class,
    uint8_t EndpAddr );
  int32_t (*EndpointStopped)( const USBD_Class_TypeDef * Class,
    uint8_t EndpAddr );
  int32_t (*EndpointDataSent)( const USBD_Class_TypeDef * Class,
    uint8_t EndpAddr );
  int32_t (*EndpointDataReceived)( const USBD_Class_TypeDef * Class,
    uint8_t EndpAddr );
  //
  // Option --------------------------------------------------------------------
  int32_t (*SetupPacketReceived)( const USBD_Class_TypeDef * Class,
    USB_SetupPacket_TypeDef * SetupPacket, uint8_t ** InOutData,
    uint16_t * Size );
  int32_t (*SetupDataReceived)( const USBD_Class_TypeDef * Class,
    USB_SetupPacket_TypeDef * SetupPacket, uint32_t Size );
  int32_t (*SetupDataSent)( const USBD_Class_TypeDef * Class,
    USB_SetupPacket_TypeDef * SetupPacket, uint32_t Size );
  //
  // MSC Only ------------------------------------------------------------------
  int32_t (*CanClearEndpointHalt)( const USBD_Class_TypeDef * Class,
    uint8_t EndpAddr );
  int32_t (*EndpointHaltClear)( const USBD_Class_TypeDef * Class,
    uint8_t EndpAddr );
} USBD_Class_Handler_TypeDef;

struct _USBD_Class_TypeDef
{
  void * Data;                                  // USBD_Class_Data_TypeDef
  const void * Config;                          // USBD_Class_Config_TypeDef
  const void * Callback;                        // USBD_Class_Callback_TypeDef
  const USBD_Class_Handler_TypeDef * Handler;   // USBD_Class_Handler_TypeDef
};

struct _HAL_USBD_TypeDef
{
  // Compiler Time
  uint8_t ClassNum;                       // Max Class Number
  uint8_t SupportHighSpeed;               // High Speed
  uint8_t bmAttributes;                   // bmAttributes configuration setting
  uint8_t MaxPacketSize0;                 //
  uint32_t StackSize;                     // = BOARD_USBDx_THREAD_STACK_SIZE
  uint32_t * ThreadStack;                 // = &HAL_USBD0_ThreadStack[]
  osThreadId ThreadData;                  // = &HAL_USBDx_Thread
  osSemaphoreId SemaphoreData;            // = &HAL_USBDx_Semaphore
  uint8_t * AltSetting;                   // = &HAL_USBDx_AltSetting[ 16 ]
  USB_SetupPacket_TypeDef * SetupPacket;  // &HAL_USBDx_SetupPacket
  const DRV_USBD_TypeDef * Instance;      // &USBDx_Instance
  const USBD_Driver_TypeDef * Driver;     // &USBD_Driver
  const USBD_Class_TypeDef ** ClassArray;
  DRV_USBD_DeviceEventHandler_TypeDef DeviceEventHandler;
  DRV_USBD_EndpointEventHandler_TypeDef EndpointEventHandler;
  void (*Initialize)( void );
  void (*Uninitialize)( void );
  int32_t (*GetDeviceDescriptor)( uint8_t ** Descriptor, uint16_t * Size );
  int32_t (*GetConfigurationDescriptor)( uint8_t ** Descriptor,
    uint16_t * Size );
  int32_t (*GetDeviceQualifilerDescriptor)( uint8_t ** Descriptor,
    uint16_t * Size );
  int32_t (*GetOtherSpeedConfigurationDescriptor)( uint8_t ** Descriptor,
    uint16_t * Size );
  int32_t (*GetStringDescriptor)( uint32_t Index, uint8_t ** Descriptor,
    uint16_t * Size );
  //
  // Run Time
  //
  const DRV_USBD_Capabilities_TypeDef * Capabilities;
  osThreadId ThreadId;
  osSemaphoreId SemaphoreId;
  //
  // the follow members are clear (except Status ) when core is reset
  // Status is assigned from bmAttributes ( Device->bmAttributes )
  uint16_t Status;              // device status (remote wakeup, self powered)
  //
  uint16_t InHighSpeed;         // information if device is in high speed
  uint8_t Buffer[ 2 ];          // ReqStatus Buffer
  uint8_t Address;              // device address on the bus
  uint8_t Configuration;        // active configuration
  uint8_t InterfaceCount;       // number of interfaces
  uint8_t SendZLP;              // zero length packet flag
  uint16_t RequestHooked;       // externally handled request
  uint16_t EP0_Size;            // number of bytes in data buffer to Xfer
  uint8_t * EP0_Data;           // data buffer for send or receive
  uint32_t EndpointActived;     // mask containing active endpoints
  uint32_t EndpointHalted;      // mask containing halted endpoints
  uint32_t TransferActived;     // mask containing active transfers
};

//------------------------------------------------------------------------------
// USBD API
//------------------------------------------------------------------------------
//
void USBD_DeviceEventHandler( HAL_USBD_TypeDef * USBD, uint32_t Event );
void USBD_EndpointEventHandler( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr,
  uint32_t Event );

// Initialize USB Device stack and controller
int32_t USBD_Initialize( HAL_USBD_TypeDef * USBD );

// De-initialize USB Device stack and controller
int32_t USBD_Uninitialize( HAL_USBD_TypeDef * USBD );

int32_t USBD_Connect( HAL_USBD_TypeDef * USBD );

int32_t USBD_Disconnect( HAL_USBD_TypeDef * USBD );

// Return USB Device configuration status
uint32_t USBD_Configured( HAL_USBD_TypeDef * USBD );

// Start reception/write on Endpoint
int32_t USBD_EndpointTransfer( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr,
  uint8_t * Buffer, uint32_t Length );

// Get result of read/write operation on Endpoint
int32_t USBD_EndpointTransferGetResult( HAL_USBD_TypeDef * USBD,
  uint8_t EndpAddr );

// Set/Clear stall on Endpoint
int32_t USBD_EndpointStall( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr,
  uint32_t Stall );

// Abort read/write operation on Endpoint
int32_t USBD_EndpointAbort( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr );

#endif
