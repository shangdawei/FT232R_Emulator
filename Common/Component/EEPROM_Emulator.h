#ifndef __EEPROM_EMULATOR_H
#define __EEPROM_EMULATOR_H

#include <stdint.h>
#include "Driver_EEPROM_Emulator.h"

#define EEPROM_EMULATOR_CACHE_ENABLED   ( 1 )

typedef struct
{
  uint32_t FlashPageBase;           // Page Base Address of Flash
  uint32_t FlashPageCount;          // Physical Pages can be used
  uint32_t FlashPageSize;           // Erasable Page Size of Flash ---------- Physical Page Size
  uint32_t EepromCapacity;          // Variables' number in Byte
} EEPROM_Configuration_TypeDef;

int32_t EEPROM_Init( const Driver_EEPROM_Emulator * EEPROM_Emulator_Driver,
  const EEPROM_Configuration_TypeDef * EEPROM_Configuration, uint8_t * EEPROM_Cache );

int32_t EEPROM_Format( uint8_t * EepromData, uint32_t Size );

int32_t EEPROM_ReadByte( uint32_t Addr, uint8_t * Data );                   // Read a byte from any address
int32_t EEPROM_ReadWord( uint32_t Addr, uint16_t * Data );                  // Read a word from Even address
int32_t EEPROM_ReadDWord( uint32_t Addr, uint32_t * Data );                 // Read a dword from DWORD alginment addr

int32_t EEPROM_ReadBytes( uint32_t Addr, uint32_t Size, uint8_t * Data );   // Read N bytes from any address

int32_t EEPROM_WriteByte( uint32_t Addr, uint8_t Data );                    // Write a byte into any address
int32_t EEPROM_WriteWord( uint32_t Addr, uint16_t Data );                   // Write a word into Even address
int32_t EEPROM_WriteDWord( uint32_t Addr, uint32_t Data );                  // Write a dword into DWORD alginment addr

int32_t EEPROM_WriteBytes( uint32_t Addr, uint32_t Size, uint8_t * Data );  // Write N bytes into any address

#endif /* __EEPROM_EMULATOR_H */
