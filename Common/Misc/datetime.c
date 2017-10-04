#include "datetime.h"

__root const char DataTime[] = __DATE__ __TIME__;

__root const int data_year_val = __DATE_YEAR_VAL__;

__root const int data_month_val = __DATE_MONTH_VAL__;

__root const int data_day_val = __DATE_DAY_VAL__;

__root const char date_str[] = { __DATE_YEAR_MONTH_DAY_STR__, 0 };

__root const char time_str[] = { __TIEM_HOUR_MIN_SEC_STR__, 0 };

__root const char date_time_str[] = { __DATE_TIME_STR__, 0 };

