/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_H__
#define __USBD_H__

#ifdef __cplusplus
"C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "usb_type.h"

// Status code values returned by USB library functions.
typedef enum
{
  usbOK = 0,                            // Function completed with no error

  usbTimeout,                           // Function completed; time-out occurred
  usbInvalidParameter,                  // Invalid Parameter error: a mandatory parameter was missing
                                        //    or specified an incorrect object
  usbThreadError = 0x10,                // CMSIS-RTOS Thread creation/termination failed
  usbTimerError,                        // CMSIS-RTOS Timer creation/deletion failed
  usbSemaphoreError,                    // CMSIS-RTOS Semaphore creation failed
  usbMutexError,                        // CMSIS-RTOS Mutex creation failed

  usbControllerError = 0x20,            // Controller does not exist
  usbDeviceError,                       // Device does not exist
  usbDriverError,                       // Driver function produced error
  usbDriverBusy,                        // Driver function is busy
  usbMemoryError,                       // Memory management function produced error
  usbNotConfigured,                     // Device is not configured (is connected)
  usbClassErrorADC,                     // Audio Device Class (ADC) error (no device or device produced error)
  usbClassErrorCDC,                     // Communication Device Class (CDC) error (no device or device produced error)
  usbClassErrorHID,                     // Human Interface Device (HID) error (no device or device produced error)
  usbClassErrorMSC,                     // Mass Storage Device (MSC) error (no device or device produced error)
  usbClassErrorCustom,                  // Custom device Class (Class) error (no device or device produced error)
  usbUnsupportedClass,                  // Unsupported Class

  usbTransferStall = 0x40,   // Transfer handshake was stall
  usbTransferError,                     // Transfer error

  usbUnknownError = 0xFF    // Unspecified USB error
} USBD_Status_TypeDef;

// USB Device Custom Class API enumerated constants
typedef enum
{
  usbdRequestNotProcessed = 0,          // Request not processed
  usbdRequestOK,                        // Request processed and OK
  usbdRequestStall,                     // Request processed but unsupported
  usbdRequestNAK                        // Request processed but busy
} USBD_RequestStatus_TypeDef;

// Structure containing all descriptors (except report descriptor)
typedef struct
{
  uint8_t *device_descriptor;                   // device descriptor
  uint8_t *config_descriptor;                   // configuration descriptor for low/full-speed
  uint8_t *device_qualifier_fs;                 // device qualifier for low/full-speed
  uint8_t *device_qualifier_hs;                 // device qualifier for high-speed
  uint8_t *config_descriptor_hs;                // configuration descriptor for high-speed
  uint8_t *other_speed_config_descriptor_fs;    // other speed configuration descriptor for low/full-speed
  uint8_t *other_speed_config_descriptor_hs;    // other speed configuration descriptor for high-speed
} USBD_Descriptor_TypeDef;

typedef struct
{
  // following functions are available for each instance of a Custom class.
  // generic prefix USBD_CustomClassn is USBD_CustomClass0 for Custom class instance 0.

  // \brief Called during \ref USBD_Initialize to initialize the USB Custom class instance
  // \return                             none.
  void (*USBD_Class_Initialize)( void );

  // \brief Called during \ref USBD_Uninitialize to de-initialize the USB Custom class instance
  // \return                             none.
  void (*USBD_Class_Uninitialize)( void );

  // \brief Custom Class Reset Event handling
  // \return                             none.
  void (*USBD_Class_EventReset)( void );

  // \brief Callback function called when DATA was sent or received on Endpoint n
  // \param[in]     ep_addr              endpoint address
  // \param[in]     event                event on Endpoint:
  //                                     - ARM_USBD_EVENT_START = Endpoint Start Event
  //                                     - ARM_USBD_EVENT_STOP = Endpoint Stop Event
  //                                     - ARM_USBD_EVENT_OUT = Endpoint data OUT received
  //                                     - ARM_USBD_EVENT_IN  = Endpoint data IN  sent
  void (*USBD_Class_EventEndpoint)( uint8_t ep_addr, uint32_t event );

  // \brief Callback function called when a SETUP PACKET was received on Control Endpoint 0
  // \param[in]     SetupPacket         pointer to received setup packet.
  // \param[out]    buf                  pointer to data buffer used for data stage requested by setup packet.
  // \param[out]    len                  pointer to number of data bytes in data stage requested by setup packet.
  // \return        usbdRequestStatus    enumerator value indicating the function execution status
  // \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
  // \return        usbdRequestOK:       request was processed successfully )( send Zero-Length Packet if no data stage)
  // \return        usbdRequestStall:    request was processed but is not supported )( STALL EP)
  USBD_RequestStatus_TypeDef (*USBD_Class_Endpoint0_SetupPacketReceived)( const USB_SetupPacket_TypeDef *SetupPacket,
    uint8_t **buf, uint32_t *len );

  // \brief Callback function called when a SETUP PACKET was processed by USB library
  // \param[in]     SetupPacket         pointer to processed setup packet.
  // \return                             none.
  void (*USBD_Class_Endpoint0_SetupPacketProcessed)( const USB_SetupPacket_TypeDef *SetupPacket );

  // \brief Callback function called when OUT DATA was received on Control Endpoint 0
  // \param[in]     len                  number of received data bytes.
  // \return        usbdRequestStatus    enumerator value indicating the function execution status
  // \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
  // \return        usbdRequestOK:       request was processed successfully )( send Zero-Length Packet)
  // \return        usbdRequestStall:    request was processed but is not supported )( stall endpoint 0)
  // \return        usbdRequestNAK:      request was processed but the device is busy )( return NAK)
  USBD_RequestStatus_TypeDef (*USBD_Class_Endpoint0_OutDataReceived)( uint32_t len );

  // \brief Callback function called when IN DATA was sent on Control Endpoint 0
  // \param[in]     len                  number of sent data bytes.
  // \return        usbdRequestStatus    enumerator value indicating the function execution status
  // \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
  // \return        usbdRequestOK:       request was processed successfully )( return ACK)
  // \return        usbdRequestStall:    request was processed but is not supported )( stall endpoint 0)
  // \return        usbdRequestNAK:      request was processed but the device is busy )( return NAK)
  USBD_RequestStatus_TypeDef (*USBD_Class_Endpoint0_InDataSent)( uint32_t len );

} USBD_ClassCallbacks_TypeDef;

typedef struct
{
  const USBD_ClassCallbacks_TypeDef * callbacks;
  uint8_t device;                       // device instance
  void * context;                       // used by class only
} USBD_Class_TypeDef;

typedef struct
{
  // \brief Device Get string descriptors Event handling
  // \return                             length of string descriptor
  uint8_t * (*USBD_Device_StringDescriptor)( uint8_t index, uint16_t * length );

  // \brief Called during \ref USBD_Initialize to initialize the USB Device
  // \return                             none.
  void (*USBD_Device_Initialize)( void );

  // \brief Called during \ref USBD_Uninitialize to de-initialize the USB Device
  // \return                             none.
  void (*USBD_Device_Uninitialize)( void );

  // \brief Device Reset Event handling
  // \return                             none.
  void (*USBD_Device_EventReset)( void );

  // \brief Device SOF Event handling
  // \return                             none.
  void (*USBD_Device_EventSOF)( void );

  // \brief Device Configured Event handling
  // \return                             none.
  void (*USBD_Device_EventConfigured)( uint8_t index );

  // \brief Device Suspended Event handling
  // \return                             none.
  void (*USBD_Device_EventSuspended)( void );

  // \brief Device Resumed Event handling
  // \return                             none.
  void (*USBD_Device_EventResumed)( void );

  // \brief Callback function called when DATA was sent or received on Endpoint n
  // \param[in]     ep_addr              endpoint address
  // \param[in]     event                event on Endpoint:
  //                                     - ARM_USBD_EVENT_START = Endpoint Start Event
  //                                     - ARM_USBD_EVENT_STOP = Endpoint Stop Event
  //                                     - ARM_USBD_EVENT_OUT = Endpoint data OUT received
  //                                     - ARM_USBD_EVENT_IN  = Endpoint data IN  sent
  void (*USBD_Device_EventEndpoint)( uint8_t ep_addr, uint32_t event );

  // \brief Callback function called when a SETUP PACKET was received on Control Endpoint 0
  // \param[in]     SetupPacket         pointer to received setup packet.
  // \param[out]    buf                  pointer to data buffer used for data stage requested by setup packet.
  // \param[out]    len                  pointer to number of data bytes in data stage requested by setup packet.
  // \return        usbdRequestStatus    enumerator value indicating the function execution status
  // \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
  // \return        usbdRequestOK:       request was processed successfully )( send Zero-Length Packet if no data stage)
  // \return        usbdRequestStall:    request was processed but is not supported )( STALL EP)
  USBD_RequestStatus_TypeDef (*USBD_Device_Endpoint0_SetupPacketReceived)( USB_SetupPacket_TypeDef *SetupPacket,
    uint8_t **buf, uint16_t *len );

  // \brief Callback function called when a SETUP PACKET was processed by USB library
  // \param[in]     SetupPacket         pointer to processed setup packet.
  // \return                             none.
  void (*USBD_Device_Endpoint0_SetupPacketProcessed)( USB_SetupPacket_TypeDef *SetupPacket );

  // \brief Callback function called when OUT DATA was received on Control Endpoint 0
  // \param[in]     len                  number of received data bytes.
  // \return        usbdRequestStatus    enumerator value indicating the function execution status
  // \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
  // \return        usbdRequestOK:       request was processed successfully )( send Zero-Length Packet)
  // \return        usbdRequestStall:    request was processed but is not supported )( stall endpoint 0)
  // \return        usbdRequestNAK:      request was processed but the device is busy )( return NAK)
  USBD_RequestStatus_TypeDef (*USBD_Device_Endpoint0_OutDataReceived)( uint32_t len );

  // \brief Callback function called when IN DATA was sent on Control Endpoint 0
  // \param[in]     len                  number of sent data bytes.
  // \return        usbdRequestStatus    enumerator value indicating the function execution status
  // \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
  // \return        usbdRequestOK:       request was processed successfully )( return ACK)
  // \return        usbdRequestStall:    request was processed but is not supported )( stall endpoint 0)
  // \return        usbdRequestNAK:      request was processed but the device is busy )( return NAK)
  USBD_RequestStatus_TypeDef (*USBD_Device_Endpoint0_InDataSent)( uint32_t len );

} USBD_DeviceCallbacks_TypeDef;

typedef struct
{
  uint16_t device_status;                     // device status (remote wakeup, self powered)
  uint8_t device_address;                     // device address on the bus
  volatile uint8_t configuration;             // active configuration
  uint8_t interface;                          // active interface
  uint32_t endpoint_mask;                     // mask containing active endpoints
  uint32_t endpoint_halt;                     // mask containing halted endpoints
  uint32_t endpoint_no_halt_clr;              // mask containing endpoints on which halt clear is prevented
  uint8_t endpoint_active[ 32 ];              // endpoint active transfer
  uint8_t num_interfaces;                     // number of available interfaces
  uint8_t high_speed;                         // information if device is in high speed
  uint8_t zlp;                                // zero length packet flag
  uint8_t ext_handle;                         // externally handled request
  uint8_t *ep0_data;                          // Control Endpoint 0 data buffer for send or receive
  uint16_t ep0_cnt;                           // Control Endpoint 0 # of bytes in data buffer (to send or received)
  USB_SetupPacket_TypeDef SetupPacket;        // Setup Packet structure
  uint8_t *buf;                               // Buffer for in/out data
  int32_t len;                                // Length for in/out data
} USBD_Context_TypeDef;

typedef struct
{
  const USBD_DeviceCallbacks_TypeDef * callback;
  const USBD_Descriptor_TypeDef * descriptor;
  USBD_Class_TypeDef ** classes;              // CDC + MSC
  uint8_t *alt_setting;                       // pointer to alternate settings
  uint8_t *ep0_buf;                           // pointer to Control Endpoint 0 buffer
  USBD_Context_TypeDef * context;             // pointer to structure containing device information
  uint8_t bmattributes;                       // bmAttributes configuration setting
  uint8_t hs;                                 // high-speed capability setting
  uint16_t if_num;                            // number of interfaces
  uint8_t ep_num;                             // number of endpoints
  uint8_t max_packet0;                        // maximum packet size for Control Endpoint 0
  void /* ARM_DRIVER_USBD */*driver;          // pointer to driver
} USBD_Device_TypeDef;

extern USBD_Device_TypeDef * USBD_Device;

// \brief Initialize USB Device stack and controller
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_Initialize( uint8_t device );

// \brief De-initialize USB Device stack and controller
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_Uninitialize( uint8_t device );

// \brief Activate pull-up on D+ or D- line to signal USB Device connection on USB Bus
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_Connect( uint8_t device );

// \brief Disconnect USB Device from USB Bus
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_Disconnect( uint8_t device );

// \brief Return USB Device configuration status
// \param[in]     device               index of USB Device.
// \return        true                 device is in configured state and ready to communicate.
// \return        false                device is not configured and not ready to communicate.
uint32_t USBD_Configured( uint8_t device );

// \brief Configure an Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[out]    ep_mps               endpoint Max Packet Size
// \param[in]     ep_type              endpoint type, CTRL, INTR, BULK, ISOC
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_EndpointConfigure( uint8_t device, uint8_t ep_addr, uint16_t ep_mps, uint8_t ep_type );

// \brief Unconfigure an Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_EndpointUnconfigure( uint8_t device, uint8_t ep_addr );

// \brief Start reception on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[out]    buf                  buffer that receives data.
// \param[in]     len                  maximum number of bytes to receive.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_EndpointRead( uint8_t device, uint8_t ep_addr, uint8_t *buf, uint32_t len );

// \brief Get result of read operation on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             number of bytes received.
uint32_t USBD_EndpointReadGetResult( uint8_t device, uint8_t ep_addr );

// \brief Start write on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[out]    buf                  buffer containing data bytes to write.
// \param[in]     len                  maximum number of bytes to write.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_EndpointWrite( uint8_t device, uint8_t ep_addr, const uint8_t *buf, uint32_t len );

// \brief Get result of write operation on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             number of bytes written.
uint32_t USBD_EndpointWriteGetResult( uint8_t device, uint8_t ep_addr );

// \brief Set/Clear stall on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address.
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[in]     stall                false = Clear stall, true = Set stall.
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_EndpointStall( uint8_t device, uint8_t ep_addr, uint32_t stall );

// \brief Abort read/write operation on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             status code that indicates the execution status of the function as defined with usbStatus.
USBD_Status_TypeDef USBD_EndpointAbort( uint8_t device, uint8_t ep_addr );

#ifdef __cplusplus
}
#endif

#endif /*__USBD_H__*/

