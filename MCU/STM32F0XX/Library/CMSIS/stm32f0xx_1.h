
/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t ISR;          /*!< ADC interrupt and status register,             Address offset: 0x00 */
  __IO uint32_t IER;          /*!< ADC interrupt enable register,                 Address offset: 0x04 */
  __IO uint32_t CR;           /*!< ADC control register,                          Address offset: 0x08 */
  __IO uint32_t CFGR1;        /*!< ADC configuration register 1,                  Address offset: 0x0C */
  __IO uint32_t CFGR2;        /*!< ADC configuration register 2,                  Address offset: 0x10 */
  __IO uint32_t SMPR;         /*!< ADC sampling time register,                    Address offset: 0x14 */
       uint32_t RESERVED1;    /*!< Reserved,                                                      0x18 */
       uint32_t RESERVED2;    /*!< Reserved,                                                      0x1C */
  __IO uint32_t TR;           /*!< ADC analog watchdog 1 threshold register,      Address offset: 0x20 */
       uint32_t RESERVED3;    /*!< Reserved,                                                      0x24 */
  __IO uint32_t CHSELR;       /*!< ADC group regular sequencer register,          Address offset: 0x28 */
       uint32_t RESERVED4[5]; /*!< Reserved,                                                      0x2C */
  __IO uint32_t DR;           /*!< ADC group regular data register,               Address offset: 0x40 */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CCR;          /*!< ADC common configuration register,             Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;

/**
  * @brief Controller Area Network TxMailBox
  */
typedef struct
{
  __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
  __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
  __IO uint32_t TDLR; /*!< CAN mailbox data low register */
  __IO uint32_t TDHR; /*!< CAN mailbox data high register */
}CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFOMailBox
  */
typedef struct
{
  __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
  __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
  __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
  __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
}CAN_FIFOMailBox_TypeDef;

/**
  * @brief Controller Area Network FilterRegister
  */
typedef struct
{
  __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
  __IO uint32_t FR2; /*!< CAN Filter bank register 1 */
}CAN_FilterRegister_TypeDef;

/**
  * @brief Controller Area Network
  */
typedef struct
{
  __IO uint32_t              MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
  __IO uint32_t              MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
  __IO uint32_t              TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
  __IO uint32_t              RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
  __IO uint32_t              RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
  __IO uint32_t              IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
  __IO uint32_t              ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
  __IO uint32_t              BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
  uint32_t                   RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
  CAN_TxMailBox_TypeDef      sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
  uint32_t                   RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
  __IO uint32_t              FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
  __IO uint32_t              FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
  uint32_t                   RESERVED2;           /*!< Reserved, 0x208                                                    */
  __IO uint32_t              FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
  uint32_t                   RESERVED3;           /*!< Reserved, 0x210                                                    */
  __IO uint32_t              FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
  uint32_t                   RESERVED4;           /*!< Reserved, 0x218                                                    */
  __IO uint32_t              FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
  uint32_t                   RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */
  CAN_FilterRegister_TypeDef sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
}CAN_TypeDef;

/**
  * @brief HDMI-CEC
  */

typedef struct
{
  __IO uint32_t CR;           /*!< CEC control register,                                       Address offset:0x00 */
  __IO uint32_t CFGR;         /*!< CEC configuration register,                                 Address offset:0x04 */
  __IO uint32_t TXDR;         /*!< CEC Tx data register ,                                      Address offset:0x08 */
  __IO uint32_t RXDR;         /*!< CEC Rx Data Register,                                       Address offset:0x0C */
  __IO uint32_t ISR;          /*!< CEC Interrupt and Status Register,                          Address offset:0x10 */
  __IO uint32_t IER;          /*!< CEC interrupt enable register,                              Address offset:0x14 */
}CEC_TypeDef;

/**
  * @brief Comparator
  */

typedef struct
{
  __IO uint16_t CSR;         /*!< COMP control and status register,                                                 Address offset: 0x00 */
} COMP_TypeDef;

typedef struct
{
  __IO uint32_t CSR;         /*!< COMP control and status register, used for bits common to several COMP instances, Address offset: 0x00 */
} COMP_Common_TypeDef;

/* Legacy defines */
typedef struct
{
  __IO uint32_t CSR;         /*!< Kept for legacy purpose. Use structure 'COMP_Common_TypeDef'. */
}COMP1_2_TypeDef;

/**
  * @brief CRC calculation unit
  */

typedef struct
{
  __IO uint32_t DR;          /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint8_t  IDR;         /*!< CRC Independent data register,               Address offset: 0x04 */
  uint8_t       RESERVED0;   /*!< Reserved,                                                    0x05 */
  uint16_t      RESERVED1;   /*!< Reserved,                                                    0x06 */
  __IO uint32_t CR;          /*!< CRC Control register,                        Address offset: 0x08 */
  uint32_t      RESERVED2;   /*!< Reserved,                                                    0x0C */
  __IO uint32_t INIT;        /*!< Initial CRC value register,                  Address offset: 0x10 */
  __IO uint32_t POL;         /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief Clock Recovery System
  */
typedef struct
{
__IO uint32_t CR;     /*!< CRS ccontrol register,              Address offset: 0x00 */
__IO uint32_t CFGR;   /*!< CRS configuration register,         Address offset: 0x04 */
__IO uint32_t ISR;    /*!< CRS interrupt and status register,  Address offset: 0x08 */
__IO uint32_t ICR;    /*!< CRS interrupt flag clear register,  Address offset: 0x0C */
}CRS_TypeDef;

/**
  * @brief Digital to Analog Converter
  */

typedef struct
{
  __IO uint32_t CR;           /*!< DAC control register,                                     Address offset: 0x00 */
  __IO uint32_t SWTRIGR;      /*!< DAC software trigger register,                            Address offset: 0x04 */
  __IO uint32_t DHR12R1;      /*!< DAC channel1 12-bit right-aligned data holding register,  Address offset: 0x08 */
  __IO uint32_t DHR12L1;      /*!< DAC channel1 12-bit left aligned data holding register,   Address offset: 0x0C */
  __IO uint32_t DHR8R1;       /*!< DAC channel1 8-bit right aligned data holding register,   Address offset: 0x10 */
  __IO uint32_t DHR12R2;      /*!< DAC channel2 12-bit right aligned data holding register,  Address offset: 0x14 */
  __IO uint32_t DHR12L2;      /*!< DAC channel2 12-bit left aligned data holding register,   Address offset: 0x18 */
  __IO uint32_t DHR8R2;       /*!< DAC channel2 8-bit right-aligned data holding register,   Address offset: 0x1C */
  __IO uint32_t DHR12RD;      /*!< Dual DAC 12-bit right-aligned data holding register,      Address offset: 0x20 */
  __IO uint32_t DHR12LD;      /*!< DUAL DAC 12-bit left aligned data holding register,       Address offset: 0x24 */
  __IO uint32_t DHR8RD;       /*!< DUAL DAC 8-bit right aligned data holding register,       Address offset: 0x28 */
  __IO uint32_t DOR1;         /*!< DAC channel1 data output register,                        Address offset: 0x2C */
  __IO uint32_t DOR2;         /*!< DAC channel2 data output register,                        Address offset: 0x30 */
  __IO uint32_t SR;           /*!< DAC status register,                                      Address offset: 0x34 */
} DAC_TypeDef;

/**
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;       /*!< MCU device ID code,                          Address offset: 0x00 */
  __IO uint32_t CR;           /*!< Debug MCU configuration register,            Address offset: 0x04 */
  __IO uint32_t APB1FZ;       /*!< Debug MCU APB1 freeze register,              Address offset: 0x08 */
  __IO uint32_t APB2FZ;       /*!< Debug MCU APB2 freeze register,              Address offset: 0x0C */
}DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;          /*!< DMA channel x configuration register        */
  __IO uint32_t CNDTR;        /*!< DMA channel x number of data register       */
  __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register   */
  __IO uint32_t CMAR;         /*!< DMA channel x memory address register       */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;          /*!< DMA interrupt status register,               Address offset: 0x00 */
  __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register,           Address offset: 0x04 */
  uint32_t RESERVED0[40];     /*!< Reserved as declared by channel typedef      0x08 - 0xA4          */
  __IO uint32_t CSELR;        /*!< Channel selection register,  RMPCR           Address offset: 0xA8 */
} DMA_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR;          /*!<EXTI Interrupt mask register,                 Address offset: 0x00 */
  __IO uint32_t EMR;          /*!<EXTI Event mask register,                     Address offset: 0x04 */
  __IO uint32_t RTSR;         /*!<EXTI Rising trigger selection register ,      Address offset: 0x08 */
  __IO uint32_t FTSR;         /*!<EXTI Falling trigger selection register,      Address offset: 0x0C */
  __IO uint32_t SWIER;        /*!<EXTI Software interrupt event register,       Address offset: 0x10 */
  __IO uint32_t PR;           /*!<EXTI Pending register,                        Address offset: 0x14 */
} EXTI_TypeDef;

/**
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t ACR;          /*!<FLASH access control register,                 Address offset: 0x00 */
  __IO uint32_t KEYR;         /*!<FLASH key register,                            Address offset: 0x04 */
  __IO uint32_t OPTKEYR;      /*!<FLASH OPT key register,                        Address offset: 0x08 */
  __IO uint32_t SR;           /*!<FLASH status register,                         Address offset: 0x0C */
  __IO uint32_t CR;           /*!<FLASH control register,                        Address offset: 0x10 */
  __IO uint32_t AR;           /*!<FLASH address register,                        Address offset: 0x14 */
  __IO uint32_t RESERVED;     /*!< Reserved,                                                     0x18 */
  __IO uint32_t OBR;          /*!<FLASH option bytes register,                   Address offset: 0x1C */
  __IO uint32_t WRPR;         /*!<FLASH option bytes register,                   Address offset: 0x20 */
} FLASH_TypeDef;

/**
  * @brief Option Bytes Registers
  */
typedef struct
{
  __IO uint16_t RDP;          /*!< FLASH option byte Read protection,             Address offset: 0x00 */
  __IO uint16_t USER;         /*!< FLASH option byte user options,                Address offset: 0x02 */
  __IO uint16_t DATA0;        /*!< User data byte 0 (stored in FLASH_OBR[23:16]), Address offset: 0x04 */
  __IO uint16_t DATA1;        /*!< User data byte 1 (stored in FLASH_OBR[31:24]), Address offset: 0x06 */
  __IO uint16_t WRP0;         /*!< FLASH option byte write protection 0,          Address offset: 0x08 */
  __IO uint16_t WRP1;         /*!< FLASH option byte write protection 1,          Address offset: 0x0A */
  __IO uint16_t WRP2;         /*!< FLASH option byte write protection 2,          Address offset: 0x0C */
  __IO uint16_t WRP3;         /*!< FLASH option byte write protection 3,          Address offset: 0x0E */
} OB_TypeDef;

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t MODER;        /*!< GPIO port mode register,                     Address offset: 0x00      */
  __IO uint32_t OTYPER;       /*!< GPIO port output type register,              Address offset: 0x04      */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,             Address offset: 0x08      */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C      */
  __IO uint32_t IDR;          /*!< GPIO port input data register,               Address offset: 0x10      */
  __IO uint32_t ODR;          /*!< GPIO port output data register,              Address offset: 0x14      */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset register,      Address offset: 0x1A */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,       Address offset: 0x1C      */
  __IO uint32_t AFR[2];       /*!< GPIO alternate function low register,  Address offset: 0x20-0x24 */
  __IO uint32_t BRR;          /*!< GPIO bit reset register,                     Address offset: 0x28      */
} GPIO_TypeDef;

/**
  * @brief SysTem Configuration
  */

typedef struct
{
  __IO uint32_t CFGR1;       /*!< SYSCFG configuration register 1,                           Address offset: 0x00 */
       uint32_t RESERVED;    /*!< Reserved,                                                                  0x04 */
  __IO uint32_t EXTICR[4];   /*!< SYSCFG external interrupt configuration register,     Address offset: 0x14-0x08 */
  __IO uint32_t CFGR2;       /*!< SYSCFG configuration register 2,                           Address offset: 0x18 */
       uint32_t RESERVED1[25];    /*!< Reserved + COMP,                                                      0x1C */
  __IO uint32_t IT_LINE_SR[32]; /*!< SYSCFG configuration IT_LINE register,                  Address offset: 0x80 */
} SYSCFG_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;          /*!< I2C Control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< I2C Control register 2,                      Address offset: 0x04 */
  __IO uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __IO uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
  __IO uint32_t WINR; /*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;

/**
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,                          Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register,                   Address offset: 0x04 */
} PWR_TypeDef;

/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                   Address offset: 0x00 */
  __IO uint32_t CFGR;       /*!< RCC clock configuration register,                            Address offset: 0x04 */
  __IO uint32_t CIR;        /*!< RCC clock interrupt register,                                Address offset: 0x08 */
  __IO uint32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
  __IO uint32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
  __IO uint32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
  __IO uint32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
  __IO uint32_t BDCR;       /*!< RCC Backup domain control register,                          Address offset: 0x20 */
  __IO uint32_t CSR;        /*!< RCC clock control & status register,                         Address offset: 0x24 */
  __IO uint32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
  __IO uint32_t CFGR2;      /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
  __IO uint32_t CFGR3;      /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
  __IO uint32_t CR2;        /*!< RCC clock control register 2,                                Address offset: 0x34 */
} RCC_TypeDef;

/**
  * @brief Real-Time Clock
  */
typedef struct
{
  __IO uint32_t TR;         /*!< RTC time register,                                         Address offset: 0x00 */
  __IO uint32_t DR;         /*!< RTC date register,                                         Address offset: 0x04 */
  __IO uint32_t CR;         /*!< RTC control register,                                      Address offset: 0x08 */
  __IO uint32_t ISR;        /*!< RTC initialization and status register,                    Address offset: 0x0C */
  __IO uint32_t PRER;       /*!< RTC prescaler register,                                    Address offset: 0x10 */
  __IO uint32_t WUTR;       /*!< RTC wakeup timer register,                                 Address offset: 0x14 */
       uint32_t RESERVED1;  /*!< Reserved,                                                  Address offset: 0x18 */
  __IO uint32_t ALRMAR;     /*!< RTC alarm A register,                                      Address offset: 0x1C */
       uint32_t RESERVED2;  /*!< Reserved,                                                  Address offset: 0x20 */
  __IO uint32_t WPR;        /*!< RTC write protection register,                             Address offset: 0x24 */
  __IO uint32_t SSR;        /*!< RTC sub second register,                                   Address offset: 0x28 */
  __IO uint32_t SHIFTR;     /*!< RTC shift control register,                                Address offset: 0x2C */
  __IO uint32_t TSTR;       /*!< RTC time stamp time register,                              Address offset: 0x30 */
  __IO uint32_t TSDR;       /*!< RTC time stamp date register,                              Address offset: 0x34 */
  __IO uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
  __IO uint32_t CALR;       /*!< RTC calibration register,                                  Address offset: 0x3C */
  __IO uint32_t TAFCR;      /*!< RTC tamper and alternate function configuration register,  Address offset: 0x40 */
  __IO uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
       uint32_t RESERVED3;  /*!< Reserved,                                                  Address offset: 0x48 */
       uint32_t RESERVED4;  /*!< Reserved,                                                  Address offset: 0x4C */
  __IO uint32_t BKP0R;      /*!< RTC backup register 0,                                     Address offset: 0x50 */
  __IO uint32_t BKP1R;      /*!< RTC backup register 1,                                     Address offset: 0x54 */
  __IO uint32_t BKP2R;      /*!< RTC backup register 2,                                     Address offset: 0x58 */
  __IO uint32_t BKP3R;      /*!< RTC backup register 3,                                     Address offset: 0x5C */
  __IO uint32_t BKP4R;      /*!< RTC backup register 4,                                     Address offset: 0x60 */
} RTC_TypeDef;

/**
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;        /*!< SPI Control register 1 (not used in I2S mode),      Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< SPI Control register 2,                             Address offset: 0x04 */
  __IO uint32_t SR;         /*!< SPI Status register,                                Address offset: 0x08 */
  __IO uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
  __IO uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  __IO uint32_t RXCRCR;     /*!< SPI Rx CRC register (not used in I2S mode),         Address offset: 0x14 */
  __IO uint32_t TXCRCR;     /*!< SPI Tx CRC register (not used in I2S mode),         Address offset: 0x18 */
  __IO uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  __IO uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
  __IO uint32_t CR1;          /*!< TIM control register 1,              Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< TIM control register 2,              Address offset: 0x04 */
  __IO uint32_t SMCR;         /*!< TIM slave Mode Control register,     Address offset: 0x08 */
  __IO uint32_t DIER;         /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t SR;           /*!< TIM status register,                 Address offset: 0x10 */
  __IO uint32_t EGR;          /*!< TIM event generation register,       Address offset: 0x14 */
  __IO uint32_t CCMR1;        /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO uint32_t CCMR2;        /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO uint32_t CCER;         /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO uint32_t CNT;          /*!< TIM counter register,                Address offset: 0x24 */
  __IO uint32_t PSC;          /*!< TIM prescaler register,              Address offset: 0x28 */
  __IO uint32_t ARR;          /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO uint32_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO uint32_t CCR3;         /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO uint32_t CCR4;         /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO uint32_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO uint32_t DMAR;            /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
  __IO uint32_t OR;           /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;

/**
  * @brief Touch Sensing Controller (TSC)
  */
typedef struct
{
  __IO uint32_t CR;        /*!< TSC control register,                                     Address offset: 0x00 */
  __IO uint32_t IER;       /*!< TSC interrupt enable register,                            Address offset: 0x04 */
  __IO uint32_t ICR;       /*!< TSC interrupt clear register,                             Address offset: 0x08 */
  __IO uint32_t ISR;       /*!< TSC interrupt status register,                            Address offset: 0x0C */
  __IO uint32_t IOHCR;     /*!< TSC I/O hysteresis control register,                      Address offset: 0x10 */
       uint32_t RESERVED1; /*!< Reserved,                                                 Address offset: 0x14 */
  __IO uint32_t IOASCR;    /*!< TSC I/O analog switch control register,                   Address offset: 0x18 */
       uint32_t RESERVED2; /*!< Reserved,                                                 Address offset: 0x1C */
  __IO uint32_t IOSCR;     /*!< TSC I/O sampling control register,                        Address offset: 0x20 */
       uint32_t RESERVED3; /*!< Reserved,                                                 Address offset: 0x24 */
  __IO uint32_t IOCCR;     /*!< TSC I/O channel control register,                         Address offset: 0x28 */
       uint32_t RESERVED4; /*!< Reserved,                                                 Address offset: 0x2C */
  __IO uint32_t IOGCSR;    /*!< TSC I/O group control status register,                    Address offset: 0x30 */
  __IO uint32_t IOGXCR[8]; /*!< TSC I/O group x counter register,                         Address offset: 0x34-50 */
}TSC_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */

typedef struct
{
  __IO uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */
  __IO uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */
  __IO uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
  __IO uint32_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
  __IO uint32_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  __IO uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */
  __IO uint32_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
  __IO uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
  __IO uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  __IO uint16_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
  uint16_t  RESERVED1;  /*!< Reserved, 0x26                                                 */
  __IO uint16_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
  uint16_t  RESERVED2;  /*!< Reserved, 0x2A                                                 */
} USART_TypeDef;


/**
  * @brief Universal Serial Bus Full Speed Device
  */

typedef struct
{
  __IO uint16_t EP0R;            /*!< USB Endpoint 0 register,                Address offset: 0x00 */
  __IO uint16_t RESERVED0;       /*!< Reserved */
  __IO uint16_t EP1R;            /*!< USB Endpoint 1 register,                Address offset: 0x04 */
  __IO uint16_t RESERVED1;       /*!< Reserved */
  __IO uint16_t EP2R;            /*!< USB Endpoint 2 register,                Address offset: 0x08 */
  __IO uint16_t RESERVED2;       /*!< Reserved */
  __IO uint16_t EP3R;            /*!< USB Endpoint 3 register,                Address offset: 0x0C */
  __IO uint16_t RESERVED3;       /*!< Reserved */
  __IO uint16_t EP4R;            /*!< USB Endpoint 4 register,                Address offset: 0x10 */
  __IO uint16_t RESERVED4;       /*!< Reserved */
  __IO uint16_t EP5R;            /*!< USB Endpoint 5 register,                Address offset: 0x14 */
  __IO uint16_t RESERVED5;       /*!< Reserved */
  __IO uint16_t EP6R;            /*!< USB Endpoint 6 register,                Address offset: 0x18 */
  __IO uint16_t RESERVED6;       /*!< Reserved */
  __IO uint16_t EP7R;            /*!< USB Endpoint 7 register,                Address offset: 0x1C */
  __IO uint16_t RESERVED7[17];   /*!< Reserved */
  __IO uint16_t CNTR;            /*!< Control register,                       Address offset: 0x40 */
  __IO uint16_t RESERVED8;       /*!< Reserved */
  __IO uint16_t ISTR;            /*!< Interrupt status register,              Address offset: 0x44 */
  __IO uint16_t RESERVED9;       /*!< Reserved */
  __IO uint16_t FNR;             /*!< Frame number register,                  Address offset: 0x48 */
  __IO uint16_t RESERVEDA;       /*!< Reserved */
  __IO uint16_t DADDR;           /*!< Device address register,                Address offset: 0x4C */
  __IO uint16_t RESERVEDB;       /*!< Reserved */
  __IO uint16_t BTABLE;          /*!< Buffer Table address register,          Address offset: 0x50 */
  __IO uint16_t RESERVEDC;       /*!< Reserved */
  __IO uint16_t LPMCSR;          /*!< LPM Control and Status register,        Address offset: 0x54 */
  __IO uint16_t RESERVEDD;       /*!< Reserved */
  __IO uint16_t BCDR;            /*!< Battery Charging detector register,     Address offset: 0x58 */
  __IO uint16_t RESERVEDE;       /*!< Reserved */
} USB_TypeDef;

/**
  * @brief Window WATCHDOG
  */
typedef struct
{
  __IO uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;

/**
  * @}
  */


/******  FLASH base and end address Definition *****************************************************************/
#if defined(STM32F030x6)
#define FLASH_BANK1_END       ((uint32_t)0x08007FFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x8000)      /*!< FLASH Size of bank1 */
#elif defined(STM32F030x8)
#define FLASH_BANK1_END       ((uint32_t)0x0800FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x10000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F030xC)
#define FLASH_BANK1_END       ((uint32_t)0x0803FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x40000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F031x6)
#define FLASH_BANK1_END       ((uint32_t)0x08007FFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x8000)      /*!< FLASH Size of bank1 */
#elif defined(STM32F038xx)
#define FLASH_BANK1_END       ((uint32_t)0x08007FFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x8000)      /*!< FLASH Size of bank1 */
#elif defined(STM32F042x6)
#define FLASH_BANK1_END       ((uint32_t)0x08007FFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x8000)      /*!< FLASH Size of bank1 */
#elif defined(STM32F048xx)
#define FLASH_BANK1_END       ((uint32_t)0x08007FFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x8000)      /*!< FLASH Size of bank1 */
#elif defined(STM32F051x8)
#define FLASH_BANK1_END       ((uint32_t)0x0800FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x10000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F058xx)
#define FLASH_BANK1_END       ((uint32_t)0x0800FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x10000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F070x6)
#define FLASH_BANK1_END       ((uint32_t)0x08007FFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x8000)      /*!< FLASH Size of bank1 */
#elif defined(STM32F070xB)
#define FLASH_BANK1_END       ((uint32_t)0x0801FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x20000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F071xB)
#define FLASH_BANK1_END       ((uint32_t)0x0801FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x20000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F072xB)
#define FLASH_BANK1_END       ((uint32_t)0x0801FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x20000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F078xx)
#define FLASH_BANK1_END       ((uint32_t)0x0801FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x20000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F091xC)
#define FLASH_BANK1_END       ((uint32_t)0x0803FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x40000)     /*!< FLASH Size of bank1 */
#elif defined(STM32F098xx)
#define FLASH_BANK1_END       ((uint32_t)0x0803FFFFU) /*!< FLASH END address of bank1 */
#define FLASH_SIZE            ((uint32_t)0x40000)     /*!< FLASH Size of bank1 */
#endif

#define FLASH_BASE            ((uint32_t)0x08000000U)              /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((uint32_t)0x20000000U)              /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000U)              /*!< Peripheral base address in the alias region */

/*!< Peripheral memory map */
#define APBPERIPH_BASE        PERIPH_BASE
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)

/*!< APB peripherals */
#define TIM2_BASE             (APBPERIPH_BASE + 0x00000000)
#define TIM3_BASE             (APBPERIPH_BASE + 0x00000400)
#define TIM6_BASE             (APBPERIPH_BASE + 0x00001000)
#define TIM7_BASE             (APBPERIPH_BASE + 0x00001400)
#define TIM14_BASE            (APBPERIPH_BASE + 0x00002000)
#define RTC_BASE              (APBPERIPH_BASE + 0x00002800)
#define WWDG_BASE             (APBPERIPH_BASE + 0x00002C00)
#define IWDG_BASE             (APBPERIPH_BASE + 0x00003000)
#define SPI2_BASE             (APBPERIPH_BASE + 0x00003800)
#define USART2_BASE           (APBPERIPH_BASE + 0x00004400)
#define USART3_BASE           (APBPERIPH_BASE + 0x00004800)
#define USART4_BASE           (APBPERIPH_BASE + 0x00004C00)
#define USART5_BASE           (APBPERIPH_BASE + 0x00005000)
#define I2C1_BASE             (APBPERIPH_BASE + 0x00005400)
#define I2C2_BASE             (APBPERIPH_BASE + 0x00005800)
#define USB_BASE              (APBPERIPH_BASE + 0x00005C00) /*!< USB_IP Peripheral Registers base address */
#define USB_PMAADDR           (APBPERIPH_BASE + 0x00006000) /*!< USB_IP Packet Memory Area base address */
#define CAN_BASE              (APBPERIPH_BASE + 0x00006400)
#define CRS_BASE              (APBPERIPH_BASE + 0x00006C00)
#define PWR_BASE              (APBPERIPH_BASE + 0x00007000)
#define DAC_BASE              (APBPERIPH_BASE + 0x00007400)

#define CEC_BASE              (APBPERIPH_BASE + 0x00007800)

#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00010000)
#define COMP_BASE             (APBPERIPH_BASE + 0x0001001C)
#define EXTI_BASE             (APBPERIPH_BASE + 0x00010400)
#define USART6_BASE           (APBPERIPH_BASE + 0x00011400)
#define USART7_BASE           (APBPERIPH_BASE + 0x00011800)
#define USART8_BASE           (APBPERIPH_BASE + 0x00011C00)
#define ADC1_BASE             (APBPERIPH_BASE + 0x00012400)
#define ADC_BASE              (APBPERIPH_BASE + 0x00012708)
#define TIM1_BASE             (APBPERIPH_BASE + 0x00012C00)
#define SPI1_BASE             (APBPERIPH_BASE + 0x00013000)
#define USART1_BASE           (APBPERIPH_BASE + 0x00013800)
#define TIM15_BASE            (APBPERIPH_BASE + 0x00014000)
#define TIM16_BASE            (APBPERIPH_BASE + 0x00014400)
#define TIM17_BASE            (APBPERIPH_BASE + 0x00014800)
#define DBGMCU_BASE           (APBPERIPH_BASE + 0x00015800)

/*!< AHB peripherals */
#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000)
#define DMA1_Channel1_BASE    (DMA1_BASE + 0x00000008)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x0000001C)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x00000030)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x00000044)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x00000058)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x0000006C)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x00000080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x00000400)
#define DMA2_Channel1_BASE    (DMA2_BASE + 0x00000008)
#define DMA2_Channel2_BASE    (DMA2_BASE + 0x0000001C)
#define DMA2_Channel3_BASE    (DMA2_BASE + 0x00000030)
#define DMA2_Channel4_BASE    (DMA2_BASE + 0x00000044)
#define DMA2_Channel5_BASE    (DMA2_BASE + 0x00000058)

#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000) /*!< FLASH registers base address */
#define OB_BASE               ((uint32_t)0x1FFFF800U)       /*!< FLASH Option Bytes base address */
#define FLASHSIZE_BASE        ((uint32_t)0x1FFFF7CCU)       /*!< FLASH Size register base address */
#define UID_BASE              ((uint32_t)0x1FFFF7ACU)       /*!< Unique device ID register base address */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000)
#define TSC_BASE              (AHBPERIPH_BASE + 0x00004000)

/*!< AHB2 peripherals */
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x00001000)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define USART4              ((USART_TypeDef *) USART4_BASE)
#define USART5              ((USART_TypeDef *) USART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define CAN                 ((CAN_TypeDef *) CAN_BASE)
#define CRS                 ((CRS_TypeDef *) CRS_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC1                ((DAC_TypeDef *) DAC_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE) /* Kept for legacy purpose */
#define CEC                 ((CEC_TypeDef *) CEC_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define COMP1               ((COMP_TypeDef *) COMP_BASE)
#define COMP2               ((COMP_TypeDef *) (COMP_BASE + 0x00000002))
#define COMP12_COMMON       ((COMP_Common_TypeDef *) COMP_BASE)
#define COMP                ((COMP1_2_TypeDef *) COMP_BASE) /* Kept for legacy purpose */
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define USART6              ((USART_TypeDef *) USART6_BASE)
#define USART7              ((USART_TypeDef *) USART7_BASE)
#define USART8              ((USART_TypeDef *) USART8_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC1_COMMON         ((ADC_Common_TypeDef *) ADC_BASE)
#define ADC                 ((ADC_Common_TypeDef *) ADC_BASE) /* Kept for legacy purpose */
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define TSC                 ((TSC_TypeDef *) TSC_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define USB                 ((USB_TypeDef *) USB_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F0 serie)
 */
#define ADC_CHANNEL_VBAT_SUPPORT                       /*!< ADC feature available only on specific devices: ADC internal channel Vbat */

/********************  Bits definition for ADC_ISR register  ******************/
#define ADC_ISR_ADRDY_Pos         (0U)
#define ADC_ISR_ADRDY_Msk         (0x1U << ADC_ISR_ADRDY_Pos)                  /*!< 0x00000001 */
#define ADC_ISR_ADRDY             ADC_ISR_ADRDY_Msk                            /*!< ADC ready flag */
#define ADC_ISR_EOSMP_Pos         (1U)
#define ADC_ISR_EOSMP_Msk         (0x1U << ADC_ISR_EOSMP_Pos)                  /*!< 0x00000002 */
#define ADC_ISR_EOSMP             ADC_ISR_EOSMP_Msk                            /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC_Pos           (2U)
#define ADC_ISR_EOC_Msk           (0x1U << ADC_ISR_EOC_Pos)                    /*!< 0x00000004 */
#define ADC_ISR_EOC               ADC_ISR_EOC_Msk                              /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS_Pos           (3U)
#define ADC_ISR_EOS_Msk           (0x1U << ADC_ISR_EOS_Pos)                    /*!< 0x00000008 */
#define ADC_ISR_EOS               ADC_ISR_EOS_Msk                              /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR_Pos           (4U)
#define ADC_ISR_OVR_Msk           (0x1U << ADC_ISR_OVR_Pos)                    /*!< 0x00000010 */
#define ADC_ISR_OVR               ADC_ISR_OVR_Msk                              /*!< ADC group regular overrun flag */
#define ADC_ISR_AWD1_Pos          (7U)
#define ADC_ISR_AWD1_Msk          (0x1U << ADC_ISR_AWD1_Pos)                   /*!< 0x00000080 */
#define ADC_ISR_AWD1              ADC_ISR_AWD1_Msk                             /*!< ADC analog watchdog 1 flag */

/* Legacy defines */
#define ADC_ISR_AWD             (ADC_ISR_AWD1)
#define ADC_ISR_EOSEQ           (ADC_ISR_EOS)

/********************  Bits definition for ADC_IER register  ******************/
#define ADC_IER_ADRDYIE_Pos       (0U)
#define ADC_IER_ADRDYIE_Msk       (0x1U << ADC_IER_ADRDYIE_Pos)                /*!< 0x00000001 */
#define ADC_IER_ADRDYIE           ADC_IER_ADRDYIE_Msk                          /*!< ADC ready interrupt */
#define ADC_IER_EOSMPIE_Pos       (1U)
#define ADC_IER_EOSMPIE_Msk       (0x1U << ADC_IER_EOSMPIE_Pos)                /*!< 0x00000002 */
#define ADC_IER_EOSMPIE           ADC_IER_EOSMPIE_Msk                          /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE_Pos         (2U)
#define ADC_IER_EOCIE_Msk         (0x1U << ADC_IER_EOCIE_Pos)                  /*!< 0x00000004 */
#define ADC_IER_EOCIE             ADC_IER_EOCIE_Msk                            /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE_Pos         (3U)
#define ADC_IER_EOSIE_Msk         (0x1U << ADC_IER_EOSIE_Pos)                  /*!< 0x00000008 */
#define ADC_IER_EOSIE             ADC_IER_EOSIE_Msk                            /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE_Pos         (4U)
#define ADC_IER_OVRIE_Msk         (0x1U << ADC_IER_OVRIE_Pos)                  /*!< 0x00000010 */
#define ADC_IER_OVRIE             ADC_IER_OVRIE_Msk                            /*!< ADC group regular overrun interrupt */
#define ADC_IER_AWD1IE_Pos        (7U)
#define ADC_IER_AWD1IE_Msk        (0x1U << ADC_IER_AWD1IE_Pos)                 /*!< 0x00000080 */
#define ADC_IER_AWD1IE            ADC_IER_AWD1IE_Msk                           /*!< ADC analog watchdog 1 interrupt */

/* Legacy defines */
#define ADC_IER_AWDIE           (ADC_IER_AWD1IE)
#define ADC_IER_EOSEQIE         (ADC_IER_EOSIE)

/********************  Bits definition for ADC_CR register  *******************/
#define ADC_CR_ADEN_Pos           (0U)
#define ADC_CR_ADEN_Msk           (0x1U << ADC_CR_ADEN_Pos)                    /*!< 0x00000001 */
#define ADC_CR_ADEN               ADC_CR_ADEN_Msk                              /*!< ADC enable */
#define ADC_CR_ADDIS_Pos          (1U)
#define ADC_CR_ADDIS_Msk          (0x1U << ADC_CR_ADDIS_Pos)                   /*!< 0x00000002 */
#define ADC_CR_ADDIS              ADC_CR_ADDIS_Msk                             /*!< ADC disable */
#define ADC_CR_ADSTART_Pos        (2U)
#define ADC_CR_ADSTART_Msk        (0x1U << ADC_CR_ADSTART_Pos)                 /*!< 0x00000004 */
#define ADC_CR_ADSTART            ADC_CR_ADSTART_Msk                           /*!< ADC group regular conversion start */
#define ADC_CR_ADSTP_Pos          (4U)
#define ADC_CR_ADSTP_Msk          (0x1U << ADC_CR_ADSTP_Pos)                   /*!< 0x00000010 */
#define ADC_CR_ADSTP              ADC_CR_ADSTP_Msk                             /*!< ADC group regular conversion stop */
#define ADC_CR_ADCAL_Pos          (31U)
#define ADC_CR_ADCAL_Msk          (0x1U << ADC_CR_ADCAL_Pos)                   /*!< 0x80000000 */
#define ADC_CR_ADCAL              ADC_CR_ADCAL_Msk                             /*!< ADC calibration */

/*******************  Bits definition for ADC_CFGR1 register  *****************/
#define ADC_CFGR1_DMAEN_Pos       (0U)
#define ADC_CFGR1_DMAEN_Msk       (0x1U << ADC_CFGR1_DMAEN_Pos)                /*!< 0x00000001 */
#define ADC_CFGR1_DMAEN           ADC_CFGR1_DMAEN_Msk                          /*!< ADC DMA transfer enable */
#define ADC_CFGR1_DMACFG_Pos      (1U)
#define ADC_CFGR1_DMACFG_Msk      (0x1U << ADC_CFGR1_DMACFG_Pos)               /*!< 0x00000002 */
#define ADC_CFGR1_DMACFG          ADC_CFGR1_DMACFG_Msk                         /*!< ADC DMA transfer configuration */
#define ADC_CFGR1_SCANDIR_Pos     (2U)
#define ADC_CFGR1_SCANDIR_Msk     (0x1U << ADC_CFGR1_SCANDIR_Pos)              /*!< 0x00000004 */
#define ADC_CFGR1_SCANDIR         ADC_CFGR1_SCANDIR_Msk                        /*!< ADC group regular sequencer scan direction */

#define ADC_CFGR1_RES_Pos         (3U)
#define ADC_CFGR1_RES_Msk         (0x3U << ADC_CFGR1_RES_Pos)                  /*!< 0x00000018 */
#define ADC_CFGR1_RES             ADC_CFGR1_RES_Msk                            /*!< ADC data resolution */
#define ADC_CFGR1_RES_0           (0x1U << ADC_CFGR1_RES_Pos)                  /*!< 0x00000008 */
#define ADC_CFGR1_RES_1           (0x2U << ADC_CFGR1_RES_Pos)                  /*!< 0x00000010 */

#define ADC_CFGR1_ALIGN_Pos       (5U)
#define ADC_CFGR1_ALIGN_Msk       (0x1U << ADC_CFGR1_ALIGN_Pos)                /*!< 0x00000020 */
#define ADC_CFGR1_ALIGN           ADC_CFGR1_ALIGN_Msk                          /*!< ADC data alignement */

#define ADC_CFGR1_EXTSEL_Pos      (6U)
#define ADC_CFGR1_EXTSEL_Msk      (0x7U << ADC_CFGR1_EXTSEL_Pos)               /*!< 0x000001C0 */
#define ADC_CFGR1_EXTSEL          ADC_CFGR1_EXTSEL_Msk                         /*!< ADC group regular external trigger source */
#define ADC_CFGR1_EXTSEL_0        (0x1U << ADC_CFGR1_EXTSEL_Pos)               /*!< 0x00000040 */
#define ADC_CFGR1_EXTSEL_1        (0x2U << ADC_CFGR1_EXTSEL_Pos)               /*!< 0x00000080 */
#define ADC_CFGR1_EXTSEL_2        (0x4U << ADC_CFGR1_EXTSEL_Pos)               /*!< 0x00000100 */

#define ADC_CFGR1_EXTEN_Pos       (10U)
#define ADC_CFGR1_EXTEN_Msk       (0x3U << ADC_CFGR1_EXTEN_Pos)                /*!< 0x00000C00 */
#define ADC_CFGR1_EXTEN           ADC_CFGR1_EXTEN_Msk                          /*!< ADC group regular external trigger polarity */
#define ADC_CFGR1_EXTEN_0         (0x1U << ADC_CFGR1_EXTEN_Pos)                /*!< 0x00000400 */
#define ADC_CFGR1_EXTEN_1         (0x2U << ADC_CFGR1_EXTEN_Pos)                /*!< 0x00000800 */

#define ADC_CFGR1_OVRMOD_Pos      (12U)
#define ADC_CFGR1_OVRMOD_Msk      (0x1U << ADC_CFGR1_OVRMOD_Pos)               /*!< 0x00001000 */
#define ADC_CFGR1_OVRMOD          ADC_CFGR1_OVRMOD_Msk                         /*!< ADC group regular overrun configuration */
#define ADC_CFGR1_CONT_Pos        (13U)
#define ADC_CFGR1_CONT_Msk        (0x1U << ADC_CFGR1_CONT_Pos)                 /*!< 0x00002000 */
#define ADC_CFGR1_CONT            ADC_CFGR1_CONT_Msk                           /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR1_WAIT_Pos        (14U)
#define ADC_CFGR1_WAIT_Msk        (0x1U << ADC_CFGR1_WAIT_Pos)                 /*!< 0x00004000 */
#define ADC_CFGR1_WAIT            ADC_CFGR1_WAIT_Msk                           /*!< ADC low power auto wait */
#define ADC_CFGR1_AUTOFF_Pos      (15U)
#define ADC_CFGR1_AUTOFF_Msk      (0x1U << ADC_CFGR1_AUTOFF_Pos)               /*!< 0x00008000 */
#define ADC_CFGR1_AUTOFF          ADC_CFGR1_AUTOFF_Msk                         /*!< ADC low power auto power off */
#define ADC_CFGR1_DISCEN_Pos      (16U)
#define ADC_CFGR1_DISCEN_Msk      (0x1U << ADC_CFGR1_DISCEN_Pos)               /*!< 0x00010000 */
#define ADC_CFGR1_DISCEN          ADC_CFGR1_DISCEN_Msk                         /*!< ADC group regular sequencer discontinuous mode */

#define ADC_CFGR1_AWD1SGL_Pos     (22U)
#define ADC_CFGR1_AWD1SGL_Msk     (0x1U << ADC_CFGR1_AWD1SGL_Pos)              /*!< 0x00400000 */
#define ADC_CFGR1_AWD1SGL         ADC_CFGR1_AWD1SGL_Msk                        /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CFGR1_AWD1EN_Pos      (23U)
#define ADC_CFGR1_AWD1EN_Msk      (0x1U << ADC_CFGR1_AWD1EN_Pos)               /*!< 0x00800000 */
#define ADC_CFGR1_AWD1EN          ADC_CFGR1_AWD1EN_Msk                         /*!< ADC analog watchdog 1 enable on scope ADC group regular */

#define ADC_CFGR1_AWD1CH_Pos      (26U)
#define ADC_CFGR1_AWD1CH_Msk      (0x1FU << ADC_CFGR1_AWD1CH_Pos)              /*!< 0x7C000000 */
#define ADC_CFGR1_AWD1CH          ADC_CFGR1_AWD1CH_Msk                         /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CFGR1_AWD1CH_0        (0x01U << ADC_CFGR1_AWD1CH_Pos)              /*!< 0x04000000 */
#define ADC_CFGR1_AWD1CH_1        (0x02U << ADC_CFGR1_AWD1CH_Pos)              /*!< 0x08000000 */
#define ADC_CFGR1_AWD1CH_2        (0x04U << ADC_CFGR1_AWD1CH_Pos)              /*!< 0x10000000 */
#define ADC_CFGR1_AWD1CH_3        (0x08U << ADC_CFGR1_AWD1CH_Pos)              /*!< 0x20000000 */
#define ADC_CFGR1_AWD1CH_4        (0x10U << ADC_CFGR1_AWD1CH_Pos)              /*!< 0x40000000 */

/* Legacy defines */
#define ADC_CFGR1_AUTDLY        (ADC_CFGR1_WAIT)
#define ADC_CFGR1_AWDSGL        (ADC_CFGR1_AWD1SGL)
#define ADC_CFGR1_AWDEN         (ADC_CFGR1_AWD1EN)
#define ADC_CFGR1_AWDCH         (ADC_CFGR1_AWD1CH)
#define ADC_CFGR1_AWDCH_0       (ADC_CFGR1_AWD1CH_0)
#define ADC_CFGR1_AWDCH_1       (ADC_CFGR1_AWD1CH_1)
#define ADC_CFGR1_AWDCH_2       (ADC_CFGR1_AWD1CH_2)
#define ADC_CFGR1_AWDCH_3       (ADC_CFGR1_AWD1CH_3)
#define ADC_CFGR1_AWDCH_4       (ADC_CFGR1_AWD1CH_4)

/*******************  Bits definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_CKMODE_Pos      (30U)
#define ADC_CFGR2_CKMODE_Msk      (0x3U << ADC_CFGR2_CKMODE_Pos)               /*!< 0xC0000000 */
#define ADC_CFGR2_CKMODE          ADC_CFGR2_CKMODE_Msk                         /*!< ADC clock source and prescaler (prescaler only for clock source synchronous) */
#define ADC_CFGR2_CKMODE_1        (0x2U << ADC_CFGR2_CKMODE_Pos)               /*!< 0x80000000 */
#define ADC_CFGR2_CKMODE_0        (0x1U << ADC_CFGR2_CKMODE_Pos)               /*!< 0x40000000 */

/* Legacy defines */
#define  ADC_CFGR2_JITOFFDIV4   (ADC_CFGR2_CKMODE_1)   /*!< ADC clocked by PCLK div4 */
#define  ADC_CFGR2_JITOFFDIV2   (ADC_CFGR2_CKMODE_0)   /*!< ADC clocked by PCLK div2 */

/******************  Bit definition for ADC_SMPR register  ********************/
#define ADC_SMPR_SMP_Pos          (0U)
#define ADC_SMPR_SMP_Msk          (0x7U << ADC_SMPR_SMP_Pos)                   /*!< 0x00000007 */
#define ADC_SMPR_SMP              ADC_SMPR_SMP_Msk                             /*!< ADC group of channels sampling time 2 */
#define ADC_SMPR_SMP_0            (0x1U << ADC_SMPR_SMP_Pos)                   /*!< 0x00000001 */
#define ADC_SMPR_SMP_1            (0x2U << ADC_SMPR_SMP_Pos)                   /*!< 0x00000002 */
#define ADC_SMPR_SMP_2            (0x4U << ADC_SMPR_SMP_Pos)                   /*!< 0x00000004 */

/* Legacy defines */
#define  ADC_SMPR1_SMPR         (ADC_SMPR_SMP)         /*!< SMP[2:0] bits (Sampling time selection) */
#define  ADC_SMPR1_SMPR_0       (ADC_SMPR_SMP_0)       /*!< bit 0 */
#define  ADC_SMPR1_SMPR_1       (ADC_SMPR_SMP_1)       /*!< bit 1 */
#define  ADC_SMPR1_SMPR_2       (ADC_SMPR_SMP_2)       /*!< bit 2 */

/*******************  Bit definition for ADC_TR register  ********************/
#define ADC_TR1_LT1_Pos           (0U)
#define ADC_TR1_LT1_Msk           (0xFFFU << ADC_TR1_LT1_Pos)                  /*!< 0x00000FFF */
#define ADC_TR1_LT1               ADC_TR1_LT1_Msk                              /*!< ADC analog watchdog 1 threshold low */
#define ADC_TR1_LT1_0             (0x001U << ADC_TR1_LT1_Pos)                  /*!< 0x00000001 */
#define ADC_TR1_LT1_1             (0x002U << ADC_TR1_LT1_Pos)                  /*!< 0x00000002 */
#define ADC_TR1_LT1_2             (0x004U << ADC_TR1_LT1_Pos)                  /*!< 0x00000004 */
#define ADC_TR1_LT1_3             (0x008U << ADC_TR1_LT1_Pos)                  /*!< 0x00000008 */
#define ADC_TR1_LT1_4             (0x010U << ADC_TR1_LT1_Pos)                  /*!< 0x00000010 */
#define ADC_TR1_LT1_5             (0x020U << ADC_TR1_LT1_Pos)                  /*!< 0x00000020 */
#define ADC_TR1_LT1_6             (0x040U << ADC_TR1_LT1_Pos)                  /*!< 0x00000040 */
#define ADC_TR1_LT1_7             (0x080U << ADC_TR1_LT1_Pos)                  /*!< 0x00000080 */
#define ADC_TR1_LT1_8             (0x100U << ADC_TR1_LT1_Pos)                  /*!< 0x00000100 */
#define ADC_TR1_LT1_9             (0x200U << ADC_TR1_LT1_Pos)                  /*!< 0x00000200 */
#define ADC_TR1_LT1_10            (0x400U << ADC_TR1_LT1_Pos)                  /*!< 0x00000400 */
#define ADC_TR1_LT1_11            (0x800U << ADC_TR1_LT1_Pos)                  /*!< 0x00000800 */

#define ADC_TR1_HT1_Pos           (16U)
#define ADC_TR1_HT1_Msk           (0xFFFU << ADC_TR1_HT1_Pos)                  /*!< 0x0FFF0000 */
#define ADC_TR1_HT1               ADC_TR1_HT1_Msk                              /*!< ADC Analog watchdog 1 threshold high */
#define ADC_TR1_HT1_0             (0x001U << ADC_TR1_HT1_Pos)                  /*!< 0x00010000 */
#define ADC_TR1_HT1_1             (0x002U << ADC_TR1_HT1_Pos)                  /*!< 0x00020000 */
#define ADC_TR1_HT1_2             (0x004U << ADC_TR1_HT1_Pos)                  /*!< 0x00040000 */
#define ADC_TR1_HT1_3             (0x008U << ADC_TR1_HT1_Pos)                  /*!< 0x00080000 */
#define ADC_TR1_HT1_4             (0x010U << ADC_TR1_HT1_Pos)                  /*!< 0x00100000 */
#define ADC_TR1_HT1_5             (0x020U << ADC_TR1_HT1_Pos)                  /*!< 0x00200000 */
#define ADC_TR1_HT1_6             (0x040U << ADC_TR1_HT1_Pos)                  /*!< 0x00400000 */
#define ADC_TR1_HT1_7             (0x080U << ADC_TR1_HT1_Pos)                  /*!< 0x00800000 */
#define ADC_TR1_HT1_8             (0x100U << ADC_TR1_HT1_Pos)                  /*!< 0x01000000 */
#define ADC_TR1_HT1_9             (0x200U << ADC_TR1_HT1_Pos)                  /*!< 0x02000000 */
#define ADC_TR1_HT1_10            (0x400U << ADC_TR1_HT1_Pos)                  /*!< 0x04000000 */
#define ADC_TR1_HT1_11            (0x800U << ADC_TR1_HT1_Pos)                  /*!< 0x08000000 */

/* Legacy defines */
#define  ADC_TR_HT              (ADC_TR1_HT1)
#define  ADC_TR_LT              (ADC_TR1_LT1)
#define  ADC_HTR_HT             (ADC_TR1_HT1)
#define  ADC_LTR_LT             (ADC_TR1_LT1)

/******************  Bit definition for ADC_CHSELR register  ******************/
#define ADC_CHSELR_CHSEL_Pos      (0U)
#define ADC_CHSELR_CHSEL_Msk      (0x7FFFFU << ADC_CHSELR_CHSEL_Pos)           /*!< 0x0007FFFF */
#define ADC_CHSELR_CHSEL          ADC_CHSELR_CHSEL_Msk                         /*!< ADC group regular sequencer channels, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL18_Pos    (18U)
#define ADC_CHSELR_CHSEL18_Msk    (0x1U << ADC_CHSELR_CHSEL18_Pos)             /*!< 0x00040000 */
#define ADC_CHSELR_CHSEL18        ADC_CHSELR_CHSEL18_Msk                       /*!< ADC group regular sequencer channel 18, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL17_Pos    (17U)
#define ADC_CHSELR_CHSEL17_Msk    (0x1U << ADC_CHSELR_CHSEL17_Pos)             /*!< 0x00020000 */
#define ADC_CHSELR_CHSEL17        ADC_CHSELR_CHSEL17_Msk                       /*!< ADC group regular sequencer channel 17, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL16_Pos    (16U)
#define ADC_CHSELR_CHSEL16_Msk    (0x1U << ADC_CHSELR_CHSEL16_Pos)             /*!< 0x00010000 */
#define ADC_CHSELR_CHSEL16        ADC_CHSELR_CHSEL16_Msk                       /*!< ADC group regular sequencer channel 16, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL15_Pos    (15U)
#define ADC_CHSELR_CHSEL15_Msk    (0x1U << ADC_CHSELR_CHSEL15_Pos)             /*!< 0x00008000 */
#define ADC_CHSELR_CHSEL15        ADC_CHSELR_CHSEL15_Msk                       /*!< ADC group regular sequencer channel 15, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL14_Pos    (14U)
#define ADC_CHSELR_CHSEL14_Msk    (0x1U << ADC_CHSELR_CHSEL14_Pos)             /*!< 0x00004000 */
#define ADC_CHSELR_CHSEL14        ADC_CHSELR_CHSEL14_Msk                       /*!< ADC group regular sequencer channel 14, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL13_Pos    (13U)
#define ADC_CHSELR_CHSEL13_Msk    (0x1U << ADC_CHSELR_CHSEL13_Pos)             /*!< 0x00002000 */
#define ADC_CHSELR_CHSEL13        ADC_CHSELR_CHSEL13_Msk                       /*!< ADC group regular sequencer channel 13, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL12_Pos    (12U)
#define ADC_CHSELR_CHSEL12_Msk    (0x1U << ADC_CHSELR_CHSEL12_Pos)             /*!< 0x00001000 */
#define ADC_CHSELR_CHSEL12        ADC_CHSELR_CHSEL12_Msk                       /*!< ADC group regular sequencer channel 12, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL11_Pos    (11U)
#define ADC_CHSELR_CHSEL11_Msk    (0x1U << ADC_CHSELR_CHSEL11_Pos)             /*!< 0x00000800 */
#define ADC_CHSELR_CHSEL11        ADC_CHSELR_CHSEL11_Msk                       /*!< ADC group regular sequencer channel 11, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL10_Pos    (10U)
#define ADC_CHSELR_CHSEL10_Msk    (0x1U << ADC_CHSELR_CHSEL10_Pos)             /*!< 0x00000400 */
#define ADC_CHSELR_CHSEL10        ADC_CHSELR_CHSEL10_Msk                       /*!< ADC group regular sequencer channel 10, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL9_Pos     (9U)
#define ADC_CHSELR_CHSEL9_Msk     (0x1U << ADC_CHSELR_CHSEL9_Pos)              /*!< 0x00000200 */
#define ADC_CHSELR_CHSEL9         ADC_CHSELR_CHSEL9_Msk                        /*!< ADC group regular sequencer channel 9, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL8_Pos     (8U)
#define ADC_CHSELR_CHSEL8_Msk     (0x1U << ADC_CHSELR_CHSEL8_Pos)              /*!< 0x00000100 */
#define ADC_CHSELR_CHSEL8         ADC_CHSELR_CHSEL8_Msk                        /*!< ADC group regular sequencer channel 8, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL7_Pos     (7U)
#define ADC_CHSELR_CHSEL7_Msk     (0x1U << ADC_CHSELR_CHSEL7_Pos)              /*!< 0x00000080 */
#define ADC_CHSELR_CHSEL7         ADC_CHSELR_CHSEL7_Msk                        /*!< ADC group regular sequencer channel 7, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL6_Pos     (6U)
#define ADC_CHSELR_CHSEL6_Msk     (0x1U << ADC_CHSELR_CHSEL6_Pos)              /*!< 0x00000040 */
#define ADC_CHSELR_CHSEL6         ADC_CHSELR_CHSEL6_Msk                        /*!< ADC group regular sequencer channel 6, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL5_Pos     (5U)
#define ADC_CHSELR_CHSEL5_Msk     (0x1U << ADC_CHSELR_CHSEL5_Pos)              /*!< 0x00000020 */
#define ADC_CHSELR_CHSEL5         ADC_CHSELR_CHSEL5_Msk                        /*!< ADC group regular sequencer channel 5, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL4_Pos     (4U)
#define ADC_CHSELR_CHSEL4_Msk     (0x1U << ADC_CHSELR_CHSEL4_Pos)              /*!< 0x00000010 */
#define ADC_CHSELR_CHSEL4         ADC_CHSELR_CHSEL4_Msk                        /*!< ADC group regular sequencer channel 4, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL3_Pos     (3U)
#define ADC_CHSELR_CHSEL3_Msk     (0x1U << ADC_CHSELR_CHSEL3_Pos)              /*!< 0x00000008 */
#define ADC_CHSELR_CHSEL3         ADC_CHSELR_CHSEL3_Msk                        /*!< ADC group regular sequencer channel 3, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL2_Pos     (2U)
#define ADC_CHSELR_CHSEL2_Msk     (0x1U << ADC_CHSELR_CHSEL2_Pos)              /*!< 0x00000004 */
#define ADC_CHSELR_CHSEL2         ADC_CHSELR_CHSEL2_Msk                        /*!< ADC group regular sequencer channel 2, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL1_Pos     (1U)
#define ADC_CHSELR_CHSEL1_Msk     (0x1U << ADC_CHSELR_CHSEL1_Pos)              /*!< 0x00000002 */
#define ADC_CHSELR_CHSEL1         ADC_CHSELR_CHSEL1_Msk                        /*!< ADC group regular sequencer channel 1, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL0_Pos     (0U)
#define ADC_CHSELR_CHSEL0_Msk     (0x1U << ADC_CHSELR_CHSEL0_Pos)              /*!< 0x00000001 */
#define ADC_CHSELR_CHSEL0         ADC_CHSELR_CHSEL0_Msk                        /*!< ADC group regular sequencer channel 0, available when ADC_CFGR1_CHSELRMOD is reset */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos           (0U)
#define ADC_DR_DATA_Msk           (0xFFFFU << ADC_DR_DATA_Pos)                 /*!< 0x0000FFFF */
#define ADC_DR_DATA               ADC_DR_DATA_Msk                              /*!< ADC group regular conversion data */
#define ADC_DR_DATA_0             (0x0001U << ADC_DR_DATA_Pos)                 /*!< 0x00000001 */
#define ADC_DR_DATA_1             (0x0002U << ADC_DR_DATA_Pos)                 /*!< 0x00000002 */
#define ADC_DR_DATA_2             (0x0004U << ADC_DR_DATA_Pos)                 /*!< 0x00000004 */
#define ADC_DR_DATA_3             (0x0008U << ADC_DR_DATA_Pos)                 /*!< 0x00000008 */
#define ADC_DR_DATA_4             (0x0010U << ADC_DR_DATA_Pos)                 /*!< 0x00000010 */
#define ADC_DR_DATA_5             (0x0020U << ADC_DR_DATA_Pos)                 /*!< 0x00000020 */
#define ADC_DR_DATA_6             (0x0040U << ADC_DR_DATA_Pos)                 /*!< 0x00000040 */
#define ADC_DR_DATA_7             (0x0080U << ADC_DR_DATA_Pos)                 /*!< 0x00000080 */
#define ADC_DR_DATA_8             (0x0100U << ADC_DR_DATA_Pos)                 /*!< 0x00000100 */
#define ADC_DR_DATA_9             (0x0200U << ADC_DR_DATA_Pos)                 /*!< 0x00000200 */
#define ADC_DR_DATA_10            (0x0400U << ADC_DR_DATA_Pos)                 /*!< 0x00000400 */
#define ADC_DR_DATA_11            (0x0800U << ADC_DR_DATA_Pos)                 /*!< 0x00000800 */
#define ADC_DR_DATA_12            (0x1000U << ADC_DR_DATA_Pos)                 /*!< 0x00001000 */
#define ADC_DR_DATA_13            (0x2000U << ADC_DR_DATA_Pos)                 /*!< 0x00002000 */
#define ADC_DR_DATA_14            (0x4000U << ADC_DR_DATA_Pos)                 /*!< 0x00004000 */
#define ADC_DR_DATA_15            (0x8000U << ADC_DR_DATA_Pos)                 /*!< 0x00008000 */

/*************************  ADC Common registers  *****************************/
/*******************  Bit definition for ADC_CCR register  ********************/
#define ADC_CCR_VREFEN_Pos        (22U)
#define ADC_CCR_VREFEN_Msk        (0x1U << ADC_CCR_VREFEN_Pos)                 /*!< 0x00400000 */
#define ADC_CCR_VREFEN            ADC_CCR_VREFEN_Msk                           /*!< ADC internal path to VrefInt enable */
#define ADC_CCR_TSEN_Pos          (23U)
#define ADC_CCR_TSEN_Msk          (0x1U << ADC_CCR_TSEN_Pos)                   /*!< 0x00800000 */
#define ADC_CCR_TSEN              ADC_CCR_TSEN_Msk                             /*!< ADC internal path to temperature sensor enable */

#define ADC_CCR_VBATEN_Pos        (24U)
#define ADC_CCR_VBATEN_Msk        (0x1U << ADC_CCR_VBATEN_Pos)                 /*!< 0x01000000 */
#define ADC_CCR_VBATEN            ADC_CCR_VBATEN_Msk                           /*!< ADC internal path to battery voltage enable */
