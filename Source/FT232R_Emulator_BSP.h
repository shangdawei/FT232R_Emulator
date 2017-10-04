#ifndef __FT232R_EMULATOR_BSP_H__
#define __FT232R_EMULATOR_BSP_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "FT232R_Emulator_Type.h"

int32_t FT232R_Emulator_BSP_Init( FT232R_Context_TypeDef * FT232R_Context );
int32_t FT232R_Emulator_BSP_Uninit( FT232R_Context_TypeDef * FT232R_Context );

int32_t FT232R_Emulator_BSP_GetModemLineStatus( FT232R_Context_TypeDef * FT232R_Context );

int32_t FT232R_Emulator_BSP_SetModemCtrl( FT232R_Context_TypeDef * FT232R_Context );
int32_t FT232R_Emulator_BSP_SetBaudrate( FT232R_Context_TypeDef * FT232R_Context );
int32_t FT232R_Emulator_BSP_SetLineCoding( FT232R_Context_TypeDef * FT232R_Context );
int32_t FT232R_Emulator_BSP_SetFlowCtrl( FT232R_Context_TypeDef * FT232R_Context );

int32_t FT232R_Emulator_BSP_Transmit( FT232R_Context_TypeDef * FT232R_Context, uint8_t * Buffer, uint32_t Size );
int32_t FT232R_Emulator_BSP_Receive( FT232R_Context_TypeDef * FT232R_Context, uint8_t * Buffer, uint32_t Size );

int32_t FT232R_Emulator_BSP_CancelTransmit( FT232R_Context_TypeDef * FT232R_Context );
int32_t FT232R_Emulator_BSP_CancelReceive( FT232R_Context_TypeDef * FT232R_Context );

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_BSP_H__ */
