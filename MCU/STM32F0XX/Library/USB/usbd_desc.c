/* Includes ------------------------------------------------------------------*/
#include "usbd_desc.h"

/* Private functions ---------------------------------------------------------*/

/**
 * @brief return the device descriptor
 * @param  speed : current device speed
 * @param  length : pointer to data length variable
 * @retval pointer to descriptor buffer
 */
uint8_t * USBD_USR_DeviceDescriptor( uint8_t speed, uint16_t *length )
{
  uint8_t * DeviceDescriptor = usbd_device->descriptor->device_descriptor;
  *length = ( (USB_DEVICE_DESCRIPTOR*) DeviceDescriptor )->bLength;
  return DeviceDescriptor;
}

uint8_t * USBD_USR_CongigurationDescriptor( uint8_t speed, uint16_t *length )
{
  uint8_t * CongigurationDescriptor = usbd_device->descriptor->config_descriptor;
  *length = ( (USB_CONFIGURATION_DESCRIPTOR*) CongigurationDescriptor )->wTotalLength;
  return CongigurationDescriptor;
}

uint8_t * USBD_USR_StringDescriptor( uint8_t index, uint16_t *length )
{
  return usbd_device->callback->USBD_Device_StringDescriptor( index, length );
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

