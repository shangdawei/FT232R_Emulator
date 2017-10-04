#ifndef __USB_H__
#define __USB_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#pragma language=extended

//------------------------------------------------------------------------------
// Status code values returned by USB library functions.
//
// Driver Error Code
#define USB_OK                            (  0 )   // Operation succeeded
#define USB_ERROR                         ( -1 )   // Unspecified error
#define USB_ERROR_BUSY                    ( -2 )   // Driver is busy
#define USB_ERROR_TIMEOUT                 ( -3 )   // Timeout occurred
#define USB_ERROR_UNSUPPORTED             ( -4 )   // Operation not supported
#define USB_ERROR_PARAMETER               ( -5 )   // Parameter error
#define USB_ERROR_SEMAPHORE               ( -6 )   // Semaphore error
#define USB_ERROR_THREAD                  ( -7 )   // Thread error
#define USB_ERROR_TIMER                   ( -8 )   // Timer error
#define USB_ERROR_DEVICE                  ( -9 )   // Device error
#define USB_ERROR_MEMORY                  ( -10 )  // Memory error
//
// USB Specific Error Code
//
#define USB_ERROR_DRIVER                  ( DRIVER_ERROR_SPECIFIC - 0 )
#define USB_ERROR_NOT_CONFIGURED          ( DRIVER_ERROR_SPECIFIC - 1 )
#define USB_ERROR_HALT                    ( DRIVER_ERROR_SPECIFIC - 2 )
#define USB_ERROR_STALL                   ( DRIVER_ERROR_SPECIFIC - 3 )
#define USB_ERROR_NAK                     ( DRIVER_ERROR_SPECIFIC - 4 )
#define USB_ERROR_TRANSFER                ( DRIVER_ERROR_SPECIFIC - 5 )

//------------------------------------------------------------------------------
// Endianess handling macros
//
#if ( __LITTLE_ENDIAN__ > 0 )

#define U32_BE(v)                                 (uint32_t)(__rev(v))
#define U16_BE(v)                                 (uint16_t)(__rev(v) >> 16)
#define U32_LE(v)                                 (uint32_t)(v)
#define U16_LE(v)                                 (uint16_t)(v)

#else

#define U32_LE(v)                                 (uint32_t)(__rev(v))
#define U16_LE(v)                                 (uint16_t)(__rev(v) >> 16)
#define U32_BE(v)                                 (uint32_t)(v)
#define U16_BE(v)                                 (uint16_t)(v)

#endif

//------------------------------------------------------------------------------
// bmRequestType.Dir
#define USB_REQUEST_HOST_TO_DEVICE                0
#define USB_REQUEST_DEVICE_TO_HOST                1

//------------------------------------------------------------------------------
// bmRequestType.Type
#define USB_REQUEST_STANDARD                      0
#define USB_REQUEST_CLASS                         1
#define USB_REQUEST_VENDOR                        2
#define USB_REQUEST_RESERVED                      3

//------------------------------------------------------------------------------
// bmRequestType.Recipient
#define USB_REQUEST_TO_DEVICE                     0
#define USB_REQUEST_TO_INTERFACE                  1
#define USB_REQUEST_TO_ENDPOINT                   2
#define USB_REQUEST_TO_OTHER                      3

//------------------------------------------------------------------------------
// USB Standard Request Codes
#define USB_REQUEST_GET_STATUS                    0
#define USB_REQUEST_CLEAR_FEATURE                 1
#define USB_REQUEST_SET_FEATURE                   3
#define USB_REQUEST_SET_ADDRESS                   5
#define USB_REQUEST_GET_DESCRIPTOR                6
#define USB_REQUEST_SET_DESCRIPTOR                7
#define USB_REQUEST_GET_CONFIGURATION             8
#define USB_REQUEST_SET_CONFIGURATION             9
#define USB_REQUEST_GET_INTERFACE                 10
#define USB_REQUEST_SET_INTERFACE                 11
#define USB_REQUEST_SYNC_FRAME                    12

//------------------------------------------------------------------------------
// USB GET_STATUS Bit Values
#define USB_GETSTATUS_SELF_POWERED                0x01
#define USB_GETSTATUS_REMOTE_WAKEUP               0x02
#define USB_GETSTATUS_ENDPOINT_STALL              0x01

//------------------------------------------------------------------------------
// USB Standard Feature selectors
#define USB_FEATURE_ENDPOINT_STALL                0
#define USB_FEATURE_REMOTE_WAKEUP                 1

//------------------------------------------------------------------------------
// USB Descriptor Types
#define USB_DEVICE_DESCRIPTOR_TYPE                1
#define USB_CONFIGURATION_DESCRIPTOR_TYPE         2
#define USB_STRING_DESCRIPTOR_TYPE                3
#define USB_INTERFACE_DESCRIPTOR_TYPE             4
#define USB_ENDPOINT_DESCRIPTOR_TYPE              5
#define USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE      6
#define USB_OTHER_SPEED_CONFIG_DESCRIPTOR_TYPE    7

#define USB_INTERFACE_POWER_DESCRIPTOR_TYPE       8
#define USB_OTG_DESCRIPTOR_TYPE                   9
#define USB_DEBUG_DESCRIPTOR_TYPE                 10
#define USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE 11

//------------------------------------------------------------------------------
// USB Device Classes
#define USB_DEVICE_CLASS_RESERVED                 0x00
#define USB_DEVICE_CLASS_AUDIO                    0x01
#define USB_DEVICE_CLASS_COMMUNICATIONS           0x02
#define USB_DEVICE_CLASS_HUMAN_INTERFACE          0x03
#define USB_DEVICE_CLASS_MONITOR                  0x04
#define USB_DEVICE_CLASS_PHYSICAL_INTERFACE       0x05
#define USB_DEVICE_CLASS_POWER                    0x06
#define USB_DEVICE_CLASS_PRINTER                  0x07
#define USB_DEVICE_CLASS_STORAGE                  0x08
#define USB_DEVICE_CLASS_HUB                      0x09
#define USB_DEVICE_CLASS_MISCELLANEOUS            0xEF
#define USB_DEVICE_CLASS_VENDOR_SPECIFIC          0xFF

//------------------------------------------------------------------------------
// bmAttributes in Configuration Descriptor
#define USB_CONFIG_POWERED_MASK                   0x40
#define USB_CONFIG_BUS_POWERED                    0x80
#define USB_CONFIG_SELF_POWERED                   0xC0
#define USB_CONFIG_REMOTE_WAKEUP                  0x20

//------------------------------------------------------------------------------
// bMaxPower in Configuration Descriptor
#define USB_CONFIG_POWER_MA(mA)                   ((mA)/2)

//------------------------------------------------------------------------------
// bEndpointAddress in Endpoint Descriptor
#define USB_ENDPOINT_DIRECTION_MASK               0x80
#define USB_ENDPOINT_OUT(addr)                    ((addr) | 0x00)
#define USB_ENDPOINT_IN(addr)                     ((addr) | 0x80)

//------------------------------------------------------------------------------
// bmAttributes in Endpoint Descriptor
#define USB_ENDPOINT_TYPE_MASK                    0x03
#define USB_ENDPOINT_TYPE_CONTROL                 0x00
#define USB_ENDPOINT_TYPE_ISOCHRONOUS             0x01
#define USB_ENDPOINT_TYPE_BULK                    0x02
#define USB_ENDPOINT_TYPE_INTERRUPT               0x03
#define USB_ENDPOINT_SYNC_MASK                    0x0C
#define USB_ENDPOINT_SYNC_NO_SYNCHRONIZATION      0x00
#define USB_ENDPOINT_SYNC_ASYNCHRONOUS            0x04
#define USB_ENDPOINT_SYNC_ADAPTIVE                0x08
#define USB_ENDPOINT_SYNC_SYNCHRONOUS             0x0C
#define USB_ENDPOINT_USAGE_MASK                   0x30
#define USB_ENDPOINT_USAGE_DATA                   0x00
#define USB_ENDPOINT_USAGE_FEEDBACK               0x10
#define USB_ENDPOINT_USAGE_IMPLICIT_FEEDBACK      0x20
#define USB_ENDPOINT_USAGE_RESERVED               0x30

//------------------------------------------------------------------------------
// USB - Timeout
//
// Default timeout for all setup requests.
// After this time a not completed setup request is terminated.
#define USB_SETUP_TIMEOUT                   1000
#define USB_SETUP_DATA_STAGE_TIMEOUT        1000
#define USB_SETUP_NO_DATA_STAGE_TIMEOUT     500
//
// Specifies the maximum time in milliseconds,
// for reading all bytes with the bulk read operation.
#define USB_READ_TIMEOUT                    1000
//
// Specifies the maximum time, in milliseconds,
// for writing all bytes with the bulk write operation.
#define USB_WRITE_TIMEOUT                   1000

//------------------------------------------------------------------------------
// USB - Timing
//
// The bus controller waits this time after port is powered
// before a port connect change interrupt enable
#define USB_POWREUP_TIME                    200
//
// The bus controller waits this time after
// a USB device connect event is detected
// before a USB bus reset is applied to the device
#define USB_DEBOUNCE_TIME                   200
//
// The host controller waits this time after reset
// before the Set Address command is sent. Some devices require some time
// before they can answer correctly.
// It is not required by the USB specification
// but Windows makes this gap with 80 ms.
#define USB_RESET_TIME                      80
//
// Give the device this time to set the new address.
// The bus driver waits this time before the next command is sent
// after Set Address. The device must answer to SetAddress on USB address 0
// with the handshake and than set the new address.
// This is a potential racing condition if this step is performed in the firmware.
#define USB_SETADDRESS_TIME                 30
//
// If the device makes an error during USB reset and set address
// the enumeration process is repeated.
// The repeat count is defined by this define.
// Possible errors are OverCurrent, remove during reset,
// no answer to SetAddress.
#define USB_ENUM_ERROR_LIMIT                10
//
// Describes the time before a USB reset is restarted if the last try has failed.
// If the enumeration of the device (get descriptors, set configuration) fails,
// it is repeated after a time gap of this value
#define USB_ENUM_RETRY_TIME                 1000

#define USB_ENUM_RETRY_LIMIT                10

#define WBVAL(x)                                  \
  ( (x) & 0xFF), ( ( (x) >> 8) & 0xFF )
#define B3VAL(x)                                  \
  ( (x) & 0xFF), ( ( (x) >> 8) & 0xFF), ( ( (x) >> 16) & 0xFF)

#define USB_DEVICE_DESC_SIZE                      \
  (sizeof(USB_DEVICE_DESCRIPTOR))
#define USB_DEVICE_QUALI_SIZE                     \
  (sizeof(USB_DEVICE_QUALIFIER_DESCRIPTOR))
#define USB_CONFIGURATION_DESC_SIZE               \
  (sizeof(USB_CONFIGURATION_DESCRIPTOR))
#define USB_INTERFACE_ASSOC_DESC_SIZE             \
  (sizeof(USB_INTERFACE_ASSOCIATION_DESCRIPTOR))
#define USB_INTERFACE_DESC_SIZE                   \
  (sizeof(USB_INTERFACE_DESCRIPTOR))
#define USB_ENDPOINT_DESC_SIZE                    \
  (sizeof(USB_ENDPOINT_DESCRIPTOR))
#define USB_HID_DESC_SIZE                         \
  (sizeof(HID_DESCRIPTOR))

// USB Standard Device Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint16_t bcdUSB;
  uint8_t bDeviceClass;
  uint8_t bDeviceSubClass;
  uint8_t bDeviceProtocol;
  uint8_t bMaxPacketSize0;
  uint16_t idVendor;
  uint16_t idProduct;
  uint16_t bcdDevice;
  uint8_t iManufacturer;
  uint8_t iProduct;
  uint8_t iSerialNumber;
  uint8_t bNumConfigurations;
} USB_DEVICE_DESCRIPTOR;

// USB 2.0 Device Qualifier Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint16_t bcdUSB;
  uint8_t bDeviceClass;
  uint8_t bDeviceSubClass;
  uint8_t bDeviceProtocol;
  uint8_t bMaxPacketSize0;
  uint8_t bNumConfigurations;
  uint8_t bReserved;
} USB_DEVICE_QUALIFIER_DESCRIPTOR;

// USB Standard Configuration Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint16_t wTotalLength;
  uint8_t bNumInterfaces;
  uint8_t bConfigurationValue;
  uint8_t iConfiguration;
  uint8_t bmAttributes;
  uint8_t bMaxPower;
} USB_CONFIGURATION_DESCRIPTOR;

/*
 * The configuration descriptor defines how fields of a high speed device's
 * configuration descriptor change if that device is run at its other speed.
 *
 * Fields of this descriptor reflect configuration descriptor field changes
 * if a device's speed is changed from full to high speed,
 * or from high to full speed.
 *
 * Please refer to Section 9.6.4 of the USB 2.0 specification.
 * The USB 2.0 specification is available at www.usb.org.
 */
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType; // USB_OTHER_SPEED_CONFIG_DESCRIPTOR_TYPE
  uint16_t wTotalLength;
  uint8_t bNumInterfaces;
  uint8_t bConfigurationValue;
  uint8_t iConfiguration;
  uint8_t bmAttributes;
  uint8_t bMaxPower;
} USB_OTHER_SPEED_CONFIG_DESCRIPTOR;

// USB Standard Interface Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bInterfaceNumber;
  uint8_t bAlternateSetting;
  uint8_t bNumEndpoints;
  uint8_t bInterfaceClass;
  uint8_t bInterfaceSubClass;
  uint8_t bInterfaceProtocol;
  uint8_t iInterface;
} USB_INTERFACE_DESCRIPTOR;

// USB Standard Endpoint Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bEndpointAddress;
  uint8_t bmAttributes;
  uint16_t wMaxPacketSize;
  uint8_t bInterval;
} USB_ENDPOINT_DESCRIPTOR;

// USB String Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint16_t bString;
} USB_STRING_DESCRIPTOR;

typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint16_t langid;
} USB_LANG_ID_STRING_DESCRIPTOR;

// USB Common Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
} USB_COMMON_DESCRIPTOR;

// USB Interface Association Descriptor
typedef __packed struct
{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t bFirstInterface;
  uint8_t bInterfaceCount;
  uint8_t bFunctionClass;
  uint8_t bFunctionSubclass;
  uint8_t bFunctionProtocol;
  uint8_t iFunction;
} USB_INTERFACE_ASSOCIATION_DESCRIPTOR;

//------------------------------------------------------------------------------
// bmRequestType Definition
typedef __packed struct
{
  union
  {
    uint8_t RequestType;
    struct
    {
      uint8_t Recipient :5;                 // D4..0: Recipient
      uint8_t Type :2;                      // D6..5: Type
      uint8_t Dir :1;                       // D7:    Data Transfer Direction
    };
  };
} USB_RequestType_TypeDef;

//------------------------------------------------------------------------------
// USB Default Control Pipe Setup Xfer
typedef __packed struct
{
  USB_RequestType_TypeDef bmRequestType;       // Characteristics of request
  uint8_t bRequest;            // Specific request
  __packed union
  {
    uint16_t wValue;              // Value according to request
    __packed struct
    {
      uint8_t wValueL;
      uint8_t wValueH;
    };
  };
  __packed union
  {
    uint16_t wIndex;              // Index or Offset according to request
    __packed struct
    {
      uint8_t wIndexL;
      uint8_t wIndexH;
    };
  };
  uint16_t wLength;    // Number of bytes to transfer if there is a Data stage
} USB_SetupPacket_TypeDef;

void USB_GetEndpointDescriptorList(
  const USB_CONFIGURATION_DESCRIPTOR * pConfDescriptor,
  uint8_t bInterfaceNumber, uint8_t bAlternateSetting,
  USB_ENDPOINT_DESCRIPTOR** pEpDescriptor );

#ifdef __cplusplus
}
#endif

#endif
