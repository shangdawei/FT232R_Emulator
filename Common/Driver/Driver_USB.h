#ifndef __DRIVER_USB_H__
#define __DRIVER_USB_H__

#include "Driver_Common.h"

/* USB Role */
#define USB_ROLE_NONE                0
#define USB_ROLE_HOST                1
#define USB_ROLE_DEVICE              2

/* USB Pins */
#define USB_PIN_DP                  (1 << 0) // USB D+ pin
#define USB_PIN_DM                  (1 << 1) // USB D- pin
#define USB_PIN_VBUS                (1 << 2) // USB VBUS pin
#define USB_PIN_OC                  (1 << 3) // USB OverCurrent pin
#define USB_PIN_ID                  (1 << 4) // USB ID pin

/* USB Speed */
#define USB_SPEED_LOW                0       // Low-speed USB
#define USB_SPEED_FULL               1       // Full-speed USB
#define USB_SPEED_HIGH               2       // High-speed USB

/* USB PID Types */
#define USB_PID_OUT                  1
#define USB_PID_IN                   9
#define USB_PID_SOF                  5
#define USB_PID_SETUP                13
#define USB_PID_DATA0                3
#define USB_PID_DATA1                11
#define USB_PID_DATA2                7
#define USB_PID_MDATA                15
#define USB_PID_ACK                  2
#define USB_PID_NAK                  10
#define USB_PID_STALL                14
#define USB_PID_NYET                 6
#define USB_PID_PRE                  12
#define USB_PID_ERR                  12
#define USB_PID_SPLIT                8
#define USB_PID_PING                 4
#define USB_PID_RESERVED             0

/* USB Endpoint Address (bEndpointAddress) */
#define USB_ENDPOINT_NUMBER_MASK     0x0F
#define USB_ENDPOINT_DIRECTION_MASK  0x80

/* USB Endpoint Type */
#define USB_ENDPOINT_CONTROL         0       // Control Endpoint
#define USB_ENDPOINT_ISOCHRONOUS     1       // Isochronous Endpoint
#define USB_ENDPOINT_BULK            2       // Bulk Endpoint
#define USB_ENDPOINT_INTERRUPT       3       // Interrupt Endpoint

/* USB Endpoint Maximum Xfer Size (wMaxPacketSize) */
#define USB_ENDPOINT_MAX_PACKET_SIZE_MASK           0x07FF
#define USB_ENDPOINT_MICROFRAME_TRANSACTIONS_MASK   0x1800
#define USB_ENDPOINT_MICROFRAME_TRANSACTIONS_1      0x0000
#define USB_ENDPOINT_MICROFRAME_TRANSACTIONS_2      0x0800
#define USB_ENDPOINT_MICROFRAME_TRANSACTIONS_3      0x1000

#endif /* __DRIVER_USB_H__ */
