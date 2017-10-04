#ifndef __LOOP_MACRO_H__
#define __LOOP_MACRO_H__
#include "macro_expr.h"

#define EMPTY()
#define EAT(...)
#define COMMA()               ,
#define EXPR(...)             __VA_ARGS__

/* https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms
 *
 * Detection
 *
 * Detection techniques can be used to detect if the parameter is
 * a certain value or if it is parenthesis(). It relies on vardiac arguments
 * expanding to different number of parameters.
 *
 * At the core of detection is a *CHECK* macro with a *PROBE* macro
 * So with this, we can create some detection macros. For instance,
 * if we want to detect for parenthesis:
 *
 * CHECK( PROBE( ~ ) ) --> CHECK( x, 1, ) --> CHECK_N( x, 1, 0, ) --> 1
 * CHECK( PROBE ) --------------------------> CHECK_N( PROBE, 0, ) --> 0
 *
 * IS_PAREN(  ()  ) --> CHECK( IS_PAREN_PROBE () ) --> CHECK( PROBE(~) )
 *  CHECK( PROBE( ~ ) ) --> CHECK( x, 1, ) --> CHECK_N( x, 1, 0, ) --> 1
 *
 * IS_PAREN( xxxx )  --> CHECK( IS_PAREN_PROBE xxxx )
 *  CHECK_N( IS_PAREN_PROBE xxxx, 0 ) --> 0
 */
#define CHECK(...)            CHECK_N( __VA_ARGS__, 0, )
#define CHECK_N(x, n, ...)    n

//#define IS_PAREN(x)         IS_PAREN_PROBE x : error !
#define IS_PAREN( x )         CHECK( IS_PAREN_PROBE x )
#define IS_PAREN_PROBE(...)   PROBE(~)
#define PROBE(x)              x, 1,

/*
 * Pattern Matching
 *
 * The ## operator is used to concatenate two tokens into one token.
 * This is provides a very powerful way to do pattern matching.
 * Say we want to write a IIF macro, we could write it like this
 *
 * #define IIF_0( true,false )  false
 * #define IIF_1( true,false )  true
 * #define IIF(cond)            IIF_##cond
 *
 * However there is one problem with this approach.
 * A subtle side effect of the ## operator is that it inhibits expansion.
 * Heres an example:
 *
 * #define A() 1
 *
 * IIF(0)( true,false )     --> IIF_0( true,false )     --> false
 * IIF(1)( true,false )     --> IIF_1( true,false )     --> true
 * IIF( A() )( true,false ) --> IIF_A()( true,false )   --> ?????
 *
 * The way to work around this is to use another indirection.
 * Sense this is commonly done we can write a macro called CAT that
 * will concatenate without inhibition.
 *
 * IIF( A() )( true,false ) --> IIF(1)(true, false)
 * IIF(1)(true, false)      --> IIF_1( true,false )     --> true
 * IIF(0)( true,false )     --> IIF_0( true,false )     --> false
 *
 * With pattern matching we can define other operations
 */

// BITAND( x ) ( y )
// x==0, y==x : 0
// x==1, y==0 : 0
// x==1, y==1 : 1
// BITAND( x ) ( BITAND( y )( z ) )
#define BITAND( x )           CAT_PRIM(BITAND_, x)
#define BITAND_0(y)           0
#define BITAND_1(y)           y

#define NOT( x )              CHECK( CAT_PRIM(NOT_, x) )
#define NOT_0                 ~, 1,

#define COMPL(b)              CAT_PRIM(COMPL_, b)
#define COMPL_0               1
#define COMPL_1               0

// IIF( cond )( macro1, macro2 )( arg ) :: ( cond ) ? macro1(arg) : macro2(arg)
#define IIF(cond)             CAT_PRIM( IIF_, cond )
#define IIF_0( t, ... )       __VA_ARGS__
#define IIF_1( t, ... )       t

/*
 * Now, say we want to write a generalized IF macro that picks false if its 0
 * otherwise it would pick true. We can use these detection techniques to do that.
 * First, we start by writing a NOT operator which is just like an IS_0 macro,
 * Next we use the COMPL macro that we wrote to inverse this result,
 * and then call IIF
 */
#define BOOL(x)               COMPL( NOT(x) )   // 0, 1
#define IF(c)                 IIF( BOOL(c) )    // IIF( 0 ), IIF( 1 )
/*
 * Recursion
 *
 * Unfortunately, macros can't expand recursively. When a macro expands its
 * painted blue, and can no longer expand for that scan.
 * First, there are ways to work around this to keep macros expanding.
 * Secondly, we can detect if a macro is painted blue (because it wont expand)
 * and use this state to expand to a different macro.
 *
 * Well when macros are scanned and expanded, they are painted blue,
 * which means they can no longer expand for that one scan;
 * but when the preprocessor starts another scan all these blue painted macros
 * are cleared, which means they can expand again.
 *
 * Deferred expression
 * A deferred expression is an expression that requires more scans to fully expand.
 * Heres an example:
 *
 * #define A()        123
 *
 * A()                123
 * DEFER(A)()         A ()  -- requires one more scan to fully expand
 * EXPR(DEFER(A)())   123 ---- the EXPR macro forces another scan
 *
 * So what that means for us, is we can create multiple EXPR macros,
 * which will let our deferred expression expand on different preprocessor scans
 *
 */
#define DEFER(id)             id EMPTY()
#define OBSTRUCT(id)          id DEFER(EMPTY)()

#define EXECUTE(...)            EXPAND(__VA_ARGS__)
#define EXPAND(...)             __VA_ARGS__
#define DISCARD(...)
#define WHEN(c)                 IF( c )(EXPAND, DISCARD)

/*
 * We can use this to write a REPEAT macro.
 * We split the macro in two parts in the interface and implementation.
 * This just makes it easier to set up any values that will be used several
 * times, such as incrementing the recursion state and decrementing the
 * repeat counter.
 *
 * Also we pass the OBSTRUCT macro in as the first parameter. This is just to
 * make it easier and cleaner to write a deferred expression in the implementation.
 * So instead of writing DEFER(WHEN)(n), we will just write WHEN _(n)
 *
 */

// -----------------------------------------------------------------------------
// This is the interface
// s - This is the current recursion state
// n - This is the number of repeats
// m - A macro to be called at each repeat: m( s, n, ... )
//
#define REPEAT_M( state, counter, a0 )   state, counter, arg0
#define REPEAT_S(s, n, m, ...) REPEAT_I( OBSTRUCT(), INC(s), DEC(n), m, __VA_ARGS__)
// -----------------------------------------------------------------------------
// This is the implementation,
#define REPEAT_INDIRECT()   REPEAT_I
#define REPEAT_I(_, s, n, m, ...) \
  WHEN _(n) \
  ( \
    EXPR_S _(s) \
    ( \
      REPEAT_INDIRECT _()( OBSTRUCT _(), INC _(s), DEC _(n), m, __VA_ARGS__) \
    ) \
  ) \
  m _(s, n, __VA_ARGS__)

// -----------------------------------------------------------------------------
// This is the example
EAT( uint8_t * ____ = TO_STRING( EXPR_S(0)( REPEAT_S( 0, 2, REPEAT_M, arg0 ) ) ) )
/*
 * state   index     args
 * 3,      0,        a0,
 * 2,      1,        a0,
 * 1,      2,        a0,
 *
 */

// -----------------------------------------------------------------------------
// This is the interface
// N - This is the number of loops
// M - A macro to be called at each repeat: M( counter, ... )
//
#define LOOP_M( counter, VA )   counter, VA
#define LOOP( N, M, ... )       EXECUTE( LOOP_S( 1, N, M, __VA_ARGS__ ) )
#define LOOP_S(s, n, m, ...)    LOOP_I( OBSTRUCT(), s, DEC(n), m, __VA_ARGS__)
// -----------------------------------------------------------------------------
// This is the implementation,
#define LOOP_INDIRECT()   LOOP_I
#define LOOP_I(_, s, n, m, ...) \
  WHEN _(n) \
  ( \
    EXPR_S _(s) \
    ( \
      LOOP_INDIRECT _()( OBSTRUCT _(), INC _(s), DEC _(n), m, __VA_ARGS__) \
    ) \
  ) \
  m _(n, __VA_ARGS__)

// -----------------------------------------------------------------------------
// This is the example
EAT( uint8_t * ____ = TO_STRING( LOOP( 2, LOOP_M, a0 ) ) )
/*
 * index     args
 * 0,        a0,
 * 1,        a0,
 * 2,        a0,
 *
 */

// -----------------------------------------------------------------------------
// This is the interface
// s - This is the current recursion state
// pred -
// op -
// m - A macro to be called at each repeat: m( s, n, ...)
//
#define FOR_S(s, pred, op, macro, ...) \
  FOR_I(OBSTRUCT(), INC(s), pred, op, macro, __VA_ARGS__) \
  /* nothing */

// -----------------------------------------------------------------------------
// This is the implementation
//
#define FOR_INDIRECT() FOR_I
#define FOR_I(_, s, pred, op, macro, ...) \
  WHEN _(pred _(s, __VA_ARGS__) )       \
  ( \
    macro _(s, __VA_ARGS__) \
    EVAL_S(s) _( \
      FOR_INDIRECT _()( OBSTRUCT _(), INC(s), pred, op, macro, op _(s, __VA_ARGS__) ) \
    ) \
  ) \
  /* nothing */

// -----------------------------------------------------------------------------
//  This is the example
//
//  #define PRED(s, state) BOOL(state)
//  #define OP(s, state) DEC(state)
//  #define MACRO(s, state) state
//
//  EXPR_S(0)(FOR_S(0, PRED, OP, MACRO, 8)) // 8 7 6 5 4 3 2 1

// -----------------------------------------------------------------------------
// This is the interface
// s - This is the current recursion state
// pred -
// op -
#define WHILE_S(s, pred, op, ...) \
  WHILE_I( OBSTRUCT(), INC(s), pred, op, __VA_ARGS__ )

// -----------------------------------------------------------------------------
// This is the implementation
//
#define WHILE_INDIRECT() WHILE_I
#define WHILE_I(_, s, pred, op, ...) \
  WHEN _(pred _(s, __VA_ARGS__)) \
  ( \
    __VA_ARGS__ \
    EVAL_S(s) _ \
    ( \
        WHILE_INDIRECT _()(OBSTRUCT _(), INC(s), pred, op, op _(s, __VA_ARGS__) ) \
    ) \
  )

// -----------------------------------------------------------------------------
//  This is the example
//  #define PRED(s, state) BOOL(state)
//  #define OP(s, state) DEC(state)
//
//  EXPR_S(0)(WHILE_S(0, PRED, OP, 8)) // 8 7 6 5 4 3 2 1

#define COMMA_IF(n)           IF(n)( COMMA, EAT )()
// -----------------------------------------------------------------------------
//    #define MM(s, i, id) \
//      COMMA_IF(i) template< > clazz id ## i \
//        /* no thing */
//
//    __root uint8_t * str1 = TO_STRING( EXPR_S(0)(REPEAT_S(0, 3, MM, T)) );
//      template< > clazz T0
//    , template< > clazz T1
//    , template< > clazz T2
//
// -----------------------------------------------------------------------------
//
//    #define B(s, i, _) COMMA_IF(i) class
//
//    #define M(s, i, id) \
//      COMMA_IF(i) template< EXPR_S(s)( REPEAT_S(s, INC(i), B, ~) ) > clazz id ## i \
//        /* no thing */
//
//    class
//    class , class
//    class , class , class
//
//    __root uint8_t * str1 = TO_STRING( EXPR_S(0)(REPEAT_S(0, 3, M, T)) );
//      template< class >                  clazz T0
//    , template< class , class >          clazz T1
//    , template< class , class , class >  clazz T2

// -----------------------------------------------------------------------------
// https://raw.github.com/swansontec/map-macro/master/map.h
//
#define MAP_EVAL0(...) __VA_ARGS__
#define MAP_EVAL1(...) MAP_EVAL0 (MAP_EVAL0 (MAP_EVAL0 (__VA_ARGS__)))
#define MAP_EVAL2(...) MAP_EVAL1 (MAP_EVAL1 (MAP_EVAL1 (__VA_ARGS__)))
#define MAP_EVAL3(...) MAP_EVAL2 (MAP_EVAL2 (MAP_EVAL2 (__VA_ARGS__)))
#define MAP_EVAL4(...) MAP_EVAL3 (MAP_EVAL3 (MAP_EVAL3 (__VA_ARGS__)))
#define MAP_EVAL(...)  MAP_EVAL4 (MAP_EVAL4 (MAP_EVAL4 (__VA_ARGS__)))

#define MAP_END(...)

#define MAP_OUT
#define MAP_GET_END() 0, MAP_END
#define MAP_NEXT0(item, next, ...) next MAP_OUT
#define MAP_NEXT1(item, next) MAP_NEXT0 (item, next, 0)
#define MAP_NEXT(item, next)  MAP_NEXT1 (MAP_GET_END item, next)

#define MAP0(m, x, peek, ...) m(x) MAP_NEXT (peek, MAP1) (m, peek, __VA_ARGS__)
#define MAP1(m, x, peek, ...) m(x) MAP_NEXT (peek, MAP0) (m, peek, __VA_ARGS__)
#define MAP(m, ...)           MAP_EVAL (MAP1 (m, __VA_ARGS__, (), 0))

#define MAP_PRINT(a) printf(#a": %d", a)
EAT( MAP(MAP_PRINT, a, b, c) ==> printf("a"": %d", a) printf("b"": %d", b) printf("c"": %d", c) )

#define FOR_EACH(m, ...)      CAT(FOR_EACH_, VA_COUNT(__VA_ARGS__))(m, __VA_ARGS__)

#define FOR_EACH_1(m, x1) m(x1)
#define FOR_EACH_2(m, x1, x2) m(x1) m(x2)
#define FOR_EACH_3(m, x1, x2, x3) m(x1) m(x2) m(x3)
#define FOR_EACH_4(m, x1, x2, x3, x4) m(x1) m(x2) m(x3) m(x4)
#define FOR_EACH_5(m, x1, x2, x3, x4, x5) m(x1) m(x2) m(x3) m(x4) m(x5)
#define FOR_EACH_6(m, x1, x2, x3, x4, x5, x6) m(x1) m(x2) m(x3) m(x4) m(x5) m(x6)
#define FOR_EACH_7(m, x1, x2, x3, x4, x5, x6, x7) m(x1) m(x2) m(x3) m(x4) m(x5) m(x6) m(x7)
#define FOR_EACH_8(m, x1, x2, x3, x4, x5, x6, x7, x8) m(x1) m(x2) m(x3) m(x4) m(x5) m(x6) m(x7) m(x8)

#endif /* __LOOP_MACRO_H__ */
