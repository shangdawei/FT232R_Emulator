#include "des_vector.h"
#include "utility.h"

//------------------------------------------------------------------------------
// DES_MODE_EBC : DES_MODE_DES  : DES_MODE_ENC
// DES_MODE_CBC : DES_MODE_3DES : DES_MODE_DEC
//
#define DES_MODE_ENC        ( 0<<0 )
#define DES_MODE_DEC        ( 1<<0 )
#define DES_MODE_3DES       ( 1<<1 )
#define DES_MODE_CBC        ( 1<<2 )
//

//------------------------------------------------------------------------------
// Mode
//
#define DES_ECB_ENC         ( DES_MODE_ENC )
#define DES_ECB_DEC         ( DES_MODE_DEC )

#define DES_CBC_ENC         ( DES_ECB_ENC | DES_MODE_CBC )
#define DES_CBC_DEC         ( DES_ECB_DEC | DES_MODE_CBC )

#define DES3_ECB_ENC        ( DES_ECB_ENC | DES_MODE_3DES )
#define DES3_ECB_DEC        ( DES_ECB_DEC | DES_MODE_3DES )

#define DES3_CBC_ENC        ( DES_CBC_ENC | DES_MODE_3DES )
#define DES3_CBC_DEC        ( DES_CBC_DEC | DES_MODE_3DES )

const uint8_t DES_RotateTimes[ 16 ] =
{ 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

const uint8_t DES_IP[ 64 ] =
{ 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37,
  29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7, 56, 48, 40, 32, 24, 16, 8, 0,
  58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38,
  30, 22, 14, 6 };

const uint8_t DES_FP[ 64 ] =
{ 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13,
  53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
  34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48,
  16, 56, 24 };

const uint8_t DES_P[ 32 ] =
{ 15, 6, 19, 20, 28, 11, 27, 16, 0, 14, 22, 25, 4, 17, 30, 9, 1, 7, 23, 13, 31,
  26, 2, 8, 18, 12, 29, 5, 21, 10, 3, 24 };

const uint8_t DES_E[ 48 ] =
{ 31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 11, 12, 13, 14, 15,
  16, 15, 16, 17, 18, 19, 20, 19, 20, 21, 22, 23, 24, 23, 24, 25, 26, 27, 28,
  27, 28, 29, 30, 31, 0 };

/* Use the key schedule specified in the Standard (ANSI X3.92-1981). */
const uint8_t DES_PC1[ 56 ] =
{ 56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34,
  26, 18, 10, 2, 59, 51, 43, 35, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37,
  29, 21, 13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27, 19, 11, 3 };

const uint8_t DES_PC2[ 48 ] =
{ 13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26,
  19, 12, 1, 40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47, 43, 48, 38, 55, 33,
  52, 45, 41, 49, 35, 28, 31 };

const uint8_t DES_SBOX[ 8 ][ 4 ][ 16 ] =
{
{
{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } }, //S1

  {
  { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
  { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
  { 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
  { 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } }, //S2

  {
  { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
  { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
  { 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
  { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } }, //S3

  {
  { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
  { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
  { 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
  { 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } }, //S4

  {
  { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
  { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
  { 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
  { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } }, //S5

  {
  { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
  { 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
  { 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
  { 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 } }, //S6

  {
  { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
  { 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
  { 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
  { 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } }, //S7
  {
  { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
  { 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
  { 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
  { 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } } }; //S8

//------------------------------------------------------------------------------
// des.c
//

/******************************************************************************/
/*                                                                            */
/******************************************************************************/
static uint8_t DES1_IV[ 8 ];
static uint32_t DES1_EKey[ 16 ][ 48 ];
static uint32_t DES1_DKey[ 16 ][ 48 ];

//循环左移
void DES1_ROL( uint8_t *data_a, uint8_t time )
{
  uint8_t temp[ 56 ], i;

  //保存将要循环移动到左边的位
  for ( i = 0; i < time; i++ )
  {
    temp[ i ] = *( data_a + i );
    temp[ time + i ] = *( data_a + 28 + i );
  }

  for ( i = 0; i <= 28 - time; i++ )
  {
    *( data_a + i ) = *( data_a + time + i );
    *( data_a + 28 + i ) = *( data_a + 28 + time + i );
  }

  for ( i = 0; i < time; i++ )
  {
    *( data_a + 28 - time + i ) = temp[ i ];
    *( data_a + 56 - time + i ) = temp[ i + time ];
  }

}

//循环右移
void DES1_ROR( uint8_t *data_a, uint8_t time )
{
  uint8_t temp[ 56 ], i;

  //保存将要循环移动到右边的位
  for ( i = 0; i < time; i++ )
  {
    temp[ time - 1 - i ] = *( data_a + 28 - 1 - i );
    temp[ time + 1 - i ] = *( data_a + 56 - 1 - i );
  }

  for ( i = 0; i <= 28 - time; i++ )
  {
    *( data_a + 27 - i ) = *( data_a + 27 - time - i );
    *( data_a + 55 - i ) = *( data_a + 55 - time - i );
  }

  for ( i = 0; i < time; i++ )
  {
    *( data_a + i ) = temp[ i ];
    *( data_a + 28 + i ) = temp[ i + 2 ];
  }
}

//异或
void DES1_XOR( uint8_t * R, uint8_t * L, uint8_t count )
{
  uint8_t cnt;
  for ( cnt = 0; cnt < count; cnt++ )
  {
    R[ cnt ] ^= L[ cnt ];
  }
}

//交换
void DES1_SWAP( uint8_t * left, uint8_t * right )
{
  uint8_t temp[ 32 ];
  memcpy( temp, left, 32 );
  memcpy( left, right, 32 );
  memcpy( right, temp, 32 );
}

//密钥置换1
void DES1_PC1_Transform( uint8_t * KeyExpanded_64Bits,
  uint8_t * KeyExpanded_PC1 )
{
  uint8_t cnt;

  for ( cnt = 0; cnt < 56; cnt++ )
  {
    KeyExpanded_PC1[ cnt ] = KeyExpanded_64Bits[ DES_PC1[ cnt ] ];
  }
}

//密钥置换2
void DES1_PC2_Transform( uint8_t * KeyExpanded_PC1, uint8_t * KeyExpanded_PC2 )
{
  uint8_t cnt;
  for ( cnt = 0; cnt < 48; cnt++ )
  {
    KeyExpanded_PC2[ cnt ] = KeyExpanded_PC1[ DES_PC2[ cnt ] ];
  }

}

//IP置换
void DES1_IP_Transform( uint8_t * data_a )
{
  uint8_t cnt;
  uint8_t temp[ 64 ];

  for ( cnt = 0; cnt < 64; cnt++ )
  {
    temp[ cnt ] = data_a[ DES_IP[ cnt ] ];
  }
  memcpy( data_a, temp, 64 );

}

//IP逆置换
void DES1_FP_Transform( uint8_t * data_a )
{
  uint8_t cnt;
  uint8_t temp[ 64 ];

  for ( cnt = 0; cnt < 64; cnt++ )
  {
    temp[ cnt ] = data_a[ DES_FP[ cnt ] ];
  }
  memcpy( data_a, temp, 64 );
}

//P置换
void DES1_P_Transform( uint8_t * data_a )
{
  uint8_t cnt;
  uint8_t temp[ 32 ];
  for ( cnt = 0; cnt < 32; cnt++ )
  {
    temp[ cnt ] = data_a[ DES_P[ cnt ] ];
  }
  memcpy( data_a, temp, 32 );

}

//扩展置换
void DES1_E_Transform( uint8_t * data_a )
{
  uint8_t cnt;
  uint8_t temp[ 48 ];

  for ( cnt = 0; cnt < 48; cnt++ )
  {
    temp[ cnt ] = data_a[ DES_E[ cnt ] ];
  }

  memcpy( data_a, temp, 48 );

}

//S盒置换
void DES1_S_Transform( uint8_t * data_a )
{

  uint8_t cnt;
  uint8_t lines, row;
  uint8_t cur1, cur2;
  uint8_t output;

  //逆初始置换表IP^-1
  for ( cnt = 0; cnt < 8; cnt++ )
  {
    cur1 = cnt * 6;
    cur2 = cnt << 2;

    //计算在S盒中的行与列
    lines = ( data_a[ cur1 ] << 1 ) + data_a[ cur1 + 5 ];
    row = ( data_a[ cur1 + 1 ] << 3 ) + ( data_a[ cur1 + 2 ] << 2 )
      + ( data_a[ cur1 + 3 ] << 1 ) + data_a[ cur1 + 4 ];

    output = DES_SBOX[ cnt ][ lines ][ row ];

    //化为2进制
    data_a[ cur2 ] = ( output & 0X08 ) >> 3;
    data_a[ cur2 + 1 ] = ( output & 0X04 ) >> 2;
    data_a[ cur2 + 2 ] = ( output & 0X02 ) >> 1;
    data_a[ cur2 + 3 ] = output & 0x01;
  }
}

void DES1_KeyExpand( uint8_t * pKey, uint8_t * pKeyExpand, uint32_t Decrypt )
{
  uint8_t Round;
  uint8_t KeyBlock_8Bytes[ 8 ];
  uint8_t KeyExpanded_64Bits[ 64 ];
  uint8_t KeyExpanded_PC1[ 56 ];

  typedef void (*DES1_ROX_FUNC)( uint8_t *data_a, uint8_t time );
  DES1_ROX_FUNC DES1_ROX_Func;

  if ( Decrypt == 0 )
    DES1_ROX_Func = DES1_ROL;         // Left Shift for Encrypt
  else
    DES1_ROX_Func = DES1_ROR;         // Right Shift for Decrypt

  memcpy( KeyBlock_8Bytes, pKey, 8 );
  Byte8ToBit64( KeyBlock_8Bytes, KeyExpanded_64Bits ); //将密钥转换为二进制流
  DES1_PC1_Transform( KeyExpanded_64Bits, KeyExpanded_PC1 );  //PC1置换

  if ( 0 )
  {
    // Left Shift for Encrypt
    if ( Decrypt == 0 )
      DES1_ROX_Func( KeyExpanded_PC1, DES_RotateTimes[ 0 ] );

    for ( Round = 1; Round < 16; Round++ )
    {
      DES1_ROX_Func( KeyExpanded_PC1, DES_RotateTimes[ Round ] );

      //生成子密钥
      DES1_PC2_Transform( KeyExpanded_PC1, &pKeyExpand[ 48 * Round ] );
    }
  }
  else
  {
    if ( Decrypt == 0 )
    {
      for ( Round = 0; Round < 16; Round++ )
      {
        DES1_ROL( KeyExpanded_PC1, DES_RotateTimes[ Round ] );    //左移
        DES1_PC2_Transform( KeyExpanded_PC1, &pKeyExpand[ 48 * Round ] ); //生成子密钥
      }
    }
    else
    {
      for ( Round = 0; Round < 16; Round++ )
      {
        if ( Round != 0 )
          DES1_ROR( KeyExpanded_PC1, DES_RotateTimes[ Round ] );   //右移

        DES1_PC2_Transform( KeyExpanded_PC1, &pKeyExpand[ 48 * Round ] ); //生成子密钥
      }
    }
  }
}

//------------------------------------------------------------------------------
// 单个分组 : 8 Bytes
//------------------------------------------------------------------------------
void DES1_Function( uint8_t *iData, uint8_t *oData,
  uint8_t * KeyExpandedArray_PC2 )
{
  uint8_t Data_64Bits[ 64 ];
  uint8_t Right_48Bits[ 48 ];

  uint8_t Round;

  Byte8ToBit64( iData, Data_64Bits );
  //初始置换（IP置换）
  DES1_IP_Transform( Data_64Bits );

  //16轮迭代
  for ( Round = 0; Round < 16; Round++ )
  {
    memcpy( Right_48Bits, Data_64Bits + 32, 32 );
    //将右半部分进行扩展置换，从32位扩展到48位
    DES1_E_Transform( Right_48Bits );
    //将右半部分与子密钥进行异或操作
    DES1_XOR( Right_48Bits, &KeyExpandedArray_PC2[ Round * 48 ], 48 );
    //异或结果进入S盒，输出32位结果
    DES1_S_Transform( Right_48Bits );
    //P置换
    DES1_P_Transform( Right_48Bits );
    //将明文左半部分与右半部分进行异或
    DES1_XOR( Data_64Bits, Right_48Bits, 32 );
    if ( Round != 15 )
    {
      //最终完成左右部的交换
      DES1_SWAP( Data_64Bits, Data_64Bits + 32 );
    }
  }
  //逆初始置换（IP^1置换）
  DES1_FP_Transform( Data_64Bits );
  Bit64ToByte8( Data_64Bits, oData );
}

void DES1_SetIv( uint8_t * pIv )
{
  uint32_t * pDWord;
  if ( pIv )
  {
    pDWord = (uint32_t *) pIv;
    DES1_IV[ 0 ] = *pDWord++;
    DES1_IV[ 1 ] = *pDWord++;
  }
}

//------------------------------------------------------------------------------
// pKeyExpanded : uint32_t DES1_EKey[ 16 ][ 48 ];
// pKeyExpanded : uint32_t DES1_DKey[ 16 ][ 48 ];
//
// pKeyExpanded : uint32_t DES3_EKey[ 3 ][ 16 ][ 48 ];
// pKeyExpanded : uint32_t DES3_DKey[ 3 ][ 16 ][ 48 ];
//
void DES1_SetKey( uint32_t Mode, uint8_t *pKey, uint8_t * pKeyExpanded )
{
  uint32_t XorTable[ 3 ] =
  {
    DES_MODE_ENC, DES_MODE_DEC, DES_MODE_ENC };

  if ( ( Mode & DES_MODE_3DES ) == 0 )
    DES1_KeyExpand( pKey + ( 0 * 8 ), &pKeyExpanded[ 0 * 16 * 48 ],
      ( Mode & DES_MODE_DEC ) );
  else
  {
    for ( uint32_t i = 0; i < 3; i++ )
    {
      DES1_KeyExpand( pKey + ( i * 8 ), &pKeyExpanded[ i * 16 * 48 ],
        ( Mode & DES_MODE_DEC ) ^ XorTable[ i ] );
    }
  }
}

void DES1_Crypt( uint32_t Mode, uint32_t Size, uint8_t * pKeyExpanded,
  uint8_t * pData, uint8_t * pOutput )
{
  uint8_t NV[ 8 ];
  uint32_t SizeOfQWord = Size >> 3;
  uint8_t * pOut = pOutput;
  if ( pOut == 0 )
    pOut = pData;

  if ( Mode & DES_MODE_CBC )
  {
    // save to decrypt next block
    if ( Mode & DES_MODE_DEC )
      memcpy( NV, pData, 8 );
    else
      DES1_XOR( pData, DES1_IV, 8 );
  }

  while ( SizeOfQWord-- )
  {

    if ( ( Mode & DES_MODE_3DES ) == 0 )
      DES1_Function( pData, pOut, &pKeyExpanded[ 0 * 16 * 48 ] );
    else
    {
      if ( ( Mode & DES_MODE_DEC ) == 0 )
      {
        for ( int32_t index = 0; index < 3; index++ )
          DES1_Function( pData, pOut, &pKeyExpanded[ index * 16 * 48 ] );
      }
      else
      {
        for ( int32_t index = 2; index >= 0; index-- )
          DES1_Function( pData, pOut, &pKeyExpanded[ index * 16 * 48 ] );
      }
    }

    if ( Mode & DES_MODE_CBC )
    {
      if ( Mode & DES_MODE_DEC )
      {
        DES1_XOR( pData, DES1_IV, 8 );         // iv <-- nv <-- pData
        memcpy( DES1_IV, NV, 8 );            // iv from nv is encrypted data
        memcpy( NV, pData + 8, 8 );     // nv is encrypted data
      }
      else if ( SizeOfQWord )
        DES1_XOR( pData + 8, pData, 8 );  // nv is encrypted data
    }

    pData += 8;
    pOut += 8;
  }

  // save to encrypt next block
  if ( Mode & DES_MODE_DEC )
    return;

  memcpy( DES1_IV, pData - 8, 8 );
}


uint32_t DES1_Demo( void )
{
  uint8_t Error;
  uint32_t ErrorIndex;

  uint8_t Plain[ 8 ];
  uint8_t Cipher[ 8 ];
  uint8_t Decrypted[ 8 ];
  uint8_t Encrypted[ 8 ];

  uint32_t cnt = DES_TestVectorValues2( );

  cnt = 8;
  for ( uint32_t i = 0; i < cnt - 1; i++ )
  {
    DES1_SetKey( DES_ECB_DEC, DES_TestVectorValueArray2[ i ].Key,
      (uint8_t *) DES1_DKey );
    DES1_Crypt( DES_ECB_DEC, 8, (uint8_t *) DES1_DKey,
      DES_TestVectorValueArray2[ i ].Cipher, Plain );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error ^= ( Plain[ j ] ^ DES_TestVectorValueArray2[ i ].Plain[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES1_SetKey( DES_ECB_ENC, DES_TestVectorValueArray2[ i ].Key,
      (uint8_t *) DES1_EKey );
    DES1_Crypt( DES_ECB_ENC, 8, (uint8_t *) DES1_EKey, Plain, Encrypted );

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
    DES1_SetKey( DES_ECB_ENC, DES_TestVectorValueArray[ i ].Key,
      (uint8_t *) DES1_EKey );
    DES1_Crypt( DES_ECB_ENC, 8, (uint8_t *) DES1_EKey,
      DES_TestVectorValueArray[ i ].Plain, Cipher );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error ^= ( Cipher[ j ] ^ DES_TestVectorValueArray[ i ].Cipher[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES1_SetKey( DES_ECB_DEC, DES_TestVectorValueArray[ i ].Key,
      (uint8_t *) DES1_DKey );
    DES1_Crypt( DES_ECB_DEC, 8, (uint8_t *) DES1_DKey, Cipher, Decrypted );

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

    DES1_SetKey( DES_ECB_ENC, DES_TestVectorValueArray[ i ].Key,
      (uint8_t *) DES1_EKey );
    DES1_Crypt( DES_ECB_ENC, 8, (uint8_t *) DES1_EKey,
      DES_TestVectorValueArray[ i ].Plain, Cipher );

    for ( uint32_t n = 1; n < 100; n++ )
      DES1_Crypt( DES_ECB_ENC, 8, (uint8_t *) DES1_EKey, Cipher, Cipher );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error ^= ( Cipher[ j ] ^ DES_TestVectorValueArray[ i ].Cipher100[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }

    DES1_SetKey( DES_ECB_ENC, DES_TestVectorValueArray[ i ].Key,
      (uint8_t *) DES1_EKey );
    DES1_Crypt( DES_ECB_ENC, 8, (uint8_t *) DES1_EKey,
      DES_TestVectorValueArray[ i ].Plain, Cipher );

    for ( uint32_t n = 1; n < 1000; n++ )
      DES1_Crypt( DES_ECB_ENC, 8, (uint8_t *) DES1_EKey, Cipher, Cipher );

    Error = 0;
    for ( uint32_t j = 0; j < 8; j++ )
      Error ^= ( Cipher[ j ] ^ DES_TestVectorValueArray[ i ].Cipher1000[ j ] );
    if ( Error )
    {
      ErrorIndex = i;
      for ( ;; )
        ;
    }
  }

  return ErrorIndex;
}
