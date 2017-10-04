//------------------------------------------------------------------------------
// Little Endian, else Big Endian
#if ( __LITTLE_ENDIAN__ > 0 )
#endif

//------------------------------------------------------------------------------
// Cortex, else Arm
#if ( __ARM_PROFILE_M__ > 0 )
#endif

        NAME aes_asm
        PUBLIC AES_ROUND_CRYPT

        SECTION .text:CODE:NOROOT(2)
#if ( __ARM_PROFILE_M__ > 0 )
        THUMB
#else
        CODE32
#endif

//void AES_ROUND_CRYPT(void * tab, unsigned int * bo, unsigned int * bi, unsigned int * k, int encrypt, int next);
//                            R0                  R1                 R2                R3      SP[0]        SP[4]
// encrypt : bi_index : 0 1 2 3 : 1 2 3 4 : 2 3 4 5 : 3 4 5 6
// decrypt : bi_index : 0 3 2 1 : 1 4 3 2 : 2 5 4 3 : 3 6 5 4
//
AES_ROUND_CRYPT:
        PUSH     {R4-R9,LR}     // SP -= 28 = 4 * 7

        LDR      R7,[SP, #+28]  // encrypt : SP[0]
        LDR      R4,[SP, #+32]  // next    : SP[4]

        RSB      R9,R7,#+2      // R9 = i + ( 2 - encrypt )
        ADDS     R7,R7,#+2      // R7 = i + ( 2 + encrypt )

        MOV.W    R12,R2         // bi
        MOVS     R5,#+0         // i

AES_ROUND_CRYPT_LOOP

        LDR      LR,[R12], #+4  // bi += 4 : bi[i]
#if ( __ARM_PROFILE_M__ > 0 )
        UXTB     LR,LR          // bi[i]
#else
        AND      LR,LR,#0xFF    // bi[i]
#endif

        CMP      R4,#+0
#if ( __ARM_PROFILE_M__ > 0 )
        ITE      NE
#endif
        LDRNE    LR,[R0, LR, LSL #+2] // DWORD
        LDRBEQ   LR,[R0, LR]          // BYTE

        AND      R6,R9,#0x3           // (i + (2-encrypt) & 3
        LDR      R6,[R2, R6, LSL #+2] //
        LSLS     R6,R6,#+16           //
        LSRS     R6,R6,#+24           // bi[i]

        CMP      R4,#+0
#if ( __ARM_PROFILE_M__ > 0 )
        ITE      NE
#endif
        LDRNE    R6,[R0, R6, LSL #+2] // DWORD
        LDRBEQ   R6,[R0, R6]          // BYTE

        EOR      LR,LR,R6, ROR #+24

        ADD      R8,R5,#+2
        AND      R6,R8,#0x3
        LDR      R6,[R2, R6, LSL #+2]
        LSLS     R6,R6,#+8
        LSRS     R6,R6,#+24

        CMP      R4,#+0
#if ( __ARM_PROFILE_M__ > 0 )
        ITE      NE
#endif
        LDRNE    R6,[R0, R6, LSL #+2] // DWORD
        LDRBEQ   R6,[R0, R6]          // BYTE

        EOR      LR,LR,R6, ROR #+16

        AND      R6,R7,#0x3           // (i + (2+encrypt) & 3
        LDR      R6,[R2, R6, LSL #+2]
        LSRS     R6,R6,#+24           // (unsigned char)(x)

        CMP      R4,#+0
#if ( __ARM_PROFILE_M__ > 0 )
        ITE      NE
#endif
        LDRNE    R6,[R0, R6, LSL #+2] // DWORD
        LDRBEQ   R6,[R0, R6]          // BYTE

        EOR      LR,LR,R6, ROR #+8

        LDR      R8,[R3], #+4         // * (k + i)
        EOR      LR,LR,R8
        STR      LR,[R1], #+4         // bo += 4

        ADD      R7,R7,#+1            // R7 = i + ( 2 + encrypt )
        ADD      R9,R9,#+1            // R9 = i + ( 2 - encrypt )
        ADD      R5,R5,#+1            // i++
        CMP      R5,#+4               // i<4
#if ( __ARM_PROFILE_M__ > 0 )
        BCC.N    AES_ROUND_CRYPT_LOOP // no
#else
        BCC      AES_ROUND_CRYPT_LOOP // no
#endif

        POP      {R4-R9,PC}

        END
