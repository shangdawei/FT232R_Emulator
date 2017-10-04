#ifndef __DRIVER_GPIO_H__
#define __DRIVER_GPIO_H__

#include "Driver_Common.h"

typedef enum
{
  DRV_GPIO0,
  DRV_GPIO1,
  DRV_GPIO2,
  DRV_GPIO3,
  DRV_GPIO4,
  DRV_GPIO5,
  DRV_GPIO6,
  DRV_GPIO7,
  DRV_GPIO8,
  DRV_GPIO9,
  DRV_GPIO10
} DRV_GPIO_TypeDef;

typedef enum
{
  DRV_GPIO_PIN0 = ( (uint32_t) 0x00000001 ),
  DRV_GPIO_PIN1 = ( (uint32_t) 0x00000002 ),
  DRV_GPIO_PIN2 = ( (uint32_t) 0x00000004 ),
  DRV_GPIO_PIN3 = ( (uint32_t) 0x00000008 ),
  DRV_GPIO_PIN4 = ( (uint32_t) 0x00000010 ),
  DRV_GPIO_PIN5 = ( (uint32_t) 0x00000020 ),
  DRV_GPIO_PIN6 = ( (uint32_t) 0x00000040 ),
  DRV_GPIO_PIN7 = ( (uint32_t) 0x00000080 ),
  DRV_GPIO_PIN8 = ( (uint32_t) 0x00000100 ),
  DRV_GPIO_PIN9 = ( (uint32_t) 0x00000200 ),
  DRV_GPIO_PIN10 = ( (uint32_t) 0x00000400 ),
  DRV_GPIO_PIN11 = ( (uint32_t) 0x00000800 ),
  DRV_GPIO_PIN12 = ( (uint32_t) 0x00001000 ),
  DRV_GPIO_PIN13 = ( (uint32_t) 0x00002000 ),
  DRV_GPIO_PIN14 = ( (uint32_t) 0x00004000 ),
  DRV_GPIO_PIN15 = ( (uint32_t) 0x00008000 ),
  DRV_GPIO_PIN16 = ( (uint32_t) 0x00010000 ),
  DRV_GPIO_PIN17 = ( (uint32_t) 0x00020000 ),
  DRV_GPIO_PIN18 = ( (uint32_t) 0x00040000 ),
  DRV_GPIO_PIN19 = ( (uint32_t) 0x00080000 ),
  DRV_GPIO_PIN20 = ( (uint32_t) 0x00100000 ),
  DRV_GPIO_PIN21 = ( (uint32_t) 0x00200000 ),
  DRV_GPIO_PIN22 = ( (uint32_t) 0x00400000 ),
  DRV_GPIO_PIN23 = ( (uint32_t) 0x00800000 ),
  DRV_GPIO_PIN24 = ( (uint32_t) 0x01000000 ),
  DRV_GPIO_PIN25 = ( (uint32_t) 0x02000000 ),
  DRV_GPIO_PIN26 = ( (uint32_t) 0x04000000 ),
  DRV_GPIO_PIN27 = ( (uint32_t) 0x08000000 ),
  DRV_GPIO_PIN28 = ( (uint32_t) 0x10000000 ),
  DRV_GPIO_PIN29 = ( (uint32_t) 0x20000000 ),
  DRV_GPIO_PIN30 = ( (uint32_t) 0x40000000 ),
  DRV_GPIO_PIN31 = ( (uint32_t) 0x80000000 ),
} DRV_GPIO_PinNum_TypeDef;

//------------------------------------------------------------------------------
// GPIO Control Codes
#define DRV_GPIO_CTRL_INIT       ( 0x00 )    // Init Pins by PinProp
#define DRV_GPIO_CTRL_UNINIT     ( 0x01 )    // Uninit Pins to Default State
#define DRV_GPIO_CTRL_DIR        ( 0x02 )    // PinDir by PinProp
#define DRV_GPIO_CTRL_PULL       ( 0x03 )    // PinPull by PinProp
#define DRV_GPIO_CTRL_DRV        ( 0x04 )    // PinDrv by PinProp
#define DRV_GPIO_CTRL_INTR       ( 0x05 )    // PinIntr by PinProp
#define DRV_GPIO_CTRL_EVENT      ( 0x06 )    // EventHandler by PinProp

typedef enum                    // STM32F4
{
  DRV_PIN_DIR_INPUT = 0,         // Input Mode
  DRV_PIN_DIR_OUTPUT,            // Output Mode
} DRV_GPIO_PinDir_TypeDef;

typedef enum                    // STM32F4
{
  DRV_PIN_PULL_NONE = 0,         // No Pull-up or Pull-down
  DRV_PIN_PULL_UP,               // Pull-up
  DRV_PIN_PULL_DOWN,             // Pull-down
} DRV_GPIO_PinPull_TypeDef;

typedef enum                    // STM32F4
{
  DRV_PIN_DRV_PP = 0,            // Output Push Pull Mode
  DRV_PIN_DRV_OD,                // Output Open Drain Mode
} DRV_GPIO_PinDrv_TypeDef;

typedef enum
{
  DRV_PIN_INTR_NONE = 0,         // No Interrupt
  DRV_PIN_INTR_RISING,           // Interrupt with Rising edge trigger detection
  DRV_PIN_INTR_FALLING,          // Interrupt with Falling edge trigger detection
  DRV_PIN_INTR_BOTH,             // Interrupt with Both edge trigger detection
} DRV_GPIO_PinIntr_TypeDef;

typedef enum
{
  DRV_PIN_RESET = 0,             // Low Level
  DRV_PIN_SET,                   // High Level
} DRV_GPIO_PinState_TypeDef;

typedef void (*DRV_GPIO_EventHandler_TypeDef)( uint32_t event );

typedef struct
{
  uint32_t Pins;                // IO_PIN0 | IO_PIN1 | IO_PIN7
  DRV_GPIO_PinDir_TypeDef Dir;   // DRV_PIN_DIR_INPUT or DRV_PIN_DIR_OUTPUT
  DRV_GPIO_PinPull_TypeDef Pull; // DRV_PIN_PULL_DOWN, DRV_PIN_PULL_UP, ...
  DRV_GPIO_PinDrv_TypeDef Drv;   // DRV_PIN_OUT_PP, DRV_PIN_OUT_OD
  DRV_GPIO_PinIntr_TypeDef Intr; // DRV_PIN_INTR_NONE, DRV_PIN_INTR_BOTH, ..
  DRV_GPIO_EventHandler_TypeDef EventHandler;
} DRV_GPIO_PinProp_TypeDef;

typedef struct
{
  uint32_t port_num :8;         // PORT0, PORT1, PORT2, ...
  uint32_t pin_num :8;          // PIN0, PIN1, PIN2, ...
  uint32_t open_drain :1;       // Open Drain Mode ?
  uint32_t pull_up :1;          // Pull-up
  uint32_t pull_down :1;        // Pull-down
  uint32_t intr_rising_edge :1; // Interrupt with Rising edge
  uint32_t intr_falling_edge :1;
} DRV_GPIO_Capabilities_TypeDef;

typedef struct
{
  const DRV_GPIO_Capabilities_TypeDef * Capabilities;
  int32_t (*GetPortIndex)( void * gpio );
  int32_t (*PowerControl)( DRV_GPIO_TypeDef hw_gpio, uint32_t state );

  // Port All Pins
  uint32_t (*Read)( DRV_GPIO_TypeDef hw_gpio, uint32_t mask );
  void (*Write)( DRV_GPIO_TypeDef hw_gpio, uint32_t mask, uint32_t val );

  uint32_t (*ReadByte)( DRV_GPIO_TypeDef hw_gpio, uint32_t order );
  void (*WriteByte)( DRV_GPIO_TypeDef hw_gpio, uint32_t order, uint32_t val );

  uint32_t (*ReadWord)( DRV_GPIO_TypeDef hw_gpio, uint32_t order );
  void (*WriteWord)( DRV_GPIO_TypeDef hw_gpio, uint32_t order, uint32_t val );

  // Port Single Pin
  DRV_GPIO_PinState_TypeDef (*ReadPin)( DRV_GPIO_TypeDef hw_gpio,
    DRV_GPIO_PinNum_TypeDef pin );
  void (*TogglePin)( DRV_GPIO_TypeDef hw_gpio, DRV_GPIO_PinNum_TypeDef pin );
  void (*WritePin)( DRV_GPIO_TypeDef hw_gpio, DRV_GPIO_PinNum_TypeDef pin,
    DRV_GPIO_PinState_TypeDef state );

  int32_t (*Control)( DRV_GPIO_TypeDef hw_gpio, uint32_t control, uint32_t arg );
} GPIO_Driver_TypeDef;

#endif /* __DRIVER_GPIO_H__ */
