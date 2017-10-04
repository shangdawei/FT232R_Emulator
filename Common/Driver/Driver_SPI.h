#ifndef __DRIVER_SPI_H__
#define __DRIVER_SPI_H__

#include "Driver_Common.h"

//------------------------------------------------------------------------------
// SPI Control Codes
#define DRV_SPI_CONTROL_POS              0
#define DRV_SPI_CONTROL_MSK             (0xFFUL << DRV_SPI_CONTROL_POS)

//------------------------------------------------------------------------------
// SPI Control Codes: Mode
// SPI Inactive
#define DRV_SPI_MODE_INACTIVE           (0x00UL << DRV_SPI_CONTROL_POS)
// SPI Master (Output on MOSI, Input on MISO); arg = Bus Speed in bps
#define DRV_SPI_MODE_MASTER             (0x01UL << DRV_SPI_CONTROL_POS)
// SPI Slave  (Output on MISO, Input on MOSI)
#define DRV_SPI_MODE_SLAVE              (0x02UL << DRV_SPI_CONTROL_POS)
// SPI Master (Output/Input on MOSI); arg = Bus Speed in bps
#define DRV_SPI_MODE_MASTER_SIMPLEX     (0x03UL << DRV_SPI_CONTROL_POS)
// SPI Slave  (Output/Input on MISO)
#define DRV_SPI_MODE_SLAVE_SIMPLEX      (0x04UL << DRV_SPI_CONTROL_POS)

//------------------------------------------------------------------------------
// SPI Control Codes: Miscellaneous Controls
// Set Bus Speed in bps; arg = value
#define DRV_SPI_SET_BUS_SPEED           (0x10UL << DRV_SPI_CONTROL_POS)
// Get Bus Speed in bps
#define DRV_SPI_GET_BUS_SPEED           (0x11UL << DRV_SPI_CONTROL_POS)
// Set default Transmit value; arg = value
#define DRV_SPI_SET_DEFAULT_TX_VALUE    (0x12UL << DRV_SPI_CONTROL_POS)
// Control Slave Select; arg: 0=inactive, 1=active
#define DRV_SPI_CONTROL_SS              (0x13UL << DRV_SPI_CONTROL_POS)
// Abort current data transfer
#define DRV_SPI_ABORT_TRANSFER          (0x14UL << DRV_SPI_CONTROL_POS)

//------------------------------------------------------------------------------
// SPI Control Codes: Mode Parameters: Frame Format [ 10..8 ]
#define DRV_SPI_FRAME_FORMAT_POS         8
#define DRV_SPI_FRAME_FORMAT_MSK        (7UL << DRV_SPI_FRAME_FORMAT_POS)
//
// Clock Polarity 0, Clock Phase 0 (default)
#define DRV_SPI_CPOL0_CPHA0             (0UL << DRV_SPI_FRAME_FORMAT_POS)
// Clock Polarity 0, Clock Phase 1
#define DRV_SPI_CPOL0_CPHA1             (1UL << DRV_SPI_FRAME_FORMAT_POS)
// Clock Polarity 1, Clock Phase 0
#define DRV_SPI_CPOL1_CPHA0             (2UL << DRV_SPI_FRAME_FORMAT_POS)
// Clock Polarity 1, Clock Phase 1
#define DRV_SPI_CPOL1_CPHA1             (3UL << DRV_SPI_FRAME_FORMAT_POS)
// Texas Instruments Frame Format
#define DRV_SPI_TI_SSI                  (4UL << DRV_SPI_FRAME_FORMAT_POS)
// National Microwire Frame Format
#define DRV_SPI_MICROWIRE               (5UL << DRV_SPI_FRAME_FORMAT_POS)

//------------------------------------------------------------------------------
// SPI Control Codes: Mode Parameters: Data Bits [ 17..12 ]
#define DRV_SPI_DATA_BITS_POS            12
#define DRV_SPI_DATA_BITS_MSK           (0x3FUL << DRV_SPI_DATA_BITS_POS)
//
// Number of Data bits
#define DRV_SPI_DATA_BITS(n)            (((n) & 0x3F) << DRV_SPI_DATA_BITS_POS)

//------------------------------------------------------------------------------
// SPI Control Codes: Mode Parameters: Bit Order [ 18 ]
#define DRV_SPI_BIT_ORDER_POS            18
#define DRV_SPI_BIT_ORDER_MSK           (1UL << DRV_SPI_BIT_ORDER_POS)
//
// SPI Bit order from MSB to LSB (default)
#define DRV_SPI_MSB_LSB                 (0UL << DRV_SPI_BIT_ORDER_POS)
// SPI Bit order from LSB to MSB
#define DRV_SPI_LSB_MSB                 (1UL << DRV_SPI_BIT_ORDER_POS)

//------------------------------------------------------------------------------
// SPI Control Codes: Mode Parameters: Slave Select Mode [ 20:19 ]
//
#define DRV_SPI_SS_MASTER_MODE_POS       19
#define DRV_SPI_SS_MASTER_MODE_MSK      (3UL << DRV_SPI_SS_MASTER_MODE_POS)
//
// SPI Slave Select when Master: Not used (default)
#define DRV_SPI_SS_MASTER_UNUSED        (0UL << DRV_SPI_SS_MASTER_MODE_POS)
// SPI Slave Select when Master: Software controlled
#define DRV_SPI_SS_MASTER_SW            (1UL << DRV_SPI_SS_MASTER_MODE_POS)
// SPI Slave Select when Master: Hardware controlled Output
#define DRV_SPI_SS_MASTER_DRV_OUTPUT     (2UL << DRV_SPI_SS_MASTER_MODE_POS)
// SPI Slave Select when Master: Hardware monitored Input
#define DRV_SPI_SS_MASTER_DRV_INPUT      (3UL << DRV_SPI_SS_MASTER_MODE_POS)

//------------------------------------------------------------------------------
// SPI Slave Select when Slave: [ 21 ]
//
#define DRV_SPI_SS_SLAVE_MODE_POS        21
#define DRV_SPI_SS_SLAVE_MODE_MSK       (1UL << DRV_SPI_SS_SLAVE_MODE_POS)
//
// SPI Slave Select when Slave: Hardware monitored (default)
#define DRV_SPI_SS_SLAVE_HW             (0UL << DRV_SPI_SS_SLAVE_MODE_POS)
// SPI Slave Select when Slave: Software controlled
#define DRV_SPI_SS_SLAVE_SW             (1UL << DRV_SPI_SS_SLAVE_MODE_POS)

//------------------------------------------------------------------------------
// SPI Slave Select Signal definitions
#define DRV_SPI_SS_INACTIVE              0  // SPI Slave Select Signal Inactive
#define DRV_SPI_SS_ACTIVE                1  // SPI Slave Select Signal Active

//------------------------------------------------------------------------------
// SPI specific error codes
#define DRV_SPI_ERROR_MODE              (DRIVER_ERROR_SPECIFIC - 1)
#define DRV_SPI_ERROR_FRAME_FORMAT      (DRIVER_ERROR_SPECIFIC - 2)
#define DRV_SPI_ERROR_DATA_BITS         (DRIVER_ERROR_SPECIFIC - 3)
#define DRV_SPI_ERROR_BIT_ORDER         (DRIVER_ERROR_SPECIFIC - 4)
#define DRV_SPI_ERROR_SS_MODE           (DRIVER_ERROR_SPECIFIC - 5)

//------------------------------------------------------------------------------
// SPI Event
// Data Transfer completed
#define DRV_SPI_EVENT_TRANSFER_COMPLETE (1UL << 0)
// Data lost: Receive overflow / Transmit underflow
#define DRV_SPI_EVENT_DATA_LOST         (1UL << 1)
// Master Mode Fault (SS deactivated when Master)
#define DRV_SPI_EVENT_MODE_FAULT        (1UL << 2)

typedef void (*DRV_SPI_EventHandler_TypeDef)( uint32_t event );

typedef struct
{
  // Transmitter/Receiver busy flag
  uint32_t busy :1;
  // Data lost: Receive overflow / Transmit underflow
  // cleared on start of transfer operation
  uint32_t data_lost :1;
  // Mode fault detected; optional
  // cleared on start of transfer operation
  uint32_t mode_fault :1;
} DRV_SPI_Status_TypeDef;

typedef struct
{
  uint32_t simplex :1;              // supports Simplex Mode (Master and Slave)
  uint32_t ti_ssi :1;               // supports TI Synchronous Serial Interface
  uint32_t microwire :1;            // supports Microwire Interface
  uint32_t event_mode_fault :1;     // Signal Mode Fault event
} DRV_SPI_Capabilities_TypeDef;

/**
 \brief Access struct
 */
typedef struct
{
  int32_t (*Initialize)( void * v, DRV_SPI_EventHandler_TypeDef cb_event );
  int32_t (*Uninitialize)( void * v );
  int32_t (*PowerControl)( void * v, uint32_t state );

  int32_t (*Send)( void * v, void *data, uint32_t num );
  int32_t (*Receive)( void * v, void *data, uint32_t num );
  int32_t (*Transfer)( void * v, void *data_out, void *data_in, uint32_t num );

  uint32_t (*GetDataCount)( void * v );

  int32_t (*Control)( void * v, uint32_t control, uint32_t arg );
  DRV_SPI_Status_TypeDef (*GetStatus)( void * v );
} SPI_Driver_TypeDef;

#endif /* __DRIVER_SPI_H__ */
