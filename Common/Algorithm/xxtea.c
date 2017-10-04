#include "xxtea.h"

void TEA_Encrypt( uint32_t* v, uint32_t* k )
{
  uint32_t v0 = v[ 0 ], v1 = v[ 1 ], sum = 0, i; /* set up */
  uint32_t delta = 0x9e3779b9; /* a key schedule constant */
  uint32_t k0 = k[ 0 ], k1 = k[ 1 ], k2 = k[ 2 ], k3 = k[ 3 ]; /* cache key */
  
  for ( i = 0; i < 32; i++ )
  { /* basic cycle start */
    sum += delta;
    v0 += ( ( v1 << 4 ) + k0 ) ^ ( v1 + sum ) ^ ( ( v1 >> 5 ) + k1 );
    v1 += ( ( v0 << 4 ) + k2 ) ^ ( v0 + sum ) ^ ( ( v0 >> 5 ) + k3 );
  } /* end cycle */
  
  v[ 0 ] = v0;
  v[ 1 ] = v1;
}

void TEA_Decrypt( uint32_t* v, uint32_t* k )
{
  uint32_t v0 = v[ 0 ], v1 = v[ 1 ], sum = 0xC6EF3720, i; /* set up */
  uint32_t delta = 0x9e3779b9; /* a key schedule constant */
  uint32_t k0 = k[ 0 ], k1 = k[ 1 ], k2 = k[ 2 ], k3 = k[ 3 ]; /* cache key */
  
  for ( i = 0; i < 32; i++ )
  { /* basic cycle start */
    v1 -= ( ( v0 << 4 ) + k2 ) ^ ( v0 + sum ) ^ ( ( v0 >> 5 ) + k3 );
    v0 -= ( ( v1 << 4 ) + k0 ) ^ ( v1 + sum ) ^ ( ( v1 >> 5 ) + k1 );
    sum -= delta;
  } /* end cycle */
  
  v[ 0 ] = v0;
  v[ 1 ] = v1;
}

#define MX ( (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z) )

void XXTEA_Encrypt( int32_t * v, int32_t n, int32_t * k )
{
  uint32_t z = v[ n - 1 ], y = v[ 0 ], sum = 0, e, DELTA = 0x9e3779b9;
  int32_t p, q;
  q = 6 + 52 / n;
  while ( q-- > 0 )
  {
    sum += DELTA;
    e = sum >> 2 & 3;
    for ( p = 0; p < n - 1; p++ )
    {
      y = v[ p + 1 ];
      z = v[ p ];
      v[ p ] += ( MX );
      y = v[ 0 ];
    }
    z = v[ n - 1 ];
    v[ n - 1 ] += ( MX );
  }
}

void XXTEA_Decrypt( int32_t * v, int32_t n, int32_t * k )
{
  uint32_t z = v[ n - 1 ], y = v[ 0 ], sum = 0, e, DELTA = 0x9e3779b9;
  int32_t p, q;
  q = 6 + 52 / n;
  sum = q * DELTA;
  while ( sum != 0 )
  {
    e = sum >> 2 & 3;
    for ( p = n - 1; p > 0; p-- )
      z = v[ p - 1 ];
    y = v[ p ];
    v[ p ] -= ( MX );
    z = v[ n - 1 ];
    y = v[ 0 ];
    v[ 0 ] -= ( MX );
    sum -= DELTA;
  }
}
