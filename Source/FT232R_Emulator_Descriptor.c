#include "FT232R_Emulator_Descriptor.h"
#include "FT232R_Emulator_Conf.h"

uint8_t FT232R_Emulator_DeviceDescriptor[ 18 ] = {
  0x12, /* bLength */
  USB_DEVICE_DESCRIPTOR_TYPE, /* bDescriptorType */
  0x00, 0x02, /* bcdUSB = 2.00 */

  0x00, /* bDeviceClass: This is an Interface Class Defined Device */
  0x00, /* bDeviceSubClass */
  0x00, /* bDeviceProtocol */

  FT232R_EMULATOR_ENDPOINT0_SIZE, /* bMaxPacketSize0 */

  0x03, 0x04, /* idVendor = 0x0403: Future Technology Devices International Limited */
  0x01, 0x60, /* idProduct = 0x6001: */
  0x00, 0x06, /* bcdDevice = 6.00 : FT232R */

  1, /* Index of string descriptor describing manufacturer */
  2, /* Index of string descriptor describing product */
  3, /* Index of string descriptor describing the device's serial number */

  0x01 /* bNumConfigurations */
};

uint8_t FT232R_Emulator_ConfigurationDescriptor[ 32 ] = {
  /*Configuration Descriptor*/
  0x09, /* bLength: Configuration Descriptor size */
  USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */

  32, 0x00, /* wTotalLength:no of returned bytes */

  0x01, /* bNumInterfaces: 1 interface */
  0x01, /* bConfigurationValue: Configuration value */
  0x00, /* iConfiguration: Index of string descriptor describing the configuration */

  0x80, /* bmAttributes: Bus powered */
  0xFA, /* MaxPower 500 mA */

  /*Interface Descriptor*/
  0x09, /* bLength: Interface Descriptor size */
  USB_INTERFACE_DESCRIPTOR_TYPE, /* bDescriptorType: Interface */
  /* Interface descriptor type */
  0x00, /* bInterfaceNumber: Number of Interface */
  0x00, /* bAlternateSetting: Alternate setting */
  0x02, /* bNumEndpoints: 2 endpoints used */

  0xFF, /* bInterfaceClass: Vendor Specific Device Interface Class */
  0xFF, /* bInterfaceSubClass: */
  0xFF, /* bInterfaceProtocol: */

  0x02, /* iInterface: Index of string descriptor describing product */

  /*Endpoint 1 Descriptor*/
  0x07, /* bLength: Endpoint Descriptor size */
  USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType: Endpoint */
  0x81, /* bEndpointAddress: (IN1) */
  0x02, /* bmAttributes: Bulk */
  FT232R_EMULATOR_ENDPOINT_SIZE, FT232R_EMULATOR_ENDPOINT_SIZE >> 8, /* wMaxPacketSize: */
  0x00, /* bInterval */

  /*Endpoint 2 Descriptor*/
  0x07, /* bLength: Endpoint Descriptor size */
  USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType: Endpoint */
  0x02, /* bEndpointAddress: (OUT2) */
  0x02, /* bmAttributes: Bulk */
  FT232R_EMULATOR_ENDPOINT_SIZE, FT232R_EMULATOR_ENDPOINT_SIZE >> 8, /* wMaxPacketSize: */
  0x00, /* bInterval */
};

/* USB String LangID Descriptors */
const uint8_t FT232R_Emulator_StringLangID[ 4 ] = {
  4, 0x03, 0x09, 0x04 /* LangID = 0x0409: U.S. English */
};

/* Manufacturer: "FTDI" */
uint8_t FT232R_Emulator_StringManufacturer[ 128 ] = {
  10, 0x03, 'F', 0, 'T', 0, 'D', 0, 'I', 0 };

/* Product name: "USB <-> Serial Cable" */
uint8_t FT232R_Emulator_StringProduct[ 128 ] = {
  42, 0x03, 'U', 0, 'S', 0, 'B', 0, ' ', 0, '<', 0, '-', 0, '>', 0, ' ', 0, 'S', 0, 'e', 0, 'r', 0, 'i', 0, 'a', 0, 'l',
  0, ' ', 0, 'C', 0, 'a', 0, 'b', 0, 'l', 0, 'e', 0 };

/* Serial Number: "FT12345678" */
uint8_t FT232R_Emulator_StringSerialNumber[ 128 ] = {
  22, 0x03, 'F', 0, 'T', 0, '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0 };

const USBD_Descriptor_TypeDef FT232R_Emulator_Descriptor = {
  (uint8_t *) &FT232R_Emulator_DeviceDescriptor,  //
  (uint8_t *) &FT232R_Emulator_ConfigurationDescriptor,  //
  };

uint8_t * FT232R_Emulator_StringDescriptor( uint8_t index, uint16_t * length )
{
  uint8_t * StringDescriptor = 0;
  if ( index == 0 )
    StringDescriptor = (uint8_t *) &FT232R_Emulator_StringLangID[ 0 ];
  else if ( index == 1 )
    StringDescriptor = (uint8_t *) &FT232R_Emulator_StringManufacturer[ 0 ];
  else if ( index == 2 )
    StringDescriptor = (uint8_t *) &FT232R_Emulator_StringProduct[ 0 ];
  else if ( index == 3 )
    StringDescriptor = (uint8_t *) &FT232R_Emulator_StringSerialNumber[ 0 ];

  if ( StringDescriptor )
    *length = ( (USB_STRING_DESCRIPTOR*) StringDescriptor )->bLength;

  return StringDescriptor;
}
