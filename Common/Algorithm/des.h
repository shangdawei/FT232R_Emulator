#ifndef __DES_H__
#define __DES_H__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "des_table.h"

//------------------------------------------------------------------------------
// Key Mode
#define DES_KEY_ENC         ( 1<<0 )
#define DES_KEY_DEC         ( 1<<1 )
#define DES_KEY_3DES        ( 2<<1 )
#define DES_KEY_BOTH        ( DES_KEY_ENC | DES_KEY_DEC )
//
//------------------------------------------------------------------------------
//
// Crypt Mode
//
// DES_MODE_EBC : DES_MODE_DES  : DES_MODE_ENC
// DES_MODE_CBC : DES_MODE_3DES : DES_MODE_DEC
//
#define DES_MODE_ENC        ( 0<<0 )
#define DES_MODE_DEC        ( 1<<0 )
#define DES_MODE_3DES       ( 1<<1 )
#define DES_MODE_CBC        ( 1<<2 )
//
//
#define DES_ECB_ENC         ( DES_MODE_ENC )
#define DES_ECB_DEC         ( DES_MODE_DEC )

#define DES_CBC_ENC         ( DES_ECB_ENC | DES_MODE_CBC )
#define DES_CBC_DEC         ( DES_ECB_DEC | DES_MODE_CBC )

#define DES3_ECB_ENC        ( DES_ECB_ENC | DES_MODE_3DES )
#define DES3_ECB_DEC        ( DES_ECB_DEC | DES_MODE_3DES )

#define DES3_CBC_ENC        ( DES_CBC_ENC | DES_MODE_3DES )
#define DES3_CBC_DEC        ( DES_CBC_DEC | DES_MODE_3DES )

typedef uint32_t DES_SP_Type[ 64 ];

typedef struct
{
  uint32_t KeyLen;            // 8, 16, 24
  uint8_t * EKeyExpanded;     // uint32_t DES_xKey[ 32 ];
  uint8_t * DKeyExpanded;     // uint32_t DES3_xKey[ 3 ][ 32 ];
  const uint8_t * DES_PC1;    // uint8_t DES_PC1[ 56 ];
  const uint8_t * DES_PC2;    // uint8_t DES_PC2[ 48 ];
  const DES_SP_Type * DES_SP; // uint32_t DES_SP[ 8 ][ 64 ]
} DES_Ctx_Typedef;

void DES_Init( DES_Ctx_Typedef * DES_Ctx, const uint8_t * DES_PC1,
  const uint8_t * DES_PC2, const DES_SP_Type * DES_SP, uint8_t * EKeyExpanded,
  uint8_t * DKeyExpanded );

void DES_SetKey( DES_Ctx_Typedef * DES_Ctx, uint32_t Mode, uint8_t * KeyStr );

void DES_Crypt( DES_Ctx_Typedef * DES_Ctx, uint32_t Mode, uint32_t Size,
  uint8_t * pIv, uint8_t * pIvOut, uint8_t * pData, uint8_t * pDataOut );

uint32_t DES_Demo( void );

/*
 Module                      ro code    ro data     rw data   DES_Demo Time
 -------------------------------------------------------------------------------
 des.o                       2 496      12          264       5 000 ms
 des_table.o                            2 280       DES_USES_IP_FP_TABLE == 0
 des_vector.o                200        48 125      46 320
 -------------------------------------------------------------------------------
 des.o                       2 708      12          264       7 000 ms
 des_table.o                            35 048      DES_USES_IP_FP_TABLE == 1
 des_vector.o                200        39 745      46 320
 -------------------------------------------------------------------------------
 des1.o                      2 216      12          6 152     130 000 ms
 des_table.o                            840         DES_USES_SBOX_TABLE == 1
 des_vector.o                200        48 125      46 320
 */

#endif /* __DES_H__ */
