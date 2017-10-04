
/*******************************************************************************
  * @file    stm32f0xx.h
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    27-May-2016
  * @brief   CMSIS STM32F0xx Device Peripheral Access Layer Header File.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The STM32F0xx device used in the target application
  *              - To use or not the peripheral¡¯s drivers in application code(i.e.
  *                code will be based on direct access to peripherals registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_HAL_DRIVER"
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f0xx
  * @{
  */

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */


#include "stm32f0xx_device.h"

#ifndef STM32F072xB
#define STM32F072xB
#endif

#if !defined  (STM32F0)
#define STM32F0
#endif /* STM32F0 */

#if !defined (STM32F030x6) && !defined (STM32F030x8) && !defined (STM32F030xC) && !defined (STM32F070x6) && !defined (STM32F070xB) && \
    !defined (STM32F031x6) && !defined (STM32F051x8) && !defined (STM32F071xB) && !defined (STM32F091xC) && \
    !defined (STM32F042x6) && !defined (STM32F072xB) && \
    !defined (STM32F038xx) && !defined (STM32F048x6) && !defined (STM32F058xx) && !defined (STM32F078xx) && !defined (STM32F098xx)

  /* #define STM32F030x6 */  /*!< STM32F030x4, STM32F030x6 Devices (STM32F030xx microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)              */
  /* #define STM32F030x8 */  /*!< STM32F030x8 Devices (STM32F030xx microcontrollers where the Flash memory is 64 Kbytes)                                              */
  /* #define STM32F030xC */  /*!< STM32F030xC Devices (STM32F030xC microcontrollers where the Flash memory is 256 Kbytes)                                             */
  /* #define STM32F070x6 */  /*!< STM32F070x6 Devices (STM32F070x6 microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)                           */
  /* #define STM32F070xB */  /*!< STM32F070xB Devices (STM32F070xB microcontrollers where the Flash memory ranges between 64 and 128 Kbytes)                          */

  /* #define STM32F031x6 */  /*!< STM32F031x4, STM32F031x6 Devices (STM32F031xx microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)              */
  /* #define STM32F051x8 */  /*!< STM32F051x4, STM32F051x6, STM32F051x8 Devices (STM32F051xx microcontrollers where the Flash memory ranges between 16 and 64 Kbytes) */
  /* #define STM32F071xB */  /*!< STM32F071x8, STM32F071xB Devices (STM32F071xx microcontrollers where the Flash memory ranges between 64 and 128 Kbytes)             */
  /* #define STM32F091xC */  /*!< STM32F091xB, STM32F091xC Devices (STM32F091xx microcontrollers where the Flash memory ranges between 128 and 256 Kbytes)            */

  /* #define STM32F042x6 */  /*!< STM32F042x4, STM32F042x6 Devices (STM32F042xx microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)              */
  /* #define STM32F072xB */  /*!< STM32F072x8, STM32F072xB Devices (STM32F072xx microcontrollers where the Flash memory ranges between 64 and 128 Kbytes)             */

  /* Renamed STM32F06x to STM32F0x8 */

  /* #define STM32F038xx */  /*!< STM32F038xx Devices (STM32F038xx microcontrollers where the Flash memory is 32 Kbytes)                                              */
  /* #define STM32F048x6 */  /*!< STM32F048xx Devices (STM32F042xx microcontrollers where the Flash memory is 32 Kbytes)                                              */
  /* #define STM32F058xx */  /*!< STM32F058xx Devices (STM32F058xx microcontrollers where the Flash memory is 64 Kbytes)                                              */
  /* #define STM32F078xx */  /*!< STM32F078xx Devices (STM32F078xx microcontrollers where the Flash memory is 128 Kbytes)                                             */
  /* #define STM32F098xx */  /*!< STM32F098xx Devices (STM32F098xx microcontrollers where the Flash memory is 256 Kbytes)                                             */

#endif

#if !defined  USE_STDPERIPH_DRIVER
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
  #define USE_STDPERIPH_DRIVER
#endif /* USE_STDPERIPH_DRIVER */

/**
  * @brief CMSIS Device version number V2.3.0
  */
#define __STM32F0_DEVICE_VERSION_MAIN   (0x02) /*!< [31:24] main version */
#define __STM32F0_DEVICE_VERSION_SUB1   (0x03) /*!< [23:16] sub1 version */
#define __STM32F0_DEVICE_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __STM32F0_DEVICE_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32F0_DEVICE_VERSION        ((__STM32F0_DEVICE_VERSION_MAIN << 24)\
                                        |(__STM32F0_DEVICE_VERSION_SUB1 << 16)\
                                        |(__STM32F0_DEVICE_VERSION_SUB2 << 8 )\
                                        |(__STM32F0_DEVICE_VERSION_RC))

  /** @addtogroup Configuration_section_for_CMSIS
  * @{
  */
/**
 * @brief Configuration of the Cortex-M0 Processor and Core Peripherals
 */
#define __CM0_REV                 0 /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0 /*!< STM32F0xx do not provide MPU                  */
#define __NVIC_PRIO_BITS          2 /*!< STM32F0xx uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0     /*!< Set to 1 if different SysTick Config is used */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32F0xx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */


/**
  * @}
  */

 /******  Interrupt Number Definition ************************************************************************/
#if defined(STM32F030x6)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  USART1_IRQn                 = 27      /*!< USART1 global Interrupt                                         */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F030x8)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_IRQn                   = 17,     /*!< TIM6 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt                                            */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,      /*!< USART1 global Interrupt                                        */
  USART2_IRQn                 = 28      /*!< USART2 global Interrupt                                         */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_DAC_IRQn              TIM6_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_DAC_IRQHandler              TIM6_IRQHandler
#elif defined(STM32F030xC)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_IRQn                   = 17,     /*!< TIM6 global Interrupt                                           */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_6_IRQn               = 29,     /*!< USART3 to USART6 global Interrupt                               */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_DAC_IRQn              TIM6_IRQn
#define USART3_4_IRQn              USART3_6_IRQn
#define USART3_8_IRQn              USART3_6_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_DAC_IRQHandler              TIM6_IRQHandler
#define USART3_4_IRQHandler              USART3_6_IRQHandler
#define USART3_8_IRQHandler              USART3_6_IRQHandler
#elif defined(STM32F031x6)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_IRQn                    = 1,      /*!< PVD Interrupt through EXTI Lines 16                             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  USART1_IRQn                 = 27      /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define VDDIO2_IRQn                PVD_IRQn
#define PVD_VDDIO2_IRQn            PVD_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define VDDIO2_IRQHandler                PVD_IRQHandler
#define PVD_VDDIO2_IRQHandler            PVD_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F038xx)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  USART1_IRQn                 = 27      /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F042x6)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define PVD_IRQn                   PVD_VDDIO2_IRQn
#define VDDIO2_IRQn                PVD_VDDIO2_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define PVD_IRQHandler                   PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler                PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#elif defined(STM32F048xx)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  VDDIO2_IRQn                 = 1,      /*!< VDDIO2 Interrupt through EXTI Line 31                           */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define PVD_IRQn                   VDDIO2_IRQn
#define PVD_VDDIO2_IRQn            VDDIO2_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define PVD_IRQHandler                   VDDIO2_IRQHandler
#define PVD_VDDIO2_IRQHandler            VDDIO2_IRQHandler
#elif defined(STM32F051x8)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_IRQn                    = 1,      /*!< PVD Interrupt through EXTI Lines 16                             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  CEC_CAN_IRQn                = 30      /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define VDDIO2_IRQn                PVD_IRQn
#define PVD_VDDIO2_IRQn            PVD_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define VDDIO2_IRQHandler                PVD_IRQHandler
#define PVD_VDDIO2_IRQHandler            PVD_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#elif defined(STM32F058xx)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  CEC_CAN_IRQn                = 30      /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#elif defined(STM32F070x6)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F070xB)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC global Interrupt                                            */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_IRQn                   = 17,     /*!< TIM6 global Interrupt                                           */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,      /*!< USART1 global Interrupt                                        */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 global Interrupt                              */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_DAC_IRQn              TIM6_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_DAC_IRQHandler              TIM6_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#elif defined(STM32F071xB)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_6_7_IRQn    = 11,     /*!< DMA1 Channel 4 to Channel 7 Interrupt                           */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 global Interrupt                              */
  CEC_CAN_IRQn                = 30      /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_6_7_IRQn
#define DMA1_Channel4_5_IRQn       DMA1_Channel4_5_6_7_IRQn
#define PVD_IRQn                   PVD_VDDIO2_IRQn
#define VDDIO2_IRQn                PVD_VDDIO2_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_6_7_IRQHandler
#define DMA1_Channel4_5_IRQHandler       DMA1_Channel4_5_6_7_IRQHandler
#define PVD_IRQHandler                   PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler                PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#elif defined(STM32F072xB)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_6_7_IRQn    = 11,     /*!< DMA1 Channel 4 to Channel 7 Interrupt                           */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 global Interrupt                              */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_6_7_IRQn
#define DMA1_Channel4_5_IRQn       DMA1_Channel4_5_6_7_IRQn
#define PVD_IRQn                   PVD_VDDIO2_IRQn
#define VDDIO2_IRQn                PVD_VDDIO2_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_6_7_IRQHandler
#define DMA1_Channel4_5_IRQHandler       DMA1_Channel4_5_6_7_IRQHandler
#define PVD_IRQHandler                   PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler                PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#elif defined(STM32F078xx)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  VDDIO2_IRQn                 = 1,      /*!< VDDIO2 Interrupt through EXTI Line 31                           */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_6_7_IRQn    = 11,     /*!< DMA1 Channel 4 to Channel 7 Interrupt                           */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 global Interrupt                              */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_6_7_IRQn
#define DMA1_Channel4_5_IRQn       DMA1_Channel4_5_6_7_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
#define PVD_IRQn                   VDDIO2_IRQn
#define PVD_VDDIO2_IRQn            VDDIO2_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_6_7_IRQHandler
#define DMA1_Channel4_5_IRQHandler       DMA1_Channel4_5_6_7_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#define PVD_IRQHandler                   VDDIO2_IRQHandler
#define PVD_VDDIO2_IRQHandler            VDDIO2_IRQHandler
#elif defined(STM32F091xC)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Ch1_IRQn               = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Ch2_3_DMA2_Ch1_2_IRQn  = 10,     /*!< DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2 Interrupts          */
  DMA1_Ch4_7_DMA2_Ch3_5_IRQn  = 11,     /*!< DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5 Interrupt             */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_8_IRQn               = 29,     /*!< USART3 to USART8 global Interrupt                               */
  CEC_CAN_IRQn                = 30      /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                ADC1_COMP_IRQn
#define DMA1_Channel1_IRQn       DMA1_Ch1_IRQn
#define DMA1_Channel2_3_IRQn     DMA1_Ch2_3_DMA2_Ch1_2_IRQn
#define DMA1_Channel4_5_6_7_IRQn DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define DMA1_Channel4_5_IRQn     DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define PVD_IRQn                 PVD_VDDIO2_IRQn
#define VDDIO2_IRQn              PVD_VDDIO2_IRQn
#define RCC_IRQn                 RCC_CRS_IRQn
#define TIM6_IRQn                TIM6_DAC_IRQn
#define USART3_4_IRQn            USART3_8_IRQn
#define USART3_6_IRQn            USART3_8_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                ADC1_COMP_IRQHandler
#define DMA1_Channel1_IRQHandler       DMA1_Ch1_IRQHandler
#define DMA1_Channel2_3_IRQHandler     DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define DMA1_Channel4_5_IRQHandler     DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define PVD_IRQHandler                 PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler              PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                 RCC_CRS_IRQHandler
#define TIM6_IRQHandler                TIM6_DAC_IRQHandler
#define USART3_4_IRQHandler            USART3_8_IRQHandler
#define USART3_6_IRQHandler            USART3_8_IRQHandler
#elif defined(STM32F098xx)
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  VDDIO2_IRQn                 = 1,      /*!< VDDIO2 Interrupt through EXTI Line 31                           */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Ch1_IRQn               = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Ch2_3_DMA2_Ch1_2_IRQn  = 10,     /*!< DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2 Interrupts          */
  DMA1_Ch4_7_DMA2_Ch3_5_IRQn  = 11,     /*!< DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5 Interrupt             */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_8_IRQn               = 29,     /*!< USART3 to USART8 global Interrupt                               */
  CEC_CAN_IRQn                = 30      /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
} IRQn_Type;
/* Aliases for __IRQn */
#define ADC1_IRQn                ADC1_COMP_IRQn
#define DMA1_Channel1_IRQn       DMA1_Ch1_IRQn
#define DMA1_Channel2_3_IRQn     DMA1_Ch2_3_DMA2_Ch1_2_IRQn
#define DMA1_Channel4_5_6_7_IRQn DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define DMA1_Channel4_5_IRQn     DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define RCC_IRQn                 RCC_CRS_IRQn
#define TIM6_IRQn                TIM6_DAC_IRQn
#define USART3_4_IRQn            USART3_8_IRQn
#define USART3_6_IRQn            USART3_8_IRQn
#define PVD_IRQn                 VDDIO2_IRQn
#define PVD_VDDIO2_IRQn          VDDIO2_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                ADC1_COMP_IRQHandler
#define DMA1_Channel1_IRQHandler       DMA1_Ch1_IRQHandler
#define DMA1_Channel2_3_IRQHandler     DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define DMA1_Channel4_5_IRQHandler     DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define RCC_IRQHandler                 RCC_CRS_IRQHandler
#define TIM6_IRQHandler                TIM6_DAC_IRQHandler
#define USART3_4_IRQHandler            USART3_8_IRQHandler
#define USART3_6_IRQHandler            USART3_8_IRQHandler
#define PVD_IRQHandler                 VDDIO2_IRQHandler
#define PVD_VDDIO2_IRQHandler          VDDIO2_IRQHandler
#endif
/******************************************************************************/
/*  For a painless codes migration between the STM32F0xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same STM32F0 Family                              */
/******************************************************************************/
#if defined(STM32F030x6)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F030x8)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_DAC_IRQn              TIM6_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_DAC_IRQHandler              TIM6_IRQHandler
#elif defined(STM32F030xC)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_DAC_IRQn              TIM6_IRQn
#define USART3_4_IRQn              USART3_6_IRQn
#define USART3_8_IRQn              USART3_6_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_DAC_IRQHandler              TIM6_IRQHandler
#define USART3_4_IRQHandler              USART3_6_IRQHandler
#define USART3_8_IRQHandler              USART3_6_IRQHandler
#elif defined(STM32F031x6)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define VDDIO2_IRQn                PVD_IRQn
#define PVD_VDDIO2_IRQn            PVD_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define VDDIO2_IRQHandler                PVD_IRQHandler
#define PVD_VDDIO2_IRQHandler            PVD_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F038xx)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F042x6)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define PVD_IRQn                   PVD_VDDIO2_IRQn
#define VDDIO2_IRQn                PVD_VDDIO2_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define PVD_IRQHandler                   PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler                PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#elif defined(STM32F048xx)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define PVD_IRQn                   VDDIO2_IRQn
#define PVD_VDDIO2_IRQn            VDDIO2_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define PVD_IRQHandler                   VDDIO2_IRQHandler
#define PVD_VDDIO2_IRQHandler            VDDIO2_IRQHandler
#elif defined(STM32F051x8)
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define VDDIO2_IRQn                PVD_IRQn
#define PVD_VDDIO2_IRQn            PVD_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define VDDIO2_IRQHandler                PVD_IRQHandler
#define PVD_VDDIO2_IRQHandler            PVD_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#elif defined(STM32F058xx)
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#elif defined(STM32F070x6)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#elif defined(STM32F070xB)
/* Aliases for __IRQn */
#define ADC1_COMP_IRQn             ADC1_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Channel4_5_6_7_IRQn   DMA1_Channel4_5_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
#define RCC_CRS_IRQn               RCC_IRQn
#define TIM6_DAC_IRQn              TIM6_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
/* Aliases for __IRQHandler */
#define ADC1_COMP_IRQHandler             ADC1_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler   DMA1_Channel4_5_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
#define RCC_CRS_IRQHandler               RCC_IRQHandler
#define TIM6_DAC_IRQHandler              TIM6_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#elif defined(STM32F071xB)
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_6_7_IRQn
#define DMA1_Channel4_5_IRQn       DMA1_Channel4_5_6_7_IRQn
#define PVD_IRQn                   PVD_VDDIO2_IRQn
#define VDDIO2_IRQn                PVD_VDDIO2_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_6_7_IRQHandler
#define DMA1_Channel4_5_IRQHandler       DMA1_Channel4_5_6_7_IRQHandler
#define PVD_IRQHandler                   PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler                PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#elif defined(STM32F072xB)
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_6_7_IRQn
#define DMA1_Channel4_5_IRQn       DMA1_Channel4_5_6_7_IRQn
#define PVD_IRQn                   PVD_VDDIO2_IRQn
#define VDDIO2_IRQn                PVD_VDDIO2_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_6_7_IRQHandler
#define DMA1_Channel4_5_IRQHandler       DMA1_Channel4_5_6_7_IRQHandler
#define PVD_IRQHandler                   PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler                PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#elif defined(STM32F078xx)
/* Aliases for __IRQn */
#define ADC1_IRQn                  ADC1_COMP_IRQn
#define DMA1_Ch1_IRQn              DMA1_Channel1_IRQn
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_6_7_IRQn
#define DMA1_Channel4_5_IRQn       DMA1_Channel4_5_6_7_IRQn
#define RCC_IRQn                   RCC_CRS_IRQn
#define TIM6_IRQn                  TIM6_DAC_IRQn
#define USART3_6_IRQn              USART3_4_IRQn
#define USART3_8_IRQn              USART3_4_IRQn
#define PVD_IRQn                   VDDIO2_IRQn
#define PVD_VDDIO2_IRQn            VDDIO2_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                  ADC1_COMP_IRQHandler
#define DMA1_Ch1_IRQHandler              DMA1_Channel1_IRQHandler
#define DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
#define DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_6_7_IRQHandler
#define DMA1_Channel4_5_IRQHandler       DMA1_Channel4_5_6_7_IRQHandler
#define RCC_IRQHandler                   RCC_CRS_IRQHandler
#define TIM6_IRQHandler                  TIM6_DAC_IRQHandler
#define USART3_6_IRQHandler              USART3_4_IRQHandler
#define USART3_8_IRQHandler              USART3_4_IRQHandler
#define PVD_IRQHandler                   VDDIO2_IRQHandler
#define PVD_VDDIO2_IRQHandler            VDDIO2_IRQHandler
#elif defined(STM32F091xC)
/* Aliases for __IRQn */
#define ADC1_IRQn                ADC1_COMP_IRQn
#define DMA1_Channel1_IRQn       DMA1_Ch1_IRQn
#define DMA1_Channel2_3_IRQn     DMA1_Ch2_3_DMA2_Ch1_2_IRQn
#define DMA1_Channel4_5_6_7_IRQn DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define DMA1_Channel4_5_IRQn     DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define PVD_IRQn                 PVD_VDDIO2_IRQn
#define VDDIO2_IRQn              PVD_VDDIO2_IRQn
#define RCC_IRQn                 RCC_CRS_IRQn
#define TIM6_IRQn                TIM6_DAC_IRQn
#define USART3_4_IRQn            USART3_8_IRQn
#define USART3_6_IRQn            USART3_8_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                ADC1_COMP_IRQHandler
#define DMA1_Channel1_IRQHandler       DMA1_Ch1_IRQHandler
#define DMA1_Channel2_3_IRQHandler     DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define DMA1_Channel4_5_IRQHandler     DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define PVD_IRQHandler                 PVD_VDDIO2_IRQHandler
#define VDDIO2_IRQHandler              PVD_VDDIO2_IRQHandler
#define RCC_IRQHandler                 RCC_CRS_IRQHandler
#define TIM6_IRQHandler                TIM6_DAC_IRQHandler
#define USART3_4_IRQHandler            USART3_8_IRQHandler
#define USART3_6_IRQHandler            USART3_8_IRQHandler
#elif defined(STM32F098xx)
/* Aliases for __IRQn */
#define ADC1_IRQn                ADC1_COMP_IRQn
#define DMA1_Channel1_IRQn       DMA1_Ch1_IRQn
#define DMA1_Channel2_3_IRQn     DMA1_Ch2_3_DMA2_Ch1_2_IRQn
#define DMA1_Channel4_5_6_7_IRQn DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define DMA1_Channel4_5_IRQn     DMA1_Ch4_7_DMA2_Ch3_5_IRQn
#define RCC_IRQn                 RCC_CRS_IRQn
#define TIM6_IRQn                TIM6_DAC_IRQn
#define USART3_4_IRQn            USART3_8_IRQn
#define USART3_6_IRQn            USART3_8_IRQn
#define PVD_IRQn                 VDDIO2_IRQn
#define PVD_VDDIO2_IRQn          VDDIO2_IRQn
/* Aliases for __IRQHandler */
#define ADC1_IRQHandler                ADC1_COMP_IRQHandler
#define DMA1_Channel1_IRQHandler       DMA1_Ch1_IRQHandler
#define DMA1_Channel2_3_IRQHandler     DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler
#define DMA1_Channel4_5_6_7_IRQHandler DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define DMA1_Channel4_5_IRQHandler     DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
#define RCC_IRQHandler                 RCC_CRS_IRQHandler
#define TIM6_IRQHandler                TIM6_DAC_IRQHandler
#define USART3_4_IRQHandler            USART3_8_IRQHandler
#define USART3_6_IRQHandler            USART3_8_IRQHandler
#define PVD_IRQHandler                 VDDIO2_IRQHandler
#define PVD_VDDIO2_IRQHandler          VDDIO2_IRQHandler
#endif

#include "core_cm0.h"            /* Cortex-M0 processor and core peripherals */
#include "system_stm32f0xx.h"    /* STM32F0xx System Header */
#include <stdint.h>
