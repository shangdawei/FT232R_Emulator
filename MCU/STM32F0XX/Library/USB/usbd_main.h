/**
  ******************************************************************************
  * @file    usbd_cdc_vcp.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-January-2014
  * @brief   Header for usbd_cdc_vcp.c file.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_MAIN_H__
#define __USBD_MAIN_H__

/* Includes ------------------------------------------------------------------*/
#include "usbd_class.h"

typedef enum
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;

#define COMn                             1

/**
 * @brief Definition for COM port1, connected to USART2
 */
#define EVAL_COM1                        USART2
#define EVAL_COM1_CLK                    RCC_APB1Periph_USART2

#define EVAL_COM1_TX_PIN                 GPIO_Pin_5
#define EVAL_COM1_TX_GPIO_PORT           GPIOD
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHBPeriph_GPIOD
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource5
#define EVAL_COM1_TX_AF                  GPIO_AF_0

#define EVAL_COM1_RX_PIN                 GPIO_Pin_6
#define EVAL_COM1_RX_GPIO_PORT           GPIOD
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHBPeriph_GPIOD
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource6
#define EVAL_COM1_RX_AF                  GPIO_AF_0

#define EVAL_COM1_CTS_PIN                GPIO_Pin_3
#define EVAL_COM1_CTS_GPIO_PORT          GPIOD
#define EVAL_COM1_CTS_GPIO_CLK           RCC_AHBPeriph_GPIOD
#define EVAL_COM1_CTS_SOURCE             GPIO_PinSource3
#define EVAL_COM1_CTS_AF                 GPIO_AF_0

#define EVAL_COM1_RTS_PIN                GPIO_Pin_4
#define EVAL_COM1_RTS_GPIO_PORT          GPIOD
#define EVAL_COM1_RTS_GPIO_CLK           RCC_AHBPeriph_GPIOD
#define EVAL_COM1_RTS_SOURCE             GPIO_PinSource4
#define EVAL_COM1_RTS_AF                 GPIO_AF_0

#define EVAL_COM1_IRQn                   USART2_IRQn

/* Exported typef ------------------------------------------------------------*/
/* The following structures groups all needed parameters to be configured for the
   ComPort. These parameters can be modified on the fly by the host through CDC class
   command class requests. */
typedef struct
{
  uint32_t bitrate;
  uint8_t  format;
  uint8_t  paritytype;
  uint8_t  datatype;
}LINE_CODING;

/* Exported constants --------------------------------------------------------*/
/* The following define is used to route the USART IRQ handler to be used.
   The IRQ handler function is implemented in the usbd_cdc_vcp.c file. */

#define EVAL_COM_IRQHandler            USART2_IRQHandler

#define USART_IT_PRIO                  0
#define USB_IT_PRIO                    1 /* USB priority should be lower than USART
                                            in order to not loose data reception from
                                            USART while USB interrupt is being handled*/

#define DEFAULT_CONFIG                  0
#define OTHER_CONFIG                    1

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void EVAL_COM_IRQHandler(void);

#endif /* __USBD_MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
