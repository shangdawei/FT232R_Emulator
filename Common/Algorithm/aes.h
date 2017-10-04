#ifndef __AES_H__
#define __AES_H__

#include <stdint.h>
#include "aes_table.h"

#define AES_MAX_ROUND       ( AES_ROUND_256 )

#define AES_MODE_ENC        (  1 )
#define AES_MODE_DEC        ( -1 )
#define AES_MODE_BOTH       (  0 )

#define AES_KEY_128         ( 16 )
#define AES_KEY_192         ( 24 )
#define AES_KEY_256         ( 32 )

#define AES_ROUND_128       ( 10 )
#define AES_ROUND_192       ( 12 )
#define AES_ROUND_256       ( 14 )

//------------------------------------------------------------------------------
//          Encrypt   Both
// AES128 : 176       176*2
// AES192 : 208       208*2
// AES256 : 240       240*2
//
#define AES_KEY_BUF_SIZE_IN_DWORD         \
  ( (1 + AES_MAX_ROUND + 1 ) * 4 )

#define AES_KEY128_BUF_SIZE_IN_DWORD       \
  ( (1 + AES_ROUND_128 + 1 ) * 4 )
#define AES_KEY192_BUF_SIZE_IN_DWORD       \
  ( (1 + AES_ROUND_192 + 1 ) * 4 )
#define AES_KEY256_BUF_SIZE_IN_DWORD       \
  ( (1 + AES_ROUND_256 + 1 ) * 4 )

typedef struct
{
  uint32_t KeyLen;
  uint32_t * KeyExpanded;
  uint32_t * DKeyExpanded;
  const uint8_t * SBox;
  const uint8_t * RSBox;
  const uint32_t * EncryptTable;
  const uint32_t * DecryptTable;
} AES_Ctx_Typedef;

#if ( __ARM_PROFILE_M__ == 0 )
__arm
#endif
void AES_Init( AES_Ctx_Typedef * AES_Ctx, const uint8_t * SBox,
  const uint8_t * RSBox, const uint32_t * EncryptTable,
  const uint32_t * DecryptTable, uint32_t * EKeyExpanded,
  uint32_t * DKeyExpanded );

#if ( __ARM_PROFILE_M__ == 0 )
__arm
#endif
void AES_SetKey( AES_Ctx_Typedef * AES_Ctx, int32_t Mode, uint32_t KeyLen,
  uint8_t * KeyStr );

//------------------------------------------------------------------------------
// pIv == 0, pIvOut == X   : ECB, Single/Multi Block
//
// pIv != 0, pIvOut == 0   : CBC, Single Block, pIvOut doesn't care
// pIv != 0, pIvOut == pIv : CBC, Multi Block, AES_Crypt Copied pIv from pIvOut
// pIv != 0, pIvOut != pIv : CBC, Multi Block, Copy pIv from pIvOut before Next
//
// pOutput == 0 : pData uses out
// pOutput != 0 : pOutput uses out
//
#if ( __ARM_PROFILE_M__ == 0 )
__arm
#endif
void AES_Crypt( AES_Ctx_Typedef * AES_Ctx, int32_t Mode, uint32_t SizeInByte,
  uint8_t * pIv, uint8_t * pIvOut, uint8_t * pData, uint8_t * pOutput );

void AES_Test( void );
uint32_t AES_Demo( void );

#endif /* __AES_H__ */

