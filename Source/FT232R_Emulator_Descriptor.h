#ifndef __FT232R_EMULATOR_DESCRIPTOR_H__
#define __FT232R_EMULATOR_DESCRIPTOR_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "usbd.h"

extern uint8_t FT232R_Emulator_DeviceDescriptor[ 18 ];
extern uint8_t FT232R_Emulator_ConfigurationDescriptor[ 32 ];

extern uint8_t FT232R_Emulator_StringSerialNumber[ 128 ];
extern uint8_t FT232R_Emulator_StringManufacturer[ 128 ];
extern uint8_t FT232R_Emulator_StringProduct[ 128 ];

extern const USBD_Descriptor_TypeDef FT232R_Emulator_Descriptor;

uint8_t * FT232R_Emulator_StringDescriptor( uint8_t index, uint16_t * length );

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_DESCRIPTOR_H__ */
