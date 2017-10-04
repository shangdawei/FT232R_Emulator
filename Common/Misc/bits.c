#include "bits.h"
#include <string.h>

#define CHAR_BIT ( 8 )
#define debug_assert(x)

// these are declared in the header and inlined to aid compiler optimizations
// (they can easily end up being time-critical).
// note: GCC can't extern functions, while VC's "Whole Program
// Optimization" can.

/**
 * a mask that includes the lowest N bits
 *
 * @param num_bits number of bits in mask
 **/
uint32_t bit_mask( uint32_t num_bits )
{
  return ( 1u << num_bits ) - 1;
}

uint64_t bit_mask64( uint32_t num_bits )
{
  return ( 1ull << num_bits ) - 1;
}

/**
 * extract the value of bits hi_idx:lo_idx within num
 *
 * example: bits(0x69, 2, 5) == 0x0A
 *
 * @param num number whose bits are to be extracted
 * @param lo_idx bit index of lowest  bit to include
 * @param hi_idx bit index of highest bit to include
 * @return value of extracted bits.
 **/
uint32_t bits( uint32_t num, uint32_t lo_idx, uint32_t hi_idx )
{
  const uint32_t count = ( hi_idx - lo_idx ) + 1;
  uint32_t result = num >> lo_idx;  // # bits to return
  result &= bit_mask( count );
  return result;
}

uint64_t bits64( uint64_t num, uint32_t lo_idx, uint32_t hi_idx )
{
  const uint32_t count = ( hi_idx - lo_idx ) + 1;  // # bits to return
  uint64_t result = num >> lo_idx;
  result &= bit_mask64( count );
  return result;
}

/**
 * @return whether the given number is a power of two.
 **/
uint32_t is_pow2( uint32_t n )
{    // 0 would pass the test below but isn't a POT.
  if ( n == 0 )
    return 0;
  return ( n & ( n - 1ul ) ) == 0;
}

/**
 * @return the (integral) base 2 logarithm, or -1 if the number
 * is not a power-of-two.
 **/
int32_t log2_of_pow2( uint32_t n )
{
  int32_t bit_index;

  if ( !is_pow2( n ) )
    bit_index = -1;
  else
  {
    // note: compare against n directly because it is known to be a POT.
    bit_index = 0;
    for ( uint32_t bit_value = 1; bit_value != n; bit_value *= 2 )
      bit_index++;
  }

  debug_assert(
      -1 <= bit_index && bit_index < (int32_t) sizeof(int32_t) * CHAR_BIT ); debug_assert( bit_index == -1 || n == ( 1u << bit_index ) );
  return bit_index;
}

/**
 * ceil(log2(n))
 *
 * @param n (integer) input; MUST be > 0, else results are undefined.
 * @return ceiling of the base-2 logarithm (i.e. rounded up).
 **/
uint32_t ceil_log2( uint32_t x )
{
  uint32_t bit = 1;
  uint32_t l = 0;
  while ( bit < x && bit != 0 )  // must detect overflow
  {
    l++;
    bit += bit;
  }

  return l;
}

/**
 * floor(log2(f))
 * fast, uses the FPU normalization hardware.
 *
 * @param f (float) input; MUST be > 0, else results are undefined.
 * @return floor of the base-2 logarithm (i.e. rounded down).
 **/
int32_t floor_log2_0( const float x )
{
  const uint32_t i = *(uint32_t*) &x;
  uint32_t biased_exp = ( i >> 23 ) & 0xFF;
  return (int32_t) biased_exp - 127;
}

uint32_t get_float_bits( const float x )
{
  uint32_t ret;
  memcpy( &ret, &x, 4 );
  return ret;
}

int32_t floor_log2( const float x )
{
  const uint32_t i = get_float_bits( x );
  const uint32_t biased_exp = ( i >> 23 ) & 0xFF;
  return (int32_t) biased_exp - 127;
}

/**
 * round up to next larger power of two.
 **/

// round_up_to_pow2 implementation assumes 32-bit int32_t.
uint32_t round_up_to_pow2( uint32_t x )
{    // fold upper bit into lower bits; leaves same MSB set but
// everything below it 1. adding 1 yields next POT.
  x |= ( x >> 1 );
  x |= ( x >> 2 );
  x |= ( x >> 4 );
  x |= ( x >> 8 );
  x |= ( x >> 16 );
  return x + 1;
}

/**
 * round number up/down to the next given multiple.
 *
 * @param multiple: must be a power of two.
 **/
uintptr_t round_up( uintptr_t n, uintptr_t multiple )
{
  debug_assert( is_pow2( (long) multiple ) );
  const uintptr_t result = ( n + multiple - 1 ) & ~( multiple - 1 );
  debug_assert( n <= result && result < n + multiple );
  return result;
}

uintptr_t round_down( uintptr_t n, uintptr_t multiple )
{
  debug_assert( is_pow2( (long) multiple ) );
  const uintptr_t result = n & ~( multiple - 1 );
  debug_assert( result <= n && n < result + multiple );
  return result;
}

