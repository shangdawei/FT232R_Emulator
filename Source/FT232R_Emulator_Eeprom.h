#ifndef __FT232R_EMULATOR_EEPROM_H__
#define __FT232R_EMULATOR_EEPROM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "FT232R_Emulator_Type.h"

DWORD FT232R_Emulator_GetChipID( UCHAR * ChipID_Data );

int32_t FT232R_Emulator_EepromDecode( FT232R_Property_TypeDef * FT232R_Property );

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_EEPROM_H__ */
