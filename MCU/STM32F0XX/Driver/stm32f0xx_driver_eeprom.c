#include "Driver_EEPROM_Emulator.h"
#include "stm32f0xx.h"

/* FLASH_PAGE_SIZE define */
#include "stm32f0xx_device.h"

int32_t STM32F0XX_DRIVER_EEPROM_FlashInit( uint32_t PageBase, uint32_t PageCount );
int32_t STM32F0XX_DRIVER_EEPROM_FlashErasePage( uint32_t PageBase, uint32_t PageCount );
int32_t STM32F0XX_DRIVER_EEPROM_FlashProgram( uint32_t Addr, uint32_t Data );
int32_t STM32F0XX_DRIVER_EEPROM_FlashRead( uint32_t Addr, uint32_t * Data );

const Driver_EEPROM_Emulator EEPROM_Emulator_Driver = {
  STM32F0XX_DRIVER_EEPROM_FlashInit,        //
  STM32F0XX_DRIVER_EEPROM_FlashErasePage,   //
  STM32F0XX_DRIVER_EEPROM_FlashProgram,     //
  STM32F0XX_DRIVER_EEPROM_FlashRead };

int32_t STM32F0XX_DRIVER_EEPROM_FlashInit( uint32_t PageBase, uint32_t PageCount )
{
  /* Unlock the Flash Program Erase controller */
  FLASH_Unlock( );

  return EEPROM_SUCCESS;
}

int32_t STM32F0XX_DRIVER_EEPROM_FlashErasePage( uint32_t PageBase, uint32_t PageCount )
{
  uint32_t ExecuteErase;
  uint16_t FlashStatus;
  for ( uint32_t PageIndex = 0; PageIndex < PageCount; PageIndex++ )
  {
    ExecuteErase = 0;
    for ( uint32_t Addr = 0; Addr < FLASH_PAGE_SIZE; Addr += 4 )
    {
      if ( 0xFFFFFFFF != *(__IO uint32_t *) ( PageBase + Addr ) )
      {
        ExecuteErase = 1;
        break;
      }
    }

    if ( ExecuteErase )
    {
      FlashStatus = FLASH_ErasePage( PageBase );
      if ( FLASH_COMPLETE == FlashStatus )
      {
        for ( uint32_t Addr = 0; Addr < FLASH_PAGE_SIZE; Addr += 4 )
        {
          if ( 0xFFFFFFFF != *(__IO uint32_t *) ( PageBase + Addr ) )
            return EEPROM_FAULT;
        }
      }
    }

    PageBase += FLASH_PAGE_SIZE;
  }

  return EEPROM_SUCCESS;
}

int32_t STM32F0XX_DRIVER_EEPROM_FlashProgram( uint32_t Addr, uint32_t Data )
{
  if ( *(__IO uint32_t *) Addr == Data )
    return EEPROM_SUCCESS;

  uint16_t FlashStatus;
  FlashStatus = FLASH_ProgramHalfWord( Addr, Data );
  if ( FLASH_COMPLETE == FlashStatus )
  {
    FlashStatus = FLASH_ProgramHalfWord( Addr + 2, Data >> 16 );
    if ( FLASH_COMPLETE == FlashStatus )
    {
      if ( *(__IO uint32_t *) Addr == Data )
        return EEPROM_SUCCESS;
    }
  }

  return EEPROM_FAULT;
}

int32_t STM32F0XX_DRIVER_EEPROM_FlashRead( uint32_t Addr, uint32_t * Data )
{
  *Data = *(__IO uint32_t *) Addr;
  return EEPROM_SUCCESS;
}
