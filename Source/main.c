/**
 ******************************************************************************
 * @file    app.c
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    31-January-2014
 * @brief   This file provides all the Application firmware functions.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include  "usbd.h"
#include  "stm32f0xx.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void ReadProtection( void )
{
  /* RDPRT[1:0]: Read protection level status
   * 00: Read protection level 0 is enabled (ST production configuration)
   * 01: Read protection level 1 is enabled
   * 11: Read protection level 2 is enabled.
   */
  if ( ( FLASH->OBR & ( FLASH_OBR_RDPRT1 | FLASH_OBR_RDPRT2 ) ) == 0 )
  {
    /* (1) Wait till no operation is on going */
    while ((FLASH->SR & FLASH_SR_BSY) != 0) /* (1) */
    {
    }

    /* (2) Check that the Flash is unlocked */
    if ((FLASH->CR & FLASH_CR_LOCK) != 0) /* (2) */
    {
      /* (3) Perform unlock sequence for Flash */
      /* Unlocking the program memory access */
      FLASH->KEYR = FLASH_KEY1; /* (3) */
      FLASH->KEYR = FLASH_KEY2;
    }

    /* (4) Check that the Option Bytes are unlocked */
    if ((FLASH->CR & FLASH_CR_OPTWRE) == 0) /* (4) */
    {
      /* (5) Perform unlock sequence for Option Bytes */
      /* Unlocking the option bytes block access */
      FLASH->OPTKEYR = FLASH_OPTKEY1; /* (5) */
      FLASH->OPTKEYR = FLASH_OPTKEY2;
    }

    /* (1) Set the OPTER bit in the FLASH_CR register to enable option byte erasing */
    FLASH->CR |= FLASH_CR_OPTER; /* (1) */

    /* (2) Set the STRT bit in the FLASH_CR register to start the erasing */
    FLASH->CR |= FLASH_CR_STRT; /* (2) */

    /* (3) Wait until the BSY bit is reset in the FLASH_SR register */
    while ((FLASH->SR & FLASH_SR_BSY) != 0) /* (3) */
    {
    }

    /* (4) Check the EOP flag in the FLASH_SR register */
    if ((FLASH->SR & FLASH_SR_EOP) != 0) /* (4) */
    {
      /* (5) Clear EOP flag by software by writing EOP at 1 */
      FLASH->SR |= FLASH_SR_EOP; /* (5)*/
    }

    /* (6) Reset the PER Bit to disable the page erase */
    /* If the erase operation is completed, disable the OPTER Bit */
    FLASH->CR &= ~FLASH_CR_OPTER; /* (6) */


    // Level 1: read protection : 0xFFFF
    //
    // This is the default protection level when RDP option byte is erased.
    // It is defined as well when RDP value is at any value different from 0xAA
    // and 0xCC, or even if the complement is not correct.

    /* (1) Set the PG bit in the FLASH_CR register to enable programming */
    FLASH->CR |= FLASH_CR_OPTPG; /* (1) */

    /* (2) Perform the data write */
    OB->RDP = 0x00FF; /* (2) */

    /* (3) Wait until the BSY bit is reset in the FLASH_SR register */
    while ((FLASH->SR & FLASH_SR_BSY) != 0) /* (3) */
    {
    }

    /* (4) Check the EOP flag in the FLASH_SR register */
    if ((FLASH->SR & FLASH_SR_EOP) != 0) /* (4) */
    {
      /* (5) Clear the EOP flag by software by writing it at 1 */
      FLASH->SR |= FLASH_SR_EOP; /* (5) */
    }

    /* (6) Reset the PG Bit to disable programming */
    /* if the program operation is completed, disable the OPTPG Bit */
    FLASH->CR &= ~FLASH_CR_OPTPG; /* (6) */


    // Force option byte loading
    // When set to 1, this bit forces the option byte reloading.
    // This operation generates a system reset.
    FLASH->CR |= FLASH_CR_OBL_LAUNCH;
  }
}

/**
 * @brief  Program entry point
 * @param  None
 * @retval None
 */
int main( void )
{
  /*!< At this stage the microcontroller clock setting is already configured,
   this is done through SystemInit() function which is called from startup
   file (startup_stm32f072.s) before to branch to application main.
   To reconfigure the default setting of SystemInit() function, refer to
   system_stm32f0xx.c file
   */
#ifndef DEBUG
  ReadProtection( );
#endif

  USBD_Initialize( 0 );

  USBD_Connect( 0 );

  while ( 1 )
  {

  }
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  assert_failed
 *         Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  File: pointer to the source file name
 * @param  Line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

