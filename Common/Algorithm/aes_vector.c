#include "aes_vector.h"
#include "utility.h"
#include "aes.h"

void AES_TestVectorValue( const AES_TestVector_TypeDef * AES_TestVector,
  AES_TestVectorValue_TypeDef * AES_TestVectorValue )
{
  AES_TestVectorValue->KeySize = AES_TestVector->KeySize;
  
  AES_TestVectorValue->IV[ 16 ] = 0x00;
  if ( AES_TestVector->strIV )
  {
    AES_TestVectorValue->IV[ 16 ] = 0x01;
    Hex2Bin( AES_TestVector->strIV, AES_TestVectorValue->IV );
  }
  
  Hex2Bin( AES_TestVector->strKey, AES_TestVectorValue->Key );
  Hex2Bin( AES_TestVector->strPlain, AES_TestVectorValue->Plain );
  Hex2Bin( AES_TestVector->strCipher, AES_TestVectorValue->Cipher );
}

const AES_TestVector_TypeDef AES_TestVectorArray[ ] =
{
{ AES_KEY_128, 0, "2b7e151628aed2a6abf7158809cf4f3c",
  "6bc1bee22e409f96e93d7e117393172a", "3ad77bb40d7a3660a89ecaf32466ef97" },
{ AES_KEY_128, 0, "2b7e151628aed2a6abf7158809cf4f3c",
  "ae2d8a571e03ac9c9eb76fac45af8e51", "f5d3d58503b9699de785895a96fdbaaf" },
{ AES_KEY_128, 0, "2b7e151628aed2a6abf7158809cf4f3c",
  "30c81c46a35ce411e5fbc1191a0a52ef", "43b1cd7f598ece23881b00e3ed030688" },
{ AES_KEY_128, 0, "2b7e151628aed2a6abf7158809cf4f3c",
  "f69f2445df4f9b17ad2b417be66c3710", "7b0c785e27e8ad3f8223207104725dd4" },

{ AES_KEY_192, 0, "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "6bc1bee22e409f96e93d7e117393172a", "bd334f1d6e45f25ff712a214571fa5cc" },
{ AES_KEY_192, 0, "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "ae2d8a571e03ac9c9eb76fac45af8e51", "974104846d0ad3ad7734ecb3ecee4eef" },
{ AES_KEY_192, 0, "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "30c81c46a35ce411e5fbc1191a0a52ef", "ef7afd2270e2e60adce0ba2face6444e" },
{ AES_KEY_192, 0, "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "f69f2445df4f9b17ad2b417be66c3710", "9a4b41ba738d6c72fb16691603c18e0e" },

{ AES_KEY_256, 0,
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "6bc1bee22e409f96e93d7e117393172a", "f3eed1bdb5d2a03c064b5a7e3db181f8" },
{ AES_KEY_256, 0,
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "ae2d8a571e03ac9c9eb76fac45af8e51", "591ccb10d410ed26dc5ba74a31362870" },
{ AES_KEY_256, 0,
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "30c81c46a35ce411e5fbc1191a0a52ef", "b6ed21b99ca6f4f9f153e7b1beafed1d" },
{ AES_KEY_256, 0,
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "f69f2445df4f9b17ad2b417be66c3710", "23304b7a39f9f3ff067d8d8f9e24ecc7" },

{ AES_KEY_128, "000102030405060708090A0B0C0D0E0F",
  "2b7e151628aed2a6abf7158809cf4f3c", "6bc1bee22e409f96e93d7e117393172a",
  "7649abac8119b246cee98e9b12e9197d" },
{ AES_KEY_128, "7649ABAC8119B246CEE98E9B12E9197D",
  "2b7e151628aed2a6abf7158809cf4f3c", "ae2d8a571e03ac9c9eb76fac45af8e51",
  "5086cb9b507219ee95db113a917678b2" },
{ AES_KEY_128, "5086CB9B507219EE95DB113A917678B2",
  "2b7e151628aed2a6abf7158809cf4f3c", "30c81c46a35ce411e5fbc1191a0a52ef",
  "73bed6b8e3c1743b7116e69e22229516" },
{ AES_KEY_128, "73BED6B8E3C1743B7116E69E22229516",
  "2b7e151628aed2a6abf7158809cf4f3c", "f69f2445df4f9b17ad2b417be66c3710",
  "3ff1caa1681fac09120eca307586e1a7" },

{ AES_KEY_192, "000102030405060708090A0B0C0D0E0F",
  "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "6bc1bee22e409f96e93d7e117393172a", "4f021db243bc633d7178183a9fa071e8" },
{ AES_KEY_192, "4F021DB243BC633D7178183A9FA071E8",
  "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "ae2d8a571e03ac9c9eb76fac45af8e51", "b4d9ada9ad7dedf4e5e738763f69145a" },
{ AES_KEY_192, "B4D9ADA9AD7DEDF4E5E738763F69145A",
  "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "30c81c46a35ce411e5fbc1191a0a52ef", "571b242012fb7ae07fa9baac3df102e0" },
{ AES_KEY_192, "571B242012FB7AE07FA9BAAC3DF102E0",
  "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b",
  "f69f2445df4f9b17ad2b417be66c3710", "08b0e27988598881d920a9e64f5615cd" },

{ AES_KEY_256, "000102030405060708090A0B0C0D0E0F",
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "6bc1bee22e409f96e93d7e117393172a", "f58c4c04d6e5f1ba779eabfb5f7bfbd6" },
{ AES_KEY_256, "F58C4C04D6E5F1BA779EABFB5F7BFBD6",
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "ae2d8a571e03ac9c9eb76fac45af8e51", "9cfc4e967edb808d679f777bc6702c7d" },
{ AES_KEY_256, "9CFC4E967EDB808D679F777BC6702C7D",
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "30c81c46a35ce411e5fbc1191a0a52ef", "39f23369a9d9bacfa530e26304231461" },
{ AES_KEY_256, "39F23369A9D9BACFA530E26304231461",
  "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4",
  "f69f2445df4f9b17ad2b417be66c3710", "b2eb05e2c39be9fcda6c19078c6a9d1b" } };

__no_init AES_TestVectorValue_TypeDef AES_TestVectorValueArray[ sizeof( AES_TestVectorArray )
  / sizeof(AES_TestVector_TypeDef) ];

uint32_t AES_TestVectorValues( void )
{
  uint32_t i = 0;
  for ( ; i < sizeof( AES_TestVectorArray ) / sizeof(AES_TestVector_TypeDef);
      i++ )
    AES_TestVectorValue( &AES_TestVectorArray[ i ],
      &AES_TestVectorValueArray[ i ] );
  
  return i;
}
