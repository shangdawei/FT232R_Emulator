#ifndef __STM332F0XX_H__
#define __STM332F0XX_H__

#include "stm32f0xx_device.h"

#include "stm32f0xx_0.h"
#include "stm32f0xx_1.h"
#include "stm32f0xx_2.h"
#include "stm32f0xx_3.h"
#include "stm32f0xx_4.h"
#include "stm32f0xx_5.h"
#include "stm32f0xx_6.h"
#include "stm32f0xx_7.h"
#include "stm32f0xx_8.h"

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  ERROR = 0,
  SUCCESS = !ERROR
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))


#ifdef USE_STDPERIPH_DRIVER
  #include "stm32f0xx_conf.h"
#endif

#endif /* __STM332F0XX_H__ */
