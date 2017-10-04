#include "FT232R_Emulator_Eeprom.h"
#include "FT232R_Emulator.h"
#include "EEPROM_Emulator.h"

#define FTDI_EEPROM_CFG0_OFFSET         ( 0x00 )
#define FTDI_EEPROM_CFG1_OFFSET         ( 0x01 )

#define FTDI_EEPROM_VID_OFFSET          ( 0x02 )
#define FTDI_EEPROM_PID_OFFSET          ( 0x04 )
#define FTDI_EEPROM_REV_OFFSET          ( 0x06 )
#define FTDI_EEPROM_CFG_OFFSET          ( 0x08 )
#define FTDI_EEPROM_PWR_OFFSET          ( 0x09 )

#define FTDI_EEPROM_CFGA_OFFSET         ( 0x0A )
#define FTDI_EEPROM_CFGB_OFFSET         ( 0x0B )

#define FTDI_EEPROM_CFGC_OFFSET         ( 0x0C )
#define FTDI_EEPROM_CFGD_OFFSET         ( 0x0D )

// USB Version for BM and 2232C
#define FTDI_EEPROM_VER_OFFSET          ( 0x0C )

#define FTDI_EEPROM_MANF_STR_OFFSET     ( 0x0E )
#define FTDI_EEPROM_MANF_LEN_OFFSET     ( 0x0F )
#define FTDI_EEPROM_PROD_STR_OFFSET     ( 0x10 )
#define FTDI_EEPROM_PROD_LEN_OFFSET     ( 0x11 )
#define FTDI_EEPROM_SNUM_STR_OFFSET     ( 0x12 )
#define FTDI_EEPROM_SNUM_LEN_OFFSET     ( 0x13 )
#define FTDI_EEPROM_CBUS_FUNC_OFFSET    ( 0x14 )

/*
 * 0x000: 00 40 03 04 01 60 00 06  80 2d 08 00 00 02 98 0a .@...`.. .-......
 *                          ----- bcdDevice : DeviceType
 * 0x010: a2 16 b8 0a 23 10 05 00  0a 03 49 00 4b 00 44 00 ....#... ..I.K.D.
 * 0x020: 41 00 16 03 4c 00 4c 00  42 00 42 00 43 00 5f 00 A...L.L. B.B.C._.
 * 0x030: 43 00 4f 00 4e 00 4e 00  0a 03 30 00 30 00 30 00 C.O.N.N. ..0.0.0.
 * 0x040: 32 00 02 03 00 00 00 00  00 00 00 00 00 00 00 00 2....... ........
 * 0x050: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 ........ ........
 * 0x060: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 ........ ........
 * 0x070: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 58 e5 ........ ......X.
 *                                                   ----- CheckSum
 * 0x000: 25 04 da fb 00 00 fd 51  32 80 42 00 00 00 00 00 %......Q 2.B.....
 *                          ------------ ChipID
 * 0x010: 00 00 00 00 00 00 00 00  38 41 4a 53 57 47 44 4a ........ 8AJSWGDJ
 *
 */
UCHAR FT232R_Emulator_GetChipIDShift( UCHAR value )
{
  return ( ( value & 1 ) << 1 ) | ( ( value & 2 ) << 5 ) | ( ( value & 4 ) >> 2 ) | ( ( value & 8 ) << 4 )
    | ( ( value & 16 ) >> 1 ) | ( ( value & 32 ) >> 1 ) | ( ( value & 64 ) >> 4 ) | ( ( value & 128 ) >> 2 );
}

#define FTDI_CHIPID_OFFSET        ( 0x06 )
DWORD FT232R_Emulator_GetChipID( UCHAR * ChipID_Data )
{
  // UCHAR * ChipID_Data = (UCHAR * )&FT232R_Emulator_ChipId[0];
  DWORD Value = *(DWORD *) ( ChipID_Data + FTDI_CHIPID_OFFSET );
  DWORD ChipId = FT232R_Emulator_GetChipIDShift( Value >> 0 ) << 0 | FT232R_Emulator_GetChipIDShift( Value >> 8 ) << 8
    | FT232R_Emulator_GetChipIDShift( Value >> 16 ) << 16 | FT232R_Emulator_GetChipIDShift( Value >> 24 ) << 24;

  ChipId ^= 0xA5F0F7D1;

  return ChipId;
}

static WORD FT232R_EepromCheckSumBuild( DWORD Size )
{
  WORD WordData;
  WORD CheckSum = 0xAAAA;

  for ( DWORD wordAddr = 0; wordAddr < ( ( Size >> 1 ) - 1 ); wordAddr++ )
  {
    EEPROM_ReadWord( wordAddr << 1, &WordData );
    CheckSum ^= WordData;
    CheckSum = ( CheckSum << 1 ) | ( CheckSum >> 15 );
  }

  return CheckSum;
}

FTDI_DeviceType_TypeDef FTDI_GetDeviceType( WORD bcdDevice )
{
  FTDI_DeviceType_TypeDef DeviceType = FTDI_DEVICE_UNKNOWN;

  if ( bcdDevice == 0x0200 )
    DeviceType = FTDI_DEVICE_AM;
  else if ( bcdDevice == 0x0400 )
    DeviceType = FTDI_DEVICE_BM;
  else if ( bcdDevice == 0x0500 )
    DeviceType = FTDI_DEVICE_2232C;
  else if ( bcdDevice == 0x0600 )
    DeviceType = FTDI_DEVICE_232R;
  else if ( bcdDevice == 0x0700 )
    DeviceType = FTDI_DEVICE_2232H;
  else if ( bcdDevice == 0x0800 )
    DeviceType = FTDI_DEVICE_4232H;
  else if ( bcdDevice == 0x0900 )
    DeviceType = FTDI_DEVICE_232H;
  else if ( bcdDevice == 0x1000 )
    DeviceType = FTDI_DEVICE_203X;
  else
    // if ( bcdDevice == 0x0000 )
    DeviceType = FTDI_DEVICE_232R;

  return DeviceType;
}

int32_t FT232R_Emulator_EepromDecode( FT232R_Property_TypeDef * FT232R_Property )
{
  BYTE ByteData;
  WORD WordData;

  // VID, PID and bcdUSB of Device Descriptor
  // Addr 02: Vendor ID
  EEPROM_ReadWord( FTDI_EEPROM_VID_OFFSET, &WordData );
  FT232R_Property->VendorID = WordData;
  // Addr 04: Product ID
  EEPROM_ReadWord( FTDI_EEPROM_PID_OFFSET, &WordData );
  FT232R_Property->ProductID = WordData;
  // bcdDevice of Device Descriptor
  // Addr 06: Device release number
  EEPROM_ReadWord( FTDI_EEPROM_REV_OFFSET, &WordData );
  FT232R_Property->bcdDevice = WordData;

  WORD CheckSum = FT232R_EepromCheckSumBuild( FT232R_EMULATOR_EEPROM_SIZE );
  EEPROM_ReadWord( FT232R_EMULATOR_EEPROM_SIZE - 2, &WordData );

  if ( CheckSum != WordData )
  {
    int32_t RetValue = EEPROM_Format( (uint8_t *) FT232R_Emulator_Eeprom, sizeof( FT232R_Emulator_Eeprom ) );
    if ( RetValue != EEPROM_SUCCESS )
      return RetValue;
  }

  // bmAttributes of Configuration Descriptor
  // Addr 08: Config descriptor
  // Bit 7: always 1
  // Bit 6: 1 if this device is self powered, 0 if bus powered
  // Bit 5: 1 if this device uses remote wakeup
  // bmAttributes = 0x80 | Device->SefPowered | Device->RemoteWakeup
  EEPROM_ReadByte( FTDI_EEPROM_CFG_OFFSET, &ByteData );
  FT232R_Property->SelfPowered = ByteData & 0x40;
  FT232R_Property->RemoteWakeup = ByteData & 0x20;

  // MaxPower of Configuration Descriptor
  // Addr 09: Max power consumption: max power = value * 2 mA
  // Device->MaxPower = 0 if ( Device->SefPowered > 0 )
  EEPROM_ReadByte( FTDI_EEPROM_PWR_OFFSET, &ByteData );
  FT232R_Property->MaxPower = ByteData;

  // Addr 0A: Chip configuration
  // Bit 7: 0 - reserved
  // Bit 6: 0 - reserved
  // Bit 5: 0 - reserved
  // Bit 4: 1 - Change USB version on BM and 2232C
  // Bit 3: 1 - Use the serial number string
  // Bit 2: 1 - Enable suspend pull downs for lower power
  // Bit 1: 1 - Out EndPoint is Isochronous
  // Bit 0: 1 - In EndPoint is Isochronous

  // Addr 0C: USB version low byte --- BM and 2232C : 0x0110
  // Addr 0D: USB version high byte -- BM and 2232C : 0x0200
  EEPROM_ReadByte( FTDI_EEPROM_CFGA_OFFSET, &ByteData );

  // iSerialNumber = 0 if ( Device->SerNumEnable == 0 )
  // iSerialNumber = 3 if ( Device->SerNumEnable > 0 )
  FT232R_Property->SerNumEnable = ByteData & 0x08;
  // Pull IO pins low during suspend
  FT232R_Property->PullDownEnable = ByteData & 0x04;

  FT232R_Property->USBVersion = 0x0200;
  FT232R_Property->USBVersionEnable = ByteData & 0x10;
  if ( FT232R_Property->USBVersionEnable )
  {
    EEPROM_ReadWord( FTDI_EEPROM_VER_OFFSET, &WordData );
    FT232R_Property->USBVersion = WordData;
  }

  // Addr 0E: Offset of the manufacturer string + 0x80, calculated later
  // Addr 0F: Length of manufacturer string
  // Manufacturer String Descriptor : LEN+2 0x03 [ ---- LEN Bytes ---- ]
  EEPROM_ReadByte( FTDI_EEPROM_MANF_LEN_OFFSET, &ByteData );
  FT232R_Property->ManufactureStrSize = ByteData;
  EEPROM_ReadByte( FTDI_EEPROM_MANF_STR_OFFSET, &ByteData );
  FT232R_Property->ManufactureStrAddr = ByteData - 0x80;

  // Addr 10: Offset of the product string + 0x80, calculated later
  // Addr 11: Length of product string
  // Product String Descriptor : LEN+2 0x03 [ ---- LEN Bytes ---- ]
  EEPROM_ReadByte( FTDI_EEPROM_PROD_LEN_OFFSET, &ByteData );
  FT232R_Property->ProductStrSize = ByteData;
  EEPROM_ReadByte( FTDI_EEPROM_PROD_STR_OFFSET, &ByteData );
  FT232R_Property->ProductStrAddr = ByteData - 0x80;

  // Addr 12: Offset of the serial number string + 0x80, calculated later
  // Addr 13: Length of serial number string
  // Serial Number String Descriptor : LEN+2 0x03 [ ---- LEN Bytes ---- ]
  EEPROM_ReadByte( FTDI_EEPROM_SNUM_LEN_OFFSET, &ByteData );
  FT232R_Property->SerialNumberStrSize = ByteData;
  EEPROM_ReadByte( FTDI_EEPROM_SNUM_STR_OFFSET, &ByteData );
  FT232R_Property->SerialNumberStrAddr = ByteData - 0x80;

  EEPROM_ReadByte( FTDI_EEPROM_CFG0_OFFSET, &ByteData );
  FT232R_Property->UseExtOsc = ByteData & FT232R_USES_EXT_OSC;
  FT232R_Property->HighDriveIOs = ByteData & FT232R_HIGH_CURRENT_DRIVE;
  FT232R_Property->IsD2XX = ( ByteData & FT232R_DRIVER_VCP ) ? 1 : 0;

  // wMaxPacketSize of Endpoint Descriptor
  if ( 0 )
  {
    EEPROM_ReadByte( FTDI_EEPROM_CFG1_OFFSET, &ByteData );
    FT232R_Property->EndpointSize = ByteData;    // 0x40
    if ( 0x40 != FT232R_Property->EndpointSize )
      FT232R_Property->EndpointSize = 0x40;
  }

  EEPROM_ReadByte( FTDI_EEPROM_CFGB_OFFSET, &ByteData );
  FT232R_Property->InvertSet = ByteData;

  // FTDI_CBUS_TXDEN, FTDI_CBUS_PWREN...
  uint32_t CBusFuctionOffset = FTDI_EEPROM_CBUS_FUNC_OFFSET;

  for ( DWORD i = 0; i < 3; i++ )
  {
    EEPROM_ReadByte( CBusFuctionOffset + i, &ByteData );
    FT232R_Property->CbusFunctions[ i * 2 + 0 ] = ( ByteData >> 0 ) & FT232R_FUNCTION_MASK0F;
    FT232R_Property->CbusFunctions[ i * 2 + 1 ] = ( ByteData >> 4 ) & FT232R_FUNCTION_MASK0F;
  }

  return EEPROM_SUCCESS;
}
