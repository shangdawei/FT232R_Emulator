#include <stdlib.h>
#include <string.h>
#include "fifo.h"

/* Macro for getting minimum value. */
#define MIN(a, b)                             \
  ((a) < (b) ? (a) : (b))

/* Macro for getting maximum value. */
#define MAX(a, b)                             \
  ((a) > (b) ? (a) : (b))

#define ABS(a)                                \
  ( (a) < 0 ? -(a) : (a) )

// This macro rounds up addr to the align boundary.
#define ALIGN_UP(addr, align)                 \
  ( ((uint32_t)(addr)) & ( (align) - 1 ) ) ?  \
  ( ( ((uint32_t)(addr)) + (align) - 1) &     \
  (~( (align) - 1) ) ) : ( (uint32_t)(addr) )

/*
 * Determine whether some value is a power of two,
 * where zero is *not* considered a power of two.
 */
static uint32_t IsPower2( uint32_t n )
{
  return ( n != 0 && ( ( n & ( n - 1 ) ) == 0 ) );
}

/**
 * Log2 - log of base 2 of 32-bit unsigned value
 */
static uint32_t Log2( uint32_t v )
{
  uint32_t l = 0;
  while ( ( 1UL << l ) < v )
    l++;
  return l;
}

/*
 * round the given value up to the nearest power of two
 * the result is undefined when n == 0
 */
static uint32_t RoundUpPower2( uint32_t n )
{
  if ( n <= 1 )
    return n;

  if ( n & ( n - 1 ) == 0 )
    return n;

  return 1UL << ( Log2( n ) + 1 );
}

/*
 * round the given value down to nearest power of two
 * the result is undefined when n == 0
 */
static uint32_t RoundDownPower2( uint32_t n )
{
  if ( n == 0 )
    return n;

  return 1UL << Log2( n );
}

static uint32_t FIFO_ReadableSize( FIFO *fifo )
{
  return fifo->writeIndex - fifo->readIndex;
}

static uint32_t FIFO_WritableSize( FIFO *fifo )
{
  return ( fifo->capacity ) - ( fifo->writeIndex - fifo->readIndex );
}

static void FIFO_DoWrite( FIFO *fifo, void * data, uint32_t count )
{
  uint32_t writeIndex = fifo->writeIndex & ( fifo->capacity - 1 );
  uint32_t upper = MIN( count, fifo->capacity - writeIndex );
  uint32_t lower = count - upper;
  memcpy( fifo->memory + writeIndex, data, upper );
  if ( lower )
    memcpy( fifo->memory, (uint8_t*) data + upper, lower );
  fifo->writeIndex += count;
}

static void FIFO_DoRead( FIFO *fifo, void * data, uint32_t count )
{
  uint32_t readIndex = fifo->readIndex & ( fifo->capacity - 1 );
  uint32_t upper = MIN( count, fifo->capacity - readIndex );
  uint32_t lower = count - upper;

  memcpy( data, fifo->memory + readIndex, upper );
  if ( lower )
    memcpy( (uint8_t*) data + upper, fifo->memory, lower );

  fifo->readIndex += count;
}

void FIFO_Init( FIFO *fifo, uint32_t capacity, void *memory )
{
  if ( IsPower2( capacity ) == 0 )
    capacity = RoundDownPower2( capacity );

  fifo->capacity = capacity;
  fifo->writeIndex = 0;
  fifo->readIndex = 0;
  fifo->memory = (uint8_t *) memory;
}

FIFO * FIFO_Create( uint32_t capacity )
{
  if ( IsPower2( capacity ) == 0 )
    capacity = RoundUpPower2( capacity );

  uint32_t size = ALIGN_UP( sizeof(FIFO), 4 );
  FIFO * fifo = (FIFO *) malloc( size + capacity );
  if ( fifo )
  {
    uint8_t * memoy = (uint8_t *) ( (uint32_t) fifo + size );

    FIFO_Init( fifo, capacity, memoy );
  }
  return fifo;
}

void FIFO_Destroy( FIFO *fifo )
{
  free( fifo );
}

void FIFO_Clear( FIFO *fifo )
{
  fifo->readIndex = fifo->writeIndex;
}

uint32_t FIFO_IsEmpty( FIFO *fifo )
{
  return fifo->writeIndex == fifo->readIndex;
}

uint32_t FIFO_IsFull( FIFO *fifo )
{
  return fifo->readIndex + fifo->capacity == fifo->writeIndex;
}

// |<--memory  |<--readIndex0   |<--readIndex1
// |<--Space-->|<--continuous-->|<--Space-->|
// |<-----------------capacity------------->|<-----------------capacity------------->|
// |<--memory              |<--readIndex0   |<--readIndex1                           |
// |<--Lower-->|<--Space-->|<-----Upper---->|<--Lower-->|<--Space-->|<-----Upper---->|
// |                       |<--continuous-->|           |
//                         |<----------readable-------->|
//
// Get continuous memory for DMA transfer
// index  : continuous memory offset
// Return : continuous memory size
// After DMA transfer, then call FIFO_Flush() : Older data is invalid
uint32_t FIFO_Readable( FIFO *fifo, uint32_t * index )
{
  uint32_t readable = FIFO_ReadableSize( fifo );
  uint32_t readIndex = fifo->readIndex & ( fifo->capacity - 1 );
  uint32_t continuous = fifo->capacity - readIndex;
  *index = readIndex;
  return ( readable > continuous ) ? continuous : readable;
}

// count of continuous memory
void FIFO_Flush( FIFO *fifo, uint32_t count )
{
  fifo->readIndex += count;
}

// Get continuous memory for DMA transfer
// index  : continuous memory offset
// Return : continuous memory size
// After DMA transfer, then call FIFO_Update() : Newer data is valid
uint32_t FIFO_Writable( FIFO *fifo, uint32_t * index )
{
  uint32_t writable = FIFO_WritableSize( fifo );
  uint32_t writeIndex = fifo->writeIndex & ( fifo->capacity - 1 );
  uint32_t continuous = fifo->capacity - writeIndex;
  *index = writeIndex;
  return ( writable > continuous ) ? continuous : writable;
}

// count of continuous memory
void FIFO_Update( FIFO *fifo, uint32_t count )
{
  fifo->writeIndex += count;
}

// return byte count has been written
// Byte Array
uint32_t FIFO_Write( FIFO *fifo, void * data, uint32_t count )
{
  uint32_t writtenCount = MIN( count, FIFO_WritableSize( fifo ) );
  FIFO_DoWrite( fifo, data, writtenCount );
  return writtenCount;
}

// return byte count has been read
// Byte Array
uint32_t FIFO_Read( FIFO *fifo, void * data, uint32_t count )
{
  uint32_t readCount = MIN( count, FIFO_ReadableSize( fifo ) );
  FIFO_DoRead( fifo, data, readCount );
  return readCount;
}

// return element count has been written
// Fixed Length Data
uint32_t FIFO_WriteFixed( FIFO *fifo, void * data, uint32_t elemCount, uint32_t elemSize )
{
  uint32_t writtenCount = MIN( elemCount, FIFO_WritableSize( fifo ) / elemSize );
  uint32_t size = elemSize * writtenCount;
  FIFO_DoWrite( fifo, data, size );
  return elemCount;
}

// return element count has been read
// Fixed Length Data
uint32_t FIFO_ReadFixed( FIFO *fifo, void * data, uint32_t elemCount, uint32_t elemSize )
{
  uint32_t readCount = MIN( elemCount, FIFO_ReadableSize( fifo ) / elemSize );
  uint32_t size = elemSize * readCount;
  FIFO_DoRead( fifo, data, size );
  return elemCount;
}

// return byte count has been written
// DataSize : data
// Variable Length Data
uint32_t FIFO_WriteVariable( FIFO *fifo, void * data, uint32_t size )
{
  if ( FIFO_WritableSize( fifo ) < size + 4 )
    return 0;

  FIFO_DoWrite( fifo, &size, 4 );         // Write Size of data
  FIFO_DoWrite( fifo, data, size );       // Write data
  return size;
}

// return byte count has been read
// DataSize : data
// Variable Length Data
uint32_t FIFO_ReadVariable( FIFO *fifo, void * data )
{
  if ( FIFO_ReadableSize( fifo ) <= 4 )
    return 0;

  uint32_t size;
  FIFO_DoRead( fifo, &size, 4 );          // Read Size of data
  FIFO_DoRead( fifo, data, size );        // Read data
  return size;
}
