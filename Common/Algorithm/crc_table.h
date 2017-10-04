#ifndef __CRC_TABLE_H__
#define __CRC_TABLE_H__

#include <stdint.h>

extern const uint32_t CRC32_Poly;
extern const uint32_t CRC32R_Poly;

extern const uint8_t CRC8_DS2432_ROM_Table[ ];

extern const uint32_t CRC32_Nibble_Table[ ];
extern const uint32_t CRC32_Byte_Table[ ];

extern const uint32_t CRC32_Nibble_Table_REV[ ];
extern const uint32_t CRC32_Byte_Table_REV[ ];

#endif /* __CRC_TABLE_H__ */
