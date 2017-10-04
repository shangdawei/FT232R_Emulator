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
File        : SEGGER_SYSVIEW_Int.h
Purpose     : SEGGER SysView internal header.
--------  END-OF-HEADER  ---------------------------------------------
*/

#ifndef SEGGER_SYSVIEW_INT_H
#define SEGGER_SYSVIEW_INT_H

/*********************************************************************
*
*       #include Section
*
**********************************************************************
*/

#include "SEGGER_SYSVIEW.h"
#include "SEGGER_SYSVIEW_Conf.h"
#include "SEGGER_SYSVIEW_ConfDefaults.h"

#ifdef __cplusplus
extern "C" {
#endif


/*********************************************************************
*
*       Private data types
*
**********************************************************************
*/

//
// SYSVIEW events. First 32 IDs from 0 .. 31 are reserved for these
//
#define   SEGGER_SYSVIEW_EVENT_ID_NOP                0  // Dummy packet.
#define   SEGGER_SYSVIEW_EVENT_ID_OVERFLOW           1
#define   SEGGER_SYSVIEW_EVENT_ID_ISR_ENTER          2
#define   SEGGER_SYSVIEW_EVENT_ID_ISR_EXIT           3
#define   SEGGER_SYSVIEW_EVENT_ID_TASK_START_EXEC    4
#define   SEGGER_SYSVIEW_EVENT_ID_TASK_STOP_EXEC     5
#define   SEGGER_SYSVIEW_EVENT_ID_TASK_START_READY   6
#define   SEGGER_SYSVIEW_EVENT_ID_TASK_STOP_READY    7
#define   SEGGER_SYSVIEW_EVENT_ID_TASK_CREATE        8
#define   SEGGER_SYSVIEW_EVENT_ID_TASK_INFO          9
#define   SEGGER_SYSVIEW_EVENT_ID_TRACE_START       10
#define   SEGGER_SYSVIEW_EVENT_ID_TRACE_STOP        11
#define   SEGGER_SYSVIEW_EVENT_ID_SYSTIME_CYCLES    12
#define   SEGGER_SYSVIEW_EVENT_ID_SYSTIME_US        13
#define   SEGGER_SYSVIEW_EVENT_ID_SYSDESC           14
#define   SEGGER_SYSVIEW_EVENT_ID_USER_START        15
#define   SEGGER_SYSVIEW_EVENT_ID_USER_STOP         16
#define   SEGGER_SYSVIEW_EVENT_ID_IDLE              17
#define   SEGGER_SYSVIEW_EVENT_ID_ISR_TO_SCHEDULER  18
#define   SEGGER_SYSVIEW_EVENT_ID_TIMER_ENTER       19
#define   SEGGER_SYSVIEW_EVENT_ID_TIMER_EXIT        20
#define   SEGGER_SYSVIEW_EVENT_ID_STACK_INFO        21
#define   SEGGER_SYSVIEW_EVENT_ID_MODULEDESC        22

#define   SEGGER_SYSVIEW_EVENT_ID_INIT              24
#define   SEGGER_SYSVIEW_EVENT_ID_NAME_RESOURCE     25
#define   SEGGER_SYSVIEW_EVENT_ID_PRINT_FORMATTED   26
#define   SEGGER_SYSVIEW_EVENT_ID_NUMMODULES        27

//
// Commands that Host can send to target
//
typedef enum {
  SEGGER_SYSVIEW_COMMAND_ID_START = 1,
  SEGGER_SYSVIEW_COMMAND_ID_STOP,
  SEGGER_SYSVIEW_COMMAND_ID_GET_SYSTIME,
  SEGGER_SYSVIEW_COMMAND_ID_GET_TASKLIST,
  SEGGER_SYSVIEW_COMMAND_ID_GET_SYSDESC,
  SEGGER_SYSVIEW_COMMAND_ID_GET_NUMMODULES,
  SEGGER_SYSVIEW_COMMAND_ID_GET_MODULEDESC,
  // Extended commands: Commands >= 128 have a second parameter
  SEGGER_SYSVIEW_COMMAND_ID_GET_MODULE = 128,
} SEGGER_SYSVIEW_COMMAND_ID;

#ifdef __cplusplus
}
#endif

#endif

/****** End Of File *************************************************/
