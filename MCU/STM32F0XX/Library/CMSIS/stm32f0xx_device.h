#ifndef __STM32F0XX_DEVICE_H__
#define __STM32F0XX_DEVICE_H__

/*********************** stm32f0xx.h V1.5.0 05-December-2014 **************************************/
/* The follow defines are used in stm32fxx_periph.h and stm32fxx_periph.c */
/* Old STM32F0XX_LD definition, maintained for legacy purpose */

/* STM32F030 : STM32F030X6, STM32F030X8 */
/* STM32F030xC */
/* STM32F070xB */
/* STM32F070x6 */

/* STM32F031 £ºSTM32F0XX_LD¡¡*/
/* STM32F051 : STM32F0X¡¡STM32F0XX_MD */
/* STM32F091 */

/* STM32F042 */
/* STM32F072 : STM32F0XX_HD */

#if !defined ( STM32F072C8 )
#define STM32F072C8
#endif

/************************************************** STM32F030 *************************************/
#if defined ( STM32F030F4 )
#define STM32F030x6
#define STM32F030
#elif defined ( STM32F030C6 ) || defined ( STM32F030K6 )
#define STM32F030x6
#define STM32F030
#elif defined ( STM32F030C8 ) || defined ( STM32F030R8 )
#define STM32F030x8
#define STM32F030
#elif defined ( STM32F030CC ) || defined ( STM32F030RC )
#define STM32F030xC
#define STM32F030

/************************************************** STM32F070 *************************************/
#elif defined ( STM32F070C6 ) || defined ( STM32F070F6 )
#define STM32F070x6
#define STM32F070
#elif defined ( STM32F070CB ) || defined ( STM32F070RB )
#define STM32F070xB
#define STM32F070

/************************************************** STM32F031 *************************************/
#elif defined ( STM32F031F4 ) || defined ( STM32F031C4 ) || defined ( STM32F031G4 ) || defined ( STM32F031K4 )
#define STM32F031x6
#define STM32F031
#elif defined ( STM32F031C6 ) || defined ( STM32F031E6 ) || defined ( STM32F031F6 ) || defined ( STM32F031G6 ) || defined ( STM32F031K6 )
#define STM32F031x6
#define STM32F031

/************************************************** STM32F051 *************************************/
#elif defined ( STM32F051C4 ) || defined ( STM32F051K4 ) || defined ( STM32F051R4 )
#define STM32F051x8
#define STM32F051
#elif defined ( STM32F051C6 ) || defined ( STM32F051K6 ) || defined ( STM32F051R6 )
#define STM32F051x8
#define STM32F051
#elif defined ( STM32F051C8 ) || defined ( STM32F051K8 ) || defined ( STM32F051R8 ) || defined ( STM32F051T8 )
#define STM32F051x8
#define STM32F051

/************************************************** STM32F071 *************************************/
#elif defined ( STM32F071V8 ) || defined ( STM32F071VB ) || defined ( STM32F071CB ) || defined ( STM32F071RB )
#define STM32F071xB
#define STM32F071

/************************************************** STM32F091 *************************************/
#elif defined ( STM32F091CB ) || defined ( STM32F091RB ) || defined ( STM32F091VB )
#define STM32F091xC
#define STM32F091
#elif defined ( STM32F091CC ) || defined ( STM32F091RC ) || defined ( STM32F091VC )
#define STM32F091xC
#define STM32F091

/************************************************** STM32F042 *************************************/
#elif defined ( STM32F042C4 ) || defined ( STM32F042F4 ) || defined ( STM32F042G4 ) || defined ( STM32F042K4 )
#define STM32F042x6
#define STM32F042
#elif defined ( STM32F042C6 ) || defined ( STM32F042F6 ) || defined ( STM32F042G6 ) || defined ( STM32F042K6 ) || defined ( STM32F042T6 )
#define STM32F042x6
#define STM32F042

/************************************************** STM32F072 *************************************/
#elif defined ( STM32F072C8 ) || defined ( STM32F072R8 ) || defined ( STM32F072V8 )
#define STM32F072xB
#define STM32F072

#elif defined ( STM32F072CB ) || defined ( STM32F072RB ) || defined ( STM32F072VB )
#define STM32F072xB
#define STM32F072

/************************************************** STM32F038 *************************************/
#elif defined ( STM32F038C6 ) || defined ( STM32F038F6 ) || defined ( STM32F038G6 ) || defined ( STM32F038K6 )
#define STM32F038xx
#define STM32F038
#elif defined ( STM32F038E8 )
#define STM32F038xx
#define STM32F038

/************************************************** STM32F048 *************************************/
#elif defined ( STM32F048C6 ) || defined ( STM32F048G6 ) || defined ( STM32F048T6 )
#define STM32F048x6
#define STM32F048xx
#define STM32F048

/************************************************** STM32F058 *************************************/
#elif defined ( STM32F058C8 ) || defined ( STM32F058R8 ) || defined ( STM32F058T8 )
#define STM32F058xx
#define STM32F058

/************************************************** STM32F078 *************************************/
#elif defined ( STM32F078CB ) || defined ( STM32F078RB ) || defined ( STM32F078VB )
#define STM32F078xx
#define STM32F078

/************************************************** STM32F098 *************************************/
#elif defined ( STM32F098CC ) || defined ( STM32F098RC ) || defined ( STM32F098VC )
#define STM32F098xx
#define STM32F098

#else
#error Please select the target STM32F0XXXX device used in your project.
#endif

#if defined( STM32F030 ) || defined( STM32F031 )
#define STM32F03x
#elif defined( STM32F042 ) || defined( STM32F048 )
#define STM32F04x
#elif defined( STM32F051 ) || defined( STM32F058 )
#define STM32F05x
#elif defined( STM32F070 ) || defined( STM32F071 ) || defined( STM32F072 ) || defined( STM32F078 )
#define STM32F07x
#elif defined( STM32F091 ) || defined( STM32F098 )
#define STM32F09x
#else
#error Please select the target STM32F0XXXX device used in your project.
#endif

/* The memory organization of STM32F03x, STM32F04x and STM32F05x devices is based on a main Flash memory block
 * containing up to 64 pages of 1 Kbyte or up to 16 sectors of 4 Kbytes (4 pages).
 *
 * The memory organization of STM32F07x and STM32F09x devices is based on a main Flash memory block
 * containing up to 128 pages of 2 Kbytes or up to 64 sectors of 4 Kbytes (2 pages).
 *
 */

#if defined( STM32F03x ) || defined( STM32F04x ) || defined( STM32F05x )
#define FLASH_PAGE_SIZE   ( 0x400 )
#elif defined( STM32F07x ) || defined( STM32F09x )
#define FLASH_PAGE_SIZE   ( 0x800 )
#else
#error Please select the target STM32F0XXXX device used in your project.
#endif

#if defined(STM32F030x6)

#elif defined(STM32F030x8)

#elif defined(STM32F030xC)

#elif defined(STM32F031x6)

#elif defined(STM32F038xx)

#elif defined(STM32F042x6)

#elif defined(STM32F048xx)

#elif defined(STM32F051x8)

#elif defined(STM32F058xx)

#elif defined(STM32F070x6)

#elif defined(STM32F070xB)

#elif defined(STM32F071xB)

#elif defined(STM32F072xB)

#elif defined(STM32F078xx)

#elif defined(STM32F091xC)

#elif defined(STM32F098xx)

#else
#error "Please select the target STM32F0xx device used in your project."
#endif

#endif /* __STM32F0XX_DEVICE_H__ */
