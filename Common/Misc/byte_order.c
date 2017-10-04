#include "byte_order.h"
#include "bits.h"

// read a little-endian number from memory into native byte order.
uint16_t read_le16( const void* p )
{
  return to_le16( *(uint16_t* )p );
}

uint32_t read_le32( const void* p )
{
  return to_le32( *(uint32_t* )p );
}	// see read_le16

uint64_t read_le64( const void* p )
{
  return to_le64( *(uint64_t* )p );
}	// see read_le16

// read a big-endian number from memory into native byte order.
uint16_t read_be16( const void* p )
{
  return to_be16( *(uint16_t* )p );
}

uint32_t read_be32( const void* p )
{
  return to_be32( *(uint32_t* )p );
}	// see read_be16

uint64_t read_be64( const void* p )
{
  return to_be64( *(uint64_t* )p );
}	// see read_be16

// write a little-endian number to memory in native byte order.
void write_le16( void* p, uint16_t x )
{
  *(uint16_t*) p = to_le16( x );
}
void write_le32( void* p, uint32_t x )
{
  *(uint32_t*) p = to_le32( x );
}	// see write_le16
void write_le64( void* p, uint64_t x )
{
  *(uint64_t*) p = to_le64( x );
}	// see write_le16

// write a big-endian number to memory in native byte order.
void write_be16( void* p, uint16_t x )
{
  *(uint16_t*) p = to_be16( x );
}
void write_be32( void* p, uint32_t x )
{
  *(uint32_t*) p = to_be32( x );
}	// see write_be16
void write_be64( void* p, uint64_t x )
{
  *(uint64_t*) p = to_be64( x );
}	// see write_be16

/**
 * zero-extend \<size\> (truncated to 8) bytes of little-endian data to uint64_t,
 * starting at address \<p\> (need not be aligned).
 **/
uint32_t std_min( size_t a, size_t b )
{
  if ( a < b )
    return a;
  else
    return b;
}

uint64_t movzx_le64( const uint8_t * p, size_t size_bytes )
{
  uint64_t number = 0;
  for ( uint32_t i = 0; i < std_min( size_bytes, (size_t) 8u ); i++ )
    number |= ( (uint64_t) p[ i ] ) << ( i * 8 );
  
  return number;
}
uint64_t movzx_be64( const uint8_t * p, size_t size_bytes )
{
  uint64_t number = 0;
  for ( uint32_t i = 0; i < std_min( size_bytes, (size_t) 8u ); i++ )
  {
    number <<= 8;
    number |= p[ i ];
  }
  
  return number;
}

/**
 * sign-extend \<size\> (truncated to 8) bytes of little-endian data to int64_t,
 * starting at address \<p\> (need not be aligned).
 **/
inline int64_t SignExtend( uint64_t bits, size_t size_bytes )
{
  // no point in sign-extending if >= 8 bytes were requested
  if ( size_bytes < 8 )
  {
    const uint64_t sign_bit = BIT64( ( size_bytes * 8 ) - 1 );
    
    // number would be negative in the smaller type,
    // so sign-extend, i.e. set all more significant bits.
    if ( bits & sign_bit )
    {
      const uint64_t valid_bit_mask = ( sign_bit + sign_bit ) - 1;
      bits |= ~valid_bit_mask;
    }
  }
  
  const int64_t number = (int64_t) ( bits );
  return number;
}

int64_t movsx_le64( const uint8_t * p, size_t size_bytes )
{
  const uint64_t number = movzx_le64( p, size_bytes );
  return SignExtend( number, size_bytes );
}
int64_t movsx_be64( const uint8_t * p, size_t size_bytes )
{
  const uint64_t number = movzx_be64( p, size_bytes );
  return SignExtend( number, size_bytes );
}

#ifndef swap16
uint16_t swap16( const uint16_t x )
{
  return (uint16_t) ( ( ( x & 0xff ) << 8 ) | ( x >> 8 ) );
}
#endif

#ifndef swap32
uint32_t swap32( const uint32_t x )
{
  return ( x << 24 ) | ( x >> 24 ) | ( ( x << 8 ) & 0x00ff0000 )
    | ( ( x >> 8 ) & 0x0000ff00 );
}
#endif

#ifndef swap64
uint64_t swap64( const uint64_t x )
{
  const uint32_t lo = (uint32_t) ( x & 0xFFFFFFFF );
  const uint32_t hi = (uint32_t) ( x >> 32 );
  uint64_t ret = swap32( lo );
  ret <<= 32;
  // careful: must shift var of type uint64_t, not uint32_t
  ret |= swap32( hi );
  return ret;
  
}
#endif
