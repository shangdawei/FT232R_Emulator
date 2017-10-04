#include "crc.h"
#include "utility.h"
/*
 * Functions For Table Calculation
 *
 * The following function can be used to calculate a CRC lookup table.
 * It can also be used at run-time to create or check static tables.
 * Returns the i'th entry for the lookup table for the specified algorithm.
 * The function examines the fields cm_width, cm_poly, cm_refin, and the
 * argument table index in the range [0,255] and returns the table entry in
 * the bottom cm_width bytes of the return value.
 */
uint32_t CRC_TableGen( CRC_Model_TypeDef * CRC_Model, int32_t index )
{
  int32_t i;
  uint32_t r;
  uint32_t topbit = BITMASK( CRC_Model->Width - 1 );
  uint32_t inbyte = (uint32_t) index;

  if ( CRC_Model->RevIn )
    inbyte = RevBitOrder( inbyte, 8 );

  r = inbyte << ( CRC_Model->Width - 8 );
  for ( i = 0; i < 8; i++ )
    if ( r & topbit )
      r = ( r << 1 ) ^ CRC_Model->Poly;
    else
      r <<= 1;

  if ( CRC_Model->RevIn )
    r = RevBitOrder( r, CRC_Model->Width );

  return r & WidthMask( CRC_Model->Width );
}

/*
 * Initializes the argument CRC model instance.
 * All parameter fields must be set before calling this.
 */
void CRC_Init( CRC_Model_TypeDef * CRC_Model )
{
  CRC_Model->Reg = CRC_Model->Rem1 ? 0xFFFFFFFF : 0;
  CRC_Model->TopBit = BITMASK( CRC_Model->Width - 1 );
}

// Processes a single message byte [0,255]
// Left Shifting : shiftout <<< [ B7..B0 ] <<< 0
//
void CRC_DoByte( CRC_Model_TypeDef * CRC_Model, uint32_t InByte )
{
  if ( CRC_Model->RevIn )
    InByte = RevBitOrder( InByte, 8 );

  CRC_Model->Reg ^= ( InByte << ( CRC_Model->Width - 8 ) );

  for ( uint32_t i = 0; i < 8; i++ )
  {
    if ( CRC_Model->Reg & CRC_Model->TopBit )
      CRC_Model->Reg = ( CRC_Model->Reg << 1 ) ^ CRC_Model->Poly;
    else
      CRC_Model->Reg <<= 1;

    CRC_Model->Reg &= WidthMask( CRC_Model->Width );
  }
}

// Processes a block of message bytes.
void CRC_DoBlock( CRC_Model_TypeDef * CRC_Model, uint32_t BlockLength,
  uint8_t * pBlock )
{
  while ( BlockLength-- )
    CRC_DoByte( CRC_Model, *pBlock++ );
}

// Returns the CRC value for the message bytes processed so far.
uint32_t CRC_Done( CRC_Model_TypeDef * CRC_Model )
{
  if ( CRC_Model->RevOut )
    return CRC_Model->XorOut ^ RevBitOrder( CRC_Model->Reg, CRC_Model->Width );
  else
    return CRC_Model->XorOut ^ CRC_Model->Reg;
}

//******************************************************************************
// CRC32
//******************************************************************************
//
// Multiple Bits At Once : When using a pre-computed look-up table
// The look-up table contains every 16th entry of the standard look-up table
// table_16[i] = table_256[ 16*i ]
//
void CRC32_NibbleTableGen( uint32_t * table, uint32_t * table_rev )
{
  for ( uint32_t i = 0; i <= 16; i++ )
  {

#if (0) // Error !!!
    uint32_t crc = ( i << 24 ) << 4;
#else
    uint32_t crc = ( i << 24 );
#endif

    uint32_t crc_rev = i << 4;

    for ( uint32_t j = 0; j < 8; j++ )
    {
      crc = ( crc << 1 ) ^ ( ( crc & 0x80000000 ) ? CRC32_Poly : 0 );
      crc_rev = ( crc_rev >> 1 ) ^ ( ( crc_rev & 1 ) ? CRC32R_Poly : 0 );
    }

    table[ i ] = crc;
    table_rev[ i ] = crc_rev;
  }
}

void CRC32_ByteTableGen( uint32_t * table, uint32_t * table_rev )
{
  for ( uint32_t i = 0; i <= 0xFF; i++ )
  {
    uint32_t crc = ( i << 24 );
    uint32_t crc_rev = i;
    for ( uint32_t j = 0; j < 8; j++ )
    {
      crc = crc & 0x80000000 ? ( crc << 1 ) ^ CRC32_Poly : crc << 1;
      crc_rev = crc_rev & 1 ? ( crc_rev >> 1 ) ^ CRC32R_Poly : crc_rev >> 1;
    }

    table[ i ] = crc;
    table_rev[ i ] = crc_rev;
  }
}

// The basic algorithm processes the input data bit-by-bit:
uint32_t CRC32R_BitWise0( uint32_t crc32, uint32_t length, uint8_t * data )
{
  uint32_t crc_rev = crc32;
  while ( length-- )
  {
    crc_rev ^= *data++;
    for ( uint32_t i = 0; i < 8; i++ )
    {
      if ( crc_rev & 1 )
        crc_rev = ( crc_rev >> 1 ) ^ CRC32R_Poly;
      else
        crc_rev = ( crc_rev >> 1 );
    }
  }

  return crc_rev;
}

// The basic algorithm processes the input data bit-by-bit:
uint32_t CRC32R_BitWise1( uint32_t crc32, uint32_t length, uint8_t * data )
{
  uint32_t crc_rev = crc32;
  while ( length-- )
  {
    crc_rev ^= *data++;
    for ( uint32_t i = 0; i < 8; i++ )
      crc_rev = ( crc_rev >> 1 ) ^ ( -(int32_t) ( crc_rev & 1 ) & CRC32R_Poly );
  }

  return crc_rev;
}

// Ether Poly : 0x4C11DB70
// LFSR <<<<< FirstByte[MSB<<<<<LSB] ... LastByte[MSB<<<<<LSB] : Left Shifting
//
// Calculate bitwise big-endian Ethernet
// The basic algorithm processes the input data bit-by-bit
uint32_t CRC32_BitWise( uint32_t crc32, uint32_t length, uint8_t * data )
{
  uint32_t crc = crc32;     // 0xFFFFFFFF for Ethernet
  while ( length-- )
  {
    crc ^= *data++ << 24;
    for ( uint32_t i = 0; i < 8; i++ )
    {
      // crc = crc & 0x80000000 ? ( crc << 1 ) ^ CRC32_Poly : crc << 1;
      crc = ( crc << 1 ) ^ ( ( crc & 0x80000000 ) ? CRC32_Poly : 0 );
    }
  }

  return crc;
}

// Ether Poly : 0xEDB88320
// LastByte[MSB>>>>>LSB]....FirstByte[MSB>>>>>LSB] >>>>> LFSR : Right Shifting
//
// Calculate bitwise little-endian Ethernet
// The basic algorithm processes the input data bit-by-bit
uint32_t CRC32R_BitWise( uint32_t crc32, uint32_t length, uint8_t * data )
{
  uint32_t crc_rev = crc32;   // 0xFFFFFFFF for Ethernet
  while ( length-- )
  {
    crc_rev ^= *data++;
    for ( uint32_t i = 0; i < 8; i++ )
      crc_rev = crc_rev & 1 ? ( crc_rev >> 1 ) ^ CRC32R_Poly : crc_rev >> 1;
  }

  return crc_rev;
}

// CRC32_Nibble_GenTable()
extern const uint32_t CRC32_Nibble_Table[ 16 ];
uint32_t CRC32_Nibble( uint32_t crc32, uint32_t length, uint8_t * data )
{
  uint32_t crc = crc32;
  while ( length-- )
  {
    crc ^= *data++ << 24;
    crc = ( crc << 4 ) ^ CRC32_Nibble_Table[ crc >> 28 ];
    crc = ( crc << 4 ) ^ CRC32_Nibble_Table[ crc >> 28 ];
  }

  return crc;
}

static uint32_t CRC32_Nibble_DWord( uint32_t crc32, uint32_t data )
{
  crc32 ^= data;
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  crc32 = ( crc32 << 4 ) ^ CRC32_Nibble_Table[ crc32 >> 28 ];
  return crc32;
}

uint32_t CRC32_Nibble_Padded( uint32_t crc32, uint32_t length, uint8_t * data,
  uint32_t Pad1 )
{
#if ( __ARM_PROFILE_M__ > 0 )

  uint32_t NumOfDWord = length >> 2;
  uint32_t NumOfTailByte = length & 3;
  uint32_t LastDWord;

  uint32_t * pData = (uint32_t *) data;
  while ( NumOfDWord-- )
  {
    crc32 = CRC32_Nibble_DWord( crc32, *pData++ );
  }

  if ( NumOfTailByte )
  {
    // 0xAABBCC00
    LastDWord = ( *pData ) << ( ( 4 - NumOfTailByte ) << 3 );
    if ( Pad1 )
    {
      Pad1 = 0xFFFFFFFF;
      Pad1 >>= ( NumOfTailByte << 3 );   // 0x000000FF
      LastDWord |= Pad1;   // 0xAABBCCFF = 0xAABBCC00 | 0x000000FF
    }
    crc32 = CRC32_Nibble_DWord( crc32, LastDWord );
  }

  return crc32;
#else
  uint32_t NumOfDWord = length >> 2;
  uint32_t NumOfTailByte = length & 3;
  uint32_t LastDWord;

  while ( NumOfDWord-- )
  {
    LastDWord = *data++;
    LastDWord <<= 8;
    LastDWord = *data++;
    LastDWord <<= 8;
    LastDWord = *data++;
    LastDWord <<= 8;
    LastDWord = *data++;
    LastDWord <<= 8;
    crc32 = CRC32_Nibble_DWord( crc32, LastDWord );
  }

  if ( NumOfTailByte )
  {
    int32_t i = NumOfTailByte + 1;
    while ( i > 1 )
    {
      i--;
      LastDWord = data[ i ];
      LastDWord <<= 8;
    }

    if ( Pad1 )
    {
      Pad1 >>= ( NumOfTailByte << 3 );  // 0x000000PP
      LastDWord |= Pad1;// 0xAABBCCPP = 0xAABBCC00 | 0x000000PP
    }
    crc32 = CRC32_Nibble_DWord( crc32, LastDWord );
  }
  return crc32;
#endif
}

// CRC32_Nibble_GenTable()
extern const uint32_t CRC32_Nibble_Table_REV[ 16 ];
uint32_t CRC32R_Nibble( uint32_t crc32, uint32_t length, uint8_t * data )
{
  uint32_t crc_rev = crc32;
  while ( length-- )
  {
    crc_rev ^= *data++;
    crc_rev = ( crc_rev >> 4 ) ^ CRC32_Nibble_Table_REV[ crc_rev & 0x0F ];
    crc_rev = ( crc_rev >> 4 ) ^ CRC32_Nibble_Table_REV[ crc_rev & 0x0F ];
  }

  return crc_rev;
}

// CRC32_Byte_GenTable()
extern const uint32_t CRC32_Byte_Table[ 256 ];
uint32_t CRC32_Byte( uint32_t crc32, uint32_t length, uint8_t * data,
  uint32_t * table )
{
  uint32_t crc = crc32; // ^ 0xFFFFFFFF
  if ( table == 0 )
    crc = CRC32_Nibble( crc32, length, data );
  else
  {
    while ( length-- )
      crc = ( crc << 8 ) ^ table[ ( crc >> 24 ) ^ *data++ ];
  }

  return crc; // ^ 0xFFFFFFFF
}

// CRC32_Byte_GenTable( table );
extern const uint32_t CRC32_Byte_Table_REV[ 256 ];
uint32_t CRC32R_Byte( uint32_t crc32, uint32_t length, uint8_t * data,
  uint32_t * table )
{
  uint32_t crc_rev = crc32; // ^ 0xFFFFFFFF

  if ( table == 0 )
    crc_rev = CRC32R_Nibble( crc32, length, data );
  else
  {
    while ( length-- )
      crc_rev = ( crc_rev >> 8 ) ^ table[ ( crc_rev & 0xFF ) ^ *data++ ];
  }

  return crc_rev; // ^ 0xFFFFFFFF
}

// STM32 : DWORD, MSB first, left shift
//
// dword = pData[0] | ( pData[1] << 8 ) | ( pData[2] << 16 ) | ( pData[3] << 24 )
// dword = *(uint32_t *)&pData[0];
//
uint32_t CRC32_Padded( uint32_t Pad1, uint32_t InitValue, uint32_t Length,
  uint8_t * pData, uint32_t * table )
{
  uint32_t Crc32 = InitValue;
  Crc32 = CRC32_Byte( Crc32, Length, pData, table );

  return Crc32;
}

uint32_t CRC32R_Padded( uint32_t Pad1, uint32_t InitValue, uint32_t Length,
  uint8_t * pData, uint32_t * table )
{
  uint32_t Crc32 = InitValue;
  Crc32 = CRC32R_Byte( Crc32, Length, pData, table );

  return Crc32;
}

/*
 * CRC8 for Dallas 1 wire ROM
 */
uint8_t CRC8_DS2432_ROM( uint32_t Size, uint8_t * pData )
{
  uint8_t CRC8 = 0;
  for ( uint32_t i = 0; i < Size; i++ )
    CRC8 = CRC8_DS2432_ROM_Table[ CRC8 ^ pData[ i ] ];
  return CRC8;
}

uint8_t CRC8_DS2432_ROM_Demo( void )
{
  uint8_t RetValue;
  uint8_t Data[ ] =
  { 0x33, 0xA0, 0x02, 0x7F, 0x00, 0x00, 0x00, 0xBE };

  RetValue = CRC8_DS2432_ROM( 7, Data );
  if ( RetValue == 0xBE )
    RetValue = CRC8_DS2432_ROM( 8, Data );
  if ( RetValue == 0x00 )
    return RetValue;
  return 0;
}

uint32_t CRC32_Byte_REV_Demo( void )
{
  uint32_t crc32_rev;
  uint8_t Data[ ] =
  { 0x03, 0x23, 0x46, 0x67, 0x89, 0xAB, 0xCD, 0xEF };

  crc32_rev = CRC32R_BitWise( 0xFFFFFFFF, 1, Data );
  crc32_rev = CRC32R_Byte( 0xFFFFFFFF, 1, Data, 0 );
  return crc32_rev;
}

#include "crc_driver.h"

const CRC_Driver_TypeDef CRC_Software =
{ CRC_Init, CRC_DoByte, CRC_DoBlock, CRC_Done };

