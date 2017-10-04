#ifndef __FT232R_EMULATOR_BSP_CONF_H__
#define __FT232R_EMULATOR_BSP_CONF_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f0xx.h"

#define BSP_USART_USES_USART2             ( 1 )

#define BSP_USART_RTS_CTS_EANBLED         ( 0 )
#define BSP_USART_DTR_DSR_EANBLED         ( 0 )
#define BSP_USART_DCD_RI_EANBLED          ( 0 )

#define BSP_USART_HW_RTS_CTS_EANBLED      ( 0 )

// TXFIFO ---> BUFFER : Word
// RXFIFO <--- BUFFER : Word
//
#define BSP_USART_TX_BUFFER_WORD_SIZE     ( 64 )
#define BSP_USART_RX_BUFFER_WORD_SIZE     ( 64 )

extern void foo( void );

/*
 * -------------------------------------------------------------------------------------------------
 * FT232R
 * -------------------------------------------------------------------------------------------------
 * DataBit : 7, 8
 * StopBit : 1, 1.5, 2
 * Parity  : None, Even, Odd, Space, Mark
 *
 * FT232R UART TX CLOCK =  3 MHz
 * FT232R UART RX CLOCK = 48 MHz
 *
 * -------------------------------------------------------------------------------------------------
 * STM32F072
 * -------------------------------------------------------------------------------------------------
 * M  PCE  WL DB USART Frame
 * -------------------------------------------------------------------------------------------------
 * 01 0    9  9  SB : Data[9]      : STB
 * 00 0    8  8  SB : Data[8]      : STB
 * 10 0    7  7  SB : Data[7]      : STB
 *
 * 01 1    8  8  SB : Data[8] : PB : STB <---- PB : ODD or EVEN are handled in HW
 * 00 1    7  7  SB : Data[7] : PB : STB <---- PB : ODD or EVEN are handled in HW
 * 10 1    6  6  SB : Data[6] : PB : STB <---- PB : ODD or EVEN are handled in HW
 *
 * 01 0    9  8  SB : Data[8] : SP : STB <---- SP : SPACE or MARK are handled in SW
 * 00 0    8  7  SB : Data[7] : SP : STB <---- SP : SPACE or MARK are handled in SW
 * 10 0    7  6  SB : Data[6] : SP : STB <---- SP : SPACE or MARK are handled in SW
 *
 * SPACE : Data.MSB = 1
 * MARK  : Data.MSB = 0
 * -------------------------------------------------------------------------------------------------
 * 7, N, X <--> 7, N, X : Without  Parity
 * 7, M, X <--> 8, N, X : Software Parity : Data |=  0x80 : Bit7 = Space
 * 7, S, X <--> 8, N, X : Software Parity : Data &= ~0x80 : Bit7 = Mark
 * 7, O, X <--> 7, O, X : Hardware Parity
 * 7, E, X <--> 7, E, X : Hardware Parity
 * 8, N, X <--> 8, N, X : Without  Parity
 * 8, M, X <--> 9, N, X : Software Parity : Data |=  0x100 : Bit8 = Space
 * 8, S, X <--> 9, N, X : Software Parity : Data &= ~0x100 : Bit8 = Mark
 * 8, O, X <--> 8, O, X : Hardware Parity
 * 8, E, X <--> 8, E, X : Hardware Parity
 *
 * USART1/USART2
 * -------------------------------------------------------------------------------------------------
 * SystemCoreClock = 48 MHz, USART Clock : PCLK/SYSCLK = 48 MHz
 * UART TX CLOCK : 48 MHz / 16 = 3 MHz : 16X Sample
 * UART TX CLOCK : 48 MHz /  8 = 6 MHz :  8X Sample
 *
 * UART_BRR = ( PCLK + (BAUD >> 1) ) / BAUD
 */

#if ( 0 == BSP_USART_USES_USART2 )
/*
 * USART1
 * -------------------------------------------------------------------------------------------------
 */
#define BSP_USART                         USART1
#define BSP_USART_CLK                     RCC_APB2Periph_USART1
#define BSP_USART_IRQ                     USART1_IRQn
#define BSP_USART_IRQHandler              USART1_IRQHandler

#define BSP_USART_DMA                     DMA1
#define BSP_USART_DMA_IRQHandler          DMA1_Channel2_3_IRQHandler

#define BSP_USART_TXDMA_CLK               RCC_AHBPeriph_DMA1
#define BSP_USART_TXDMA_CH                DMA1_Channel2
#define BSP_USART_TXDMA_IRQ               DMA1_Channel2_3_IRQn
#define BSP_USART_TXDMA_CGIF              DMA_IFCR_CGIF2
#define BSP_USART_TXDMA_CTCIF             DMA_IFCR_CTCIF2
#define BSP_USART_TXDMA_CTEIF             DMA_IFCR_CTEIF2

#define BSP_USART_RXDMA_CLK               RCC_AHBPeriph_DMA1
#define BSP_USART_RXDMA_CH                DMA1_Channel3
#define BSP_USART_RXDMA_IRQ               DMA1_Channel2_3_IRQn
#define BSP_USART_RXDMA_CGIF              DMA_IFCR_CGIF3
#define BSP_USART_RXDMA_CTCIF             DMA_IFCR_CTCIF3
#define BSP_USART_RXDMA_CTEIF             DMA_IFCR_CTEIF3

#define BSP_USART_TX_PIN                  GPIO_Pin_9
#define BSP_USART_TX_GPIO_PORT            GPIOA
#define BSP_USART_TX_GPIO_CLK             RCC_AHBPeriph_GPIOA
#define BSP_USART_TX_PIN_SOURCE           GPIO_PinSource9
#define BSP_USART_TX_AF                   GPIO_AF_1

#define BSP_USART_RX_PIN                  GPIO_Pin_10
#define BSP_USART_RX_GPIO_PORT            GPIOA
#define BSP_USART_RX_GPIO_CLK             RCC_AHBPeriph_GPIOA
#define BSP_USART_RX_PIN_SOURCE           GPIO_PinSource10
#define BSP_USART_RX_AF                   GPIO_AF_1

#if ( BSP_USART_RTS_CTS_EANBLED > 0 )
//
// Hardware RTS/CTS FlowCtrl is not available
//
#define BSP_USART_RTS_PIN                 GPIO_Pin_12
#define BSP_USART_RTS_GPIO_PORT           GPIOA
#define BSP_USART_RTS_GPIO_CLK            RCC_AHBPeriph_GPIOA
#define BSP_USART_RTS_PIN_SOURCE          GPIO_PinSource12
#define BSP_USART_RTS_AF                  GPIO_AF_1

#define BSP_USART_CTS_PIN                 GPIO_Pin_11
#define BSP_USART_CTS_GPIO_PORT           GPIOA
#define BSP_USART_CTS_GPIO_CLK            RCC_AHBPeriph_GPIOA
#define BSP_USART_CTS_PIN_SOURCE          GPIO_PinSource11
#define BSP_USART_CTS_AF                  GPIO_AF_1

// EXTI
#define BSP_USART_CTS_EXTI_LINE           EXTI_Line13
#define BSP_USART_CTS_EXTI_PORT_SOURCE    EXTI_PortSourceGPIOC
#define BSP_USART_CTS_EXTI_PIN_SOURCE     EXTI_PinSource13
#define BSP_USART_CTS_EXTI_IRQn           EXTI4_15_IRQn

#else

#define BSP_USART_RTS_GPIO_CLK            0
#define BSP_USART_CTS_GPIO_CLK            0

#endif

#else

/*
 * USART2
 * -------------------------------------------------------------------------------------------------
 */
#define BSP_USART                         USART2
#define BSP_USART_CLK                     RCC_APB1Periph_USART2
#define BSP_USART_IRQ                     USART2_IRQn
#define BSP_USART_IRQHandler              USART2_IRQHandler

#define BSP_USART_DMA                     DMA1
#define BSP_USART_DMA_IRQHandler          DMA1_Channel4_5_6_7_IRQHandler

#define BSP_USART_TXDMA_CLK               RCC_AHBPeriph_DMA1
#define BSP_USART_TXDMA_CH                DMA1_Channel4
#define BSP_USART_TXDMA_IRQ               DMA1_Channel4_5_6_7_IRQn
#define BSP_USART_TXDMA_CGIF              DMA_IFCR_CGIF4
#define BSP_USART_TXDMA_CTCIF             DMA_IFCR_CTCIF4
#define BSP_USART_TXDMA_CTEIF             DMA_IFCR_CTEIF4

#define BSP_USART_RXDMA_CLK               RCC_AHBPeriph_DMA1
#define BSP_USART_RXDMA_CH                DMA1_Channel5
#define BSP_USART_RXDMA_IRQ               DMA1_Channel4_5_6_7_IRQn
#define BSP_USART_RXDMA_CGIF              DMA_IFCR_CGIF5
#define BSP_USART_RXDMA_CTCIF             DMA_IFCR_CTCIF5
#define BSP_USART_RXDMA_CTEIF             DMA_IFCR_CTEIF5

#define BSP_USART_TX_PIN                  GPIO_Pin_2
#define BSP_USART_TX_GPIO_PORT            GPIOA
#define BSP_USART_TX_GPIO_CLK             RCC_AHBPeriph_GPIOA
#define BSP_USART_TX_PIN_SOURCE           GPIO_PinSource2
#define BSP_USART_TX_AF                   GPIO_AF_1

#define BSP_USART_RX_PIN                  GPIO_Pin_3
#define BSP_USART_RX_GPIO_PORT            GPIOA
#define BSP_USART_RX_GPIO_CLK             RCC_AHBPeriph_GPIOA
#define BSP_USART_RX_PIN_SOURCE           GPIO_PinSource3
#define BSP_USART_RX_AF                   GPIO_AF_1

//
// Hardware RTS/CTS FlowCtrl is available
//
#if ( BSP_USART_RTS_CTS_EANBLED > 0 )

#define BSP_USART_RTS_PIN                 GPIO_Pin_1
#define BSP_USART_RTS_GPIO_PORT           GPIOA
#define BSP_USART_RTS_GPIO_CLK            RCC_AHBPeriph_GPIOA
#define BSP_USART_RTS_PIN_SOURCE          GPIO_PinSource1
#define BSP_USART_RTS_AF                  GPIO_AF_1

#define BSP_USART_CTS_PIN                 GPIO_Pin_0
#define BSP_USART_CTS_GPIO_PORT           GPIOA
#define BSP_USART_CTS_GPIO_CLK            RCC_AHBPeriph_GPIOA
#define BSP_USART_CTS_PIN_SOURCE          GPIO_PinSource0
#define BSP_USART_CTS_AF                  GPIO_AF_1

// EXTI
#define BSP_USART_CTS_EXTI_LINE           EXTI_Line0
#define BSP_USART_CTS_EXTI_PORT_SOURCE    EXTI_PortSourceGPIOA
#define BSP_USART_CTS_EXTI_PIN_SOURCE     EXTI_PinSource0
#define BSP_USART_CTS_EXTI_IRQn           EXTI4_15_IRQn

#else

#define BSP_USART_RTS_GPIO_CLK            0
#define BSP_USART_CTS_GPIO_CLK            0

#endif

#endif

#if ( BSP_USART_DTR_DSR_EANBLED > 0 )

#define BSP_USART_DTR_PIN                 GPIO_Pin_1
#define BSP_USART_DTR_GPIO_PORT           GPIOC
#define BSP_USART_DTR_GPIO_CLK            RCC_AHBPeriph_GPIOB

#define BSP_USART_DSR_PIN                 GPIO_Pin_0
#define BSP_USART_DSR_GPIO_PORT           GPIOB
#define BSP_USART_DSR_GPIO_CLK            RCC_AHBPeriph_GPIOB

// EXTI
#define BSP_USART_DSR_EXTI_LINE           EXTI_Line0
#define BSP_USART_DSR_EXTI_PORT_SOURCE    EXTI_PortSourceGPIOB
#define BSP_USART_DSR_EXTI_PIN_SOURCE     EXTI_PinSource0
#define BSP_USART_DSR_EXTI_IRQn           EXTI0_1_IRQn

#else

#define BSP_USART_DTR_GPIO_CLK            0
#define BSP_USART_DSR_GPIO_CLK            0

#endif

#if ( BSP_USART_DCD_RI_EANBLED > 0 )

#define BSP_USART_DCD_PIN                 GPIO_Pin_1
#define BSP_USART_DCD_GPIO_PORT           GPIOC
#define BSP_USART_DCD_GPIO_CLK            RCC_AHBPeriph_GPIOC

#define BSP_USART_RI_PIN                  GPIO_Pin_0
#define BSP_USART_RI_GPIO_PORT            GPIOC
#define BSP_USART_RI_GPIO_CLK             RCC_AHBPeriph_GPIOC

#else

#define BSP_USART_DCD_GPIO_CLK            0
#define BSP_USART_RI_GPIO_CLK             0

#endif

#ifdef __cplusplus
}
#endif

#endif /* __FT232R_EMULATOR_BSP_CONF_H__ */
