#ifndef __DES_VECTOR_H__
#define __DES_VECTOR_H__

#include <stdint.h>

typedef struct
{
  uint8_t * strKey;
  uint8_t * strPlain;
  uint8_t * strCipher;
  uint8_t * strDecrypted;
  uint8_t * strCipher100;
  uint8_t * strCipher1000;
} DES_TestVector_TypeDef;

typedef struct
{
  uint8_t Key[ 8 ];
  uint8_t Plain[ 8 ];
  uint8_t Cipher[ 8 ];
  uint8_t Decrypted[ 8 ];
  uint8_t Cipher100[ 8 ];
  uint8_t Cipher1000[ 8 ];
} DES_TestVectorValue_TypeDef;

extern const DES_TestVector_TypeDef DES_TestVectorArray[ ];
extern DES_TestVectorValue_TypeDef DES_TestVectorValueArray[ ];
uint32_t DES_TestVectorValues( void );

typedef struct
{
  uint8_t * strKey;
  uint8_t * strCipher;
  uint8_t * strPlain;
  uint8_t * strEncrypted;
} DES_TestVector2_TypeDef;

typedef struct
{
  uint8_t Key[ 8 ];
  uint8_t Cipher[ 8 ];
  uint8_t Plain[ 8 ];
  uint8_t Encrypted[ 8 ];
} DES_TestVectorValue2_TypeDef;

extern const DES_TestVector2_TypeDef DES_TestVectorArray2[ ];
extern DES_TestVectorValue2_TypeDef DES_TestVectorValueArray2[ ];
uint32_t DES_TestVectorValues2( void );

#endif /* __DES_VECTOR_H__ */
