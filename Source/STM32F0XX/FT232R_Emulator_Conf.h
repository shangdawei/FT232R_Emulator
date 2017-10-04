#ifndef __FT232R_EMULATOR_CONF_H__
#define __FT232R_EMULATOR_CONF_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f0xx_device.h"

#define FT232R_EMULATOR_IN_ENDPOINT_ADDR          ( 0x81 )
#define FT232R_EMULATOR_OUT_ENDPOINT_ADDR         ( 0x02 )

#define FT232R_EMULATOR_ENDPOINT0_SIZE            ( 64 )
#define FT232R_EMULATOR_ENDPOINT_SIZE             ( 64 )

#define FT232R_EMULATOR_EEPROM_SIZE               ( 128 )

#define FT232R_EMULATOR_TXFIFO_SIZE               ( 256 )
#define FT232R_EMULATOR_RXFIFO_SIZE               ( 256 )

#define FT232R_EMULATOR_EEPROM_FLASH_BASE_ADDR    ( 0x08007000 )
#define FT232R_EMULATOR_EEPROM_FLASH_PAGE_SIZE    ( FLASH_PAGE_SIZE )
#define FT232R_EMULATOR_EEPROM_FLASH_PAGE_COUNT   ( 4 )

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_CONF_H__ */
