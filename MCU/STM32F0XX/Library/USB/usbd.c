/* Includes ------------------------------------------------------------------*/
#include "usbd.h"
#include "usbd_class.h"
#include  "usbd_usr.h"
#include  "usb_bsp.h"
#include  "usb_conf.h"

USB_CORE_HANDLE USB_Device_dev;

// \brief Initialize USB Device stack and controller
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_Initialize( uint8_t device )
{
  /* The Application layer has only to call USBD_Init to
   initialize the USB low level driver, the USB device library, the USB clock
   ,pins and interrupt service routine (BSP) to start the Library*/
  USBD_Init( &USB_Device_dev );

  /* Upon Init call usr callback */
  if ( USBD_Device->callback->USBD_Device_Initialize )
    USBD_Device->callback->USBD_Device_Initialize( );
  // call classes[n]->callbacks->USBD_Class_Initialize()

  return usbOK;
}

// \brief De-initialize USB Device stack and controller
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_Uninitialize( uint8_t device )
{
  /* Upon Init call usr callback */
  // call classes[n]->callbacks->USBD_Class_Initialize()
  if ( USBD_Device->callback->USBD_Device_Uninitialize )
    USBD_Device->callback->USBD_Device_Uninitialize( );

  USBD_DeInit( &USB_Device_dev );
  return usbOK;
}

// \brief Activate pull-up on D+ or D- line to signal USB Device connection on USB Bus
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_Connect( uint8_t device )
{
  /* Enable the pull-up */
#ifdef INTERNAL_PULLUP
  DCD_DevConnect( &USB_Device_dev );
#else
  USB_BSP_DevConnect( &USB_Device_dev );
#endif

  return usbOK;
}

// \brief Disconnect USB Device from USB Bus
// \param[in]     device               index of USB Device.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_Disconnect( uint8_t device )
{
  /* Enable the pull-up */
#ifdef INTERNAL_PULLUP
  DCD_DevDisconnect( &USB_Device_dev );
#else
  USB_BSP_DevDisconnect( &USB_Device_dev );
#endif

  return usbOK;
}

// \brief Return USB Device configuration status
// \param[in]     device               index of USB Device.
// \return        true                 device is in configured state and ready to communicate.
// \return        false                device is not configured and not ready to communicate.
uint32_t USBD_Configured( uint8_t device )
{
  return USB_Device_dev.dev.device_config;
}

USBD_Status_TypeDef USBD_EndpointConfigure( uint8_t device, uint8_t ep_addr, uint16_t ep_mps, uint8_t ep_type )
{
  DCD_EP_Open( &USB_Device_dev, ep_addr, ep_mps, ep_type );
  return usbOK;
}

USBD_Status_TypeDef USBD_EndpointUnconfigure( uint8_t device, uint8_t ep_addr )
{
  DCD_EP_Close( &USB_Device_dev, ep_addr );
  return usbOK;
}

// \brief Start reception on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[out]    buf                  buffer that receives data.
// \param[in]     len                  maximum number of bytes to receive.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_EndpointRead( uint8_t device, uint8_t ep_addr, uint8_t *buf, uint32_t len )
{
  /* Prepare Out endpoint to receive next packet */
  DCD_EP_PrepareRx( &USB_Device_dev, ep_addr, buf, len );
  return usbOK;
}

// \brief Get result of read operation on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             number of bytes received.
uint32_t USBD_EndpointReadGetResult( uint8_t device, uint8_t ep_addr )
{
  return USBD_GetRxCount( &USB_Device_dev, ep_addr );
}

// \brief Start write on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[out]    buf                  buffer containing data bytes to write.
// \param[in]     len                  maximum number of bytes to write.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_EndpointWrite( uint8_t device, uint8_t ep_addr, const uint8_t *buf, uint32_t len )
{
  DCD_EP_Tx( &USB_Device_dev, ep_addr, buf, len );
  return usbOK;
}

// \brief Get result of write operation on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             number of bytes written.
uint32_t USBD_EndpointWriteGetResult( uint8_t device, uint8_t ep_addr )
{
  return USBD_GetTxCount( &USB_Device_dev, ep_addr );
}

// \brief Set/Clear stall on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address.
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \param[in]     stall                false = Clear stall, true = Set stall.
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_EndpointStall( uint8_t device, uint8_t ep_addr, uint32_t stall )
{
  if ( stall )
    DCD_EP_Stall( &USB_Device_dev, ep_addr );
  else
    DCD_EP_ClrStall( &USB_Device_dev, ep_addr );

  return usbOK;
}

// \brief Abort read/write operation on Endpoint
// \param[in]     device               index of USB Device.
// \param[in]     ep_addr              endpoint address
//                 - ep_addr.0..3:       address
//                 - ep_addr.7:          direction
// \return                             status code that indicates the execution status of the function as defined with \ref usbStatus.
USBD_Status_TypeDef USBD_EndpointAbort( uint8_t device, uint8_t ep_addr )
{
  // Dont care
  return usbOK;
}
