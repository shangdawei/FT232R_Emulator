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
File        : SEGGER_SYSVIEW_Conf.h
Purpose     : SEGGER SysView configuration.
--------  END-OF-HEADER  ---------------------------------------------
*/

#ifndef SEGGER_SYSVIEW_CONF_H
#define SEGGER_SYSVIEW_CONF_H

/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/
//
// Constants for known core configuration
//
#define SEGGER_SYSVIEW_CORE_OTHER   0
#define SEGGER_SYSVIEW_CORE_CM0     1 // Cortex-M0/M0+/M1
#define SEGGER_SYSVIEW_CORE_CM3     2 // Cortex-M3/M4/M7

#if (defined __SES_ARM) || (defined __CROSSWORKS_ARM) || (defined __GNUC__)
  #ifdef __ARM_ARCH_6M__
    #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_CM0
  #elif (defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__))
    #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_CM3
  #endif
#elif defined(__ICCARM__)
  #if (defined (__ARM6M__) && (__CORE__ == __ARM6M__))
    #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_CM0
  #elif ((defined (__ARM7M__) && (__CORE__ == __ARM7M__)) || (defined (__ARM7EM__) && (__CORE__ == __ARM7EM__)))
    #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_CM3
  #endif
#elif defined(__CC_ARM)
  #if (defined(__TARGET_ARCH_6S_M))
    #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_CM0
  #elif (defined(__TARGET_ARCH_7_M) || defined(__TARGET_ARCH_7E_M))
    #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_CM3	
  #endif
#endif

#ifndef   SEGGER_SYSVIEW_CORE
  #define SEGGER_SYSVIEW_CORE SEGGER_SYSVIEW_CORE_OTHER
#endif

/*********************************************************************
*
*       Defines, configurable
*
**********************************************************************
*/
/*********************************************************************
*
*       SysView buffer configuration
*/
#define SEGGER_SYSVIEW_RTT_BUFFER_SIZE      1024                                // Number of bytes that SysView uses for the buffer.
#define SEGGER_SYSVIEW_RTT_CHANNEL          1                                   // The RTT channel that SysView will use. 0: Auto selection

#define SEGGER_SYSVIEW_USE_STATIC_BUFFER    1                                   // Use a static buffer to generate events instead of a buffer on the stack

#define SEGGER_SYSVIEW_POST_MORTEM_MODE     0                                   // 1: Enable post mortem analysis mode

/*********************************************************************
*
*       SysView timestamp configuration
*/
#if SEGGER_SYSVIEW_CORE == SEGGER_SYSVIEW_CORE_CM3
  #define SEGGER_SYSVIEW_GET_TIMESTAMP()      ((*(U32 *)(0xE0001004)) >> 4)     // Retrieve a system timestamp. Cortex-M cycle counter. Shifted by 4 to save bandwith.
  #define SEGGER_SYSVIEW_TIMESTAMP_BITS       28                                // Define number of valid bits low-order delivered by clock source
#else
  #define SEGGER_SYSVIEW_GET_TIMESTAMP()      SEGGER_SYSVIEW_X_GetTimestamp()   // Retrieve a system timestamp via user-defined function
  #define SEGGER_SYSVIEW_TIMESTAMP_BITS       32                                // Define number of valid bits low-order delivered by SEGGER_SYSVIEW_X_GetTimestamp()
#endif

/*********************************************************************
*
*       SysView Id configuration
*/
#define SEGGER_SYSVIEW_ID_BASE         0x10000000                               // Default value for the lowest Id reported by the application. Can be overridden by the application via SEGGER_SYSVIEW_SetRAMBase(). (i.e. 0x20000000 when all Ids are an address in this RAM)
#define SEGGER_SYSVIEW_ID_SHIFT        2                                        // Number of bits to shift the Id to save bandwidth. (i.e. 2 when Ids are 4 byte aligned)

/*********************************************************************
*
*       SysView interrupt configuration
*/
#if SEGGER_SYSVIEW_CORE == SEGGER_SYSVIEW_CORE_CM3
  #define SEGGER_SYSVIEW_GET_INTERRUPT_ID()   ((*(U32 *)(0xE000ED04)) & 0x1FF)  // Get the currently active interrupt Id. (i.e. read Cortex-M ICSR[8:0] = active vector)
#elif SEGGER_SYSVIEW_CORE == SEGGER_SYSVIEW_CORE_CM0
  #define SEGGER_SYSVIEW_GET_INTERRUPT_ID()   ((*(U32 *)(0xE000ED04)) & 0x3F)   // Get the currently active interrupt Id. (i.e. read Cortex-M ICSR[5:0] = active vector)
#else
  #error "SEGGER_SYSVIEW_GET_INTERRUPT_ID has to be defined!"
#endif

#endif

/*************************** End of file ****************************/
