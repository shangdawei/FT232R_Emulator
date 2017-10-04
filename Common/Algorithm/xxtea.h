#ifndef __XXTEA_H__
#define __XXTEA_H__

#include <stdint.h>

void TEA_Encrypt( uint32_t* v, uint32_t* k );
void TEA_Decrypt( uint32_t* v, uint32_t* k );

void XXTEA_Decrypt( int32_t * v, int32_t n, int32_t * k );
void XXTEA_Encrypt( int32_t * v, int32_t n, int32_t * k );

#endif /* __XXTEA_H__ */
