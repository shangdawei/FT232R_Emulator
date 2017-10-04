#ifndef __VA_MACRO_H__
#define __VA_MACRO_H__

#define ITERATOR_ENABLED      ( 0 )

#define VA_EMPTY()
#define VA_EAT(...)
#define VA_EXPR(...)          __VA_ARGS__
#define VA_ARGS(...)          , ##__VA_ARGS__

/*
 * Variadic Macros -- http://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
 *
 * A macro can be declared to accept a variable number of arguments much as
 * a function can. The syntax for defining the macro
 * is similar to that of a function.
 * This kind of macro is called variadic. When the macro is invoked,
 * all the tokens in its argument list after the last named argument
 * (this macro has none), including any commas, become the variable argument.
 *
 * This sequence of tokens replaces the identifier __VA_ARGS__
 * in the macro body wherever it appears.
 *
 * The variable argument is completely macro-expanded before it is inserted into
 * the macro expansion, just like an ordinary argument.
 * You may use the ¡®#¡¯ and ¡®##¡¯ operators to stringify the variable argument or
 * to paste its leading or trailing token with another token.
 *
 * But see below for an important special case for ¡®##¡¯.
 * Both __ICCARM__ and __GNUC__ support the special case
 *
 * __VA_ARGS__ is a C99 innovation that is not part of the C++ standard.
 *
 * you cannot omit the comma separating the named argument from the variable
 * arguments. Furthermore, if you leave the variable argument empty, you will
 * get a syntax error, because there will be an extra comma after the format string.
 *
 */
#define macro_standard_c99(format, ...) fprintf(stderr, format, __VA_ARGS__)
VA_EAT( macro_standard_c99( "success!\n" ) ==> fprintf(stderr, "success!\n", ) )

/*
 * GNU CPP has a pair of extensions which deal with this problem, the ¡®##¡¯ token
 * paste operator has a special meaning when placed between a comma and
 * a variable argument. If the variable argument is left out when the macro is
 * used, then the comma before the ¡®##¡¯ will be deleted. This does not happen
 * if you pass an empty argument, nor does it happen if the token preceding ¡®##¡¯
 * is anything other than a comma.
 *
 * Both GCC extension and __ICCARM__ can swallow the comma
 *
 */
#define macro_gnu_extension(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
VA_EAT( macro_gnu_extension( "success!\n" ) ==> fprintf(stderr, "success!\n" ) )

/*
 * You may write an argument name immediately before the ¡®...¡¯;
 * that name is used for the variable argument.
 * You cannot use __VA_ARGS__ and this extension in the same macro.
 *
 * Both GCC extension and __ICCARM__ can write an argument name
 *
 */
#define macro_named_args(format, args...) fprintf(stderr, format, ##args)

// -----------------------------------------------------------------------------
// A single '#' will create a string from the given argument,
// regardless of what that argument contains
//
#define VA_STRING( ... )      VA__STRING( ( __VA_ARGS__ ) )
#define VA__STRING( x )       #x

// -----------------------------------------------------------------------------
// The double '##' will create a new token by concatenating the arguments
// If __VA_ARGS__ is empty, GCC's preprocessor removes preceding comma.
//
#define VA_CAT(a, ...)        VA_CAT_PRIM(a, ##__VA_ARGS__)
#define VA_CAT_PRIM(a, ...)   a##__VA_ARGS__

// -----------------------------------------------------------------------------
// Count the number of arguments, works correctly even for zero arguments
// If __VA_ARGS__ is empty, GCC's preprocessor removes preceding comma.
//
#define VA_COUNT_GCC(...)     (sizeof((int[]){0, ##__VA_ARGS__})/sizeof(int)-1)

// -----------------------------------------------------------------------------
// Count the number of arguments, doesn't work for zero arguments
//
#define VA_COUNT_C99(...)     (sizeof((int[]){__VA_ARGS__})/sizeof(int))

// -----------------------------------------------------------------------------
// Count the number of arguments, works correctly even for zero arguments
//
#define VA_COUNT_II( _dummy,                        \
   _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
  _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
  _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
  _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
  _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
  _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
  _61, _62, _63, _64, N, ... ) N

#define VA_RSEQ_N()                                 \
  64, 63, 62, 61, 60,                               \
  59, 58, 57, 56, 55, 54, 53, 52, 51, 50,           \
  49, 48, 47, 46, 45, 44, 43, 42, 41, 40,           \
  39, 38, 37, 36, 35, 34, 33, 32, 31, 30,           \
  29, 28, 27, 26, 25, 24, 23, 22, 21, 20,           \
  19, 18, 17, 16, 15, 14, 13, 12, 11, 10,           \
   9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#define VA_COUNT_I(...)           VA_COUNT_II( __VA_ARGS__  )
#define VA_COUNT_X(...)           VA_COUNT_I(_dummy, ##__VA_ARGS__, VA_RSEQ_N() )
#define VA_COUNT(...)             VA_COUNT_GCC(__VA_ARGS__ )

VA_EAT( VA_COUNT_X( ) : 0 )
VA_EAT( VA_COUNT_X( VA_ARGS_64 ) : 64)

#define VA_NARGS                  VA_EXPR( VA_CAT(VA_ARGS_, i) )

#define VA_ARGS_0
#define VA_ARGS_1   a0
#define VA_ARGS_2   a0, a1
#define VA_ARGS_3   a0, a1, a2
#define VA_ARGS_4   a0, a1, a2, a3
#define VA_ARGS_5   a0, a1, a2, a3, a4
#define VA_ARGS_6   a0, a1, a2, a3, a4, a5
#define VA_ARGS_7   a0, a1, a2, a3, a4, a5, a6
#define VA_ARGS_8   a0, a1, a2, a3, a4, a5, a6, a7
#define VA_ARGS_9   a0, a1, a2, a3, a4, a5, a6, a7, a8
#define VA_ARGS_10  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
#define VA_ARGS_11  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
#define VA_ARGS_12  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
#define VA_ARGS_13  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
#define VA_ARGS_14  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
#define VA_ARGS_15  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
#define VA_ARGS_16  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
#define VA_ARGS_17  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16
#define VA_ARGS_18  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17
#define VA_ARGS_19  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18
#define VA_ARGS_20  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19
#define VA_ARGS_21  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20
#define VA_ARGS_22  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21
#define VA_ARGS_23  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22
#define VA_ARGS_24  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23
#define VA_ARGS_25  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24
#define VA_ARGS_26  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25
#define VA_ARGS_27  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26
#define VA_ARGS_28  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27
#define VA_ARGS_29  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28
#define VA_ARGS_30  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29
#define VA_ARGS_31  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30
#define VA_ARGS_32  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31
#define VA_ARGS_33  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32
#define VA_ARGS_34  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33
#define VA_ARGS_35  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34
#define VA_ARGS_36  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35
#define VA_ARGS_37  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36
#define VA_ARGS_38  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37
#define VA_ARGS_39  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38
#define VA_ARGS_40  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39
#define VA_ARGS_41  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40
#define VA_ARGS_42  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41
#define VA_ARGS_43  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42
#define VA_ARGS_44  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43
#define VA_ARGS_45  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44
#define VA_ARGS_46  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45
#define VA_ARGS_47  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46
#define VA_ARGS_48  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47
#define VA_ARGS_49  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48
#define VA_ARGS_50  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49
#define VA_ARGS_51  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50
#define VA_ARGS_52  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51
#define VA_ARGS_53  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52
#define VA_ARGS_54  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53
#define VA_ARGS_55  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54
#define VA_ARGS_56  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55
#define VA_ARGS_57  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56
#define VA_ARGS_58  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57
#define VA_ARGS_59  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58
#define VA_ARGS_60  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59
#define VA_ARGS_61  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60
#define VA_ARGS_62  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61
#define VA_ARGS_63  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62
#define VA_ARGS_64  a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63

// -----------------------------------------------------------------------------
// Extract and Discard First Argument
//
#define VA_USE_0(arg0, ...)       arg0
#define VA_REM_0(arg0, ...)       __VA_ARGS__

#define VA_ARG0( ... )            VA_USE_0( arg0, __VA_ARGS__ )
#define VA_REST( ... )            VA_REM_0( __VA_ARGS__)

// -----------------------------------------------------------------------------
// Extract an Argument By Index
//
#define VA_GET(i, ...)            VA_CAT(VA_GET_, i)(__VA_ARGS__)

// -----------------------------------------------------------------------------
// Copy n arguments start from i
//
// VA_COPY(3, 2, a0, a1, a2, a3, a4, a5, a6 ) --> a3, a4
//
#define VA_CPY(i, n, ...)         \
    VA_EXPR( VA_CAT( VA_CPY_, n) VA_EXPR( ( VA_DEL(i, __VA_ARGS__ ) ) ) )

// -----------------------------------------------------------------------------
// Delete N Arguments from head
//
#define VA_DEL(n, ...)            VA_EXPR( VA_CAT(VA_DEL_, n)(__VA_ARGS__ ) )

#if ( ITERATOR_ENABLED > 0 )

//#define VA_GET_0(a0, ...)       a0
#define VA_GET_0(...)             VA_USE_0(__VA_ARGS__, throwaway )
#define VA_GET_1( ... )           VA_GET_0(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_2( ... )           VA_GET_1(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_3( ... )           VA_GET_2(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_4( ... )           VA_GET_3(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_5( ... )           VA_GET_4(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_6( ... )           VA_GET_5(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_7( ... )           VA_GET_6(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_8( ... )           VA_GET_7(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_9( ... )           VA_GET_8(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_10( ... )          VA_GET_9(  VA_REM_0( __VA_ARGS__) )
#define VA_GET_11( ... )          VA_GET_10( VA_REM_0( __VA_ARGS__) )
#define VA_GET_12( ... )          VA_GET_11( VA_REM_0( __VA_ARGS__) )
#define VA_GET_13( ... )          VA_GET_12( VA_REM_0( __VA_ARGS__) )
#define VA_GET_14( ... )          VA_GET_13( VA_REM_0( __VA_ARGS__) )
#define VA_GET_15( ... )          VA_GET_14( VA_REM_0( __VA_ARGS__) )
#define VA_GET_16( ... )          VA_GET_15( VA_REM_0( __VA_ARGS__) )
#define VA_GET_17( ... )          VA_GET_16( VA_REM_0( __VA_ARGS__) )
#define VA_GET_18( ... )          VA_GET_17( VA_REM_0( __VA_ARGS__) )
#define VA_GET_19( ... )          VA_GET_18( VA_REM_0( __VA_ARGS__) )
#define VA_GET_20( ... )          VA_GET_19( VA_REM_0( __VA_ARGS__) )
#define VA_GET_21( ... )          VA_GET_20( VA_REM_0( __VA_ARGS__) )
#define VA_GET_22( ... )          VA_GET_21( VA_REM_0( __VA_ARGS__) )
#define VA_GET_23( ... )          VA_GET_22( VA_REM_0( __VA_ARGS__) )
#define VA_GET_24( ... )          VA_GET_23( VA_REM_0( __VA_ARGS__) )
#define VA_GET_25( ... )          VA_GET_24( VA_REM_0( __VA_ARGS__) )
#define VA_GET_26( ... )          VA_GET_25( VA_REM_0( __VA_ARGS__) )
#define VA_GET_27( ... )          VA_GET_26( VA_REM_0( __VA_ARGS__) )
#define VA_GET_28( ... )          VA_GET_27( VA_REM_0( __VA_ARGS__) )
#define VA_GET_29( ... )          VA_GET_28( VA_REM_0( __VA_ARGS__) )
#define VA_GET_30( ... )          VA_GET_29( VA_REM_0( __VA_ARGS__) )
#define VA_GET_31( ... )          VA_GET_30( VA_REM_0( __VA_ARGS__) )
#define VA_GET_32( ... )          VA_GET_31( VA_REM_0( __VA_ARGS__) )
#define VA_GET_33( ... )          VA_GET_32( VA_REM_0( __VA_ARGS__) )
#define VA_GET_34( ... )          VA_GET_33( VA_REM_0( __VA_ARGS__) )
#define VA_GET_35( ... )          VA_GET_34( VA_REM_0( __VA_ARGS__) )
#define VA_GET_36( ... )          VA_GET_35( VA_REM_0( __VA_ARGS__) )
#define VA_GET_37( ... )          VA_GET_36( VA_REM_0( __VA_ARGS__) )
#define VA_GET_38( ... )          VA_GET_37( VA_REM_0( __VA_ARGS__) )
#define VA_GET_39( ... )          VA_GET_38( VA_REM_0( __VA_ARGS__) )
#define VA_GET_40( ... )          VA_GET_39( VA_REM_0( __VA_ARGS__) )
#define VA_GET_41( ... )          VA_GET_40( VA_REM_0( __VA_ARGS__) )
#define VA_GET_42( ... )          VA_GET_41( VA_REM_0( __VA_ARGS__) )
#define VA_GET_43( ... )          VA_GET_42( VA_REM_0( __VA_ARGS__) )
#define VA_GET_44( ... )          VA_GET_43( VA_REM_0( __VA_ARGS__) )
#define VA_GET_45( ... )          VA_GET_44( VA_REM_0( __VA_ARGS__) )
#define VA_GET_46( ... )          VA_GET_45( VA_REM_0( __VA_ARGS__) )
#define VA_GET_47( ... )          VA_GET_46( VA_REM_0( __VA_ARGS__) )
#define VA_GET_48( ... )          VA_GET_47( VA_REM_0( __VA_ARGS__) )
#define VA_GET_49( ... )          VA_GET_48( VA_REM_0( __VA_ARGS__) )
#define VA_GET_50( ... )          VA_GET_49( VA_REM_0( __VA_ARGS__) )
#define VA_GET_51( ... )          VA_GET_50( VA_REM_0( __VA_ARGS__) )
#define VA_GET_52( ... )          VA_GET_51( VA_REM_0( __VA_ARGS__) )
#define VA_GET_53( ... )          VA_GET_52( VA_REM_0( __VA_ARGS__) )
#define VA_GET_54( ... )          VA_GET_53( VA_REM_0( __VA_ARGS__) )
#define VA_GET_55( ... )          VA_GET_54( VA_REM_0( __VA_ARGS__) )
#define VA_GET_56( ... )          VA_GET_55( VA_REM_0( __VA_ARGS__) )
#define VA_GET_57( ... )          VA_GET_56( VA_REM_0( __VA_ARGS__) )
#define VA_GET_58( ... )          VA_GET_57( VA_REM_0( __VA_ARGS__) )
#define VA_GET_59( ... )          VA_GET_58( VA_REM_0( __VA_ARGS__) )
#define VA_GET_60( ... )          VA_GET_59( VA_REM_0( __VA_ARGS__) )
#define VA_GET_61( ... )          VA_GET_60( VA_REM_0( __VA_ARGS__) )
#define VA_GET_62( ... )          VA_GET_61( VA_REM_0( __VA_ARGS__) )
#define VA_GET_63( ... )          VA_GET_62( VA_REM_0( __VA_ARGS__) )

#define VA_DEL_0(...)             __VA_ARGS__
#define VA_DEL_1(...)             VA_REM_0( __VA_ARGS__ )
#define VA_DEL_2( ... )           VA_DEL_1(  __VA_ARGS__ )
#define VA_DEL_3( ... )           VA_DEL_2(  a0,  __VA_ARGS__ )
#define VA_DEL_4( ... )           VA_DEL_3(  a0,  __VA_ARGS__ )
#define VA_DEL_5( ... )           VA_DEL_4(  a0,  __VA_ARGS__ )
#define VA_DEL_6( ... )           VA_DEL_5(  a0,  __VA_ARGS__ )
#define VA_DEL_7( ... )           VA_DEL_6(  a0,  __VA_ARGS__ )
#define VA_DEL_8( ... )           VA_DEL_7(  a0,  __VA_ARGS__ )
#define VA_DEL_9( ... )           VA_DEL_8(  a0,  __VA_ARGS__ )
#define VA_DEL_10( ... )          VA_DEL_9(  a0,  __VA_ARGS__ )
#define VA_DEL_11( ... )          VA_DEL_10( a0,  __VA_ARGS__ )
#define VA_DEL_12( ... )          VA_DEL_11( a0,  __VA_ARGS__ )
#define VA_DEL_13( ... )          VA_DEL_12( a0,  __VA_ARGS__ )
#define VA_DEL_14( ... )          VA_DEL_13( a0,  __VA_ARGS__ )
#define VA_DEL_15( ... )          VA_DEL_14( a0,  __VA_ARGS__ )
#define VA_DEL_16( ... )          VA_DEL_15( a0,  __VA_ARGS__ )
#define VA_DEL_17( ... )          VA_DEL_16( a0,  __VA_ARGS__ )
#define VA_DEL_18( ... )          VA_DEL_17( a0,  __VA_ARGS__ )
#define VA_DEL_19( ... )          VA_DEL_18( a0,  __VA_ARGS__ )
#define VA_DEL_20( ... )          VA_DEL_19( a0,  __VA_ARGS__ )
#define VA_DEL_21( ... )          VA_DEL_20( a0,  __VA_ARGS__ )
#define VA_DEL_22( ... )          VA_DEL_21( a0,  __VA_ARGS__ )
#define VA_DEL_23( ... )          VA_DEL_22( a0,  __VA_ARGS__ )
#define VA_DEL_24( ... )          VA_DEL_23( a0,  __VA_ARGS__ )
#define VA_DEL_25( ... )          VA_DEL_24( a0,  __VA_ARGS__ )
#define VA_DEL_26( ... )          VA_DEL_25( a0,  __VA_ARGS__ )
#define VA_DEL_27( ... )          VA_DEL_26( a0,  __VA_ARGS__ )
#define VA_DEL_28( ... )          VA_DEL_27( a0,  __VA_ARGS__ )
#define VA_DEL_29( ... )          VA_DEL_28( a0,  __VA_ARGS__ )
#define VA_DEL_30( ... )          VA_DEL_29( a0,  __VA_ARGS__ )
#define VA_DEL_31( ... )          VA_DEL_30( a0,  __VA_ARGS__ )
#define VA_DEL_32( ... )          VA_DEL_31( a0,  __VA_ARGS__ )
#define VA_DEL_33( ... )          VA_DEL_32( a0,  __VA_ARGS__ )
#define VA_DEL_34( ... )          VA_DEL_33( a0,  __VA_ARGS__ )
#define VA_DEL_35( ... )          VA_DEL_34( a0,  __VA_ARGS__ )
#define VA_DEL_36( ... )          VA_DEL_35( a0,  __VA_ARGS__ )
#define VA_DEL_37( ... )          VA_DEL_36( a0,  __VA_ARGS__ )
#define VA_DEL_38( ... )          VA_DEL_37( a0,  __VA_ARGS__ )
#define VA_DEL_39( ... )          VA_DEL_38( a0,  __VA_ARGS__ )
#define VA_DEL_40( ... )          VA_DEL_39( a0,  __VA_ARGS__ )
#define VA_DEL_41( ... )          VA_DEL_40( a0,  __VA_ARGS__ )
#define VA_DEL_42( ... )          VA_DEL_41( a0,  __VA_ARGS__ )
#define VA_DEL_43( ... )          VA_DEL_42( a0,  __VA_ARGS__ )
#define VA_DEL_44( ... )          VA_DEL_43( a0,  __VA_ARGS__ )
#define VA_DEL_45( ... )          VA_DEL_44( a0,  __VA_ARGS__ )
#define VA_DEL_46( ... )          VA_DEL_45( a0,  __VA_ARGS__ )
#define VA_DEL_47( ... )          VA_DEL_46( a0,  __VA_ARGS__ )
#define VA_DEL_48( ... )          VA_DEL_47( a0,  __VA_ARGS__ )
#define VA_DEL_49( ... )          VA_DEL_48( a0,  __VA_ARGS__ )
#define VA_DEL_50( ... )          VA_DEL_49( a0,  __VA_ARGS__ )
#define VA_DEL_51( ... )          VA_DEL_50( a0,  __VA_ARGS__ )
#define VA_DEL_52( ... )          VA_DEL_51( a0,  __VA_ARGS__ )
#define VA_DEL_53( ... )          VA_DEL_52( a0,  __VA_ARGS__ )
#define VA_DEL_54( ... )          VA_DEL_53( a0,  __VA_ARGS__ )
#define VA_DEL_55( ... )          VA_DEL_54( a0,  __VA_ARGS__ )
#define VA_DEL_56( ... )          VA_DEL_55( a0,  __VA_ARGS__ )
#define VA_DEL_57( ... )          VA_DEL_56( a0,  __VA_ARGS__ )
#define VA_DEL_58( ... )          VA_DEL_57( a0,  __VA_ARGS__ )
#define VA_DEL_59( ... )          VA_DEL_58( a0,  __VA_ARGS__ )
#define VA_DEL_60( ... )          VA_DEL_59( a0,  __VA_ARGS__ )
#define VA_DEL_61( ... )          VA_DEL_60( a0,  __VA_ARGS__ )
#define VA_DEL_62( ... )          VA_DEL_61( a0,  __VA_ARGS__ )
#define VA_DEL_63( ... )          VA_DEL_62( a0,  __VA_ARGS__ )
#define VA_DEL_64( ... )

#define VA_CPY_0( ... )
#define VA_CPY_1(a0,  ... )      a0
#define VA_CPY_2(a0,  ... )      a0, VA_CPY_1(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_3(a0,  ... )      a0, VA_CPY_2(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_4(a0,  ... )      a0, VA_CPY_3(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_5(a0,  ... )      a0, VA_CPY_4(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_6(a0,  ... )      a0, VA_CPY_5(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_7(a0,  ... )      a0, VA_CPY_6(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_8(a0,  ... )      a0, VA_CPY_7(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_9(a0,  ... )      a0, VA_CPY_8(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_10(a0,  ... )     a0, VA_CPY_9(  VA_REM_0( __VA_ARGS__) )
#define VA_CPY_11(a0,  ... )     a0, VA_CPY_10( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_12(a0,  ... )     a0, VA_CPY_11( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_13(a0,  ... )     a0, VA_CPY_12( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_14(a0,  ... )     a0, VA_CPY_13( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_15(a0,  ... )     a0, VA_CPY_14( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_16(a0,  ... )     a0, VA_CPY_15( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_17(a0,  ... )     a0, VA_CPY_16( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_18(a0,  ... )     a0, VA_CPY_17( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_19(a0,  ... )     a0, VA_CPY_18( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_20(a0,  ... )     a0, VA_CPY_19( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_21(a0,  ... )     a0, VA_CPY_20( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_22(a0,  ... )     a0, VA_CPY_21( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_23(a0,  ... )     a0, VA_CPY_22( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_24(a0,  ... )     a0, VA_CPY_23( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_25(a0,  ... )     a0, VA_CPY_24( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_26(a0,  ... )     a0, VA_CPY_25( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_27(a0,  ... )     a0, VA_CPY_26( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_28(a0,  ... )     a0, VA_CPY_27( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_29(a0,  ... )     a0, VA_CPY_28( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_30(a0,  ... )     a0, VA_CPY_29( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_31(a0,  ... )     a0, VA_CPY_30( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_32(a0,  ... )     a0, VA_CPY_31( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_33(a0,  ... )     a0, VA_CPY_32( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_34(a0,  ... )     a0, VA_CPY_33( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_35(a0,  ... )     a0, VA_CPY_34( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_36(a0,  ... )     a0, VA_CPY_35( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_37(a0,  ... )     a0, VA_CPY_36( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_38(a0,  ... )     a0, VA_CPY_37( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_39(a0,  ... )     a0, VA_CPY_38( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_40(a0,  ... )     a0, VA_CPY_39( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_41(a0,  ... )     a0, VA_CPY_40( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_42(a0,  ... )     a0, VA_CPY_41( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_43(a0,  ... )     a0, VA_CPY_42( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_44(a0,  ... )     a0, VA_CPY_43( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_45(a0,  ... )     a0, VA_CPY_44( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_46(a0,  ... )     a0, VA_CPY_45( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_47(a0,  ... )     a0, VA_CPY_46( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_48(a0,  ... )     a0, VA_CPY_47( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_49(a0,  ... )     a0, VA_CPY_48( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_50(a0,  ... )     a0, VA_CPY_49( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_51(a0,  ... )     a0, VA_CPY_50( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_52(a0,  ... )     a0, VA_CPY_51( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_53(a0,  ... )     a0, VA_CPY_52( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_54(a0,  ... )     a0, VA_CPY_53( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_55(a0,  ... )     a0, VA_CPY_54( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_56(a0,  ... )     a0, VA_CPY_55( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_57(a0,  ... )     a0, VA_CPY_56( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_58(a0,  ... )     a0, VA_CPY_57( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_59(a0,  ... )     a0, VA_CPY_58( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_60(a0,  ... )     a0, VA_CPY_59( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_61(a0,  ... )     a0, VA_CPY_60( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_62(a0,  ... )     a0, VA_CPY_61( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_63(a0,  ... )     a0, VA_CPY_62( VA_REM_0( __VA_ARGS__) )
#define VA_CPY_64(a0,  ... )     a0, VA_CPY_63( VA_REM_0( __VA_ARGS__) )

#else

#define VA_GET_0(a0, ...) a0
#define VA_GET_1(a0, a1, ...) a1
#define VA_GET_2(a0, a1, a2, ...) a2
#define VA_GET_3(a0, a1, a2, a3, ...) a3
#define VA_GET_4(a0, a1, a2, a3, a4, ...) a4
#define VA_GET_5(a0, a1, a2, a3, a4, a5, ...) a5
#define VA_GET_6(a0, a1, a2, a3, a4, a5, a6, ...) a6
#define VA_GET_7(a0, a1, a2, a3, a4, a5, a6, a7, ...) a7
#define VA_GET_8(a0, a1, a2, a3, a4, a5, a6, a7, a8, ...) a8
#define VA_GET_9(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, ...) a9
#define VA_GET_10(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) a10
#define VA_GET_11(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) a11
#define VA_GET_12(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, ...) a12
#define VA_GET_13(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, ...) a13
#define VA_GET_14(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, ...) a14
#define VA_GET_15(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, ...) a15
#define VA_GET_16(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, ...) a16
#define VA_GET_17(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, ...) a17
#define VA_GET_18(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, ...) a18
#define VA_GET_19(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, ...) a19
#define VA_GET_20(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, ...) a20
#define VA_GET_21(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, ...) a21
#define VA_GET_22(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, ...) a22
#define VA_GET_23(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, ...) a23
#define VA_GET_24(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, ...) a24
#define VA_GET_25(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, ...) a25
#define VA_GET_26(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, ...) a26
#define VA_GET_27(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, ...) a27
#define VA_GET_28(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, ...) a28
#define VA_GET_29(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, ...) a29
#define VA_GET_30(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, ...) a30
#define VA_GET_31(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, ...) a31
#define VA_GET_32(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, ...) a32
#define VA_GET_33(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, ...) a33
#define VA_GET_34(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, ...) a34
#define VA_GET_35(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, ...) a35
#define VA_GET_36(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, ...) a36
#define VA_GET_37(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, ...) a37
#define VA_GET_38(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, ...) a38
#define VA_GET_39(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, ...) a39
#define VA_GET_40(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, ...) a40
#define VA_GET_41(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, ...) a41
#define VA_GET_42(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, ...) a42
#define VA_GET_43(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, ...) a43
#define VA_GET_44(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, ...) a44
#define VA_GET_45(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, ...) a45
#define VA_GET_46(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, ...) a46
#define VA_GET_47(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, ...) a47
#define VA_GET_48(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, ...) a48
#define VA_GET_49(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, ...) a49
#define VA_GET_50(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, ...) a50
#define VA_GET_51(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, ...) a51
#define VA_GET_52(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, ...) a52
#define VA_GET_53(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, ...) a53
#define VA_GET_54(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, ...) a54
#define VA_GET_55(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, ...) a55
#define VA_GET_56(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, ...) a56
#define VA_GET_57(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, ...) a57
#define VA_GET_58(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, ...) a58
#define VA_GET_59(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, ...) a59
#define VA_GET_60(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, ...) a60
#define VA_GET_61(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, ...) a61
#define VA_GET_62(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, ...) a62
#define VA_GET_63(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63, ...) a63

#define VA_DEL_0(...) __VA_ARGS__
#define VA_DEL_1(a0, ...) __VA_ARGS__
#define VA_DEL_2(a0, a1, ...) __VA_ARGS__
#define VA_DEL_3(a0, a1, a2, ...) __VA_ARGS__
#define VA_DEL_4(a0, a1, a2, a3, ...) __VA_ARGS__
#define VA_DEL_5(a0, a1, a2, a3, a4, ...) __VA_ARGS__
#define VA_DEL_6(a0, a1, a2, a3, a4, a5, ...) __VA_ARGS__
#define VA_DEL_7(a0, a1, a2, a3, a4, a5, a6, ...) __VA_ARGS__
#define VA_DEL_8(a0, a1, a2, a3, a4, a5, a6, a7, ...) __VA_ARGS__
#define VA_DEL_9(a0, a1, a2, a3, a4, a5, a6, a7, a8, ...) __VA_ARGS__
#define VA_DEL_10(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, ...) __VA_ARGS__
#define VA_DEL_11(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) __VA_ARGS__
#define VA_DEL_12(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) __VA_ARGS__
#define VA_DEL_13(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, ...) __VA_ARGS__
#define VA_DEL_14(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, ...) __VA_ARGS__
#define VA_DEL_15(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, ...) __VA_ARGS__
#define VA_DEL_16(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, ...) __VA_ARGS__
#define VA_DEL_17(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, ...) __VA_ARGS__
#define VA_DEL_18(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, ...) __VA_ARGS__
#define VA_DEL_19(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, ...) __VA_ARGS__
#define VA_DEL_20(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, ...) __VA_ARGS__
#define VA_DEL_21(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, ...) __VA_ARGS__
#define VA_DEL_22(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, ...) __VA_ARGS__
#define VA_DEL_23(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, ...) __VA_ARGS__
#define VA_DEL_24(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, ...) __VA_ARGS__
#define VA_DEL_25(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, ...) __VA_ARGS__
#define VA_DEL_26(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, ...) __VA_ARGS__
#define VA_DEL_27(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, ...) __VA_ARGS__
#define VA_DEL_28(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, ...) __VA_ARGS__
#define VA_DEL_29(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, ...) __VA_ARGS__
#define VA_DEL_30(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, ...) __VA_ARGS__
#define VA_DEL_31(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, ...) __VA_ARGS__
#define VA_DEL_32(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, ...) __VA_ARGS__
#define VA_DEL_33(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, ...) __VA_ARGS__
#define VA_DEL_34(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, ...) __VA_ARGS__
#define VA_DEL_35(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, ...) __VA_ARGS__
#define VA_DEL_36(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, ...) __VA_ARGS__
#define VA_DEL_37(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, ...) __VA_ARGS__
#define VA_DEL_38(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, ...) __VA_ARGS__
#define VA_DEL_39(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, ...) __VA_ARGS__
#define VA_DEL_40(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, ...) __VA_ARGS__
#define VA_DEL_41(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, ...) __VA_ARGS__
#define VA_DEL_42(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, ...) __VA_ARGS__
#define VA_DEL_43(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, ...) __VA_ARGS__
#define VA_DEL_44(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, ...) __VA_ARGS__
#define VA_DEL_45(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, ...) __VA_ARGS__
#define VA_DEL_46(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, ...) __VA_ARGS__
#define VA_DEL_47(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, ...) __VA_ARGS__
#define VA_DEL_48(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, ...) __VA_ARGS__
#define VA_DEL_49(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, ...) __VA_ARGS__
#define VA_DEL_50(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, ...) __VA_ARGS__
#define VA_DEL_51(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, ...) __VA_ARGS__
#define VA_DEL_52(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, ...) __VA_ARGS__
#define VA_DEL_53(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, ...) __VA_ARGS__
#define VA_DEL_54(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, ...) __VA_ARGS__
#define VA_DEL_55(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, ...) __VA_ARGS__
#define VA_DEL_56(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, ...) __VA_ARGS__
#define VA_DEL_57(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, ...) __VA_ARGS__
#define VA_DEL_58(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, ...) __VA_ARGS__
#define VA_DEL_59(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, ...) __VA_ARGS__
#define VA_DEL_60(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, ...) __VA_ARGS__
#define VA_DEL_61(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, ...) __VA_ARGS__
#define VA_DEL_62(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, ...) __VA_ARGS__
#define VA_DEL_63(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, ...) __VA_ARGS__
#define VA_DEL_64( ... )

#define VA_CPY_0( ... )
#define VA_CPY_1(a0,  ... ) a0
#define VA_CPY_2(a0, a1, ... ) a0, a1
#define VA_CPY_3(a0, a1, a2, ... ) a0, a1, a2
#define VA_CPY_4(a0, a1, a2, a3, ... ) a0, a1, a2, a3
#define VA_CPY_5(a0, a1, a2, a3, a4, ... ) a0, a1, a2, a3, a4
#define VA_CPY_6(a0, a1, a2, a3, a4, a5, ... ) a0, a1, a2, a3, a4, a5
#define VA_CPY_7(a0, a1, a2, a3, a4, a5, a6, ... ) a0, a1, a2, a3, a4, a5, a6
#define VA_CPY_8(a0, a1, a2, a3, a4, a5, a6, a7, ... ) a0, a1, a2, a3, a4, a5, a6, a7
#define VA_CPY_9(a0, a1, a2, a3, a4, a5, a6, a7, a8, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8
#define VA_CPY_10(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
#define VA_CPY_11(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
#define VA_CPY_12(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
#define VA_CPY_13(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
#define VA_CPY_14(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
#define VA_CPY_15(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
#define VA_CPY_16(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
#define VA_CPY_17(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16
#define VA_CPY_18(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17
#define VA_CPY_19(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18
#define VA_CPY_20(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19
#define VA_CPY_21(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20
#define VA_CPY_22(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21
#define VA_CPY_23(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22
#define VA_CPY_24(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23
#define VA_CPY_25(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24
#define VA_CPY_26(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25
#define VA_CPY_27(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26
#define VA_CPY_28(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27
#define VA_CPY_29(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28
#define VA_CPY_30(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29
#define VA_CPY_31(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30
#define VA_CPY_32(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31
#define VA_CPY_33(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32
#define VA_CPY_34(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33
#define VA_CPY_35(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34
#define VA_CPY_36(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35
#define VA_CPY_37(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36
#define VA_CPY_38(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37
#define VA_CPY_39(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38
#define VA_CPY_40(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39
#define VA_CPY_41(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40
#define VA_CPY_42(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41
#define VA_CPY_43(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42
#define VA_CPY_44(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43
#define VA_CPY_45(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44
#define VA_CPY_46(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45
#define VA_CPY_47(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46
#define VA_CPY_48(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47
#define VA_CPY_49(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48
#define VA_CPY_50(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49
#define VA_CPY_51(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50
#define VA_CPY_52(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51
#define VA_CPY_53(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52
#define VA_CPY_54(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53
#define VA_CPY_55(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54
#define VA_CPY_56(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55
#define VA_CPY_57(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56
#define VA_CPY_58(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57
#define VA_CPY_59(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58
#define VA_CPY_60(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59
#define VA_CPY_61(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60
#define VA_CPY_62(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61
#define VA_CPY_63(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62
#define VA_CPY_64(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63, ... ) a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63

#endif

VA_EAT( VA_STRING( VA_GET(63, VA_ARGS_64 ) ) : ( a63 ) )
VA_EAT( VA_STRING( VA_DEL(1, VA_ARGS_64 ) ) : ( a1, a2, ..., a62, a63 ) )
VA_EAT( VA_STRING( VA_DEL(63, VA_ARGS_64 ) ) : ( a63 ) )
VA_EAT( VA_STRING( VA_CPY(0, 4, VA_ARGS_64 ) ) : ( a0, a1, a2, a3 ) )
VA_EAT( VA_STRING( VA_CPY(31, 4, VA_ARGS_64 ) ) : ( a31, a32, a33, a34 ) )

// -----------------------------------------------------------------------------
// variadic arguments macro
//
#define VM_USES_I( NAME, i )  CAT( NAME##_, i)
#define VM_USES( NAME, ... )  \
  VM_USES_I( NAME, VA_COUNT(__VA_ARGS__) )( __VA_ARGS__ )

// -----------------------------------------------------------------------------
// join variadic parameters < variadic arguments macro >
//
#define VM_JOIN(...)          VM_USES( VM_JOIN_, ##__VA_ARGS__ )
#define VM_JOIN_0( )
#define VM_JOIN_1( a )        a
#define VM_JOIN_2( a, b )     CAT(a, b )
#define VM_JOIN_3( a, ... )   CAT(a, VM_JOIN_2( __VA_ARGS__ ) )
#define VM_JOIN_4( a, ... )   CAT(a, VM_JOIN_3( __VA_ARGS__ ) )
#define VM_JOIN_3( a, ... )   CAT(a, VM_JOIN_2( __VA_ARGS__ ) )
#define VM_JOIN_4( a, ... )   CAT(a, VM_JOIN_3( __VA_ARGS__ ) )
#define VM_JOIN_5( a, ... )   CAT(a, VM_JOIN_4( __VA_ARGS__ ) )
#define VM_JOIN_6( a, ... )   CAT(a, VM_JOIN_5( __VA_ARGS__ ) )
#define VM_JOIN_7( a, ... )   CAT(a, VM_JOIN_6( __VA_ARGS__ ) )
#define VM_JOIN_8( a, ... )   CAT(a, VM_JOIN_7( __VA_ARGS__ ) )
#define VM_JOIN_9( a, ... )   CAT(a, VM_JOIN_8( __VA_ARGS__ ) )

#endif /* __VA_MACRO_H__ */
