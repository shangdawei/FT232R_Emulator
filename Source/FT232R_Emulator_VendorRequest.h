#ifndef __FT232R_EMULATOR_VENDOR_REQUEST_H__
#define __FT232R_EMULATOR_VENDOR_REQUEST_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "FT232R_Emulator_Type.h"
#include "usbd.h"

USBD_RequestStatus_TypeDef FT232R_Emulator_Endpoint0_SetupPacketReceived( USB_SetupPacket_TypeDef *setup_packet,
  uint8_t **buf,
  uint16_t *len );
USBD_RequestStatus_TypeDef FT232R_Emulator_Endpoint0_OutDataReceived( uint32_t len );
USBD_RequestStatus_TypeDef FT232R_Emulator_Endpoint0_InDataSent( uint32_t len );

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_VENDOR_REQUEST_H__ */
