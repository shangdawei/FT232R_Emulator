#ifndef __AES_TABLE_H__
#define __AES_TABLE_H__

#include <stdint.h>

extern const uint32_t AES_DECRYPT_TAB[ 256 ];
extern const uint32_t AES_ENCRYPT_TAB[ 256 ];
extern const uint8_t AES_RCON[ 10 ];
extern const uint8_t AES_RSBOX[ 256 ];
extern const uint8_t AES_SBOX[ 256 ];

#endif /* __AES_TABLE_H__ */
