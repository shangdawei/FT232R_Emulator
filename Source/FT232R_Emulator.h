#ifndef __FT232R_EMULATOR_H__
#define __FT232R_EMULATOR_H__

#include "FT232R_Emulator_Type.h"
#include "FT232R_Emulator_Conf.h"

extern FT232R_Property_TypeDef FT232R_Property;
extern FT232R_Context_TypeDef FT232R_Context;

extern WORD FT232R_Emulator_DummyData;
extern const UCHAR FT232R_Emulator_ChipId[ 32 ];
extern const UCHAR FT232R_Emulator_Eeprom[ FT232R_EMULATOR_EEPROM_SIZE ];

#endif /* __FT232R_EMULATOR_H__ */
