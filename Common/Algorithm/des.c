#include <string.h>
#include "des.h"
#include "utility.h"

const uint16_t DES_ByteBit[ 8 ] =
{ 0200, 0100, 040, 020, 010, 04, 02, 01 };

const uint8_t DES_Totrot[ 16 ] =
{ 1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28 };

const uint32_t DES_BigByte[ 24 ] =
{ 0x800000L, 0x400000L, 0x200000L, 0x100000L, 0x80000L, 0x40000L, 0x20000L,
  0x10000L, 0x8000L, 0x4000L, 0x2000L, 0x1000L, 0x800L, 0x400L, 0x200L, 0x100L,
  0x80L, 0x40L, 0x20L, 0x10L, 0x8L, 0x4L, 0x2L, 0x1L };

void DES_KeyExpand( DES_Ctx_Typedef * DES_Ctx, uint8_t * pKey,
  uint32_t * pKeyExpanded, uint32_t Decrypt )
{
  uint32_t i, j;
  uint32_t Value, Mask, Count;

  uint8_t pc1m[ 56 ], pcr[ 56 ];
  uint32_t KeyArray[ 32 ];

  for ( j = 0; j < 56; j++ )
  {
    Value = DES_Ctx->DES_PC1[ j ];
    Mask = Value & 07;
    pc1m[ j ] = ( pKey[ Value >> 3 ] & DES_ByteBit[ Mask ] ) ? 1 : 0;
  }

  for ( i = 0; i < 16; i++ )
  {
    if ( Decrypt )
      Mask = ( 15 - i ) << 1;
    else
      Mask = i << 1;

    Count = Mask + 1;
    KeyArray[ Mask ] = KeyArray[ Count ] = 0L;

    for ( j = 0; j < 28; j++ )
    {
      Value = j + DES_Totrot[ i ];

      if ( Value < 28 )
        pcr[ j ] = pc1m[ Value ];
      else
        pcr[ j ] = pc1m[ Value - 28 ];
    }

    for ( j = 28; j < 56; j++ )
    {
      Value = j + DES_Totrot[ i ];

      if ( Value < 56 )
        pcr[ j ] = pc1m[ Value ];
      else
        pcr[ j ] = pc1m[ Value - 28 ];
    }

    for ( j = 0; j < 24; j++ )
    {
      if ( pcr[ DES_Ctx->DES_PC2[ j ] ] )
        KeyArray[ Mask ] |= DES_BigByte[ j ];
      if ( pcr[ DES_Ctx->DES_PC2[ j + 24 ] ] )
        KeyArray[ Count ] |= DES_BigByte[ j ];
    }
  }

  for ( i = 0; i < 16; i++ )
  {
    pKeyExpanded[ i * 2 + 0 ] = ( KeyArray[ i * 2 + 0 ] & 0x00fc0000L ) << 6;
    pKeyExpanded[ i * 2 + 0 ] |= ( KeyArray[ i * 2 + 0 ] & 0x00000fc0L ) << 10;
    pKeyExpanded[ i * 2 + 0 ] |= ( KeyArray[ i * 2 + 1 ] & 0x00fc0000L ) >> 10;
    pKeyExpanded[ i * 2 + 0 ] |= ( KeyArray[ i * 2 + 1 ] & 0x00000fc0L ) >> 6;

    pKeyExpanded[ i * 2 + 1 ] = ( KeyArray[ i * 2 + 0 ] & 0x0003f000L ) << 12;
    pKeyExpanded[ i * 2 + 1 ] |= ( KeyArray[ i * 2 + 0 ] & 0x0000003fL ) << 16;
    pKeyExpanded[ i * 2 + 1 ] |= ( KeyArray[ i * 2 + 1 ] & 0x0003f000L ) >> 4;
    pKeyExpanded[ i * 2 + 1 ] |= ( KeyArray[ i * 2 + 1 ] & 0x0000003fL );
  }
}

void DES_Function( DES_Ctx_Typedef * DES_Ctx, uint32_t * Block2DWord,
  uint32_t * pKeyExpanded )
{
  uint32_t Round, Value;
  uint32_t LDWord, RDWord, ADWord;

  // DES_IP_Function
  LDWord = Block2DWord[ 0 ];
  RDWord = Block2DWord[ 1 ];

  ADWord = ( ( LDWord >> 4 ) ^ RDWord ) & 0x0F0F0F0FL;
  RDWord ^= ADWord;
  LDWord ^= ( ADWord << 4 );

  ADWord = ( ( LDWord >> 16 ) ^ RDWord ) & 0x0000FFFFL;
  RDWord ^= ADWord;
  LDWord ^= ( ADWord << 16 );

  ADWord = ( ( RDWord >> 2 ) ^ LDWord ) & 0x33333333L;
  LDWord ^= ADWord;
  RDWord ^= ( ADWord << 2 );

  ADWord = ( ( RDWord >> 8 ) ^ LDWord ) & 0x00FF00FFL;
  LDWord ^= ADWord;
  RDWord ^= ( ADWord << 8 );
  RDWord = ( ( RDWord << 1 ) | ( ( RDWord >> 31 ) & 1L ) );

  ADWord = ( LDWord ^ RDWord ) & 0xAAAAAAAAL;
  LDWord ^= ADWord;
  RDWord ^= ADWord;
  LDWord = ( ( LDWord << 1 ) | ( ( LDWord >> 31 ) & 1L ) );

  for ( Round = 0; Round < 8; Round++ )
  {
    ADWord = ( RDWord << 28 ) | ( RDWord >> 4 );

    ADWord ^= *pKeyExpanded++;
    Value = DES_Ctx->DES_SP[ 6 ][ ADWord & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 4 ][ ( ADWord >> 8 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 2 ][ ( ADWord >> 16 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 0 ][ ( ADWord >> 24 ) & 0x3fL ];

    ADWord = RDWord ^ *pKeyExpanded++;
    Value |= DES_Ctx->DES_SP[ 7 ][ ADWord & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 5 ][ ( ADWord >> 8 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 3 ][ ( ADWord >> 16 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 1 ][ ( ADWord >> 24 ) & 0x3fL ];
    LDWord ^= Value;

    ADWord = ( LDWord << 28 ) | ( LDWord >> 4 );
    ADWord ^= *pKeyExpanded++;
    Value = DES_Ctx->DES_SP[ 6 ][ ADWord & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 4 ][ ( ADWord >> 8 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 2 ][ ( ADWord >> 16 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 0 ][ ( ADWord >> 24 ) & 0x3fL ];

    ADWord = LDWord ^ *pKeyExpanded++;
    Value |= DES_Ctx->DES_SP[ 7 ][ ADWord & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 5 ][ ( ADWord >> 8 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 3 ][ ( ADWord >> 16 ) & 0x3fL ];
    Value |= DES_Ctx->DES_SP[ 1 ][ ( ADWord >> 24 ) & 0x3fL ];

    RDWord ^= Value;
  }

  // DES_FP_Function
  RDWord = ( RDWord << 31 ) | ( RDWord >> 1 );
  ADWord = ( LDWord ^ RDWord ) & 0xAAAAAAAAL;
  LDWord ^= ADWord;
  RDWord ^= ADWord;
  LDWord = ( LDWord << 31 ) | ( LDWord >> 1 );
  ADWord = ( ( LDWord >> 8 ) ^ RDWord ) & 0x00FF00FFL;
  RDWord ^= ADWord;
  LDWord ^= ( ADWord << 8 );
  ADWord = ( ( LDWord >> 2 ) ^ RDWord ) & 0x33333333L;
  RDWord ^= ADWord;
  LDWord ^= ( ADWord << 2 );
  ADWord = ( ( RDWord >> 16 ) ^ LDWord ) & 0x0000FFFFL;
  LDWord ^= ADWord;
  RDWord ^= ( ADWord << 16 );
  ADWord = ( ( RDWord >> 4 ) ^ LDWord ) & 0x0F0F0F0FL;
  LDWord ^= ADWord;
  RDWord ^= ( ADWord << 4 );

  Block2DWord[ 0 ] = RDWord;
  Block2DWord[ 1 ] = LDWord;
}

void DES_Init( DES_Ctx_Typedef * DES_Ctx, const uint8_t * DES_PC1,
  const uint8_t * DES_PC2, const DES_SP_Type * DES_SP, uint8_t * EKeyExpanded,
  uint8_t * DKeyExpanded )
{
  DES_Ctx->DES_PC1 = DES_PC1;
  DES_Ctx->DES_PC2 = DES_PC2;
  DES_Ctx->DES_SP = DES_SP;
  DES_Ctx->EKeyExpanded = EKeyExpanded;
  DES_Ctx->DKeyExpanded = DKeyExpanded;
}

// DES  : KeySize =  8
// 3DES : KeySize =  8 : K1 == K2 == K3
// 3DES : KeySize = 16 : K1, K2, K3 == K1
// 3DES : KeySize = 24 : K1, K2, K3
//
void DES_SetKey( DES_Ctx_Typedef * DES_Ctx, uint32_t Mode, uint8_t * KeyStr )
{
  uint8_t * pEKeyExpanded = DES_Ctx->EKeyExpanded;
  uint8_t * pDKeyExpanded = DES_Ctx->DKeyExpanded;

  if ( ( Mode & DES_KEY_3DES ) == 0 )
    DES_Ctx->KeyLen = 8;
  else // if ( Mode & DES_KEY_3DES )
  {
    DES_Ctx->KeyLen = 24;
    Mode |= DES_KEY_BOTH;
  }

  for ( uint32_t i = 0; i < 3; i++ )
  {
    if ( Mode & DES_KEY_ENC )
      DES_KeyExpand( DES_Ctx, (uint8_t *) ( KeyStr + ( i << 3 ) ),
        (uint32_t *) &pEKeyExpanded[ i * 32 * 4 ], DES_MODE_ENC );

    if ( Mode & DES_KEY_DEC )
      DES_KeyExpand( DES_Ctx, (uint8_t *) ( KeyStr + ( i << 3 ) ),
        (uint32_t *) &pDKeyExpanded[ i * 32 * 4 ], DES_MODE_DEC );

    if ( DES_Ctx->KeyLen == 8 )
      break;
  }
}

void DES_Crypt( DES_Ctx_Typedef * DES_Ctx, uint32_t Mode, uint32_t Size,
  uint8_t * pIv, uint8_t * pIvOut, uint8_t * pData, uint8_t * pDataOut )
{
  uint32_t IV[ 2 ], NV[ 2 ];

  //----------------------------------------------------------------------------
  // Pre Process -- Setup Key Table
  uint8_t * pKeyExpandedTable[ 3 ];

  if ( DES_Ctx->KeyLen == 8 ) // Decrypt : D1, Encrypt : E1
    pKeyExpandedTable[ 0 ] =
        ( Mode & DES_MODE_DEC ) ? DES_Ctx->DKeyExpanded : DES_Ctx->EKeyExpanded;
  else if ( ( Mode & DES_MODE_DEC ) )   // Decrypt : D3, E2, D1
  {
    pKeyExpandedTable[ 0 ] = DES_Ctx->DKeyExpanded + ( 2 ) * 32 * 4;
    pKeyExpandedTable[ 1 ] = DES_Ctx->EKeyExpanded + ( 1 ) * 32 * 4;
    pKeyExpandedTable[ 2 ] = DES_Ctx->DKeyExpanded + ( 0 ) * 32 * 4;
  }
  else // Encrypt : E1, D2, E3
  {
    pKeyExpandedTable[ 0 ] = DES_Ctx->EKeyExpanded + ( 0 ) * 32 * 4;
    pKeyExpandedTable[ 1 ] = DES_Ctx->DKeyExpanded + ( 1 ) * 32 * 4;
    pKeyExpandedTable[ 2 ] = DES_Ctx->EKeyExpanded + ( 2 ) * 32 * 4;
  }

  //----------------------------------------------------------------------------
  // Pre Process
  uint32_t * pDWordIv = 0;
  uint32_t * pDWordDataOut = (uint32_t *) pDataOut;

  if ( ( pIv == 0 ) && ( Mode & DES_MODE_CBC ) )
    return;

#if ( __LITTLE_ENDIAN__ > 0 )
  if ( pIv )
  {
    RevByteOrderDWordBuffer( (uint32_t *) IV, (uint32_t *) pIv, 2 );
    pDWordIv = (uint32_t *) IV;
  }

  // pData[] must be writable
  if ( pDataOut == 0 )
  {
    pDWordDataOut = (uint32_t *) pData;
  }

  // pDataOut[] must be writable
  // always even if pOutput == pInput
  if ( 1 )
  {
    RevByteOrderDWordBuffer( (uint32_t *) pDWordDataOut, (uint32_t *) pData,
      Size >> 2 );
  }

#else

  if ( pIv )
  {
    CopyDWordBuffer( (uint32_t *) IV, (uint32_t *) pIv, 2 );
    pDWordIv = (uint32_t *) IV;
  }

  // pData[] must be writable
  if ( pDataOut == 0 )
  {
    pDWordDataOut = (uint32_t *) pData;
  }

  // pOutput != pInput
  if ( pDWordDataOut != (uint32_t *) pData )
  {
    // pDataOut[] must be writable
    CopyDWordBuffer( (uint32_t *) pDWordDataOut, (uint32_t *) pData,
        Size >> 2 );
  }
#endif

  uint32_t SizeInQWord = Size >> 3;
  while ( SizeInQWord-- )
  {
    //--------------------------------------------------------------------------
    // Init Input or Update NV
    if ( pDWordIv )
    {
      if ( Mode & DES_MODE_DEC ) // Decrypt, Update NV
        CopyDWordBuffer( NV, pDWordDataOut, 2 );
      else
        // Encrypt, Init Input
        XorDWordBuffer( pDWordDataOut, pDWordIv, 2 );
    }

    for ( int32_t index = 0; index < 3; index++ )
    {
      DES_Function( DES_Ctx, pDWordDataOut,
        (uint32_t *) pKeyExpandedTable[ index ] );
      if ( DES_Ctx->KeyLen == 8 )
        break;
    }

    //--------------------------------------------------------------------------
    if ( pDWordIv )
    {
      if ( ( Mode & DES_MODE_DEC ) == 0 ) // Encrypt
        CopyDWordBuffer( pDWordIv, pDWordDataOut, 2 );
      else
      {
        // Update Output
        XorDWordBuffer( pDWordDataOut, pDWordIv, 2 );
        // Update IV
        CopyDWordBuffer( pDWordIv, NV, 2 );
      }
    }

    pDWordDataOut += 2;
  } // while ( SizeInQWord-- )

  uint32_t * pDWordIvOut = (uint32_t *) pIvOut;
#if ( __LITTLE_ENDIAN__ > 0 )
  if ( pDWordIv && pDWordIvOut )
  {
    RevByteOrderDWordBuffer( pDWordIvOut, pDWordIv, 2 );
  }
  pDWordDataOut -= Size >> 2;
  RevByteOrderDWordBuffer( (uint32_t *) pDWordDataOut,
    (uint32_t *) pDWordDataOut, Size >> 2 );
#else
  if ( pDWordIv && pDWordIvOut )  // pIv == pIvOut, pIv != pIvOut
  {
    CopyDWordBuffer( pDWordIvOut, pDWordIv, 2 );
  }
#endif
}

#include "des_vector.h"
#include "des_table.h"

static DES_Ctx_Typedef DES_Ctx;
static uint32_t DES_EKey[ 3 ][ 32 ];
static uint32_t DES_DKey[ 3 ][ 32 ];

uint32_t DES_Demo( void )
{
  volatile uint8_t Error;
  uint32_t ErrorIndex;

  uint8_t Plain[ 8 ];
  uint8_t Cipher[ 8 ];
  uint8_t Decrypted[ 8 ];
  uint8_t Encrypted[ 8 ];

  uint32_t cnt = DES_TestVectorValues2( );

  DES_Init( &DES_Ctx, DES_PC1, DES_PC2, DES_SP, (uint8_t *) &DES_EKey[ 0 ][ 0 ],
    (uint8_t *) &DES_DKey[ 0 ][ 0 ] );

  for ( uint32_t i = 0; i < cnt; i++ )
  {
    DES_SetKey( &DES_Ctx, DES_KEY_DEC, DES_TestVectorValueArray2[ i ].Key );
    DES_Crypt( &DES_Ctx, DES_ECB_DEC, 8, 0, 0,
      DES_TestVectorValueArray2[ i ].Cipher, Plain );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error |= ( Plain[ j ] ^ DES_TestVectorValueArray2[ i ].Plain[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES_SetKey( &DES_Ctx, DES_KEY_ENC, DES_TestVectorValueArray2[ i ].Key );
    DES_Crypt( &DES_Ctx, DES_ECB_ENC, 8, 0, 0, Plain, Encrypted );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error ^=
        ( Encrypted[ j ] ^ DES_TestVectorValueArray2[ i ].Encrypted[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }
  }

  cnt = DES_TestVectorValues( );
  cnt = 8;

  for ( uint32_t i = 0; i < cnt - 1; i++ )
  {
    DES_SetKey( &DES_Ctx, DES_KEY_ENC, DES_TestVectorValueArray[ i ].Key );
    DES_Crypt( &DES_Ctx, DES_ECB_ENC, 8, 0, 0,
      DES_TestVectorValueArray[ i ].Plain, Cipher );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error |= ( Cipher[ j ] ^ DES_TestVectorValueArray[ i ].Cipher[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES_SetKey( &DES_Ctx, DES_KEY_DEC, DES_TestVectorValueArray[ i ].Key );
    DES_Crypt( &DES_Ctx, DES_ECB_DEC, 8, 0, 0, Cipher, Decrypted );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error ^=
        ( Decrypted[ j ] ^ DES_TestVectorValueArray[ i ].Decrypted[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES_SetKey( &DES_Ctx, DES_KEY_ENC, DES_TestVectorValueArray[ i ].Key );
    DES_Crypt( &DES_Ctx, DES_ECB_ENC, 8, 0, 0,
      DES_TestVectorValueArray[ i ].Plain, Cipher );

    for ( uint32_t n = 1; n < 100; n++ )
      DES_Crypt( &DES_Ctx, DES_ECB_ENC, 8, 0, 0, Cipher, Cipher );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error |= ( Cipher[ j ] ^ DES_TestVectorValueArray[ i ].Cipher100[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES_SetKey( &DES_Ctx, DES_KEY_ENC, DES_TestVectorValueArray[ i ].Key );
    DES_Crypt( &DES_Ctx, DES_ECB_ENC, 8, 0, 0,
      DES_TestVectorValueArray[ i ].Plain, Cipher );

    for ( uint32_t n = 1; n < 1000; n++ )
      DES_Crypt( &DES_Ctx, DES_ECB_ENC, 8, 0, 0, Cipher, Cipher );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error |= ( Cipher[ j ] ^ DES_TestVectorValueArray[ i ].Cipher1000[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }
  }

  return ErrorIndex;
}

