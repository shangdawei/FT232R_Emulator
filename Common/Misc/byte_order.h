/*
 * byte order (endianness) support routines.
 */

#ifndef __BYTE_ORDER_H__
#define __BYTE_ORDER_H__

#include <stdint.h>
#include <stddef.h>

// detect byte order via predefined macros.
#ifndef BYTE_ORDER
# define LITTLE_ENDIAN 0x4321
# define BIG_ENDIAN    0x1234
# if (__LITTLE_ENDIAN__ > 0 )
#  define BYTE_ORDER LITTLE_ENDIAN
# else
#  define BYTE_ORDER BIG_ENDIAN
# endif
#endif

/**
 * convert 4 characters to uint32_t (at compile time) for easy comparison.
 * output is in native byte order; e.g. FOURCC_LE can be used instead.
 **/
#define FOURCC(a,b,c,d)	// real definition is below
#undef  FOURCC

// implementation rationale:
// - can't pass code as string, and use s[0]..s[3], because
//   VC6/7 don't realize the macro is constant
//   (it should be usable as a switch{} expression)
// - the casts are ugly but necessary. uint32_t is required because u8 << 8 == 0;
//   the additional u8 cast ensures each character is treated as unsigned
//   (otherwise, they'd be promoted to signed int before the uint32_t cast,
//   which would break things).

/// big-endian version of FOURCC
#define FOURCC_BE(a,b,c,d) ( ((uint32_t)(u8)a) << 24 | ((uint32_t)(u8)b) << 16 | \
	((uint32_t)(u8)c) << 8  | ((uint32_t)(u8)d) << 0  )

/// little-endian version of FOURCC
#define FOURCC_LE(a,b,c,d) ( ((uint32_t)(u8)a) << 0  | ((uint32_t)(u8)b) << 8  | \
	((uint32_t)(u8)c) << 16 | ((uint32_t)(u8)d) << 24 )

#if BYTE_ORDER == BIG_ENDIAN
# define FOURCC FOURCC_BE
#else
# define FOURCC FOURCC_LE
#endif

#if BYTE_ORDER == BIG_ENDIAN
// convert a little-endian number to/from native byte order.
# define to_le16(x) swap16(x)
# define to_le32(x) swap32(x)
# define to_le64(x) swap64(x)
// convert a big-endian number to/from native byte order.
# define to_be16(x) (x)
# define to_be32(x) (x)
# define to_be64(x) (x)
#else // LITTLE_ENDIAN
// convert a little-endian number to/from native byte order.
# define to_le16(x) (x)
# define to_le32(x) (x)
# define to_le64(x) (x)
// convert a big-endian number to/from native byte order.
# define to_be16(x) swap16(x)
# define to_be32(x) swap32(x)
# define to_be64(x) swap64(x)
#endif

/// read a little-endian number from memory into native byte order.
uint16_t read_le16( const void* p );
uint32_t read_le32( const void* p );	/// see read_le16
uint64_t read_le64( const void* p );	/// see read_le16

/// read a big-endian number from memory into native byte order.
uint16_t read_be16( const void* p );
uint32_t read_be32( const void* p );	/// see read_be16
uint64_t read_be64( const void* p );	/// see read_be16

/// write a little-endian number to memory in native byte order.
void write_le16( void* p, uint16_t x );
void write_le32( void* p, uint32_t x );	/// see write_le16
void write_le64( void* p, uint64_t x );	/// see write_le16

/// write a big-endian number to memory in native byte order.
void write_be16( void* p, uint16_t x );
void write_be32( void* p, uint32_t x );	/// see write_be16
void write_be64( void* p, uint64_t x );	/// see write_be16

/**
 * zero-extend \<size\> (truncated to 8) bytes of little-endian data to uint64_t,
 * starting at address \<p\> (need not be aligned).
 **/
uint64_t movzx_le64( const uint8_t * p, size_t size_bytes );
uint64_t movzx_be64( const uint8_t * p, size_t size_bytes );

/**
 * sign-extend \<size\> (truncated to 8) bytes of little-endian data to int64_t,
 * starting at address \<p\> (need not be aligned).
 **/
int64_t movsx_le64( const uint8_t * p, size_t size_bytes );
int64_t movsx_be64( const uint8_t * p, size_t size_bytes );

#ifndef swap16
uint16_t swap16( const uint16_t x );
#endif
#ifndef swap32
uint32_t swap32( const uint32_t x );
#endif
#ifndef swap64
uint64_t swap64( const uint64_t x );
#endif

#endif	// #ifndef __BYTE_ORDER_H__
