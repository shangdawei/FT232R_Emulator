#ifndef __CRC_DRIVER_H__
#define __CRC_DRIVER_H__

#include "Driver_Common.h"
#include "crc.h"

typedef struct
{
  void (*Init)( CRC_Model_TypeDef * CRC_Model );

  void (*DoByte)( CRC_Model_TypeDef * CRC_Model, uint32_t InByte );

  void (*DoBlock)( CRC_Model_TypeDef * CRC_Model, uint32_t Size,
    uint8_t * InBlock );

  uint32_t (*Done)( CRC_Model_TypeDef * CRC_Model );
} CRC_Driver_TypeDef;

#endif /* __CRC_DRIVER_H__ */
