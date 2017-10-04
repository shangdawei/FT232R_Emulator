#include "rc4.h"

/*
 * Initialize an RC4 state buffer using the supplied key,
 * which can have arbitrary length.
 */
void RC4_KeyInit( RC4_CTX_TypeDef * RC4_Ctx, uint8_t * key_str_256_bytes )
{
  uint32_t i;
  uint8_t j, k;
  
  *( (uint32_t *) ( &RC4_Ctx->index0 ) ) = 0;
  //RC4_Ctx->index0 = 0;
  //RC4_Ctx->index1 = 0;
  
  for ( i = 0; i < 256; i++ )
    RC4_Ctx->perm[ i ] = i;
  
  for ( j = i = 0; i < 256; i++ )
  {
    j += ( key_str_256_bytes[ i ] + RC4_Ctx->perm[ i ] );
    k = RC4_Ctx->perm[ i ];
    RC4_Ctx->perm[ i ] = RC4_Ctx->perm[ j ];
    RC4_Ctx->perm[ j ] = k;
  }
}

#pragma optimize=speed
#if ( __ARM_PROFILE_M__ == 0 )
__arm
#endif
uint8_t RC4_KeyGet( RC4_CTX_TypeDef * RC4_Ctx )
{
  /* Update modification indicies */
  // index0 : byte count of crypted
  RC4_Ctx->index1 += RC4_Ctx->perm[ ++RC4_Ctx->index0 ];
  
  /* Modify permutation */
  uint8_t k = RC4_Ctx->perm[ RC4_Ctx->index0 ];
  RC4_Ctx->perm[ RC4_Ctx->index0 ] = RC4_Ctx->perm[ RC4_Ctx->index1 ];
  RC4_Ctx->perm[ RC4_Ctx->index1 ] = k;
  
  /* Key to encrypt/Decrypt next byte */
  k = ( RC4_Ctx->perm[ RC4_Ctx->index0 ] + RC4_Ctx->perm[ RC4_Ctx->index1 ] );
  return RC4_Ctx->perm[ k ];
}

/*
 * Since RC4 is a stream cypher, this function is used
 * for both encryption and decryption.
 */
#pragma optimize=speed
#if ( __ARM_PROFILE_M__ == 0 )
__arm
#endif
void RC4_Crypt( RC4_CTX_TypeDef * RC4_Ctx, uint32_t len, uint8_t *buf )
{
  while ( len-- )
    *buf++ ^= RC4_KeyGet( RC4_Ctx );
}

void RC4_Init( RC4_CTX_TypeDef * RC4_Ctx, uint8_t * key_str_256_bytes )
{
  RC4_KeyInit( RC4_Ctx, key_str_256_bytes );
}

void RC4_Demo( void )
{
  // 256 + 4 bytes
  RC4_CTX_TypeDef RC4_Ctx;
  
  uint8_t key_str_256_bytes[ 256 ];
  for ( uint32_t i = 0; i < 256; i++ )
    key_str_256_bytes[ i ] = i;
  
  RC4_Init( &RC4_Ctx, key_str_256_bytes );
  RC4_Crypt( &RC4_Ctx, 256, key_str_256_bytes );
}

