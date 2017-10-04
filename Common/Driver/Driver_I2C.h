#ifndef __DRIVER_I2C_H__
#define __DRIVER_I2C_H__

#include "Driver_Common.h"

//------------------------------------------------------------------------------
// I2C Control Codes
// Set Own Slave Address; arg = address
#define DRV_I2C_OWN_ADDRESS                ( 0x01 )
// Set Bus Speed; arg = speed
#define DRV_I2C_BUS_SPEED                  ( 0x02 )
// Execute Bus clear: send nine clock pulses
#define DRV_I2C_BUS_CLEAR                  ( 0x03 )
// Abort Master/Slave Transmit/Receive
#define DRV_I2C_ABORT_TRANSFER             ( 0x04 )

//------------------------------------------------------------------------------
// I2C Bus Speed
// Standard Speed ( 100kHz )
#define DRV_I2C_BUS_SPEED_STANDARD         ( 0x01 )
// Fast Speed     ( 400kHz )
#define DRV_I2C_BUS_SPEED_FAST             ( 0x02 )
// Fast+ Speed    (   1MHz )
#define DRV_I2C_BUS_SPEED_FAST_PLUS        ( 0x03 )
// High Speed     ( 3.4MHz )
#define DRV_I2C_BUS_SPEED_HIGH             ( 0x04 )

//------------------------------------------------------------------------------
// I2C Address Flags
// 10-bit address flag
#define DRV_I2C_ADDRESS_10BIT              0x0400
// General Call flag
#define DRV_I2C_ADDRESS_GC                 0x8000

//------------------------------------------------------------------------------
// I2C Event
// Master/Slave Transmit/Receive finished
#define DRV_I2C_EVENT_TRANSFER_DONE        ( 1UL<< 0 )
// Master/Slave Transmit/Receive incomplete transfer
#define DRV_I2C_EVENT_TRANSFER_INCOMPLETE  ( 1UL<< 1 )
// Slave Transmit operation requested
#define DRV_I2C_EVENT_SLAVE_TRANSMIT       ( 1UL<< 2 )
// Slave Receive operation requested
#define DRV_I2C_EVENT_SLAVE_RECEIVE        ( 1UL<< 3 )
// Address not acknowledged from Slave
#define DRV_I2C_EVENT_ADDRESS_NACK         ( 1UL<< 4 )
// General Call indication
#define DRV_I2C_EVENT_GENERAL_CALL         ( 1UL<< 5 )
// Master lost arbitration
#define DRV_I2C_EVENT_ARBITRATION_LOST     ( 1UL<< 6 )
// Bus error detected ( START/STOP at illegal position )
#define DRV_I2C_EVENT_BUS_ERROR            ( 1UL<< 7 )
// Bus clear finished
#define DRV_I2C_EVENT_BUS_CLEAR            ( 1UL<< 8 )

typedef void (*DRV_I2C_EventHandler_TypeDef)( uint32_t event );

typedef struct
{
  // Busy flag
  uint32_t busy :1;
  // Mode: 0=Slave, 1=Master
  uint32_t mode :1;
  // Direction: 0=Transmitter, 1=Receiver
  uint32_t direction :1;
  // General Call indication ( cleared on start of next Slave operation )
  uint32_t general_call :1;
  // Master lost arbitration ( cleared on start of next Master operation )
  uint32_t arbitration_lost :1;
  // Bus error detected ( cleared on start of next Master/Slave operation )
  uint32_t bus_error :1;
} DRV_I2C_Status_TypeDef;

typedef struct
{
  uint32_t address_10_bit :1;             // supports 10-bit addressing
} DRV_I2C_Capabilities_TypeDef;

typedef struct
{
  int32_t (*Initialize)( void * v, DRV_I2C_EventHandler_TypeDef cb_event );
  int32_t (*Uninitialize)( void * v );
  int32_t (*PowerControl)( void * v, uint32_t state );

  int32_t (*MasterTransmit)( void * v, uint32_t addr, uint8_t *data,
    uint32_t num, uint32_t xfer_pending );
  int32_t (*MasterReceive)( void * v, uint32_t addr, uint8_t *data,
    uint32_t num, uint32_t xfer_pending );

  int32_t (*SlaveTransmit)( void * v, uint8_t *data, uint32_t num );
  int32_t (*SlaveReceive)( void * v, uint8_t *data, uint32_t num );

  int32_t (*GetDataCount)( void * v );

  int32_t (*Control)( void * v, uint32_t control, uint32_t arg );
  DRV_I2C_Status_TypeDef (*GetStatus)( void * v );
} I2C_Driver_TypeDef;

#endif /* __DRIVER_I2C_H__ */
