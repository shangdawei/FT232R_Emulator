/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 1995 - 2016 SEGGER Microcontroller GmbH & Co. KG         *
*                                                                    *
*     Internet: segger.com   Support: support_embos@segger.com       *
*                                                                    *
**********************************************************************
*                                                                    *
*       embOS * Real time operating system for microcontrollers      *
*                                                                    *
*                                                                    *
*       Please note:                                                 *
*                                                                    *
*       Knowledge of this file may under no circumstances            *
*       be used to write a similar product or a real-time            *
*       operating system for in-house use.                           *
*                                                                    *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       OS version: 4.22                                             *
*                                                                    *
**********************************************************************

----------------------------------------------------------------------
File    : RTOSInit_STM32F4x_CMSIS.c for STM32F4x

Purpose : Initializes and handles the hardware for embOS as far
          as required by embOS
          Feel free to modify this file acc. to your target system.
--------  END-OF-HEADER  ---------------------------------------------
*/

#include "RTOS.h"
#include "SEGGER_SYSVIEW.h"
#include "stm32f4xx.h"  // Device specific header file, contains CMSIS

/*********************************************************************
*
*       Configuration
*
**********************************************************************
*/

/*********************************************************************
*
*       Clock frequency settings (configuration)
*/
#ifndef   OS_FSYS                   /* CPU Main clock frequency     */
  #define OS_FSYS SystemCoreClock
#endif

#ifndef   OS_PCLK_TIMER             /* Peripheral clock for timer   */
  #define OS_PCLK_TIMER (OS_FSYS)   /* May vary from CPU clock      */
#endif                              /* depending on CPU             */

#ifndef   OS_PCLK_UART              /* Peripheral clock for UART    */
  #define OS_PCLK_UART (OS_FSYS)    /* May vary from CPU clock      */
#endif                              /* depending on CPU             */

#ifndef   OS_TICK_FREQ
  #define OS_TICK_FREQ (1000u)
#endif

/*********************************************************************
*
*       Configuration of communication to embOSView
*/
#ifndef   OS_VIEW_ENABLE            // Global enable of communication
  #define OS_VIEW_ENABLE    (1)     // Default: on
#endif

#ifndef   OS_VIEW_USE_UART          // If set, UART will be used for communication
  #define OS_VIEW_USE_UART  (0)     // Default: 0 => memory access is used
#endif                              // if OS_VIEW_ENABLE is on

/*********************************************************************
*
*       UART settings for embOSView
*       If you do not want (or can not due to hardware limitations)
*       to dedicate a UART to embOSView, please define it to be -1
*       Currently the standard code enables OS_UART 3 per default.
*       UART 3 is configured to be used on STM3240G Eval board.
*       UART 6 is configured to be used on STM32F401xC-Discovery evalboard.
*       OS_UART=3: RS232 on STM3240G_Eval (CN16 USART)
*       OS_UART=6: Pins TX PC6 / RX PC7 on STM32F401xC-Discovery
*/
#ifndef   OS_UART
  #define OS_UART (3)
#endif

#ifndef   OS_BAUDRATE
  #define OS_BAUDRATE (38400)
#endif

/*********************************************************************
*
*       Configuration of systemView
*/
#ifndef   SEGGER_SYSVIEW_SINGLE_SHOT     /* Should normally be defined as project option */
  #define SEGGER_SYSVIEW_SINGLE_SHOT  (0)
#endif

/****** End of configurable options *********************************/

/*********************************************************************
*
*       Check configuration
*
**********************************************************************
*/
#ifndef   DEBUG     /* Should normally be defined as project option */
  #define DEBUG  (0)
#endif

/*********************************************************************
*
*       JLINKMEM and UART settings for embOSView
*
*       Automatically generated from configuration settings
*/
#define OS_USE_JLINKMEM   (OS_VIEW_ENABLE && (OS_VIEW_USE_UART == 0))

#define OS_UART_USED      (OS_VIEW_ENABLE && (OS_VIEW_USE_UART != 0) && ((OS_UART == 3) || (OS_UART == 6)))

#if OS_USE_JLINKMEM
  #include "JLINKMEM.h"
#endif

/****** MAP UART initialization function ****************************/

#if  (OS_UART_USED || OS_USE_JLINKMEM)
  #define OS_COM_INIT() OS_COM_Init()
#else
  #define OS_COM_INIT()
#endif

/*********************************************************************
*
*       Vector table
*/
#if (defined __SES_ARM)           // SEGGER Embedded Studio
  extern int _vectors;
  #define __Vectors    _vectors
#elif (defined __CROSSWORKS_ARM)  // Rowley CrossStudio
  extern int _vectors;
  #define __Vectors    _vectors
#elif (defined __ICCARM__)        // IAR
  #define __Vectors    __vector_table
#elif (defined __GNUC__)          // GCC
  extern unsigned char __Vectors;
#elif (defined __CC_ARM)          // KEIL
  extern unsigned char __Vectors;
#endif

/*********************************************************************
*
*       Local defines (sfrs and addresses used in RTOSInit.c)
*
**********************************************************************
*/
#define NVIC_VTOR         (*(volatile OS_U32*) (0xE000ED08uL))

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

#if OS_USE_JLINKMEM
  // Size of the communication buffer for JLINKMEM
const OS_U32 OS_JLINKMEM_BufferSize = 32u;
#else
const OS_U32 OS_JLINKMEM_BufferSize = 0;     // Communication not used
#endif

/*********************************************************************
*
*       Local functions
*
**********************************************************************
*/

/*********************************************************************
*
*       _OS_GetHWTimerCycles()
*
* Function description
*   Returns the current hardware timer count value
*
* Return value
*   Current timer count value
*/
static unsigned int _OS_GetHWTimerCycles(void) {
  return SysTick->VAL;
}

/*********************************************************************
*
*       _OS_GetHWTimer_IntPending()
*
* Function description
*   Returns if the hardware timer interrupt pending flag is set
*
* Return value
*   == 0; Interrupt pending flag not set
*   != 0: Interrupt pending flag set
*/
static unsigned int _OS_GetHWTimer_IntPending(void) {
  return SCB->ICSR & SCB_ICSR_PENDSTSET_Msk;
}

/*********************************************************************
*
*       Global functions
*
**********************************************************************
*/

/*********************************************************************
*
*       OS_GetPClkTimer()
*
* Function description
*   Helper function for Percepio embOS-Trace
*/
OS_U32 OS_GetPClkTimer(void) {
  return OS_PCLK_TIMER;
}

/*********************************************************************
*
*       OS_GetTickFreq()
*
* Function description
*   Helper function for Percepio embOS-Trace
*/
OS_U32 OS_GetTickFreq(void) {
  return OS_TICK_FREQ;
}

/*********************************************************************
*
*       SysTick_Handler()
*
* Function description
*   This is the code that gets called when the processor receives a
*   _SysTick exception. SysTick is used as OS timer tick.
*/
#ifdef __cplusplus
extern "C" {
#endif
void SysTick_Handler(void);      // Avoid warning, Systick_Handler is not prototyped in any CMSIS header
#ifdef __cplusplus
}
#endif
void SysTick_Handler(void) {
  OS_EnterNestableInterrupt();
  OS_TICK_Handle();
  #if OS_USE_JLINKMEM
    JLINKMEM_Process();
  #endif
  OS_LeaveNestableInterrupt();
}

/*********************************************************************
*
*       OS_InitHW()
*
*       Initialize the hardware (timer) required for the OS to run.
*       May be modified, if an other timer should be used
*/
void OS_InitHW(void) {
  //
  // Structure with information about timer frequency, tick frequency, etc.
  // for micro second precise system time.
  // SysTimerConfig.TimerFreq will be set later, thus it is initialized with zero.
  //
  OS_SYSTIMER_CONFIG SysTimerConfig = {0, OS_TICK_FREQ, 0, _OS_GetHWTimerCycles, _OS_GetHWTimer_IntPending};

  OS_IncDI();
  //
  // We assume, the PLL and core clock was already set by the SystemInit() function
  // which was called from the startup code
  // Therefore, we don't have to initialize any hardware here,
  // we just ensure that the system clock variable is updated and then
  // set the periodic system timer tick for embOS.
  //
  SystemCoreClockUpdate();                             // Update the system clock variable (might not have been set before)
  if (SysTick_Config (OS_PCLK_TIMER / OS_TICK_FREQ)) { // Setup SysTick Timer for 1 msec interrupts
    while (1);                                         // Handle Error
  }
  //
  // Initialize NVIC vector base address. Might be necessary for RAM targets or application not running from 0
  //
  NVIC_VTOR = (OS_U32)&__Vectors;
  //
  // Set the interrupt priority for the system timer to 2nd lowest level to ensure the timer can preempt PendSV handler
  //
  NVIC_SetPriority(SysTick_IRQn, (1u << __NVIC_PRIO_BITS) - 2u);
  //
  // Setup values for usec precise system time functions
  //
  SysTimerConfig.TimerFreq = SystemCoreClock;
  OS_Config_SysTimer(&SysTimerConfig);
  //
  // Configure and initialize SEGGER SystemView
  //
#if OS_PROFILE
  SEGGER_SYSVIEW_Conf();
  //
  // The following call is required when using SEGGER SystemView
  // in single-shot mode, e.g. when using ST-Link instead of J-Link
  //
#if SEGGER_SYSVIEW_SINGLE_SHOT
  SEGGER_SYSVIEW_Start();
#endif
#endif

  OS_COM_INIT();
  OS_DecRI();
}

/*********************************************************************
*
*       OS_Idle()
*
*       Please note:
*       This is basically the "core" of the idle loop.
*       This core loop can be changed, but:
*       The idle loop does not have a stack of its own, therefore no
*       functionality should be implemented that relies on the stack
*       to be preserved. However, a simple program loop can be programmed
*       (like toggling an output or incrementing a counter)
*/
void OS_Idle(void) {     // Idle loop: No task is ready to execute
  while (1) {
    #if ((OS_USE_JLINKMEM == 0) && (DEBUG == 0))     // Enter CPU halt mode when not in DEBUG build and J-Link communication not used
      __WFI();
    #endif
  }
}

/*********************************************************************
*
*       OS_GetTime_Cycles()
*
*       This routine is required for task-info via embOSView or high
*       resolution time measurement functions.
*       It returns the system time in timer clock cycles.
*/
OS_U32 OS_GetTime_Cycles(void) {
  OS_U32 Time;
  OS_U32 Cnt;

  Time = OS_GetTime32();
  Cnt  = (OS_PCLK_TIMER/1000u) - SysTick->VAL;
  //
  // Check if timer interrupt pending ...
  //
  if (SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) {
    Cnt = (OS_PCLK_TIMER/1000u) - SysTick->VAL;     // Interrupt pending, re-read timer and adjust result
    Time++;
  }
  return ((OS_PCLK_TIMER/1000u) * Time) + Cnt;
}

/*********************************************************************
*
*       OS_ConvertCycles2us()
*
*       Convert Cycles into micro seconds.
*
*       If your clock frequency is not a multiple of 1 MHz,
*       you may have to modify this routine in order to get proper
*       diagnostics.
*
*       This routine is required for profiling or high resolution time
*       measurement only. It does not affect operation of the OS.
*/
OS_U32 OS_ConvertCycles2us(OS_U32 Cycles) {
  return Cycles/(OS_PCLK_TIMER/1000000u);
}

/*********************************************************************
*
*       Optional communication with embOSView
*
**********************************************************************
*/

#if OS_USE_JLINKMEM                    // Communication via JTAG / SWD

static void _JLINKMEM_OnRx(OS_U8 Data);
static void _JLINKMEM_OnTx(void);
static OS_INT _JLINKMEM_GetNextChar(void);

/*********************************************************************
*
*       _JLINKMEM_OnRx()
*/
static void _JLINKMEM_OnRx(OS_U8 Data) {
  OS_OnRx(Data);
}

/*********************************************************************
*
*       _JLINKMEM_OnTx()
*/
static void _JLINKMEM_OnTx(void) {
  OS_OnTx();
}

/*********************************************************************
*
*       _JLINKMEM_GetNextChar()
*/
static OS_INT _JLINKMEM_GetNextChar(void) {
  return OS_COM_GetNextChar();
}

/*********************************************************************
*
*       OS_COM_Init()
*       Initialize memory access for embOSView
*/
void OS_COM_Init(void) {
  JLINKMEM_SetpfOnRx(_JLINKMEM_OnRx);
  JLINKMEM_SetpfOnTx(_JLINKMEM_OnTx);
  JLINKMEM_SetpfGetNextChar(_JLINKMEM_GetNextChar);
}

/*********************************************************************
*
*       OS_COM_Send1()
*       Send one character via memory
*/
void OS_COM_Send1(OS_U8 c) {
  JLINKMEM_SendChar(c);
}

#elif OS_UART_USED   // Communication via UART, can not be implemented generic
/*********************************************************************
*
*       Optional communication with embOSView
*
**********************************************************************
*/
#define ISR_ID_USART3         USART3_IRQn                      // USART3 ID = 39
#define ISR_ID_USART6         USART6_IRQn                      // USART6 ID = 71

#define USART3_BASE_ADDR      (0x40004800uL)                   // USART3 base address
#define USART6_BASE_ADDR      (0x40011400uL)                   // USART6 base address

#define OS_BRR_VALUE3         (OS_PCLK_UART / OS_BAUDRATE / 4) // USART3 uses PCKL1 = HCKL / 4
#define OS_BRR_VALUE6         (OS_PCLK_UART / OS_BAUDRATE)     // USART6 uses PCKL1

#define USART3_SR             (*(volatile OS_U32*)(USART3_BASE_ADDR + 0x00))
#define USART3_DR             (*(volatile OS_U32*)(USART3_BASE_ADDR + 0x04))
#define USART3_BRR            (*(volatile OS_U32*)(USART3_BASE_ADDR + 0x08))
#define USART3_CR1            (*(volatile OS_U32*)(USART3_BASE_ADDR + 0x0C))
#define USART6_SR             (*(volatile OS_U32*)(USART6_BASE_ADDR + 0x00))
#define USART6_DR             (*(volatile OS_U32*)(USART6_BASE_ADDR + 0x04))
#define USART6_BRR            (*(volatile OS_U32*)(USART6_BASE_ADDR + 0x08))
#define USART6_CR1            (*(volatile OS_U32*)(USART6_BASE_ADDR + 0x0C))

#define RCC_BASE_ADDR         ((OS_U32)0x40023800uL)
#define RCC_APB1ENR           (*(volatile OS_U32*)(RCC_BASE_ADDR + 0x40))
#define RCC_APB2ENR           (*(volatile OS_U32*)(RCC_BASE_ADDR + 0x44))
#define RCC_AHB1ENR           (*(volatile OS_U32*)(RCC_BASE_ADDR + 0x30))

#define GPIOC_BASE_ADDR       ((OS_U32)0x40020800uL)
#define GPIOC_MODER           (*(volatile OS_U32*)(GPIOC_BASE_ADDR + 0x00))
#define GPIOC_OTYPER          (*(volatile OS_U32*)(GPIOC_BASE_ADDR + 0x04))
#define GPIOC_OSPEEDR         (*(volatile OS_U32*)(GPIOC_BASE_ADDR + 0x08))
#define GPIOC_PUPDR           (*(volatile OS_U32*)(GPIOC_BASE_ADDR + 0x0C))
#define GPIOC_AF_LOW          (*(volatile OS_U32*)(GPIOC_BASE_ADDR + 0x20))
#define GPIOC_AF_HIGH         (*(volatile OS_U32*)(GPIOC_BASE_ADDR + 0x24))

#define GPIOD_BASE_ADDR       ((OS_U32)0x40020C00uL)
#define GPIOD_MODER           (*(volatile OS_U32*)(GPIOD_BASE_ADDR + 0x00))
#define GPIOD_OTYPER          (*(volatile OS_U32*)(GPIOD_BASE_ADDR + 0x04))
#define GPIOD_OSPEEDR         (*(volatile OS_U32*)(GPIOD_BASE_ADDR + 0x08))
#define GPIOD_PUPDR           (*(volatile OS_U32*)(GPIOD_BASE_ADDR + 0x0C))
#define GPIOD_AF_LOW          (*(volatile OS_U32*)(GPIOD_BASE_ADDR + 0x20))
#define GPIOD_AF_HIGH         (*(volatile OS_U32*)(GPIOD_BASE_ADDR + 0x24))

#define US_RXRDY              (0x20u)  // RXNE
#define USART_RX_ERROR_FLAGS  (0x0Fu)  // ORE/NE/FE/PE
#define US_TXEMPTY            (0x80u)  // TXE

/*********************************************************************
*
*       USART3_IRQHandler
*
* Function description
*   The communication interrupt handler for UART communication
*   to embOSView.
*/
#if (defined __GNUC__)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable" // Avoid variable 'Dummy' set but not used warning
#endif
#if (OS_UART == 6)
void USART6_IRQHandler(void);
void USART6_IRQHandler(void) {
#else
void USART3_IRQHandler(void);
void USART3_IRQHandler(void) {
#endif
  volatile OS_U32 Dummy;
  int UsartStatus;
  OS_EnterNestableInterrupt();
  #if (OS_UART == 6)
  UsartStatus = USART6_SR;                       // Examine status register
  #else
  UsartStatus = USART3_SR;                       // Examine status register
  #endif
  do {
    if (UsartStatus & US_RXRDY) {                // Data received?
      if (UsartStatus & USART_RX_ERROR_FLAGS) {  // Any error ?
        #if (OS_UART == 6)
        Dummy = USART6_DR;                       // => Discard data
        #else
        Dummy = USART3_DR;                       // => Discard data
        #endif
      } else {
        #if (OS_UART == 6)
        OS_OnRx(USART6_DR);                      // Process actual byte
        #else
        OS_OnRx(USART3_DR);                      // Process actual byte
        #endif
      }
    }
    #if (OS_UART == 6)
    UsartStatus = USART6_SR;                     // Examine status register
    #else
    UsartStatus = USART3_SR;                     // Examine status register
    #endif
  } while (UsartStatus & US_RXRDY);
  if (UsartStatus & US_TXEMPTY) {
    if (OS_OnTx()) {                             // No more characters to send ?
      #if (OS_UART == 6)
      USART6_CR1 &= ~0x40uL;                     // Disable further tx interrupts
      #else
      USART3_CR1 &= ~0x40uL;                     // Disable further tx interrupts
      #endif
    }
  }
  OS_LeaveNestableInterrupt();
}
#if (defined __GNUC__)
  #pragma GCC diagnostic pop
#endif

/*********************************************************************
*
*       OS_COM_Send1()
*
*       Sends one character via UART. Never call this from your application
*/
void OS_COM_Send1(OS_U8 c) {
  #if (OS_UART == 6)
  USART6_DR   = (c & (OS_U16)0x01FF);
  USART6_CR1 |= 0x40;                           // Enable tx interrupt
  #else
  USART3_DR   = (c & (OS_U16)0x01FF);
  USART3_CR1 |= 0x40;                           // Enable tx interrupt
  #endif
}

/*********************************************************************
*
*       OS_COM_Init()
*
*       Initialize the selected UART
*/
void OS_COM_Init(void) {
  //
  // Initialize clock and port for USART, selection specific
  //
  OS_IncDI();
  #if (OS_UART == 6)
  RCC_AHB1ENR   |= (1uL << 2);               // GPIOC CLK enable
  RCC_APB2ENR   |= (1uL << 5);               // Enable USART6 clock
                                             // GPIOC set alternate function for USART6
  GPIOC_AF_LOW  = (8uL << 24 )               // - Set pin_6 to AF7
                | (8uL << 28);               // - Set pin_7 to AF7
                                             // GPIOC alternate function mode
  GPIOC_MODER   = (2uL << 12)                // - Pin_6 AF
                | (2uL << 14);               // - Pin_7 AF
                                             // GPIOC speed setting
  GPIOC_OSPEEDR = (2uL << 12)                // - Pin_6 fast speed
                | (2uL << 14);               // - Pin_7 fast speed
  GPIOC_OTYPER  = 0x0;                       // Output type: push-pull for pin_2 and pin_3
                                             // Pull-up/pull-down register
  GPIOC_PUPDR   = (1uL << 12)                // - Pin_6 pull-up
                | (1uL << 14);               // - Pin_7 pull-up
  //
  // USART6 settings
  //
  USART6_CR1 = (1uL << 3)                    // Transmitter enable
             | (1uL << 2)                    // Receiver enable
             | (1uL << 5);                   // RX interrupt enable
  USART6_BRR = OS_BRR_VALUE;                 // Set baudrate
  USART6_CR1 |= (1uL << 13);                 // Enable USART
  NVIC_SetPriority(ISR_ID_USART6, (1u << __NVIC_PRIO_BITS) - 4u);
  NVIC_EnableIRQ(ISR_ID_USART6);
  #else
  RCC_AHB1ENR   |= (1uL <<  2);              // GPIO CLK enable
  RCC_APB1ENR   |= (1uL << 18);              // Enable USART3 clock
                                             // GPIOC set alternate function for USART3
  GPIOC_AF_HIGH = (7uL <<  8)                // - Set pin_10 to AF7
                | (7uL << 12);               // - Set pin_11 to AF7
                                             // GPIOC alternate function mode
  GPIOC_MODER   = (2uL << 20)                // - Pin_10 AF
                | (2uL << 22);               // - Pin_11 AF
                                             // GPIOC speed setting
  GPIOC_OSPEEDR = (2uL << 20)                // - Pin_10 fast speed
                | (2uL << 22);               // - Pin_11 fast speed
  GPIOC_OTYPER  = 0x0;                       // Output type: push-pull for pin_10 and pin_11
                                             // Pull-up/pull-down register
  GPIOC_PUPDR   = (1uL << 20)                // - Pin_10 pull-up
                | (1uL << 22);               // - Pin_11 pull-up
  //
  // USART3 settings
  //
  USART3_CR1 = (1uL << 3)                     // Transmitter enable
             | (1uL << 2)                     // Receiver enable
             | (1uL << 5);                    // RX interrupt enable
  USART3_BRR = OS_BRR_VALUE3;                 // Set baudrate
  USART3_CR1 |= (1uL << 13);                  // Enable USART
  NVIC_SetPriority(ISR_ID_USART3, (1u << __NVIC_PRIO_BITS) - 4u);
  NVIC_EnableIRQ(ISR_ID_USART3);
  #endif
  OS_DecRI();
}

#else  /*  No communication or UART selected, using dummies */

void OS_COM_Send1(OS_U8 c) {
  OS_USEPARA(c);           /* Avoid compiler warning */
  OS_COM_ClearTxActive();  /* Let the OS know that Tx is not busy */
}

#endif /*  OS_UART_USED  */

/****** Final check of configuration ********************************/

#ifndef OS_UART_USED
  #error "OS_UART_USED has to be defined"
#endif

#if (OS_TICK_FREQ != 1000u)
  #error "OS_TICK_FREQ != 1000, ensure OS_GetTime_Cycles() and OS_ConvertCycles2us() work."
#endif

/****** End Of File *************************************************/
