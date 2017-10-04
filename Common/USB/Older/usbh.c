#include "usb.h"
#include "usbh.h"

static void USBH_PortEventHandler( HAL_USBH_TypeDef * USBH, uint32_t Port,
  uint32_t Event );

static void USBH_PipeEventHandler( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle, uint32_t Event );

#if ( BOARD_USBH1_USED )

static void HAL_USBH1_PortEventHandler( uint32_t Port, uint32_t Event )
{
  USBH_PortEventHandler( &HAL_USBH1, Port, Event );
}

static void HAL_USBH1_PipeEventHandler( DRV_USBH_PipeHandle_TypeDef PipeHandle,
  uint32_t Event )
{
  USBH_PipeEventHandler( &HAL_USBH1, PipeHandle, Event );
}

static osThread HAL_USBH1_Thread;
static osTimer HAL_USBH1_Timer;
static osSemaphore HAL_USBH1_Semaphore;
static HAL_USBH_Info_TypeDef HAL_USBH1_Info;
static uint32_t HAL_USBH1_ThreadStack[ BOARD_USBH_THREAD_STACK_SIZE >> 2 ];
static USBH_Device_TypeDef HAL_USBH1_DeviceArray[ BOARD_USBH1_DEVICE_NUM ];
static HAL_USBH_Pipe_TypeDef HAL_USBH1_PipeArray[ BOARD_USBH1_PIPE_NUM ];
static HAL_USB_DEVICE_DESCRIPTOR HAL_USBH1_DeviceDescriptorArray[ BOARD_USBH1_DEVICE_DESCRIPTOR_NUM ];
static HAL_USB_CONFIGURATION_DESCRIPTOR HAL_USBH1_ConfigurationDescriptorArray[ BOARD_USBH1_CONFIGURATION_DESCRIPTOR_NUM ];

static const USBH_Class_TypeDef * HAL_USBH1_ClassArray[ BOARD_USBH1_CLASS_NUM ];

HAL_USBH_TypeDef HAL_USBH1 =
{ BOARD_USBH1_CLASS_NUM,                      //
  BOARD_USBH1_DEVICE_NUM,                     //
  BOARD_USBH1_PIPE_NUM,                       //
  BOARD_USBH1_XFER_NUM,                       //
  BOARD_USBH1_DEVICE_DESCRIPTOR_NUM,          //
  BOARD_USBH1_CONFIGURATION_DESCRIPTOR_NUM,   //
  BOARD_USBH_THREAD_STACK_SIZE,               //
  BOARD_USBH_DEBOUNCE_IN_MS,                  //
  HAL_USBH1_PortEventHandler,                 //
  HAL_USBH1_PipeEventHandler,                 //
  &HAL_USBH1_Timer,                           //
  &HAL_USBH1_Semaphore,                       //
  &HAL_USBH1_Thread,                          //
  HAL_USBH1_ThreadStack,                      //
  HAL_USBH1_ClassArray,                       //
  HAL_USBH1_PipeArray,                        //
  HAL_USBH1_DeviceArray,                      //
  HAL_USBH1_DeviceDescriptorArray,            //
  HAL_USBH1_ConfigurationDescriptorArray,     //
  &HAL_USBH1_Info,                            //
  &USBH1_Instance,                            //
  &USBH_Driver };                             //

#endif /* #if ( BOARD_USBH1_USED ) */

#if ( BOARD_USBH2_USED )

static void HAL_USBH2_PortEventHandler( uint32_t Port, uint32_t Event )
{
  USBH_PortEventHandler( &HAL_USBH2, Port, Event );
}

static void HAL_USBH2_PipeEventHandler( DRV_USBH_PipeHandle_TypeDef PipeHandle,
  uint32_t Event )
{
  USBH_PipeEventHandler( &HAL_USBH2, PipeHandle, Event );
}

static osThread HAL_USBH2_Thread;
static osTimer HAL_USBH2_Timer;
static osSemaphore HAL_USBH2_Semaphore;
static HAL_USBH_Info_TypeDef HAL_USBH2_Info;
static uint32_t HAL_USBH2_ThreadStack[ BOARD_USBH_THREAD_STACK_SIZE >> 2 ];
static USBH_Device_TypeDef HAL_USBH2_DeviceArray[ BOARD_USBH2_DEVICE_NUM ];
static HAL_USBH_Pipe_TypeDef HAL_USBH2_PipeArray[ BOARD_USBH2_PIPE_NUM ];
static HAL_USB_DEVICE_DESCRIPTOR HAL_USBH2_DeviceDescriptorArray[ BOARD_USBH2_DEVICE_DESCRIPTOR_NUM ];
static HAL_USB_CONFIGURATION_DESCRIPTOR HAL_USBH2_ConfigurationDescriptorArray[ BOARD_USBH2_CONFIGURATION_DESCRIPTOR_NUM ];

static const USBH_Class_TypeDef * HAL_USBH2_ClassArray[ BOARD_USBH2_CLASS_NUM ];

HAL_USBH_TypeDef HAL_USBH2 =
{ BOARD_USBH2_CLASS_NUM,                      //
  BOARD_USBH2_DEVICE_NUM,                     //
  BOARD_USBH2_PIPE_NUM,                       //
  BOARD_USBH2_XFER_NUM,                       //
  BOARD_USBH2_DEVICE_DESCRIPTOR_NUM,          //
  BOARD_USBH2_CONFIGURATION_DESCRIPTOR_NUM,   //
  BOARD_USBH_THREAD_STACK_SIZE,               //
  BOARD_USBH_DEBOUNCE_IN_MS,                  //
  HAL_USBH2_PortEventHandler,                 //
  HAL_USBH2_PipeEventHandler,                 //
  &HAL_USBH2_Timer,                           //
  &HAL_USBH2_Semaphore,                       //
  &HAL_USBH2_Thread,                          //
  HAL_USBH2_ThreadStack,                      //
  HAL_USBH2_ClassArray,                       //
  HAL_USBH2_PipeArray,                        //
  HAL_USBH2_DeviceArray,                      //
  HAL_USBH2_DeviceDescriptorArray,            //
  HAL_USBH2_ConfigurationDescriptorArray,     //
  &HAL_USBH2_Info,                            //
  &USBH2_Instance,                            //
  &USBH_Driver };                             //

#endif /* #if ( BOARD_USBH1_USED ) */

//------------------------------------------------------------------------------
// USB Host Functions for Memory Management
//------------------------------------------------------------------------------
//
// Initialize memory pool to be used used by USB Host controller
// USBH->MemoryPoolSize
//
int32_t USBH_MemoryInitialize( HAL_USBH_TypeDef * USBH )
{
  return USB_OK;
}

// Allocate a chunk of memory from the initialized pool
// to be used by USB Host controller
int32_t USBH_MemoryAllocate( HAL_USBH_TypeDef * USBH, uint8_t ** Memory,
  uint32_t Size )
{
  return USB_OK;
}

// Release a piece of memory back to memory pool used by USB Host controller
int32_t USBH_MemoryFree( HAL_USBH_TypeDef * USBH, uint8_t * Memory )
{
  return USB_OK;
}

// De-initialize memory pool used by USB Host controller
int32_t USBH_MemoryUninitialize( HAL_USBH_TypeDef * USBH )
{
  return USB_OK;
}

//------------------------------------------------------------------------------
// USB Host USBH is not present !
//
#ifndef USBH_DRV_TIMEOUT

#define USBH_DRV_TIMEOUT                      ( 100 )
#define USBH_DEBOUNCE_IN_MS                   ( 100 )
#define USBH_DEBOUNCE_INTERVAL                ( 10 )

#endif

//------------------------------------------------------------------------------
// USB Host Pipe Event : Driver_USBH.h
//
// #define DRV_USBH_EVENT_TRANSFER_COMPLETE   Transfer completed
// #define DRV_USBH_EVENT_HANDSHAKE_NAK       NAK Handshake received
// #define DRV_USBH_EVENT_HANDSHAKE_NYET      NYET Handshake received
// #define DRV_USBH_EVENT_HANDSHAKE_MDATA     MDATA Handshake received
// #define DRV_USBH_EVENT_HANDSHAKE_STALL     STALL Handshake received
// #define DRV_USBH_EVENT_HANDSHAKE_ERR       ERR Handshake received
// #define DRV_USBH_EVENT_BUS_ERROR           Bus Error detected
//
void USBH_PipeEventHandler( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle, uint32_t Event )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->PipeArray;
  if ( Event )
  {
    for ( uint32_t PipeIndex = 0; PipeIndex < USBH->PipeNum; PipeIndex++ )
    {
      if ( PipeHandle == Pipe->Handle )
      {
        osSignalSet( Pipe->TransferThreadId, Event );
        return;
      }
      Pipe++;
    }
  }
}

//------------------------------------------------------------------------------
// USB Host Port Event : Driver_USBH.h
//
// #define DRV_USBH_EVENT_CONNECT             USB Device Connected to Port
// #define DRV_USBH_EVENT_DISCONNECT          USB Device Disconnected from Port
// #define DRV_USBH_EVENT_OVERCURRENT         USB Device caused Overcurrent
// #define DRV_USBH_EVENT_RESET               USB Reset completed
// #define DRV_USBH_EVENT_SUSPEND             USB Suspend occurred
// #define DRV_USBH_EVENT_RESUME              USB Resume occurred
// #define DRV_USBH_EVENT_REMOTE_WAKEUP       USB Device activated Remote Wakeup
//
void USBH_PortEventHandler( HAL_USBH_TypeDef * USBH, uint32_t Port,
  uint32_t Event )
{
  uint32_t PortMask = ( 1 << Port );

  if ( PortMask & USBH->Info->PortConnected )
  {
    // port reset (for enum or recovery )
    // (0 = none, 1..128 = reset active port)
    if ( USBH->Info->PortReset != ( Port + 1 ) )
      USBH->Info->PortDisconnected |= PortMask;
  }

  USBH->Info->PortEvent[ Port ] |= Event;

  // port locked ( for enumeration )
  // (0 = none, 1..128 = locked port)
  if ( ( USBH->Info->PortLock == 0 )
    || ( USBH->Info->PortLock == ( Port + 1 ) ) )
    osSignalSet( USBH->ThreadId, DRV_USBH_SIGNAL_PORT_EVENT );
}

//------------------------------------------------------------------------------
// Driver API
//
#if ( USBH_SUPPORT_USE_MULTI_THREAD > 0 )

int32_t USBH_SemaphoreWait( HAL_USBH_TypeDef * USBH )
{
  return osSemaphoreWait( USBH->Semaphore, USBH_DRV_TIMEOUT );
}

void USBH_SemaphoreRelease( HAL_USBH_TypeDef * USBH )
{
  osSemaphoreRelease( USBH->Semaphore );
}

#else

#define USBH_SemaphoreWait( ... )         ( 1 )
#define USBH_SemaphoreRelease( ... )

#endif

//------------------------------------------------------------------------------
// USB Host Custom Class Functions called by USBH_EnumerateDevice()
//------------------------------------------------------------------------------
//
int32_t USBH_ClassFunction( USBH_Device_TypeDef * Device, uint32_t Index )
{
  int32_t RetValue;
  const USBH_Class_TypeDef * USBH_Class;
  for ( uint32_t i = 0; i < Device->Parent->ClassNum; i++ )
  {
    USBH_Class = Device->Parent->ClassArray[ i ];
    if ( USBH_Class )
    {
      RetValue = ( *( ( (int32_t *) ( USBH_Class ) ) + Index ) );
      RetValue = ( (ClassFunction) RetValue )( Device );
      if ( RetValue == USB_OK )
        return RetValue;
    }
  }
  return USB_ERROR_UNSUPPORTED;
}
// Callback function called when custom class device is connected
// and needs to configure resources used by custom class device instance
// param[in]     Device              pointer to device structure.
// param[in]     DeviceDescriptor         pointer to device descriptor.
// param[in]     ConfigurationDescriptor         pointer to configuration descriptor.
// return        value <= 127         Index of configured custom class device instance.
// return        value == 0xFF        configuration failed.
int32_t USBH_ClassConfigure( USBH_Device_TypeDef * Device )
{
  int32_t RetValue = USBH_ClassFunction( Device, USBH_CLASS_CONFIGURE );
  if ( RetValue == USB_OK )
    Device->Configured = 1;
  return RetValue;
}

// Callback function called when custom class device is disconnected
// and needs to de-configure resources used by custom class device instance
// param[in]     instance Index of custom class device instance.
int32_t USBH_ClassUnconfigure( USBH_Device_TypeDef * Device )
{
  int32_t RetValue = USBH_ClassFunction( Device, USBH_CLASS_UNCONFIGURE );
  if ( RetValue == USB_OK )
    Device->Configured = 0;
  return RetValue;
}

// Callback function called when custom class device is connected
// and needs to initialize custom class device instance
// param[in]     instance Index of custom class device instance.
int32_t USBH_ClassInitialize( USBH_Device_TypeDef * Device )
{
  int32_t RetValue = USBH_ClassFunction( Device, USBH_CLASS_INITIALIZE );
  if ( RetValue == USB_OK )
    Device->Initialized = 1;
  else
  {
    // USB_ERROR_UNSUPPORTED
  }
  return RetValue;
}

// called by USBH_UninitializeDevices() and USBH_EnumerateDevice()
//
// Callback function called when custom class device is disconnected
// and needs to de-initialize custom class device instance
// param[in]     instance Index of custom class device instance.
int32_t USBH_ClassUninitialize( USBH_Device_TypeDef * Device )
{
  int32_t RetValue = USBH_ClassFunction( Device, USBH_CLASS_UNINITIALIZE );
  if ( RetValue == USB_OK )
    Device->Initialized = 0;
  return RetValue;
}

//------------------------------------------------------------------------------
// USB Host Driver Functions
//------------------------------------------------------------------------------
// Initialize USB Host Interface.
int32_t USBH_DriverInitialize( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PortEventHandler_TypeDef PortEventHandler,
  DRV_USBH_PipeEventHandler_TypeDef PipeEventHandler )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->Initialize( USBH->Instance, PortEventHandler,
      PipeEventHandler );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// De-initialize USB Host Interface.
int32_t USBH_DriverUninitialize( HAL_USBH_TypeDef * USBH )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->Uninitialize( USBH->Instance );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Control USB Host Interface Power.
int32_t USBH_DriverPowerControl( HAL_USBH_TypeDef * USBH, uint32_t State )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PowerControl( USBH->Instance, State );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Get current USB Frame Number.
uint16_t USBH_DriverGetFrameNumber( HAL_USBH_TypeDef * USBH )
{
  uint16_t result = 0;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    result = USBH->Driver->GetFrameNumber( USBH->Instance );
    USBH_SemaphoreRelease( USBH );
  }
  return result;
}

//------------------------------------------------------------------------------
// Port Functions
//------------------------------------------------------------------------------
// Get current Root HUB Port State.
DRV_USBH_PortState_TypeDef USBH_DriverPortGetState( HAL_USBH_TypeDef * USBH,
  uint32_t port )
{
  DRV_USBH_PortState_TypeDef PortState = USBH->Driver->PortGetState(
    USBH->Instance, port );

  // port disconnect map in software
  if ( USBH->Info->PortDisconnected & ( 1 << port ) )
    PortState.Connected = 0;

  return PortState;
}

// Do Root HUB Port Reset.
int32_t USBH_DriverPortReset( HAL_USBH_TypeDef * USBH, uint8_t Port )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    USBH->Info->PortReset = Port + 1;
    RetValue = USBH->Driver->PortReset( USBH->Instance, Port );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Resume Root HUB Port (start generating SOFs).
int32_t USBH_DriverPortResume( HAL_USBH_TypeDef * USBH, uint8_t Port )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PortResume( USBH->Instance, Port );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Suspend Root HUB Port (stop generating SOFs).
int32_t USBH_DriverPortSuspend( HAL_USBH_TypeDef * USBH, uint8_t Port )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PortSuspend( USBH->Instance, Port );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Root HUB Port VBUS on/off.
int32_t USBH_DriverPortVbusOnOff( HAL_USBH_TypeDef * USBH, uint8_t Port,
  uint32_t VBusOn )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PortVbusOnOff( USBH->Instance, Port, VBusOn );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

//------------------------------------------------------------------------------
// Pipe Functions
//------------------------------------------------------------------------------
// Create Pipe in System.
// return PipeHandle : USBH's Hardware Resource
DRV_USBH_PipeHandle_TypeDef USBH_DriverPipeCreate( HAL_USBH_TypeDef * USBH,
  uint8_t DevAddr, uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort,
  uint8_t EndpAddr, uint8_t EndpType, uint16_t MaxPacketSize,
  uint8_t EndpInterval )
{
  DRV_USBH_PipeHandle_TypeDef Handle = INVALID_PIPE_HANDLE;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    Handle = USBH->Driver->PipeCreate( USBH->Instance, DevAddr, DevSpeed,
      HubAddr, HubPort, EndpAddr, EndpType, MaxPacketSize, EndpInterval );
    USBH_SemaphoreRelease( USBH );
  }

  return Handle;
}

// Modify Pipe in System.
int32_t USBH_DriverPipeModify( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle, uint8_t DevAddr, uint8_t DevSpeed,
  uint8_t HubAddr, uint8_t HubPort, uint16_t MaxPacketSize )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PipeModify( USBH->Instance, PipeHandle, DevAddr,
      DevSpeed, HubAddr, HubPort, MaxPacketSize );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Delete Pipe from System.
int32_t USBH_DriverPipeDelete( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PipeDelete( USBH->Instance, PipeHandle );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Reset Pipe.
int32_t USBH_DriverPipeReset( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PipeReset( USBH->Instance, PipeHandle );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Abort current USB Pipe transfer.
int32_t USBH_DriverPipeTransferAbort( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PipeTransferAbort( USBH->Instance, PipeHandle );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Transfer packets through USB Pipe.
int32_t USBH_DriverPipeTransfer( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle, uint32_t Packet, uint8_t * Data,
  uint32_t Size )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PipeTransfer( USBH->Instance, PipeHandle, Packet,
      Data, Size );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

// Get result of USB Pipe transfer.
int32_t USBH_DriverPipeTransferGetResult( HAL_USBH_TypeDef * USBH,
  DRV_USBH_PipeHandle_TypeDef PipeHandle )
{
  int32_t RetValue = DRIVER_ERROR_BUSY;
  if ( USBH_SemaphoreWait( USBH ) )
  {
    RetValue = USBH->Driver->PipeTransferGetResult( USBH->Instance,
      PipeHandle );
    USBH_SemaphoreRelease( USBH );
  }
  return RetValue;
}

//------------------------------------------------------------------------------
// USBH Helper Function
//------------------------------------------------------------------------------
uint32_t USBH_PortConnected( HAL_USBH_TypeDef * USBH, uint32_t Port )
{
  DRV_USBH_PortState_TypeDef PortState;
  PortState = USBH_DriverPortGetState( USBH, Port );
  return ( PortState.Connected != 0 );
}

uint32_t USBH_PortDisconnected( HAL_USBH_TypeDef * USBH, uint32_t Port )
{
  DRV_USBH_PortState_TypeDef PortState;
  PortState = USBH_DriverPortGetState( USBH, Port );
  return ( PortState.Connected == 0 );
}

uint32_t USBH_PortSpeed( HAL_USBH_TypeDef * USBH, uint32_t Port )
{
  DRV_USBH_PortState_TypeDef PortState;
  PortState = USBH_DriverPortGetState( USBH, Port );
  return PortState.Speed;
}

// Connect Debounce Timer Callback
//
void USBH_ConnectDebounce( void * pvController )
{
  DRV_USBH_PortState_TypeDef PortState;
  HAL_USBH_TypeDef * USBH = (HAL_USBH_TypeDef *) pvController;
  HAL_USBH_Info_TypeDef * HCI = USBH->Info;

  if ( HCI->DebounceReload ) // start or restart
  {
    HCI->DebounceReload = 0;
    HCI->DebounceCountDown = USBH->DebounceTime / USBH_DEBOUNCE_INTERVAL;
    HCI->DebounceMaxCountDown = 2 * USBH->DebounceTime / USBH_DEBOUNCE_INTERVAL;
  }

  if ( HCI->DebounceCountDown )           // USBH_DEBOUNCE_INTERVAL
    HCI->DebounceCountDown--;
  if ( HCI->DebounceMaxCountDown )        // USBH_DEBOUNCE_INTERVAL
    HCI->DebounceMaxCountDown--;

  for ( uint32_t Port = 0; Port < 15; Port++ )
  {
    // capabilities_and_0x7FFF is bug ?
    if ( ( ( USBH->Capabilities->PortMask >> Port ) == 0 )
      || ( ( HCI->PortDebounce >> Port ) == 0 ) )
      break; // all ports are checked

    PortState = USBH_DriverPortGetState( USBH, Port ); // port connected or not

    if ( HCI->PortDebounce & ( 1 << Port ) ) // port debounce active for both
    {
      // both are connected or disconnected : connect or disconnect debounce
      if ( ( ( HCI->PortConnected >> Port ) & 1 ) == ( PortState.Connected ) )
        HCI->DebounceCountDown = USBH->DebounceTime / USBH_DEBOUNCE_INTERVAL;
    }
  }

  if ( HCI->DebounceMaxCountDown == 0 )           // debouncing
    HCI->PortDebounce = 0;
  else if ( HCI->DebounceCountDown )              // debouncing
  {
    if ( HCI->PortDebounce )                      // any port debounce active
      osTimerStart( USBH->Timer, USBH_DEBOUNCE_INTERVAL );
  }
  else
  {
    for ( uint32_t Port = 0; Port < 15; Port++ )
    {
      // capabilities_and_0x7FFF is bug ?
      if ( ( ( USBH->Capabilities->PortMask >> Port ) == 0 )
        || ( ( HCI->PortDebounce >> Port ) == 0 ) )
        break;  // all ports are checked

      PortState = USBH_DriverPortGetState( USBH, Port );

      // port debounce active and port state are connected
      if ( ( HCI->PortDebounce & ( 1 << Port ) ) && ( PortState.Connected ) )
      {
        if ( ( HCI->PortConnected & ( 1 << Port ) ) == 0 )  // not yet connected
        {
          // port events (16 bits per port) : 16 bits *  16 ports = 256 bits
          HCI->PortEvent[ Port ] |= DRV_USBH_EVENT_DEBOUNCED;
          osSignalSet( USBH->ThreadId, DRV_USBH_SIGNAL_PORT_EVENT );
        }
      }
    }
  }
}

int32_t USBH_UninitializeDevices( HAL_USBH_TypeDef * USBH, uint32_t Port )
{
  uint32_t DevAddr;
  USBH_Device_TypeDef * Device = USBH->DeviceArray;
  for ( uint32_t i = 0; i < USBH->DeviceNum; i++ )
  {
    if ( Device->Used && ( Device->HubPort == Port ) )
    {
      DevAddr = Device->DevAddr;

      if ( Device->Initialized )
        USBH_ClassUninitialize( Device );

      if ( Device->Configured )
        USBH_ClassUnconfigure( Device );

      memset( Device, 0, sizeof(USBH_Device_TypeDef) ); // Free Device

      // DevAddrMask[3] [2] [1]      [0]
      // [127..96] [95..64] [63..32] [31..0]
      USBH->Info->DevAddrMask[ DevAddr >> 5 ] &= ~( 1 << ( DevAddr & 0x1F ) );
    }

    Device++;
  }
  return USB_OK;
}

USBH_Device_TypeDef * USBH_FindRecoveryDevice( HAL_USBH_TypeDef * USBH,
  uint32_t Port )
{
  USBH_Device_TypeDef * Device = USBH->DeviceArray;
  for ( uint32_t i = 0; i < USBH->DeviceNum; i++ )
  {
    if ( Device->HubPort == Port )
      return Device;
    Device++;
  }

  return 0;
}

USBH_Device_TypeDef * USBH_FindFreeDevice( HAL_USBH_TypeDef * USBH )
{
  USBH_Device_TypeDef * Device = USBH->DeviceArray;
  for ( uint32_t i = 0; i < USBH->DeviceNum; i++ )
  {
    if ( Device->Used == 0 )
    {
      Device->Used = 1;
      return Device;
    }
    Device++;
  }

  return 0;
}

USB_DEVICE_DESCRIPTOR * USBH_FindFreeDeviceDescriptor( HAL_USBH_TypeDef * USBH )
{
  HAL_USB_DEVICE_DESCRIPTOR * HAL_DeviceDescriptor = //
    USBH->DeviceDescriptorArray;
  for ( uint32_t i = 0; i < USBH->DeviceDescriptorNum; i++ )
  {
    if ( HAL_DeviceDescriptor->Used == 0 )
    {
      HAL_DeviceDescriptor->Used = 1;
      return (USB_DEVICE_DESCRIPTOR *) HAL_DeviceDescriptor;
    }
    HAL_DeviceDescriptor++;
  }

  return 0;
}

USB_CONFIGURATION_DESCRIPTOR * USBH_FindFreeConfigurationDescriptor(
  HAL_USBH_TypeDef * USBH )
{
  HAL_USB_CONFIGURATION_DESCRIPTOR * HAL_ConfigurationDescriptor = //
    USBH->ConfigurationDescriptorArray;
  for ( uint32_t i = 0; i < USBH->ConfigurationDescriptorNum; i++ )
  {
    if ( HAL_ConfigurationDescriptor->Used == 0 )
    {
      HAL_ConfigurationDescriptor->Used = 1;
      return (USB_CONFIGURATION_DESCRIPTOR *) HAL_ConfigurationDescriptor;
    }
    HAL_ConfigurationDescriptor++;
  }

  return 0;
}

void USBH_FreeDeviceDescriptor( USB_DEVICE_DESCRIPTOR * DeviceDescriptor )
{
  ( (HAL_USB_DEVICE_DESCRIPTOR *) DeviceDescriptor )->Used = 0;
}

void USBH_FreeConfigDescriptor(
  USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptor )
{
  ( (HAL_USB_CONFIGURATION_DESCRIPTOR *) ConfigurationDescriptor )->Used = 0;
}

void USBH_FreeDevcie( USBH_Device_TypeDef * Device )
{
  Device->Used = 0;
}

uint32_t USBH_UpdateLastDeviceAddr( HAL_USBH_TypeDef * USBH )
{
  if ( ( ( USBH->Info->DevAddrMask[ 0 ] >> 1 ) == 0x7FFFFFFF )
    && ( USBH->Info->DevAddrMask[ 1 ] == 0xFFFFFFFF )
    && ( USBH->Info->DevAddrMask[ 2 ] == 0xFFFFFFFF )
    && ( USBH->Info->DevAddrMask[ 3 ] == 0xFFFFFFFF ) )
    return 0xFFFFFFFF;

  uint32_t LastDevAddr = USBH->Info->LastDevAddr & 0x7F;
  while ( 1 )
  {
    LastDevAddr = ( LastDevAddr + 1 ) & 0x7F;

    if ( LastDevAddr == 0 )
      continue;

    if ( ( USBH->Info->DevAddrMask[ LastDevAddr >> 5 ]
      & ( 1 << ( LastDevAddr & 0x1F ) ) ) == 0x00000000 )
      break;
  }

  USBH->Info->LastDevAddr = LastDevAddr;
  return LastDevAddr;
}

int32_t USBH_DefaultPipeSetMaxPacketSize( HAL_USBH_TypeDef * USBH,
  uint32_t MaxPacketSize );
int32_t USBH_DefaultPipeSetAddress( HAL_USBH_TypeDef * USBH, uint32_t Addr );

int32_t USBH_PrepareEnumerateDevice( HAL_USBH_TypeDef * USBH, uint32_t Port,
  uint32_t Speed )
{
  int32_t RetValue;
  USB_DEVICE_DESCRIPTOR * DevDescriptor;

  RetValue = USB_ERROR_DEVICE;
  uint32_t DevAddr = USBH_UpdateLastDeviceAddr( USBH );
  if ( DevAddr == 0xFFFFFFFF )  // No Address Available
    return RetValue;

  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  if ( Pipe == 0 )
    return USB_ERROR_DEVICE;

  RetValue = USB_ERROR_MEMORY;  // Find Free DevDescriptor
  DevDescriptor = USBH_FindFreeDeviceDescriptor( USBH );
  if ( DevDescriptor == 0 )
    return RetValue;

  while ( 1 )
  {
    // Addr = 0x00, MaxPacketSize = 8, Speed and Port from Arguments
    // Pipe->HubAddr == 0 After Pipe is created
    RetValue = USBH_PipeModify( USBH, Pipe, 0x00, Speed, Pipe->HubAddr, Port,
      8 );
    if ( RetValue != USB_OK )
      break;
    /*
     Pipe->DevAddr = 0;
     Pipe->DevSpeed = Speed;
     Pipe->HubPort = Port;
     Pipe->MaxPacketSize = 8;
     */

    osDelay( 100 );

    RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
    USB_REQUEST_TO_DEVICE, USB_DEVICE_DESCRIPTOR_TYPE, 0, 0,
      (uint8_t *) DevDescriptor, 8 );
    if ( RetValue != USB_OK )
      break;

    RetValue = USBH_DefaultPipeSetMaxPacketSize( USBH,
      ( (USB_DEVICE_DESCRIPTOR*) DevDescriptor )->bMaxPacketSize0 );
    break;
  }

  if ( DevDescriptor )
    USBH_FreeDeviceDescriptor( DevDescriptor );

  return RetValue;
}

int32_t USBH_EnumerateDevice( HAL_USBH_TypeDef * USBH, uint32_t Port,
  uint32_t Speed )
{
  uint32_t DeviceDescriptorSize;
  uint32_t ConfigDescriptorSize;
  USBH_Device_TypeDef * Device;
  USB_DEVICE_DESCRIPTOR * DeviceDescriptor;
  USB_CONFIGURATION_DESCRIPTOR * ConfigurationDescriptor;

  int32_t RetValue = USB_ERROR_DEVICE;
  uint32_t RecoverEnumerateDevice = ( Speed == 0xFFFFFFFF );
  if ( RecoverEnumerateDevice )
  {
    Device = USBH_FindRecoveryDevice( USBH, Port );
    if ( Device == 0 )
      return RetValue;
  }

  uint32_t DevAddr = USBH_UpdateLastDeviceAddr( USBH );
  if ( DevAddr == 0xFFFFFFFF )  // No Address Available
    return RetValue;

  while ( 1 )
  {
    if ( RecoverEnumerateDevice )
    {
      DeviceDescriptorSize = Device->DeviceDescriptorSize;
      ConfigDescriptorSize = Device->ConfigurationDescriptorSize;
      DeviceDescriptor = Device->DeviceDescriptor;
      ConfigurationDescriptor = Device->ConfigurationDescriptor;
      Device = USBH_FindRecoveryDevice( USBH, Port );
      if ( Device == 0 )
        return RetValue;

      RetValue = USBH_DefaultPipeSetAddress( USBH, 0x00 );
      if ( RetValue != USB_OK )
        break;

      RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
      USB_REQUEST_TO_DEVICE, USB_DEVICE_DESCRIPTOR_TYPE, 0, 0,
        (uint8_t *) DeviceDescriptor, DeviceDescriptorSize );
      if ( RetValue != USB_OK )
        break;

      RetValue = USBH_DefaultPipeSetMaxPacketSize( USBH,
        DeviceDescriptor->bMaxPacketSize0 );
      if ( RetValue != USB_OK )
        break;
    }
    else
    {
      DeviceDescriptorSize = sizeof(USB_DEVICE_DESCRIPTOR);
      ConfigDescriptorSize = 0x09;

      // Find Free DevDescriptor/ConfDescriptor and Device
      RetValue = USB_ERROR_MEMORY;
      DeviceDescriptor = USBH_FindFreeDeviceDescriptor( USBH );
      if ( DeviceDescriptor == 0 )
        break;

      ConfigurationDescriptor = USBH_FindFreeConfigurationDescriptor( USBH );
      if ( ConfigurationDescriptor == 0 )
        break;

      Device = USBH_FindFreeDevice( USBH );
      if ( Device == 0 )
        break;
    }

    RetValue = USBH_DeviceRequest_SetAddress( USBH, DevAddr );
    if ( RetValue != USB_OK )
      break;

    RetValue = USBH_DefaultPipeSetAddress( USBH, DevAddr );
    if ( RetValue != USB_OK )
      break;

    osDelay( 50 );

    RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
    USB_REQUEST_TO_DEVICE, USB_DEVICE_DESCRIPTOR_TYPE, 0, 0,
      (uint8_t *) DeviceDescriptor, DeviceDescriptorSize );
    if ( RetValue != USB_OK )
      break;

    RetValue = USBH_DefaultPipeSetMaxPacketSize( USBH,
      DeviceDescriptor->bMaxPacketSize0 );
    if ( RetValue != USB_OK )
      break;

    if ( RecoverEnumerateDevice == 0 )
    {
      RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
      USB_REQUEST_TO_DEVICE, USB_CONFIGURATION_DESCRIPTOR_TYPE, 0, 0,
        (uint8_t *) ConfigurationDescriptor, ConfigDescriptorSize );
      if ( RetValue != USB_OK )
        break;

      RetValue = USB_ERROR_MEMORY;
      ConfigDescriptorSize = ConfigurationDescriptor->wTotalLength;
      if ( ConfigDescriptorSize > USBH_MAX_CONFIGURATION_DESCRIPTOR_SIZE )
        break;
    }

    // ConfigDescriptorSize == 255 : Last Member : uint8_t Used
    RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
    USB_REQUEST_TO_DEVICE, USB_CONFIGURATION_DESCRIPTOR_TYPE, 0, 0,
      (uint8_t *) ConfigurationDescriptor, ConfigDescriptorSize );
    if ( RetValue != USB_OK )
      break;

    USBH->Info->DevAddrMask[ DevAddr >> 5 ] |= ( 1 << ( DevAddr & 0x1F ) );

    if ( RecoverEnumerateDevice == 0 )
    {
      // Except Last Member : Used
      memset( Device, 0, sizeof(USBH_Device_TypeDef) - sizeof(uint32_t) );

      Device->Parent = USBH;
      Device->DevAddr = DevAddr;
      Device->DevSpeed = Speed;
      Device->HubAddr = 0;
      Device->HubPort = Port;
      Device->MaxPacketSize = DeviceDescriptor->bMaxPacketSize0;
      Device->VID = DeviceDescriptor->idVendor;
      Device->PID = DeviceDescriptor->idProduct;
      Device->DeviceDescriptorSize = DeviceDescriptorSize;
      Device->ConfigurationDescriptorSize = ConfigDescriptorSize;
      Device->DeviceDescriptor = DeviceDescriptor;
      Device->ConfigurationDescriptor = ConfigurationDescriptor;

      // Create Pipes
      RetValue = USBH_ClassConfigure( Device );
      if ( RetValue != USB_OK )
        break;

      osDelay( 10 );
    }

    RetValue = USBH_DeviceRequest_SetConfiguration( USBH, 1 );
    if ( RetValue != USB_OK )
      break;
    osDelay( 50 );

    if ( RecoverEnumerateDevice == 0 )
    {
      RetValue = USBH_ClassInitialize( Device );  // Class Request etc.
      if ( RetValue != USB_OK )
        USBH_ClassUnconfigure( Device );          // Delete Pipes
      else
      {
        // USB_ERROR_UNSUPPORTED
      }
    }

    break;
  }

  if ( RecoverEnumerateDevice == 0 )
  {
    if ( RetValue != USB_OK )
    {
      if ( Device )
        USBH_FreeDevcie( Device );

      if ( DeviceDescriptor )
        USBH_FreeDeviceDescriptor( DeviceDescriptor );

      if ( ConfigurationDescriptor )
        USBH_FreeConfigDescriptor( ConfigurationDescriptor );
    }
  }

  return RetValue;
}

int32_t USBH_RecoverEnumerateDevice( HAL_USBH_TypeDef * USBH, uint32_t Port )
{
  return USBH_EnumerateDevice( USBH, Port, 0xFFFFFFFF );
}

int32_t USBH_RecoverEnumerateDeviceEx( HAL_USBH_TypeDef * USBH, uint32_t Port )
{
  int32_t RetValue = USB_ERROR_DEVICE;
  USBH_Device_TypeDef * Device = USBH_FindRecoveryDevice( USBH, Port );
  if ( Device == 0 )
    return RetValue;

  USB_DEVICE_DESCRIPTOR * DevDescriptor = Device->DeviceDescriptor;
  USB_CONFIGURATION_DESCRIPTOR * ConfDescriptor = Device
    ->ConfigurationDescriptor;

// DevAddrMask[3] [2] [1     ] [0    ]
// [127..96] [95..64] [63..32] [31..0]
  USBH->Info->DevAddrMask[ Device->DevAddr >> 5 ] |= //
    ( 1 << ( Device->DevAddr & 0x1F ) );

  uint32_t DevAddr = USBH_UpdateLastDeviceAddr( USBH );
  if ( DevAddr == 0xFFFFFFFF )  // No Address Available
    return RetValue;

  RetValue = USBH_DefaultPipeSetAddress( USBH, 0x00 );
  while ( RetValue == USB_OK )
  {
    RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
    USB_REQUEST_TO_DEVICE, USB_DEVICE_DESCRIPTOR_TYPE, 0, 0,
      (uint8_t *) DevDescriptor, Device->DeviceDescriptorSize );
    if ( RetValue != USB_OK )
      break;

    RetValue = USBH_DefaultPipeSetMaxPacketSize( USBH,
      DevDescriptor->bMaxPacketSize0 );
    if ( RetValue != USB_OK )
      break;

    // Standard Device Request : SetAddress
    RetValue = USBH_DeviceRequest_SetAddress( USBH, DevAddr );
    if ( RetValue != USB_OK )
      break;

    // Set Pipe Address
    RetValue = USBH_DefaultPipeSetAddress( USBH, DevAddr );
    if ( RetValue != USB_OK )
      break;

    // Set Device Address
    Device->DevAddr = DevAddr;

    osDelay( 50 );

    RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
    USB_REQUEST_TO_DEVICE, USB_DEVICE_DESCRIPTOR_TYPE, 0, 0,
      (uint8_t *) DevDescriptor, Device->DeviceDescriptorSize );
    if ( RetValue != USB_OK )
      break;

    RetValue = USBH_DefaultPipeSetMaxPacketSize( USBH,
      DevDescriptor->bMaxPacketSize0 );
    if ( RetValue != USB_OK )
      break;

    osDelay( 50 );

    RetValue = USBH_DeviceRequest_GetDescriptor( USBH,
    USB_REQUEST_TO_DEVICE, USB_CONFIGURATION_DESCRIPTOR_TYPE, 0, 0,
      (uint8_t *) ConfDescriptor, Device->ConfigurationDescriptorSize );
    if ( RetValue != USB_OK )
      break;

    USBH->Info->DevAddrMask[ DevAddr >> 5 ] |= //
      ( 1 << ( DevAddr & 0x1F ) );

    osDelay( 10 );

    RetValue = USBH_DeviceRequest_SetConfiguration( USBH, 1 );

    osDelay( 50 );
    break;
  }

  return RetValue;
}

// Get Status of USB Device
int32_t USBH_GetDeviceStatus( USBH_Device_TypeDef * Device )
{
  if ( Device->DevAddr == 0 )
    return USB_ERROR_DEVICE;
  if ( Device->Initialized == 0 )
    return USB_ERROR_DEVICE;
  if ( Device->Configured == 0 )
    return USB_ERROR_DEVICE;
  return USB_OK;
}

//------------------------------------------------------------------------------
// USBH API Interface
//------------------------------------------------------------------------------
// Initialize USB Host stack and controller
// param[in]     USBH                 Index of USB Host controller.
void USBH_ConnectDebounce( void * pvController );
void USBH_CoreThrad( HAL_USBH_TypeDef * USBH );
int32_t USBH_Initialize( HAL_USBH_TypeDef * USBH )
{
  int32_t RetValue;
  USBH->Capabilities = USBH->Driver->GetCapabilities( USBH->Instance );

  memset( USBH->Info, 0x00, sizeof(HAL_USBH_Info_TypeDef) );
  for ( uint32_t PipeIndex = 0; PipeIndex < USBH->PipeNum; PipeIndex++ )
    USBH->PipeArray[ PipeIndex ].Handle = INVALID_PIPE_HANDLE;

  if ( USBH->SemaphoreCreated == 0 )
  {
    osSemaphoreCreateEx( USBH->Semaphore, 1 );
    USBH->SemaphoreCreated = 1;
  }

  if ( USBH->TimerCreated == 0 )
  {
    osTimerCreateEx( USBH->Timer, USBH_ConnectDebounce, osTimerOnce, USBH );
    USBH->TimerCreated = 1;
  }

  if ( USBH->ThreadCreated == 0 )
  {
    osThreadCreateEx( "USBH_Core", (void *) USBH_CoreThrad,
      osPriorityAboveNormal, USBH->StackSize, USBH->ThreadId, USBH->ThreadStack,
      USBH );
    USBH->ThreadCreated = 1;
  }

  RetValue = USBH_MemoryInitialize( USBH );
  if ( RetValue == USB_OK )
    RetValue = USBH_DriverInitialize( USBH, USBH->PortEventHandler,
      USBH->PipeEventHandler );

  if ( RetValue != USB_OK )
  {
    if ( USBH->ThreadCreated )
    {
      osThreadTerminateEx( USBH->ThreadId );
      USBH->ThreadCreated = 0;
    }

    if ( USBH->TimerCreated )
    {
      osTimerDeleteEx( USBH->Timer );
      USBH->TimerCreated = 0;
    }
  }

  return RetValue;
}

int32_t USBH_Start( HAL_USBH_TypeDef * USBH )
{
  int32_t RetValue;
  HAL_USBH_Pipe_TypeDef * DefaultPipe;

  RetValue = USBH_DriverPowerControl( USBH, DRIVER_POWER_FULL );
  if ( RetValue == USB_OK )
  {
    // MaxPacketSize = 8 Bytes : Get Device Descriptor
    DefaultPipe = USBH_PipeCreate( USBH, 0, 0, 0, 0, 0, 0, 8, 0 );
    if ( DefaultPipe == 0 )
      RetValue = USB_ERROR;
    else
    {
      USBH->Info->DefaultPipe = DefaultPipe;
      uint32_t PortNum = 0;
      for ( uint32_t Port = 0; Port < 15; Port++ )
      {
        if ( USBH->Capabilities->PortMask & ( 1 << Port ) )
        {
          PortNum++;
          USBH_DriverPortVbusOnOff( USBH, Port, 1 );
        }
        else
        {
        }
      }

      osDelay( 500 );
    }
  }

  return RetValue;
}

// Register USB Class to Host USBH
int32_t USBH_RegisterClass( HAL_USBH_TypeDef * USBH,
  const USBH_Class_TypeDef * Class )
{
  for ( uint32_t i = 0; i < USBH->ClassNum; i++ )
  {
    if ( USBH->ClassArray[ i ] == Class )
      return USB_OK;

    if ( USBH->ClassArray[ i ] == 0 )
    {
      USBH->ClassArray[ i ] = Class;
      return USB_OK;
    }
  }

  return USB_ERROR_UNSUPPORTED;
}

// Unregister USB Class from Host USBH
int32_t USBH_UnregisterClass( HAL_USBH_TypeDef * USBH,
  const USBH_Class_TypeDef * Class )
{
  for ( uint32_t i = 0; i < USBH->ClassNum; i++ )
  {
    if ( USBH->ClassArray[ i ] == Class )
    {
      USBH->ClassArray[ i ] = 0;
      return USB_OK;
    }
  }

  return USB_ERROR_UNSUPPORTED;
}

int32_t USBH_Stop( HAL_USBH_TypeDef * USBH )
{
  HAL_USBH_Pipe_TypeDef * DefaultPipe = USBH->Info->DefaultPipe;
  if ( DefaultPipe )
    USBH_PipeDelete( USBH, DefaultPipe );

  for ( uint32_t Port = 0; Port < 15; Port++ )
  {
    if ( USBH->Capabilities->PortMask & ( 1 << Port ) )
      USBH_DriverPortVbusOnOff( USBH, Port, 0 );
    else
      break;  // No More Port in PortMask
  }

  USBH_DriverPowerControl( USBH, DRIVER_POWER_OFF );

  return USB_OK;
}

// De-initialize USB Host stack and controller
// param[in]     USBH                 Index of USB Host controller.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_Uninitialize( HAL_USBH_TypeDef * USBH )
{
  if ( USBH->ThreadCreated )
  {
    osThreadTerminateEx( USBH->ThreadId );
    USBH->ThreadCreated = 0;
  }

  if ( USBH->TimerCreated )
  {
    osTimerDeleteEx( USBH->Timer );
    USBH->TimerCreated = 0;
  }

  if ( USBH->SemaphoreCreated )
  {
    osSemaphoreDeleteEx( USBH->Semaphore );
    USBH->ThreadCreated = 0;
  }

  USBH_MemoryUninitialize( USBH );

  osDelay( 100 );
  return USB_OK;
}

// Create Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     DevAddr             device address.
// param[in]     DevSpeed            device speed.
// param[in]     HubAddr             hub address.
// param[in]     HubPort             hub port.
// param[in]     EndpAddr              endpoint address
//                 - EndpAddr.0..3:       address
//                 - EndpAddr.7:          direction
// param[in]     EndpType              endpoint type.
// param[in]     MaxPacketSize   endpoint maximum packet size.
// param[in]     ep_interval          endpoint polling interval.
// return                             pointer to created pipe or pipe creation failed
//                - value > 0:         pointer to created pipe
//                - value 0:           pipe creation failed
HAL_USBH_Pipe_TypeDef * USBH_PipeCreate( HAL_USBH_TypeDef * USBH,
  uint8_t DevAddr, uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort,
  uint8_t EndpAddr, uint8_t EndpType, uint16_t MaxPacketSize, uint8_t Interval )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->PipeArray;
  for ( uint32_t PipeIndex = 0; PipeIndex < USBH->PipeNum; PipeIndex++ )
  {
    if ( Pipe->Handle == INVALID_PIPE_HANDLE )  // Free Pipe
    {
      Pipe->Handle = USBH_DriverPipeCreate( USBH, DevAddr, DevSpeed, HubAddr,
        HubPort, EndpAddr, EndpType, MaxPacketSize, Interval );
      if ( Pipe->Handle != INVALID_PIPE_HANDLE )
      {
        Pipe->EndpointAddress = EndpAddr;
        Pipe->Attributes = EndpType;
        Pipe->Interval = Interval;

        Pipe->DevAddr = DevAddr;
        Pipe->DevSpeed = DevSpeed;
        Pipe->HubAddr = HubAddr;
        Pipe->HubPort = HubPort;
        Pipe->MaxPacketSize = MaxPacketSize;

        Pipe->Active = 0;
        Pipe->Transferred = 0;
        Pipe->TransferThreadId = 0;

        return Pipe;
      }

      Pipe++;
    }
  }
  return 0;
}

// Modify Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// param[in]     DevAddr             device address.
// param[in]     DevSpeed            device speed.
// param[in]     HubAddr             hub address.
// param[in]     HubPort             hub port.
// param[in]     MaxPacketSize   endpoint maximum packet size.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_PipeModify( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe,
  uint8_t DevAddr, uint8_t DevSpeed, uint8_t HubAddr, uint8_t HubPort,
  uint16_t MaxPacketSize )
{
  int32_t RetValue = USBH_DriverPipeModify( USBH, Pipe->Handle, DevAddr,
    DevSpeed, HubAddr, HubPort, MaxPacketSize );

  if ( RetValue == USB_OK )
  {
    Pipe->DevAddr = DevAddr;
    Pipe->DevSpeed = DevSpeed;
    Pipe->HubAddr = HubAddr;
    Pipe->HubPort = HubPort;
    Pipe->MaxPacketSize = MaxPacketSize;
  }

  return RetValue;
}

// Delete Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_PipeDelete( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe )
{
  int32_t RetValue = USBH_DriverPipeDelete( USBH, Pipe->Handle );

// Always Delete Pipe
  if ( RetValue == USB_OK )
    memset( Pipe, 0, sizeof(HAL_USBH_Pipe_TypeDef) );
  else
    memset( Pipe, 0, sizeof(HAL_USBH_Pipe_TypeDef) );

  Pipe->Handle = INVALID_PIPE_HANDLE;

  return RetValue;
}

// Reset Pipe (reset Data toggle)
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_PipeReset( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe )
{
  return USBH_DriverPipeReset( USBH, Pipe->Handle );
}

// Abort send/receive operation on Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_PipeAbort( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe )
{
  int32_t RetValue = USB_OK;
  if ( Pipe->Active )
  {
    RetValue = USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
    osSignalSet( Pipe->TransferThreadId, DRV_USBH_EVENT_TRANSFER_ABORT );
  }
  return RetValue;
}

int32_t USBH_PipeDoPing( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe )
{
  int32_t RetValue;
  osEvent Event;
  uint32_t SystemTickCountCurrent;
  uint32_t SystemTickCountElapsed;

  uint32_t SystemTickCountFirst = osKernelSysTickCount();
  while ( 1 )
  {
    RetValue = USB_ERROR;
    // USBH_PipeSend() set TransferThreadId before call USBH_PipeDoPing
    // Pipe->TransferThreadId = osThreadGetId( );

    // Packet = DRV_USBH_PACKET_PING : 4
    RetValue = USBH_DriverPipeTransfer( USBH, Pipe->Handle,
    DRV_USBH_PACKET_PING, 0, 0 );
    if ( RetValue != USB_OK )
    {
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      return RetValue;
    }

    Event = osSignalWait( 0, 10000 );       // wait 10,000 ms

    if ( OS_EVENT_STATUS(Event) != osEventSignal )
    {
      if ( OS_EVENT_STATUS(Event) == osEventTimeout )
        RetValue = USB_ERROR_TIMEOUT;
      else
        RetValue = USB_ERROR;

      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      return RetValue;
    }

    // EventStatus == osEventSignal
    // RetValue == USB_OK
    if ( OS_EVENT_SIGNAL( Event ) )
    {
      if ( OS_EVENT_SIGNAL(Event) >> 7 )
      {
        osSignalSet( Pipe->TransferThreadId, OS_EVENT_SIGNAL(Event) & ~0x7F );
        uint32_t APort = USBH->Info->PortLock;     // Port 1 is first port
        if ( APort == 0 )         // No Port Lock
          APort = Pipe->HubPort;  // Is Port 0 NOT NEVER used ?
        if ( USBH->Info->PortEvent[ APort - 1 ] )  // Port is 0 based
        {
          RetValue = USB_ERROR_TRANSFER;
          USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
          return RetValue;
        }
      }

      if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_COMPLETE )
        return RetValue;

      if ( OS_EVENT_SIGNAL(Event) != DRV_USBH_EVENT_HANDSHAKE_NAK )
      {
        if ( OS_EVENT_SIGNAL(Event) != DRV_USBH_EVENT_BUS_ERROR )
        {
          if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_ABORT )
            RetValue = USB_ERROR_TRANSFER;
          else
            RetValue = USB_ERROR;
          USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
          return RetValue;
        }

        RetValue = USB_ERROR_TRANSFER;  // DRV_USBH_EVENT_BUS_ERROR
        osDelay( 10 );
      }

      SystemTickCountCurrent = osKernelSysTickCount();
      if ( SystemTickCountCurrent >= SystemTickCountFirst )
        SystemTickCountElapsed = SystemTickCountCurrent - SystemTickCountFirst;
      else
        SystemTickCountElapsed = ~SystemTickCountFirst - SystemTickCountCurrent;

      if ( SystemTickCountElapsed > osKernelSysTickMicroSec( 10000000 ) )
      {
        if ( RetValue == USB_OK )
          RetValue = USB_ERROR_TIMEOUT;
        return RetValue;
      }
    }
  } // while ( 1 )
}

int32_t USBH_PipeSendSetup( HAL_USBH_TypeDef * USBH,
  HAL_USBH_Pipe_TypeDef * Pipe, USB_SetupPacket_TypeDef * SetupPacket )
{
  osEvent Event;

  int32_t RetValue = USB_ERROR_PARAMETER;
  if ( ( Pipe == 0 ) || ( Pipe->Handle == 0 ) || ( SetupPacket == 0 ) )
    return RetValue;

  RetValue = USB_ERROR_BUSY;
  if ( Pipe->Active )
    return RetValue;

  Pipe->Active = 1;
  Pipe->TransferThreadId = osThreadGetId( );

  uint32_t Retry = 0;
  while ( Retry < 3 )
  {
    RetValue = USB_ERROR;

    // Packet = DRV_USBH_PACKET_SETUP : 1
    RetValue = USBH_DriverPipeTransfer( USBH, Pipe->Handle,
    DRV_USBH_PACKET_SETUP, (uint8_t *) SetupPacket, 8 );
    if ( RetValue != USB_OK )
    {
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->Active = 0;
      return RetValue;
    }

    Event = osSignalWait( 0, 100 );       // wait 100 ms
    if ( OS_EVENT_STATUS(Event) != osEventSignal )
    {
      if ( OS_EVENT_STATUS(Event) == osEventTimeout )
        RetValue = USB_ERROR_TIMEOUT;
      else
        RetValue = USB_ERROR;

      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->Active = 0;
      return RetValue;
    }

    if ( OS_EVENT_SIGNAL(Event) >> 7 )
    {
      osSignalSet( Pipe->TransferThreadId, OS_EVENT_SIGNAL(Event) & ~0x7F );

      uint32_t APort = USBH->Info->PortLock;     // Port 1 is first port
      if ( APort == 0 )         // No Port Lock
        APort = Pipe->HubPort;  // Is Port 0 NOT NEVER used ?
      if ( USBH->Info->PortEvent[ APort - 1 ] )  // Port is 0 based
      {
        RetValue = USB_ERROR_TRANSFER;
        USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
        return RetValue;
      }

      if ( OS_EVENT_SIGNAL(Event) >> 7 )
        osSignalSet( Pipe->TransferThreadId, OS_EVENT_SIGNAL(Event) & ~0x7F );
    }

    if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_COMPLETE )
    {
      Pipe->Transferred = 8;
      break;
    }

    if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_BUS_ERROR )
    {
      RetValue = USB_ERROR_TRANSFER;
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      break;
    }

    if ( OS_EVENT_SIGNAL(Event) != DRV_USBH_EVENT_TRANSFER_ABORT )
    {
      RetValue = USB_ERROR;
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      break;
    }

    osDelay( 10 );
  }

  if ( Retry == 3 )
    RetValue = USB_ERROR;

  Pipe->Active = 0;
  return RetValue;
}

// Send Data on Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// param[in]     buf                  buffer containing Data bytes to send.
// param[in]     len                  maximum number of bytes to send.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_PipeSend( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe,
  uint8_t * Data, uint32_t Size )
{
  int32_t RetValue;
  osEvent Event;
  uint32_t Wait;

  RetValue = USB_ERROR_PARAMETER;
  if ( ( Pipe == 0 ) || ( Pipe->Handle == 0 ) )
    return RetValue;

  RetValue = USB_ERROR_BUSY;
  if ( Pipe->Active )
    return RetValue;

  Pipe->Active = 1;
  Pipe->Transferred = 0;
  Pipe->TransferThreadId = osThreadGetId( );

  uint32_t EndpType = Pipe->Attributes & 0x03;
  uint32_t IsHighSpeed = ( Pipe->DevSpeed == USB_SPEED_HIGH );
  uint32_t TransferResult = 0;
  uint32_t Transferred = 0;

  uint32_t SystemTickCountCurrent;
  uint32_t SystemTickCountElapsed;
  uint32_t SystemTickCountFirst = osKernelSysTickCount();
  uint32_t TransferTimeout = osKernelSysTickMicroSec( 10000000 );

  // Control Transfer start with DATA1 always because SetupPacket with DATA0
  uint32_t Packet = DRV_USBH_PACKET_OUT;
  if ( ( Pipe->EndpointAddress & 0x0F ) == 0 )
    Packet |= DRV_USBH_PACKET_DATA1;

  while ( 1 )
  {
    RetValue = USB_ERROR_DRIVER;
    if ( USBH_PortDisconnected( USBH, Pipe->HubPort ) )
    {
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->TransferThreadId = 0;
      Pipe->Active = 0;
      return RetValue;
    }

    // DATA0 for State Stage : Control Transfer with Data Stage
    if ( ( TransferResult ) && ( Packet & DRV_USBH_PACKET_DATA1 ) )
      Packet &= ~DRV_USBH_PACKET_DATA1;

    RetValue = USBH_DriverPipeTransfer( USBH, Pipe->Handle, Packet,
      Data + Transferred, Size - Transferred );

    if ( RetValue != USB_OK )
    {
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->TransferThreadId = 0;
      Pipe->Active = 0;
      return RetValue;
    }

    switch ( EndpType )
    {
      case USB_ENDPOINT_TYPE_CONTROL:
        Wait = 500 * ( Size != 0 ) + 100;
        break;

      case USB_ENDPOINT_TYPE_BULK:
        Wait = 10000;
        break;

      case USB_ENDPOINT_TYPE_INTERRUPT:
      case USB_ENDPOINT_TYPE_ISOCHRONOUS:
        Wait = osWaitForever;
        break;
    }

    Event = osSignalWait( 0, Wait );
    TransferResult = USBH_DriverPipeTransferGetResult( USBH, Pipe->Handle );

    Size -= TransferResult;
    Data += TransferResult;
    Transferred += TransferResult;
    Pipe->Transferred += TransferResult;

    if ( OS_EVENT_STATUS(Event) != osEventSignal )
    {
      if ( OS_EVENT_STATUS(Event) == osEventTimeout )
        RetValue = USB_ERROR_TIMEOUT;
      else
        RetValue = USB_ERROR;
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->TransferThreadId = 0;
      Pipe->Active = 0;
      return RetValue;
    }
    else if ( OS_EVENT_SIGNAL( Event ) == 0 )
      continue;
    else
    {
      if ( OS_EVENT_SIGNAL(Event) >> 7 )
      {
        osSignalSet( Pipe->TransferThreadId, OS_EVENT_SIGNAL(Event) & ~0x7F );
        uint32_t APort = USBH->Info->PortLock;     // Port 1 is first port
        if ( APort == 0 )     // No Port Lock
          APort = Pipe->HubPort;     // Is Port 0 NOT NEVER used ?
        if ( USBH->Info->PortEvent[ APort - 1 ] )     // Port is 0 based
        {
          RetValue = USB_ERROR_TRANSFER;
          USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
          Pipe->TransferThreadId = 0;
          Pipe->Active = 0;
          return RetValue;
        }
      }

      if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_BUS_ERROR )
      {
        RetValue = USB_ERROR_TRANSFER;
        osDelay( 10 );
      }
      else if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_HANDSHAKE_STALL )
      {
        RetValue = USB_ERROR_STALL;
        Pipe->Active = 0;
        return RetValue;
      }
      else if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_COMPLETE )
      {
        if ( Size > 0 )
          continue;

        Pipe->Active = 0;
        return RetValue;
      }
      else if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_HANDSHAKE_NYET )
      {
        if ( Size )
        {
          RetValue = USBH_PipeDoPing( USBH, Pipe );
          if ( RetValue == USB_OK )
            continue;
        }

        Pipe->Active = 0;
        return RetValue;
      }
      else if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_HANDSHAKE_NAK )
      {
        switch ( EndpType )
        {
          case USB_ENDPOINT_TYPE_CONTROL:
          case USB_ENDPOINT_TYPE_BULK:
            SystemTickCountCurrent = osKernelSysTickCount();
            if ( SystemTickCountCurrent >= SystemTickCountFirst )
              SystemTickCountElapsed = SystemTickCountCurrent
                - SystemTickCountFirst;
            else
              SystemTickCountElapsed = ~SystemTickCountFirst
                - SystemTickCountCurrent;

            if ( SystemTickCountElapsed >= TransferTimeout )
            {
              if ( RetValue == USB_OK )
                RetValue = USB_ERROR_TIMEOUT;
              Pipe->Active = 0;
              return RetValue;
            }

            if ( !IsHighSpeed )
              continue;

            RetValue = USBH_PipeDoPing( USBH, Pipe );
            if ( RetValue == USB_OK )
              continue;

            Pipe->Active = 0;
            return RetValue;

          case USB_ENDPOINT_TYPE_ISOCHRONOUS:
            break;

          case USB_ENDPOINT_TYPE_INTERRUPT:
            if ( IsHighSpeed )
            {
              if ( Pipe->Interval >= 4 )
                osDelay( 1 << ( Pipe->Interval - 4 ) );
            }
            else if ( Pipe->Interval )
              osDelay( Pipe->Interval );

            continue;
            break;
        }
      }
      else
      {
        if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_ABORT )
          RetValue = USB_ERROR_TRANSFER;
        else
          RetValue = USB_ERROR;
        USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
        Pipe->TransferThreadId = 0;
        Pipe->Active = 0;
        return RetValue;
      }
    }
  } // while ( 1 )
}

// Get result of send Data operation on Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// return                             number of successfully sent Data bytes.
int32_t USBH_PipeSendGetResult( HAL_USBH_TypeDef * USBH,
  HAL_USBH_Pipe_TypeDef * Pipe )
{
  if ( Pipe->EndpointAddress & 0x80 )
    return 0;
  return Pipe->Transferred;
}

// Receive Data on Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// param[out]    buf                  buffer that receives Data.
// param[in]     len                  maximum number of bytes to receive.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_PipeReceive( HAL_USBH_TypeDef * USBH, HAL_USBH_Pipe_TypeDef * Pipe,
  uint8_t * Data, uint32_t Size )
{
  int32_t RetValue;
  osEvent Event;
  uint32_t Wait;

  RetValue = USB_ERROR_PARAMETER;
  if ( ( Pipe == 0 ) || ( Pipe->Handle == 0 ) )
    return RetValue;

  RetValue = USB_ERROR_BUSY;
  if ( Pipe->Active )
    return RetValue;

  Pipe->Active = 1;
  Pipe->Transferred = 0;
  Pipe->TransferThreadId = osThreadGetId( );

  uint32_t EndpType = Pipe->Attributes & 0x03;
  uint32_t IsHighSpeed = ( Pipe->DevSpeed == USB_SPEED_HIGH );
  uint32_t TransferResult = 0;
  uint32_t Transferred = 0;

  uint32_t SystemTickCountCurrent;
  uint32_t SystemTickCountElapsed;
  uint32_t SystemTickCountFirst = osKernelSysTickCount();
  uint32_t TransferTimeout = osKernelSysTickMicroSec( 10000000 );

  // Control Transfer start with DATA1 always because SetupPacket with DATA0
  uint32_t Packet = DRV_USBH_PACKET_IN;
  if ( ( Pipe->EndpointAddress & 0x0F ) == 0 )
    Packet |= DRV_USBH_PACKET_DATA1;

  while ( 1 )
  {
    // DATA0 for State Stage : Control Transfer with Data Stage
    if ( ( TransferResult ) && ( Packet & DRV_USBH_PACKET_DATA1 ) )
      Packet &= ~DRV_USBH_PACKET_DATA1;

    RetValue = USBH_DriverPipeTransfer( USBH, Pipe->Handle, Packet,
      Data + Transferred, Size - Transferred );

    if ( RetValue != USB_OK )
    {
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->TransferThreadId = 0;
      Pipe->Active = 0;
      return RetValue;
    }

    switch ( EndpType )
    {
      case USB_ENDPOINT_TYPE_CONTROL:
        Wait = 500 * ( Size != 0 ) + 100;
        break;

      case USB_ENDPOINT_TYPE_BULK:
        Wait = 10000;
        break;

      case USB_ENDPOINT_TYPE_INTERRUPT:
      case USB_ENDPOINT_TYPE_ISOCHRONOUS:
        Wait = osWaitForever;
        break;
    }

    Event = osSignalWait( 0, Wait );
    TransferResult = USBH_DriverPipeTransferGetResult( USBH, Pipe->Handle );

    Size -= TransferResult;
    Data += TransferResult;
    Transferred += TransferResult;
    Pipe->Transferred += TransferResult;

    if ( OS_EVENT_STATUS(Event) != osEventSignal )
    {
      if ( OS_EVENT_STATUS(Event) == osEventTimeout )
        RetValue = USB_ERROR_TIMEOUT;
      else
        RetValue = USB_ERROR;
      USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
      Pipe->TransferThreadId = 0;
      Pipe->Active = 0;
      return RetValue;
    }
    else if ( OS_EVENT_SIGNAL( Event ) == 0 )
      continue;
    else
    {
      if ( OS_EVENT_SIGNAL(Event) >> 7 )
      {
        osSignalSet( Pipe->TransferThreadId, OS_EVENT_SIGNAL(Event) & ~0x7F );
        uint32_t APort = USBH->Info->PortLock;     // Port 1 is first port
        if ( APort == 0 )     // No Port Lock
          APort = Pipe->HubPort;     // Is Port 0 NOT NEVER used ?
        if ( USBH->Info->PortEvent[ APort - 1 ] )     // Port is 0 based
        {
          RetValue = USB_ERROR_TRANSFER;
          USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
          Pipe->TransferThreadId = 0;
          Pipe->Active = 0;
          return RetValue;
        }
      }

      if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_BUS_ERROR )
      {
        RetValue = USB_ERROR_TRANSFER;
        osDelay( 10 );
      }
      else if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_COMPLETE )
      {
        if ( Size > 0 )
          continue;

        Pipe->TransferThreadId = 0;
        Pipe->Active = 0;
        return RetValue;
      }
      else if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_HANDSHAKE_NAK )
      {
        switch ( EndpType )
        {
          case USB_ENDPOINT_TYPE_CONTROL:
          case USB_ENDPOINT_TYPE_BULK:
            SystemTickCountCurrent = osKernelSysTickCount();
            if ( SystemTickCountCurrent >= SystemTickCountFirst )
              SystemTickCountElapsed = SystemTickCountCurrent
                - SystemTickCountFirst;
            else
              SystemTickCountElapsed = ~SystemTickCountFirst
                - SystemTickCountCurrent;

            if ( SystemTickCountElapsed < TransferTimeout )
              continue;

            if ( RetValue == USB_OK )
              RetValue = USB_ERROR_TIMEOUT;
            Pipe->TransferThreadId = 0;
            Pipe->Active = 0;
            return RetValue;

          case USB_ENDPOINT_TYPE_ISOCHRONOUS:
            break;

          case USB_ENDPOINT_TYPE_INTERRUPT:
            if ( IsHighSpeed )
            {
              if ( Pipe->Interval >= 4 )
                osDelay( 1 << ( Pipe->Interval - 4 ) );
            }
            else if ( Pipe->Interval )
              osDelay( Pipe->Interval );

            continue;
            break;
        }
      }
      else
      {
        if ( OS_EVENT_SIGNAL(Event) == DRV_USBH_EVENT_TRANSFER_ABORT )
          RetValue = USB_ERROR_TRANSFER;
        else
          RetValue = USB_ERROR;
        USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
        Pipe->TransferThreadId = 0;
        Pipe->Active = 0;
        return RetValue;
      }
    }
  } // while ( 1 )
}

// Get result of receive Data operation on Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     ptr_pipe             pointer to pipe.
// return                             number of successfully received Data bytes.
int32_t USBH_PipeReceiveGetResult( HAL_USBH_TypeDef * USBH,
  HAL_USBH_Pipe_TypeDef * Pipe )
{
  if ( Pipe->EndpointAddress & 0x80 )
    return Pipe->Transferred;
  return 0;
}

//------------------------------------------------------------------------------
// Default Pipe Functions
//------------------------------------------------------------------------------
// Send Setup Xfer on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     SetupPacket         pointer to setup packet.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DefaultPipeSendSetup( HAL_USBH_TypeDef * USBH,
  USB_SetupPacket_TypeDef * SetupPacket )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeSendSetup( USBH, Pipe, SetupPacket );
}

// Receive Data on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[out]    buf                  buffer that receives Data.
// param[in]     len                  maximum number of bytes to receive.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DefaultPipeReceive( HAL_USBH_TypeDef * USBH, uint8_t * Data,
  uint32_t Size )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeReceive( USBH, Pipe, Data, Size );
}

// Get result of receive Data operation on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// return                             number of successfully received Data bytes.
int32_t USBH_DefaultPipeReceiveGetResult( HAL_USBH_TypeDef * USBH )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeReceiveGetResult( USBH, Pipe );
}

// Send Data on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     buf                  buffer containing Data bytes to send.
// param[in]     len                  maximum number of bytes to send.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DefaultPipeSend( HAL_USBH_TypeDef * USBH, uint8_t * Data,
  uint32_t Size )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeSend( USBH, Pipe, Data, Size );
}

// Get result of send Data operation on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// return                             number of successfully sent Data bytes.
int32_t USBH_DefaultPipeSendGetResult( HAL_USBH_TypeDef * USBH )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeSendGetResult( USBH, Pipe );
}

// Abort send/receive operation on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DefaultPipeAbort( HAL_USBH_TypeDef * USBH )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeAbort( USBH, Pipe );
}

int32_t USBH_DefaultPipeSetAddress( HAL_USBH_TypeDef * USBH, uint32_t Addr )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeModify( USBH, Pipe, Addr, Pipe->DevSpeed, Pipe->HubAddr,
    Pipe->HubPort, Pipe->MaxPacketSize );
}

int32_t USBH_DefaultPipeSetMaxPacketSize( HAL_USBH_TypeDef * USBH,
  uint32_t MaxPacketSize )
{
  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  return USBH_PipeModify( USBH, Pipe, Pipe->DevAddr, Pipe->DevSpeed,
    Pipe->HubAddr, Pipe->HubPort, MaxPacketSize );
}

// Do a Control Transfer on Default Pipe
// param[in]     USBH                 Index of USB Host controller.
// param[in]     SetupPacket         pointer to setup packet.
// param[in,out] Data                 buffer containing Data bytes to send or where Data should be received in Data stage of Control Transfer.
// param[in]     len                  number of bytes to send or receive in Data stage of Control Transfer.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_ControlTransfer( HAL_USBH_TypeDef * USBH,
  USB_SetupPacket_TypeDef * SetupPacket, uint8_t * Data, uint32_t Size )
{
  int32_t RetValue = USB_ERROR_PARAMETER;
  if ( ( Size > 0 ) && ( Data == 0 ) )
    return RetValue;

  HAL_USBH_Pipe_TypeDef * Pipe = USBH->Info->DefaultPipe;
  if ( Pipe == 0 )
    return USB_ERROR;

  SetupPacket->wLength = Size;
  for ( uint32_t Retry = 0; Retry < 3; Retry++ )
  {
    RetValue = USBH_PipeSendSetup( USBH, Pipe, SetupPacket );
    if ( RetValue == USB_OK )
    {
      if ( Size == 0 )  // With Data Stage, Status In Stage
      {
        RetValue = USBH_PipeReceive( USBH, Pipe, 0, 0 );
        if ( RetValue == USB_OK )
          break;
      }
      else if ( SetupPacket->bmRequestType.Dir == 1 )  // Control In
      {
        RetValue = USBH_PipeReceive( USBH, Pipe, Data, Size );  // Data In
        if ( RetValue == USB_OK )
        {
          RetValue = USBH_PipeSend( USBH, Pipe, 0, 0 );   // Status Out
          if ( RetValue == USB_OK )
            break;
        }
      }
      else
      {
        RetValue = USBH_PipeSend( USBH, Pipe, Data, Size );   // Data Out
        if ( RetValue == USB_OK )
        {
          RetValue = USBH_PipeReceive( USBH, Pipe, 0, 0 );    // Status In
          if ( RetValue == USB_OK )
            break;
        }
      }
    }

    osDelay( 50 );
  }

  return RetValue;
}

// Standard Device Request on Default Pipe - GET_STATUS
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     Index                interface or endpoint Index.
// param[out]    ptr_stat_dat         pointer to where RetValue Data should be received.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_GetStatus( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t Index, uint8_t * Status )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 1;
  SetupPacket.bmRequestType.Recipient = Recipient;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_GET_STATUS;
  SetupPacket.wValue = 0;
  SetupPacket.wIndex = Index;
  return USBH_ControlTransfer( USBH, &SetupPacket, Status, 2 );
}

// Standard Device Request on Default Pipe - CLEAR_FEATURE
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     Index                interface or endpoint Index.
// param[in]     FeatureSelector     feature selector.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_ClearFeature( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t Index, uint8_t FeatureSelector )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 0;
  SetupPacket.bmRequestType.Recipient = Recipient;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_CLEAR_FEATURE;
  SetupPacket.wValue = FeatureSelector;
  SetupPacket.wIndex = Index;
  return USBH_ControlTransfer( USBH, &SetupPacket, 0, 0 );
}

// Standard Device Request on Default Pipe - SET_FEATURE
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     Index                interface or endpoint Index.
// param[in]     FeatureSelector     feature selector.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_SetFeature( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t Index, uint8_t FeatureSelector )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 0;
  SetupPacket.bmRequestType.Recipient = Recipient;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_SET_FEATURE;
  SetupPacket.wValue = FeatureSelector;
  SetupPacket.wIndex = Index;
  return USBH_ControlTransfer( USBH, &SetupPacket, 0, 0 );
}

// Standard Device Request on Default Pipe - SET_ADDRESS
// param[in]     USBH                 Index of USB Host controller.
// param[in]     device_address       device address.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_SetAddress( HAL_USBH_TypeDef * USBH,
  uint8_t Address )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 0;
  SetupPacket.bmRequestType.Recipient = USB_REQUEST_TO_DEVICE;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_SET_ADDRESS;
  SetupPacket.wValue = Address;
  SetupPacket.wIndex = 0;
  return USBH_ControlTransfer( USBH, &SetupPacket, 0, 0 );
}

// Standard Device Request on Default Pipe - GET_DESCRIPTOR
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     descriptor_type      descriptor type.
// param[in]     descriptor_index     descriptor Index.
// param[in]     language_id          language ID.
// param[out]    descriptor_Data      pointer to where descriptor Data will be read.
// param[in]     descriptor_length    descriptor length.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_GetDescriptor( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t DescriptorType, uint8_t DescriptorIndex,
  uint8_t LanguageId, uint8_t * Descriptor, uint16_t DescriptorLength )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 1;
  SetupPacket.bmRequestType.Recipient = Recipient;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_GET_DESCRIPTOR;
  SetupPacket.wValue = LanguageId | ( DescriptorType << 8 );
  SetupPacket.wIndex = DescriptorIndex;
  return USBH_ControlTransfer( USBH, &SetupPacket, Descriptor,
    DescriptorLength );
}

// Standard Device Request on Default Pipe - SET_DESCRIPTOR
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Recipient            Recipient.
// param[in]     descriptor_type      descriptor type.
// param[in]     descriptor_index     descriptor Index.
// param[in]     language_id          language ID.
// param[in]     descriptor_Data      pointer to descriptor Data to be written.
// param[in]     descriptor_length    descriptor length.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_SetDescriptor( HAL_USBH_TypeDef * USBH,
  uint8_t Recipient, uint8_t DescriptorType, uint8_t DescriptorIndex,
  uint8_t LanguageId, uint8_t * Descriptor, uint16_t DescriptorLength )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 0;
  SetupPacket.bmRequestType.Recipient = Recipient;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_GET_DESCRIPTOR;
  SetupPacket.wValue = LanguageId | ( DescriptorType << 8 );
  SetupPacket.wIndex = DescriptorIndex;
  return USBH_ControlTransfer( USBH, &SetupPacket, 0, 0 );
}

// Standard Device Request on Default Pipe - GET_CONFIGURATION
// param[in]     USBH                 Index of USB Host controller.
// param[out]    ptr_configuration    pointer to where configuration will be read.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_GetConfiguration( HAL_USBH_TypeDef * USBH,
  uint8_t * Configuration )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 1;
  SetupPacket.bmRequestType.Recipient = USB_REQUEST_TO_DEVICE;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_GET_CONFIGURATION;
  SetupPacket.wValue = 0;
  SetupPacket.wIndex = 0;
  return USBH_ControlTransfer( USBH, &SetupPacket, Configuration, 1 );
}

// Standard Device Request on Default Pipe - SET_CONFIGURATION
// param[in]     USBH                 Index of USB Host controller.
// param[in]     configuration        configuration.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_SetConfiguration( HAL_USBH_TypeDef * USBH,
  uint8_t Configuration )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 0;
  SetupPacket.bmRequestType.Recipient = USB_REQUEST_TO_DEVICE;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_SET_CONFIGURATION;
  SetupPacket.wValue = Configuration;
  SetupPacket.wIndex = 0;
  return USBH_ControlTransfer( USBH, &SetupPacket, 0, 0 );
}

// Standard Device Request on Default Pipe - GET_INTERFACE
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Index                interface Index.
// param[out]    ptr_alternate        pointer to where AltSetting setting Data will be read.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_GetInterface( HAL_USBH_TypeDef * USBH, uint8_t Index,
  uint8_t * Alternate )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 1;
  SetupPacket.bmRequestType.Recipient = USB_REQUEST_TO_DEVICE;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_GET_INTERFACE;
  SetupPacket.wValue = 0;
  SetupPacket.wIndex = Index;
  return USBH_ControlTransfer( USBH, &SetupPacket, Alternate, 1 );
}

// Standard Device Request on Default Pipe - SET_INTERFACE
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Index                interface Index.
// param[in]     AltSetting            AltSetting setting.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_SetInterface( HAL_USBH_TypeDef * USBH, uint8_t Index,
  uint8_t AltSetting )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 0;
  SetupPacket.bmRequestType.Recipient = USB_REQUEST_TO_DEVICE;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_SET_INTERFACE;
  SetupPacket.wValue = AltSetting;
  SetupPacket.wIndex = Index;
  return USBH_ControlTransfer( USBH, &SetupPacket, 0, 0 );
}

// Standard Device Request on Default Pipe - SYNCH_FRAME
// param[in]     USBH                 Index of USB Host controller.
// param[in]     Index                interface or endpoint Index.
// param[out]    ptr_frame_number     pointer to where frame number Data will be read.
// return                             RetValue code that indicates the execution RetValue of the function as defined with \ref int32_t.
int32_t USBH_DeviceRequest_SynchFrame( HAL_USBH_TypeDef * USBH, uint8_t Index,
  uint8_t * FrameNumber )
{
  USB_SetupPacket_TypeDef SetupPacket;
  SetupPacket.bmRequestType.Dir = 1;
  SetupPacket.bmRequestType.Recipient = USB_REQUEST_TO_DEVICE;
  SetupPacket.bmRequestType.Type = USB_REQUEST_STANDARD;
  SetupPacket.bRequest = USB_REQUEST_SYNC_FRAME;
  SetupPacket.wValue = 0;
  SetupPacket.wIndex = Index;
  return USBH_ControlTransfer( USBH, &SetupPacket, FrameNumber, 2 );
}

void USBH_RecoverThreadEventHandler( HAL_USBH_TypeDef * USBH, uint32_t Port,
  uint32_t Event )
{
  USBH_Device_TypeDef * Device;
  Device = USBH_FindRecoveryDevice( USBH, Port );
  if ( Device )
    osSignalSet( Device->RecoveryThreadId, Event );
}

int32_t USBH_RecoverDevice( USBH_Device_TypeDef * Device )
{
  Device->RecoveryThreadId = osThreadGetId( );
  HAL_USBH_TypeDef * USBH = Device->Parent;
  HAL_USBH_Info_TypeDef * HCI = USBH->Info;
  while ( HCI->PortLock )
    osDelay( 1 );

  HCI->PortEvent[ Device->HubPort ] |= DRV_USBH_EVENT_RECOVER_DEVICE;
  osSignalSet( USBH->ThreadId, DRV_USBH_SIGNAL_PORT_EVENT );

  osEvent Event = osSignalWait( 0, osWaitForever );
  if ( Event.status == osEventSignal )
  {
    if ( Event.value.signals & DRV_USBH_EVENT_RECOVER_SUCCESS )
      return USB_OK;
    else
    {
      // Event.value.signals == DRV_USBH_EVENT_RECOVER_FAILED
    }
  }

  return USB_ERROR;
}

void USBH_Core( HAL_USBH_TypeDef * USBH, uint32_t Port, uint32_t Event )
{
  int32_t RetValue;
  uint32_t PortSpeed;
  uint32_t PortMask = 1 << Port;
  uint32_t PortRetryValueDec = 1 << 2 * Port;
  uint32_t PortRetryValueReload = 3 << 2 * Port;

  uint8_t * PortEnumStatePtr = &USBH->Info->EnumState[ Port ];
  if ( Event & DRV_USBH_EVENT_RECOVER_DEVICE )
    *PortEnumStatePtr = ENUM_STATE_RECOVER_FIND_RESET;

  switch ( *PortEnumStatePtr )
  {
    case ENUM_STATE_CONNECTED:
      if ( PortMask & USBH->Info->PortConnected )  // has been Connected
        return;
      if ( ( Event & DRV_USBH_EVENT_CONNECT ) == 0 )        // Not Connect Event
        return;

      USBH->Info->PortConnected |= PortMask;           // Connected
      USBH->Info->PortRetry |= PortRetryValueReload;   // RetryValue = 3
      RetValue = USBH_DriverPortReset( USBH, Port );  // Reset Port
      if ( RetValue == USB_OK )                             // Wait Reset Event
      {
        *PortEnumStatePtr = ENUM_STATE_RESET_PORT;      // Next State
        return;
      }
      goto EnumCompleted;

    case ENUM_STATE_RESET_PORT:                         // Reset OK
      if ( USBH_PortDisconnected( USBH, Port ) )      // Disconnected ?
        goto DeviceDisconnected;
      if ( ( Event & DRV_USBH_EVENT_RESET ) == 0 )             // Reset Failed ?
        return;

      osDelay( 35 );
      USBH_DriverPortSuspend( USBH, Port );

      osDelay( 100 );
      USBH_DriverPortResume( USBH, Port );

      osDelay( 35 );

      USBH->Info->PortReset = 0;

      if ( USBH_PortDisconnected( USBH, Port ) )      // Disconnected ?
        goto DeviceDisconnected;

      RetValue = USBH_DriverPortReset( USBH, Port );  // Reset Port
      if ( RetValue == USB_OK )                             // Wait Reset Event
      {
        *PortEnumStatePtr = ENUM_STATE_GET_MAX_PACKET_SIZE0; // DRV_USBH_EVENT_RESET
        return;                                             // Trigger NextState
      }
      goto EnumCompleted;

    case ENUM_STATE_GET_MAX_PACKET_SIZE0:
      if ( USBH_PortDisconnected( USBH, Port ) )      // Disconnected ?
        goto DeviceDisconnected;
      if ( ( Event & DRV_USBH_EVENT_RESET ) == 0 )             // Reset Failed ?
        return;

      USBH->Info->PortReset = 0;

      osDelay( 100 );

      if ( USBH_PortDisconnected( USBH, Port ) )      // Disconnected ?
        goto DeviceDisconnected;

      PortSpeed = USBH_PortSpeed( USBH, Port );
      RetValue = USBH_PrepareEnumerateDevice( USBH, Port, PortSpeed );

      // Disconnected After USBH_PrepareEnumerateDevice()
      if ( USBH_PortDisconnected( USBH, Port ) )
        goto DeviceDisconnected;

      if ( RetValue == USB_OK )
      {
        if ( USBH_DriverPortReset( USBH, Port ) == USB_OK )
        {
          *PortEnumStatePtr = ENUM_STATE_ENUMERATION;    // DRV_USBH_EVENT_RESET
          return;                                         // Trigger NextState
        }
      }
      else if ( ( USBH->Info->PortRetry & PortRetryValueReload ) )
      {
        USBH->Info->PortRetry -= PortRetryValueDec;
        if ( USBH_DriverPortReset( USBH, Port ) == USB_OK )
        {
          *PortEnumStatePtr = ENUM_STATE_RESET_PORT;  // DRV_USBH_EVENT_RESET
          return;                                         // Trigger NextState
        }
      }
      goto EnumCompleted;
      // Failed Try 3 Times

    case ENUM_STATE_ENUMERATION:
      if ( USBH_PortDisconnected( USBH, Port ) )
        goto DeviceDisconnected;

      if ( ( Event & DRV_USBH_EVENT_RESET ) == 0 )
        return;

      EnumerateDevice: USBH->Info->PortReset = 0;

      osDelay( 100 ); // Device is handling reset event

      if ( USBH_PortDisconnected( USBH, Port ) )
        goto DeviceDisconnected;

      PortSpeed = USBH_PortSpeed( USBH, Port );
      RetValue = USBH_EnumerateDevice( USBH, Port, PortSpeed );

      if ( USBH_PortDisconnected( USBH, Port ) )
        goto DeviceDisconnected;

      if ( RetValue == USB_OK )
        goto EnumCompleted;

      if ( ( USBH->Info->PortRetry & PortRetryValueReload ) == 0 )
        goto EnumCompleted;

      USBH->Info->PortRetry -= PortRetryValueDec;
      if ( USBH_DriverPortReset( USBH, Port ) == USB_OK )
      {
        *PortEnumStatePtr = ENUM_STATE_RESET_PORT;
        return;
      }
      goto EnumCompleted;

    case ENUM_STATE_COMPLETED:
      EnumCompleted: *PortEnumStatePtr = ENUM_STATE_COMPLETED;
      if ( USBH_PortDisconnected( USBH, Port ) )
        goto DeviceDisconnected;

      USBH->Info->PortLock = 0;
      osSignalSet( USBH->ThreadId, DRV_USBH_SIGNAL_PORT_EVENT );
      return;

    case ENUM_STATE_RECOVER_FIND_RESET:
      RecoverTryAgain: if ( ( USBH_PortConnected( USBH, Port ) )
        && ( USBH_DriverPortReset( USBH, Port ) == USB_OK ) )
      {
        *PortEnumStatePtr = ENUM_STATE_RECOVER_RESET_AGAIN;
        return;
      }
      goto RecoverFailed;

    case ENUM_STATE_RECOVER_RESET_AGAIN:
      if ( USBH_PortDisconnected( USBH, Port ) )
        goto RecoverFailed;

      if ( ( Event & DRV_USBH_EVENT_RESET ) == 0 )
        return;

      osDelay( 50 );

      if ( USBH_PortDisconnected( USBH, Port ) )
        goto RecoverFailed;

      if ( USBH_DriverPortReset( USBH, Port ) )
        goto EnumCompleted;

      *PortEnumStatePtr = ENUM_STATE_RECOVER_ENUMERATE;
      return;

    case ENUM_STATE_RECOVER_ENUMERATE:
      if ( USBH_PortDisconnected( USBH, Port ) )
        goto RecoverFailed;

      // Recover Device while Working
      // [ Suspend Resume Reset Enumerate Working ]
      if ( ( Event & DRV_USBH_EVENT_RESET ) == 0 )
        goto EnumerateDevice;

      // Recover Device before Enumerated -- After Port Reset
      // [ Suspend Resume Reset Enumerate Working ]
      USBH->Info->PortReset = 0;
      osDelay( 100 );
      if ( USBH_PortDisconnected( USBH, Port ) )
        goto DeviceDisconnected;

      RetValue = USBH_RecoverEnumerateDevice( USBH, Port );
      if ( RetValue == USB_OK )
      {
        USBH_RecoverThreadEventHandler( USBH, Port,
        DRV_USBH_EVENT_RECOVER_SUCCESS );
        goto EnumCompleted;
      }

      if ( USBH->Info->PortRetry & PortRetryValueReload )
      {
        if ( USBH_PortDisconnected( USBH, Port ) )
          goto RecoverFailed;

        USBH->Info->PortRetry -= PortRetryValueDec;
        goto RecoverTryAgain;
      }

      USBH_RecoverThreadEventHandler( USBH, Port,
      DRV_USBH_EVENT_RECOVER_FAILED );
      goto EnumCompleted;

    case ENUM_STATE_RECOVER_FAILED:
      RecoverFailed: USBH_RecoverThreadEventHandler( USBH, Port,
      DRV_USBH_EVENT_RECOVER_FAILED );
      goto DeviceDisconnected;

    default:
      DeviceDisconnected: //
      USBH->Info->PortConnected &= ~(uint16_t) PortMask;
      USBH->Info->PortDisconnected &= ~(uint16_t) PortMask;
      USBH->Info->PortReset = 0;

      osDelay( 100 );

      HAL_USBH_Pipe_TypeDef * Pipe = USBH->PipeArray;
      for ( uint32_t PipeIndex = 0; PipeIndex < USBH->PipeNum; PipeIndex++ )
      {
        if ( Pipe->Handle && Pipe->TransferThreadId )
        {
          if ( Pipe->HubPort == Port )
          {
            USBH_DriverPipeTransferAbort( USBH, Pipe->Handle );
            USBH_PipeEventHandler( USBH, Pipe->Handle,
            DRV_USBH_EVENT_TRANSFER_ABORT );
          }
        }
        Pipe++;
      }

      osDelay( 100 );

      USBH_UninitializeDevices( USBH, Port );
      *PortEnumStatePtr = ENUM_STATE_CONNECTED;

      // Trigger USBH_CoreThread() to Call USBH_Core() again
      // USBH->HCI->PortEvent[ Port ] != 0x00
      // USBH->HCI->PortEvent[ Port ] be cleared while Call USBH_Core()
      USBH->Info->PortLock = 0;
      osSignalSet( USBH->ThreadId, DRV_USBH_SIGNAL_PORT_EVENT );
  }
}

void USBH_CoreThrad( HAL_USBH_TypeDef * USBH )
{
  osEvent Event;

  uint16_t PortMask;
  uint16_t PortEvent;
  uint16_t DebouncePending;

  uint32_t EventSomething = 0;
  if ( USBH->Capabilities->EventConnect == 0 )
    EventSomething |= DRV_USBH_EVENT_CONNECT;
  if ( USBH->Capabilities->EventDisconnect == 0 )
    EventSomething |= DRV_USBH_EVENT_DISCONNECT;
  //if ( USBH->Capabilities->EventOvercurrent == 0 )
  //  EventSomething |= DRV_USBH_EVENT_OVERCURRENT;

  uint32_t Timeout = osWaitForever;
  if ( EventSomething )
    Timeout = 100;

  while ( 1 )
  {
    DebouncePending = 0;
    Event = osSignalWait( 0, Timeout );

    if ( Event.status == osEventSignal )
    {
      for ( uint32_t Port = 0; Port < 15; Port++ )
      {
        if ( ( USBH->Capabilities->PortMask >> Port ) == 0 )
          break;

        PortMask = ( 1 << Port );
        PortEvent = USBH->Info->PortEvent[ Port ];
        if ( PortEvent == 0 ) // No Event for this port
          continue;

        if ( ( USBH->Info->PortLock == Port + 1 )  //
        || ( USBH->Info->PortLock == 0 ) )         // All Ports Unlocked
        {
          USBH->Info->PortEvent[ Port ] = 0;       // Clear Event

          // Debounce Done : 0x0100 <-- USBH_ConnectDebounce()
          if ( PortEvent & DRV_USBH_EVENT_DEBOUNCED )
          {
            USBH->Info->PortLock = Port + 1;
            USBH_Core( USBH, Port, DRV_USBH_EVENT_CONNECT );
          }

          if ( PortEvent & DRV_USBH_EVENT_CONNECT )
          {
            if ( ( ( USBH->Info->PortConnected & PortMask ) == 0x0000 ) )
              DebouncePending |= PortMask;
          }

          if ( PortEvent & DRV_USBH_EVENT_DISCONNECT )
          {
            if ( ( ( USBH->Info->PortConnected & PortMask ) != 0x0000 ) )
              USBH_Core( USBH, Port, DRV_USBH_EVENT_DISCONNECT );
          }

          if ( PortEvent & DRV_USBH_EVENT_RESET )
          {
            if ( USBH->Info->PortReset == Port + 1 )
              USBH_Core( USBH, Port, DRV_USBH_EVENT_RESET );
          }

          // Retry Enumerate : 0x0200
          if ( PortEvent & DRV_USBH_EVENT_RECOVER_DEVICE )
          {
            USBH->Info->PortLock = Port + 1;
            USBH_Core( USBH, Port, DRV_USBH_EVENT_RECOVER_DEVICE );
          }
        }
      }
    }
    else if ( Event.status == osEventTimeout )
    {
      for ( uint32_t Port = 0; Port < 15; Port++ )
      {
        if ( ( USBH->Capabilities->PortMask >> Port ) == 0 )
          break;

        if ( USBH_DriverPortGetState( USBH, Port ).Connected )
        {
          if ( ( EventSomething & DRV_USBH_EVENT_CONNECT )
            && ( ( USBH->Info->PortConnected & PortMask ) == 0x0000 ) )
          {
            DebouncePending |= PortMask;           // Reload Timer and Start it
          }
        }
        else // ( USBH_DriverPortGetState( USBH, Port ).Connected == 0 )
        {
          if ( ( EventSomething & DRV_USBH_EVENT_DISCONNECT )
            && ( ( ( USBH->Info->PortConnected & PortMask ) != 0x0000 ) ) )
          {
            USBH_Core( USBH, Port, DRV_USBH_EVENT_DISCONNECT );
          }
        }
      }
    }

    if ( 1 )
    {
      if ( DebouncePending ) // Debounce Pending now
      {
        USBH->Info->DebounceReload = 1;              // always reload timer
        uint32_t DebounceIdle = USBH->Info->PortDebounce == 0 ? 1 : 0;
        USBH->Info->PortDebounce |= DebouncePending; // Now Active It
        if ( DebounceIdle ) // Previous Idle But Current DebouncePending
          osTimerStart( USBH->Timer, USBH_DEBOUNCE_INTERVAL );
      }
    }
    else
    {
      // USBH_ConnectDebounce() :
      // if ( HCI->DebounceMaxCountDown == 0 )
      //   USBH->HCI->PortDebounce = 0;
      uint32_t PortDebounce_Is_0 = DebouncePending;
      do
      {
        if ( PortDebounce_Is_0 == 0 )
          break;

        PortDebounce_Is_0 = USBH->Info->PortDebounce == 0 ? 1 : 0;
        USBH->Info->DebounceReload = 1;      // always reload timer
        USBH->Info->PortDebounce |= DebouncePending;
      }while ( PortDebounce_Is_0 == 0 );

      if ( PortDebounce_Is_0 )
        osTimerStart( USBH->Timer, USBH_DEBOUNCE_INTERVAL );
    }
  }
}

