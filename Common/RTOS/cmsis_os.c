#include "cmsis_os.h"
#include "macro_misc.h"

static osMutex mutexMemory;
static osMutexId mutexMemoryId;

#if defined(osFeature_MainThread) && (osFeature_MainThread > 0 )

extern int main( void );
extern int __low_level_init( void );
extern void __iar_data_init3( void );
extern void exit( int arg );
static osThread mainThread;
static uint32_t mainStack[ OS_MAINSTKSIZE >> 2 ];
__noreturn void __cmain( void )
{
  if ( __low_level_init( ) != 0 )
    __iar_data_init3( );

  osInitialize( );
  osThreadCreateEx( "main", (void *) main, osPriorityRealtime,
    sizeof( mainStack ), &mainThread, mainStack, 0 );
  osStart( );
  exit( 0 );
}

#endif

static osThread threadHP, threadLP;
static uint32_t stackHP[ OS_MAINSTKSIZE >> 2 ], stackLP[ OS_MAINSTKSIZE >> 2 ];

static void HPTask( void )
{
  while ( 1 )
  {
    osDelay( 50 );
  }
}

static void LPTask( void )
{
  while ( 1 )
  {
    osDelay( 200 );
  }
}

void osThreadDemo( void )
{
  osThreadCreateEx( "HP", (void *) HPTask, 0, sizeof( stackHP ), &threadHP,
    stackHP, 0 );

  osThreadCreateEx( "LP", (void *) LPTask, 0, sizeof( stackLP ), &threadLP,
    stackLP, 0 );
}

// ============= Interrupt Control Functions ===================================
//
uint32_t osDisableInterrupt( void )
{
  __istate_t val = __get_interrupt_state( );
  __disable_interrupt( );
  return (uint32_t) val;

}

void osRestoreInterrupt( uint32_t val )
{
  __set_interrupt_state( (__istate_t ) val );
}

/*
 * Informs RTOS that interrupt code is executing.
 *
 * If osEnterInterrupt() is used, it should be the first function to be called
 * in the interrupt handler. It must be used with osLeaveInterrupt() as the last
 * function called. The use of this function has the following effects, it:
 *
 * disables task switches
 * keeps interrupts in internal routines disabled.
 */
void osEnterInterrupt( void )
{
  OS_EnterInterrupt()
}

void osEnterNestableInterrupt( void )
{
  OS_EnterNestableInterrupt()
}

/*
 * Informs RTOS that the end of the interrupt routine has been reached;
 * executes task switching within ISR.
 *
 * If osLeaveInterrupt()is used, it should be the last function to be called
 * in the interrupt handler. If the interrupt has caused a task switch, it will
 * be executed (unless the program which was interrupted was in a critical region).
 *
 */
void osLeaveNestableInterrupt( void )
{
  OS_LeaveNestableInterrupt()
}

void osLeaveInterrupt( void )
{
  OS_LeaveInterrupt()
}


// ============= Kernel Control Functions ======================================
//
// Initialize the RTOS Kernel for creating objects.
// return : status code that indicates the execution status of the function.
void osInitialize( void )
{
  OS_IncDI();
  OS_InitKern( );
  OS_InitHW( );
}

// Start the RTOS Kernel.
// return : status code that indicates the execution status of the function.
void osStart( void )
{
  if ( OS_Running == 0 )
  {
    OS_StartASM( );
  }
}

// Check if the RTOS kernel is already started.
// return : 0 RTOS is not started, 1 RTOS is started.
//
int32_t osRunning( void )
{
  return OS_IsRunning();
}

// ============= Generic Wait Functions ========================================
//
// Wait for Timeout (Time Delay).
// param[in]   millisec    time delay value
// return : status code that indicates the execution status of the function.
//
void osDelay( uint32_t millisec )
{
  OS_Delay( osKernelTicksByMilliSec( millisec ) );
}

// Suspends the calling task until a specified time
void osDelayUntil( uint32_t time )
{
  OS_DelayUntil( osKernelTicksByMilliSec( time ) );
}

// Generic Wait available
//
// Wait for Signal, Message, Mail, or Timeout.
// param[in] millisec      timeout value or 0 in case of no time-out
// return : event that contains signal, message, or mail information or error code.
// MUST REMAIN UNCHANGED: osWait shall be consistent in every CMSIS-RTOS.
//
osEvent osWait( uint32_t millisec )
{
  osEvent event;
  event.status = osOK;
  event.value.signals = 0;
  return event;
}

// ============= Thread Management =============================================
//
// Create a thread and add it to Active Threads and set it to state READY.
// return : thread ID for reference by other functions or NULL in case of error.
osThreadId osThreadCreate( uint8_t * name,       // name of the thread function.
  void * routine,             // a routine that should run as thread
  uint32_t priority,          // initial priority
  uint32_t stackSize,         // stack size (in bytes) requirements
  void * argument )           // argument for routine
{
  uint32_t size = 0;
  uint32_t * allocMemory;

  void * stackMemory;
  osThreadId threadId;

  if ( stackSize == 0 )
    stackSize = OS_MAINSTKSIZE;
  else
    stackSize = ROUND_DOWN( stackSize, 4 );

  // [ TCB ] [ StackMemory ]
  size = ROUND_UP( sizeof(osThread), 4 ) + stackSize;

  allocMemory = (uint32_t *) osMalloc( size, osWaitForever );
  if ( allocMemory == NULL )
    return NULL;

  // [ TCB ] [ StackMemory ]
  threadId = (osThreadId) allocMemory;
  stackMemory = (void *) ( ( (uint32_t) allocMemory )
    + ROUND_UP( sizeof(osThread), 4 ) );

  return osThreadCreateEx( name, routine, priority, stackSize, threadId,
    stackMemory, argument );
}
//
// time slice value for round-robin scheduling
#define osThreadTimeSlice   (1)
//
osThreadId osThreadCreateEx(  //
  uint8_t * name,             // name of the thread function.
  void * routine,             // a routine that should run as thread
  uint32_t priority,          // initial priority
  uint32_t stackSize,         // stack size (in bytes) requirements
  osThreadId threadId,        // Thread Control Block is static
  void * stackMemory,         // stack is static
  void * argument )           // argument for routine
{
  if ( priority == osPriorityDefault )
    priority = osPriorityNormal;

  if ( stackSize == 0 )
    stackSize = OS_MAINSTKSIZE;
  else
    stackSize = ROUND_DOWN( stackSize, 4 );

  OS_CreateTaskEx( threadId, (char *) name, priority,
    (void (*)( void * )) ( routine ), stackMemory, stackSize,
    osThreadTimeSlice, argument );

  return threadId;
}

void osThreadTerminate( osThreadId threadId )
{
  osThreadTerminateEx( threadId );
  //
  // Free Thread Control Block and Stack created by osThreadCreate()
  osFree( threadId );
}

// Terminate execution of a thread and remove it from Active Threads.
// param[in]   threadId   thread ID obtained by osThreadCreate or osThreadGetId.
// return : status code that indicates the execution status of the function.
void osThreadTerminateEx( osThreadId threadId )
{
#if 0
  // If pTaskis the NULL pointer, the current task terminates.
  if ( threadId == 0 )
  threadId = osThreadGetId( );
#endif

  // The specified task will terminate immediately.
  // The memory used for stack and task control block can be reassigned.
  // If pTask is NULL, the current task terminates.
  OS_TerminateTask( threadId );
}

// Return the thread ID of the current running thread.
// return : thread ID for reference by other functions or NULL in case of error.
osThreadId osThreadGetId( void )
{
  return OS_GetTaskID();
}

// Pass control to next thread that is in state READY.
// return : status code that indicates the execution status of the function.
void osThreadYield( void )
{
  // Calls the scheduler to force a task switch.
  OS_Yield( );
}

// Change priority of an active thread.
// param[in]   threadId   thread ID obtained by osThreadCreate or osThreadGetId.
// param[in]   priority    new priority value for the thread function.
// return : status code that indicates the execution status of the function.
void osThreadSetPriority( osThreadId threadId, osPriority priority )
{
  OS_SetPriority( threadId, priority );
}

// Get current priority of an active thread.
// param[in]   threadId   thread ID obtained by osThreadCreate or osThreadGetId.
// return : current priority value of the thread function.
osPriority osThreadGetPriority( osThreadId threadId )
{
  return (osPriority) OS_GetPriority( threadId );
}

//
// Decrements the suspend count of the specified task
// and resumes it, if the suspend count reaches zero.
void osThreadResume( osThreadId threadId )
{
  OS_Resume( threadId );
}

//
// Suspends the specified task.
// the suspend count of the specified task is incremented.
void osThreadSupsend( osThreadId threadId )
{
  OS_Suspend( threadId );
}
// ============= Timer Management Functions ====================================
//
// Create a timer.
// param[in]   timer_def   timer object referenced with osTimer.
// param[in]   type      osTimerOnce for one-shot or osTimerPeriodic for periodic behavior.
// param[in]   argument    argument to the timer call back function.
// return : timer ID for reference by other functions or NULL in case of error.
// MUST REMAIN UNCHANGED: osTimerCreate shall be consistent in every CMSIS-RTOS.
//
osTimerId osTimerCreate( os_ptimer ptimer, os_timer_type type, void * argument )
{
  // type != osTimerPeriodic
  //
  osTimerId timerId = (osTimerId) osMalloc( sizeof(osTimer), osWaitForever );
  if ( timerId )
    OS_CreateTimerEx( timerId, (OS_TIMER_EX_ROUTINE *) ( ptimer ), -1,
      argument );
  return timerId;
}

osTimerId osTimerCreateEx( osTimerId timerId, os_ptimer ptimer,
  os_timer_type type, void * argument )
{
  // type != osTimerPeriodic
  //
  OS_CreateTimerEx( timerId, (OS_TIMER_EX_ROUTINE *) ( ptimer ), -1, argument );
  return timerId;
}

// Start or restart a timer.
// param[in]   timerId    timer ID obtained by osTimerCreate.
// param[in]   millisec    time delay value of the timer.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osTimerStart shall be consistent in every CMSIS-RTOS.
//
osStatus osTimerStart( osTimerId timerId, uint32_t millisec )
{
  OS_SetTimerPeriodEx( timerId, osKernelTicksByMilliSec( millisec ) );
  OS_RetriggerTimerEx( timerId );
  return osOK;
}

// Stop the timer.
// param[in]   timerId    timer ID obtained by osTimerCreate.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osTimerStop shall be consistent in every CMSIS-RTOS.
//
osStatus osTimerStop( osTimerId timerId )
{
  OS_StopTimerEx( timerId );
  return osOK;
}

// Delete a timer that was created by osTimerCreate.
// param[in]   timerId    timer ID obtained by osTimerCreate.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osTimerDelete shall be consistent in every CMSIS-RTOS.
//
osStatus osTimerDelete( osTimerId timerId )
{
  OS_DeleteTimerEx( timerId );
  osFree( timerId );
  return osOK;
}

osStatus osTimerDeleteEx( osTimerId timerId )
{
  OS_DeleteTimerEx( timerId );
  return osOK;
}
// ============= Signal Management =============================================
//
// Get previous signal flags of the specified thread or
// 0x80000000 in case of incorrect parameters.
int32_t osSignalGet( osThreadId threadId )
{
  int32_t result = OS_GetEventsOccurred( threadId );
  return result;
}

// Set the specified Signal Flags of an active thread.
// param[in]   threadId   thread ID obtained by osThreadCreate or osThreadGetId.
// param[in]   signals     specifies the signal flags of the thread that should be set.
// return : previous signal flags of the specified thread
//          or 0x80000000 in case of incorrect parameters.
// MUST REMAIN UNCHANGED: osSignalSet shall be consistent in every CMSIS-RTOS.
//
int32_t osSignalSet( osThreadId threadId, int32_t signals )
{
  // Returns a list of events that have occurred for a specified task.
  // The event mask of the events that have actually occurred
  // the actual events remain signaled
  //
  int32_t result = OS_GetEventsOccurred( threadId );
  OS_SignalEvent( signals, threadId );
  return result;
}

int32_t OS_ClearEvent( osThreadId threadId, int32_t signals )
{
  if ( threadId == 0 )
    threadId = osThreadGetId( );
  int32_t result = threadId->Events;
#if (1)
  uint32_t val = osDisableInterrupt( );
  threadId->Events &= ~signals;
  osRestoreInterrupt( val );
#else
  OS_DisableInt( );   // MOV.W   R1, #0x80   MSR.W   BASEPRI, R1
  threadId->Events &= ~signals;
  if ( OS_Global.Counters.Cnt.DI == 0 )
  OS_EnableInt( );// MOV.W   R1, #0x00   MSR.W   BASEPRI, R1
#endif
  return result;
}

// Clear the specified Signal Flags of an active thread.
// param[in]   threadId   thread ID obtained by osThreadCreate or osThreadGetId.
// param[in]   signals     specifies the signal flags of the thread that shall be cleared.
// return : previous signal flags of the specified thread
//          or 0x80000000 in case of incorrect parameters.
// MUST REMAIN UNCHANGED: osSignalClear shall be consistent in every CMSIS-RTOS.
//
int32_t osSignalClear( osThreadId threadId, int32_t signals )
{
  // Returns the actual state of events
  // and then clears the events of a specified task.
  // Returns the actual state of events and then
  // clears ** the ALL events ** of a specified task.
  //
  // return OS_ClearEvents( threadId );
  //
  return OS_ClearEvent( threadId, signals );
}

// Wait for one or more Signal Flags to become signaled for the current RUNNING thread.
// param[in]   signals     wait until all specified signal flags set or 0 for any single signal flag.
// param[in]   millisec    timeout value or 0 in case of no time-out.
// return : event flag information or error code.
// MUST REMAIN UNCHANGED: osSignalWait shall be consistent in every CMSIS-RTOS.
//
osEvent osSignalWait( int32_t signals, uint32_t millisec )
{
  osEvent event;
  event.status = osEventSignal;

  // Not allowed in ISR ?
  // event.status = osErrorISR
  //
  // The task is not suspended even if no events are signaled.
  if ( millisec == 0 )
  {
    // Returns a list of events that have occurred for a specified task.
    // The event mask of the events that have actually occurred.
    event.value.signals = OS_GetEventsOccurred( 0 );
  }

  else if ( millisec == osWaitForever )
  {
    if ( signals == 0 ) // Wait forever until any single signal flag
    {
      // Waits for one of the events specified in the bitmask and
      // clears the event memory after an event occurs
      event.value.signals = OS_WaitEvent( 0xFFFFFFFF );
    }

    else // Wait forever until all specified signal flags set
    {
      // Waits for one or more of the events specified by the Eventmask
      // and clears only those events that were specified in the eventmask.
      event.value.signals = OS_WaitSingleEvent( signals );
    }
  }

  else
  {
    if ( signals == 0 ) // Wait millisec until any single signal flag
    {
      // Waits for the specified events for a given time, and clears
      // ** the event memory ** after one of the requsted events occurs,
      // or after the timeout expired.
      event.value.signals = OS_WaitEventTimed( 0xFFFFFFFF,
        osKernelTicksByMilliSec( millisec ) );
    }

    else // Wait millisec until all specified signal flags set
    {
      // Waits for the specified events for a given time; after an event occurs,
      // only ** the requested events ** are cleared.
      event.value.signals = OS_WaitSingleEventTimed( signals,
        osKernelTicksByMilliSec( millisec ) );
    }
  }

  if ( event.value.signals == 0 )
  {
    event.status = ( millisec > 0 ) ? osEventTimeout : osOK;
  }

  return event;
}

// ============= Mutex Management ==============================================
//
/* Resource semaphores are used for managingresources by avoiding conflicts
 * caused by simultaneous use of a resource. The resource managed can be of
 * any kind: a part of the program that is not reentrant, a piece of hardware
 * like the display, a flash prom that can only be written to by a single task
 * at a time, a motor in a CNC control that can only be controlled by one task
 * at a time, and a lot more.
 *
 * The basic procedure is as follows:
 * Any task that uses a resource first claims it calling the OS_Use() or
 * OS_Request() routines of embOS. If the resource is available, the program
 * execution of the task continues, but the resource is blocked for other tasks.
 *
 * If a second task now tries to use the same resource while it is in use
 * by the first task, this second task is suspended until the first task releases
 * the resource. However, if the first task that uses the resource calls
 * OS_Use() again for that resource, it is not suspended because the resource
 * is blocked only for other tasks.
 *
 * A resource semaphore contains a counter that keeps track of how many times
 * the resource has been claimed by calling OS_Request() or OS_Use()
 * by a particular task. It is released when that counter reaches 0,
 * which means the OS_Unuse() routine has to be called exactly the same number
 * of times as OS_Use() or OS_Request(). If it is not, the resource remains
 * blocked for other tasks.
 *
 * On the other hand, a task cannot release a resource that it does not own
 * by calling OS_Unuse().
 *
 * counter = 0 after OS_CreateRSema()
 * counter++ : OS_Use() or OS_Request()
 * counter-- : OS_Unuse()
 *
 * A programmer can prefer mutex rather than creating a semaphore with count 1.
 */
// Create and Initialize a Mutex object.
// param[in]   mutex_def   mutex definition referenced with osMutex.
// return : mutex ID for reference by other functions or NULL in case of error.
// MUST REMAIN UNCHANGED: osMutexCreate shall be consistent in every CMSIS-RTOS.
//
osMutexId osMutexCreate( void )
{
  osMutexId mutexId = (osMutexId) osMalloc( sizeof(osMutex), osWaitForever );
  if ( mutexId )
    OS_CreateRSema( mutexId );
  return mutexId;
}

osMutexId osMutexCreateEx( osMutexId mutexId )
{
  OS_CreateRSema( mutexId );
  return mutexId;
}

// Wait until a Mutex becomes available.
// param[in]   mutexId    mutex ID obtained by osMutexCreate.
// param[in]   millisec    timeout value or 0 in case of no time-out.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osMutexWait shall be consistent in every CMSIS-RTOS.
//
osStatus osMutexWait( osMutexId mutexId, uint32_t millisec )
{
  osStatus status = osOK;

  if ( millisec == 0 )
  {
    if ( OS_Request( mutexId ) == 0 )
    {
      status = osErrorResource;
    }
  }

  else if ( millisec == osWaitForever )
  {
    OS_Use( mutexId );
  }

  else if ( 0 == OS_UseTimed( mutexId, osKernelTicksByMilliSec( millisec ) ) )
  {
    status = osErrorTimeoutResource;
  }

  return status;
}

// Release a Mutex that was obtained by osMutexWait.
// param[in]   mutexId    mutex ID obtained by osMutexCreate.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osMutexRelease shall be consistent in every CMSIS-RTOS.
//
osStatus osMutexRelease( osMutexId mutexId )
{
  OS_Unuse( mutexId );
  return osOK;
}

// Delete a Mutex that was created by osMutexCreate.
// param[in]   mutexId    mutex ID obtained by osMutexCreate.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osMutexDelete shall be consistent in every CMSIS-RTOS.
//
osStatus osMutexDelete( osMutexId mutexId )
{
  OS_DeleteRSema( mutexId );
  osFree( mutexId );
  return osOK;
}

osStatus osMutexDeleteEx( osMutexId mutexId )
{
  OS_DeleteRSema( mutexId );
  return osOK;
}
// ============= Semaphore Management Functions ================================
/* Counting semaphores are counters that are managed by embOS.
 * They are not as widely used as resource semaphores, events or mailboxes,
 * but they can be very useful sometimes.
 *
 * They are used in situations where a task needs to wait for something
 * that can be signaled one or more times.
 *
 * The semaphores can be accessed from any point, any task,
 * or any interrupt in any way.
 *
 * OS_CreateCSema()
 * Creates a counting semaphore with a specified initial count value
 *
 * OS_SignalCSema()
 * Increments the counter of a semaphore.
 * If one or more tasks are waiting for an event to be signaled to this
 * semaphore, the task that has the highest priority will become the running task
 *
 * OS_WaitCSema()
 * Decrements the counter of a semaphore.
 * If the counter of the semaphore is not 0, the counter is decremented
 * and program execution continues.
 * If the counter is 0, WaitCSema()waits until the counter is incremented by
 * another task, a timer or an interrupt handler via a call to OS_SignalCSema().
 * The counter is then decremented and program execution continues.
 *
 * OS_WaitCSemaTimed()
 * Decrements a semaphore counter if the semaphore is available
 * within a specified time.
 * If the semaphore was not signaled within the specified time, the program
 * execution continues but returns a value of 0.
 *
 * OS_CSemaRequest()
 * Decrements the counter of a semaphore, if it is signaled.
 * If the counter is 0, OS_CSemaRequest() does not wait and does not modify
 * the semaphore counter. The function returns with error state.
 *
 */

// Create and Initialize a Semaphore object used for managing resources.
// param[in]   semaphore_def semaphore definition referenced with osSemaphore.
// param[in]   count     number of available resources.
// return : semaphore ID for reference by other functions or NULL in case of error.
// MUST REMAIN UNCHANGED: osSemaphoreCreate shall be consistent in every CMSIS-RTOS.
//
osSemaphoreId osSemaphoreCreate( int32_t initValue )
{
  // Creates a counting semaphore with a specified initial count value.
  osSemaphoreId semaphoreId = (osSemaphoreId) osMalloc( sizeof(osSemaphore),
  osWaitForever );
  if ( semaphoreId )
    OS_CreateCSema( semaphoreId, initValue );
  return semaphoreId;
}

osSemaphoreId osSemaphoreCreateEx( osSemaphoreId semaphoreId,
  int32_t initValue )
{
  // Creates a counting semaphore with a specified initial count value.
  OS_CreateCSema( semaphoreId, initValue );
  return semaphoreId;
}

// Wait until a Semaphore token becomes available.
// param[in]  semaphoreId  semaphore object referenced with osSemaphoreCreate.
// param[in]  millisec      timeout value or 0 in case of no time-out.
// return :   number of available tokens : (tokens after wait) + 1
//            or -1 in case of incorrect parameters.
// MUST REMAIN UNCHANGED: osSemaphoreWait shall be consistent in every CMSIS-RTOS.
//
int32_t osSemaphoreWait( osSemaphoreId semaphoreId, uint32_t millisec )
{
  int32_t result = -1; // OS_WaitCSemaTimed() timeout

  if ( millisec == 0 )
  {
    // Decrements the counter of a semaphore, if it is signaled
    if ( OS_CSemaRequest( semaphoreId ) )
    {
      // Returns the counter value of a specified semaphore
      result = OS_GetCSemaValue( semaphoreId );
    }
  }

  else if ( millisec == osWaitForever )
  {
    // Decrements the counter of a semaphore
    // If the counter of the semaphore is not 0, the counter is decremented
    // and program execution continues.
    // If the counter is 0, WaitCSema() waits until the counter is incremented
    // by another task, a timer or an interrupt handler
    // via a call to OS_SignalCSema().
    OS_WaitCSema( semaphoreId );

    // Returns the counter value of a specified semaphore
    result = OS_GetCSemaValue( semaphoreId );
  }
  // Decrements a semaphore counter if the semaphore is available
  // within a specified time.
  else if ( OS_WaitCSemaTimed( semaphoreId,
    osKernelTicksByMilliSec( millisec ) ) )
  {
    result = OS_GetCSemaValue( semaphoreId );
  }

  return result + 1;
}

/**
 * @brief Give a Semaphore token
 * @param  semaphoreId  semaphore object referenced with osSemaphore.
 * @retval  status code that indicates the execution status of the function.
 */
osStatus osSemaphoreRelease( osSemaphoreId semaphoreId )
{
  // Increments the counter of a semaphore
  // If one or more tasks are waiting for an event to be signaled to
  // this semaphore, the task that has the highest priority will
  // become the running task.
  OS_SignalCSema( semaphoreId );
  return osOK;
}

// Release a Semaphore token.
// param[in]     semaphoreId  semaphore object referenced with osSemaphoreCreate.
// return :  status code that indicates the execution status of the function.
//
osStatus osSemaphoreDelete( osSemaphoreId semaphoreId )
{
  // Deletes a specified semaphore.
  // Before deleting a semaphore, make sure that no task is waiting for it
  // and that notask will signal that semaphore at a later point.
  OS_DeleteCSema( semaphoreId );
  osFree( semaphoreId );
  return osOK;
}

osStatus osSemaphoreDeleteEx( osSemaphoreId semaphoreId )
{
  // Deletes a specified semaphore.
  // Before deleting a semaphore, make sure that no task is waiting for it
  // and that notask will signal that semaphore at a later point.
  OS_DeleteCSema( semaphoreId );
  return osOK;
}

// ============= Message Queue Management Functions =============================

// Create and Initialize a Message Queue.
// param[in]   queue_def   queue definition referenced with osMessageQ.
// param[in]   threadId   thread ID (obtained by osThreadCreate or osThreadGetId) or NULL.
// return : message queue ID for reference by other functions or NULL in case of error.
// MUST REMAIN UNCHANGED: osMessageCreate shall be consistent in every CMSIS-RTOS.
//
osMessageQId osMessageCreate( uint32_t msgCount, osThreadId threadId )
{
  uint32_t messageQSize = ALIGN_UP( sizeof(osMessageQ), 4 );
  uint32_t memorySize = 4 * msgCount;

  osMessageQId messageQId = (osMessageQId) osMalloc( messageQSize + memorySize,
  osWaitForever );
  if ( messageQId )
  {
    void * memory = (void *) ( ( (uint32_t) ( messageQId ) ) + messageQSize );
    OS_CreateMB( messageQId, 4, msgCount, memory );
  }
  return messageQId;
}

osMessageQId osMessageCreateEx( osMessageQId messageQId, void * memory,
  uint32_t msgCount, osThreadId threadId )
{
  OS_CreateMB( messageQId, 4, msgCount, memory );
  return messageQId;
}
// Put a Message to a Queue.
// param[in]   messageQId    message queue ID obtained with osMessageCreate.
// param[in]   info      message information.
// param[in]   millisec    timeout value or 0 in case of no time-out.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osMessagePut shall be consistent in every CMSIS-RTOS.
//
osStatus osMessagePut( osMessageQId messageQId, uint32_t info,
  uint32_t millisec )
{
  osStatus status = osOK;

  if ( millisec == 0 )
  {
    if ( OS_PutMailCond( messageQId, (const void *) &info ) > 0 )
    {
      status = osErrorResource;
    }
  }
  else if ( millisec == osWaitForever )
  {
    OS_PutMail( messageQId, (const void *) &info );
  }
  else
  {
    OS_TIME osKernelTickCountPrev = osKernelTickCount();

    while ( 1 )
    {
      if ( OS_PutMailCond( messageQId, (const void *) &info ) == 0 )
        return status;

      osDelay( 1 );

      if ( ( osKernelTickCount() - osKernelTickCountPrev )
        > osKernelTicksByMilliSec( millisec ) )
        return osErrorTimeoutResource;
    }
  }

  return status;
}

// Get a Message or Wait for a Message from a Queue.
// param[in]   messageQId    message queue ID obtained with osMessageCreate.
// param[in]   millisec    timeout value or 0 in case of no time-out.
// return : event information that includes status code.
// MUST REMAIN UNCHANGED: osMessageGet shall be consistent in every CMSIS-RTOS.
//
osEvent osMessageGet( osMessageQId messageQId, uint32_t millisec )
{
  osEvent event;
  event.status = osEventMessage;

  // The task is not suspended even if no events are signaled.
  if ( millisec == 0 )
  {
    if ( OS_GetMailCond( messageQId, &event.value.v ) > 0 )
    {
      event.status = osOK;
    }
  }

  else if ( millisec == osWaitForever )
  {
    OS_GetMail( messageQId, &event.value.v );
  }

  else if ( OS_GetMailTimed( messageQId, &event.value.v,
    osKernelTicksByMilliSec( millisec ) ) > 0 )
  {
    event.status = osEventTimeout;
  }

  return event;
}

osStatus osMessageDelete( osMessageQId messageQId )
{
  OS_DeleteMB( messageQId );
  osFree( messageQId );
  return osOK;
}

osStatus osMessageDeleteEx( osMessageQId messageQId )
{
  OS_DeleteMB( messageQId );
  return osOK;
}

// ============= Memory Management Functions ===================================

osStatus osMemoryLock( uint32_t timeout )
{
  return osMutexWait( mutexMemoryId, timeout );
}

void osMemoryUnlock( void )
{
  osMutexRelease( mutexMemoryId );
}

/* Allocates a block of size bytes of memory, returning a pointer
 * to the beginning of the block. The content of the newly allocated block of
 * memory is not initialized, remaining with indeterminate values.
 *
 * On success, a pointer to the memory block allocated by the function.
 * The type of this pointer is always void*, which can be cast to the desired
 * type of data pointer in order to be dereferenceable.
 *
 * If the function failed to allocate the requested block of memory,
 * a null pointer is returned.
 *
 */
void * osMalloc( size_t size, uint32_t timeout )
{
  if ( mutexMemoryId == 0 )
  {
    mutexMemoryId = &mutexMemory;
    OS_CreateRSema( mutexMemoryId );
  }

  void * p = 0;
  osStatus status = osMemoryLock( timeout );
  if ( status == osOK )
  {
    p = malloc( size );
    osMemoryUnlock( );
  }
  return p;
}

/* Allocates a block of memory for an array of num elements,
 * each of them size bytes long, and initializes all its bits to zero.
 *
 * The effective result is the allocation of a zero-initialized memory block
 * of (num*size) bytes.
 *
 * On success, a pointer to the memory block allocated by the function.
 * The type of this pointer is always void*, which can be cast to the desired
 * type of data pointer in order to be dereferenceable.
 *
 * If the function failed to allocate the requested block of memory,
 * a null pointer is returned.
 *
 */
void * osCalloc( size_t nelem, size_t elsize, uint32_t timeout )
{
  void * p = osMalloc( nelem * elsize, timeout );

  if ( p )
  {
    memset( p, 0, nelem * elsize );
  }

  return p;
}

/* Changes the size of the memory block pointed to by ptr.
 * The function may move the memory block to a new location (whose address is
 * returned by the function).
 *
 * The content of the memory block is preserved up to the lesser of the new
 * and old sizes, even if the block is moved to a new location.
 *
 * If the new size is larger, the value of the newly allocated portion
 * is indeterminate.
 *
 * In case that ptr is a null pointer, the function behaves like malloc,
 * assigning a new block of size bytes and returning a pointer to its beginning.
 *
 * If the function fails to allocate the requested block of memory,
 * a null pointer is returned, and the memory block pointed to by argument ptr
 * is not deallocated (it is still valid, and with its contents unchanged).
 *
 * A pointer to the reallocated memory block, which may be either the same
 * as ptr or a new location. The type of this pointer is void*, which can be
 * cast to the desired type of data pointer in order to be dereferenceable.
 */
void * osRealloc( void * ptr, size_t size, uint32_t timeout )
{
  void * p = 0;
  osStatus status = osMemoryLock( timeout );
  if ( status == osOK )
  {
    p = realloc( ptr, size );
    osMemoryUnlock( );
  }
  return p;
}

/* A block of memory previously allocated by a call to malloc, calloc or realloc
 * is deallocated, making it available again for further allocations.
 *
 * If ptr does not point to a block of memory allocated with the above functions
 * it causes undefined behavior.
 * If ptr is a null pointer, the function does nothing.
 *
 * Notice that this function does not change the value of ptr itself,
 * hence it still points to the same (now invalid) location.
 *
 */
void osFree( void * ptr )
{
  osMemoryLock( osWaitForever );
  free( ptr );
  osMemoryUnlock( );
}

// ============= Mail Queue Management Functions ===============================

// Mail Queues available
// Create and Initialize mail queue.
// param[in]   queue_def   reference to the mail queue definition obtain with osMailQ
// param[in]   threadId   thread ID (obtained by osThreadCreate or osThreadGetId) or NULL.
// return : mail queue ID for reference by other functions or NULL in case of error.
// MUST REMAIN UNCHANGED: osMailCreate shall be consistent in every CMSIS-RTOS.
//
osMailQId osMailCreate( uint32_t mailSize, uint32_t mailCount,
  osThreadId threadId )
{
  osMailQId mailQId = (osMailQId) osMalloc( ALIGN_UP( sizeof(osMailQ), 4 ),
  osWaitForever );
  if ( mailQId )
  {
    mailQId->messageId = osMessageCreate( mailCount, threadId );
    if ( mailQId->messageId )
    {
      mailQId->poolId = osPoolCreate( mailSize, mailCount );
      if ( mailQId->poolId == 0 )
        osFree( mailQId->messageId );
    }
    else
    {
      osFree( mailQId );
      mailQId = 0;
    }
  }
  return mailQId;
}

osMailQId osMailCreateEx( osMailQId mailQId, void * memory, uint32_t mailSize,
  uint32_t mailCount, osThreadId threadId )
{
  mailQId->messageId = osMessageCreateEx( mailQId->messageId, memory, mailCount,
    threadId );
  if ( mailQId->messageId )
  {
    mailQId->poolId = osPoolCreate( mailSize, mailCount );
    if ( mailQId->poolId == 0 )
      osFree( mailQId->messageId );
  }
  else
  {
    osFree( mailQId );
    mailQId = 0;
  }
  return mailQId;
}

// Allocate a memory block from a mail.
// param[in]   messageQId    mail queue ID obtained with osMailCreate.
// param[in]   millisec    timeout value or 0 in case of no time-out
// return : pointer to memory block that can be filled with mail or NULL in case of error.
// MUST REMAIN UNCHANGED: osMailAlloc shall be consistent in every CMSIS-RTOS.
//
void * osPoolRequest( osPoolId poolId );
void * osPoolAllocTimed( osPoolId poolId, uint32_t millisec );
void * osMailAlloc( osMailQId messageQId, uint32_t millisec )
{
  void * p;

  if ( millisec == 0 )
  {
    p = osPoolRequest( messageQId->poolId );
  }

  else if ( millisec == osWaitForever )
  {
    p = osPoolAlloc( messageQId->poolId );
  }

  else
  {
    p = osPoolAllocTimed( messageQId->poolId, millisec );
  }

  return p;
}

// Allocate a memory block from a mail and set memory block to zero.
// param[in]   messageQId    mail queue ID obtained with osMailCreate.
// param[in]   millisec    timeout value or 0 in case of no time-out
// return : pointer to memory block that can be filled with mail or NULL in case of error.
// MUST REMAIN UNCHANGED: osMailCAlloc shall be consistent in every CMSIS-RTOS.
//
void * osMailCAlloc( osMailQId messageQId, uint32_t millisec )
{
  void * p = osMailAlloc( messageQId, millisec );

  if ( p )
  {
    memset( p, 0, messageQId->poolId->BlockSize );
  }

  return p;
}

// Put a mail to a queue.
// param[in]   messageQId    mail queue ID obtained with osMailCreate.
// param[in]   mail      memory block previously allocated with osMailAlloc or osMailCAlloc.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osMailPut shall be consistent in every CMSIS-RTOS.
//
osStatus osMailPut( osMailQId messageQId, void * mail )
{
  return osMessagePut( messageQId->messageId, (uint32_t) mail, osWaitForever );
}

// Get a mail from a queue.
// param[in]   messageQId    mail queue ID obtained with osMailCreate.
// param[in]   millisec    timeout value or 0 in case of no time-out
// return : event that contains mail information or error code.
// MUST REMAIN UNCHANGED: osMailGet shall be consistent in every CMSIS-RTOS.
//
osEvent osMailGet( osMailQId messageQId, uint32_t millisec )
{
  osEvent event = osMessageGet( messageQId->messageId, millisec );

  if ( event.status == osEventMessage )
  {
    event.status = osEventMail;
  }

  return event;
}

// Free a memory block from a mail.
// param[in]   messageQId    mail queue ID obtained with osMailCreate.
// param[in]   mail      pointer to the memory block that was obtained with osMailGet.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osMailFree shall be consistent in every CMSIS-RTOS.
//
osStatus osMailFree( osMailQId messageQId, void * mail )
{
  return osPoolFree( messageQId->poolId, mail );
}

osStatus osMailFreeEx( osMailQId messageQId, void * mail )
{
  return osOK;
}

// ============= Memory Pool Management Functions ==============================

// Create and Initialize a memory pool.
// param[in]   pool_def    memory pool definition referenced with osPool.
// return : memory pool ID for reference by other functions or NULL in case of error.
// MUST REMAIN UNCHANGED: osPoolCreate shall be consistent in every CMSIS-RTOS.
//
osPoolId osPoolCreate( uint32_t blockSize, uint32_t blockCount )
{
  uint32_t poolSizeAlign4 = ALIGN_UP( sizeof(osPool), 4 );
  uint32_t poolMemorySizeAlign4 = ALIGN_UP( OS_MEMF_SIZEOF_BLOCKCONTROL, 4 );
  poolMemorySizeAlign4 += ALIGN_UP( blockSize, 4 ) * blockCount;

  osPoolId poolId = (osPoolId) osMalloc( poolSizeAlign4 + poolMemorySizeAlign4,
  osWaitForever );
  if ( poolId )
  {
    void * pool = (void *) ( ( (uint32_t) ( poolId ) ) + poolSizeAlign4 );
    OS_MEMF_Create( poolId, pool, blockCount, blockSize );
  }
  return poolId;
}

// Allocate a memory block from a memory pool.
// param[in]   poolId     memory pool ID obtain referenced with osPoolCreate.
// return : address of the allocated memory block or NULL in case of no memory available.
// MUST REMAIN UNCHANGED: osPoolAlloc shall be consistent in every CMSIS-RTOS.
//
// Requests allocation of a memory block.
// Waits until a block of memory is available
// If there is no free memory block in the pool, the calling task is suspended
// until a memory block becomes available.
//
void * osPoolAlloc( osPoolId poolId )
{
  return OS_MEMF_Alloc( poolId, 0 );
}

// Requests allocation of a memory block. Waits until a block of memory
// is available or the timeout has expired.
//
void * osPoolAllocTimed( osPoolId poolId, uint32_t millisec )
{
  return OS_MEMF_AllocTimed( poolId, osKernelTicksByMilliSec( millisec ), 0 );
}

// Requests allocation of a memory block. Continues execution in any case.
// The calling task is never suspended by calling OS_MEMF_Request()
//
void * osPoolRequest( osPoolId poolId )
{
  return OS_MEMF_Request( poolId, 0 );
}

// Allocate a memory block from a memory pool and set memory block to zero.
// param[in]   poolId     memory pool ID obtain referenced with osPoolCreate.
// return : address of the allocated memory block or NULL in case of no memory available.
// MUST REMAIN UNCHANGED: osPoolCAlloc shall be consistent in every CMSIS-RTOS.
void * osPoolCAlloc( osPoolId poolId )
{
  void * p = osPoolAlloc( poolId );

  if ( p )
  {
    memset( p, 0, poolId->BlockSize );
  }

  return p;
}

// Return an allocated memory block back to a specific memory pool.
// param[in]   poolId     memory pool ID obtain referenced with osPoolCreate.
// param[in]   block     address of the allocated memory block that is returned to the memory pool.
// return : status code that indicates the execution status of the function.
// MUST REMAIN UNCHANGED: osPoolFree shall be consistent in every CMSIS-RTOS.
osStatus osPoolFree( osPoolId poolId, void * block )
{
  OS_MEMF_Release( poolId, block );
  osFree( poolId );
  return osOK;
}
