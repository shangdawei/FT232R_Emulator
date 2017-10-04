#ifndef __ENDIAN_H__
#define __ENDIAN_H__

// These are different compilers for ARM processors
//
#ifndef __ICCARM__
#error This file should only be compiled by ICCARM
#endif
//
// __LITTLE_ENDIAN__
//
// An integer that reflects the --endian option and is defined to 1
// when the byte order is little-endian.
// The symbol is defined to 0 when the byte order is big-endian.
//
#if ( __LITTLE_ENDIAN__ ==  1 )
#define __BIG_ENDIAN__    ( 0 )
#else
#define __BIG_ENDIAN__    ( 1 )
#endif

// ARMv6 added the SETEND instruction which manipulates a state bit to configure
// which endianess the processor will use when performing a load/store operation.
// Looks like IAR's __big_endian intrinsic just causes the processor to manipulate
// that bit when accessing the variable tagged with that attribute.
//
// __big_endian int i;

//Dependencies
#include <stdint.h>

//Load unaligned 16-bit integer (little-endian encoding)
#define LOAD16LE(p) ((uint16_t) (((uint8_t *)(p))[0] | (((uint8_t *)(p))[1] << 8)))

//Load unaligned 16-bit integer (big-endian encoding)
#define LOAD16BE(p) ((uint16_t) ((((uint8_t *)(p))[0] << 8) | ((uint8_t *)(p))[1]))

//Load unaligned 24-bit integer (little-endian encoding)
#define LOAD24LE(p) ((uint32_t) (((uint8_t *)(p))[0] | \
   (((uint8_t *)(p))[1] << 8) | (((uint8_t *)(p))[2] << 16)))

//Load unaligned 24-bit integer (big-endian encoding)
#define LOAD24BE(p) ((uint32_t) ((((uint8_t *)(p))[0] << 16) | \
   (((uint8_t *)(p))[1] << 8) | ((uint8_t *)(p))[2]))

//Load unaligned 32-bit integer (little-endian encoding)
#define LOAD32LE(p) ((uint32_t) (((uint8_t *)(p))[0] | (((uint8_t *)(p))[1] << 8) | \
   (((uint8_t *)(p))[2] << 16) | (((uint8_t *)(p))[3] << 24)))

//Load unaligned 32-bit integer (big-endian encoding)
#define LOAD32BE(p) ((uint32_t) ((((uint8_t *)(p))[0] << 24) | (((uint8_t *)(p))[1] << 16) | \
   (((uint8_t *)(p))[2] << 8) | ((uint8_t *)(p))[3]))

//Store unaligned 16-bit integer (little-endian encoding)
#define STORE16LE(a, p) \
   ((uint8_t *)(p))[0] = (a) & 0xFF, \
   ((uint8_t *)(p))[1] = ((a) >> 8) & 0xFF

//Store unaligned 32-bit integer (big-endian encoding)
#define STORE16BE(a, p) \
   ((uint8_t *)(p))[0] = ((a) >> 8) & 0xFF, \
   ((uint8_t *)(p))[1] = (a) & 0xFF

//Store unaligned 24-bit integer (little-endian encoding)
#define STORE24LE(a, p) \
   ((uint8_t *)(p))[0] = (a) & 0xFF, \
   ((uint8_t *)(p))[1] = ((a) >> 8) & 0xFF, \
   ((uint8_t *)(p))[2] = ((a) >> 16) & 0xFF

//Store unaligned 24-bit integer (big-endian encoding)
#define STORE24BE(a, p) \
   ((uint8_t *)(p))[0] = ((a) >> 16) & 0xFF, \
   ((uint8_t *)(p))[1] = ((a) >> 8) & 0xFF, \
   ((uint8_t *)(p))[2] = (a) & 0xFF

//Store unaligned 32-bit integer (little-endian encoding)
#define STORE32LE(a, p) \
   ((uint8_t *)(p))[0] = (a) & 0xFF, \
   ((uint8_t *)(p))[1] = ((a) >> 8) & 0xFF, \
   ((uint8_t *)(p))[2] = ((a) >> 16) & 0xFF, \
   ((uint8_t *)(p))[3] = ((a) >> 24) & 0xFF

//Store unaligned 32-bit integer (big-endian encoding)
#define STORE32BE(a, p) \
   ((uint8_t *)(p))[0] = ((a) >> 24) & 0xFF, \
   ((uint8_t *)(p))[1] = ((a) >> 16) & 0xFF, \
   ((uint8_t *)(p))[2] = ((a) >> 8) & 0xFF, \
   ((uint8_t *)(p))[3] = (a) & 0xFF

//Swap a 16-bit integer
#define __SWAP16__(x) ( \
   (((x) & 0x00FF) << 8) | \
   (((x) & 0xFF00) >> 8))

//Swap a 32-bit integer
#define __SWAP32__(x) ( \
   (((x) & 0x000000FFUL) << 24) | \
   (((x) & 0x0000FF00UL) << 8) | \
   (((x) & 0x00FF0000UL) >> 8) | \
   (((x) & 0xFF000000UL) >> 24))

//Swap a 64-bit integer
#define __SWAP64__(x) ( \
   (((x) & 0x00000000000000FFULL) << 56) | \
   (((x) & 0x000000000000FF00ULL) << 40) | \
   (((x) & 0x0000000000FF0000ULL) << 24) | \
   (((x) & 0x00000000FF000000ULL) << 8) | \
   (((x) & 0x000000FF00000000ULL) >> 8) | \
   (((x) & 0x0000FF0000000000ULL) >> 24) | \
   (((x) & 0x00FF000000000000ULL) >> 40) | \
   (((x) & 0xFF00000000000000ULL) >> 56))

//Big-endian machine?
#if ( __BIG_ENDIAN__ > 0 )

//Host byte order to network byte order
#define HTONS(value) (value)
#define HTONL(value) (value)

#define htons(value) (value)
#define htonl(value) (value)

//Network byte order to host byte order
#define NTOHS(value) (value)
#define NTOHL(value) (value)

#define ntohs(value) (value)
#define ntohl(value) (value)

//Host byte order to little-endian byte order
#define HTOLE16(value) __SWAP16__(value)
#define HTOLE32(value) __SWAP32__(value)
#define HTOLE64(value) __SWAP64__(value)

#define htole16(value) _swap16(value)
#define htole32(value) _swap32(value)
#define htole64(value) _swap64(value)

//Little-endian byte order to host byte order
#define LETOH16(value) __SWAP16__(value)
#define LETOH32(value) __SWAP32__(value)
#define LETOH64(value) __SWAP64__(value)

#define letoh16(value) _swap16(value)
#define letoh32(value) _swap32(value)
#define letoh64(value) _swap64(value)

//Host byte order to big-endian byte order
#define HTOBE16(value) (value)
#define HTOBE32(value) (value)
#define HTOBE64(value) (value)

#define htobe16(value) (value)
#define htobe32(value) (value)
#define htobe64(value) (value)

//Big-endian byte order to host byte order
#define BETOH16(value) (value)
#define BETOH32(value) (value)
#define BETOH64(value) (value)

#define betoh16(value) (value)
#define betoh32(value) (value)
#define betoh64(value) (value)

//Little-endian machine?
#else

//Host byte order to network byte order
#define HTONS(value) __SWAP16__(value)
#define HTONL(value) __SWAP32__(value)

#define htons(value) _swap16(value)
#define htonl(value) _swap32(value)

//Network byte order to host byte order
#define NTOHS(value) __SWAP16__(value)
#define NTOHL(value) __SWAP32__(value)

#define ntohs(value) _swap16(value)
#define ntohl(value) _swap32(value)

//Host byte order to little-endian byte order
#define HTOLE16(value) (value)
#define HTOLE32(value) (value)
#define HTOLE64(value) (value)

#define htole16(value) (value)
#define htole32(value) (value)
#define htole64(value) (value)

//Little-endian byte order to host byte order
#define LETOH16(value) (value)
#define LETOH32(value) (value)
#define LETOH64(value) (value)

#define letoh16(value) (value)
#define letoh32(value) (value)
#define letoh64(value) (value)

//Host byte order to big-endian byte order
#define HTOBE16(value) __SWAP16__(value)
#define HTOBE32(value) __SWAP32__(value)
#define HTOBE64(value) __SWAP64__(value)

#define htobe16(value) _swap16(value)
#define htobe32(value) _swap32(value)
#define htobe64(value) _swap64(value)

//Big-endian byte order to host byte order
#define BETOH16(value) __SWAP16__(value)
#define BETOH32(value) __SWAP32__(value)
#define BETOH64(value) __SWAP64__(value)

#define betoh16(value) _swap16(value)
#define betoh32(value) _swap32(value)
#define betoh64(value) _swap64(value)

#endif

//Byte order conversion functions
static inline uint16_t _swap16( uint16_t value )
{
  return __SWAP16__( value );
}

static inline uint32_t _swap32( uint32_t value )
{
  return __SWAP32__( value );
}

static inline uint64_t _swap64( uint64_t value )
{
  return __SWAP64__( value );
}

#endif /* __ENDIAN_H__ */

