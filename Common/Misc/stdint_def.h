#ifndef __STDINT_DEF_H__
#define __STDINT_DEF_H__

#define __I
#define __O
#define __IO

#define NULL  ( 0 )

// Basic data types integer types
//
typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef signed short int int16_t;
typedef unsigned short int uint16_t;

typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef unsigned int size_t;

// typedef signed long   int32_t;
// typedef unsigned long uint32_t;

#pragma language=save

#pragma language=extended
typedef signed long int int64_t;
typedef unsigned long int uint64_t;

#pragma language=restore

#endif /*  __STDINT_DEF_H__ */
