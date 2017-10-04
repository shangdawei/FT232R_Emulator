#ifndef __DATE_TIME__H__
#define __DATE_TIME__H__

// __DATE__
// Aug 31 2016#0
// 0123456789A
//
// Aug 31 2016
//        789A
#define __DATE_YEAR_VAL__             \
( ( ( ( __DATE__  [7] - '0' )   * 10  \
    + ( __DATE__  [8] - '0' ) ) * 10  \
    + ( __DATE__  [9] - '0' ) ) * 10  \
    + ( __DATE__ [10] - '0' ) )

//
// const char * months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//
// Aug 31 2016
// 012
// 1   2   3   4   5   6   7   8   9   10  11  12
// Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
//   *       ^   ^       *
//
#define __DATE_MONTH_VAL__            \
( __DATE__ [2] == 'n' ? ( __DATE__ [1] == 'a' ? 1 : 6 ) \
: __DATE__ [2] == 'b' ? 2                               \
: __DATE__ [2] == 'r' ? ( __DATE__ [0] == 'M' ? 3 : 4)  \
: __DATE__ [2] == 'y' ? 5             \
: __DATE__ [2] == 'l' ? 7             \
: __DATE__ [2] == 'g' ? 8             \
: __DATE__ [2] == 'p' ? 9             \
: __DATE__ [2] == 't' ? 10            \
: __DATE__ [2] == 'v' ? 11 : 12 )

// Aug 31 2016
//     45
#define __DATE_DAY_VAL__              \
 ( ( __DATE__ [4] == ' ' ? 0 : __DATE__ [4] - '0') * 10 + (__DATE__ [5] - '0') )


#define BCD_DIGIT(digit) "0123456789"[ ( digit ) ]

#define __DATE_MONTH_HI_VAL__         ( __DATE_MONTH_VAL__ / 10  )
#define __DATE_MONTH_LO_VAL__         ( __DATE_MONTH_VAL__ % 10 )

#define __DATE_DAY_HI_VAL__           ( __DATE_DAY_VAL__ / 10  )
#define __DATE_DAY_LO_VAL__           ( __DATE_DAY_VAL__ % 10 )

#define __DATE_YEAR_0_VAL__           ( __DATE_YEAR_VAL__ / 1000 )
#define __DATE_YEAR_1_VAL__           ( __DATE_YEAR_VAL__ / 100 )
#define __DATE_YEAR_2_VAL__           ( __DATE_YEAR_VAL__ / 10 )
#define __DATE_YEAR_3_VAL__           ( __DATE_YEAR_VAL__ % 10 )

// Aug 31 2016
//        789A
#define __DATE_YEAR_CH0__             BCD_DIGIT( ( __DATE__[ 7] - 0x30 ) )
#define __DATE_YEAR_CH1__             BCD_DIGIT( ( __DATE__[ 8] - 0x30 ) )
#define __DATE_YEAR_CH2__             BCD_DIGIT( ( __DATE__[ 9] - 0x30 ) )
#define __DATE_YEAR_CH3__             BCD_DIGIT( ( __DATE__[10] - 0x30 ) )

#define __DATE_YEAR_STR__             \
  __DATE_YEAR_CH0__, __DATE_YEAR_CH1__, __DATE_YEAR_CH2__, __DATE_YEAR_CH3__

#define __DATE_MONTH_CH0__            BCD_DIGIT(  __DATE_MONTH_HI_VAL__  )
#define __DATE_MONTH_CH1__            BCD_DIGIT(  __DATE_MONTH_LO_VAL__  )

#define __DATE_MONTH_STR__            \
  __DATE_MONTH_CH0__, __DATE_MONTH_CH1__

#define __DATE_DAY_CH0__              BCD_DIGIT(  __DATE_DAY_HI_VAL__  )
#define __DATE_DAY_CH1__              BCD_DIGIT(  __DATE_DAY_LO_VAL__  )

#define __DATE_DAY_STR__              \
  __DATE_DAY_CH0__, __DATE_DAY_CH1__

#define __DATE_YEAR_MONTH_DAY_STR__   \
  __DATE_YEAR_STR__, __DATE_MONTH_STR__, __DATE_DAY_STR__

// __TIME__
// 23:59:59#0
// 01234567
//
#define __TIME_HOUR_VAL__             \
  ( ( __TIME__  [0] - '0' )   * 10    \
  + ( __TIME__  [1] - '0' ) )

#define __TIME_MIN_VAL__              \
  ( ( __TIME__  [3] - '0' )   * 10    \
  + ( __TIME__  [4] - '0' ) )

#define __TIME_SEC_VAL__              \
  ( ( __TIME__  [6] - '0' )   * 10    \
  + ( __TIME__  [7] - '0' ) )


#define __TIME_HOUR_CH0__             BCD_DIGIT(  __TIME_HOUR_VAL__ / 10  )
#define __TIME_HOUR_CH1__             BCD_DIGIT(  __TIME_HOUR_VAL__ % 10  )

#define __TIME_HOUR_STR__             \
  __TIME_HOUR_CH0__, __TIME_HOUR_CH1__

#define __TIME_MIN_CH0__              BCD_DIGIT(  __TIME_MIN_VAL__ / 10  )
#define __TIME_MIN_CH1__              BCD_DIGIT(  __TIME_MIN_VAL__ % 10  )

#define __TIME_MIN_STR__              \
  __TIME_MIN_CH0__, __TIME_MIN_CH1__

#define __TIME_SEC_CH0__              BCD_DIGIT(  __TIME_SEC_VAL__ / 10  )
#define __TIME_SEC_CH1__              BCD_DIGIT(  __TIME_SEC_VAL__ % 10  )

#define __TIME_SEC_STR__              \
  __TIME_SEC_CH0__, __TIME_SEC_CH1__

#define __TIEM_HOUR_MIN_SEC_STR__     \
  __TIME_HOUR_STR__, __TIME_MIN_STR__, __TIME_SEC_STR__

#define __DATE_TIME_STR__             \
  __DATE_YEAR_MONTH_DAY_STR__, __TIEM_HOUR_MIN_SEC_STR__

#endif /* __DATE_TIME__H__ */

