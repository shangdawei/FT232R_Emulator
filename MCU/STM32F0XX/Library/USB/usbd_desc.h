/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __USB_DESC_H
#define __USB_DESC_H

/* Includes ------------------------------------------------------------------*/
#include "usb_type.h"
#include "usbd_ctrlreq.h"
#include "usbd.h"

uint8_t * USBD_USR_DeviceDescriptor( uint8_t speed, uint16_t *length );
uint8_t * USBD_USR_CongigurationDescriptor( uint8_t speed, uint16_t *length );
uint8_t * USBD_USR_StringDescriptor( uint8_t index, uint16_t *length );

#endif /* __USBD_DESC_H */
