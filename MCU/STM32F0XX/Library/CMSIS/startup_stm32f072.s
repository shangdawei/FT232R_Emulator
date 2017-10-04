//******************** (C) COPYRIGHT 2016 STMicroelectronics ********************
//* File Name          : startup_stm32f072xb.s
//* Author             : MCD Application Team
//* Version            : V2.3.0
//* Date               : 27-May-2016
//* Description        : STM32F072x8/STM32F072xB devices vector table for EWARM toolchain.
//*                      This module performs:
//*                      - Set the initial SP
//*                      - Set the initial PC == __iar_program_start,
//*                      - Set the vector table entries with the exceptions ISR
//*                        address,
//*                      - Branches to main in the C library (which eventually
//*                        calls main()).
//*                      After Reset the Cortex-M0 processor is in Thread mode,
//*                      priority is Privileged, and the Stack is set to Main.
//*******************************************************************************
//*
//* Redistribution and use in source and binary forms, with or without modification,
//* are permitted provided that the following conditions are met:
//*   1. Redistributions of source code must retain the above copyright notice,
//*      this list of conditions and the following disclaimer.
//*   2. Redistributions in binary form must reproduce the above copyright notice,
//*      this list of conditions and the following disclaimer in the documentation
//*      and/or other materials provided with the distribution.
//*   3. Neither the name of STMicroelectronics nor the names of its contributors
//*      may be used to endorse or promote products derived from this software
//*      without specific prior written permission.
//*
//* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//* SERVICES// LOSS OF USE, DATA, OR PROFITS// OR BUSINESS INTERRUPTION) HOWEVER
//* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*
//*******************************************************************************
//
//
// The modules in this file are included in the libraries, and may be replaced
// by any user-defined modules that define the PUBLIC symbol _program_start or
// a user defined start symbol.
// To override the cstartup defined in the library, simply add your modified
// version to the workbench project.
//
// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// The name "__vector_table" has special meaning for C-SPY:
// it is where the SP start value is found, and the NVIC vector
// table register (VTOR) is initialized to this address if != 0.
//
// Cortex-M version
//

        MODULE  ?cstartup

        // Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

#include "stm32f0xx_device.h"

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler                  // Reset Handler

        DCD     NMI_Handler                    // NMI Handler
        DCD     HardFault_Handler              // Hard Fault Handler
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     SVC_Handler                    // SVCall Handler
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     PendSV_Handler                 // PendSV Handler
        DCD     SysTick_Handler                // SysTick Handler

#if defined(STM32F030x6)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     0                              // Reserved
        DCD     TIM3_IRQHandler                // TIM3
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     0                              // Reserved
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     0                              // Reserved
        DCD     SPI1_IRQHandler                // SPI1
        DCD     0                              // Reserved
        DCD     USART1_IRQHandler              // USART1

#elif defined(STM32F030x8)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     0                              // Reserved
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_IRQHandler                // TIM6
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2

#elif defined(STM32F030xC)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     0                              // Reserved
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_IRQHandler                // TIM6
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_6_IRQHandler            // USART3, USART4, USART5, USART6
        DCD     0                              // Reserved
        DCD     0                              // Reserved

#elif defined(STM32F031x6)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     PVD_IRQHandler                 // PVD through EXTI Line detect
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     0                              // Reserved
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     0                              // Reserved
        DCD     SPI1_IRQHandler                // SPI1
        DCD     0                              // Reserved
        DCD     USART1_IRQHandler              // USART1

#elif defined(STM32F038xx)
        // External Interrupts
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     0                              // Reserved
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     0                              // Reserved
        DCD     SPI1_IRQHandler                // SPI1
        DCD     0                              // Reserved
        DCD     USART1_IRQHandler              // USART1

#elif defined(STM32F042x6)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     PVD_VDDIO2_IRQHandler          // PVD and VDDIO2 through EXTI Line detect
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     0                              // Reserved
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     0                              // Reserved
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     0                              // Reserved
        DCD     CEC_CAN_IRQHandler             // CEC and CAN
        DCD     USB_IRQHandler                 // USB

#elif defined(STM32F048xx)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     VDDIO2_IRQHandler              // VDDIO2 Monitor through EXTI Line 31
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     0                              // Reserved
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     0                              // Reserved
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     0                              // Reserved
        DCD     CEC_CAN_IRQHandler             // CEC and CAN
        DCD     USB_IRQHandler                 // USB

#elif defined(STM32F051x8)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     PVD_IRQHandler                 // PVD through EXTI Line detect
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     0                              // Reserved
        DCD     CEC_CAN_IRQHandler             // CEC and CAN

#elif defined(STM32F058xx)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     0                              // Reserved
        DCD     CEC_CAN_IRQHandler             // CEC and CAN

#elif defined(STM32F070x6)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     0                              // Reserved
        DCD     TIM3_IRQHandler                // TIM3
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     TIM14_IRQHandler               // TIM14
        DCD     0                              // Reserved
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     0                              // Reserved
        DCD     SPI1_IRQHandler                // SPI1
        DCD     0                              // Reserved
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     0                              // Reserved
        DCD     0                              // Reserved
        DCD     USB_IRQHandler                 // USB

#elif defined(STM32F070xB)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     0                              // Reserved
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_IRQHandler                 // RCC
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     0                              // Reserved
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_IRQHandler     // DMA1 Channel 4 and Channel 5
        DCD     ADC1_IRQHandler                // ADC1
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     0                              // Reserved
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_IRQHandler                // TIM6
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_4_IRQHandler            // USART3 and USART4
        DCD     0                              // Reserved
        DCD     USB_IRQHandler                 // USB

#elif defined(STM32F071xB)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     PVD_VDDIO2_IRQHandler          // PVD and VDDIO2 through EXTI Line detect
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_6_7_IRQHandler // DMA1 Channel 4 to Channel 7
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_4_IRQHandler            // USART3 and USART4
        DCD     CEC_CAN_IRQHandler             // CEC and CAN

#elif defined(STM32F072xB)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     PVD_VDDIO2_IRQHandler          // PVD and VDDIO2 through EXTI Line detect
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_6_7_IRQHandler // DMA1 Channel 4 to Channel 7
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_4_IRQHandler            // USART3 and USART4
        DCD     CEC_CAN_IRQHandler             // CEC and CAN
        DCD     USB_IRQHandler                 // USB

#elif defined(STM32F078xx)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     VDDIO2_IRQHandler              // VDDIO2 Monitor through EXTI Line 31
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TSC
        DCD     DMA1_Channel1_IRQHandler       // DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     // DMA1 Channel 2 and Channel 3
        DCD     DMA1_Channel4_5_6_7_IRQHandler // DMA1 Channel 4 to Channel 7
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_4_IRQHandler            // USART3 and USART4
        DCD     CEC_CAN_IRQHandler             // CEC and CAN
        DCD     USB_IRQHandler                 // USB

#elif defined(STM32F091xC)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     PVD_VDDIO2_IRQHandler          // PVD and VDDIO2 through EXTI Line detect
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TS
        DCD     DMA1_Ch1_IRQHandler       		 // DMA1 Channel 1
        DCD     DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler // DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2
        DCD     DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler // DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_8_IRQHandler    				 // USART3, USART4, USART5, USART6, USART7, USART8
        DCD     CEC_CAN_IRQHandler             // CEC and CAN

#elif defined(STM32F098xx)
        // External Interrupts
        DCD     WWDG_IRQHandler                // Window Watchdog
        DCD     VDDIO2_IRQHandler              // VDDIO2 Monitor through EXTI Line 31
        DCD     RTC_IRQHandler                 // RTC through EXTI Line
        DCD     FLASH_IRQHandler               // FLASH
        DCD     RCC_CRS_IRQHandler             // RCC and CRS
        DCD     EXTI0_1_IRQHandler             // EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             // EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            // EXTI Line 4 to 15
        DCD     TSC_IRQHandler                 // TS
        DCD     DMA1_Ch1_IRQHandler       		 // DMA1 Channel 1
        DCD     DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler // DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2
        DCD     DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler // DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5
        DCD     ADC1_COMP_IRQHandler           // ADC1, COMP1 and COMP2
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler // TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             // TIM1 Capture Compare
        DCD     TIM2_IRQHandler                // TIM2
        DCD     TIM3_IRQHandler                // TIM3
        DCD     TIM6_DAC_IRQHandler            // TIM6 and DAC
        DCD     TIM7_IRQHandler                // TIM7
        DCD     TIM14_IRQHandler               // TIM14
        DCD     TIM15_IRQHandler               // TIM15
        DCD     TIM16_IRQHandler               // TIM16
        DCD     TIM17_IRQHandler               // TIM17
        DCD     I2C1_IRQHandler                // I2C1
        DCD     I2C2_IRQHandler                // I2C2
        DCD     SPI1_IRQHandler                // SPI1
        DCD     SPI2_IRQHandler                // SPI2
        DCD     USART1_IRQHandler              // USART1
        DCD     USART2_IRQHandler              // USART2
        DCD     USART3_8_IRQHandler    				 // USART3, USART4, USART5, USART6, USART7, USART8
        DCD     CEC_CAN_IRQHandler             // CEC and CAN

#else
 #error "Please select the target STM32F0xx device used in your project."
#endif


//
// Default interrupt handlers.
//
        THUMB

        PUBWEAK Reset_Handler
        //SECTION .text:CODE:NOROOT:REORDER(2)
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =sfe(CSTACK)          // set stack pointer
        MSR     MSP, R0                   // maybe from BootLoader

// Check if boot space corresponds to test memory
//
// After reset these bits take on the value selected by the actual boot mode configuration
// The boot mode configuration is also re-sampled when exiting from Standby mode.
// Consequently they must be kept in the required Boot mode configuration in Standby mode.
// Once the boot mode is selected, the application can modify the memory accessible in the code area.
// This modification is performed by programming the MEM_MODE bits in SYSCFG_CFGR1.
//
// MEM_MODE[1:0]: Memory mapping selection bits
//
// 00: Main Flash memory mapped at 0x00000000
// 01: System Flash memory mapped at 0x00000000
// 10: Main Flash memory mapped at 0x00000000
// 11: Embedded SRAM mapped at 0x00000000

// SYSCFG clock enable
        LDR R0,=0x40021018
        LDR R1,=0x00000001
        STR R1, [R0]

// 0x08000000, 0x08001000, 0x20000000
// BootLoader, Application Debug

        LDR R0,=__vector_table
        LDR R1,=0x08000000
        CMP R0, R1
        BEQ ApplicationStart

        LDR R1,=0x20000000
        CMP R0, R1
        BEQ MapVectorToSRAM

// Copy 48 DWords from Flash to Sram
        LDR R3,=12
CopyAndMapVectorToSRAM
        LDMIA R0!,{R4-R7}
        STMIA R1!,{R4-R7}
        SUBS R3, R3, #1
        BNE CopyAndMapVectorToSRAM

// Set CFGR1 register with sram memory remap at address 0
MapVectorToSRAM
        LDR R0,=0x40010000
        LDR R1,=0x00000003
        STR R1, [R0]

ApplicationStart
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK ADC1_COMP_IRQHandler
        PUBWEAK ADC1_IRQHandler
        PUBWEAK CEC_CAN_IRQHandler
        PUBWEAK CEC_IRQHandler
        PUBWEAK DMA1_Ch1_IRQHandler
        PUBWEAK DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler
        PUBWEAK DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
        PUBWEAK DMA1_Channel1_IRQHandler
        PUBWEAK DMA1_Channel2_3_IRQHandler
        PUBWEAK DMA1_Channel4_5_6_7_IRQHandler
        PUBWEAK DMA1_Channel4_5_IRQHandler
        PUBWEAK EXTI0_1_IRQHandler
        PUBWEAK EXTI2_3_IRQHandler
        PUBWEAK EXTI4_15_IRQHandler
        PUBWEAK FLASH_IRQHandler
        PUBWEAK HardFault_Handler
        PUBWEAK I2C1_IRQHandler
        PUBWEAK I2C2_IRQHandler
        PUBWEAK NMI_Handler
        PUBWEAK PVD_IRQHandler
        PUBWEAK PVD_VDDIO2_IRQHandler
        PUBWEAK PendSV_Handler
        PUBWEAK RCC_CRS_IRQHandler
        PUBWEAK RCC_IRQHandler
        PUBWEAK RTC_IRQHandler
        PUBWEAK SPI1_IRQHandler
        PUBWEAK SPI2_IRQHandler
        PUBWEAK SVC_Handler
        PUBWEAK SysTick_Handler
        PUBWEAK TIM14_IRQHandler
        PUBWEAK TIM15_IRQHandler
        PUBWEAK TIM16_IRQHandler
        PUBWEAK TIM17_IRQHandler
        PUBWEAK TIM1_BRK_UP_TRG_COM_IRQHandler
        PUBWEAK TIM1_CC_IRQHandler
        PUBWEAK TIM2_IRQHandler
        PUBWEAK TIM3_IRQHandler
        PUBWEAK TIM6_DAC_IRQHandler
        PUBWEAK TIM6_IRQHandler
        PUBWEAK TIM7_IRQHandler
        PUBWEAK TSC_IRQHandler
        PUBWEAK TS_IRQHandler
        PUBWEAK USART1_IRQHandler
        PUBWEAK USART2_IRQHandler
        PUBWEAK USART3_4_IRQHandler
        PUBWEAK USART3_6_IRQHandler
        PUBWEAK USART3_8_IRQHandler
        PUBWEAK USB_IRQHandler
        PUBWEAK VDDIO2_IRQHandler
        PUBWEAK WWDG_IRQHandler

        //SECTION .text:CODE:NOROOT:REORDER(1)
        SECTION .text:CODE:REORDER:NOROOT(1)

ADC1_COMP_IRQHandler
ADC1_IRQHandler
CEC_CAN_IRQHandler
CEC_IRQHandler
DMA1_Ch1_IRQHandler
DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler
DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler
DMA1_Channel1_IRQHandler
DMA1_Channel2_3_IRQHandler
DMA1_Channel4_5_6_7_IRQHandler
DMA1_Channel4_5_IRQHandler
EXTI0_1_IRQHandler
EXTI2_3_IRQHandler
EXTI4_15_IRQHandler
FLASH_IRQHandler
HardFault_Handler
I2C1_IRQHandler
I2C2_IRQHandler
NMI_Handler
PVD_IRQHandler
PVD_VDDIO2_IRQHandler
PendSV_Handler
RCC_CRS_IRQHandler
RCC_IRQHandler
RTC_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
SVC_Handler
SysTick_Handler
TIM14_IRQHandler
TIM15_IRQHandler
TIM16_IRQHandler
TIM17_IRQHandler
TIM1_BRK_UP_TRG_COM_IRQHandler
TIM1_CC_IRQHandler
TIM2_IRQHandler
TIM3_IRQHandler
TIM6_DAC_IRQHandler
TIM6_IRQHandler
TIM7_IRQHandler
TS_IRQHandler
TSC_IRQHandler
USART1_IRQHandler
USART2_IRQHandler
USART3_4_IRQHandler
USART3_6_IRQHandler
USART3_8_IRQHandler
USB_IRQHandler
VDDIO2_IRQHandler
WWDG_IRQHandler
        B       .

        END

