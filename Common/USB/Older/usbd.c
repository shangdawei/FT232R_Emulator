#include "os.h"
#include "usbd.h"

#define USBD_DRIVER_TIMEOUT               (100)
#define USBD_SUPPORT_USE_MULTI_THREAD     ( 0 )

//------------------------------------------------------------------------------
// Helper API
//
static uint32_t USBD_EndpointMask( uint8_t EndpAddr )
{
  uint8_t EndpNum = EndpAddr & 0x0F;
  if ( EndpAddr & 0x80 )
    return ( 0x00010000 << ( EndpNum ) );
  else
    return ( 0x00000001 << ( EndpNum ) );
}

#if ( USBD_SUPPORT_USE_MULTI_THREAD > 0 )

int32_t USBD_SemaphoreWait( HAL_USBD_TypeDef * USBD )
{
  return osSemaphoreWait( USBD->SemaphoreId, USBD_DRIVER_TIMEOUT );
}

void USBD_SemaphoreRelease( HAL_USBD_TypeDef * USBD )
{
  osSemaphoreRelease( USBD->SemaphoreId );
}

#else

#define USBD_SemaphoreWait( ... )         ( 1 )
#define USBD_SemaphoreRelease( ... )      do { } while (0)

#endif

//------------------------------------------------------------------------------
// EndpointAddr[8] : EndpointEvent[8] : DeviceEvent[8]
void USBD_EndpointEventHandler( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr,
  uint32_t Event )
{
  USBD->TransferActived &= USBD_EndpointMask( EndpAddr );
  osSignalSet( USBD->ThreadId,
    ( EndpAddr << 16 ) | ( Event << 8 ) | ( 0 << 0 ) );
}

//------------------------------------------------------------------------------
// EndpointAddr[8] : EndpointEvent[8] : DeviceEvent[8]
void USBD_DeviceEventHandler( HAL_USBD_TypeDef * USBD, uint32_t Event )
{
  osSignalSet( USBD->ThreadId, ( 0 << 16 ) | ( 0 << 8 ) | Event );
}

void USBD_Class_Initialize( HAL_USBD_TypeDef * USBD )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->Initialize )
      USBD->ClassArray[ i ]->Handler->Initialize( USBD->ClassArray[ i ] );
  }
}

void USBD_Class_Uninitialize( HAL_USBD_TypeDef * USBD )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->Uninitialize )
      USBD->ClassArray[ i ]->Handler->Uninitialize( USBD->ClassArray[ i ] );
  }
}

void USBD_Class_Reset( HAL_USBD_TypeDef * USBD )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->Reset )
      USBD->ClassArray[ i ]->Handler->Reset( USBD->ClassArray[ i ] );
  }
}

void USBD_Class_EndpointStarted( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->EndpointStarted )
      if ( USBD->ClassArray[ i ]->Handler->EndpointStarted(
        USBD->ClassArray[ i ], EndpAddr ) == USB_OK )
        break;
  }
}

void USBD_Class_EndpointStopped( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->EndpointStopped )
      if ( USBD->ClassArray[ i ]->Handler->EndpointStopped(
        USBD->ClassArray[ i ], EndpAddr ) == USB_OK )
        break;
  }
}

void USBD_Class_EndpointDataSent( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->EndpointDataSent )
      if ( USBD->ClassArray[ i ]->Handler->EndpointDataSent(
        USBD->ClassArray[ i ], EndpAddr ) == USB_OK )
        break;
  }
}

void USBD_Class_EndpointDataReceived( HAL_USBD_TypeDef * USBD,
  uint8_t EndpAddr )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->EndpointDataReceived )
      if ( USBD->ClassArray[ i ]->Handler->EndpointDataReceived(
        USBD->ClassArray[ i ], EndpAddr ) == USB_OK )
        break;
  }
}

//
// Option --------------------------------------------------------------------
int32_t USBD_Class_SetupPacketReceived( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_UNSUPPORTED;
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->SetupPacketReceived )
    {
      RetValue = USBD->ClassArray[ i ]->Handler->SetupPacketReceived(
        USBD->ClassArray[ i ], USBD->SetupPacket, &USBD->EP0_Data,
        &USBD->EP0_Size );

      if ( RetValue != USB_ERROR_UNSUPPORTED )  // USB_OK or USB_ERROR
        break;
    }
  }

  return RetValue;
}

int32_t USBD_Class_SetupDataReceived( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_UNSUPPORTED;
  uint32_t Size = USBD_EndpointTransferGetResult( USBD, 0x00 );
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->SetupDataReceived )
    {
      RetValue = USBD->ClassArray[ i ]->Handler->SetupDataReceived(
        USBD->ClassArray[ i ], USBD->SetupPacket, Size );

      if ( RetValue != USB_ERROR_UNSUPPORTED )  // USB_OK or USB_ERROR
        break;
    }
  }

  if ( RetValue == USB_ERROR_UNSUPPORTED )
    RetValue = USB_OK;

  return RetValue;
}

int32_t USBD_Class_SetupDataSent( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_UNSUPPORTED;
  uint32_t Size = USBD_EndpointTransferGetResult( USBD, 0x80 );

  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->SetupDataSent )
    {
      RetValue = USBD->ClassArray[ i ]->Handler->SetupDataSent(
        USBD->ClassArray[ i ], USBD->SetupPacket, Size );

      if ( RetValue != USB_ERROR_UNSUPPORTED )  // USB_OK or USB_ERROR
        break;
    }
  }

  if ( RetValue == USB_ERROR_UNSUPPORTED )
    RetValue = USB_OK;

  return RetValue;
}

//
// MSC Only --------------------------------------------------------------------
//
int32_t USBD_Class_CanClearEndpointHalt( HAL_USBD_TypeDef * USBD,
  uint8_t EndpAddr )
{
  int32_t RetValue = USB_OK;
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->CanClearEndpointHalt )
    {
      RetValue = USBD->ClassArray[ i ]->Handler->CanClearEndpointHalt(
        USBD->ClassArray[ i ], EndpAddr );
      if ( RetValue != USB_ERROR_UNSUPPORTED )  // USB_OK or USB_ERROR
        break;
    }
  }

  if ( RetValue == USB_ERROR_UNSUPPORTED )
    RetValue = USB_OK;

  return RetValue;
}

//
// MSC Only --------------------------------------------------------------------
//
void USBD_Class_EndpointHaltClear( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr )
{
  for ( uint32_t i = 0; i < USBD->ClassNum; i++ )
  {
    if ( USBD->ClassArray[ i ]->Handler->EndpointHaltClear )
      USBD->ClassArray[ i ]->Handler->EndpointHaltClear( USBD->ClassArray[ i ],
        EndpAddr );
  }
}

//------------------------------------------------------------------------------
// Driver API
//
// Initialize USB USBD Interface.
int32_t USBD_InitializeDriver( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->Initialize( USBD->Instance, USBD->DeviceEventHandler,
      USBD->EndpointEventHandler ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// De-initialize USB USBD Interface.
int32_t USBD_UninitializeDriver( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->Uninitialize( USBD->Instance ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Control USB USBD Interface Power.
int32_t USBD_PowerControl( HAL_USBD_TypeDef * USBD, uint32_t State )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->PowerControl( USBD->Instance, State ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Connect USB USBD
int32_t USBD_Connect( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->Connect( USBD->Instance ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Disconnect USB USBD.
int32_t USBD_Disconnect( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->Disconnect( USBD->Instance ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Set USB USBD Address.
int32_t USBD_SetAddress( HAL_USBD_TypeDef * USBD, uint8_t Address )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->SetAddress( USBD->Instance, Address ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Read setup packet received over Control Endpoint.
int32_t USBD_ReadSetupPacket( HAL_USBD_TypeDef * USBD, uint8_t * SetupPacket )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    // Copy 8 bytes from setup_buf to setup
    if ( USBD->Driver->ReadSetupPacket( USBD->Instance, SetupPacket ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Abort current USB Endpoint transfer
int32_t USBD_EndpointAbort( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr )
{
  int32_t RetValue;
  uint32_t EndpMask = USBD_EndpointMask( EndpAddr );
  RetValue = ( ( USBD->TransferActived & EndpMask ) == 0 );
  if ( RetValue != USB_OK ) // Endpoint transfer Active
  {
    RetValue = USB_ERROR_BUSY;
    if ( USBD_SemaphoreWait( USBD ) )
    {
      if ( USBD->Driver->EndpointTransferAbort( USBD->Instance, EndpAddr ) )
        RetValue = USB_ERROR_DRIVER;
      else
      {
        USBD->TransferActived &= ~EndpMask;
        RetValue = USB_OK;
      }
      USBD_SemaphoreRelease( USBD );
    }
  }
  return RetValue;
}

// Read data from or Write data to USB Endpoint.
// Buffer : Pointer to buffer for data to read or with data to write
// Length : Number of data bytes to transfer
int32_t USBD_EndpointTransfer( HAL_USBD_TypeDef * USBD, uint8_t EndpAddr,
  uint8_t * Buffer, uint32_t Length )
{
  uint32_t EndpMask = USBD_EndpointMask( EndpAddr );

  if ( 0 )
  {
    if ( ( ( USBD->TransferActived & EndpMask ) > 0 )
      && ( USBD_EndpointAbort( USBD, EndpAddr ) != USB_OK ) )
      return USB_ERROR_DRIVER;
  }
  else
  {
    if ( ( USBD->TransferActived & EndpMask ) > 0 )
      return USB_ERROR_BUSY;
  }

  if ( ( USBD->EndpointHalted & EndpMask ) > 0 )
    return USB_ERROR_HALT;

  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    USBD->TransferActived |= EndpMask;
    RetValue = USBD->Driver->EndpointTransfer( USBD->Instance, EndpAddr, Buffer,
      Length );
    if ( RetValue < USB_OK )
    {
      USBD->TransferActived &= ~EndpMask;
      RetValue = USB_ERROR_DRIVER;
    }

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;

}

// Get Result of USB Endpoint transfer.
// Return Number of successfully transferred data bytes
int32_t USBD_EndpointTransferGetResult( HAL_USBD_TypeDef * USBD,
  uint8_t EndpAddr )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( USBD_SemaphoreWait( USBD ) )
  {
    RetValue = USBD->Driver->EndpointTransferGetResult( USBD->Instance,
      EndpAddr );
    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Configure USB Endpoint.
int32_t USBD_EndpointConfigure( HAL_USBD_TypeDef * USBD, uint8_t Addr,
  uint8_t Type, uint16_t MaxPacketSize )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( ( USBD->TransferActived & USBD_EndpointMask( Addr ) )
    && ( USBD_EndpointAbort( USBD, Addr ) != USB_OK ) )
    RetValue = USB_ERROR_DRIVER;

  else if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->EndpointConfigure( USBD->Instance, Addr, Type,
      MaxPacketSize ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

//Unconfigure USB Endpoint.
int32_t USBD_EndpointUnconfigure( HAL_USBD_TypeDef * USBD, uint8_t Addr )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( ( USBD->TransferActived & USBD_EndpointMask( Addr ) )
    && ( USBD_EndpointAbort( USBD, Addr ) != USB_OK ) )
    RetValue = USB_ERROR_DRIVER;

  else if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->EndpointUnconfigure( USBD->Instance, Addr ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

// Set/Clear Stall for USB Endpoint.
int32_t USBD_EndpointStall( HAL_USBD_TypeDef * USBD, uint8_t Addr,
  uint32_t Stall )
{
  int32_t RetValue = USB_ERROR_BUSY;
  if ( ( USBD->TransferActived & USBD_EndpointMask( Addr ) )
    && ( USBD_EndpointAbort( USBD, Addr ) != USB_OK ) )
    RetValue = USB_ERROR_DRIVER;
  else if ( USBD_SemaphoreWait( USBD ) )
  {
    if ( USBD->Driver->EndpointStall( USBD->Instance, Addr, Stall ) )
      RetValue = USB_ERROR_DRIVER;
    else
      RetValue = USB_OK;

    USBD_SemaphoreRelease( USBD );
  }
  return RetValue;
}

//------------------------------------------------------------------------------
// Endpoint0 Handler
// SETUP : DATA : ACK :: Read Setup Packet
int32_t USBD_SetupStage( HAL_USBD_TypeDef * USBD )
{
  // Copy 8 bytes from setup_buf to setup
  return USBD_ReadSetupPacket( USBD, (uint8_t*) USBD->SetupPacket );
}

// IN : DATA : ACK :: Check whether more data to send
int32_t USBD_DataInStage( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_DRIVER;
  if ( USBD->EP0_Size )
  {
    RetValue = USBD_EndpointTransfer( USBD, 0x80, USBD->EP0_Data,
      USBD->EP0_Size );
    if ( RetValue == USB_OK )
    {
      //USBD->InOutSize -= USBD->EP0_Size;
      USBD->EP0_Data += USBD->EP0_Size;
      USBD->EP0_Size = 0;
    }
  }
  else if ( USBD->SendZLP )
  {
    RetValue = USBD_EndpointTransfer( USBD, 0x80, 0, 0 );
    if ( RetValue == USB_OK )
      USBD->SendZLP = 0;
  }
  return RetValue;
}

// OUT : DATA : ACK :: Read Out Data
int32_t USBD_DataOutStage( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USBD_EndpointTransfer( USBD, 0x00, USBD->EP0_Data,
    USBD->EP0_Size );
  if ( RetValue == USB_OK )
  {
    //USBD->InOutSize -= USBD->EP0_Size;
    USBD->EP0_Data += USBD->EP0_Size;
    USBD->EP0_Size = 0;
  }
  return RetValue;
}

int32_t USBD_StatusInStage( HAL_USBD_TypeDef * USBD )
{
  return USBD_EndpointTransfer( USBD, 0x80, 0, 0 );
}

int32_t USBD_StatusOutStage( HAL_USBD_TypeDef * USBD )
{
  return USBD_EndpointTransfer( USBD, 0x00, 0, 0 );
}

int32_t USBD_StatusInStageDone( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_OK;
  if ( USBD_EndpointTransferGetResult( USBD, 0x80 ) != USB_OK )
    RetValue = USB_ERROR_DRIVER;
  return RetValue;
}

int32_t USBD_StatusOutStageDone( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_OK;
  if ( USBD_EndpointTransferGetResult( USBD, 0x00 ) != USB_OK )
    RetValue = USB_ERROR_DRIVER;
  else if ( USBD->TransferActived & 0x00010000 )     // Endpoint In Pending
    RetValue = USBD_EndpointAbort( USBD, 0x80 );    // Abort it
  return RetValue;
}

//------------------------------------------------------------------------------
// Standard Request Handler
//
/* Get Configuration/Set Configuration is used to request or set the current
 * USBD configuration. In the case of a Get Configuration request,
 * a byte will be returned during the data stage indicating the devices RetValue.
 * A zero value means the USBD is not configured and a non-zero value
 * indicates the USBD is configured.
 *
 * Set Configuration is used to enable a USBD.
 * It should contain the value of bConfigurationValue of the desired
 * configuration descriptor in the lower byte of wValue
 * to select which configuration to enable.
 *
 */
int32_t USBD_ReqGetConfiguration( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;
  if ( USBD->SetupPacket->bmRequestType.Recipient == USB_REQUEST_TO_DEVICE )
  {
    USBD->EP0_Size = 1;
    USBD->EP0_Data = (uint8_t*) &USBD->Configuration;
    RetValue = USBD->EP0_Size;
  }
  return RetValue;
}

/* Get Descriptor is used to return the specified descriptor in wValue.
 *
 * A request for the configuration descriptor will return the configuration
 * descriptor and all interface and endpoint descriptors in the one request.
 *
 * Endpoint Descriptors cannot be accessed directly by a GetDescriptor Request.
 * Interface Descriptors cannot be accessed directly by a GetDescriptor Request.
 *
 * String Descriptors include a Language ID in wIndex to allow
 * for multiple language support.
 *
 */
int32_t USBD_ReqGetDescriptor( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;

  if ( USBD->SetupPacket->bmRequestType.Recipient != USB_REQUEST_TO_DEVICE )
    return RetValue;

  USBD->EP0_Size = 0;

  if ( ( USBD->SetupPacket->wValueH ) == USB_DEVICE_DESCRIPTOR_TYPE )
    USBD->GetDeviceDescriptor( &USBD->EP0_Data, &USBD->EP0_Size );
  else if ( ( USBD->SetupPacket->wValueH ) == USB_CONFIGURATION_DESCRIPTOR_TYPE )
    USBD->GetConfigurationDescriptor( &USBD->EP0_Data, &USBD->EP0_Size );
  else if ( ( USBD->SetupPacket->wValueH )
    == USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE )
    USBD->GetDeviceQualifilerDescriptor( &USBD->EP0_Data, &USBD->EP0_Size );
  else if ( ( USBD->SetupPacket->wValueH )
    == USB_OTHER_SPEED_CONFIG_DESCRIPTOR_TYPE )
    USBD->GetOtherSpeedConfigurationDescriptor( &USBD->EP0_Data,
      &USBD->EP0_Size );
  else if ( ( USBD->SetupPacket->wValueH ) == USB_STRING_DESCRIPTOR_TYPE )
    USBD->GetStringDescriptor( USBD->SetupPacket->wValueL, &USBD->EP0_Data,
      &USBD->EP0_Size );
  else
  {
    // Handled by Class Request Handler
    // USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE
    // USB_INTERFACE_DRIVER_POWER_DESCRIPTOR_TYPE
    // USB_OTG_DESCRIPTOR_TYPE
    // USB_DEBUG_DESCRIPTOR_TYPE
  }

  if ( USBD->EP0_Size )
    RetValue = USBD->EP0_Size;

  return RetValue;
}

/* Get Interface and Set Interface set the Alternative Interface setting.
 *
 * When this configuration is enabled, the interface descriptors with
 * bAlternativeSettings equal to zero is used.
 * However during operation the host can send a SetInterface request directed
 * to that of Interface one with a alternative setting of one
 * to enable the other interface descriptor.
 */
int32_t USBD_ReqGetInterface( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;

  if ( ( USBD->SetupPacket->bmRequestType.Recipient == USB_REQUEST_TO_INTERFACE )
    && ( USBD->Configuration )
    && ( USBD->SetupPacket->wIndexL < USBD->InterfaceCount ) )
  {
    USBD->EP0_Size = 1;
    USBD->EP0_Data = &USBD->AltSetting[ USBD->SetupPacket->wIndexL ];
    RetValue = USBD->EP0_Size;
  }

  return RetValue;
}

/*
 *
 * The current RetValue of the USBD.
 *
 *    If D0 is set, then this indicates the USBD is self powered.
 *    If clear, the USBD is bus powered.
 *    If D1 is set, the USBD has remote wakeup enabled and
 *    can wake the host up during suspend.
 *
 *    The remote wakeup bit can be by the SetFeature and ClearFeature requests
 *    with a feature selector of DEVICE_REMOTE_WAKEUP (0x01) *
 *    The Self-powered bit is only controlled by the USBD.
 *
 * The RetValue of the interface.
 *
 *    Such a request to the interface should return two bytes of 0x00, 0x00.
 *    (Both bytes are reserved for future use)
 *
 * The RetValue of the endpoint.
 *
 *    bit0 indicating the RetValue (Halted/Stalled) of a endpoint.
 *    The Halt RetValue bits can be controlled by the host
 *    using Set.Clear Feature requests,
 *
 */
int32_t USBD_ReqGetStatus( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;

  USBD->EP0_Size = 0;

  if ( USB_REQUEST_TO_DEVICE == USBD->SetupPacket->bmRequestType.Recipient )
  {
    USBD->EP0_Size = 2;
    USBD->EP0_Data = (uint8_t*) &USBD->Status;
    return USB_OK;
  }
  else if ( USB_REQUEST_TO_INTERFACE
    == USBD->SetupPacket->bmRequestType.Recipient )
  {
    if ( USBD->Configuration == 0 )
      return RetValue;
    if ( USBD->SetupPacket->wIndexL >= USBD->InterfaceCount )
      return RetValue;

    USBD->Buffer[ 0 ] = 0;
    USBD->Buffer[ 1 ] = 0;
    USBD->EP0_Size = 2;
    USBD->EP0_Data = USBD->Buffer;
  }
  else if ( USB_REQUEST_TO_ENDPOINT
    == USBD->SetupPacket->bmRequestType.Recipient )
  {
    uint8_t EndpAddr;
    uint32_t EndpMask;

    EndpAddr = USBD->SetupPacket->wIndexL & 0x8F;
    EndpMask = USBD_EndpointMask( EndpAddr );

    if ( ( EndpAddr & 0x0F ) == 0 )
      return RetValue;

    if ( USBD->Configuration == 0 )
      return RetValue;

    if ( USBD->EndpointActived & EndpMask == 0 )
      return RetValue;

    USBD->Buffer[ 0 ] = ( USBD->EndpointHalted & EndpMask ) ? 1 : 0;
    USBD->Buffer[ 1 ] = 0;
    USBD->EP0_Size = 2;
    USBD->EP0_Data = USBD->Buffer;
  }

  if ( USBD->EP0_Size )
    RetValue = USBD->EP0_Size;

  return RetValue;
}

/* Set Address is used during enumeration to assign a unique address to
 * the USB USBD. The address is specified in wValue and can only be
 * a maximum of 127. This request is unique in that the USBD does not
 * set its address until after the completion of the RetValue stage.
 * (See Control Transfers.)
 *
 * All other requests must complete before the RetValue stage.
 *
 */
int32_t USBD_ReqSetAddress( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;
  if ( USB_REQUEST_TO_DEVICE == USBD->SetupPacket->bmRequestType.Recipient )
  {
    USBD->Address = 0x80 | USBD->SetupPacket->wValueL;
    RetValue = USB_OK;
  }
  return RetValue;
}

/* Clear Feature and Set Feature requests can be used to set boolean features.
 *
 * When the designated recipient is the USBD, the only two feature selectors
 * available are DEVICE_REMOTE_WAKEUP and TEST_MODE.
 *
 * Test mode allows the USBD to exhibit various conditions.
 * These are further documented in the USB Specification Revision 2.0.
 *
 * When the designated recipient is the interface, the current USB Specification
 * Revision 2 specifies no interface features.
 *
 * When the designated recipient is the endpoint, the standard currently defines
 * one endpoint feature selector, ENDPOINT_HALT (0x00)
 * which allows the host to Stall and clear an endpoint.
 *
 * Only endpoints other than the default endpoint are recommended
 * to have this functionality.
 *
 */
int32_t USBD_ReqSetClrFeature( HAL_USBD_TypeDef * USBD, uint32_t SetFeature )
{
  int32_t RetValue = USB_ERROR_PARAMETER;

  if ( USB_REQUEST_TO_DEVICE == USBD->SetupPacket->bmRequestType.Recipient )
  {
    if ( 1 == USBD->SetupPacket->wValue )
    {
      if ( SetFeature )
        USBD->Status |= 0x0002;
      else
        USBD->Status &= 0xFFFD;

      RetValue = USB_OK;
    }
  }
  else if ( USB_REQUEST_TO_ENDPOINT
    == USBD->SetupPacket->bmRequestType.Recipient )
  {
    uint32_t EndpAddr = USBD->SetupPacket->wIndexL & 0x8F;
    uint32_t EndpMask = USBD_EndpointMask( EndpAddr );
    uint32_t EndpHalt = USBD->EndpointHalted & EndpMask;

    if ( ( EndpAddr & 0x0F ) && ( USBD->Configuration )
      && ( USBD->EndpointActived & EndpMask )
      && ( ( USBD->SetupPacket->wValue ) == 0 ) )
    {
      if ( SetFeature == 0 )  // Clear Halt
      {
        RetValue = USBD_Class_CanClearEndpointHalt( USBD, EndpAddr );
        if ( USB_OK != RetValue )
          return RetValue;

        RetValue = USBD_EndpointStall( USBD, EndpAddr, 0 );
        if ( USB_OK == RetValue )
        {
          USBD->EndpointHalted &= ~EndpMask;
          USBD_Class_EndpointHaltClear( USBD, EndpAddr );
          USBD_Class_EndpointStarted( USBD, EndpAddr );
        }
      }
      else                    // Set Halt
      {
        if ( ( EndpHalt == 0 ) && ( USBD->TransferActived & EndpMask ) )
        {
          RetValue = USBD_EndpointAbort( USBD, EndpAddr );
          if ( USB_OK == RetValue )
          {
            RetValue = USBD_EndpointStall( USBD, EndpAddr, 1 );
            if ( USB_OK == RetValue )
            {
              USBD->EndpointHalted |= EndpMask;
              USBD_Class_EndpointStopped( USBD, EndpAddr );
            }
          }
        }
      }
    }
  }

  return RetValue;
}

void USBD_ConfigureEndpoints( HAL_USBD_TypeDef * USBD,
  uint32_t bInterfaceNumber, uint32_t bAlternateSetting,
  const USB_CONFIGURATION_DESCRIPTOR * pConfigurationDescriptor )
{
  USB_ENDPOINT_DESCRIPTOR * pEndpoiontDescriptor;
  USB_ENDPOINT_DESCRIPTOR * pEndpoiontDescriptorArray[ 32 ];

  USB_GetEndpointDescriptorList( pConfigurationDescriptor, bInterfaceNumber,
    bAlternateSetting, pEndpoiontDescriptorArray );

  uint32_t EndpMask;
  for ( uint32_t i = 0;; i++ )
  {
    pEndpoiontDescriptor = pEndpoiontDescriptorArray[ i ];
    if ( pEndpoiontDescriptor == 0 )
      break;

    EndpMask = USBD_EndpointMask( pEndpoiontDescriptor->bEndpointAddress );
    USBD->EndpointActived |= EndpMask;
    USBD->EndpointHalted &= ~EndpMask;

    if ( USBD->TransferActived & EndpMask )
      USBD_EndpointAbort( USBD, pEndpoiontDescriptor->bEndpointAddress & 0x8F );

    USBD_EndpointConfigure( USBD, pEndpoiontDescriptor->bEndpointAddress,
      pEndpoiontDescriptor->bmAttributes & 3,
      pEndpoiontDescriptor->wMaxPacketSize );

    // Endpoint Started
    USBD_Class_EndpointStarted( USBD, pEndpoiontDescriptor->bEndpointAddress );
  }
}

int32_t USBD_UnconfigureEndpointsByDir( HAL_USBD_TypeDef * USBD,
  uint32_t InEndpoint )
{
  int32_t RetValue = USB_ERROR_DRIVER;
  uint32_t EndpMask = ( InEndpoint ) ? 0x00010000 : 0x00000001;
  uint32_t EndpDir = ( InEndpoint ) ? 0x00000000 : 0x00000080;

  for ( uint32_t i = 1; i < 16; i++ )
  {
    if ( USBD->EndpointActived & ( 1 << EndpMask ) )
    {
      if ( USBD->TransferActived & ( 1 << EndpMask ) )
      {
        RetValue = USBD_EndpointAbort( USBD, i | EndpDir );
        if ( USB_OK != RetValue )
          break;
      }

      RetValue = USBD_EndpointUnconfigure( USBD, i | EndpDir );
      if ( USB_OK != RetValue )
        break;

      // Endpoint Stopped
      USBD_Class_EndpointStarted( USBD, ( i | EndpDir ) );
    }
  }

  return RetValue;
}

void USBD_UnconfigureEndpoints( HAL_USBD_TypeDef * USBD )
{
  USBD_UnconfigureEndpointsByDir( USBD, 0 );
  USBD_UnconfigureEndpointsByDir( USBD, 1 );

  USBD->TransferActived = 0x00000000;
  USBD->EndpointHalted = 0x00000000;
  USBD->EndpointActived = 0x00000000;
}

/* Get Configuration/Set Configuration is used to request or set the current
 * USBD configuration. In the case of a Get Configuration request,
 * a byte will be returned during the data stage indicating the devices RetValue.
 * A zero value means the USBD is not configured and a non-zero value
 * indicates the USBD is configured.
 *
 * Set Configuration is used to enable a USBD.
 * It should contain the value of bConfigurationValue of the desired
 * configuration descriptor in the lower byte of wValue
 * to select which configuration to enable.
 *
 */
int32_t USBD_ReqSetConfiguration( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;
  uint16_t Size;
  const USB_CONFIGURATION_DESCRIPTOR * pConfigurationDescriptor;
  if ( USB_REQUEST_TO_DEVICE == USBD->SetupPacket->bmRequestType.Recipient )
  {
    USBD->GetConfigurationDescriptor( (uint8_t **) &pConfigurationDescriptor,
      &Size );

    USBD_UnconfigureEndpoints( USBD );

    USBD->EndpointActived = 0x00010001;

    if ( USBD->SetupPacket->wValueL )
      USBD_ConfigureEndpoints( USBD, 0xFF, 0, pConfigurationDescriptor );

    USBD->EndpointHalted = 0;
    USBD->Configuration = USBD->SetupPacket->wValueL;
    USBD->InterfaceCount = pConfigurationDescriptor->bNumInterfaces;
    for ( uint32_t i = 0; i < USBD->InterfaceCount; i++ )
      USBD->AltSetting[ i ] = 0;

    RetValue = USB_OK;
  }

  return RetValue;
}

/* Get Interface and Set Interface set the Alternative Interface setting.
 *
 * When this configuration is enabled, the interface descriptors with
 * bAlternativeSettings equal to zero is used.
 * However during operation the host can send a SetInterface request directed
 * to that of Interface one with a alternative setting of one
 * to enable the other interface descriptor.
 */
int32_t USBD_ReqSetInterface( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;
  uint16_t Size;
  const USB_CONFIGURATION_DESCRIPTOR * pConfigurationDescriptor;
  if ( ( USB_REQUEST_TO_INTERFACE == USBD->SetupPacket->bmRequestType.Recipient )
    && ( USBD->Configuration ) )
  {
    USBD->GetConfigurationDescriptor( (uint8_t **) &pConfigurationDescriptor,
      &Size );

    uint32_t bInterfaceNumber = USBD->SetupPacket->wIndexL;
    uint32_t bAlternateSetting = USBD->SetupPacket->wValueL;
    USBD_ConfigureEndpoints( USBD, bInterfaceNumber, bAlternateSetting,
      pConfigurationDescriptor );

    RetValue = USB_OK;
  }
  return RetValue;
}

int32_t USBD_StandardRequestHandler( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue = USB_ERROR_PARAMETER;

  if ( USBD->SetupPacket->bmRequestType.Type == USB_REQUEST_STANDARD )
  {
    switch ( USBD->SetupPacket->bRequest )
    {
      case USB_REQUEST_GET_STATUS:
        RetValue = USBD_ReqGetStatus( USBD );
        break;

      case USB_REQUEST_CLEAR_FEATURE:
        RetValue = USBD_ReqSetClrFeature( USBD, 0 );
        break;

      case 2:
        break;

      case USB_REQUEST_SET_FEATURE:
        RetValue = USBD_ReqSetClrFeature( USBD, 1 );
        break;

      case 4:
        break;

      case USB_REQUEST_SET_ADDRESS:
        RetValue = USBD_ReqSetAddress( USBD );
        break;

      case USB_REQUEST_GET_DESCRIPTOR:
        RetValue = USBD_ReqGetDescriptor( USBD );
        break;

      case USB_REQUEST_SET_DESCRIPTOR:
        break;

      case USB_REQUEST_GET_CONFIGURATION:
        RetValue = USBD_ReqGetConfiguration( USBD );
        break;

      case USB_REQUEST_SET_CONFIGURATION:
        RetValue = USBD_ReqSetConfiguration( USBD );
        break;

      case USB_REQUEST_GET_INTERFACE:
        RetValue = USBD_ReqGetInterface( USBD );
        break;

      case USB_REQUEST_SET_INTERFACE:
        RetValue = USBD_ReqSetInterface( USBD );
        break;

      case USB_REQUEST_SYNC_FRAME:
        break;

      default:
        break;
    } // switch ( USBD->SetupPacket->bRequest )
  }

  return RetValue;
}

int32_t USBD_Endpoint0( HAL_USBD_TypeDef * USBD, uint8_t Event )
{
  int32_t RetValue;
  uint32_t ControlIn = USBD->SetupPacket->bmRequestType.Dir;
  uint32_t ControlWithDataStage = USBD->SetupPacket->wLength;

  if ( Event & DRV_USBD_EVENT_SETUP )
  {
    RetValue = USBD_SetupStage( USBD );
    if ( RetValue != USB_OK )
      return RetValue;

    RetValue = USBD_Class_SetupPacketReceived( USBD );

    if ( RetValue == USB_OK )                     // External Request Handler
      USBD->RequestHooked = 1;
    else if ( RetValue == USB_ERROR_UNSUPPORTED ) // Standard Request Handler
      RetValue = USBD_StandardRequestHandler( USBD );
    else
    {
      // USB_ERROR : Stall
    }
  }
  else if ( Event & DRV_USBD_EVENT_OUT )  // OutDataReceived
  {
    if ( ControlIn ) // Status Out for Control In
      return USBD_StatusOutStageDone( USBD );

    if ( USBD->EP0_Size )           // Never be executed
      return USBD_DataOutStage( USBD );

    if ( USBD->RequestHooked == 0 )
      RetValue = USB_ERROR_UNSUPPORTED;     // Stall In and Out
    else
    {
      USBD->RequestHooked = 0;
      RetValue = USBD_Class_SetupDataReceived( USBD );
      if ( RetValue == USB_OK )
        USBD_StatusInStage( USBD );
      else
      {
        // Stall In and Out
      }
    }
  }
  else if ( Event & DRV_USBD_EVENT_IN )       // InDataSent
  {
    if ( ( USBD->EP0_Size ) || ( USBD->SendZLP ) )
      return USBD_DataInStage( USBD );  // Never be executed

    if ( USBD->RequestHooked )
    {
      USBD->RequestHooked = 0;
      RetValue = USBD_Class_SetupDataSent( USBD );
      // RetValue < USB_OK : Stall In or/and Out
    }

    if ( ControlIn == 0 )                 // Status In for Control Out
    {
      USBD_StatusInStageDone( USBD );
      if ( USBD->Address & 0x80 )
      {
        USBD->Address &= 0x7F;
        USBD_SetAddress( USBD, USBD->Address );
      }
      RetValue = USB_OK;
    }
  }

  // Stall In or/and Out
  if ( RetValue < USB_OK )
  {
    USBD->EP0_Size = 0;
    USBD_EndpointStall( USBD, 0x80, 1 );                // Stall In always
    if ( ( ControlIn == 0 ) && ( ControlWithDataStage ) ) // Control Out w/ Data
      USBD_EndpointStall( USBD, 0x00, 1 );              // Stall Out
    return RetValue;
  }

  if ( Event & DRV_USBD_EVENT_SETUP )
  {
    if ( USBD->SetupPacket->wLength == 0 )
      return USBD_StatusInStage( USBD );        // Send ZLP for Status Stage

    if ( USBD->EP0_Size > USBD->SetupPacket->wLength )
      USBD->EP0_Size = USBD->SetupPacket->wLength;

    if ( USBD->SetupPacket->bmRequestType.Dir ) // Control In
    {
      USBD_DataInStage( USBD );                 // Fill FIFO and Wait In
      return USBD_StatusOutStage( USBD );       // Wait ZLP for Status Stage
    }
    else                                          // Control Out
    {
      USBD_DataOutStage( USBD );                // Set to Read FIFO
      return USBD_StatusInStage( USBD );        // Send ZLP for Status Stage
    }
  }

  return RetValue;
}

void USBD_SwitchToHighSpeed( HAL_USBD_TypeDef * USBD )
{
  USBD->InHighSpeed = 1;
}

int32_t USBD_ConfigureEndpoint0( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue;
  uint8_t wMaxPacketSize = USBD->MaxPacketSize0;
  RetValue = USBD_EndpointConfigure( USBD, 0x00, USB_ENDPOINT_TYPE_CONTROL,
    wMaxPacketSize );

  if ( USB_OK == RetValue )
    RetValue = USBD_EndpointConfigure( USBD, 0x80, USB_ENDPOINT_TYPE_CONTROL,
      wMaxPacketSize );

  USBD->EndpointActived = 0x00010001;

  return RetValue;
}

int32_t USBD_ResetCore( HAL_USBD_TypeDef * USBD )
{
  memset( &USBD->Status, 0,
    sizeof(HAL_USBD_TypeDef)
      - (uint32_t) ( &( (HAL_USBD_TypeDef*) 0 )->Status ) );
  USBD->Status = ( USBD->bmAttributes >> 6 ) & 1;
  return USB_OK;
}

//------------------------------------------------------------------------------
// EndpointAddr[8] : EndpointEvent[8] : DeviceEvent[8]
void USBD_Core( HAL_USBD_TypeDef * USBD, uint32_t Event )
{
  uint8_t EndpointAddr = ( Event >> 16 ) & 0xFF;
  uint8_t EndpointEvent = ( Event >> 8 ) & 0xFF;
  uint8_t DeviceEvent = ( Event >> 0 ) & 0xFF;

  if ( DeviceEvent & DRV_USBD_EVENT_RESET )
  {
    USBD_ResetCore( USBD );
    USBD_ConfigureEndpoint0( USBD );
    USBD_Class_Reset( USBD );
  }

  if ( DeviceEvent & DRV_USBD_EVENT_HIGH_SPEED )
    USBD_SwitchToHighSpeed( USBD );

  if ( EndpointEvent )
  {
    if ( ( EndpointAddr & 0x0F ) == 0 )
    {
      // DRV_USBD_EVENT_SETUP
      // DRV_USBD_EVENT_IN
      // DRV_USBD_EVENT_OUT
      USBD_Endpoint0( USBD, EndpointEvent );
    }
    else
    {
      // DRV_USBD_EVENT_IN
      // DRV_USBD_EVENT_OUT
      USBD->TransferActived &= ~USBD_EndpointMask( EndpointAddr );

      if ( EndpointEvent == DRV_USBD_EVENT_IN )
        USBD_Class_EndpointDataSent( USBD, EndpointAddr );
      else
        USBD_Class_EndpointDataReceived( USBD, EndpointAddr );
    }
  }
}

void USBD_CoreThread( HAL_USBD_TypeDef * USBD )
{
  osEvent Event;

  uint32_t EventVbusOffOn = 0;
  uint32_t Timeout = osWaitForever;

  if ( USBD->Capabilities->VBusDetection )
  {
    if ( USBD->Capabilities->EventVbusOn == 0 )
      EventVbusOffOn |= DRV_USBD_EVENT_VBUS_ON;
    if ( USBD->Capabilities->EventVbusOff == 0 )
      EventVbusOffOn |= DRV_USBD_EVENT_VBUS_OFF;
  }

  if ( EventVbusOffOn )
    Timeout = 100;

  if ( EventVbusOffOn & 1 )
    USBD_Core( USBD, DRV_USBD_EVENT_VBUS_ON );

  while ( 1 )
  {
    Event = osSignalWait( 0, Timeout );

    if ( OS_EVENT_STATUS(Event) == osEventSignal )
      USBD_Core( USBD, OS_EVENT_SIGNAL( Event ) );
    else if ( OS_EVENT_STATUS(Event) == osEventTimeout )
    {
      DRV_USBD_State_TypeDef USBD_State = USBD->Driver->GetState(
        USBD->Instance );

      if ( USBD_State.VBus )
      {
        if ( EventVbusOffOn & DRV_USBD_EVENT_VBUS_ON )
          USBD_Core( USBD, DRV_USBD_EVENT_VBUS_ON );
      }
      else if ( EventVbusOffOn & DRV_USBD_EVENT_VBUS_OFF )
        USBD_Core( USBD, DRV_USBD_EVENT_VBUS_OFF );
    }
  }
}

// USBD is in configured state and ready to communicate.
// USBD is not configured and not ready to communicate.
uint32_t USBD_Configured( HAL_USBD_TypeDef * USBD )
{
  return USBD->Configuration;
}

// Initialize USB USBD stack and controller
int32_t USBD_Initialize( HAL_USBD_TypeDef * USBD )
{
  int32_t RetValue;

  if ( ( USBD == 0 ) || ( USBD->Driver == 0 ) )
    return USB_ERROR_PARAMETER;

  USBD->Capabilities = USBD->Driver->GetCapabilities( USBD->Instance );

  USBD_ResetCore( USBD );

  // USBD Driver Semaphore
#if ( USBD_SUPPORT_USE_MULTI_THREAD > 0 )
  if ( USBD->SemaphoreId == 0 )
  {
    USBD->SemaphoreId = osSemaphoreCreateEx( USBD->SemaphoreData, 1 );
    if ( USBD->SemaphoreId == 0 )
    return USB_ERROR_SEMAPHORE;
  }
#endif

  USBD->Initialize( );

  USBD_Class_Initialize( USBD );

  // USBD Core Thread
  if ( USBD->ThreadId == 0 )
  {
    USBD->ThreadId = osThreadCreateEx( "USBD_Core", (void*) USBD_CoreThread,
      osPriorityAboveNormal, USBD->StackSize, USBD->ThreadData,
      USBD->ThreadStack, (void*) USBD );
    if ( USBD->ThreadId == 0 )
      return USB_ERROR_THREAD;
  }

  RetValue = USBD_InitializeDriver( USBD );

  RetValue = USBD_PowerControl( USBD, DRIVER_POWER_FULL );

  return RetValue;
}

// De-initialize USB USBD stack and controller
int32_t USBD_Uninitialize( HAL_USBD_TypeDef * USBD )
{
  USBD_UnconfigureEndpoints( USBD );

  USBD_PowerControl( USBD, DRIVER_POWER_OFF );
  USBD_UninitializeDriver( USBD );

  if ( USBD->ThreadId != 0 )
  {
    osThreadTerminateEx( USBD->ThreadId );
    USBD->ThreadId = 0;
  }

  USBD_Class_Uninitialize( USBD );

  USBD->Uninitialize( );

#if ( USBD_SUPPORT_USE_MULTI_THREAD > 0 )
  if ( USBD->SemaphoreId != 0 )
  {
    osSemaphoreDeleteEx( USBD->SemaphoreId );
    USBD->SemaphoreId = 0;
  }
#endif

  return USB_OK;
}

