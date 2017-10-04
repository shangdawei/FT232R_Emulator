/**
 ******************************************************************************
 * @file    usb_bsp.c
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    31-January-2014
 * @brief   This file Provides Device Core configuration Functions
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
#include "usb_bsp.h"
#include "stm32f0xx.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_crs.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
#if defined USB_CLOCK_SOURCE_CRS
static void CRS_Config( void );
#endif /* USB_CLOCK_SOURCE_CRS */

/** System Clock Configuration
 */
void SystemClock_Config( void )
{
  /* Enable Prefetch Buffer and set Flash Latency */
  FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;

  /* Select HSI as SystemClock -----------------------------------------------*/
  RCC->CFGR &= ~RCC_CFGR_SW;
  RCC->CFGR |= RCC_CFGR_SW_HSI;

  /* Reset HSEON and HSEBYP bits before configuring the HSE ------------------*/
  RCC->CR &= ~( RCC_CR_HSEON | RCC_CR_HSEBYP );

  /* Set the new HSE configuration -------------------------------------------*/
  RCC->CR |= RCC_CR_HSEON;
  while ( 0 == ( RCC->CR & RCC_CR_HSERDY ) )
    ;

  /* HSE Div 2 as the PLL Source */
  RCC->CFGR2 &= ~RCC_CFGR2_PREDIV;
  RCC->CFGR2 |= RCC_CFGR2_PREDIV_DIV2;

  /* Set the PLL Source and Multiplier */
  RCC->CFGR &= ~( RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL );
  RCC->CFGR |= RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR_PLLMUL12;

  RCC->CR |= RCC_CR_PLLON;
  while ( 0 == ( RCC->CR & RCC_CR_PLLRDY ) )
    ;

  RCC->CFGR |= RCC_CFGR_SW_PLL;
}

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Initialize BSP configurations
 * @param  None
 * @retval None
 */

void USB_BSP_Init( USB_CORE_HANDLE *pdev )
{
#ifdef USB_DEVICE_LOW_PWR_MGMT_SUPPORT
  EXTI_InitTypeDef EXTI_InitStructure;
#endif /*USB_DEVICE_LOW_PWR_MGMT_SUPPORT */

  /* Enable USB clock */
  RCC_APB1PeriphClockCmd( RCC_APB1Periph_USB, ENABLE );

#if defined USB_CLOCK_SOURCE_CRS

  /*For using CRS, you need to do the following:
   - Enable HSI48 (managed by the SystemInit() function at the application startup)
   - Select HSI48 as USB clock
   - Enable CRS clock
   - Set AUTOTRIMEN
   - Set CEN
   */

  /* Select HSI48 as USB clock */
  RCC_USBCLKConfig( RCC_USBCLK_HSI48 );

  /* Configure the Clock Recovery System */
  CRS_Config( );
#else
  /* Configure USBCLK from PLL clock */
  /* Clear USBSW bit */
  RCC->CFGR3 &= ~RCC_CFGR3_USBSW;
  /* Set USBSW bits according to RCC_USBCLK value */
  RCC->CFGR3 |= RCC_CFGR3_USBSW_PLLCLK;
#endif /*USB_CLOCK_SOURCE_CRS */

#ifdef USB_DEVICE_LOW_PWR_MGMT_SUPPORT

  EXTI_InitTypeDef EXTI_InitStructure;

  /* Enable the PWR clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

  /* EXTI line 18 is connected to the USB Wakeup from suspend event   */
  EXTI_ClearITPendingBit(EXTI_Line18);
  EXTI_InitStructure.EXTI_Line = EXTI_Line18;
  /*Must Configure the EXTI Line 18 to be sensitive to rising edge*/
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
#endif /*USB_DEVICE_LOW_PWR_MGMT_SUPPORT */

}

/*
 * USB priority should be lower than USART in order to not loose data reception from USART
 * while USB interrupt is being handled */

#define USB_IT_PRIO                    0

/**
 * @brief  Enable USB Global interrupt
 * @param  None
 * @retval None
 */
void USB_BSP_EnableInterrupt( USB_CORE_HANDLE *pdev )
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USB interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USB_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = USB_IT_PRIO;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init( &NVIC_InitStructure );
}

void USB_BSP_DevConnect( USB_CORE_HANDLE *pdev )
{

}

void USB_BSP_DevDisconnect( USB_CORE_HANDLE *pdev )
{

}

#if defined USB_CLOCK_SOURCE_CRS
/**
 * @brief  Configure CRS peripheral to automatically trim the HSI
 *         oscillator according to USB SOF
 * @param  None
 * @retval None
 */
static void CRS_Config( void )
{
  /*Enable CRS Clock*/
  RCC_APB1PeriphClockCmd( RCC_APB1Periph_CRS, ENABLE );

  /* Select USB SOF as synchronization source */
  CRS_SynchronizationSourceConfig( CRS_SYNCSource_USB );

  /*Enables the automatic hardware adjustment of TRIM bits: AUTOTRIMEN:*/
  CRS_AutomaticCalibrationCmd( ENABLE );

  /*Enables the oscillator clock for frequency error counter CEN*/
  CRS_FrequencyErrorCounterCmd( ENABLE );
}

#endif
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
