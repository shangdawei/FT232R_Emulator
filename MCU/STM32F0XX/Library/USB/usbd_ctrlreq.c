/**
 ******************************************************************************
 * @file    usbd_req.c
 * @author  MCD Application Team
 * @version V1.0.1
 * @date    31-January-2014
 * @brief   This file provides the standard USB requests following chapter 9.
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
#include "usb_conf.h"
#include "usbd.h"
#include "usbd_ctrlreq.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t ADDRESS = 0;

/* Private function prototypes -----------------------------------------------*/
static void USBD_GetDescriptor( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static void USBD_SetAddress( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static void USBD_SetConfig( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static void USBD_GetConfig( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static void USBD_GetStatus( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static void USBD_SetFeature( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static void USBD_ClrFeature( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req );

static uint8_t USBD_GetLen( uint8_t *buf );

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  USBD_StdDevReq
 *         Handle standard usb device requests
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
USBD_Status USBD_StdDevReq( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  USBD_Status ret = USBD_OK;

  switch ( req->bRequest )
  {
    case USB_REQ_GET_DESCRIPTOR:
      USBD_GetDescriptor( pdev, req );
      break;

    case USB_REQ_SET_ADDRESS:
      USBD_SetAddress( pdev, req );
      break;

    case USB_REQ_SET_CONFIGURATION:
      USBD_SetConfig( pdev, req );
      break;

    case USB_REQ_GET_CONFIGURATION:
      USBD_GetConfig( pdev, req );
      break;

    case USB_REQ_GET_STATUS:
      USBD_GetStatus( pdev, req );
      break;

    case USB_REQ_SET_FEATURE:
      USBD_SetFeature( pdev, req );
      break;

    case USB_REQ_CLEAR_FEATURE:
      USBD_ClrFeature( pdev, req );
      break;

    default:
      USBD_CtlError( pdev, req );
      break;
  }

  return ret;
}

/**
 * @brief  USBD_StdItfReq
 *         Handle standard usb interface requests
 * @param  pdev: USB device instance
 * @param  req: usb request
 * @retval status
 */
USBD_Status USBD_StdItfReq( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  USBD_Status ret = USBD_OK;

  switch ( pdev->dev.device_status )
  {
    case USB_CONFIGURED:

      if ( LOBYTE(req->wIndex) <= USBD_ITF_MAX_NUM )
      {
        if ( ( req->wLength == 0 ) && ( ret == USBD_OK ) )
        {
          USBD_CtlSendStatus( pdev );
        }
      }
      else
      {
        USBD_CtlError( pdev, req );
      }
      break;

    default:
      USBD_CtlError( pdev, req );
      break;
  }
  return ret;
}

/**
 * @brief  USBD_StdEPReq
 *         Handle standard usb endpoint requests
 * @param  pdev: USB device instance
 * @param  req: usb request
 * @retval status
 */
USBD_Status USBD_StdEPReq( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{

  uint8_t ep_addr;
  uint32_t USBD_ep_status = 0;
  USBD_Status ret = USBD_OK;

  ep_addr = LOBYTE( req->wIndex );

  switch ( req->bRequest )
  {
    case USB_REQ_SET_FEATURE:

      switch ( pdev->dev.device_status )
      {
        case USB_ADDRESSED:
          if ( ( ep_addr != 0x00 ) && ( ep_addr != 0x80 ) )
          {
            DCD_EP_Stall( pdev, ep_addr );
          }
          break;

        case USB_CONFIGURED:
          if ( req->wValue == USB_FEATURE_EP_HALT )
          {
            if ( ( ep_addr != 0x00 ) && ( ep_addr != 0x80 ) )
            {
              DCD_EP_Stall( pdev, ep_addr );

            }
          }
          USBD_CtlSendStatus( pdev );

          break;

        default:
          USBD_CtlError( pdev, req );
          break;
      }
      break;

    case USB_REQ_CLEAR_FEATURE:

      switch ( pdev->dev.device_status )
      {
        case USB_ADDRESSED:
          if ( ( ep_addr != 0x00 ) && ( ep_addr != 0x80 ) )
          {
            DCD_EP_Stall( pdev, ep_addr );
          }
          break;

        case USB_CONFIGURED:
          if ( req->wValue == USB_FEATURE_EP_HALT )
          {
            if ( ( ep_addr != 0x00 ) && ( ep_addr != 0x80 ) )
            {
              DCD_EP_ClrStall( pdev, ep_addr );
            }
          }
          USBD_CtlSendStatus( pdev );
          break;

        default:
          USBD_CtlError( pdev, req );
          break;
      }
      break;

    case USB_REQ_GET_STATUS:
      switch ( pdev->dev.device_status )
      {
        case USB_ADDRESSED:
          if ( ( ep_addr != 0x00 ) && ( ep_addr != 0x80 ) )
          {
            DCD_EP_Stall( pdev, ep_addr );
          }
          break;

        case USB_CONFIGURED:

          if ( ( ep_addr & 0x80 ) == 0x80 )
          {
            if ( pdev->dev.in_ep[ ep_addr & 0x7F ].is_stall )
            {
              USBD_ep_status = 0x0001;
            }
            else
            {
              USBD_ep_status = 0x0000;
            }
          }
          else if ( ( ep_addr & 0x80 ) == 0x00 )
          {
            if ( pdev->dev.out_ep[ ep_addr ].is_stall )
            {
              USBD_ep_status = 0x0001;
            }

            else
            {
              USBD_ep_status = 0x0000;
            }
          }
          USBD_CtlSendData( pdev, (uint8_t *) &USBD_ep_status, 2 );
          break;

        default:
          USBD_CtlError( pdev, req );
          break;
      }
      break;

    default:
      break;
  }
  return ret;
}
/**
 * @brief  USBD_GetDescriptor
 *         Handle Get Descriptor requests
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_GetDescriptor( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  uint16_t len;
  uint8_t *pbuf = 0;

  switch ( req->wValue >> 8 )
  {
#ifdef LPM_ENABLED
    case USB_DESC_TYPE_BOS:
    pbuf = pdev->dev.usr_device->GetBOSDescriptor(pdev->dev.speed, &len);
    break;
#endif

    case USB_DESC_TYPE_DEVICE:
      pbuf = USBD_Device->descriptor->device_descriptor;
      len = ( (USB_DEVICE_DESCRIPTOR*) pbuf )->bLength;
      break;

    case USB_DESC_TYPE_CONFIGURATION:
      pbuf = USBD_Device->descriptor->config_descriptor;
      len = ( (USB_CONFIGURATION_DESCRIPTOR*) pbuf )->wTotalLength;
      break;

    case USB_DESC_TYPE_STRING:
      pbuf = USBD_Device->callback->USBD_Device_StringDescriptor( ( (uint8_t) ( req->wValue ) ), &len );
      break;

    default:
      break;
  }

  if ( 0 == pbuf )
    USBD_CtlError( pdev, req );
  else if ( ( len != 0 ) && ( req->wLength != 0 ) )
  {
    len = MIN( len, req->wLength );
    USBD_CtlSendData( pdev, pbuf, len );
  }
}

/**
 * @brief  USBD_SetAddress
 *         Set device address
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_SetAddress( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  uint8_t dev_addr;

  if ( ( req->wIndex == 0 ) && ( req->wLength == 0 ) )
  {
    dev_addr = (uint8_t) ( req->wValue ) & 0x7F;

    if ( pdev->dev.device_status == USB_CONFIGURED )
    {
      USBD_CtlError( pdev, req );
    }
    else
    {
      pdev->dev.device_address = dev_addr;
      ADDRESS = dev_addr;
      USBD_CtlSendStatus( pdev );

      if ( dev_addr != 0 )
      {
        pdev->dev.device_status = USB_ADDRESSED;
      }
      else
      {
        pdev->dev.device_status = USB_DEFAULT;
      }
    }
  }
  else
  {
    USBD_CtlError( pdev, req );
  }
}

/**
 * @brief  USBD_SetConfig
 *         Handle Set device configuration request
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_SetConfig( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  static uint8_t cfgidx;

  cfgidx = (uint8_t) ( req->wValue );

  if ( cfgidx > USBD_CFG_MAX_NUM )
  {
    USBD_CtlError( pdev, req );
  }
  else
  {
    switch ( pdev->dev.device_status )
    {
      case USB_ADDRESSED:
        if ( cfgidx )
        {
          pdev->dev.device_config = cfgidx;
          pdev->dev.device_status = USB_CONFIGURED;
          USBD_SetCfg( pdev, cfgidx );
        }

        USBD_CtlSendStatus( pdev );
        break;

      case USB_CONFIGURED:
        pdev->dev.device_config = cfgidx;
        if ( cfgidx == 0 )
          pdev->dev.device_status = USB_ADDRESSED;

        /* set new configuration */
        USBD_SetCfg( pdev, cfgidx );
        USBD_CtlSendStatus( pdev );
        break;

      default:
        USBD_CtlError( pdev, req );
        break;
    }
  }
}

/**
 * @brief  USBD_GetConfig
 *         Handle Get device configuration request
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_GetConfig( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  uint32_t USBD_default_cfg = 0;

  if ( req->wLength != 1 )
  {
    USBD_CtlError( pdev, req );
  }
  else
  {
    switch ( pdev->dev.device_status )
    {
      case USB_ADDRESSED:

        USBD_CtlSendData( pdev, (uint8_t *) &USBD_default_cfg, 1 );
        break;

      case USB_CONFIGURED:

        USBD_CtlSendData( pdev, &pdev->dev.device_config, 1 );
        break;

      default:
        USBD_CtlError( pdev, req );
        break;
    }
  }
}

/**
 * @brief  USBD_GetStatus
 *         Handle Get Status request
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_GetStatus( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  uint32_t USBD_cfg_status = 0;
  switch ( pdev->dev.device_status )
  {
    case USB_ADDRESSED:
    case USB_CONFIGURED:

#ifdef USBD_SELF_POWERED
      USBD_cfg_status = USB_CONFIG_SELF_POWERED;
#else
      USBD_cfg_status = 0x00;
#endif

      if ( pdev->dev.DevRemoteWakeup )
      {
        USBD_cfg_status |= USB_CONFIG_REMOTE_WAKEUP;
      }

      USBD_CtlSendData( pdev, (uint8_t *) &USBD_cfg_status, 2 );
      break;

    default:
      USBD_CtlError( pdev, req );
      break;
  }
}

/**
 * @brief  USBD_SetFeature
 *         Handle Set device feature request
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_SetFeature( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{

  if ( req->wValue == USB_FEATURE_REMOTE_WAKEUP )
  {
    pdev->dev.DevRemoteWakeup = 1;
    USBD_CtlSendStatus( pdev );
  }
}

/**
 * @brief  USBD_ClrFeature
 *         Handle clear device feature request
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval status
 */
static void USBD_ClrFeature( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  switch ( pdev->dev.device_status )
  {
    case USB_ADDRESSED:
    case USB_CONFIGURED:
      if ( req->wValue == USB_FEATURE_REMOTE_WAKEUP )
      {
        pdev->dev.DevRemoteWakeup = 0;
        USBD_CtlSendStatus( pdev );
      }
      break;

    default:
      USBD_CtlError( pdev, req );
      break;
  }
}

/**
 * @brief  USBD_ParseSetupRequest
 *         Copy buffer into setup structure
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval None
 */

void USBD_ParseSetupRequest( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  req->bmRequest = *(uint8_t *) ( pdev->dev.setup_packet );
  req->bRequest = *(uint8_t *) ( pdev->dev.setup_packet + 1 );
  req->wValue = SWAPBYTE( pdev->dev.setup_packet + 2 );
  req->wIndex = SWAPBYTE( pdev->dev.setup_packet + 4 );
  req->wLength = SWAPBYTE( pdev->dev.setup_packet + 6 );

  pdev->dev.in_ep[ 0 ].ctl_data_len = req->wLength;
  pdev->dev.device_state = USB_EP0_SETUP;
}

/**
 * @brief  USBD_CtlError
 *         Handle USB low level Error
 * @param  pdev: device instance
 * @param  req: usb request
 * @retval None
 */

void USBD_CtlError( USB_CORE_HANDLE *pdev, USB_SETUP_REQ *req )
{
  DCD_EP_Stall( pdev, 0 );
}

/**
 * @brief  USBD_GetString
 *         Convert Ascii string into unicode one
 * @param  desc : descriptor buffer
 * @param  unicode : Formatted string buffer (unicode)
 * @param  len : descriptor length
 * @retval None
 */
void USBD_GetString( uint8_t *desc, uint8_t *unicode, uint16_t *len )
{
  uint8_t idx = 0;

  if ( desc != NULL )
  {
    *len = USBD_GetLen( desc ) * 2 + 2;
    unicode[ idx++ ] = *len;
    unicode[ idx++ ] = USB_DESC_TYPE_STRING;

    while ( *desc != NULL )
    {
      unicode[ idx++ ] = *desc++;
      unicode[ idx++ ] = 0x00;
    }
  }
}

/**
 * @brief  USBD_GetLen
 *         return the string length
 * @param  buf : pointer to the ascii string buffer
 * @retval string length
 */
static uint8_t USBD_GetLen( uint8_t *buf )
{
  uint8_t len = 0;

  while ( *buf != NULL )
  {
    len++;
    buf++;
  }

  return len;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
