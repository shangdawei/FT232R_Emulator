#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>
#include "crc_table.h"

/*
 * A cyclic redundancy check (CRC) is an error-detecting code commonly used
 * in digital networks and storage devices to detect accidental changes
 * to raw data. Blocks of data entering these systems get a short check value
 * attached, based on the remainder of a polynomial division of their contents.
 * On retrieval the calculation is repeated, and corrective action can be taken
 * against presumed data corruption if the check values do not match.
 *
 * the 32-bit CRC function of Ethernet and many other standards
 * is the work of several researchers and was published in 1975.
 *
 * Specification of a CRC code requires definition of a so-called
 * generator polynomial. This polynomial becomes the divisor in a polynomial
 * long division, which takes the message as the dividend
 * and in which the quotient is discarded and the remainder becomes the result.
 *
 * In practice, all commonly used CRCs employ the Galois field of two elements,
 * GF(2). The two elements are usually called 0 and 1, comfortably
 * matching computer architecture.
 *
 * A CRC is called an n-bit CRC when its check value is n bits.
 * For a given n, multiple CRCs are possible, each with a different polynomial.
 *
 * Such a polynomial has highest degree n, which means it has n + 1 terms.
 * In other words, the polynomial has a length of n + 1;
 * its encoding requires n + 1 bits.
 *
 * Note that most polynomial specifications either drop the MSB or LSB bit,
 * since they are always 1.
 * The CRC and associated polynomial typically have a name of the form
 * CRC-n-XXXX as in the table below.
 *
 * The simplest error-detection system, the parity bit, is in fact a trivial
 * 1-bit CRC: it uses the generator polynomial x + 1 (two terms),
 * and has the name CRC-1.
 *
 * To compute an n-bit binary CRC, line the bits representing the input in a row,
 * and position the (n + 1)-bit pattern representing the CRC's divisor
 * (called a "polynomial") underneath the left-hand end of the row.
 *
 * In this example, we shall encode 14 bits of message with a 3-bit CRC,
 * with a polynomial x3 + x + 1.
 *
 * The polynomial is written in binary as the coefficients;
 * a 3rd-order polynomial has 4 coefficients (1 x^3 + 0 x^2 + 1 x^1 + 1 x^0).
 * In this case, the coefficients are         1,      0,      1 and   1.
 *
 * The result of the calculation is 3 bits long.
 * Start with the message to be encoded:
 *
 * 11010011101100
 *
 * This is first padded with zeros corresponding to the bit length n of the CRC.
 * Here is the first calculation for computing a 3-bit CRC:
 *
 * 11010011101100 000 <--- input right padded by 3 bits
 * 1011               <--- divisor (4 bits) = x3 + x + 1
 * ------------------
 * 01100011101100 000 <--- result
 *
 * The algorithm acts on the bits directly above the divisor in each step.
 * The result for that iteration is the bitwise XOR of the polynomial divisor
 * with the bits above it.
 * The bits not above the divisor are simply copied directly below for that step.
 * The divisor is then shifted one bit to the right, and the process is repeated
 * until the divisor reaches the right-hand end of the input row.
 * Here is the entire calculation:
 *
 * ****               <--- the first 4 bits are the XOR with the divisor beneath
 * 11010011101100 000 <--- input right padded by 3 bits
 *     ^^^^^^^^^^ ^^^ <--- the rest of the bits are unchanged
 * 1011               <--- divisor
 * 01100011101100 000 <--- result
 *  1011              <--- divisor ...
 * 00111011101100 000
 *   1011
 * 00010111101100 000
 *    1011
 * 00000001101100 000 <--- the divisor moves over to align with the next 1
 *        *           <--- in the dividend (since quotient for that step was 0
 *        1011        <--- in other words, needn't move one bit per iteration
 * 00000000110100 000
 *         1011
 * 00000000011000 000
 *          1011
 * 00000000001110 000
 *           1011
 * 00000000000101 000
 *            101 1
 * -----------------
 * 00000000000000 100 <--- remainder (3 bits).
 *                    <--- Division algorithm stops here as quotient == 0
 *
 * Since the leftmost divisor bit zeroed every input bit it touched,
 * when this process ends the only bits in the input row that can be nonzero
 * are the n bits at the right-hand end of the row.
 * These n bits are the remainder of the division step,
 * and will also be the value of the CRC function.
 *
 * The validity of a received message can easily be verified by performing
 * the above calculation again, this time with the check value added
 * instead of zeroes.
 *
 * The remainder should equal zero if there are no detectable errors.
 *
 * 11010011101100 100 <--- input with check value ***
 * 1011           *** <--- divisor
 * 01100011101100 100 <--- result
 *  1011              <--- divisor ...
 * 00111011101100 100
 * ......
 * 00000000001110 100
 *           1011
 * 00000000000101 100
 *            101 1
 * ------------------
 *                  0 <--- remainder
 *
 * The most commonly used polynomial lengths are:
 *
 *  9 bits (CRC-8)
 * 17 bits (CRC-16)
 * 33 bits (CRC-32)
 * 65 bits (CRC-64)
 *
 * A CRC is called an n-bit CRC when its check value is n-bits.
 * For a given n, multiple CRCs are possible, each with a different polynomial.
 * Such a polynomial has highest degree n, and hence n + 1 terms
 * (the polynomial has a length of n + 1). The remainder has length n.
 *
 * The CRC has a name of the form CRC-n-XXXX.
 *
 * Prefixes a fixed bit:
 *
 * Sometimes an implementation prefixes a fixed bit pattern to the bitstream
 * to be checked. This is useful when clocking errors might insert 0-bits
 * in front of a message, an alteration that would otherwise leave the check
 * value unchanged.   PPPPPPPDDDDDDDDDDDDD
 *
 * Appends n bits:
 *
 * Usually, but not always, an implementation appends n 0-bits
 * (n being the size of the CRC) to the bitstream to be checked
 * before the polynomial division occurs. DDDDDDDDDDDDD00000000
 *
 * This has the convenience that the remainder of the original bitstream
 * with the check value appended is exactly zero, so the CRC can be checked
 * simply by performing the polynomial division on the received bitstream
 * and comparing the remainder with zero.
 *
 * Bit order:
 *
 * Some schemes view the low-order bit of each byte as "first",
 * which then during polynomial division means "leftmost", which is contrary
 * to our customary understanding of "low-order".
 * This convention makes sense when serial-port transmissions are CRC-checked
 * in hardware, because some widespread serial-port transmission conventions
 * transmit bytes least-significant bit first.
 *
 * Byte order:
 *
 * With multi-byte CRCs, there can be confusion over whether
 * the byte transmitted first (or stored in the lowest-addressed byte of memory)
 * is the least-significant byte (LSB) or the most-significant byte (MSB).
 * For example, some 16-bit CRC schemes swap the bytes of the check value.
 *
 * the polynomial x4 + x + 1 may be transcribed as
 *
 * 0x03 = 0b0011 : MSB-first code   :  x^4 + 0x^3 + 0x^2 + 1x^1 + 1x^0
 * 0x0C = 0b1100 : LSB-first code   : 1x^0 + 1x^1 + 0x^2 + 0x^3 +  x^4
 * 0x09 = 0b1001 : Koopman notation : 1x^4 + 0x^3 + 0x^2 + 1x^1 +  x^0
 *
 * In the table below they are shown as:
 * Examples of CRC Representations
 * Name       Normal      Reversed    Reversed reciprocal
 * CRC-4      0x3         0xC         0x9
 *
 *
 *******************************************************************************
 * Author : Ross Williams (ross@guest.adelaide.edu.au.).
 * Date   : 3 June 1993.
 * Status : Public domain.
 * For more information on the Rocksoft^tm Model CRC Algorithm,
 * see the document titled "A Painless Guide to CRC Error Detection Algorithms"
 * by Ross Williams (ross@guest.adelaide.edu.au.)
 * This document is likely to be in
 *
 * ftp://ftp.adelaide.edu.au/pub/rocksoft/crc_v3.txt
 * http://www.zlib.net/crc_v3.txt
 *
 * Note: Rocksoft is a trademark of Rocksoft Pty Ltd, Adelaide, Australia.
 *******************************************************************************
 * CHECKSUM - A number that has been calculated as a function of some
 * message. The literal interpretation of this word "Check-Sum" indicates
 * that the function should involve simply adding up the bytes in the
 * message. Perhaps this was what early checksums were. Today, however,
 * although more sophisticated formulae are used, the term "checksum" is
 * still used.
 *
 * CRC - This stands for "Cyclic Redundancy Code". Whereas the term
 * "checksum" seems to be used to refer to any non-cryptographic checking
 * information unit, the term "CRC" seems to be reserved only for
 * algorithms that are based on the "polynomial" division idea.
 *
 * G - This symbol is used in this document to represent the Poly.
 *
 * MESSAGE - The input data being checksummed. This is usually structured
 * as a sequence of bytes. Whether the top bit or the bottom bit of each
 * byte is treated as the most significant or least significant is a
 * parameter of CRC algorithms.
 *
 * POLY - This is my friendly term for the polynomial of a CRC.
 *
 * POLYNOMIAL - The "polynomial" of a CRC algorithm is simply the divisor
 * in the division implementing the CRC algorithm.
 *
 * REFLECT - A binary number is reflected by swapping all of its bits
 * around the central point. For example, 1101 is the reflection of 1011.
 *
 * ROCKSOFT^TM MODEL CRC ALGORITHM - A parameterized algorithm whose
 * purpose is to act as a solid reference for describing CRC algorithms.
 * Typically CRC algorithms are specified by quoting a polynomial.
 * However, in order to construct a precise implementation, one also
 * needs to know initialization values and so on.
 *
 * WIDTH - The width of a CRC algorithm is the width of its polynomical
 * minus one. For example, if the polynomial is 11010, the width would be
 * 4 bits. The width is usually set to be a multiple of 8 bits.
 *
 * By putting all these pieces together we end up with the parameters of
 * the algorithm:
 *
 * NAME: This is a name given to the algorithm. A string value.
 *
 * WIDTH: This is the width of the algorithm expressed in bits. This
 * is one less than the width of the Poly.
 *
 * POLY: This parameter is the poly. This is a binary value that
 * should be specified as a hexadecimal number. The top bit of the
 * poly should be omitted. For example, if the poly is 10110, you
 * should specify 06. An important aspect of this parameter is that it
 * represents the unreflected poly; the bottom bit of this parameter
 * is always the LSB of the divisor during the division regardless of
 * whether the algorithm being modelled is reflected.
 *
 * INIT: This parameter specifies the initial value of the register
 * when the algorithm starts. This is the value that is to be assigned
 * to the register in the direct table algorithm. In the table
 * algorithm, we may think of the register always commencing with the
 * value zero, and this value being XORed into the register after the
 * N'th bit iteration. This parameter should be specified as a
 * hexadecimal number.
 *
 * REFIN: This is a boolean parameter. If it is FALSE, input bytes are
 * processed with bit 7 being treated as the most significant bit
 * (MSB) and bit 0 being treated as the least significant bit. If this
 * parameter is FALSE, each byte is reflected before being processed.
 *
 * REFOUT: This is a boolean parameter. If it is set to FALSE, the
 * final value in the register is fed into the XOROUT stage directly,
 *    otherwise, if this parameter is TRUE, the final register value is
 *    reflected first.
 *
 * XOROUT: This is an W-bit value that should be specified as a
 * hexadecimal number. It is XORed to the final register value (after
 * the REFOUT) stage before the value is returned as the official
 * checksum.
 *
 * CHECK: This field is not strictly part of the definition, and, in
 * the event of an inconsistency between this field and the other
 * field, the other fields take precedence. This field is a check
 * value that can be used as a weak validator of implementations of
 * the algorithm. The field contains the checksum obtained when the
 * ASCII string "123456789" is fed through the specified algorithm
 * (i.e. 313233... (hexadecimal)).
 *
 * With these parameters defined, the model can now be used to specify a
 * particular CRC algorithm exactly. Here is an example specification for
 * a popular form of the CRC-16 algorithm.
 *
 *    Name   : "CRC-16"
 *    Width  : 16
 *    Poly   : 8005
 *    Rest   : 0000
 *    RevIn  : True
 *    RevOut : True
 *    XorOut : 0000
 *    Check  : BB3D
 *
 *    Name   : "CRC-16/CITT"
 *    Width  : 16
 *    Poly   : 1021
 *    Rest   : FFFF
 *    RevIn  : False
 *    RevOut : False
 *    XorOut : 0000
 *    Check  : ?
 *
 *    Name   : "XMODEM"
 *    Width  : 16
 *    Poly   : 8408
 *    Rest   : 0000
 *    RevIn  : True
 *    RevOut : True
 *    XorOut : 0000
 *    Check  : ?
 *
 *    Name   : "ARC"
 *    Width  : 16
 *    Poly   : 8005
 *    Rest   : 0000
 *    RevIn  : True
 *    RevOut : True
 *    XorOut : 0000
 *    Check  : ?
 *
 * Here is the specification for the CRC32 algo which is reportedly used in
 * PKZip, AUTODIN II, Ethernet, and FDDI.
 *
 *    Name   : "CRC32"
 *    Width  : 32
 *    Poly   : 04C11DB7
 *    Rest   : FFFFFFFF
 *    RevIn  : True
 *    RevOut : True
 *    XorOut : FFFFFFFF
 *    Check  : CBF43926
 *
 *    Name   : "CRC32-STM32"
 *    Width  : 32
 *    Poly   : 04C11DB7
 *    Rest   : FFFFFFFF
 *    RevIn  : False
 *    RevOut : False
 *    XorOut : 00000000
 *    Check  :
 *
 *******************************************************************************
 * How to Use This Package
 *******************************************************************************
 * Step 1: Declare a variable of type CRC_Model_TypeDef.
 *         Declare another variable (CRC_Model say) of type CRC_Model_TypeDef
 *         and initialize it to point to the first variable
 *
 *         (e.g. CRC_Model_TypeDef * CRC_Model = &CRC_Model_Var).
 *
 * Step 2: Assign values to the parameter fields of the structure.
 *         If you don't know what to assign, see the document cited earlier.
 *         For example:
 *
 *            CRC_Model->cm_width = 16;
 *            CRC_Model->cm_poly  = 0x8005L;
 *            CRC_Model->cm_init  = 0L;
 *            CRC_Model->cm_refin = TRUE;
 *            CRC_Model->cm_refot = TRUE;
 *            CRC_Model->cm_xorot = 0L;
 *
 *         Note Poly is specified without its top bit (0x18005 becomes 0x8005)
 *         Note Width is one bit less than the raw poly width.
 *
 * Step 3: Initialize the instance with a call CRC_Init( CRC_Model );
 *
 * Step 4: Process zero or more message bytes by placing zero or more
 *         successive calls to cm_nxt. Example: CRC_Next(CRC_Model,ch);
 *
 * Step 5: Extract the CRC value at any time by calling
 *         crc = CRC_Result( CRC_Model );
 *         If the CRC is a 16-bit value, it will be in the bottom 16 bits.
 *
 *******************************************************************************
 * Design Notes
 *******************************************************************************
 * PORTABILITY: This package has been coded very conservatively so that
 * it will run on as many machines as possible. For example, all external
 * identifiers have been restricted to 6 characters and all internal ones to
 * 8 characters. The prefix cm (for Crc Model) is used as an attempt to avoid
 * namespace collisions. This package is endian independent.
 *
 *******************************************************************************
 * EFFICIENCY:
 *******************************************************************************
 * This package (and its interface) is not designed for speed.
 * The purpose of this package is to act as a well-defined reference
 * model for the specification of CRC algorithms. If you want speed, cook up
 * a specific table-driven implementation as described in the document cited
 * above. This package is designed for validation only; if you have found or
 * implemented a CRC algorithm and wish to describe it as a set of parameters
 * to the Rocksoft^tm Model CRC Algorithm, your CRC algorithm implementation
 * should behave identically to this package under those parameters.
 */

/* CRC Model Abstract Type
 *
 * The following type stores the context of an executing instance of the
 * model algorithm. Most of the fields are model parameters which must be
 * set before the first initializing call to cm_ini.
 */
typedef struct
{
  uint32_t Width;   // Parameter: Width in bits [8..32]
  uint32_t Poly;    // Parameter: The algorithm's poly : LFSR << Shift Left Data
  uint32_t Rem1;    // Parameter: Initial register value.
  uint32_t Pad1;    // Parameter: Append for Hardware CRC module, 0 or 1
  uint32_t RevIn;   // Parameter: Reflect input bytes : Shift Right Data >> LFSR
  uint32_t RevOut;  // Parameter: Reflect output CRC
  uint32_t XorOut;  // Parameter: XOR this to output CRC.
  uint32_t TopBit;  // Context: 0x80, 0x80000000
  uint32_t Reg;     // Context: Context during execution.
} CRC_Model_TypeDef;

/*
 * Initializes the argument CRC model instance.
 * All parameter fields must be set before calling this.
 */
void CRC_Init( CRC_Model_TypeDef * CRC_Model );

// Processes a single message byte [0,255]
void CRC_DoByte( CRC_Model_TypeDef * CRC_Model, uint32_t InByte );

// Processes a block of message bytes.
void CRC_DoBlock( CRC_Model_TypeDef * CRC_Model, uint32_t BlockLength,
  uint8_t * pBlock );

// Returns the CRC value for the message bytes processed so far.
uint32_t CRC_Done( CRC_Model_TypeDef * CRC_Model );

/*
 * Functions For Table Calculation
 *
 * The following function can be used to calculate a CRC lookup table.
 * It can also be used at run-time to create or check static tables.
 * Returns the i'th entry for the lookup table for the specified algorithm.
 * The function examines the fields cm_width, cm_poly, cm_refin, and the
 * argument table index in the range [0,255] and returns the table entry in
 * the bottom cm_width bytes of the return value.
 */
uint32_t CRC_TableGen( CRC_Model_TypeDef * CRC_Model, int32_t index );

// uint32_t table[ 16 ];
// uint32_t table_rev[ 16 ];
void CRC32_NibbleTableGen( uint32_t * table, uint32_t * table_rev );
// uint32_t table[ 256 ]
// uint32_t table_rev[ 256 ];
void CRC32_ByteTableGen( uint32_t * table, uint32_t * table_rev );

uint32_t CRC32R_BitWise( uint32_t crc32, uint32_t length, uint8_t * data );
uint32_t CRC32R_Nibble( uint32_t crc32, uint32_t length, uint8_t * data );
uint32_t CRC32R_Byte( uint32_t crc32, uint32_t length, uint8_t * data,
  uint32_t * table );

uint32_t CRC32_BitWise( uint32_t crc32, uint32_t length, uint8_t * data );
uint32_t CRC32_Nibble( uint32_t crc32, uint32_t length, uint8_t * data );
uint32_t CRC32_Byte( uint32_t crc32, uint32_t length, uint8_t * data,
  uint32_t * table );

uint32_t CRC32_Padded( uint32_t Pad, uint32_t InitValue, uint32_t Length,
  uint8_t * pData, uint32_t * table );
uint32_t CRC32R_Padded( uint32_t Pad, uint32_t InitValue, uint32_t Length,
  uint8_t * pData, uint32_t * table );

uint8_t CRC8_DS2432_ROM( uint32_t Size, uint8_t * pData );

void CRC_Demo( void );

#endif /* __CRC_H__ */
