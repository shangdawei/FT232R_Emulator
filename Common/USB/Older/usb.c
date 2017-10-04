#include "usb.h"

/*
 * Parses the given Configuration descriptor (followed by relevant interface,
 * endpoint and class-specific descriptors) into three arrays.
 * Each array must have its size equal or greater to the number of descriptors
 * it stores plus one. A null-value is inserted after the last descriptor of
 * each type to indicate the array end.
 *
 * Note that if the pointer to an array is null (0), nothing is stored in it.
 *
 * pConfDescriptor    Pointer to the start of the whole Configuration descriptor.
 * bInterfaceNumber   Get from which interface, 0xFF means any interface
 * bAlternateSetting  which Alternate Setting will be used
 * pEpDescriptor      Pointer to the Endpoint descriptor array.
 *
 */
void USB_GetEndpointDescriptorList(
  const USB_CONFIGURATION_DESCRIPTOR * pConfDescriptor,
  uint8_t bInterfaceNumber, uint8_t bAlternateSetting,
  USB_ENDPOINT_DESCRIPTOR** pEpDescriptor )
{
  for ( uint32_t i = 0; i < 32; i++ )
    pEpDescriptor[ i ] = 0;

  uint32_t ConfDescriptorSize = pConfDescriptor->wTotalLength;
  ConfDescriptorSize -= sizeof(USB_CONFIGURATION_DESCRIPTOR);
  USB_INTERFACE_DESCRIPTOR * pIfDescriptor;
  USB_COMMON_DESCRIPTOR * pDescriptor =
    (USB_COMMON_DESCRIPTOR *) pConfDescriptor;

  while ( ConfDescriptorSize > 0 )
  {
    pDescriptor = (USB_COMMON_DESCRIPTOR *) ( (uint8_t*) pDescriptor
      + pDescriptor->bLength );
    ConfDescriptorSize -= pDescriptor->bLength;

    if ( pDescriptor->bDescriptorType == USB_INTERFACE_DESCRIPTOR_TYPE )
      pIfDescriptor = (USB_INTERFACE_DESCRIPTOR*) pDescriptor;
    else if ( pDescriptor->bDescriptorType == USB_ENDPOINT_DESCRIPTOR_TYPE )
    {
      if ( bInterfaceNumber != 0xFF )
        if ( bInterfaceNumber != pIfDescriptor->bInterfaceNumber )
          continue;

      if ( bAlternateSetting != pIfDescriptor->bAlternateSetting )
        continue;

      *pEpDescriptor = (USB_ENDPOINT_DESCRIPTOR*) pDescriptor;
      pEpDescriptor++;
    }
  }

  *pEpDescriptor = 0;
}

USB_COMMON_DESCRIPTOR * USBD_ExtractDescriptorByType(
  USB_COMMON_DESCRIPTOR * pFirstDescriptor,
  USB_COMMON_DESCRIPTOR ** pNextDescriptor, uint32_t DescriptorSize,
  uint8_t DescriptorType )
{
  USB_COMMON_DESCRIPTOR * ret;
  uint8_t * pDummyDescriptor;
  while ( 1 )
  {
    ret = ( *pNextDescriptor );

    pDummyDescriptor = (uint8_t *) ( *pNextDescriptor );
    pDummyDescriptor += ret->bLength;
    ( *pNextDescriptor ) = (USB_COMMON_DESCRIPTOR *) pDummyDescriptor;

    if ( ( (uint32_t) ret )
      >= ( ( (uint32_t) pFirstDescriptor ) + DescriptorSize ) )
      return 0;
    if ( ret->bDescriptorType == DescriptorType )
      break;
  }
  return ret;
}

USB_INTERFACE_DESCRIPTOR * USBD_ParseDescriptor(
  USB_CONFIGURATION_DESCRIPTOR * pConfDescriptor,
  USB_COMMON_DESCRIPTOR ** pCommDescriptor,
  uint32_t TotalLength, uint32_t DescriptorType )
{
  return 0;
}

uint32_t USBD_ExtractInterfaceDescriptor(
  USB_CONFIGURATION_DESCRIPTOR * pConfDescriptor,
  USB_INTERFACE_DESCRIPTOR ** pIfDescriptor, uint32_t ifNumber,
  uint32_t altSetting )
{
  USB_INTERFACE_DESCRIPTOR * pNextIfDescriptor;
  USB_COMMON_DESCRIPTOR * pCommDescriptor =
    (USB_COMMON_DESCRIPTOR *) pConfDescriptor;

  *pIfDescriptor = 0;
  while ( 1 )
  {
    pNextIfDescriptor = (USB_INTERFACE_DESCRIPTOR *) USBD_ParseDescriptor(
      (USB_CONFIGURATION_DESCRIPTOR*) pConfDescriptor, &pCommDescriptor,
      pConfDescriptor->wTotalLength, USB_INTERFACE_DESCRIPTOR_TYPE );

    if ( pNextIfDescriptor == 0 )
      break;

    if ( ( ifNumber != -1 )
      && ( pNextIfDescriptor->bInterfaceNumber != ifNumber ) )
      continue;

    if ( ( altSetting != -1 )
      && ( pNextIfDescriptor->bAlternateSetting != altSetting ) )
      continue;

    if ( *pIfDescriptor != 0 )
      break;

    *pIfDescriptor = pNextIfDescriptor;
    ifNumber = -1;
    altSetting = -1;
  }

  if ( *pIfDescriptor == 0 )
    return 0;

  if ( pNextIfDescriptor == 0 )
    pNextIfDescriptor =
      (USB_INTERFACE_DESCRIPTOR *) ( (uint32_t) pConfDescriptor
        + pConfDescriptor->wTotalLength );

  return ( (uint32_t) pNextIfDescriptor - (uint32_t) ( *pIfDescriptor ) );
}

/*
 * Parses the given Configuration descriptor (followed by relevant interface,
 * endpoint and class-specific descriptors) into three arrays.
 * Each array must have its size equal or greater to the number of descriptors
 * it stores plus one. A null-value is inserted after the last descriptor of
 * each type to indicate the array end.
 *
 * Note that if the pointer to an array is null (0), nothing is stored in it.
 *
 * pConfDescriptor    Pointer to the start of the whole Configuration descriptor.
 * pIfDescriptor      Pointer to the Interface descriptor array.
 * pEpDescriptor      Pointer to the Endpoint descriptor array.
 * pGenericDescriptor Pointer to the class-specific descriptor array
 *
 */
void USB_ParseConfigurationDescriptor(
  USB_CONFIGURATION_DESCRIPTOR * pConfDescriptor,
  USB_INTERFACE_DESCRIPTOR ** pIfDescriptor,
  USB_ENDPOINT_DESCRIPTOR ** pEpDescriptor,
  USB_COMMON_DESCRIPTOR ** pGenericDescriptor )
{
  USB_COMMON_DESCRIPTOR * pDescriptor;
  uint32_t ConfDescriptorSize = pConfDescriptor->wTotalLength;
  ConfDescriptorSize -= sizeof(USB_CONFIGURATION_DESCRIPTOR);
  pDescriptor = (USB_COMMON_DESCRIPTOR *) pConfDescriptor;
  while ( ConfDescriptorSize > 0 )
  {
    pDescriptor = (USB_COMMON_DESCRIPTOR *) ( (uint8_t*) pDescriptor
      + pDescriptor->bLength );
    ConfDescriptorSize -= pDescriptor->bLength;

    if ( pDescriptor->bDescriptorType == USB_INTERFACE_DESCRIPTOR_TYPE )
    {
      if ( pIfDescriptor )
      {
        *pIfDescriptor = (USB_INTERFACE_DESCRIPTOR*) pDescriptor;
        pIfDescriptor++;
      }
    }
    else if ( pDescriptor->bDescriptorType == USB_ENDPOINT_DESCRIPTOR_TYPE )
    {
      if ( pEpDescriptor )
      {
        *pEpDescriptor = (USB_ENDPOINT_DESCRIPTOR*) pDescriptor;
        pEpDescriptor++;
      }
    }
    else if ( pGenericDescriptor )
    {
      *pGenericDescriptor = (USB_COMMON_DESCRIPTOR*) pDescriptor;
      pGenericDescriptor++;
    }
  }

  if ( pIfDescriptor )
    *pIfDescriptor = 0;
  if ( pEpDescriptor )
    *pEpDescriptor = 0;
  if ( pGenericDescriptor )
    *pGenericDescriptor = 0;
}
