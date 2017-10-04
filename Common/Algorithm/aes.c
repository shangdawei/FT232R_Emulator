#include <string.h>

#include "aes.h"
#include "aes_table.h"
#include "aes_vector.h"

#include "utility.h"

/*
 * An integer that is set based on the --cpu option.
 * The symbol is set to 1 if the selected
 * processor architecture is a profile M core.
 *
 * The symbol is undefined for other cores.
 */

#if ( __ARM_PROFILE_M__ > 0 )
#endif

/*
 * An integer that reflects the --endian option and is defined to 1
 * when the byte order is little-endian.
 * The symbol is defined to 0 when the byte order is big-endian.
 */

#if ( __LITTLE_ENDIAN__ > 0 )
#endif

/*
 * An integer that identifies the processor architecture in use.
 * The symbol reflects the --core option and is defined to
 * __ARM4TM__,  // STR7
 * __ARM5__,
 * __ARM5E__,   //
 * __ARM6__,
 * __ARM6M__,   // STM32F0
 * __ARM6SM__,
 * __ARM7M__,   // STM32F1
 * __ARM7EM__,  // STM32F4
 * __ARM7A__, or
 * __ARM7R__.
 *
 * These symbolic names can be used when testing the __CORE__ symbol.
 *
 */

#if ( __CORE__ == __ARM7EM__ )
#endif

#define LSR(x,n)        ( (x) >> (n) )
#define LSL(x,n)        ( (x) << (n) )
#define ROL(x,n)        ( ROR(x,(32-n) ) )
#define ROR(x,n)        ( ((x) << (32 - (int32_t)(n))) | ((x) >> ((int32_t)(n))) )

//------------------------------------------------------------------------------
#define GETBYTE(x, nr)      (  (uint8_t)( (x) >> (nr*8) ) )

#define AES_GET_RCON(i) AES_RCON[i]

#define AES_GET_SBOX(i) AES_Ctx->SBox[i]

// AES_ENCRYPT_KEY [ (1+AES_MAX_ROUND+1)*4 ) ) ]
// AES_DECRYPT_KEY [ (1+AES_MAX_ROUND+1)*4 ) ) ]
//
#define AES_ENCRYPT_KEY \
  ( (uint32_t *)(AES_Ctx->KeyExpanded ) )

#define AES_DECRYPT_KEY \
  ( (uint32_t *)(AES_Ctx->DKeyExpanded ) )

#define SET_KEY_BOX(x)                    \
(                                         \
( AES_GET_SBOX(GETBYTE(x, 0) ) <<  0 ) ^  \
( AES_GET_SBOX(GETBYTE(x, 1) ) <<  8 ) ^  \
( AES_GET_SBOX(GETBYTE(x, 2) ) << 16 ) ^  \
( AES_GET_SBOX(GETBYTE(x, 3) ) << 24 ) )

// initialise the key schedule from the user supplied key
#define SET_KEY_LOOP4(i)                  \
{                                         \
t = ROR(t,  8);                           \
t = SET_KEY_BOX(t) ^ AES_GET_RCON(i);     \
t ^= AES_ENCRYPT_KEY[4 * i + 0];          \
AES_ENCRYPT_KEY[4 * i + 4] = t;           \
t ^= AES_ENCRYPT_KEY[4 * i + 1];          \
AES_ENCRYPT_KEY[4 * i + 5] = t;           \
t ^= AES_ENCRYPT_KEY[4 * i + 2];          \
AES_ENCRYPT_KEY[4 * i + 6] = t;           \
t ^= AES_ENCRYPT_KEY[4 * i + 3];          \
AES_ENCRYPT_KEY[4 * i + 7] = t;           \
}

#define SET_KEY_LOOP6(i)                  \
{                                         \
t = ROR(t,  8);                           \
t = SET_KEY_BOX(t) ^ AES_GET_RCON(i);     \
t ^= AES_ENCRYPT_KEY[6 * i + 0];          \
AES_ENCRYPT_KEY[6 * i + 6] = t;           \
t ^= AES_ENCRYPT_KEY[6 * i + 1];          \
AES_ENCRYPT_KEY[6 * i + 7] = t;           \
t ^= AES_ENCRYPT_KEY[6 * i + 2];          \
AES_ENCRYPT_KEY[6 * i + 8] = t;           \
t ^= AES_ENCRYPT_KEY[6 * i + 3];          \
AES_ENCRYPT_KEY[6 * i + 9] = t;           \
t ^= AES_ENCRYPT_KEY[6 * i + 4];          \
AES_ENCRYPT_KEY[6 * i + 10] = t;          \
t ^= AES_ENCRYPT_KEY[6 * i + 5];          \
AES_ENCRYPT_KEY[6 * i + 11] = t;          \
}

#define SET_KEY_LOOP8(i)                  \
{                                         \
t = ROR(t,  8);                           \
t = SET_KEY_BOX(t) ^ AES_GET_RCON(i);     \
t ^= AES_ENCRYPT_KEY[8 * i + 0];          \
AES_ENCRYPT_KEY[8 * i + 8] = t;           \
t ^= AES_ENCRYPT_KEY[8 * i + 1];          \
AES_ENCRYPT_KEY[8 * i + 9] = t;           \
t ^= AES_ENCRYPT_KEY[8 * i + 2];          \
AES_ENCRYPT_KEY[8 * i + 10] = t;          \
t ^= AES_ENCRYPT_KEY[8 * i + 3];          \
AES_ENCRYPT_KEY[8 * i + 11] = t;          \
t  = AES_ENCRYPT_KEY[8 * i + 4] ^ SET_KEY_BOX(t);   \
AES_ENCRYPT_KEY[8 * i + 12] = t;          \
t ^= AES_ENCRYPT_KEY[8 * i + 5];          \
AES_ENCRYPT_KEY[8 * i + 13] = t;          \
t ^= AES_ENCRYPT_KEY[8 * i + 6];          \
AES_ENCRYPT_KEY[8 * i + 14] = t;          \
t ^= AES_ENCRYPT_KEY[8 * i + 7];          \
AES_ENCRYPT_KEY[8 * i + 15] = t;          \
}

#define star_x(x)                         \
  ( ( (x) & 0x7f7f7f7f) << 1) ^ ( ( ( (x) & 0x80808080) >> 7) * 0x1b )

#define imix_col(y,x)                       \
  do {                                      \
  u     = star_x(x);                        \
  v     = star_x(u);                        \
  w     = star_x(v);                        \
  t     = w ^ (x);                          \
  (y)   = u ^ v ^ w;                        \
  (y)  ^= ROR(u ^ t,  8) ^ ROR(v ^ t, 16) ^ ROR(t,24); \
  } while (0)

//------------------------------------------------------------------------------
// Buffer : AA BB CC DD
// LE : AA BB CC DD ------------------> 0xDDCCBBAA
// BE : AA BB CC DD --> DD CC BB AA --> 0xDDCCBBAA

void AES_EncryptKeyExpand( AES_Ctx_Typedef * AES_Ctx, uint8_t * KeyStr )
{
  uint32_t i, t;

#if ( __LITTLE_ENDIAN__ == 0 )
  RevByteOrderDWordBuffer( AES_ENCRYPT_KEY, (uint32_t *) KeyStr,
      AES_Ctx->KeyLen / 4 );
#else
  CopyDWordBuffer( AES_ENCRYPT_KEY, (uint32_t *) KeyStr, AES_Ctx->KeyLen / 4 );
#endif

  if ( AES_Ctx->KeyLen == 16 )
  {
    t = AES_ENCRYPT_KEY[ 3 ];
    for ( i = 0; i < 10; ++i )
      SET_KEY_LOOP4( i );
  }
  else if ( AES_Ctx->KeyLen == 24 )
  {
    t = AES_ENCRYPT_KEY[ 5 ];
    for ( i = 0; i < 8; ++i )
      SET_KEY_LOOP6( i );
  }
  else if ( AES_Ctx->KeyLen == 32 )
  {
    t = AES_ENCRYPT_KEY[ 7 ];
    for ( i = 0; i < 7; ++i )
      SET_KEY_LOOP8( i );
  }
}

void AES_DecryptKeyExpand( AES_Ctx_Typedef * AES_Ctx, uint8_t * KeyStr )
{
  uint32_t i, t, u, v, w;
  AES_EncryptKeyExpand( AES_Ctx, KeyStr );

  CopyDWordBuffer( AES_DECRYPT_KEY, AES_ENCRYPT_KEY, 4 ); // EKey == DKey

  // k_len = 16, 24, 32
  // i ===== 40, 48, 56
  for ( i = 4; i < AES_Ctx->KeyLen + 24; ++i )
    imix_col( AES_DECRYPT_KEY[i], AES_ENCRYPT_KEY[i] );

  CopyDWordBuffer( &AES_DECRYPT_KEY[ AES_Ctx->KeyLen + 24 ],
    &AES_ENCRYPT_KEY[ AES_Ctx->KeyLen + 24 ], 4 );        // EKey == DKey
}

/*
 * both Encrypt and Decrypt Key are set
 *
 * RAM :
 * uint32_t KeyLen;
 * uint8_t * KeyStr;
 *
 * ROM :
 * uint8_t * SBox;
 * uint8_t * RSBox;
 * uint32_t * EncryptTable;
 * uint32_t * DecryptTable;
 *
 * RAM : encrypt_key[ ------ ] :: decrypt_key[ ------ ]
 * uint32_t * key_buf;
 * KeyStr : flash or sram
 * aes_key_buf : sram only
 */

void AES_SetKey( AES_Ctx_Typedef * AES_Ctx, int32_t Mode, uint32_t KeyLen,
  uint8_t * KeyStr )
{
  AES_Ctx->KeyLen = KeyLen;

  // Only Setup Encrypt Key
  if ( Mode > AES_MODE_BOTH )
    AES_EncryptKeyExpand( AES_Ctx, KeyStr );
  else // ( Mode == AES_MODE_BOTH ) || ( Mode == AES_MODE_DEC )
  {
    // Both Encrypt and Decrypt Key Setup
    AES_DecryptKeyExpand( AES_Ctx, KeyStr );
  }
}

void AES_Init( AES_Ctx_Typedef * AES_Ctx, const uint8_t * SBox,
  const uint8_t * RSBox, const uint32_t * EncryptTable,
  const uint32_t * DecryptTable, uint32_t * KeyExpanded,
  uint32_t * DKeyExpanded )
{
  AES_Ctx->KeyExpanded = KeyExpanded; // Save Expanded Key
  AES_Ctx->DKeyExpanded = DKeyExpanded; // Save Expanded Key
  if ( AES_Ctx->DKeyExpanded == 0 )
    AES_Ctx->DKeyExpanded = KeyExpanded;

  AES_Ctx->SBox = SBox;                 //
  AES_Ctx->RSBox = RSBox;
  AES_Ctx->EncryptTable = EncryptTable;
  AES_Ctx->DecryptTable = DecryptTable;
}

// encrypt and decrypt, next round and last round
//
// R0    = tab        : encrypt/decryt table or SBox/RSBox
// R1    = bo         : outuput
// R2    = bi         : input
// R3    = k          : key
// SP[0] = aes_mode   : 1=encrypt, -1=decrypt
// SP[4] = next       : next round or last round
//
// encrypt : bi_index : 0 1 2 3 [ 1 2 3 4 : 2 3 4 5 : 3 4 5 6 ]
// decrypt : bi_index : 0 3 2 1 [ 1 4 3 2 : 2 5 4 3 : 3 6 5 4 ]
//
// {
//   int32_t xor = ( next ) ? bi[0] : bi[1];
//   for ( uint32_t i=0; i<4; i++)
//   {
//     bo[i]  =    ( tab[ (uint8_t)( bi[  i                    ] >> (8 * 0 ) ) ]     );
//     bo[i] ^= ROL( tab[ (uint8_t)( bi[ (i + (2-encrypt) ) & 3] >> (8 * 1 ) ) ],  8 );
//     bo[i] ^= ROL( tab[ (uint8_t)( bi[ (i + (2        ) ) & 3] >> (8 * 2 ) ) ], 16 );
//     bo[i] ^= ROL( tab[ (uint8_t)( bi[ (i + (2+encrypt) ) & 3] >> (8 * 3 ) ) ], 24 );
//     bo[i] ^= * (k + i);
//   }
//   if ( xor ) bi[0] ^= bi[1];
// }
#if ( __ARM_PROFILE_M__ > 0 )
void AES_RoundThumb2( void * tab, uint32_t * bo, uint32_t * bi, uint32_t * k,
  int32_t aes_mode, int32_t next )
{
  asm volatile(
      "AES_ROUND_CRYPT:                       \n"
      "        PUSH     {R4-R9,LR}            \n"   //SP -= 28 = 4 * 7
      "        LDR      R7,[SP, #+28]         \n"//encrypt : SP[0]
      "        LDR      R4,[SP, #+32]         \n"//next    : SP[4]
      "        RSB      R9,R7,#+2             \n"//R9 = i + ( 2 - encrypt )
      "        ADDS     R7,R7,#+2             \n"//R7 = i + ( 2 + encrypt )
      "        MOV.W    R12,R2                \n"//bi
      "        MOVS     R5,#+0                \n"//i
      "AES_ROUND_CRYPT_LOOP:                  \n"
      "        LDR      LR,[R12], #+4         \n"//bi += 4 : bi[i]
      "        UXTB     LR,LR                 \n"//bi[i]
      "        CMP      R4,#+0                \n"
      "        ITE      NE                    \n"
      "        LDRNE    LR,[R0, LR, LSL #+2]  \n"//DWORD
      "        LDRBEQ   LR,[R0, LR]           \n"//BYTE
      "        AND      R6,R9,#0x3            \n"//(i + (2-encrypt) & 3
      "        LDR      R6,[R2, R6, LSL #+2]  \n"
      "        LSLS     R6,R6,#+16            \n"
      "        LSRS     R6,R6,#+24            \n"//bi[i]
      "        CMP      R4,#+0                \n"
      "        ITE      NE                    \n"
      "        LDRNE    R6,[R0, R6, LSL #+2]  \n"//DWORD
      "        LDRBEQ   R6,[R0, R6]           \n"//BYTE
      "        EOR      LR,LR,R6, ROR #+24    \n"
      "        ADD      R8,R5,#+2             \n"
      "        AND      R6,R8,#0x3            \n"
      "        LDR      R6,[R2, R6, LSL #+2]  \n"
      "        LSLS     R6,R6,#+8             \n"
      "        LSRS     R6,R6,#+24            \n"
      "        CMP      R4,#+0                \n"
      "        ITE      NE                    \n"
      "        LDRNE    R6,[R0, R6, LSL #+2]  \n"//DWORD
      "        LDRBEQ   R6,[R0, R6]           \n"//BYTE
      "        EOR      LR,LR,R6, ROR #+16    \n"
      "        AND      R6,R7,#0x3            \n"//(i + (2+encrypt) & 3
      "        LDR      R6,[R2, R6, LSL #+2]  \n"
      "        LSRS     R6,R6,#+24            \n"//(unsigned char)(x)
      "        CMP      R4,#+0                \n"
      "        ITE      NE                    \n"
      "        LDRNE    R6,[R0, R6, LSL #+2]  \n"//DWORD
      "        LDRBEQ   R6,[R0, R6]           \n"//BYTE
      "        EOR      LR,LR,R6, ROR #+8     \n"
      "        LDR      R8,[R3], #+4          \n"//* (k + i)
      "        EOR      LR,LR,R8              \n"
      "        STR      LR,[R1], #+4          \n"//bo += 4
      "        ADD      R7,R7,#+1             \n"//R7 = i + ( 2 + encrypt )
      "        ADD      R9,R9,#+1             \n"//R9 = i + ( 2 - encrypt )
      "        ADD      R5,R5,#+1             \n"//i++
      "        CMP      R5,#+4                \n"//i<4
      "        BCC.N    AES_ROUND_CRYPT_LOOP  \n"//no
      "        POP      {R4-R9,PC}            \n");
}
#else
__arm void AES_RoundArm( void * tab, uint32_t * bo, uint32_t * bi, uint32_t * k,
    int32_t aes_mode, int32_t next )
{
  asm volatile(
      "AES_ROUND_CRYPT:                       \n"
      "        PUSH     {R4-R9,LR}            \n"   //SP -= 28 = 4 * 7
      "        LDR      R7,[SP, #+28]         \n"//encrypt : SP[0]
      "        LDR      R4,[SP, #+32]         \n"//next    : SP[4]
      "        RSB      R9,R7,#+2             \n"//R9 = i + ( 2 - encrypt )
      "        ADDS     R7,R7,#+2             \n"//R7 = i + ( 2 + encrypt )
      "        MOV.W    R12,R2                \n"//bi
      "        MOVS     R5,#+0                \n"//i
      "AES_ROUND_CRYPT_LOOP:                  \n"
      "        LDR      LR,[R12], #+4         \n"//bi += 4 : bi[i]
      "        AND      LR,LR,#0xFF           \n"//bi[i]
      "        CMP      R4,#+0                \n"
      "        LDRNE    LR,[R0, LR, LSL #+2]  \n"//DWORD
      "        LDRBEQ   LR,[R0, LR]           \n"//BYTE
      "        AND      R6,R9,#0x3            \n"//(i + (2-encrypt) & 3
      "        LDR      R6,[R2, R6, LSL #+2]  \n"
      "        LSLS     R6,R6,#+16            \n"
      "        LSRS     R6,R6,#+24            \n"//bi[i]
      "        CMP      R4,#+0                \n"
      "        LDRNE    R6,[R0, R6, LSL #+2]  \n"//DWORD
      "        LDRBEQ   R6,[R0, R6]           \n"//BYTE
      "        EOR      LR,LR,R6, ROR #+24    \n"
      "        ADD      R8,R5,#+2             \n"
      "        AND      R6,R8,#0x3            \n"
      "        LDR      R6,[R2, R6, LSL #+2]  \n"
      "        LSLS     R6,R6,#+8             \n"
      "        LSRS     R6,R6,#+24            \n"
      "        CMP      R4,#+0                \n"
      "        LDRNE    R6,[R0, R6, LSL #+2]  \n"//DWORD
      "        LDRBEQ   R6,[R0, R6]           \n"//BYTE
      "        EOR      LR,LR,R6, ROR #+16    \n"
      "        AND      R6,R7,#0x3            \n"//(i + (2+encrypt) & 3
      "        LDR      R6,[R2, R6, LSL #+2]  \n"
      "        LSRS     R6,R6,#+24            \n"//(unsigned char)(x)
      "        CMP      R4,#+0                \n"
      "        LDRNE    R6,[R0, R6, LSL #+2]  \n"//DWORD
      "        LDRBEQ   R6,[R0, R6]           \n"//BYTE
      "        EOR      LR,LR,R6, ROR #+8     \n"
      "        LDR      R8,[R3], #+4          \n"//* (k + i)
      "        EOR      LR,LR,R8              \n"
      "        STR      LR,[R1], #+4          \n"//bo += 4
      "        ADD      R7,R7,#+1             \n"//R7 = i + ( 2 + encrypt )
      "        ADD      R9,R9,#+1             \n"//R9 = i + ( 2 - encrypt )
      "        ADD      R5,R5,#+1             \n"//i++
      "        CMP      R5,#+4                \n"//i<4
      "        BCC      AES_ROUND_CRYPT_LOOP  \n"//no
      "        POP      {R4-R9,PC}            \n");
}
#endif

//------------------------------------------------------------------------------
// In : AA BB CC DD
// LE : AA BB CC DD ------------------> 0xDDCCBBAA
// BE : AA BB CC DD --> DD CC BB AA --> 0xDDCCBBAA
//

void AES_Crypt( AES_Ctx_Typedef * AES_Ctx, int32_t Mode, uint32_t SizeInByte,
  uint8_t * pIv, uint8_t * pIvOut, uint8_t * pData, uint8_t * pDataOut )
{
  int32_t i;
  uint32_t * pTable, *pSbox;
  uint32_t * p, *pLeft, *pRight;
  uint32_t *pKey, *BlockLeft, BlockRight[ 4 ];

  // SizeInDWord : AES128 = 4, AES192 = 6, AES256 = 8
  uint32_t k_len = AES_Ctx->KeyLen >> 2;
  uint32_t SizeInDWord = SizeInByte >> 2;
  uint32_t SizeIn16Byte = SizeInDWord >> 2;

  uint32_t IV[ 4 ], NV[ 4 ];

  //----------------------------------------------------------------------------
  // Pre Process
  uint32_t * pDWordIv = 0;
  uint32_t * pDWordDataOut = (uint32_t *) pDataOut;

#if ( __LITTLE_ENDIAN__ == 0 )
  if ( pIv )
  {
    RevByteOrderDWordBuffer( (uint32_t *) IV, (uint32_t *) pIv, 4 );
    pDWordIv = (uint32_t *) IV;
  }

  if ( pDataOut == 0 )
  {
    // pData[] must be writable
    pDWordDataOut = (uint32_t *) pData;
  }

  // pDataOut[] must be writable
  // always even if pOutput == pInput
  if ( 1 )
  {
    RevByteOrderDWordBuffer( (uint32_t *) pDWordDataOut, (uint32_t *) pData,
        SizeInDWord );
  }
#else
  if ( pIv )
  {
    CopyDWordBuffer( (uint32_t *) IV, (uint32_t *) pIv, 4 );
    pDWordIv = (uint32_t *) IV;
  }

  if ( pDataOut == 0 )
  {
    // pData[] must be writable
    pDWordDataOut = (uint32_t *) pData;
  }

  // pOutput != pInput
  if ( pDWordDataOut != (uint32_t *) pData )
  {
    // pDataOut[] must be writable
    CopyDWordBuffer( (uint32_t *) pDWordDataOut, (uint32_t *) pData,
      SizeInDWord );
  }
#endif

  //----------------------------------------------------------------------------
  // Setup Param
  Mode = ( Mode > AES_MODE_BOTH ) ? AES_MODE_ENC : AES_MODE_DEC;
  if ( Mode == AES_MODE_ENC )
  {
    pSbox = (uint32_t *) AES_Ctx->SBox;
    pTable = (uint32_t *) AES_Ctx->EncryptTable;
  }
  else
  {
    pSbox = (uint32_t *) AES_Ctx->RSBox;
    pTable = (uint32_t *) AES_Ctx->DecryptTable;
  }

  //----------------------------------------------------------------------------
  // Process
  while ( SizeIn16Byte-- )
  {
    //--------------------------------------------------------------------------
    // Init Input or Update NV
    if ( pDWordIv )
    {
      if ( Mode == AES_MODE_DEC ) // Update NV
        CopyDWordBuffer( NV, pDWordDataOut, 4 );
      else
        // Init Input
        XorDWordBuffer( pDWordDataOut, pDWordIv, 4 );
    }

    //--------------------------------------------------------------------------
    // Setup Expanded Key
    if ( Mode == AES_MODE_ENC )
      pKey = AES_ENCRYPT_KEY;                       // First Key >>>>>>
    else
      pKey = AES_DECRYPT_KEY + 4 * ( k_len + 6 );   // <<<<<<< Last Key

    BlockLeft = (uint32_t *) pDWordDataOut;
    XorDWordBuffer( BlockLeft, pKey, 4 );

    pKey += ( 4 * Mode );                           // ENC += 4, DEC -= 4

    pLeft = BlockLeft;
    pRight = BlockRight;
    for ( i = k_len + 5; i > -1; i--, pKey += ( 4 * Mode ) )
    {
#if ( __ARM_PROFILE_M__ == 0 )
      AES_RoundArm( ( i ) ? (void *) pTable : (void *) pSbox, pRight, pLeft,
          pKey, Mode, i );
#else
      AES_RoundThumb2( ( i ) ? (void *) pTable : (void *) pSbox, pRight, pLeft,
        pKey, Mode, i );
#endif

      p = pLeft;
      pLeft = pRight;
      pRight = p;
    }

    //--------------------------------------------------------------------------
    if ( pDWordIv )
    {
      if ( Mode == AES_MODE_ENC )
        CopyDWordBuffer( pDWordIv, pDWordDataOut, 4 );
      else
      {
        // Update Output
        XorDWordBuffer( pDWordDataOut, pDWordIv, 4 );
        // Update IV
        CopyDWordBuffer( pDWordIv, NV, 4 );
      }
    }

    pDWordDataOut += 4;                             // 4 * 4 = 16 bytes
  }

  //----------------------------------------------------------------------------
  // Post Process
  uint32_t * pDWordIvOut = (uint32_t *) pIvOut;
#if ( __LITTLE_ENDIAN__ == 0 )
  if ( pDWordIv && pDWordIvOut )
  {
    RevByteOrderDWordBuffer( pDWordIvOut, pDWordIv, 4 );
  }
  pDWordDataOut -= SizeInDWord;
  RevByteOrderDWordBuffer( (uint32_t *) pDWordDataOut,
      (uint32_t *) pDWordDataOut, SizeInDWord );
#else
  if ( pDWordIv && pDWordIvOut )  // pIv == pIvOut, pIv != pIvOut
  {
    CopyDWordBuffer( pDWordIvOut, pDWordIv, 4 );
  }
#endif
}

static const uint8_t * AES_Demo_IV = "89ABCDEF01234567";
static const uint8_t * AES_Demo_Key = "0123456789ABCDEF";
static const uint8_t * AES_Demo_Text = "56789AB01234CDEFAB01234CDEF12456";

static __no_init uint8_t AES_Demo_Iv[ 16 ];
static __no_init uint8_t AES_Demo_OutIv[ 16 ];
static __no_init uint8_t AES_Demo_DataEncrypted[ 16 ];
static __no_init uint8_t AES_Demo_DataDecrypted[ 16 ];

static __no_init AES_Ctx_Typedef AES_Demo_Ctx;
static __no_init uint32_t AES_Demo_KeyExpanded[ AES_KEY_BUF_SIZE_IN_DWORD ];
static __no_init uint32_t AES_Demo_DKeyExpanded[ AES_KEY_BUF_SIZE_IN_DWORD ];

void AES_Test( void )
{
  AES_Init( &AES_Demo_Ctx, (uint8_t *) &AES_SBOX, (uint8_t *) &AES_RSBOX,
    (uint32_t *) &AES_ENCRYPT_TAB, (uint32_t *) &AES_DECRYPT_TAB,
    AES_Demo_KeyExpanded, AES_Demo_DKeyExpanded );
  AES_SetKey( &AES_Demo_Ctx, AES_MODE_BOTH, AES_KEY_128,
    (uint8_t *) AES_Demo_Key );

  memcpy( AES_Demo_Iv, (uint8_t *) AES_Demo_IV, 16 );

  AES_Crypt( &AES_Demo_Ctx, AES_MODE_ENC, 32, (uint8_t *) AES_Demo_Iv, 0,
    (uint8_t *) AES_Demo_Text, AES_Demo_DataEncrypted );

  AES_Crypt( &AES_Demo_Ctx, AES_MODE_DEC, 32, (uint8_t *) AES_Demo_Iv, 0,
    (uint8_t *) AES_Demo_DataEncrypted, AES_Demo_DataDecrypted );
}

uint32_t AES_Demo( void )
{
  uint32_t Error;
  uint32_t ErrorIndex;
  uint8_t * pIV;
  uint32_t i;

  uint32_t UseSingleKeyExpanded = 0;

  while ( UseSingleKeyExpanded < 2 )
  {
    if ( UseSingleKeyExpanded == 0 )
      AES_Init( &AES_Demo_Ctx, (uint8_t *) &AES_SBOX, (uint8_t *) &AES_RSBOX,
        (uint32_t *) &AES_ENCRYPT_TAB, (uint32_t *) &AES_DECRYPT_TAB,
        AES_Demo_KeyExpanded, AES_Demo_DKeyExpanded );
    else
      AES_Init( &AES_Demo_Ctx, (uint8_t *) &AES_SBOX, (uint8_t *) &AES_RSBOX,
        (uint32_t *) &AES_ENCRYPT_TAB, (uint32_t *) &AES_DECRYPT_TAB,
        AES_Demo_KeyExpanded, 0 );

    UseSingleKeyExpanded++;

    uint32_t cnt = AES_TestVectorValues( );
    for ( i = 0; i < cnt; i++ )
    {
      AES_SetKey( &AES_Demo_Ctx, AES_MODE_ENC,
        AES_TestVectorValueArray[ i ].KeySize,
        AES_TestVectorValueArray[ i ].Key );

      pIV = 0;
      if ( AES_TestVectorValueArray[ i ].IV[ 16 ] )
      {
        memcpy( AES_Demo_Iv, AES_TestVectorValueArray[ i ].IV, 16 );
        pIV = AES_Demo_Iv;
      }

      AES_Crypt( &AES_Demo_Ctx, AES_MODE_ENC, 16, pIV, AES_Demo_OutIv,
        AES_TestVectorValueArray[ i ].Plain, AES_Demo_DataEncrypted );

      Error = memcmp( AES_Demo_DataEncrypted,
        &AES_TestVectorValueArray[ i ].Cipher, 16 );
      if ( Error )
      {
        ErrorIndex = i;
        for ( ;; )
          ;
      }

      AES_SetKey( &AES_Demo_Ctx, AES_MODE_DEC,
        AES_TestVectorValueArray[ i ].KeySize,
        AES_TestVectorValueArray[ i ].Key );

      pIV = 0;
      if ( AES_TestVectorValueArray[ i ].IV[ 16 ] )
      {
        memcpy( AES_Demo_Iv, AES_TestVectorValueArray[ i ].IV, 16 );
        pIV = AES_Demo_Iv;
      }

      AES_Crypt( &AES_Demo_Ctx, AES_MODE_DEC, 16, pIV, AES_Demo_OutIv,
        AES_Demo_DataEncrypted, AES_Demo_DataDecrypted );

      Error = memcmp( AES_Demo_DataDecrypted,
        &AES_TestVectorValueArray[ i ].Plain, 16 );
      if ( Error )
      {
        ErrorIndex = i;
        for ( ;; )
          ;
      }
    }
  }

  return ErrorIndex;
}
