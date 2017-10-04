#ifndef __RC4_H__
#define __RC4_H__

#include <stdint.h>

typedef struct _RC4_ctx
{
  uint8_t perm[ 256 ];
  uint8_t index0;
  uint8_t index1;
  uint16_t dummy0;
} RC4_CTX_TypeDef;

void RC4_KeyInit( RC4_CTX_TypeDef * RC4_ctx, uint8_t * key_str_256_bytes );

uint8_t RC4_KeyGet( RC4_CTX_TypeDef * RC4_ctx );

void RC4_Crypt( RC4_CTX_TypeDef * RC4_ctx, uint32_t len, uint8_t *buf );

void RC4_Init( RC4_CTX_TypeDef * RC4_Ctx, uint8_t * key_str_256_bytes );

void RC4_Demo( void );

#endif /* __RC4_H__ */
