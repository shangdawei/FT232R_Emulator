#ifndef __DRIVER_EEPROM_EMULATOR_H__
#define __DRIVER_EEPROM_EMULATOR_H__

#include <stdint.h>

typedef enum
{
  EEPROM_SUCCESS = 0,               // Everything is OK
  EEPROM_FAULT = -1,                // Flash Hardware Fault, Erase Error, Program Error

  EEPROM_VIRGIN = -2,               // All Pages are ERASED, Eeprom need be formatted with init data
  EEPROM_PAGE_FULL = -3,            // Can not write Current Page because it is full
} EEPROM_Status;

typedef struct
{
  int32_t (*FlashInit)( uint32_t PageBase, uint32_t PageCount );        //
  int32_t (*FlashErasePage)( uint32_t PageBase, uint32_t PageCount );   //
  int32_t (*FlashProgram)( uint32_t Addr, uint32_t Data );              //
  int32_t (*FlashRead)( uint32_t Addr, uint32_t * Data );               //
} Driver_EEPROM_Emulator;

// low level driver for EEPROM_Emulator
extern const Driver_EEPROM_Emulator EEPROM_Emulator_Driver;

#endif /* __DRIVER_EEPROM_EMULATOR_H__ */
