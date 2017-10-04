#ifndef __COMPILER_H__
#define __COMPILER_H__

/* __packed keyword used to decrease the data type alignment to 1-byte */

/*
 * Various compiler declaration methods for packed structures:
 * GNU: typedef struct { blah blah blah } __attribute__((packed)) structName;
 * Keil/IAR: typedef __packed struct { blah blah blah } structName;
 */
#if defined   (__GNUC__) /* GNU Compiler */
#define PACKED_PRE      /**/
#define PACKED_POST     __attribute__((packed))
#elif defined (__ICCARM__)    /* IAR Compiler */
#define PACKED_PRE      __packed
#define PACKED_POST     /**/
#elif defined   (__CC_ARM)      /* ARM Compiler */
#define PACKED_PRE      __packed
#define PACKED_POST     /**/
#endif

#if defined   (__GNUC__) /* GNU Compiler */
// typedef struct __attribute( ( packed ) )
#endif

#if defined   (__CC_ARM)      /* ARM Compiler */
// typedef __packed struct
#endif

#if defined   (__TASKING__)  /* TASKING Compiler */
// typedef __packed struct
#endif

#if defined (__ICCARM__)    /* IAR Compiler */
// typedef __packed struct
//
// #pragma pack(push, 1)
// typedef struct { uint8_t member };
// #pragma pack(pop)
#endif

#if defined   (__CC_ARM)      /* ARM Compiler */
/** Macros for handling packed structs. */
#define STRINGIZE(X)          #X

#define __PACK_START(X)       _Pragma(STRINGIZE(pack(X)))
#define __PACK_END()          _Pragma("pack()")
#define __ATTRIBUTE_PACKED

/** MDK-ARM compiler: Macros for handling aligned structs. */
#define __ALIGN(X)            __align(X)

#endif // defined   (__CC_ARM)      /* ARM Compiler */

#if defined (__ICCARM__)    /* IAR Compiler */

/** Macros for handling packed structs. */
#define STRINGIZE(X)          #X

#define __PACK_START(X)       _Pragma(STRINGIZE(pack(X)))
#define __PACK_END()          _Pragma("pack()")
#define __ATTRIBUTE_PACKED

/** IAR Embedded Workbench: Macros for handling aligned structs. */
#define __ALIGN(X) _Pragma(STRINGIZE(data_alignment=X))

#endif // defined (__ICCARM__)    /* IAR Compiler */

#endif /* __COMPILER_H__ */
