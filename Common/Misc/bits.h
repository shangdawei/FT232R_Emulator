#ifndef __BITS_H__
#define __BITS_H__

#include <stdint.h>
#include <stddef.h>

/**
 * value of bit number <n> as unsigned long.
 *
 * @param n bit index (0..CHAR_BIT*sizeof(int)-1)
 **/
#define BIT(n) (1ul << (n))

/**
 * value of bit number <n> as unsigned long long.
 *
 * @param n bit index (0..CHAR_BIT*sizeof(int)-1)
 **/
#define BIT64(n) (1ull << (n))

uint32_t bit_mask( uint32_t num_bits );
uint64_t bit_mask64( uint32_t num_bits );
uint32_t bits( uint32_t num, uint32_t lo_idx, uint32_t hi_idx );
uint64_t bits64( uint64_t num, uint32_t lo_idx, uint32_t hi_idx );

/**
 * @return whether the given number is a power of two.
 **/
uint32_t is_pow2( uint32_t n );

/**
 * @return the (integral) base 2 logarithm, or -1 if the number
 * is not a power-of-two.
 **/
int log2_of_pow2( uint32_t n );

/**
 * ceil(log2(n))
 *
 * @param n (integer) input; MUST be > 0, else results are undefined.
 * @return ceiling of the base-2 logarithm (i.e. rounded up).
 **/
uint32_t ceil_log2( uint32_t x );

/**
 * floor(log2(f))
 * fast, uses the FPU normalization hardware.
 *
 * @param f (float) input; MUST be > 0, else results are undefined.
 * @return floor of the base-2 logarithm (i.e. rounded down).
 **/
int floor_log2( const float x );

/**
 * round up to next larger power of two.
 **/
uint32_t round_up_to_pow2( uint32_t x );

/**
 * round number up/down to the next given multiple.
 *
 * @param multiple: must be a power of two.
 **/
uintptr_t round_up( uintptr_t n, uintptr_t multiple );
uintptr_t round_down( uintptr_t n, uintptr_t multiple );

#endif /* __BITS_H__ */

