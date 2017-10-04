#include "FT232R_Emulator_BSP.h"
#include "FT232R_Emulator_Conf.h"

#include "FT232R_Emulator_BSP_Conf.h"

#include "fifo.h"

#define FT232R_INVERT_TXD                 ( 0x01 )
#define FT232R_INVERT_RXD                 ( 0x02 )
#define FT232R_INVERT_RTS                 ( 0x04 )
#define FT232R_INVERT_CTS                 ( 0x08 )
#define FT232R_INVERT_DTR                 ( 0x10 )
#define FT232R_INVERT_DSR                 ( 0x20 )
#define FT232R_INVERT_DCD                 ( 0x40 )
#define FT232R_INVERT_RI                  ( 0x80 )

typedef enum USART_PIN
{
  USART_PIN_TX = 0,
  USART_PIN_RX,
  USART_PIN_RTS,
  USART_PIN_CTS,
  USART_PIN_DTR,
  USART_PIN_DSR,
  USART_PIN_DCD,
  USART_PIN_RI,
} BSP_USART_Pin_TypeDef;

/* Peripheral and Memory DMA transactions
 * Peripheral and Peripheral DMA transactions
 * -------------------------------------------------------------------------------------------------
 *
 * After an event, the peripheral sends a request signal to the DMA Controller.
 * The DMA controller serves the request depending on the channel priorities.
 * As soon as the DMA Controller accesses the peripheral,
 * an Acknowledge is sent to the peripheral by the DMA Controller.
 * The peripheral releases its request as soon as it gets the Acknowledge from the DMA Controller.
 * Once the request is deasserted by the peripheral, the DMA Controller releases the Acknowledge.
 * If there are more requests, the peripheral can initiate the next transaction.
 *
 * Each DMA transfer consists of three operations:
 *
 * 1) The loading of data from the peripheral data register or a location in memory addressed
 *    through an internal current peripheral/memory address register.
 *    The start address used for the first transfer is the base peripheral/memory address.
 *
 * 2) The storage of the data loaded to the peripheral data register or a location in memory addressed
 *    through an internal current peripheral/memory address register.
 *    The start address used for the first transfer is the base peripheral/memory address.
 *
 * 3) The post-decrementing of the DMA counter, which contains the number of transactions
 *    that still have to be performed.
 *
 * Memory and Memory DMA transactions
 * -------------------------------------------------------------------------------------------------
 *
 * The DMA channels can also work without being triggered by a request from a peripheral.
 * This mode is called Memory to Memory mode. If the MEM2MEM bit is set,
 * then the channel initiates transfers as soon as it is enabled by software by setting the Enable bit.
 * The transfer stops once the DMA counter reaches zero.
 * Memory to Memory mode may not be used at the same time as Circular mode.
 */
typedef struct
{
  FT232R_Context_TypeDef * FT232R_Context;

  FIFO TxFifo;
  FIFO RxFifo;

  uint8_t TxFifoMemory[ FT232R_EMULATOR_TXFIFO_SIZE ];
  uint8_t RxFifoMemory[ FT232R_EMULATOR_RXFIFO_SIZE ];

  uint16_t DataBit;         // From LineCoding
  uint16_t Parity;          // From LineCoding
  uint16_t TxBrokenState;   // From LineCoding
  uint16_t FlowControl;     // From LineCoding

  uint8_t Receiving;        // DMA Receiving
  uint8_t Transmitting;     // DMA Transmitting

  uint16_t TransmitTimes;   // DMA TransferSize
  uint32_t TxMemoryIndex;   // DMA TxFifoIndex

  uint32_t RxBufferIndex;   // DMA RxBufferIndex
  uint16_t RxBuffers[ 2 ][ BSP_USART_RX_BUFFER_WORD_SIZE ];
  uint8_t TxBuffer[ BSP_USART_TX_BUFFER_WORD_SIZE * 2 ];
} BSP_USART_Context_TypeDef;

BSP_USART_Context_TypeDef USART_Context;

/*
 * For example, the parity bit can be computed as follows,
 * assuming we are sending simple 4-bit values 1001.
 *
 * Even parity
 * A computes parity bit value: 1^0^0^1 = 0 ^ 0 = 0
 * A adds parity bit and sends: 1001-0
 *
 * B receives: 10010
 * B computes parity: 1^0^0^1^0 = 0
 * B reports correct transmission after observing expected even result.
 *
 * Odd parity
 * A computes parity bit value: 1^0^0^1 = 0 ^ 1 = 1
 * A adds parity bit and sends: 1001-1
 *
 * B receives: 10011
 * B computes overall parity: 1^0^0^1^1 = 1
 * B reports correct transmission after observing expected odd result.
 */
uint32_t FT232R_Emulator_BSP_BuildParity( uint8_t Data, uint32_t BitNum, uint32_t ParityType )
{
  uint32_t RetValue = 0;
  for ( uint32_t i = 0; i < BitNum; i++ )
  {
    if ( Data & ( 1 << i ) )
      RetValue ^= 1;
  }

  if ( FT232R_SET_LINE_PARITY_ODD == ParityType )
    RetValue ^= 1;

  return RetValue;
}

uint32_t FT232R_Emulator_BSP_BeforeTransmit( FT232R_Context_TypeDef * FT232R_Context )
{
  uint32_t TransmitTxBuffer = 0;
  uint32_t BuildSpaceMarkParity = 0x00;

  // 7Sx, 7Mx, 8Sx, 8Mx
  if ( ( FT232R_SET_LINE_PARITY_SPACE == USART_Context.Parity )
    || ( FT232R_SET_LINE_PARITY_MARK == USART_Context.Parity ) )
  {
    if ( FT232R_SET_LINE_DATA_BITS_8 == USART_Context.DataBit )
      TransmitTxBuffer = 1;

    if ( FT232R_SET_LINE_PARITY_MARK == USART_Context.Parity )
      BuildSpaceMarkParity = 0x01;
  }

  if ( 0 == TransmitTxBuffer )                  // From TxFifo, 7Nx, 7Ox, 7Ex, 7Sx, 8Nx, 8Ox, 8Ex
  {
    if ( BuildSpaceMarkParity )                 // 7Mx
    {
      for ( uint32_t i = 0; i < USART_Context.TransmitTimes; i++ )
        USART_Context.TxFifo.memory[ USART_Context.TxMemoryIndex + i ] |= 0x80;
    }

    BSP_USART_TXDMA_CH->CCR &= ~DMA_CCR_MSIZE;
    BSP_USART_TXDMA_CH->CMAR = (uint32_t) ( USART_Context.TxFifo.memory + USART_Context.TxMemoryIndex );
  }
  // 8Sx, 8Mx : 1 Start bit, 9 Data bits, n Stop bit
  // 8Sx, 8Mx : Copy from TxFifo to TxBuffer[ x ] and build parity
  else
  {
    if ( USART_Context.TransmitTimes > BSP_USART_TX_BUFFER_WORD_SIZE )
      USART_Context.TransmitTimes = BSP_USART_TX_BUFFER_WORD_SIZE;
    for ( uint32_t i = 0; i < USART_Context.TransmitTimes; i++ )
    {
      USART_Context.TxBuffer[ i * 2 + 0 ] = USART_Context.TxFifo.memory[ USART_Context.TxMemoryIndex + i ];
      USART_Context.TxBuffer[ i * 2 + 1 ] = BuildSpaceMarkParity;       // 0x00 or 0x01
    }

    BSP_USART_TXDMA_CH->CCR &= ~DMA_CCR_MSIZE;
    BSP_USART_TXDMA_CH->CCR |= DMA_MemoryDataSize_HalfWord;
    BSP_USART_TXDMA_CH->CMAR = (uint32_t) ( &USART_Context.TxBuffer[ 0 ] );

    if ( 0 )
    {
      FIFO_Flush( &USART_Context.TxFifo, USART_Context.TransmitTimes );
      USART_Context.TransmitTimes = 0;
    }
  }

  return 0;
}

void FT232R_Emulator_BSP_AfterReceived( FT232R_Context_TypeDef * FT232R_Context, uint32_t RxSize )
{
  uint16_t USART_RDR;
  uint32_t RxMemoryIndex, Writable, Written;

  uint32_t RxBufferIndex = ( USART_Context.RxBufferIndex - 1 ) & 1;

  uint32_t RxByteIndex = 0;
  while ( RxSize )
  {
    Writable = FIFO_Writable( &USART_Context.RxFifo, &RxMemoryIndex );
    Written = ( RxSize > Writable ) ? Writable : RxSize;

    for ( uint32_t i = 0; i < Written; i++, RxByteIndex++ )
    {
      USART_RDR = USART_Context.RxBuffers[ RxBufferIndex ][ RxByteIndex ];
      //
      // ToDo : Parity Bit Handle
      //
      USART_Context.RxFifo.memory[ RxMemoryIndex + i ] = USART_RDR;
    }

    FIFO_Update( &USART_Context.RxFifo, Written );
    FT232R_Context->OnRxCompleted( FT232R_Context );

    RxSize -= Written;
  }
}

void FT232R_Emulator_BSP_StartReceive( FT232R_Context_TypeDef * FT232R_Context )
{
  BSP_USART_RXDMA_CH->CNDTR = BSP_USART_RX_BUFFER_WORD_SIZE;  // DMA Transfer Times
  BSP_USART_RXDMA_CH->CMAR = (uint32_t) ( &USART_Context.RxBuffers[ USART_Context.RxBufferIndex & 1 ][ 0 ] );
  BSP_USART_RXDMA_CH->CCR |= DMA_CCR_EN;
  BSP_USART->RTOR = 32;
  USART_Context.Receiving = 1;
}

void FT232R_Emulator_BSP_StartTransmit( FT232R_Context_TypeDef * FT232R_Context )
{
  // ToDo : Hanlder FlowControl for XON/XOFF, RTS/CTS, DTR/DSR

  if ( USART_Context.Transmitting )
    return;

  USART_Context.TransmitTimes = FIFO_Readable( &USART_Context.TxFifo, &USART_Context.TxMemoryIndex );
  if ( USART_Context.TransmitTimes )
  {
    FT232R_Emulator_BSP_BeforeTransmit( FT232R_Context );
    // MemorySize and MemoryAddr are set
    BSP_USART_TXDMA_CH->CNDTR = USART_Context.TransmitTimes;
    BSP_USART_TXDMA_CH->CCR |= DMA_CCR_EN;
    USART_Context.Transmitting = 1;
  }
}

int32_t FT232R_Emulator_BSP_Init( FT232R_Context_TypeDef * FT232R_Context )
{
  GPIO_InitTypeDef GPIO_InitStructure;
  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  USART_Context.FT232R_Context = FT232R_Context;

  FIFO_Init( &USART_Context.TxFifo, FT232R_EMULATOR_TXFIFO_SIZE, USART_Context.TxFifoMemory );
  FIFO_Init( &USART_Context.RxFifo, FT232R_EMULATOR_RXFIFO_SIZE, USART_Context.RxFifoMemory );

  /* Enable GPIO clock */
  uint32_t RCC_AHBPeriph = 0  //
  | BSP_USART_TX_GPIO_CLK  //
    | BSP_USART_RX_GPIO_CLK  //
#if ( BSP_USART_RTS_CTS_EANBLED > 0 )
    | BSP_USART_RTS_GPIO_CLK  //
    | BSP_USART_CTS_GPIO_CLK//
#endif
#if ( BSP_USART_DTR_DSR_EANBLED > 0 )
    | BSP_USART_DTR_GPIO_CLK  //
    | BSP_USART_DSR_GPIO_CLK//
#endif
#if ( BSP_USART_DCD_RI_EANBLED > 0 )
    | BSP_USART_DCD_GPIO_CLK  //
    | BSP_USART_RI_GPIO_CLK//
#endif
    | 0;

  /* Enable GPIO clock */
  RCC_AHBPeriphClockCmd( RCC_AHBPeriph, ENABLE );

  /* Connect Pin to USARTx_Tx */
  GPIO_PinAFConfig( BSP_USART_TX_GPIO_PORT, BSP_USART_TX_PIN_SOURCE, BSP_USART_TX_AF );

  /* Configure USART Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init( BSP_USART_TX_GPIO_PORT, &GPIO_InitStructure );

  /* Connect Pin to USARTx_Rx */
  GPIO_PinAFConfig( BSP_USART_RX_GPIO_PORT, BSP_USART_RX_PIN_SOURCE, BSP_USART_RX_AF );

  /* Configure USART Rx as alternate function push-pull? */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_RX_PIN;
  GPIO_Init( BSP_USART_RX_GPIO_PORT, &GPIO_InitStructure );

#if ( BSP_USART_RTS_CTS_EANBLED > 0 )

#if ( BSP_USART_HW_RTS_CTS_EANBLED > 0 )
  /* Connect Pin to USARTx_RTS */
  GPIO_PinAFConfig( BSP_USART_RTS_GPIO_PORT, BSP_USART_RTS_PIN_SOURCE, BSP_USART_RTS_AF );

  /* Configure USART RTS as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_RTS_PIN;
  GPIO_Init( BSP_USART_RTS_GPIO_PORT, &GPIO_InitStructure );

  /* Connect Pin to USARTx_CTS */
  GPIO_PinAFConfig( BSP_USART_CTS_GPIO_PORT, BSP_USART_CTS_PIN_SOURCE, BSP_USART_CTS_AF );

  /* Configure USART Rx as alternate function push-pull? */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_CTS_PIN;
  GPIO_Init( BSP_USART_CTS_GPIO_PORT, &GPIO_InitStructure );
#else
  /* Configure USART RTS as push-pull output */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_RTS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init( BSP_USART_RTS_GPIO_PORT, &GPIO_InitStructure );

  /* Configure USART CTS as input with pullup */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_CTS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init( BSP_USART_CTS_GPIO_PORT, &GPIO_InitStructure );

  /* Connect EXTI Line to GPIO Pin */
  SYSCFG_EXTILineConfig( BSP_USART_CTS_EXTI_PORT_SOURCE, BSP_USART_CTS_EXTI_PIN_SOURCE );

  /* Configure Button EXTI line */
  EXTI_InitStructure.EXTI_Line = BSP_USART_CTS_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init( &EXTI_InitStructure );

  /* Enable and set EXTI Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_CTS_EXTI_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0x03;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init( &NVIC_InitStructure );

#endif

#endif

#if ( BSP_USART_DTR_DSR_EANBLED > 0 )
  /* Configure USART DTR as push-pull output */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_DTR_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init( BSP_USART_DTR_GPIO_PORT, &GPIO_InitStructure );

  /* Configure USART DSR as input with pullup */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_DSR_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init( BSP_USART_DSR_GPIO_PORT, &GPIO_InitStructure );

  /* Connect EXTI Line to GPIO Pin */
  SYSCFG_EXTILineConfig( BSP_USART_DSR_EXTI_PORT_SOURCE, BSP_USART_DSR_EXTI_PIN_SOURCE );

  /* Configure Button EXTI line */
  EXTI_InitStructure.EXTI_Line = BSP_USART_DSR_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init( &EXTI_InitStructure );

  /* Enable and set EXTI Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_DSR_EXTI_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0x03;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init( &NVIC_InitStructure );
#endif

#if ( BSP_USART_DCD_RI_EANBLED > 0 )
  /* Configure USART DCD as push-pull output */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_DCD_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init( BSP_USART_DCD_GPIO_PORT, &GPIO_InitStructure );

  /* Configure USART RI as input with pullup */
  GPIO_InitStructure.GPIO_Pin = BSP_USART_RI_PIN;
  GPIO_Init( BSP_USART_RI_GPIO_PORT, &GPIO_InitStructure );
#endif

  /* Enable USART clock */
#if ( 0 == BSP_USART_USES_USART2 )
  RCC_APB2PeriphClockCmd( BSP_USART_CLK, ENABLE );
#else
  RCC_APB1PeriphClockCmd( BSP_USART_CLK, ENABLE );
#endif

  /* Enable USART, USART_TX, USART_RX,
   * RTOIE: Receiver timeout interrupt enable
   * CMIE: Character match interrupt enable
   *
   * Enable RX Interrupt only,  TX interrupt enabled in send routine
   */
  BSP_USART->CR1 =
  USART_CR1_UE |          // USART enable
    USART_CR1_TE |        // Transmitter enabled
    USART_CR1_RE |        // Receiver enabled
    USART_CR1_IDLEIE |    // Receiver Idle interrupt enabled
    USART_CR1_RTOIE |     // Receive Timeout interrupt enabled
    0;

  // ToDo : Handle Pin Invert for TXD and RXD

  //  Enable USART DMA TX and RX request
  BSP_USART->CR3 |= ( USART_CR3_DMAR | USART_CR3_DMAT );

  // Bits 23:0 RTO[23:0]: Receiver timeout value
  // This bit-field gives the Receiver timeout value in terms of number of bit duration.
  // This value must only be programmed once per received character.
  BSP_USART->RTOR = 0xFFFFFFFF;

  /* RxDMA (triggered by USART Rx event : RXNE == 1 ) Config */
  RCC_AHBPeriphClockCmd( BSP_USART_RXDMA_CLK, ENABLE );

  BSP_USART_RXDMA_CH->CCR = 0;   // Disable DMA to Config it
  BSP_USART_RXDMA_CH->CPAR = (uint32_t) &BSP_USART->RDR;

  BSP_USART_RXDMA_CH->CCR =
  DMA_M2M_Disable |                     // Memory to memory mode disabled
    DMA_Priority_High |                 // Channel priority level
    DMA_PeripheralDataSize_HalfWord |   // Peripheral size always uses Half Word
    DMA_MemoryDataSize_HalfWord |       // Memory size always uses Half Word
    DMA_MemoryInc_Enable |              // Memory increment mode
    DMA_PeripheralInc_Disable |         // Peripheral increment mode
    DMA_Mode_Normal |                   // Circular mode disabled
    DMA_DIR_PeripheralSRC |             // Data transfer direction, Write to memory
    DMA_CCR_TCIE | DMA_CCR_TEIE |       // Transfer error and complete interrupt enable
    0;                                  // Channel disabled

  /* RxDMA is ready to receive -- RxBuffer[0][0], HalfWord, Transfer USART_RX_BUFFER_WORD_SIZE Times */
  USART_Context.RxBufferIndex = 0;
  FT232R_Emulator_BSP_StartReceive( FT232R_Context );

  /* TxDMA (triggered by USART Tx event : TXE == 1 ) Config */
  RCC_AHBPeriphClockCmd( BSP_USART_TXDMA_CLK, ENABLE );

  BSP_USART_TXDMA_CH->CCR = 0;   // Disable DMA to Config it

  BSP_USART_TXDMA_CH->CNDTR = 0;
  BSP_USART_TXDMA_CH->CMAR = 0;
  BSP_USART_TXDMA_CH->CPAR = (uint32_t) &BSP_USART->TDR;

  BSP_USART_TXDMA_CH->CCR =
  DMA_M2M_Disable |                     // Memory to memory mode disabled
    DMA_Priority_High |                 // Channel priority level
    DMA_PeripheralDataSize_HalfWord |   // Peripheral size always uses Half Word
    DMA_MemoryDataSize_Byte |           // Memory size, Byte/HalfWord for 8/9 bits word length
    DMA_MemoryInc_Enable |              // Memory increment mode
    DMA_PeripheralInc_Disable |         // Peripheral increment mode
    DMA_Mode_Normal |                   // Circular mode disabled
    DMA_DIR_PeripheralDST |             // Data transfer direction, Read from memory
    DMA_CCR_TCIE | DMA_CCR_TEIE |       // Transfer error and complete interrupt enable
    0;                                  // Channel disabled

  /* TxDMA is disabled -- MemoryAddr, MemorySize and TransferTimes are unknown */

  /* USB interrupt PreemptionPriority = 3 */
  /* USB Wake-up interrupt PreemptionPriority = 3 */
  /* RXDMA Interrupt Priority is heigher USART Receiver timeout Interrupt */
  /* USART Receiver timeout Interrupt Priority is heigher TXDMA Interrupt */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  /* Clears the corresponding HTIF flag in the DMA_ISR register */
  BSP_USART_DMA->IFCR = BSP_USART_TXDMA_CGIF;
  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_RXDMA_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 3;
  NVIC_Init( &NVIC_InitStructure );

  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 2;
  NVIC_Init( &NVIC_InitStructure );

  /* Clears the corresponding HTIF flag in the DMA_ISR register */
  BSP_USART_DMA->IFCR = BSP_USART_RXDMA_CGIF;
  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_RXDMA_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
  NVIC_Init( &NVIC_InitStructure );

  return 0;
}

int32_t FT232R_Emulator_BSP_Uninit( FT232R_Context_TypeDef * FT232R_Context )
{
  return 0;
}

int32_t FT232R_Emulator_BSP_GetModemLineStatus( FT232R_Context_TypeDef * FT232R_Context )
{
  FT232R_Context->ModemStatus = 0x01;

#if ( BSP_USART_RTS_CTS_EANBLED)
  // ToDo : Handle Pin Invert for CTS, DSR, DCD and RI
  if ( BSP_USART_CTS_GPIO_PORT->IDR & BSP_USART_CTS_PIN )
  FT232R_Context->ModemStatus |= FT232R_GET_MODEM_STATUS_CTS;
#endif

#if ( BSP_USART_DTR_DSR_EANBLED)

  if ( BSP_USART_DSR_GPIO_PORT->IDR & BSP_USART_DSR_PIN )
  FT232R_Context->ModemStatus |= FT232R_GET_MODEM_STATUS_DSR;
#endif

#if ( BSP_USART_DCD_RI_EANBLED)

  if ( BSP_USART_DCD_GPIO_PORT->IDR & BSP_USART_DCD_PIN )
  FT232R_Context->ModemStatus |= FT232R_GET_MODEM_STATUS_DCD;

  if ( BSP_USART_RI_GPIO_PORT->IDR & BSP_USART_RI_PIN )
  FT232R_Context->ModemStatus |= FT232R_GET_MODEM_STATUS_RI;
#endif

  FT232R_Context->LineStatus = 0x00;
  uint32_t USART_ISR = BSP_USART->ISR;

  if ( USART_ISR & USART_ISR_RXNE )    // RXNE
  {
    FT232R_Context->LineStatus |= FT232R_LINE_STATUS_DR;
  }

  if ( USART_ISR & USART_ISR_ORE )    // ORE
  {
    FT232R_Context->LineStatus |= FT232R_LINE_STATUS_OE;
  }

  if ( USART_ISR & USART_ISR_PE )     // PE
  {
    FT232R_Context->LineStatus |= FT232R_LINE_STATUS_PE;
  }

  // This bit is set by hardware when the LIN break is detected.
  // It is cleared by software (by writing it to 0).
  if ( USART_ISR & USART_ISR_LBDF )    // LBD
  {
    FT232R_Context->LineStatus |= FT232R_LINE_STATUS_BI;
    BSP_USART->ISR &= ~( USART_ISR_LBDF );
  }

  if ( USART_ISR & USART_ISR_TXE )    // TXE -- Transmit data register -- TDR
  {
    FT232R_Context->LineStatus |= FT232R_LINE_STATUS_THRE;
  }

  if ( USART_ISR & USART_ISR_TC )     // TC -- Transmit Shift Register -- TSR
  {
    FT232R_Context->LineStatus |= FT232R_LINE_STATUS_TEMT;
  }

  return 0;
}

/* FT232R_Context->ModemControl
 *
 *  B0    DTR state
 *          0 = reset
 *          1 = set
 * B1    RTS state
 *          0 = reset
 *          1 = set
 * B2..7 Reserved
 *
 * B8    DTR state enable
 *          0 = ignore
 *          1 = use DTR state
 * B9    RTS state enable
 *          0 = ignore
 *          1 = use RTS state
 * B10..15 Reserved
 */
int32_t FT232R_Emulator_BSP_SetModemCtrl( FT232R_Context_TypeDef * FT232R_Context )
{
#if ( ( BSP_USART_DTR_DSR_EANBLED > 0 ) || ( BSP_USART_RTS_CTS_EANBLED > 0 ) )
  uint8_t Mask, Value;

  Mask = FT232R_Context->ModemControl >> 8;
  Value = FT232R_Context->ModemControl >> 0;
#endif

  // ToDo : Handle Invert for RTS and DTR

#if ( BSP_USART_DTR_DSR_EANBLED > 0 )
  if ( Mask & FT232R_SET_MODEM_CTRL_DTR )
  {
    // BSRR : BR:BS : If both BSx and BRx are set, BSx has priority -- Set
    if ( Value & FT232R_SET_MODEM_CTRL_DTR )
    BSP_USART_DTR_GPIO_PORT->BSRR = FT232R_SET_MODEM_CTRL_DTR;
    else
    BSP_USART_DTR_GPIO_PORT->BRR = FT232R_SET_MODEM_CTRL_DTR;
  }
#endif

#if ( BSP_USART_RTS_CTS_EANBLED > 0 )
  if ( Mask & FT232R_SET_MODEM_CTRL_RTS )
  {
    if ( Value & FT232R_SET_MODEM_CTRL_RTS )
    BSP_USART_DTR_GPIO_PORT->BSRR = FT232R_SET_MODEM_CTRL_RTS;
    else
    BSP_USART_DTR_GPIO_PORT->BRR = FT232R_SET_MODEM_CTRL_RTS;
  }
#endif

  return 0;
}

int32_t FT232R_Emulator_BSP_SetBaudrate( FT232R_Context_TypeDef * FT232R_Context )
{
  uint32_t apbclock;
  uint16_t Div, DIV_Mantissa, DIV_Fraction;
  uint32_t BaudRate = FT232R_Context->BaudRate;

  RCC_ClocksTypeDef RCC_ClocksStatus;
  RCC_GetClocksFreq( &RCC_ClocksStatus );
  if ( USART1_BASE == (uint32_t) ( BSP_USART ) )
    apbclock = RCC_ClocksStatus.USART1CLK_Frequency;
  else
    apbclock = RCC_ClocksStatus.USART2CLK_Frequency;

  Div = ( apbclock + ( BaudRate >> 1 ) ) / BaudRate;

  if ( 0 )  // ( BSP_USART->CR1 & USART_CR1_OVER8 )
  {
    DIV_Mantissa = ( Div & ~0x7 ) << 1;
    DIV_Fraction = Div & 0x07;
    Div = DIV_Mantissa | DIV_Fraction;
  }

  BSP_USART->BRR = Div;

  return 0;
}

int32_t FT232R_Emulator_BSP_SetLineBreak( FT232R_Context_TypeDef * FT232R_Context, uint32_t BreakOn )
{
  // Todo : Handle Invert for TXD
  //
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Pin = BSP_USART_TX_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

  if ( BreakOn )
  {
    /* Configure USART Tx as general purpose push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init( BSP_USART_TX_GPIO_PORT, &GPIO_InitStructure );

    BSP_USART_TX_GPIO_PORT->BRR = BSP_USART_TX_PIN;
  }
  else
  {
    BSP_USART_TX_GPIO_PORT->BSRR = BSP_USART_TX_PIN;

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init( BSP_USART_TX_GPIO_PORT, &GPIO_InitStructure );
  }
  return 0;
}

/*   B0..7   Number of data bits < 7 or 8 >
 *   B8..10  Parity
 *           0 = None
 *           1 = Odd
 *           2 = Even
 *           3 = Mark
 *           4 = Space
 *   B11..13 Stop Bits
 *           0 = 1
 *           1 = 1.5
 *           2 = 2
 *   B14
 *           1 = TX ON (break)
 *           0 = TX OFF (normal state)
 *   B15 Reserved
 */
int32_t FT232R_Emulator_BSP_SetLineCoding( FT232R_Context_TypeDef * FT232R_Context )
{
  // Set TxBreak
  uint16_t TxBreak = FT232R_Context->LineCoding & FT232R_SET_LINE_BREAK_MASK;
  if ( USART_Context.TxBrokenState ^ TxBreak )                      // Break State Changed
  {
    FT232R_Emulator_BSP_SetLineBreak( FT232R_Context, TxBreak );    // Change Tx Level
    USART_Context.TxBrokenState ^= FT232R_SET_LINE_BREAK_MASK;      // Save New State
  }

  // Set StopBit
  uint32_t USART_CR = BSP_USART->CR2 & ~USART_CR2_STOP;             // 1 STOP
  if ( FT232R_SET_LINE_STOP_BITS_1_5 == ( FT232R_Context->LineCoding & FT232R_SET_LINE_STOP_BITS_MASK ) )
    USART_CR |= ( USART_CR2_STOP_1 | USART_CR2_STOP_0 );            // 1.5 STOP
  else if ( FT232R_SET_LINE_STOP_BITS_2 == ( FT232R_Context->LineCoding & FT232R_SET_LINE_STOP_BITS_MASK ) )
    USART_CR |= USART_CR2_STOP_1;                                   // 2 STOP
  // USART_CR |= USART_CR2_RTOEN;                                   // Receiver timeout enable
  BSP_USART->CR2 |= USART_CR;

  // Set DataBit and Parity : PCE, PS, M1, M0 by USART_Context.Parity and USART_Context.DataBit
  USART_Context.Parity = FT232R_Context->LineCoding & FT232R_SET_LINE_PARITY_MARK;
  USART_Context.DataBit = FT232R_Context->LineCoding & FT232R_SET_LINE_DATA_BITS_MASK;
  //
  // M1, M0  : 00 : 1 Start bit, 8 data bits, n stop bits
  // M1, M0  : 01 : 1 Start bit, 9 data bits, n stop bits
  // M1, M0  : 10 : 1 Start bit, 7 data bits, n stop bits
  // PCE, PE : 0X : Parity control disabled
  // PCE, PE : 10 : Parity control enabled : Even parity
  // PCE, PE : 11 : Parity control enabled : Odd parity
  //
  // 7, O, X <--> 7, O, X : Hardware Parity : M1=0, M0=0, PCE=1, PS=1
  // 7, E, X <--> 7, E, X : Hardware Parity : M1=0, M0=0, PCE=1, PS=0
  // 8, O, X <--> 8, O, X : Hardware Parity : M1=0, M0=1, PCE=1, PS=1
  // 8, E, X <--> 8, E, X : Hardware Parity : M1=0, M0=1, PCE=1, PS=0
  //
  // 7, N, X <--> 7, N, X : Without  Parity : M1=1, M0=1, PCE=0, PS=0
  // 8, N, X <--> 8, N, X : Without  Parity : M1=0, M0=0, PCE=0, PS=0
  //
  // 8, M, X <--> 9, N, X : Software Parity : M1=0, M0=1, PCE=0, PS=0 : Data |=  0x100 : Bit8 = Space
  // 8, S, X <--> 9, N, X : Software Parity : M1=0, M0=1, PCE=0, PS=0 : Data &= ~0x100 : Bit8 = Mark
  // 7, M, X <--> 8, N, X : Software Parity : M1=0, M0=0, PCE=0, PS=0 : Data |=   0x80 : Bit7 = Space
  // 7, S, X <--> 8, N, X : Software Parity : M1=0, M0=0, PCE=0, PS=0 : Data &=  ~0x80 : Bit7 = Mark
  //
  USART_CR = BSP_USART->CR1 & ~( USART_CR1_M | USART_CR1_PCE | USART_CR1_PS );
  if ( ( FT232R_SET_LINE_PARITY_ODD == USART_Context.Parity )
    || ( FT232R_SET_LINE_PARITY_EVEN == USART_Context.Parity ) )
  {
    USART_CR |= USART_CR1_PCE;
    if ( FT232R_SET_LINE_PARITY_ODD == USART_Context.Parity )       // if Odd Parity
      USART_CR |= USART_CR1_PS;                                     // else Even Parity
    if ( FT232R_SET_LINE_DATA_BITS_8 == USART_Context.DataBit )     // 8 + 1 = 9 Bits : 8Ox, 8Ex
      USART_CR |= USART_CR1_M0;                                     // 7 + 1 = 8 Bits : 7Ox, 7Ex
  }
  else
  {
    if ( FT232R_SET_LINE_PARITY_NONE == USART_Context.Parity )      // No Parity
    {
      if ( FT232R_SET_LINE_DATA_BITS_7 == USART_Context.DataBit )   // 7 Bits : 7Nx
        USART_CR |= USART_CR1_M;                                    // 8 Bits : 8Nx
    }
    else
    {
      if ( FT232R_SET_LINE_DATA_BITS_8 == USART_Context.DataBit )   // 8 + 1 = 9 Bits : 8Sx, 8Mx
        USART_CR |= USART_CR1_M0;                                   // 7 + 1 = 8 Bits : 7Sx, 7Mx
    }
  }
  BSP_USART->CR1 = USART_CR;

  return 0;
}

/* FlowControl
 *
 * B0 Output handshaking using RTS/CTS
 *     0 = disabled
 *     1 = enabled
 * B1 Output handshaking using DTR/DSR
 *     0 = disabled
 *     1 = enabled
 * B2 Xon/Xoff handshaking
 *     0 = disabled
 *     1 = enabled
 *
 * Bit 9 CTSE: CTS enable
 *
 * 0: CTS hardware flow control disabled
 * 1: CTS mode enabled, data is only transmitted when the nCTS input is asserted (tied to 0).
 *
 * If the nCTS input is de-asserted while data is being transmitted,
 * then the transmission is completed before stopping.
 * If data is written into the data register while nCTS is de-asserted,
 * the transmission is postponed until nCTS is asserted.
 * This bit can only be written when the USART is disabled (UE=0)
 *
 * Bit 8 RTSE: RTS enable
 *
 * 0: RTS hardware flow control disabled
 * 1: RTS output enabled, data is only requested when there is space in the receive buffer.
 *
 * The transmission of data is expected to cease after the current character has been transmitted.
 * The nRTS output is asserted (pulled to 0) when data can be received.
 * This bit can only be written when the USART is disabled (UE=0).
 *
 */
int32_t FT232R_Emulator_BSP_SetFlowCtrl( FT232R_Context_TypeDef * FT232R_Context )
{
  USART_Context.FlowControl = FT232R_Context->FlowControl;

  BSP_USART->CR1 &= ~USART_CR1_UE;

  if ( FT232R_SET_FLOW_CTRL_RTSCTS == USART_Context.FlowControl )
  {
    BSP_USART->CR3 &= ~( USART_CR3_CTSE | USART_CR3_RTSE );
  }
  else
  {
    BSP_USART->CR3 |= ( USART_CR3_CTSE | USART_CR3_RTSE );
  }

  BSP_USART->CR1 |= USART_CR1_UE;

  return 0;
}

int32_t FT232R_Emulator_BSP_CancelTransmit( FT232R_Context_TypeDef * FT232R_Context )
{
  FIFO_Clear( &USART_Context.TxFifo );
  return 0;
}

int32_t FT232R_Emulator_BSP_CancelReceive( FT232R_Context_TypeDef * FT232R_Context )
{
  FIFO_Clear( &USART_Context.RxFifo );
  return 0;
}

int32_t FT232R_Emulator_BSP_Transmit( FT232R_Context_TypeDef * FT232R_Context, uint8_t * Buffer, uint32_t Size )
{
  int32_t RetValue = FIFO_Write( &USART_Context.TxFifo, Buffer, Size );
  FT232R_Emulator_BSP_StartTransmit( FT232R_Context );
  return RetValue;
}

int32_t FT232R_Emulator_BSP_Receive( FT232R_Context_TypeDef * FT232R_Context, uint8_t * Buffer, uint32_t Size )
{
  int32_t RetValue = FIFO_Read( &USART_Context.RxFifo, Buffer, Size );
  return RetValue;
}

/* RTOF: Receiver timeout
 * This bit is set by hardware when the timeout value, programmed in the RTOR register has lapsed,
 * without any communication.
 *
 * It is cleared by software, writing 1 to the RTOCF bit in the USARTx_ICR register.
 *
 * An interrupt is generated if RTOIE=1 in the USARTx_CR2 register.
 * 0: Timeout value not reached
 * 1: Timeout value reached without any data reception
 *
 * Note:If a time equal to the value programmed in RTOR register separates 2 characters, RTOF is not set.
 * If this time exceeds this value + 2 sample times, RTOF flag is set.
 * The sample times (2/16 or 2/8, depending on the oversampling method)
 * The counter counts even if RE = 0 but RTOF is set only when RE = 1.
 * If the timeout has already elapsed when RE is set, then RTOF will be set.
 */
void BSP_USART_RXDMA_IRQHandler( void );
void BSP_USART_IRQHandler( void )
{
  if ( BSP_USART->ISR & USART_ISR_IDLE )
  {
    BSP_USART->ICR = USART_ICR_IDLECF;
    if ( USART_Context.Receiving )
    {
      USART_Context.Receiving = 0;
      BSP_USART_RXDMA_IRQHandler( );
    }
  }

  if ( 0 )  // BSP_USART->ISR & USART_ISR_RTOF )
  {
    BSP_USART->ICR = USART_ICR_RTOCF;
    if ( USART_Context.Receiving )
    {
      USART_Context.Receiving = 0;
      BSP_USART_RXDMA_IRQHandler( );
    }
  }
}

void BSP_USART_RXDMA_IRQHandler( void )
{
  /* Clear the flag */
  BSP_USART_DMA->IFCR = BSP_USART_RXDMA_CGIF;

  BSP_USART_RXDMA_CH->CCR &= ~DMA_CCR_EN;

  uint32_t RxSize = BSP_USART_RX_BUFFER_WORD_SIZE - BSP_USART_RXDMA_CH->CNDTR;
  USART_Context.RxBufferIndex++;                                                // Switch RxBuffer
  FT232R_Emulator_BSP_StartReceive( USART_Context.FT232R_Context );             // Receive New Data
  FT232R_Emulator_BSP_AfterReceived( USART_Context.FT232R_Context, RxSize );    // Handle Old Data
}

void BSP_USART_TXDMA_IRQHandler( void )
{
  // 1) Last But One Byte has been written to USART->TDR
  // 2) Last But One Byte in USART->DR has been transferred to USART->TSR
  // 3) USART->SR.TXE=1, DMA Tx request triggered : TXE=1 and TC=0
  // 4) DMA Tx Last Byte to USART->DR : TXE=0 and TC=0
  // 5) Last Byte in USART->DR has been transferred to Shift Register
  // 6) USART->SR.TXE=1, DMA Tx request triggered : TXE=1 and TC=0
  // DMA Tx request will be triggered again after USART->SR.TXE=1
  //
  // NOW TXE=0 and TC=0
  /* Clear the flag */
  BSP_USART_DMA->IFCR = BSP_USART_TXDMA_CGIF;

  BSP_USART_TXDMA_CH->CCR &= ~DMA_CCR_EN;

  FIFO_Flush( &USART_Context.TxFifo, USART_Context.TransmitTimes );  // - CNTR
  // TxFifo can be written again
  USART_Context.FT232R_Context->OnTxCompleted( USART_Context.FT232R_Context );
  USART_Context.Transmitting = 0;
  // Try to send if new data has been written
  FT232R_Emulator_BSP_StartTransmit( USART_Context.FT232R_Context );
}

void BSP_USART_DMA_IRQHandler( void )
{
  /* Test if transfer completed or error on TXDMA channel */
  if ( ( BSP_USART_DMA->ISR & BSP_USART_TXDMA_CTCIF ) || ( BSP_USART_DMA->ISR & BSP_USART_TXDMA_CTEIF ) )
    BSP_USART_TXDMA_IRQHandler( );

  /* Test if transfer completed or error on RXDMA channel */
  if ( ( BSP_USART_DMA->ISR & BSP_USART_RXDMA_CTCIF ) || ( BSP_USART_DMA->ISR & BSP_USART_RXDMA_CTEIF ) )
    BSP_USART_RXDMA_IRQHandler( );
}
