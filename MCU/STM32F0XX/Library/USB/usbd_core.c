/**
 ******************************************************************************
 * @file    usbd_core.c
 * @author  MCD Application Team
 * @version V1.0.1
 * @date    31-January-2014
 * @brief   This file provides all the USBD core functions.
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
#include "usbd_core.h"
#include "usbd_ctrlreq.h"
#include "usbd_ioreq.h"

#include "FT232R_Emulator_Conf.h"

#define USB_MAX_EP0_SIZE                     FT232R_EMULATOR_ENDPOINT0_SIZE

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern uint32_t ADDRESS;

/* Private function prototypes -----------------------------------------------*/
static uint8_t USBD_SetupStage( USB_CORE_HANDLE *pdev );
static uint8_t USBD_DataOutStage( USB_CORE_HANDLE *pdev, uint8_t epnum );
static uint8_t USBD_DataInStage( USB_CORE_HANDLE *pdev, uint8_t epnum );
static uint8_t USBD_SOF( USB_CORE_HANDLE *pdev );
static uint8_t USBD_Reset( USB_CORE_HANDLE *pdev );
static uint8_t USBD_Suspend( USB_CORE_HANDLE *pdev );
static uint8_t USBD_Resume( USB_CORE_HANDLE *pdev );

USBD_DCD_INT_cb_TypeDef USBD_DCD_INT_cb = {
  USBD_DataOutStage, USBD_DataInStage, USBD_SetupStage, USBD_SOF, USBD_Reset, USBD_Suspend, USBD_Resume,

};

USBD_DCD_INT_cb_TypeDef *USBD_DCD_INT_fops = &USBD_DCD_INT_cb;

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  USBD_Init
 *         Initializes the device stack and load the class driver
 * @param  pdev: device instance
 * @param  class_cb: Class callback structure address
 * @param  usr_cb: User callback structure address
 * @retval None
 */
void USBD_Init( USB_CORE_HANDLE *pdev )
{
  /* Hardware Init */
  USB_BSP_Init( pdev );

  USBD_DeInit( pdev );

  /* set USB DEVICE core params */
  DCD_Init( pdev );

  /* Enable Interrupts */
  USB_BSP_EnableInterrupt( pdev );
}

/**
 * @brief  USBD_DeInit
 *         Re-Initialize th device library
 * @param  pdev: device instance
 * @retval status: status
 */
USBD_Status USBD_DeInit( USB_CORE_HANDLE *pdev )
{
  /* Software Init */

  return USBD_OK;
}

/**
 * @brief  USBD_SetupStage
 *         Handle the setup stage
 * @param  pdev: device instance
 * @retval status
 */
static uint8_t USBD_SetupStage( USB_CORE_HANDLE *pdev )
{
  USB_SETUP_REQ req;
  USB_SetupPacket_TypeDef * setup_packet;

  pdev->dev.setup_external = 0;
  setup_packet = (USB_SetupPacket_TypeDef *) &pdev->dev.setup_packet;
  USBD_RequestStatus_TypeDef RequestStatus = USBD_Device->callback->USBD_Device_Endpoint0_SetupPacketReceived(
    setup_packet, &pdev->dev.setup_buffer, &pdev->dev.setup_length );

  if ( usbdRequestNotProcessed != RequestStatus )
  {
    pdev->dev.setup_external = 1;
    if ( usbdRequestOK != RequestStatus )
      DCD_EP_Stall( pdev, setup_packet->bmRequestType.Dir );
    else if ( setup_packet->wLength == 0 )        // NoData Setup
      USBD_CtlSendStatus( pdev );
    else if ( setup_packet->bmRequestType.Dir )   // Data Setup, Control In
      USBD_CtlSendData( pdev, pdev->dev.setup_buffer, MIN( pdev->dev.setup_length, setup_packet->wLength ) );
    else
      USBD_CtlPrepareRx( pdev, pdev->dev.setup_buffer, MIN( pdev->dev.setup_length, setup_packet->wLength ) );

    return USBD_OK;
  }

  USBD_ParseSetupRequest( pdev, &req );

  switch ( req.bmRequest & 0x1F )
  {
    case USB_REQ_RECIPIENT_DEVICE:
      USBD_StdDevReq( pdev, &req );
      break;

    case USB_REQ_RECIPIENT_INTERFACE:
      USBD_StdItfReq( pdev, &req );
      break;

    case USB_REQ_RECIPIENT_ENDPOINT:
      USBD_StdEPReq( pdev, &req );
      break;

    default:
      DCD_EP_Stall( pdev, req.bmRequest & 0x80 );
      break;
  }
  return USBD_OK;
}

/**
 * @brief  USBD_DataOutStage
 *         Handle data out stage
 * @param  pdev: device instance
 * @param  epnum: endpoint index
 * @retval status
 */
static uint8_t USBD_DataOutStage( USB_CORE_HANDLE *pdev, uint8_t epnum )
{
  USB_EP *ep;

  if ( epnum == 0 )
  {
    ep = &pdev->dev.out_ep[ 0 ];
    if ( pdev->dev.device_state == USB_EP0_DATA_OUT )
    {
      if ( ep->rem_data_len > ep->maxpacket )
      {
        ep->rem_data_len -= ep->maxpacket;
        USBD_CtlContinueRx( pdev, ep->xfer_buff, MIN( ep->rem_data_len, ep->maxpacket ) );
      }
      else
      {
        if ( ( USBD_Device->callback->USBD_Device_Endpoint0_OutDataReceived )
          && ( pdev->dev.device_status == USB_CONFIGURED ) )
        {
          USBD_Device->callback->USBD_Device_Endpoint0_OutDataReceived( ep->total_data_len );
        }
        USBD_CtlSendStatus( pdev );
      }
    }
  }
  else if ( ( USBD_Device->callback->USBD_Device_EventEndpoint ) && ( pdev->dev.device_status == USB_CONFIGURED ) )
  {
    USBD_Device->callback->USBD_Device_EventEndpoint( 0x7F & epnum, ARM_USBD_EVENT_OUT );
  }

  return USBD_OK;
}

/**
 * @brief  USBD_DataInStage
 *         Handle data in stage
 * @param  pdev: device instance
 * @param  epnum: endpoint index
 * @retval status
 */
static uint8_t USBD_DataInStage( USB_CORE_HANDLE *pdev, uint8_t epnum )
{
  USB_EP *ep;

  if ( epnum == 0 )
  {
    ep = &pdev->dev.in_ep[ 0 ];
    if ( pdev->dev.device_state == USB_EP0_DATA_IN )
    {
      if ( ep->rem_data_len > ep->maxpacket )
      {
        ep->rem_data_len -= ep->maxpacket;
        USBD_CtlContinueSendData( pdev, ep->xfer_buff, ep->rem_data_len );
      }
      else
      { /* last packet is MPS multiple, so send ZLP packet */
        if ( ( ep->total_data_len % ep->maxpacket == 0 ) && ( ep->total_data_len >= ep->maxpacket )
          && ( ep->total_data_len < ep->ctl_data_len ) )
        {
          USBD_CtlContinueSendData( pdev, NULL, 0 );
          ep->ctl_data_len = 0;
        }
        else
        {
          if ( ( USBD_Device->callback->USBD_Device_Endpoint0_InDataSent )
            && ( pdev->dev.device_status == USB_CONFIGURED ) )
          {
            USBD_Device->callback->USBD_Device_Endpoint0_InDataSent( ep->total_data_len );
          }
          USBD_CtlReceiveStatus( pdev );
        }
      }
    }
    else if ( ( pdev->dev.device_state == USB_EP0_STATUS_IN ) && ( ADDRESS != 0 ) )
    {
      DCD_EP_SetAddress( pdev, ADDRESS );
      ADDRESS = 0;
    }
  }
  else if ( ( USBD_Device->callback->USBD_Device_EventEndpoint ) && ( pdev->dev.device_status == USB_CONFIGURED ) )
  {
    USBD_Device->callback->USBD_Device_EventEndpoint( 0x80 | epnum, ARM_USBD_EVENT_IN );
  }
  return USBD_OK;
}

/**
 * @brief  USBD_Reset
 *         Handle Reset event
 * @param  pdev: device instance
 * @retval status
 */

static uint8_t USBD_Reset( USB_CORE_HANDLE *pdev )
{
  /* Open EP0 OUT */
  DCD_EP_Open( pdev, 0x00, USB_MAX_EP0_SIZE, EP_TYPE_CTRL );

  /* Open EP0 IN */
  DCD_EP_Open( pdev, 0x80, USB_MAX_EP0_SIZE, EP_TYPE_CTRL );

  pdev->dev.device_status = USB_DEFAULT;

  /* Upon Reset call user call back */
  if ( USBD_Device->callback->USBD_Device_EventReset )
    USBD_Device->callback->USBD_Device_EventReset( );

  return USBD_OK;
}

/**
 * @brief  USBD_Resume
 *         Handle Resume event
 * @param  pdev: device instance
 * @retval status
 */

static uint8_t USBD_Resume( USB_CORE_HANDLE *pdev )
{
  /* Upon Resume call user call back */
  if ( USBD_Device->callback->USBD_Device_EventResumed )
    USBD_Device->callback->USBD_Device_EventResumed( );
  pdev->dev.device_status = pdev->dev.device_old_status;
  return USBD_OK;
}

/**
 * @brief  USBD_Suspend
 *         Handle Suspend event
 * @param  pdev: device instance
 * @retval status
 */

static uint8_t USBD_Suspend( USB_CORE_HANDLE *pdev )
{
  pdev->dev.device_old_status = pdev->dev.device_status;
  /*Device is in Suspended State*/
  pdev->dev.device_status = USB_SUSPENDED;
  /* Upon Resume call user call back */
  if ( USBD_Device->callback->USBD_Device_EventSuspended )
    USBD_Device->callback->USBD_Device_EventSuspended( );
  return USBD_OK;
}

/**
 * @brief  USBD_SOF
 *         Handle SOF event
 * @param  pdev: device instance
 * @retval status
 */

static uint8_t USBD_SOF( USB_CORE_HANDLE *pdev )
{
  if ( USBD_Device->callback->USBD_Device_EventSOF )
    USBD_Device->callback->USBD_Device_EventSOF( );
  return USBD_OK;
}

/**
 * @brief  USBD_SetCfg
 *        Configure device and start the interface
 * @param  pdev: device instance
 * @param  cfgidx: configuration index
 * @retval status
 */
USBD_Status USBD_SetCfg( USB_CORE_HANDLE *pdev, uint8_t cfgidx )
{
  /* Upon set config call user call back */
  if ( USBD_Device->callback->USBD_Device_EventConfigured )
    USBD_Device->callback->USBD_Device_EventConfigured( cfgidx );

  return USBD_OK;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

