/**
  ******************************************************************************
  * @file    usbd_class_core.c
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    31-January-2014
  * @brief   This file provides the high layer firmware functions to manage the
  *          following functionalities of the USB CDC Class:
  *           - Initialization and Configuration of high and low layer
  *           - Enumeration as CDC Device (and enumeration for each implemented memory interface)
  *           - OUT/IN data transfer
  *           - Command IN transfer (class requests management)
  *           - Error management
  *
  *  @verbatim
  *
  *          ===================================================================
  *                                CDC Class Driver Description
  *          ===================================================================
  *           This driver manages the "Universal Serial Bus Class Definitions for Communications Devices
  *           Revision 1.2 November 16, 2007" and the sub-protocol specification of "Universal Serial Bus
  *           Communications Class Subclass Specification for PSTN Devices Revision 1.2 February 9, 2007"
  *           This driver implements the following aspects of the specification:
  *             - Device descriptor management
  *             - Configuration descriptor management
  *             - Enumeration as CDC device with 2 data endpoints (IN and OUT) and 1 command endpoint (IN)
  *             - Requests management (as described in section 6.2 in specification)
  *             - Abstract Control Model compliant
  *             - Union Functional collection (using 1 IN endpoint for control)
  *             - Data interface class

  *           @note
  *             For the Abstract Control Model, this core allows only transmitting the requests to
  *             lower layer dispatcher (ie. usbd_class_vcp.c/.h) which should manage each request and
  *             perform relative actions.
  *
  *           These aspects may be enriched or modified for a specific user application.
  *
  *            This driver doesn't implement the following aspects of the specification
  *            (but it is possible to manage these features with some modifications on this driver):
  *             - Any class-specific aspect relative to communication classes should be managed by user application.
  *             - All communication classes other than PSTN are not managed
  *
  *  @endverbatim
  *
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
#include "usbd_class.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/*********************************************
   CDC Device library callbacks
 *********************************************/
uint8_t  usbd_class_Init        (void  *pdev, uint8_t cfgidx);
uint8_t  usbd_class_DeInit      (void  *pdev, uint8_t cfgidx);
uint8_t  usbd_class_Setup       (void  *pdev, USB_SETUP_REQ *req);
uint8_t  usbd_class_EP0_RxReady  (void *pdev);
uint8_t  usbd_class_DataIn      (void *pdev, uint8_t epnum);
uint8_t  usbd_class_DataOut     (void *pdev, uint8_t epnum);
uint8_t  usbd_class_SOF         (void *pdev);

/*********************************************
   CDC specific management functions
 *********************************************/
static void Handle_USBAsynchXfer  (void *pdev);
static uint8_t  *usbd_class_GetCfgDesc (uint8_t speed, uint16_t *length);

extern CDC_IF_Prop_TypeDef  APP_FOPS;

static __IO uint32_t  usbd_class_AltSet  = 0;

uint8_t USB_Rx_Buffer   [CDC_DATA_MAX_PACKET_SIZE] ;

uint8_t APP_Rx_Buffer   [APP_RX_DATA_SIZE] ;

uint8_t CmdBuff[CDC_CMD_PACKET_SZE] ;
__IO uint32_t last_packet = 0;
uint32_t APP_Rx_ptr_in  = 0;
uint32_t APP_Rx_ptr_out = 0;
uint32_t APP_Rx_length  = 0;

uint8_t  USB_Tx_State = 0;

static uint32_t cdcCmd = 0xFF;
static uint32_t cdcLen = 0;

/* CDC interface class callbacks structure */
USBD_Class_cb_TypeDef  USBD_Class_cb =
{
  usbd_class_Init,
  usbd_class_DeInit,
  usbd_class_Setup,
  NULL,                 /* EP0_TxSent, */
  usbd_class_EP0_RxReady,
  usbd_class_DataIn,
  usbd_class_DataOut,
  usbd_class_SOF,
  usbd_class_GetCfgDesc,
};

/* USB CDC device Configuration Descriptor */
/* Private function ----------------------------------------------------------*/
/**
  * @brief  usbd_class_Init
  *         Initialize the CDC interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
uint8_t  usbd_class_Init (void  *pdev,
                               uint8_t cfgidx)
{
  DCD_PMA_Config(pdev , CDC_IN_EP,USB_SNG_BUF,BULK_IN_TX_ADDRESS);
  DCD_PMA_Config(pdev , CDC_CMD_EP,USB_SNG_BUF,INT_IN_TX_ADDRESS);
  DCD_PMA_Config(pdev , CDC_OUT_EP,USB_SNG_BUF,BULK_OUT_RX_ADDRESS);

  /* Open EP IN */
  DCD_EP_Open(pdev,
              CDC_IN_EP,
              CDC_DATA_IN_PACKET_SIZE,
              USB_EP_TYPE_BULK);

  /* Open EP OUT */
  DCD_EP_Open(pdev,
              CDC_OUT_EP,
              CDC_DATA_OUT_PACKET_SIZE,
              USB_EP_TYPE_BULK);

  /* Open Command IN EP */
  DCD_EP_Open(pdev,
              CDC_CMD_EP,
              CDC_CMD_PACKET_SZE,
              USB_EP_TYPE_INT);



  /* Initialize the Interface physical components */
  APP_FOPS.pIf_Init();

  /* Prepare Out endpoint to receive next packet */
  DCD_EP_PrepareRx(pdev,
                   CDC_OUT_EP,
                   (uint8_t*)(USB_Rx_Buffer),
                   CDC_DATA_OUT_PACKET_SIZE);

  return USBD_OK;
}

/**
  * @brief  usbd_class_Init
  *         DeInitialize the CDC layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
uint8_t  usbd_class_DeInit (void  *pdev,
                                 uint8_t cfgidx)
{
  /* Open EP IN */
  DCD_EP_Close(pdev,
              CDC_IN_EP);

  /* Open EP OUT */
  DCD_EP_Close(pdev,
              CDC_OUT_EP);

  /* Open Command IN EP */
  DCD_EP_Close(pdev,
              CDC_CMD_EP);

  /* Restore default state of the Interface physical components */
  APP_FOPS.pIf_DeInit();

  return USBD_OK;
}

/**
  * @brief  usbd_class_Setup
  *         Handle the CDC specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
uint8_t  usbd_class_Setup (void  *pdev,
                                USB_SETUP_REQ *req)
{
  uint16_t len=USB_CDC_DESC_SIZ;
  uint8_t  *pbuf= (uint8_t*)usbd_class_CfgDesc + 9;

  switch (req->bmRequest & USB_REQ_TYPE_MASK)
  {
    /* CDC Class Requests -------------------------------*/
  case USB_REQ_TYPE_CLASS :
      /* Check if the request is a data setup packet */
      if (req->wLength)
      {
        /* Check if the request is Device-to-Host */
        if (req->bmRequest & 0x80)
        {
          /* Get the data to be sent to Host from interface layer */
          APP_FOPS.pIf_Ctrl(req->bRequest, CmdBuff, req->wLength);

          /* Send the data to the host */
          USBD_CtlSendData (pdev,
                            CmdBuff,
                            req->wLength);
        }
        else /* Host-to-Device requeset */
        {
          /* Set the value of the current command to be processed */
          cdcCmd = req->bRequest;
          cdcLen = req->wLength;

          /* Prepare the reception of the buffer over EP0
          Next step: the received data will be managed in usbd_class_EP0_TxSent()
          function. */
          USBD_CtlPrepareRx (pdev,
                             CmdBuff,
                             req->wLength);
        }
      }
      else /* No Data request */
      {
        /* Transfer the command to the interface layer */
        APP_FOPS.pIf_Ctrl(req->bRequest, NULL, 0);
      }

      return USBD_OK;

    default:
      USBD_CtlError (pdev, req);
      return USBD_FAIL;



    /* Standard Requests -------------------------------*/
  case USB_REQ_TYPE_STANDARD:
    switch (req->bRequest)
    {
    case USB_REQ_GET_DESCRIPTOR:
      if( (req->wValue >> 8) == CDC_DESCRIPTOR_TYPE)
      {
        pbuf = (uint8_t*)usbd_class_CfgDesc + 9 + (9 * USBD_ITF_MAX_NUM);
        len = MIN(USB_CDC_DESC_SIZ , req->wLength);
      }

      USBD_CtlSendData (pdev,
                        pbuf,
                        len);
      break;

    case USB_REQ_GET_INTERFACE :
      USBD_CtlSendData (pdev,
                        (uint8_t *)&usbd_class_AltSet,
                        1);
      break;

    case USB_REQ_SET_INTERFACE :
      if ((uint8_t)(req->wValue) < USBD_ITF_MAX_NUM)
      {
        usbd_class_AltSet = (uint8_t)(req->wValue);
      }
      else
      {
        /* Call the error management function (command will be nacked */
        USBD_CtlError (pdev, req);
      }
      break;
    }
  }
  return USBD_OK;
}

/**
  * @brief  usbd_class_EP0_RxReady
  *         Data received on control endpoint
  * @param  pdev: device device instance
  * @retval status
  */
uint8_t  usbd_class_EP0_RxReady (void  *pdev)
{
  if (cdcCmd != NO_CMD)
  {
    /* Process the data */
    APP_FOPS.pIf_Ctrl(cdcCmd, CmdBuff, cdcLen);

    /* Reset the command variable to default value */
    cdcCmd = NO_CMD;
  }

  return USBD_OK;
}

/**
  * @brief  usbd_audio_DataIn
  *         Data sent on non-control IN endpoint
  * @param  pdev: device instance
  * @param  epnum: endpoint number
  * @retval status
  */
uint8_t  usbd_class_DataIn (void *pdev, uint8_t epnum)
{
  uint16_t USB_Tx_ptr;
  uint16_t USB_Tx_length;

  if (USB_Tx_State == 1)
  {
    if (APP_Rx_length == 0)
    {
      if (last_packet ==1)
      {
        last_packet =0;

        /*Send zero-length packet*/
        DCD_EP_Tx (pdev, CDC_IN_EP, 0, 0);
      }
      else
      {
        USB_Tx_State = 0;
      }
    }
    else
    {
      if (APP_Rx_length > CDC_DATA_IN_PACKET_SIZE){
        USB_Tx_ptr = APP_Rx_ptr_out;
        USB_Tx_length = CDC_DATA_IN_PACKET_SIZE;

        APP_Rx_ptr_out += CDC_DATA_IN_PACKET_SIZE;
        APP_Rx_length -= CDC_DATA_IN_PACKET_SIZE;
      }
      else
      {
        USB_Tx_ptr = APP_Rx_ptr_out;
        USB_Tx_length = APP_Rx_length;

        APP_Rx_ptr_out += APP_Rx_length;
        APP_Rx_length = 0;
        if (APP_Rx_length == CDC_DATA_IN_PACKET_SIZE) last_packet = 1;
      }

      /* Prepare the available data buffer to be sent on IN endpoint */
      DCD_EP_Tx (pdev,
                 CDC_IN_EP,
                 (uint8_t*)&APP_Rx_Buffer[USB_Tx_ptr],
                 USB_Tx_length);
    }
  }

  return USBD_OK;
}

/**
  * @brief  usbd_class_DataOut
  *         Data received on non-control Out endpoint
  * @param  pdev: device instance
  * @param  epnum: endpoint number
  * @retval status
  */
uint8_t  usbd_class_DataOut (void *pdev, uint8_t epnum)
{
  uint16_t USB_Rx_Cnt;

  /* Get the received data buffer and update the counter */
  USB_Rx_Cnt = ((USB_CORE_HANDLE*)pdev)->dev.out_ep[epnum].xfer_count;

  /* USB data will be immediately processed, this allow next USB traffic being
     NAKed till the end of the application Xfer */
  APP_FOPS.pIf_DataRx(USB_Rx_Buffer, USB_Rx_Cnt);

  /* Prepare Out endpoint to receive next packet */
  DCD_EP_PrepareRx(pdev,
                   CDC_OUT_EP,
                   (uint8_t*)(USB_Rx_Buffer),
                   CDC_DATA_OUT_PACKET_SIZE);

  return USBD_OK;
}

/**
  * @brief  usbd_class_SOF
  *         Start Of Frame event management
  * @param  pdev: instance
  * @param  epnum: endpoint number
  * @retval status
  */
uint8_t  usbd_class_SOF (void *pdev)
{
  static uint32_t FrameCount = 0;

  if (FrameCount++ == CDC_IN_FRAME_INTERVAL)
  {
    /* Reset the frame counter */
    FrameCount = 0;

    /* Check the data to be sent through IN pipe */
    Handle_USBAsynchXfer(pdev);
  }

  return USBD_OK;
}

/**
  * @brief  Handle_USBAsynchXfer
  *         Send data to USB
  * @param  pdev: instance
  * @retval None
  */
static void Handle_USBAsynchXfer (void *pdev)
{
  uint16_t USB_Tx_ptr;
  uint16_t USB_Tx_length;

  if(USB_Tx_State != 1)
  {
    if (APP_Rx_ptr_out == APP_RX_DATA_SIZE)
    {
      APP_Rx_ptr_out = 0;
    }

    if(APP_Rx_ptr_out == APP_Rx_ptr_in)
    {
      USB_Tx_State = 0;
      return;
    }

    if(APP_Rx_ptr_out > APP_Rx_ptr_in) /* rollback */
    {
      APP_Rx_length = APP_RX_DATA_SIZE - APP_Rx_ptr_out;

    }
    else
    {
      APP_Rx_length = APP_Rx_ptr_in - APP_Rx_ptr_out;

    }

    if (APP_Rx_length > CDC_DATA_IN_PACKET_SIZE)
    {
      USB_Tx_ptr = APP_Rx_ptr_out;
      USB_Tx_length = CDC_DATA_IN_PACKET_SIZE;

      APP_Rx_ptr_out += CDC_DATA_IN_PACKET_SIZE;
      APP_Rx_length -= CDC_DATA_IN_PACKET_SIZE;
    }
    else
    {
      USB_Tx_ptr = APP_Rx_ptr_out;
      USB_Tx_length = APP_Rx_length;

      APP_Rx_ptr_out += APP_Rx_length;
      APP_Rx_length = 0;
      if (USB_Tx_length == CDC_DATA_IN_PACKET_SIZE) last_packet = 1; //IBA
      if (APP_Rx_ptr_in == 64) APP_Rx_ptr_in=0;
    }
    USB_Tx_State = 1;

    DCD_EP_Tx (pdev,
               CDC_IN_EP,
               (uint8_t*)&APP_Rx_Buffer[USB_Tx_ptr],
               USB_Tx_length);
  }

}

/**
  * @brief  usbd_class_GetCfgDesc
  *         Return configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t  *usbd_class_GetCfgDesc (uint8_t speed, uint16_t *length)
{
  *length = sizeof (usbd_class_CfgDesc);
  return (uint8_t*)usbd_class_CfgDesc;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
