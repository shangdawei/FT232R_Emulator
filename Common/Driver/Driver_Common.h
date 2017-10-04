#ifndef __DRIVER_COMMON_H__
#define __DRIVER_COMMON_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
// General return codes
//
#define DRIVER_OK                           (  0 )   // Operation succeeded
#define DRIVER_ERROR                        ( -1 )   // Unspecified error
#define DRIVER_ERROR_BUSY                   ( -2 )   // Driver is busy
#define DRIVER_ERROR_TIMEOUT                ( -3 )   // Timeout occurred
#define DRIVER_ERROR_UNSUPPORTED            ( -4 )   // Operation not supported
#define DRIVER_ERROR_PARAMETER              ( -5 )   // Parameter error
#define DRIVER_ERROR_SEMAPHORE              ( -6 )   // Semaphore error
#define DRIVER_ERROR_THREAD                 ( -7 )   // Thread error
#define DRIVER_ERROR_TIMER                  ( -8 )   // Timer error
#define DRIVER_ERROR_DEVICE                 ( -9 )   // Device error
#define DRIVER_ERROR_MEMORY                 ( -10 )  // Memory error
#define DRIVER_ERROR_SPECIFIC               ( -11 )  // Specific error

//------------------------------------------------------------------------------
// General power states
//
// Power off: no operation possible
#define DRIVER_POWER_OFF            ( 0 )
// Low Power mode: retain state, detect and signal wake-up events
#define DRIVER_POWER_LOW            ( 1 )
// Power on: full operation at maximum performance
#define DRIVER_POWER_FULL           ( 2 )

#endif /* __DRIVER_COMMON_H__ */
