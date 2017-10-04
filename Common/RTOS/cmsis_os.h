#ifndef __OS_H__
#define __OS_H__

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#if !defined SYS_CLOCK
#error SYS_CLOCK must be defined! 
#endif

/******************************************************************************/
/*  Generic OS Config                                                         */
/******************************************************************************/

/* Clock frequency settings : CPU Main clock frequency : SYS_CLOCK */
#define OS_FSYS                                 ( SYS_CLOCK )

/* OS Tick Freq : 1000 HZ */
#define OS_TICK_FREQ                            ( 1000u )

#define OS_MEMF_MAX_ITEMS                       ( 128 )

/* Peripheral clock for timer : SysTick  */
#define OS_PCLK_TIMER                           OS_FSYS

/* Peripheral clock for UART */
#define OS_PCLK_UART                            OS_FSYS

//
// cmsis_main.c : stack size of main()
//
#define OS_MAINSTKSIZE                          ( 128 )

//
// default stack size
//
#define OS_STKSIZE                              ( 512 )

/******************************************************************************/
/* OS Time Defines                                                            */
/******************************************************************************/

// The RTOS kernel system timer frequency in Hz.
#define osKernelSysTickFrequency                ( OS_FSYS )
//
// The RTOS kernel frequency in Hz.
#define osKernelTickFrequency                   ( OS_TICK_FREQ )
//
#define osKernelTickPeriod                      ( 1 / osKernelTickFrequency )
#define osKernelTicksPerSecond                  ( osKernelTickFrequency )
//
#if ( osKernelTickFrequency == 1000 )
#define osKernelTicksPerMilliSec                ( 1 )
#else
#define osKernelTicksPerMilliSec                ( osKernelTickFrequency / 1000 )
#endif
//
// Convert timeout in millisec to system ticks
#if ( osKernelTickFrequency == 1000 )
#define osKernelTicksByMilliSec( millisec )     ( millisec )
#else
#define osKernelTicksByMilliSec( millisec )     ( ( millisec ) * osKernelTicksPerMilliSec )
#endif
//
// Convert timeout in second to system ticks
#define osKernelTicksBySecond( second )         ( ( second ) * osKernelTicksPerSecond )
//
// Convert kernel ticks to millisec
#if ( osKernelTickFrequency == 1000 )
#define osKernelTicks2MilliSec( ticks )         ( ticks )
#else
#define osKernelTicks2MilliSec( ticks )         ( ( ticks ) / osKernelTicksPerMilliSec )
#endif
//
// Convert kernel ticks to second
#define osKernelTicks2Second( ticks )           ( ( ticks ) / osKernelTicksPerSecond )
//
#define osKernelSysTicksPerSecond               ( osKernelSysTickFrequency )
#define osKernelSysTicksPerMilliSec             ( osKernelSysTickFrequency / 1000 )
//
// Convert timeout in millisec to system ticks
#define osKernelSysTicksByMilliSec( millisec )  ( ( millisec ) * osKernelSysTicksPerMilliSec )
//
// Convert timeout in second to system ticks
#define osKernelSysTicksBySecond( second )      ( ( second ) * osKernelSysTicksPerSecond )
//
// Convert system ticks to millisec
#define osKernelSysTicks2MilliSec( ticks )      ( ( ticks ) / osKernelSysTicksPerMilliSec )
//
// Convert system ticks to second
#define osKernelSysTicks2Second( ticks )        ( ( ticks ) / osKernelSysTicksPerSecond )
//
#define osKernelSysTickMicroSec_i  \
  ( osKernelSysTickFrequency / 1000000 )
//
#define osKernelSysTickMicroSec_f  \
  ( ( ( (uint64_t)( osKernelSysTickFrequency - 1000000 * ( osKernelSysTickFrequency / 1000000 ) ) ) << 16 ) / 1000000 )
//
// Convert a microseconds value to a RTOS kernel system timer value.
#define osKernelSysTickMicroSec(microsec)   \
  ( ( microsec * osKernelSysTickMicroSec_i ) + ( ( microsec * osKernelSysTickMicroSec_f ) >> 16 ) )
//
// Convert a milliseconds value to a RTOS kernel system timer value.
#define osKernelSysTickMilliSec(millisec)   \
  osKernelSysTicksByMilliSec(millisec)

/******************************************************************************/
/* OS Feature Config                                                          */
/******************************************************************************/
//
// Main Thread:     1=main can be thread, 0=not available
#define osFeature_MainThread  1
//
// Memory Pools:    1=available, 0=not available
#define osFeature_Pool        1
//
// Mail Queues:     1=available, 0=not available
#define osFeature_MailQ       1
//
// Message Queues:  1=available, 0=not available
#define osFeature_MessageQ    1
//
// osKernelSysTick functions: 1=available, 0=not available
#define osFeature_SysTick     1
//
// osWait function: 1=available, 0=not available
#define osFeature_Wait        0
//
// maximum number of Signal Flags available per thread
// bit31 = 0x80000000 : incorrect parameters
#define osFeature_Signals     31
//
// maximum count for osSemaphoreCreate function
#define osFeature_Semaphore   0xFFFFFFFF

// ==== Enumeration, structures, defines for all ===============================
//
// Timeout value :: wait forever timeout value
//
#define osWaitForever     0xFFFFFFFF
//
// Status code values returned by CMSIS-RTOS functions.
//
typedef enum
{
  // function completed; no error or event occurred.
  osOK = 0,
  //
  // function completed; signal event occurred.
  osEventSignal = 0x08,
  // function completed; message event occurred.
  osEventMessage = 0x10,
  // function completed; mail event occurred.
  osEventMail = 0x20,
  //
  // function completed; timeout occurred.
  osEventTimeout = 0x40,
  //
  // parameter error: a mandatory parameter was missing
  // or specified an incorrect object.
  osErrorParameter = 0x80,
  //
  // resource not available: a specified resource was not available.
  osErrorResource = 0x81,
  // resource not available within given time:
  // a specified resource was not available within the timeout period.
  osErrorTimeoutResource = 0xC1,
  // not allowed in ISR context:
  // the function cannot be called from interrupt service routines.
  osErrorISR = 0x82,
  // function called multiple times from ISR with same object.
  osErrorISRRecursive = 0x83,
  // system cannot determine priority or thread has illegal priority.
  osErrorPriority = 0x84,
  // system is out of memory:
  // it was impossible to allocate or reserve memory for the operation.
  osErrorNoMemory = 0x85,
  // value of a parameter is out of range.
  osErrorValue = 0x86,
  // unspecified RTOS error: run-time error but no other error message fits.
  osErrorOS = 0xFF,
  // prevent from enum down-size compiler optimization.
  // 32 bits for osStatus
  os_status_reserved = 0x7FFFFFFF
} osStatus;
//
// Timer type value for the timer definition.
//
typedef enum
{
  osTimerOnce = 0,            // one-shot timer
  osTimerPeriodic = 1         // repeating timer
} os_timer_type;
//
// Entry point of a thread.
//
typedef void (*os_pthread)( void * argument );

// Entry point of a timer call back function.
//
typedef void (*os_ptimer)( void * argument );
//
//
// ==== Enumeration, structures, defines for embOS =============================
//
// Priority used for thread control :: Higher values indicate higher priorities
//
typedef enum
{
  osPriorityDefault = 0,         // priority: normal (default)
  osPriorityIdle = 1,            // priority: idle (lowest)
  osPriorityLow = 2,             // priority: low
  osPriorityBelowNormal = 3,     // priority: below normal
  osPriorityNormal = 4,          // priority: normal (default)
  osPriorityAboveNormal = 5,     // priority: above normal
  osPriorityHigh = 6,            // priority: high
  osPriorityRealtime = 7,        // priority: realtime (highest)
} osPriority;

/******************************************************************************/
/*  Segger RTOS                                                               */
/******************************************************************************/

#include "RTOS.h"

//
// Thread ID identifies the thread (pointer to a thread control block).
typedef OS_TASK osThread;
typedef osThread * osThreadId;
typedef struct osThreadDef
{
  uint8_t * name;             // name of the thread function.
  void * routine;             // start address of thread function
  osPriority priority;        // initial thread priority
  uint32_t stacksize;         // stack size requirements in bytes
} osThreadDef_t;
//
// Timer ID identifies the timer (pointer to a timer control block).
typedef OS_TIMER_EX osTimer;
typedef osTimer * osTimerId;
//
// Mutex ID identifies the mutex (pointer to a mutex control block).
typedef OS_RSEMA osMutex;
typedef osMutex * osMutexId;
//
// Semaphore ID identifies the semaphore (pointer to a semaphore control block).
typedef OS_CSEMA osSemaphore;
typedef osSemaphore * osSemaphoreId;
//
// Pool ID identifies the memory pool (pointer to a memory pool control block).
typedef OS_MEMF osPool;
typedef osPool * osPoolId;
//
// Message ID identifies the message queue (pointer to a message queue control block).
typedef OS_MAILBOX osMessageQ;
typedef osMessageQ * osMessageQId;
//
// Mail ID identifies the mail queue (pointer to a mail queue control block).
typedef struct _osMailQ
{
  osMessageQId messageId;
  osPoolId poolId;
} osMailQ;
typedef osMailQ * osMailQId;
//
// Event structure contains detailed information about an event.
// However the struct may be extended at the end.
//
typedef struct
{
  osStatus status;     // status code: event or error information

  union
  {
    uint32_t v;         // message as 32-bit value
    void * p;           // message or mail as void pointer
    int32_t signals;    // signal flags
  } value;              // event value

  union
  {
    osMailQId mail_id;        // mail id obtained by osMailCreate
    osMessageQId message_id;  // message id obtained by osMessageCreate
  } def;                      // event definition

} osEvent;

#define OS_EVENT_STATUS(event)                  ( (event).status )
#define OS_EVENT_SIGNAL(event)                  ( (event).value.signals )

//
// ======= Kernel Control Functions ============================================
//
//
// return RTOS kernel time as 32-bit value in milli second
//
//#include "rt_Time.h"
//#define osKernelTickTime                ( os_time / osKernelTicksPerMilliSec )
//
#define osKernelTickCount()               OS_GetTime32()
#define osKernelSysTickCount()            OS_GetTime_Cycles()

#define osGetTickCount()                  \
  ( osKernelTickCount() / osKernelTicksPerMilliSec )

#define osSleep(ms)                       osDelay( ms )
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
void osEnterInterrupt( void );
void osEnterNestableInterrupt( void );

/*
 * Informs RTOS that the end of the interrupt routine has been reached;
 * executes task switching within ISR.
 *
 * If osLeaveInterrupt()is used, it should be the last function to be called
 * in the interrupt handler. If the interrupt has caused a task switch, it will
 * be executed (unless the program which was interrupted was in a critical region).
 *
 */
void osLeaveNestableInterrupt( void );
void osLeaveInterrupt( void );

uint32_t osDisableInterrupt( void );

void osRestoreInterrupt( uint32_t val );
//
// Initialize of the RTOS Kernel to allow peripheral setup
// and creation of other RTOS objects with the functions
void osInitialize( void );
//
// Start the RTOS Kernel and begin thread scheduler.
void osStart( void );
//
// Identifies if the RTOS kernel is started by a call of osStart().
int32_t osRunning( void );
//
// ======= Generic Wait Functions ==============================================
//
// Wait for any event of the type Signal, Message, Mail
// for a specified time period in millisec
osEvent osWait( uint32_t millisec );
//
// Suspends the calling task for a specified period of time
void osDelay( uint32_t millisec );
//
// Suspends the calling task until a specified time
void osDelayUntil( uint32_t time );
//
// ======= Signal Management ===================================================
//
// Get previous signal flags of the specified thread or
// 0x80000000 in case of incorrect parameters.
int32_t osSignalGet( osThreadId threadId );
//
// Set the signal flags of an active thread.
// Return previous signal flags of the specified thread or
// 0x80000000 in case of incorrect parameters.
int32_t osSignalSet( osThreadId threadId, int32_t signals );
//
// Clear the signal flags of an active thread.
// Return previous signal flags of the specified thread or
// 0x80000000 in case of incorrect parameters.
int32_t osSignalClear( osThreadId threadId, int32_t signals );
//
// Suspend the execution of the current RUNNING thread until
// all specified signal flags with the parameter signals are set.
// When this signal flags are already set, the function returns instantly.
// Otherwise the thread is put into the state WAITING.
// Signal flags that are reported as event are automatically cleared.
osEvent osSignalWait( int32_t signals, uint32_t millisec );
//
// ======= Thread Management ===================================================
//
// Start a thread function by adding it to the Active Threads list
// and set it to state READY.
// The thread function receives the argument pointer as function argument
// when the function is started.
// When the priority of the created thread function is higher than the current
// RUNNING thread, the created thread function starts instantly
// and becomes the new RUNNING thread.
//
osThreadId osThreadCreate( uint8_t * name,       // name of the thread function.
  void * routine,             // a routine that should run as thread
  uint32_t priority,          // initial priority
  uint32_t stackSize,         // stack size (in bytes) requirements
  void * argument );          // argument for routine
//
osThreadId osThreadCreateEx(  //
  uint8_t * name,             // name of the thread function.
  void * routine,             // a routine that should run as thread
  uint32_t priority,          // initial priority
  uint32_t stackSize,         // stack size (in bytes) requirements
  osThreadId threadId,        // Thread Control Block is static
  void * stackMemory,         // stack is static
  void * argument );          // argument for routine

//
// Decrements the suspend count of the specified task
// and resumes it, if the suspend count reaches zero.
void osThreadResume( osThreadId threadId );
//
// Suspends the specified task.
// the suspend count of the specified task is incremented.
void osThreadSupsend( osThreadId threadId );
//
// Remove the thread function from the active thread list.
// If the thread is currently RUNNING the execution will stop.
// if threadId is the NULL, the current running thread terminates.
void osThreadTerminate( osThreadId threadId );
void osThreadTerminateEx( osThreadId threadId );
//
// Change the priority of an active thread.
void osThreadSetPriority( osThreadId threadId, osPriority priority );
//
// Get the priority of an active thread.
osPriority osThreadGetPriority( osThreadId threadId );
//
// Get the thread ID of the current running thread.
osThreadId osThreadGetId( void );
//
// Pass control to the next thread that is in state READY.
// If there is no other thread in the state READY, the current thread
// continues execution and no thread switching occurs.
void osThreadYield( void );
//
void osThreadDemo( void );
//
// ======= Timer Management Functions ==========================================
//
// Create a one-shot or periodic timer and associate it with
// a callback function argument (but does not start it).
// The timer is in stopped until it is started with osTimerStart.
osTimerId osTimerCreate( os_ptimer ptimer, os_timer_type type, void * argument );
osTimerId osTimerCreateEx( osTimerId timerId, os_ptimer ptimer,
  os_timer_type type, void * argument );
//
// Start or restart the timer.
osStatus osTimerStart( osTimerId timerId, uint32_t millisec );
//
// Stop the timer.
osStatus osTimerStop( osTimerId timerId );
//
// Stop and Delete the timer object.Delete the timer object.
osStatus osTimerDelete( osTimerId timerId );
osStatus osTimerDeleteEx( osTimerId timerId );
//
// ======= Mutex Management ====================================================
//
// Create and Initialize a Mutex object
osMutexId osMutexCreate( void );
osMutexId osMutexCreateEx( osMutexId mutexId );
//
// Wait until a Mutex becomes available.
osStatus osMutexWait( osMutexId mutex_id, uint32_t millisec );
//
// Release a Mutex that was obtained with osMutexWait.
osStatus osMutexRelease( osMutexId mutex_id );
//
// Delete a Mutex object and releases memory obtained for Mutex handling.
osStatus osMutexDelete( osMutexId mutex_id );
osStatus osMutexDeleteEx( osMutexId mutexId );
//
// ======= Semaphore Management Functions ======================================
//
// Create and initialize a Semaphore object that is used to manage access to
// shared resources. The parameter specifies the number of available resources.
// The initValue 1 creates a binary semaphore.
osSemaphoreId osSemaphoreCreate( int32_t initValue );
osSemaphoreId osSemaphoreCreateEx( osSemaphoreId semaphoreId,
  int32_t initValue );
//
// Wait until a Semaphore token becomes available.
int32_t osSemaphoreWait( osSemaphoreId semaphoreId, uint32_t millisec );
//
// Give a Semaphore token, Increments the count of available semaphore tokens.
osStatus osSemaphoreRelease( osSemaphoreId semaphoreId );
//
// Delete a Semaphore object.
osStatus osSemaphoreDelete( osSemaphoreId semaphoreId );
osStatus osSemaphoreDeleteEx( osSemaphoreId semaphoreId );

//
// ======= Message Queue Management Functions ==================================
//
osMessageQId osMessageCreate( uint32_t msgCount, osThreadId threadId );
osMessageQId osMessageCreateEx( osMessageQId messageQId, void * memory,
  uint32_t msgCount, osThreadId threadId );
osStatus osMessagePut( osMessageQId msgQId, uint32_t info, uint32_t millisec );
osEvent osMessageGet( osMessageQId msgQId, uint32_t millisec );
osStatus osMessageDelete( osMessageQId messageQId );
osStatus osMessageDeleteEx( osMessageQId messageQId );
//
// ============= Memory Management Functions ===================================
//
osStatus osMemoryLock( uint32_t timeout );
void osMemoryUnlock( void );

/*
 * ANSI C offers some basic dynamic memory management functions.
 * These are malloc, free, and realloc. Unfortunately, these routines are
 * not thread-safe, unless a special thread-safe implementation exists
 * in the compiler specific runtime libraries; they can only be used from
 * one task or by multiple tasks if they are called sequentially.
 *
 * Therefore, embOS offer task-safe variants of these routines.
 * These variants have the same names as their ANSI counterparts,
 * but are prefixed OS_; they are called OS_malloc(), OS_free(), OS_realloc().
 *
 * The thread-safe variants that embOS offers use the standard ANSI routines,
 * but they guarantee that the calls are serialized using a resource semaphore.
 *
 * If heap memory management is not supported by the standard C-libraries
 * for a specific CPU, embOS heap memory management is not implemented.
 *
 * Heap type memory management is part of the embOS libraries.
 * It does not use any resources if it is not referenced by the application
 * (that is, if the application does not use any memory management API function).
 *
 * Note that another aspect of these routines may still be a problem:
 * the memory used for the functions (known as heap) may fragment.
 *
 * This can lead to a situation where the total amount of memory is sufficient,
 * but there is not enough memory available in a single block
 * to satisfy an allocation request.
 *
 */

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
void * osMalloc( size_t size, uint32_t timeout );

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
void * osCalloc( size_t nelem, size_t elsize, uint32_t timeout );

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
void * osRealloc( void * ptr, size_t size, uint32_t timeout );

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
void osFree( void * ptr );

//
// ======= Mail Queue Management Functions =====================================
//
osMailQId osMailCreate( uint32_t mailSize, uint32_t mailCount,
  osThreadId threadId );
osMailQId osMailCreateEx( osMailQId mailQId, void * memory, uint32_t mailSize,
  uint32_t mailCount, osThreadId threadId );
void * osMailAlloc( osMailQId mailId, uint32_t millisec );
void * osMailCAlloc( osMailQId mailId, uint32_t millisec );
osStatus osMailPut( osMailQId mailId, void * mail );
osEvent osMailGet( osMailQId mailId, uint32_t millisec );
osStatus osMailFree( osMailQId mailId, void * mail );
osStatus osMailFreeEx( osMailQId mailId, void * mail );
//
// ============= Memory Pool Management Functions ==============================
//
// Create and initialize a fixed block size memory pool.
osPoolId osPoolCreate( uint32_t blockSize, uint32_t blockCount );
//
// Allocate a memory block from the memory pool.
void * osPoolAlloc( osPoolId poolId );
//
// Allocate a memory block from the memory pool and initialize to zero.
void * osPoolCAlloc( osPoolId poolId );
//
// Return a memory block to a memory pool.
osStatus osPoolFree( osPoolId poolId, void * block );
//
// Deletes a fixed block size memory pool
void osPoolDelete( osPoolId poolId );

#endif  // __OS_H__
