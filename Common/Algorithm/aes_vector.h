#ifndef __AES_VECTOR_H__
#define __AES_VECTOR_H__

#include <stdint.h>

typedef struct
{
  uint32_t KeySize;
  uint8_t * strIV;
  uint8_t * strKey;
  uint8_t * strPlain;
  uint8_t * strCipher;
} AES_TestVector_TypeDef;

typedef struct
{
  uint32_t KeySize;
  uint8_t IV[ 16 + 4 ];
  uint8_t Key[ 32 ];
  uint8_t Plain[ 16 ];
  uint8_t Cipher[ 16 ];
} AES_TestVectorValue_TypeDef;

extern const AES_TestVector_TypeDef AES_TestVectorArray[ ];
extern AES_TestVectorValue_TypeDef AES_TestVectorValueArray[ ];
uint32_t AES_TestVectorValues( void );

#endif /* __AES_VECTOR_H__ */
