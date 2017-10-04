/******************************************************************************/
/*                                                                            */
/*                                 HDMI-CEC (CEC)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CEC_CR register  *********************/
#define CEC_CR_CECEN_Pos         (0U)                                          
#define CEC_CR_CECEN_Msk         (0x1U << CEC_CR_CECEN_Pos)                    /*!< 0x00000001 */
#define CEC_CR_CECEN             CEC_CR_CECEN_Msk                              /*!< CEC Enable                         */
#define CEC_CR_TXSOM_Pos         (1U)                                          
#define CEC_CR_TXSOM_Msk         (0x1U << CEC_CR_TXSOM_Pos)                    /*!< 0x00000002 */
#define CEC_CR_TXSOM             CEC_CR_TXSOM_Msk                              /*!< CEC Tx Start Of Message            */
#define CEC_CR_TXEOM_Pos         (2U)                                          
#define CEC_CR_TXEOM_Msk         (0x1U << CEC_CR_TXEOM_Pos)                    /*!< 0x00000004 */
#define CEC_CR_TXEOM             CEC_CR_TXEOM_Msk                              /*!< CEC Tx End Of Message              */

/*******************  Bit definition for CEC_CFGR register  *******************/
#define CEC_CFGR_SFT_Pos         (0U)                                          
#define CEC_CFGR_SFT_Msk         (0x7U << CEC_CFGR_SFT_Pos)                    /*!< 0x00000007 */
#define CEC_CFGR_SFT             CEC_CFGR_SFT_Msk                              /*!< CEC Signal Free Time               */
#define CEC_CFGR_RXTOL_Pos       (3U)                                          
#define CEC_CFGR_RXTOL_Msk       (0x1U << CEC_CFGR_RXTOL_Pos)                  /*!< 0x00000008 */
#define CEC_CFGR_RXTOL           CEC_CFGR_RXTOL_Msk                            /*!< CEC Tolerance                      */
#define CEC_CFGR_BRESTP_Pos      (4U)                                          
#define CEC_CFGR_BRESTP_Msk      (0x1U << CEC_CFGR_BRESTP_Pos)                 /*!< 0x00000010 */
#define CEC_CFGR_BRESTP          CEC_CFGR_BRESTP_Msk                           /*!< CEC Rx Stop                        */
#define CEC_CFGR_BREGEN_Pos      (5U)                                          
#define CEC_CFGR_BREGEN_Msk      (0x1U << CEC_CFGR_BREGEN_Pos)                 /*!< 0x00000020 */
#define CEC_CFGR_BREGEN          CEC_CFGR_BREGEN_Msk                           /*!< CEC Bit Rising Error generation    */
#define CEC_CFGR_LBPEGEN_Pos     (6U)                                          
#define CEC_CFGR_LBPEGEN_Msk     (0x1U << CEC_CFGR_LBPEGEN_Pos)                /*!< 0x00000040 */
#define CEC_CFGR_LBPEGEN         CEC_CFGR_LBPEGEN_Msk                          /*!< CEC Long Bit Period Error gener.   */
#define CEC_CFGR_BRDNOGEN_Pos    (7U)                                          
#define CEC_CFGR_BRDNOGEN_Msk    (0x1U << CEC_CFGR_BRDNOGEN_Pos)               /*!< 0x00000080 */
#define CEC_CFGR_BRDNOGEN        CEC_CFGR_BRDNOGEN_Msk                         /*!< CEC Broadcast No Error generation  */
#define CEC_CFGR_SFTOPT_Pos      (8U)                                          
#define CEC_CFGR_SFTOPT_Msk      (0x1U << CEC_CFGR_SFTOPT_Pos)                 /*!< 0x00000100 */
#define CEC_CFGR_SFTOPT          CEC_CFGR_SFTOPT_Msk                           /*!< CEC Signal Free Time optional      */
#define CEC_CFGR_OAR_Pos         (16U)                                         
#define CEC_CFGR_OAR_Msk         (0x7FFFU << CEC_CFGR_OAR_Pos)                 /*!< 0x7FFF0000 */
#define CEC_CFGR_OAR             CEC_CFGR_OAR_Msk                              /*!< CEC Own Address                    */
#define CEC_CFGR_LSTN_Pos        (31U)                                         
#define CEC_CFGR_LSTN_Msk        (0x1U << CEC_CFGR_LSTN_Pos)                   /*!< 0x80000000 */
#define CEC_CFGR_LSTN            CEC_CFGR_LSTN_Msk                             /*!< CEC Listen mode                    */

/*******************  Bit definition for CEC_TXDR register  *******************/
#define CEC_TXDR_TXD_Pos         (0U)                                          
#define CEC_TXDR_TXD_Msk         (0xFFU << CEC_TXDR_TXD_Pos)                   /*!< 0x000000FF */
#define CEC_TXDR_TXD             CEC_TXDR_TXD_Msk                              /*!< CEC Tx Data                        */

/*******************  Bit definition for CEC_RXDR register  *******************/
#define CEC_TXDR_RXD_Pos         (0U)                                          
#define CEC_TXDR_RXD_Msk         (0xFFU << CEC_TXDR_RXD_Pos)                   /*!< 0x000000FF */
#define CEC_TXDR_RXD             CEC_TXDR_RXD_Msk                              /*!< CEC Rx Data                        */

/*******************  Bit definition for CEC_ISR register  ********************/
#define CEC_ISR_RXBR_Pos         (0U)                                          
#define CEC_ISR_RXBR_Msk         (0x1U << CEC_ISR_RXBR_Pos)                    /*!< 0x00000001 */
#define CEC_ISR_RXBR             CEC_ISR_RXBR_Msk                              /*!< CEC Rx-Byte Received                   */
#define CEC_ISR_RXEND_Pos        (1U)                                          
#define CEC_ISR_RXEND_Msk        (0x1U << CEC_ISR_RXEND_Pos)                   /*!< 0x00000002 */
#define CEC_ISR_RXEND            CEC_ISR_RXEND_Msk                             /*!< CEC End Of Reception                   */
#define CEC_ISR_RXOVR_Pos        (2U)                                          
#define CEC_ISR_RXOVR_Msk        (0x1U << CEC_ISR_RXOVR_Pos)                   /*!< 0x00000004 */
#define CEC_ISR_RXOVR            CEC_ISR_RXOVR_Msk                             /*!< CEC Rx-Overrun                         */
#define CEC_ISR_BRE_Pos          (3U)                                          
#define CEC_ISR_BRE_Msk          (0x1U << CEC_ISR_BRE_Pos)                     /*!< 0x00000008 */
#define CEC_ISR_BRE              CEC_ISR_BRE_Msk                               /*!< CEC Rx Bit Rising Error                */
#define CEC_ISR_SBPE_Pos         (4U)                                          
#define CEC_ISR_SBPE_Msk         (0x1U << CEC_ISR_SBPE_Pos)                    /*!< 0x00000010 */
#define CEC_ISR_SBPE             CEC_ISR_SBPE_Msk                              /*!< CEC Rx Short Bit period Error          */
#define CEC_ISR_LBPE_Pos         (5U)                                          
#define CEC_ISR_LBPE_Msk         (0x1U << CEC_ISR_LBPE_Pos)                    /*!< 0x00000020 */
#define CEC_ISR_LBPE             CEC_ISR_LBPE_Msk                              /*!< CEC Rx Long Bit period Error           */
#define CEC_ISR_RXACKE_Pos       (6U)                                          
#define CEC_ISR_RXACKE_Msk       (0x1U << CEC_ISR_RXACKE_Pos)                  /*!< 0x00000040 */
#define CEC_ISR_RXACKE           CEC_ISR_RXACKE_Msk                            /*!< CEC Rx Missing Acknowledge             */
#define CEC_ISR_ARBLST_Pos       (7U)                                          
#define CEC_ISR_ARBLST_Msk       (0x1U << CEC_ISR_ARBLST_Pos)                  /*!< 0x00000080 */
#define CEC_ISR_ARBLST           CEC_ISR_ARBLST_Msk                            /*!< CEC Arbitration Lost                   */
#define CEC_ISR_TXBR_Pos         (8U)                                          
#define CEC_ISR_TXBR_Msk         (0x1U << CEC_ISR_TXBR_Pos)                    /*!< 0x00000100 */
#define CEC_ISR_TXBR             CEC_ISR_TXBR_Msk                              /*!< CEC Tx Byte Request                    */
#define CEC_ISR_TXEND_Pos        (9U)                                          
#define CEC_ISR_TXEND_Msk        (0x1U << CEC_ISR_TXEND_Pos)                   /*!< 0x00000200 */
#define CEC_ISR_TXEND            CEC_ISR_TXEND_Msk                             /*!< CEC End of Transmission                */
#define CEC_ISR_TXUDR_Pos        (10U)                                         
#define CEC_ISR_TXUDR_Msk        (0x1U << CEC_ISR_TXUDR_Pos)                   /*!< 0x00000400 */
#define CEC_ISR_TXUDR            CEC_ISR_TXUDR_Msk                             /*!< CEC Tx-Buffer Underrun                 */
#define CEC_ISR_TXERR_Pos        (11U)                                         
#define CEC_ISR_TXERR_Msk        (0x1U << CEC_ISR_TXERR_Pos)                   /*!< 0x00000800 */
#define CEC_ISR_TXERR            CEC_ISR_TXERR_Msk                             /*!< CEC Tx-Error                           */
#define CEC_ISR_TXACKE_Pos       (12U)                                         
#define CEC_ISR_TXACKE_Msk       (0x1U << CEC_ISR_TXACKE_Pos)                  /*!< 0x00001000 */
#define CEC_ISR_TXACKE           CEC_ISR_TXACKE_Msk                            /*!< CEC Tx Missing Acknowledge             */

/*******************  Bit definition for CEC_IER register  ********************/
#define CEC_IER_RXBRIE_Pos       (0U)                                          
#define CEC_IER_RXBRIE_Msk       (0x1U << CEC_IER_RXBRIE_Pos)                  /*!< 0x00000001 */
#define CEC_IER_RXBRIE           CEC_IER_RXBRIE_Msk                            /*!< CEC Rx-Byte Received IT Enable         */
#define CEC_IER_RXENDIE_Pos      (1U)                                          
#define CEC_IER_RXENDIE_Msk      (0x1U << CEC_IER_RXENDIE_Pos)                 /*!< 0x00000002 */
#define CEC_IER_RXENDIE          CEC_IER_RXENDIE_Msk                           /*!< CEC End Of Reception IT Enable         */
#define CEC_IER_RXOVRIE_Pos      (2U)                                          
#define CEC_IER_RXOVRIE_Msk      (0x1U << CEC_IER_RXOVRIE_Pos)                 /*!< 0x00000004 */
#define CEC_IER_RXOVRIE          CEC_IER_RXOVRIE_Msk                           /*!< CEC Rx-Overrun IT Enable               */
#define CEC_IER_BREIE_Pos        (3U)                                          
#define CEC_IER_BREIE_Msk        (0x1U << CEC_IER_BREIE_Pos)                   /*!< 0x00000008 */
#define CEC_IER_BREIE            CEC_IER_BREIE_Msk                             /*!< CEC Rx Bit Rising Error IT Enable      */
#define CEC_IER_SBPEIE_Pos       (4U)                                          
#define CEC_IER_SBPEIE_Msk       (0x1U << CEC_IER_SBPEIE_Pos)                  /*!< 0x00000010 */
#define CEC_IER_SBPEIE           CEC_IER_SBPEIE_Msk                            /*!< CEC Rx Short Bit period Error IT Enable*/
#define CEC_IER_LBPEIE_Pos       (5U)                                          
#define CEC_IER_LBPEIE_Msk       (0x1U << CEC_IER_LBPEIE_Pos)                  /*!< 0x00000020 */
#define CEC_IER_LBPEIE           CEC_IER_LBPEIE_Msk                            /*!< CEC Rx Long Bit period Error IT Enable */
#define CEC_IER_RXACKEIE_Pos     (6U)                                          
#define CEC_IER_RXACKEIE_Msk     (0x1U << CEC_IER_RXACKEIE_Pos)                /*!< 0x00000040 */
#define CEC_IER_RXACKEIE         CEC_IER_RXACKEIE_Msk                          /*!< CEC Rx Missing Acknowledge IT Enable   */
#define CEC_IER_ARBLSTIE_Pos     (7U)                                          
#define CEC_IER_ARBLSTIE_Msk     (0x1U << CEC_IER_ARBLSTIE_Pos)                /*!< 0x00000080 */
#define CEC_IER_ARBLSTIE         CEC_IER_ARBLSTIE_Msk                          /*!< CEC Arbitration Lost IT Enable         */
#define CEC_IER_TXBRIE_Pos       (8U)                                          
#define CEC_IER_TXBRIE_Msk       (0x1U << CEC_IER_TXBRIE_Pos)                  /*!< 0x00000100 */
#define CEC_IER_TXBRIE           CEC_IER_TXBRIE_Msk                            /*!< CEC Tx Byte Request  IT Enable         */
#define CEC_IER_TXENDIE_Pos      (9U)                                          
#define CEC_IER_TXENDIE_Msk      (0x1U << CEC_IER_TXENDIE_Pos)                 /*!< 0x00000200 */
#define CEC_IER_TXENDIE          CEC_IER_TXENDIE_Msk                           /*!< CEC End of Transmission IT Enable      */
#define CEC_IER_TXUDRIE_Pos      (10U)                                         
#define CEC_IER_TXUDRIE_Msk      (0x1U << CEC_IER_TXUDRIE_Pos)                 /*!< 0x00000400 */
#define CEC_IER_TXUDRIE          CEC_IER_TXUDRIE_Msk                           /*!< CEC Tx-Buffer Underrun IT Enable       */
#define CEC_IER_TXERRIE_Pos      (11U)                                         
#define CEC_IER_TXERRIE_Msk      (0x1U << CEC_IER_TXERRIE_Pos)                 /*!< 0x00000800 */
#define CEC_IER_TXERRIE          CEC_IER_TXERRIE_Msk                           /*!< CEC Tx-Error IT Enable                 */
#define CEC_IER_TXACKEIE_Pos     (12U)                                         
#define CEC_IER_TXACKEIE_Msk     (0x1U << CEC_IER_TXACKEIE_Pos)                /*!< 0x00001000 */
#define CEC_IER_TXACKEIE         CEC_IER_TXACKEIE_Msk                          /*!< CEC Tx Missing Acknowledge IT Enable   */


/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/
/***********************  Bit definition for COMP_CSR register  ***************/
/* COMP1 bits definition */
#define COMP_CSR_COMP1EN_Pos          (0U)                                     
#define COMP_CSR_COMP1EN_Msk          (0x1U << COMP_CSR_COMP1EN_Pos)           /*!< 0x00000001 */
#define COMP_CSR_COMP1EN              COMP_CSR_COMP1EN_Msk                     /*!< COMP1 enable */
#define COMP_CSR_COMP1SW1_Pos         (1U)                                     
#define COMP_CSR_COMP1SW1_Msk         (0x1U << COMP_CSR_COMP1SW1_Pos)          /*!< 0x00000002 */
#define COMP_CSR_COMP1SW1             COMP_CSR_COMP1SW1_Msk                    /*!< COMP1 SW1 switch control */
#define COMP_CSR_COMP1MODE_Pos        (2U)                                     
#define COMP_CSR_COMP1MODE_Msk        (0x3U << COMP_CSR_COMP1MODE_Pos)         /*!< 0x0000000C */
#define COMP_CSR_COMP1MODE            COMP_CSR_COMP1MODE_Msk                   /*!< COMP1 power mode */
#define COMP_CSR_COMP1MODE_0          (0x1U << COMP_CSR_COMP1MODE_Pos)         /*!< 0x00000004 */
#define COMP_CSR_COMP1MODE_1          (0x2U << COMP_CSR_COMP1MODE_Pos)         /*!< 0x00000008 */
#define COMP_CSR_COMP1INSEL_Pos       (4U)                                     
#define COMP_CSR_COMP1INSEL_Msk       (0x7U << COMP_CSR_COMP1INSEL_Pos)        /*!< 0x00000070 */
#define COMP_CSR_COMP1INSEL           COMP_CSR_COMP1INSEL_Msk                  /*!< COMP1 inverting input select */
#define COMP_CSR_COMP1INSEL_0         (0x1U << COMP_CSR_COMP1INSEL_Pos)        /*!< 0x00000010 */
#define COMP_CSR_COMP1INSEL_1         (0x2U << COMP_CSR_COMP1INSEL_Pos)        /*!< 0x00000020 */
#define COMP_CSR_COMP1INSEL_2         (0x4U << COMP_CSR_COMP1INSEL_Pos)        /*!< 0x00000040 */
#define COMP_CSR_COMP1OUTSEL_Pos      (8U)                                     
#define COMP_CSR_COMP1OUTSEL_Msk      (0x7U << COMP_CSR_COMP1OUTSEL_Pos)       /*!< 0x00000700 */
#define COMP_CSR_COMP1OUTSEL          COMP_CSR_COMP1OUTSEL_Msk                 /*!< COMP1 output select */
#define COMP_CSR_COMP1OUTSEL_0        (0x1U << COMP_CSR_COMP1OUTSEL_Pos)       /*!< 0x00000100 */
#define COMP_CSR_COMP1OUTSEL_1        (0x2U << COMP_CSR_COMP1OUTSEL_Pos)       /*!< 0x00000200 */
#define COMP_CSR_COMP1OUTSEL_2        (0x4U << COMP_CSR_COMP1OUTSEL_Pos)       /*!< 0x00000400 */
#define COMP_CSR_COMP1POL_Pos         (11U)                                    
#define COMP_CSR_COMP1POL_Msk         (0x1U << COMP_CSR_COMP1POL_Pos)          /*!< 0x00000800 */
#define COMP_CSR_COMP1POL             COMP_CSR_COMP1POL_Msk                    /*!< COMP1 output polarity */
#define COMP_CSR_COMP1HYST_Pos        (12U)                                    
#define COMP_CSR_COMP1HYST_Msk        (0x3U << COMP_CSR_COMP1HYST_Pos)         /*!< 0x00003000 */
#define COMP_CSR_COMP1HYST            COMP_CSR_COMP1HYST_Msk                   /*!< COMP1 hysteresis */
#define COMP_CSR_COMP1HYST_0          (0x1U << COMP_CSR_COMP1HYST_Pos)         /*!< 0x00001000 */
#define COMP_CSR_COMP1HYST_1          (0x2U << COMP_CSR_COMP1HYST_Pos)         /*!< 0x00002000 */
#define COMP_CSR_COMP1OUT_Pos         (14U)                                    
#define COMP_CSR_COMP1OUT_Msk         (0x1U << COMP_CSR_COMP1OUT_Pos)          /*!< 0x00004000 */
#define COMP_CSR_COMP1OUT             COMP_CSR_COMP1OUT_Msk                    /*!< COMP1 output level */
#define COMP_CSR_COMP1LOCK_Pos        (15U)                                    
#define COMP_CSR_COMP1LOCK_Msk        (0x1U << COMP_CSR_COMP1LOCK_Pos)         /*!< 0x00008000 */
#define COMP_CSR_COMP1LOCK            COMP_CSR_COMP1LOCK_Msk                   /*!< COMP1 lock */
/* COMP2 bits definition */
#define COMP_CSR_COMP2EN_Pos          (16U)                                    
#define COMP_CSR_COMP2EN_Msk          (0x1U << COMP_CSR_COMP2EN_Pos)           /*!< 0x00010000 */
#define COMP_CSR_COMP2EN              COMP_CSR_COMP2EN_Msk                     /*!< COMP2 enable */
#define COMP_CSR_COMP2MODE_Pos        (18U)                                    
#define COMP_CSR_COMP2MODE_Msk        (0x3U << COMP_CSR_COMP2MODE_Pos)         /*!< 0x000C0000 */
#define COMP_CSR_COMP2MODE            COMP_CSR_COMP2MODE_Msk                   /*!< COMP2 power mode */
#define COMP_CSR_COMP2MODE_0          (0x1U << COMP_CSR_COMP2MODE_Pos)         /*!< 0x00040000 */
#define COMP_CSR_COMP2MODE_1          (0x2U << COMP_CSR_COMP2MODE_Pos)         /*!< 0x00080000 */
#define COMP_CSR_COMP2INSEL_Pos       (20U)                                    
#define COMP_CSR_COMP2INSEL_Msk       (0x7U << COMP_CSR_COMP2INSEL_Pos)        /*!< 0x00700000 */
#define COMP_CSR_COMP2INSEL           COMP_CSR_COMP2INSEL_Msk                  /*!< COMP2 inverting input select */
#define COMP_CSR_COMP2INSEL_0         (0x1U << COMP_CSR_COMP2INSEL_Pos)        /*!< 0x00100000 */
#define COMP_CSR_COMP2INSEL_1         (0x2U << COMP_CSR_COMP2INSEL_Pos)        /*!< 0x00200000 */
#define COMP_CSR_COMP2INSEL_2         (0x4U << COMP_CSR_COMP2INSEL_Pos)        /*!< 0x00400000 */
#define COMP_CSR_WNDWEN_Pos           (23U)                                    
#define COMP_CSR_WNDWEN_Msk           (0x1U << COMP_CSR_WNDWEN_Pos)            /*!< 0x00800000 */
#define COMP_CSR_WNDWEN               COMP_CSR_WNDWEN_Msk                      /*!< COMPx window mode. Bit intended to be used with COMP common instance (COMP_Common_TypeDef) */
#define COMP_CSR_COMP2OUTSEL_Pos      (24U)                                    
#define COMP_CSR_COMP2OUTSEL_Msk      (0x7U << COMP_CSR_COMP2OUTSEL_Pos)       /*!< 0x07000000 */
#define COMP_CSR_COMP2OUTSEL          COMP_CSR_COMP2OUTSEL_Msk                 /*!< COMP2 output select */
#define COMP_CSR_COMP2OUTSEL_0        (0x1U << COMP_CSR_COMP2OUTSEL_Pos)       /*!< 0x01000000 */
#define COMP_CSR_COMP2OUTSEL_1        (0x2U << COMP_CSR_COMP2OUTSEL_Pos)       /*!< 0x02000000 */
#define COMP_CSR_COMP2OUTSEL_2        (0x4U << COMP_CSR_COMP2OUTSEL_Pos)       /*!< 0x04000000 */
#define COMP_CSR_COMP2POL_Pos         (27U)                                    
#define COMP_CSR_COMP2POL_Msk         (0x1U << COMP_CSR_COMP2POL_Pos)          /*!< 0x08000000 */
#define COMP_CSR_COMP2POL             COMP_CSR_COMP2POL_Msk                    /*!< COMP2 output polarity */
#define COMP_CSR_COMP2HYST_Pos        (28U)                                    
#define COMP_CSR_COMP2HYST_Msk        (0x3U << COMP_CSR_COMP2HYST_Pos)         /*!< 0x30000000 */
#define COMP_CSR_COMP2HYST            COMP_CSR_COMP2HYST_Msk                   /*!< COMP2 hysteresis */
#define COMP_CSR_COMP2HYST_0          (0x1U << COMP_CSR_COMP2HYST_Pos)         /*!< 0x10000000 */
#define COMP_CSR_COMP2HYST_1          (0x2U << COMP_CSR_COMP2HYST_Pos)         /*!< 0x20000000 */
#define COMP_CSR_COMP2OUT_Pos         (30U)                                    
#define COMP_CSR_COMP2OUT_Msk         (0x1U << COMP_CSR_COMP2OUT_Pos)          /*!< 0x40000000 */
#define COMP_CSR_COMP2OUT             COMP_CSR_COMP2OUT_Msk                    /*!< COMP2 output level */
#define COMP_CSR_COMP2LOCK_Pos        (31U)                                    
#define COMP_CSR_COMP2LOCK_Msk        (0x1U << COMP_CSR_COMP2LOCK_Pos)         /*!< 0x80000000 */
#define COMP_CSR_COMP2LOCK            COMP_CSR_COMP2LOCK_Msk                   /*!< COMP2 lock */
/* COMPx bits definition */
#define COMP_CSR_COMPxEN_Pos          (0U)                                     
#define COMP_CSR_COMPxEN_Msk          (0x1U << COMP_CSR_COMPxEN_Pos)           /*!< 0x00000001 */
#define COMP_CSR_COMPxEN              COMP_CSR_COMPxEN_Msk                     /*!< COMPx enable */
#define COMP_CSR_COMPxMODE_Pos        (2U)                                     
#define COMP_CSR_COMPxMODE_Msk        (0x3U << COMP_CSR_COMPxMODE_Pos)         /*!< 0x0000000C */
#define COMP_CSR_COMPxMODE            COMP_CSR_COMPxMODE_Msk                   /*!< COMPx power mode */
#define COMP_CSR_COMPxMODE_0          (0x1U << COMP_CSR_COMPxMODE_Pos)         /*!< 0x00000004 */
#define COMP_CSR_COMPxMODE_1          (0x2U << COMP_CSR_COMPxMODE_Pos)         /*!< 0x00000008 */
#define COMP_CSR_COMPxINSEL_Pos       (4U)                                     
#define COMP_CSR_COMPxINSEL_Msk       (0x7U << COMP_CSR_COMPxINSEL_Pos)        /*!< 0x00000070 */
#define COMP_CSR_COMPxINSEL           COMP_CSR_COMPxINSEL_Msk                  /*!< COMPx inverting input select */
#define COMP_CSR_COMPxINSEL_0         (0x1U << COMP_CSR_COMPxINSEL_Pos)        /*!< 0x00000010 */
#define COMP_CSR_COMPxINSEL_1         (0x2U << COMP_CSR_COMPxINSEL_Pos)        /*!< 0x00000020 */
#define COMP_CSR_COMPxINSEL_2         (0x4U << COMP_CSR_COMPxINSEL_Pos)        /*!< 0x00000040 */
#define COMP_CSR_COMPxOUTSEL_Pos      (8U)                                     
#define COMP_CSR_COMPxOUTSEL_Msk      (0x7U << COMP_CSR_COMPxOUTSEL_Pos)       /*!< 0x00000700 */
#define COMP_CSR_COMPxOUTSEL          COMP_CSR_COMPxOUTSEL_Msk                 /*!< COMPx output select */
#define COMP_CSR_COMPxOUTSEL_0        (0x1U << COMP_CSR_COMPxOUTSEL_Pos)       /*!< 0x00000100 */
#define COMP_CSR_COMPxOUTSEL_1        (0x2U << COMP_CSR_COMPxOUTSEL_Pos)       /*!< 0x00000200 */
#define COMP_CSR_COMPxOUTSEL_2        (0x4U << COMP_CSR_COMPxOUTSEL_Pos)       /*!< 0x00000400 */
#define COMP_CSR_COMPxPOL_Pos         (11U)                                    
#define COMP_CSR_COMPxPOL_Msk         (0x1U << COMP_CSR_COMPxPOL_Pos)          /*!< 0x00000800 */
#define COMP_CSR_COMPxPOL             COMP_CSR_COMPxPOL_Msk                    /*!< COMPx output polarity */
#define COMP_CSR_COMPxHYST_Pos        (12U)                                    
#define COMP_CSR_COMPxHYST_Msk        (0x3U << COMP_CSR_COMPxHYST_Pos)         /*!< 0x00003000 */
#define COMP_CSR_COMPxHYST            COMP_CSR_COMPxHYST_Msk                   /*!< COMPx hysteresis */
#define COMP_CSR_COMPxHYST_0          (0x1U << COMP_CSR_COMPxHYST_Pos)         /*!< 0x00001000 */
#define COMP_CSR_COMPxHYST_1          (0x2U << COMP_CSR_COMPxHYST_Pos)         /*!< 0x00002000 */
#define COMP_CSR_COMPxOUT_Pos         (14U)                                    
#define COMP_CSR_COMPxOUT_Msk         (0x1U << COMP_CSR_COMPxOUT_Pos)          /*!< 0x00004000 */
#define COMP_CSR_COMPxOUT             COMP_CSR_COMPxOUT_Msk                    /*!< COMPx output level */
#define COMP_CSR_COMPxLOCK_Pos        (15U)                                    
#define COMP_CSR_COMPxLOCK_Msk        (0x1U << COMP_CSR_COMPxLOCK_Pos)         /*!< 0x00008000 */
#define COMP_CSR_COMPxLOCK            COMP_CSR_COMPxLOCK_Msk                   /*!< COMPx lock */

/******************************************************************************/
/*                                                                            */
/*                       CRC calculation unit (CRC)                           */
/*                                                                            */
/******************************************************************************/

/*
* @brief Specific device feature definitions (not present on all devices in the STM32F0 serie)
*/

/* Support of Programmable Polynomial size and value feature */
#define CRC_PROG_POLYNOMIAL_SUPPORT

/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos            (0U)                                          
#define CRC_DR_DR_Msk            (0xFFFFFFFFU << CRC_DR_DR_Pos)                /*!< 0xFFFFFFFF */
#define CRC_DR_DR                CRC_DR_DR_Msk                                 /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR              ((uint8_t)0xFFU)                              /*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos         (0U)                                          
#define CRC_CR_RESET_Msk         (0x1U << CRC_CR_RESET_Pos)                    /*!< 0x00000001 */
#define CRC_CR_RESET             CRC_CR_RESET_Msk                              /*!< RESET the CRC computation unit bit */
#define CRC_CR_POLYSIZE_Pos      (3U)                                          
#define CRC_CR_POLYSIZE_Msk      (0x3U << CRC_CR_POLYSIZE_Pos)                 /*!< 0x00000018 */
#define CRC_CR_POLYSIZE          CRC_CR_POLYSIZE_Msk                           /*!< Polynomial size bits */
#define CRC_CR_POLYSIZE_0        (0x1U << CRC_CR_POLYSIZE_Pos)                 /*!< 0x00000008 */
#define CRC_CR_POLYSIZE_1        (0x2U << CRC_CR_POLYSIZE_Pos)                 /*!< 0x00000010 */
#define CRC_CR_REV_IN_Pos        (5U)                                          
#define CRC_CR_REV_IN_Msk        (0x3U << CRC_CR_REV_IN_Pos)                   /*!< 0x00000060 */
#define CRC_CR_REV_IN            CRC_CR_REV_IN_Msk                             /*!< REV_IN Reverse Input Data bits */
#define CRC_CR_REV_IN_0          (0x1U << CRC_CR_REV_IN_Pos)                   /*!< 0x00000020 */
#define CRC_CR_REV_IN_1          (0x2U << CRC_CR_REV_IN_Pos)                   /*!< 0x00000040 */
#define CRC_CR_REV_OUT_Pos       (7U)                                          
#define CRC_CR_REV_OUT_Msk       (0x1U << CRC_CR_REV_OUT_Pos)                  /*!< 0x00000080 */
#define CRC_CR_REV_OUT           CRC_CR_REV_OUT_Msk                            /*!< REV_OUT Reverse Output Data bits */

/*******************  Bit definition for CRC_INIT register  *******************/
#define CRC_INIT_INIT_Pos        (0U)                                          
#define CRC_INIT_INIT_Msk        (0xFFFFFFFFU << CRC_INIT_INIT_Pos)            /*!< 0xFFFFFFFF */
#define CRC_INIT_INIT            CRC_INIT_INIT_Msk                             /*!< Initial CRC value bits */

/*******************  Bit definition for CRC_POL register  ********************/
#define CRC_POL_POL_Pos          (0U)                                          
#define CRC_POL_POL_Msk          (0xFFFFFFFFU << CRC_POL_POL_Pos)              /*!< 0xFFFFFFFF */
#define CRC_POL_POL              CRC_POL_POL_Msk                               /*!< Coefficients of the polynomial  */

/******************************************************************************/
/*                                                                            */
/*                          CRS Clock Recovery System                         */
/******************************************************************************/

/*******************  Bit definition for CRS_CR register  *********************/
#define CRS_CR_SYNCOKIE_Pos       (0U)                                         
#define CRS_CR_SYNCOKIE_Msk       (0x1U << CRS_CR_SYNCOKIE_Pos)                /*!< 0x00000001 */
#define CRS_CR_SYNCOKIE           CRS_CR_SYNCOKIE_Msk                          /* SYNC event OK interrupt enable        */
#define CRS_CR_SYNCWARNIE_Pos     (1U)                                         
#define CRS_CR_SYNCWARNIE_Msk     (0x1U << CRS_CR_SYNCWARNIE_Pos)              /*!< 0x00000002 */
#define CRS_CR_SYNCWARNIE         CRS_CR_SYNCWARNIE_Msk                        /* SYNC warning interrupt enable         */
#define CRS_CR_ERRIE_Pos          (2U)                                         
#define CRS_CR_ERRIE_Msk          (0x1U << CRS_CR_ERRIE_Pos)                   /*!< 0x00000004 */
#define CRS_CR_ERRIE              CRS_CR_ERRIE_Msk                             /* SYNC error interrupt enable           */
#define CRS_CR_ESYNCIE_Pos        (3U)                                         
#define CRS_CR_ESYNCIE_Msk        (0x1U << CRS_CR_ESYNCIE_Pos)                 /*!< 0x00000008 */
#define CRS_CR_ESYNCIE            CRS_CR_ESYNCIE_Msk                           /* Expected SYNC(ESYNCF) interrupt Enable*/
#define CRS_CR_CEN_Pos            (5U)                                         
#define CRS_CR_CEN_Msk            (0x1U << CRS_CR_CEN_Pos)                     /*!< 0x00000020 */
#define CRS_CR_CEN                CRS_CR_CEN_Msk                               /* Frequency error counter enable        */
#define CRS_CR_AUTOTRIMEN_Pos     (6U)                                         
#define CRS_CR_AUTOTRIMEN_Msk     (0x1U << CRS_CR_AUTOTRIMEN_Pos)              /*!< 0x00000040 */
#define CRS_CR_AUTOTRIMEN         CRS_CR_AUTOTRIMEN_Msk                        /* Automatic trimming enable             */
#define CRS_CR_SWSYNC_Pos         (7U)                                         
#define CRS_CR_SWSYNC_Msk         (0x1U << CRS_CR_SWSYNC_Pos)                  /*!< 0x00000080 */
#define CRS_CR_SWSYNC             CRS_CR_SWSYNC_Msk                            /* A Software SYNC event is generated    */
#define CRS_CR_TRIM_Pos           (8U)                                         
#define CRS_CR_TRIM_Msk           (0x3FU << CRS_CR_TRIM_Pos)                   /*!< 0x00003F00 */
#define CRS_CR_TRIM               CRS_CR_TRIM_Msk                              /* HSI48 oscillator smooth trimming      */

/*******************  Bit definition for CRS_CFGR register  *********************/
#define CRS_CFGR_RELOAD_Pos       (0U)                                         
#define CRS_CFGR_RELOAD_Msk       (0xFFFFU << CRS_CFGR_RELOAD_Pos)             /*!< 0x0000FFFF */
#define CRS_CFGR_RELOAD           CRS_CFGR_RELOAD_Msk                          /* Counter reload value               */
#define CRS_CFGR_FELIM_Pos        (16U)                                        
#define CRS_CFGR_FELIM_Msk        (0xFFU << CRS_CFGR_FELIM_Pos)                /*!< 0x00FF0000 */
#define CRS_CFGR_FELIM            CRS_CFGR_FELIM_Msk                           /* Frequency error limit              */

#define CRS_CFGR_SYNCDIV_Pos      (24U)                                        
#define CRS_CFGR_SYNCDIV_Msk      (0x7U << CRS_CFGR_SYNCDIV_Pos)               /*!< 0x07000000 */
#define CRS_CFGR_SYNCDIV          CRS_CFGR_SYNCDIV_Msk                         /* SYNC divider                       */
#define CRS_CFGR_SYNCDIV_0        (0x1U << CRS_CFGR_SYNCDIV_Pos)               /*!< 0x01000000 */
#define CRS_CFGR_SYNCDIV_1        (0x2U << CRS_CFGR_SYNCDIV_Pos)               /*!< 0x02000000 */
#define CRS_CFGR_SYNCDIV_2        (0x4U << CRS_CFGR_SYNCDIV_Pos)               /*!< 0x04000000 */

#define CRS_CFGR_SYNCSRC_Pos      (28U)                                        
#define CRS_CFGR_SYNCSRC_Msk      (0x3U << CRS_CFGR_SYNCSRC_Pos)               /*!< 0x30000000 */
#define CRS_CFGR_SYNCSRC          CRS_CFGR_SYNCSRC_Msk                         /* SYNC signal source selection       */
#define CRS_CFGR_SYNCSRC_0        (0x1U << CRS_CFGR_SYNCSRC_Pos)               /*!< 0x10000000 */
#define CRS_CFGR_SYNCSRC_1        (0x2U << CRS_CFGR_SYNCSRC_Pos)               /*!< 0x20000000 */

#define CRS_CFGR_SYNCPOL_Pos      (31U)                                        
#define CRS_CFGR_SYNCPOL_Msk      (0x1U << CRS_CFGR_SYNCPOL_Pos)               /*!< 0x80000000 */
#define CRS_CFGR_SYNCPOL          CRS_CFGR_SYNCPOL_Msk                         /* SYNC polarity selection            */
  
/*******************  Bit definition for CRS_ISR register  *********************/
#define CRS_ISR_SYNCOKF_Pos       (0U)                                         
#define CRS_ISR_SYNCOKF_Msk       (0x1U << CRS_ISR_SYNCOKF_Pos)                /*!< 0x00000001 */
#define CRS_ISR_SYNCOKF           CRS_ISR_SYNCOKF_Msk                          /* SYNC event OK flag             */
#define CRS_ISR_SYNCWARNF_Pos     (1U)                                         
#define CRS_ISR_SYNCWARNF_Msk     (0x1U << CRS_ISR_SYNCWARNF_Pos)              /*!< 0x00000002 */
#define CRS_ISR_SYNCWARNF         CRS_ISR_SYNCWARNF_Msk                        /* SYNC warning                   */
#define CRS_ISR_ERRF_Pos          (2U)                                         
#define CRS_ISR_ERRF_Msk          (0x1U << CRS_ISR_ERRF_Pos)                   /*!< 0x00000004 */
#define CRS_ISR_ERRF              CRS_ISR_ERRF_Msk                             /* SYNC error flag                */
#define CRS_ISR_ESYNCF_Pos        (3U)                                         
#define CRS_ISR_ESYNCF_Msk        (0x1U << CRS_ISR_ESYNCF_Pos)                 /*!< 0x00000008 */
#define CRS_ISR_ESYNCF            CRS_ISR_ESYNCF_Msk                           /* Expected SYNC flag             */
#define CRS_ISR_SYNCERR_Pos       (8U)                                         
#define CRS_ISR_SYNCERR_Msk       (0x1U << CRS_ISR_SYNCERR_Pos)                /*!< 0x00000100 */
#define CRS_ISR_SYNCERR           CRS_ISR_SYNCERR_Msk                          /* SYNC error                     */
#define CRS_ISR_SYNCMISS_Pos      (9U)                                         
#define CRS_ISR_SYNCMISS_Msk      (0x1U << CRS_ISR_SYNCMISS_Pos)               /*!< 0x00000200 */
#define CRS_ISR_SYNCMISS          CRS_ISR_SYNCMISS_Msk                         /* SYNC missed                    */
#define CRS_ISR_TRIMOVF_Pos       (10U)                                        
#define CRS_ISR_TRIMOVF_Msk       (0x1U << CRS_ISR_TRIMOVF_Pos)                /*!< 0x00000400 */
#define CRS_ISR_TRIMOVF           CRS_ISR_TRIMOVF_Msk                          /* Trimming overflow or underflow */
#define CRS_ISR_FEDIR_Pos         (15U)                                        
#define CRS_ISR_FEDIR_Msk         (0x1U << CRS_ISR_FEDIR_Pos)                  /*!< 0x00008000 */
#define CRS_ISR_FEDIR             CRS_ISR_FEDIR_Msk                            /* Frequency error direction      */
#define CRS_ISR_FECAP_Pos         (16U)                                        
#define CRS_ISR_FECAP_Msk         (0xFFFFU << CRS_ISR_FECAP_Pos)               /*!< 0xFFFF0000 */
#define CRS_ISR_FECAP             CRS_ISR_FECAP_Msk                            /* Frequency error capture        */

/*******************  Bit definition for CRS_ICR register  *********************/
#define CRS_ICR_SYNCOKC_Pos       (0U)                                         
#define CRS_ICR_SYNCOKC_Msk       (0x1U << CRS_ICR_SYNCOKC_Pos)                /*!< 0x00000001 */
#define CRS_ICR_SYNCOKC           CRS_ICR_SYNCOKC_Msk                          /* SYNC event OK clear flag     */
#define CRS_ICR_SYNCWARNC_Pos     (1U)                                         
#define CRS_ICR_SYNCWARNC_Msk     (0x1U << CRS_ICR_SYNCWARNC_Pos)              /*!< 0x00000002 */
#define CRS_ICR_SYNCWARNC         CRS_ICR_SYNCWARNC_Msk                        /* SYNC warning clear flag      */
#define CRS_ICR_ERRC_Pos          (2U)                                         
#define CRS_ICR_ERRC_Msk          (0x1U << CRS_ICR_ERRC_Pos)                   /*!< 0x00000004 */
#define CRS_ICR_ERRC              CRS_ICR_ERRC_Msk                             /* Error clear flag        */
#define CRS_ICR_ESYNCC_Pos        (3U)                                         
#define CRS_ICR_ESYNCC_Msk        (0x1U << CRS_ICR_ESYNCC_Pos)                 /*!< 0x00000008 */
#define CRS_ICR_ESYNCC            CRS_ICR_ESYNCC_Msk                           /* Expected SYNC clear flag     */

/******************************************************************************/
/*                                                                            */
/*                 Digital to Analog Converter (DAC)                          */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F0 serie)
 */
#define DAC_CHANNEL2_SUPPORT                       /*!< DAC feature available only on specific devices: availability of DAC channel 2 */

/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1_Pos              (0U)                                       
#define DAC_CR_EN1_Msk              (0x1U << DAC_CR_EN1_Pos)                   /*!< 0x00000001 */
#define DAC_CR_EN1                  DAC_CR_EN1_Msk                             /*!< DAC channel1 enable */
#define DAC_CR_BOFF1_Pos            (1U)                                       
#define DAC_CR_BOFF1_Msk            (0x1U << DAC_CR_BOFF1_Pos)                 /*!< 0x00000002 */
#define DAC_CR_BOFF1                DAC_CR_BOFF1_Msk                           /*!< DAC channel1 output buffer disable */
#define DAC_CR_TEN1_Pos             (2U)                                       
#define DAC_CR_TEN1_Msk             (0x1U << DAC_CR_TEN1_Pos)                  /*!< 0x00000004 */
#define DAC_CR_TEN1                 DAC_CR_TEN1_Msk                            /*!< DAC channel1 Trigger enable */

#define DAC_CR_TSEL1_Pos            (3U)                                       
#define DAC_CR_TSEL1_Msk            (0x7U << DAC_CR_TSEL1_Pos)                 /*!< 0x00000038 */
#define DAC_CR_TSEL1                DAC_CR_TSEL1_Msk                           /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define DAC_CR_TSEL1_0              (0x1U << DAC_CR_TSEL1_Pos)                 /*!< 0x00000008 */
#define DAC_CR_TSEL1_1              (0x2U << DAC_CR_TSEL1_Pos)                 /*!< 0x00000010 */
#define DAC_CR_TSEL1_2              (0x4U << DAC_CR_TSEL1_Pos)                 /*!< 0x00000020 */

#define DAC_CR_WAVE1_Pos            (6U)                                       
#define DAC_CR_WAVE1_Msk            (0x3U << DAC_CR_WAVE1_Pos)                 /*!< 0x000000C0 */
#define DAC_CR_WAVE1                DAC_CR_WAVE1_Msk                           /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define DAC_CR_WAVE1_0              (0x1U << DAC_CR_WAVE1_Pos)                 /*!< 0x00000040 */
#define DAC_CR_WAVE1_1              (0x2U << DAC_CR_WAVE1_Pos)                 /*!< 0x00000080 */

#define DAC_CR_MAMP1_Pos            (8U)                                       
#define DAC_CR_MAMP1_Msk            (0xFU << DAC_CR_MAMP1_Pos)                 /*!< 0x00000F00 */
#define DAC_CR_MAMP1                DAC_CR_MAMP1_Msk                           /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector)  */
#define DAC_CR_MAMP1_0              (0x1U << DAC_CR_MAMP1_Pos)                 /*!< 0x00000100 */
#define DAC_CR_MAMP1_1              (0x2U << DAC_CR_MAMP1_Pos)                 /*!< 0x00000200 */
#define DAC_CR_MAMP1_2              (0x4U << DAC_CR_MAMP1_Pos)                 /*!< 0x00000400 */
#define DAC_CR_MAMP1_3              (0x8U << DAC_CR_MAMP1_Pos)                 /*!< 0x00000800 */

#define DAC_CR_DMAEN1_Pos           (12U)                                      
#define DAC_CR_DMAEN1_Msk           (0x1U << DAC_CR_DMAEN1_Pos)                /*!< 0x00001000 */
#define DAC_CR_DMAEN1               DAC_CR_DMAEN1_Msk                          /*!< DAC channel1 DMA enable */
#define DAC_CR_DMAUDRIE1_Pos        (13U)                                      
#define DAC_CR_DMAUDRIE1_Msk        (0x1U << DAC_CR_DMAUDRIE1_Pos)             /*!< 0x00002000 */
#define DAC_CR_DMAUDRIE1            DAC_CR_DMAUDRIE1_Msk                       /*!< DAC channel1 DMA Underrun Interrupt enable */

#define DAC_CR_EN2_Pos              (16U)                                      
#define DAC_CR_EN2_Msk              (0x1U << DAC_CR_EN2_Pos)                   /*!< 0x00010000 */
#define DAC_CR_EN2                  DAC_CR_EN2_Msk                             /*!< DAC channel2 enable */
#define DAC_CR_BOFF2_Pos            (17U)                                      
#define DAC_CR_BOFF2_Msk            (0x1U << DAC_CR_BOFF2_Pos)                 /*!< 0x00020000 */
#define DAC_CR_BOFF2                DAC_CR_BOFF2_Msk                           /*!< DAC channel2 output buffer disable */
#define DAC_CR_TEN2_Pos             (18U)                                      
#define DAC_CR_TEN2_Msk             (0x1U << DAC_CR_TEN2_Pos)                  /*!< 0x00040000 */
#define DAC_CR_TEN2                 DAC_CR_TEN2_Msk                            /*!< DAC channel2 Trigger enable */

#define DAC_CR_TSEL2_Pos            (19U)                                      
#define DAC_CR_TSEL2_Msk            (0x7U << DAC_CR_TSEL2_Pos)                 /*!< 0x00380000 */
#define DAC_CR_TSEL2                DAC_CR_TSEL2_Msk                           /*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define DAC_CR_TSEL2_0              (0x1U << DAC_CR_TSEL2_Pos)                 /*!< 0x00080000 */
#define DAC_CR_TSEL2_1              (0x2U << DAC_CR_TSEL2_Pos)                 /*!< 0x00100000 */
#define DAC_CR_TSEL2_2              (0x4U << DAC_CR_TSEL2_Pos)                 /*!< 0x00200000 */

#define DAC_CR_WAVE2_Pos            (22U)                                      
#define DAC_CR_WAVE2_Msk            (0x3U << DAC_CR_WAVE2_Pos)                 /*!< 0x00C00000 */
#define DAC_CR_WAVE2                DAC_CR_WAVE2_Msk                           /*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define DAC_CR_WAVE2_0              (0x1U << DAC_CR_WAVE2_Pos)                 /*!< 0x00400000 */
#define DAC_CR_WAVE2_1              (0x2U << DAC_CR_WAVE2_Pos)                 /*!< 0x00800000 */

#define DAC_CR_MAMP2_Pos            (24U)                                      
#define DAC_CR_MAMP2_Msk            (0xFU << DAC_CR_MAMP2_Pos)                 /*!< 0x0F000000 */
#define DAC_CR_MAMP2                DAC_CR_MAMP2_Msk                           /*!< MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define DAC_CR_MAMP2_0              (0x1U << DAC_CR_MAMP2_Pos)                 /*!< 0x01000000 */
#define DAC_CR_MAMP2_1              (0x2U << DAC_CR_MAMP2_Pos)                 /*!< 0x02000000 */
#define DAC_CR_MAMP2_2              (0x4U << DAC_CR_MAMP2_Pos)                 /*!< 0x04000000 */
#define DAC_CR_MAMP2_3              (0x8U << DAC_CR_MAMP2_Pos)                 /*!< 0x08000000 */

#define DAC_CR_DMAEN2_Pos           (28U)                                      
#define DAC_CR_DMAEN2_Msk           (0x1U << DAC_CR_DMAEN2_Pos)                /*!< 0x10000000 */
#define DAC_CR_DMAEN2               DAC_CR_DMAEN2_Msk                          /*!< DAC channel2 DMA enabled */
#define DAC_CR_DMAUDRIE2_Pos        (29U)                                      
#define DAC_CR_DMAUDRIE2_Msk        (0x1U << DAC_CR_DMAUDRIE2_Pos)             /*!< 0x20000000 */
#define DAC_CR_DMAUDRIE2            DAC_CR_DMAUDRIE2_Msk                       /*!< DAC channel2 DMA Underrun Interrupt enable */

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1_Pos     (0U)                                       
#define DAC_SWTRIGR_SWTRIG1_Msk     (0x1U << DAC_SWTRIGR_SWTRIG1_Pos)          /*!< 0x00000001 */
#define DAC_SWTRIGR_SWTRIG1         DAC_SWTRIGR_SWTRIG1_Msk                    /*!< DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG2_Pos     (1U)                                       
#define DAC_SWTRIGR_SWTRIG2_Msk     (0x1U << DAC_SWTRIGR_SWTRIG2_Pos)          /*!< 0x00000002 */
#define DAC_SWTRIGR_SWTRIG2         DAC_SWTRIGR_SWTRIG2_Msk                    /*!< DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR_Pos    (0U)                                       
#define DAC_DHR12R1_DACC1DHR_Msk    (0xFFFU << DAC_DHR12R1_DACC1DHR_Pos)       /*!< 0x00000FFF */
#define DAC_DHR12R1_DACC1DHR        DAC_DHR12R1_DACC1DHR_Msk                   /*!< DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR_Pos    (4U)                                       
#define DAC_DHR12L1_DACC1DHR_Msk    (0xFFFU << DAC_DHR12L1_DACC1DHR_Pos)       /*!< 0x0000FFF0 */
#define DAC_DHR12L1_DACC1DHR        DAC_DHR12L1_DACC1DHR_Msk                   /*!< DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR_Pos     (0U)                                       
#define DAC_DHR8R1_DACC1DHR_Msk     (0xFFU << DAC_DHR8R1_DACC1DHR_Pos)         /*!< 0x000000FF */
#define DAC_DHR8R1_DACC1DHR         DAC_DHR8R1_DACC1DHR_Msk                    /*!< DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR_Pos    (0U)                                       
#define DAC_DHR12R2_DACC2DHR_Msk    (0xFFFU << DAC_DHR12R2_DACC2DHR_Pos)       /*!< 0x00000FFF */
#define DAC_DHR12R2_DACC2DHR        DAC_DHR12R2_DACC2DHR_Msk                   /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR_Pos    (4U)                                       
#define DAC_DHR12L2_DACC2DHR_Msk    (0xFFFU << DAC_DHR12L2_DACC2DHR_Pos)       /*!< 0x0000FFF0 */
#define DAC_DHR12L2_DACC2DHR        DAC_DHR12L2_DACC2DHR_Msk                   /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR_Pos     (0U)                                       
#define DAC_DHR8R2_DACC2DHR_Msk     (0xFFU << DAC_DHR8R2_DACC2DHR_Pos)         /*!< 0x000000FF */
#define DAC_DHR8R2_DACC2DHR         DAC_DHR8R2_DACC2DHR_Msk                    /*!< DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR_Pos    (0U)                                       
#define DAC_DHR12RD_DACC1DHR_Msk    (0xFFFU << DAC_DHR12RD_DACC1DHR_Pos)       /*!< 0x00000FFF */
#define DAC_DHR12RD_DACC1DHR        DAC_DHR12RD_DACC1DHR_Msk                   /*!< DAC channel1 12-bit Right aligned data */
#define DAC_DHR12RD_DACC2DHR_Pos    (16U)                                      
#define DAC_DHR12RD_DACC2DHR_Msk    (0xFFFU << DAC_DHR12RD_DACC2DHR_Pos)       /*!< 0x0FFF0000 */
#define DAC_DHR12RD_DACC2DHR        DAC_DHR12RD_DACC2DHR_Msk                   /*!< DAC channel2 12-bit Right aligned data  */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR_Pos    (4U)                                       
#define DAC_DHR12LD_DACC1DHR_Msk    (0xFFFU << DAC_DHR12LD_DACC1DHR_Pos)       /*!< 0x0000FFF0 */
#define DAC_DHR12LD_DACC1DHR        DAC_DHR12LD_DACC1DHR_Msk                   /*!< DAC channel1 12-bit Left aligned data */
#define DAC_DHR12LD_DACC2DHR_Pos    (20U)                                      
#define DAC_DHR12LD_DACC2DHR_Msk    (0xFFFU << DAC_DHR12LD_DACC2DHR_Pos)       /*!< 0xFFF00000 */
#define DAC_DHR12LD_DACC2DHR        DAC_DHR12LD_DACC2DHR_Msk                   /*!< DAC channel2 12-bit Left aligned data  */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR_Pos     (0U)                                       
#define DAC_DHR8RD_DACC1DHR_Msk     (0xFFU << DAC_DHR8RD_DACC1DHR_Pos)         /*!< 0x000000FF */
#define DAC_DHR8RD_DACC1DHR         DAC_DHR8RD_DACC1DHR_Msk                    /*!< DAC channel1 8-bit Right aligned data */
#define DAC_DHR8RD_DACC2DHR_Pos     (8U)                                       
#define DAC_DHR8RD_DACC2DHR_Msk     (0xFFU << DAC_DHR8RD_DACC2DHR_Pos)         /*!< 0x0000FF00 */
#define DAC_DHR8RD_DACC2DHR         DAC_DHR8RD_DACC2DHR_Msk                    /*!< DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR_Pos       (0U)                                       
#define DAC_DOR1_DACC1DOR_Msk       (0xFFFU << DAC_DOR1_DACC1DOR_Pos)          /*!< 0x00000FFF */
#define DAC_DOR1_DACC1DOR           DAC_DOR1_DACC1DOR_Msk                      /*!< DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR_Pos       (0U)                                       
#define DAC_DOR2_DACC2DOR_Msk       (0xFFFU << DAC_DOR2_DACC2DOR_Pos)          /*!< 0x00000FFF */
#define DAC_DOR2_DACC2DOR           DAC_DOR2_DACC2DOR_Msk                      /*!< DAC channel2 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define DAC_SR_DMAUDR1_Pos          (13U)                                      
#define DAC_SR_DMAUDR1_Msk          (0x1U << DAC_SR_DMAUDR1_Pos)               /*!< 0x00002000 */
#define DAC_SR_DMAUDR1              DAC_SR_DMAUDR1_Msk                         /*!< DAC channel1 DMA underrun flag */
#define DAC_SR_DMAUDR2_Pos          (29U)                                      
#define DAC_SR_DMAUDR2_Msk          (0x1U << DAC_SR_DMAUDR2_Pos)               /*!< 0x20000000 */
#define DAC_SR_DMAUDR2              DAC_SR_DMAUDR2_Msk                         /*!< DAC channel2 DMA underrun flag  */

/******************************************************************************/
/*                                                                            */
/*                           Debug MCU (DBGMCU)                               */
/*                                                                            */
/******************************************************************************/

/****************  Bit definition for DBGMCU_IDCODE register  *****************/
#define DBGMCU_IDCODE_DEV_ID_Pos                     (0U)                      
#define DBGMCU_IDCODE_DEV_ID_Msk                     (0xFFFU << DBGMCU_IDCODE_DEV_ID_Pos) /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                         DBGMCU_IDCODE_DEV_ID_Msk  /*!< Device Identifier */

#define DBGMCU_IDCODE_REV_ID_Pos                     (16U)                     
#define DBGMCU_IDCODE_REV_ID_Msk                     (0xFFFFU << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                         DBGMCU_IDCODE_REV_ID_Msk  /*!< REV_ID[15:0] bits (Revision Identifier) */
#define DBGMCU_IDCODE_REV_ID_0                       (0x0001U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00010000 */
#define DBGMCU_IDCODE_REV_ID_1                       (0x0002U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00020000 */
#define DBGMCU_IDCODE_REV_ID_2                       (0x0004U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00040000 */
#define DBGMCU_IDCODE_REV_ID_3                       (0x0008U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00080000 */
#define DBGMCU_IDCODE_REV_ID_4                       (0x0010U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00100000 */
#define DBGMCU_IDCODE_REV_ID_5                       (0x0020U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00200000 */
#define DBGMCU_IDCODE_REV_ID_6                       (0x0040U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00400000 */
#define DBGMCU_IDCODE_REV_ID_7                       (0x0080U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x00800000 */
#define DBGMCU_IDCODE_REV_ID_8                       (0x0100U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x01000000 */
#define DBGMCU_IDCODE_REV_ID_9                       (0x0200U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x02000000 */
#define DBGMCU_IDCODE_REV_ID_10                      (0x0400U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x04000000 */
#define DBGMCU_IDCODE_REV_ID_11                      (0x0800U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x08000000 */
#define DBGMCU_IDCODE_REV_ID_12                      (0x1000U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x10000000 */
#define DBGMCU_IDCODE_REV_ID_13                      (0x2000U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x20000000 */
#define DBGMCU_IDCODE_REV_ID_14                      (0x4000U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x40000000 */
#define DBGMCU_IDCODE_REV_ID_15                      (0x8000U << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0x80000000 */

/******************  Bit definition for DBGMCU_CR register  *******************/
#define DBGMCU_CR_DBG_STOP_Pos                       (1U)                      
#define DBGMCU_CR_DBG_STOP_Msk                       (0x1U << DBGMCU_CR_DBG_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                           DBGMCU_CR_DBG_STOP_Msk    /*!< Debug Stop Mode */
#define DBGMCU_CR_DBG_STANDBY_Pos                    (2U)                      
#define DBGMCU_CR_DBG_STANDBY_Msk                    (0x1U << DBGMCU_CR_DBG_STANDBY_Pos) /*!< 0x00000004 */
#define DBGMCU_CR_DBG_STANDBY                        DBGMCU_CR_DBG_STANDBY_Msk /*!< Debug Standby mode */

/******************  Bit definition for DBGMCU_APB1_FZ register  **************/
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos             (0U)                      
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos) /*!< 0x00000001 */
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP                 DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk /*!< TIM2 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos             (1U)                      
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos) /*!< 0x00000002 */
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP                 DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk /*!< TIM3 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos             (4U)                      
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos) /*!< 0x00000010 */
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP                 DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk /*!< TIM6 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos             (5U)                      
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos) /*!< 0x00000020 */
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP                 DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk /*!< TIM7 counter stopped when core is halted  */
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos            (8U)                      
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk            (0x1U << DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos) /*!< 0x00000100 */
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP                DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk /*!< TIM14 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos              (10U)                     
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk              (0x1U << DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos) /*!< 0x00000400 */
#define DBGMCU_APB1_FZ_DBG_RTC_STOP                  DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk /*!< RTC Calendar frozen when core is halted */
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos             (11U)                     
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos) /*!< 0x00000800 */
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP                 DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk /*!< Debug Window Watchdog stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos             (12U)                     
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos) /*!< 0x00001000 */
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP                 DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk /*!< Debug Independent Watchdog stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos    (21U)                     
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk    (0x1U << DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos) /*!< 0x00200000 */
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk /*!< I2C1 SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_APB1_FZ_DBG_CAN_STOP_Pos              (25U)                     
#define DBGMCU_APB1_FZ_DBG_CAN_STOP_Msk              (0x1U << DBGMCU_APB1_FZ_DBG_CAN_STOP_Pos) /*!< 0x02000000 */
#define DBGMCU_APB1_FZ_DBG_CAN_STOP                  DBGMCU_APB1_FZ_DBG_CAN_STOP_Msk /*!< CAN debug stopped when Core is halted  */

/******************  Bit definition for DBGMCU_APB2_FZ register  **************/
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos             (11U)                     
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk             (0x1U << DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos) /*!< 0x00000800 */
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP                 DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk /*!< TIM1 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP_Pos            (16U)                     
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP_Msk            (0x1U << DBGMCU_APB2_FZ_DBG_TIM15_STOP_Pos) /*!< 0x00010000 */
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP                DBGMCU_APB2_FZ_DBG_TIM15_STOP_Msk /*!< TIM15 counter stopped when core is halted  */
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP_Pos            (17U)                     
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP_Msk            (0x1U << DBGMCU_APB2_FZ_DBG_TIM16_STOP_Pos) /*!< 0x00020000 */
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP                DBGMCU_APB2_FZ_DBG_TIM16_STOP_Msk /*!< TIM16 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP_Pos            (18U)                     
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP_Msk            (0x1U << DBGMCU_APB2_FZ_DBG_TIM17_STOP_Pos) /*!< 0x00040000 */
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP                DBGMCU_APB2_FZ_DBG_TIM17_STOP_Msk /*!< TIM17 counter stopped when core is halted */

/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for DMA_ISR register  ********************/
#define DMA_ISR_GIF1_Pos       (0U)                                            
#define DMA_ISR_GIF1_Msk       (0x1U << DMA_ISR_GIF1_Pos)                      /*!< 0x00000001 */
#define DMA_ISR_GIF1           DMA_ISR_GIF1_Msk                                /*!< Channel 1 Global interrupt flag    */
#define DMA_ISR_TCIF1_Pos      (1U)                                            
#define DMA_ISR_TCIF1_Msk      (0x1U << DMA_ISR_TCIF1_Pos)                     /*!< 0x00000002 */
#define DMA_ISR_TCIF1          DMA_ISR_TCIF1_Msk                               /*!< Channel 1 Transfer Complete flag   */
#define DMA_ISR_HTIF1_Pos      (2U)                                            
#define DMA_ISR_HTIF1_Msk      (0x1U << DMA_ISR_HTIF1_Pos)                     /*!< 0x00000004 */
#define DMA_ISR_HTIF1          DMA_ISR_HTIF1_Msk                               /*!< Channel 1 Half Transfer flag       */
#define DMA_ISR_TEIF1_Pos      (3U)                                            
#define DMA_ISR_TEIF1_Msk      (0x1U << DMA_ISR_TEIF1_Pos)                     /*!< 0x00000008 */
#define DMA_ISR_TEIF1          DMA_ISR_TEIF1_Msk                               /*!< Channel 1 Transfer Error flag      */
#define DMA_ISR_GIF2_Pos       (4U)                                            
#define DMA_ISR_GIF2_Msk       (0x1U << DMA_ISR_GIF2_Pos)                      /*!< 0x00000010 */
#define DMA_ISR_GIF2           DMA_ISR_GIF2_Msk                                /*!< Channel 2 Global interrupt flag    */
#define DMA_ISR_TCIF2_Pos      (5U)                                            
#define DMA_ISR_TCIF2_Msk      (0x1U << DMA_ISR_TCIF2_Pos)                     /*!< 0x00000020 */
#define DMA_ISR_TCIF2          DMA_ISR_TCIF2_Msk                               /*!< Channel 2 Transfer Complete flag   */
#define DMA_ISR_HTIF2_Pos      (6U)                                            
#define DMA_ISR_HTIF2_Msk      (0x1U << DMA_ISR_HTIF2_Pos)                     /*!< 0x00000040 */
#define DMA_ISR_HTIF2          DMA_ISR_HTIF2_Msk                               /*!< Channel 2 Half Transfer flag       */
#define DMA_ISR_TEIF2_Pos      (7U)                                            
#define DMA_ISR_TEIF2_Msk      (0x1U << DMA_ISR_TEIF2_Pos)                     /*!< 0x00000080 */
#define DMA_ISR_TEIF2          DMA_ISR_TEIF2_Msk                               /*!< Channel 2 Transfer Error flag      */
#define DMA_ISR_GIF3_Pos       (8U)                                            
#define DMA_ISR_GIF3_Msk       (0x1U << DMA_ISR_GIF3_Pos)                      /*!< 0x00000100 */
#define DMA_ISR_GIF3           DMA_ISR_GIF3_Msk                                /*!< Channel 3 Global interrupt flag    */
#define DMA_ISR_TCIF3_Pos      (9U)                                            
#define DMA_ISR_TCIF3_Msk      (0x1U << DMA_ISR_TCIF3_Pos)                     /*!< 0x00000200 */
#define DMA_ISR_TCIF3          DMA_ISR_TCIF3_Msk                               /*!< Channel 3 Transfer Complete flag   */
#define DMA_ISR_HTIF3_Pos      (10U)                                           
#define DMA_ISR_HTIF3_Msk      (0x1U << DMA_ISR_HTIF3_Pos)                     /*!< 0x00000400 */
#define DMA_ISR_HTIF3          DMA_ISR_HTIF3_Msk                               /*!< Channel 3 Half Transfer flag       */
#define DMA_ISR_TEIF3_Pos      (11U)                                           
#define DMA_ISR_TEIF3_Msk      (0x1U << DMA_ISR_TEIF3_Pos)                     /*!< 0x00000800 */
#define DMA_ISR_TEIF3          DMA_ISR_TEIF3_Msk                               /*!< Channel 3 Transfer Error flag      */
#define DMA_ISR_GIF4_Pos       (12U)                                           
#define DMA_ISR_GIF4_Msk       (0x1U << DMA_ISR_GIF4_Pos)                      /*!< 0x00001000 */
#define DMA_ISR_GIF4           DMA_ISR_GIF4_Msk                                /*!< Channel 4 Global interrupt flag    */
#define DMA_ISR_TCIF4_Pos      (13U)                                           
#define DMA_ISR_TCIF4_Msk      (0x1U << DMA_ISR_TCIF4_Pos)                     /*!< 0x00002000 */
#define DMA_ISR_TCIF4          DMA_ISR_TCIF4_Msk                               /*!< Channel 4 Transfer Complete flag   */
#define DMA_ISR_HTIF4_Pos      (14U)                                           
#define DMA_ISR_HTIF4_Msk      (0x1U << DMA_ISR_HTIF4_Pos)                     /*!< 0x00004000 */
#define DMA_ISR_HTIF4          DMA_ISR_HTIF4_Msk                               /*!< Channel 4 Half Transfer flag       */
#define DMA_ISR_TEIF4_Pos      (15U)                                           
#define DMA_ISR_TEIF4_Msk      (0x1U << DMA_ISR_TEIF4_Pos)                     /*!< 0x00008000 */
#define DMA_ISR_TEIF4          DMA_ISR_TEIF4_Msk                               /*!< Channel 4 Transfer Error flag      */
#define DMA_ISR_GIF5_Pos       (16U)                                           
#define DMA_ISR_GIF5_Msk       (0x1U << DMA_ISR_GIF5_Pos)                      /*!< 0x00010000 */
#define DMA_ISR_GIF5           DMA_ISR_GIF5_Msk                                /*!< Channel 5 Global interrupt flag    */
#define DMA_ISR_TCIF5_Pos      (17U)                                           
#define DMA_ISR_TCIF5_Msk      (0x1U << DMA_ISR_TCIF5_Pos)                     /*!< 0x00020000 */
#define DMA_ISR_TCIF5          DMA_ISR_TCIF5_Msk                               /*!< Channel 5 Transfer Complete flag   */
#define DMA_ISR_HTIF5_Pos      (18U)                                           
#define DMA_ISR_HTIF5_Msk      (0x1U << DMA_ISR_HTIF5_Pos)                     /*!< 0x00040000 */
#define DMA_ISR_HTIF5          DMA_ISR_HTIF5_Msk                               /*!< Channel 5 Half Transfer flag       */
#define DMA_ISR_TEIF5_Pos      (19U)                                           
#define DMA_ISR_TEIF5_Msk      (0x1U << DMA_ISR_TEIF5_Pos)                     /*!< 0x00080000 */
#define DMA_ISR_TEIF5          DMA_ISR_TEIF5_Msk                               /*!< Channel 5 Transfer Error flag      */
#define DMA_ISR_GIF6_Pos       (20U)                                           
#define DMA_ISR_GIF6_Msk       (0x1U << DMA_ISR_GIF6_Pos)                      /*!< 0x00100000 */
#define DMA_ISR_GIF6           DMA_ISR_GIF6_Msk                                /*!< Channel 6 Global interrupt flag    */
#define DMA_ISR_TCIF6_Pos      (21U)                                           
#define DMA_ISR_TCIF6_Msk      (0x1U << DMA_ISR_TCIF6_Pos)                     /*!< 0x00200000 */
#define DMA_ISR_TCIF6          DMA_ISR_TCIF6_Msk                               /*!< Channel 6 Transfer Complete flag   */
#define DMA_ISR_HTIF6_Pos      (22U)                                           
#define DMA_ISR_HTIF6_Msk      (0x1U << DMA_ISR_HTIF6_Pos)                     /*!< 0x00400000 */
#define DMA_ISR_HTIF6          DMA_ISR_HTIF6_Msk                               /*!< Channel 6 Half Transfer flag       */
#define DMA_ISR_TEIF6_Pos      (23U)                                           
#define DMA_ISR_TEIF6_Msk      (0x1U << DMA_ISR_TEIF6_Pos)                     /*!< 0x00800000 */
#define DMA_ISR_TEIF6          DMA_ISR_TEIF6_Msk                               /*!< Channel 6 Transfer Error flag      */
#define DMA_ISR_GIF7_Pos       (24U)                                           
#define DMA_ISR_GIF7_Msk       (0x1U << DMA_ISR_GIF7_Pos)                      /*!< 0x01000000 */
#define DMA_ISR_GIF7           DMA_ISR_GIF7_Msk                                /*!< Channel 7 Global interrupt flag    */
#define DMA_ISR_TCIF7_Pos      (25U)                                           
#define DMA_ISR_TCIF7_Msk      (0x1U << DMA_ISR_TCIF7_Pos)                     /*!< 0x02000000 */
#define DMA_ISR_TCIF7          DMA_ISR_TCIF7_Msk                               /*!< Channel 7 Transfer Complete flag   */
#define DMA_ISR_HTIF7_Pos      (26U)                                           
#define DMA_ISR_HTIF7_Msk      (0x1U << DMA_ISR_HTIF7_Pos)                     /*!< 0x04000000 */
#define DMA_ISR_HTIF7          DMA_ISR_HTIF7_Msk                               /*!< Channel 7 Half Transfer flag       */
#define DMA_ISR_TEIF7_Pos      (27U)                                           
#define DMA_ISR_TEIF7_Msk      (0x1U << DMA_ISR_TEIF7_Pos)                     /*!< 0x08000000 */
#define DMA_ISR_TEIF7          DMA_ISR_TEIF7_Msk                               /*!< Channel 7 Transfer Error flag      */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define DMA_IFCR_CGIF1_Pos     (0U)                                            
#define DMA_IFCR_CGIF1_Msk     (0x1U << DMA_IFCR_CGIF1_Pos)                    /*!< 0x00000001 */
#define DMA_IFCR_CGIF1         DMA_IFCR_CGIF1_Msk                              /*!< Channel 1 Global interrupt clear    */
#define DMA_IFCR_CTCIF1_Pos    (1U)                                            
#define DMA_IFCR_CTCIF1_Msk    (0x1U << DMA_IFCR_CTCIF1_Pos)                   /*!< 0x00000002 */
#define DMA_IFCR_CTCIF1        DMA_IFCR_CTCIF1_Msk                             /*!< Channel 1 Transfer Complete clear   */
#define DMA_IFCR_CHTIF1_Pos    (2U)                                            
#define DMA_IFCR_CHTIF1_Msk    (0x1U << DMA_IFCR_CHTIF1_Pos)                   /*!< 0x00000004 */
#define DMA_IFCR_CHTIF1        DMA_IFCR_CHTIF1_Msk                             /*!< Channel 1 Half Transfer clear       */
#define DMA_IFCR_CTEIF1_Pos    (3U)                                            
#define DMA_IFCR_CTEIF1_Msk    (0x1U << DMA_IFCR_CTEIF1_Pos)                   /*!< 0x00000008 */
#define DMA_IFCR_CTEIF1        DMA_IFCR_CTEIF1_Msk                             /*!< Channel 1 Transfer Error clear      */
#define DMA_IFCR_CGIF2_Pos     (4U)                                            
#define DMA_IFCR_CGIF2_Msk     (0x1U << DMA_IFCR_CGIF2_Pos)                    /*!< 0x00000010 */
#define DMA_IFCR_CGIF2         DMA_IFCR_CGIF2_Msk                              /*!< Channel 2 Global interrupt clear    */
#define DMA_IFCR_CTCIF2_Pos    (5U)                                            
#define DMA_IFCR_CTCIF2_Msk    (0x1U << DMA_IFCR_CTCIF2_Pos)                   /*!< 0x00000020 */
#define DMA_IFCR_CTCIF2        DMA_IFCR_CTCIF2_Msk                             /*!< Channel 2 Transfer Complete clear   */
#define DMA_IFCR_CHTIF2_Pos    (6U)                                            
#define DMA_IFCR_CHTIF2_Msk    (0x1U << DMA_IFCR_CHTIF2_Pos)                   /*!< 0x00000040 */
#define DMA_IFCR_CHTIF2        DMA_IFCR_CHTIF2_Msk                             /*!< Channel 2 Half Transfer clear       */
#define DMA_IFCR_CTEIF2_Pos    (7U)                                            
#define DMA_IFCR_CTEIF2_Msk    (0x1U << DMA_IFCR_CTEIF2_Pos)                   /*!< 0x00000080 */
#define DMA_IFCR_CTEIF2        DMA_IFCR_CTEIF2_Msk                             /*!< Channel 2 Transfer Error clear      */
#define DMA_IFCR_CGIF3_Pos     (8U)                                            
#define DMA_IFCR_CGIF3_Msk     (0x1U << DMA_IFCR_CGIF3_Pos)                    /*!< 0x00000100 */
#define DMA_IFCR_CGIF3         DMA_IFCR_CGIF3_Msk                              /*!< Channel 3 Global interrupt clear    */
#define DMA_IFCR_CTCIF3_Pos    (9U)                                            
#define DMA_IFCR_CTCIF3_Msk    (0x1U << DMA_IFCR_CTCIF3_Pos)                   /*!< 0x00000200 */
#define DMA_IFCR_CTCIF3        DMA_IFCR_CTCIF3_Msk                             /*!< Channel 3 Transfer Complete clear   */
#define DMA_IFCR_CHTIF3_Pos    (10U)                                           
#define DMA_IFCR_CHTIF3_Msk    (0x1U << DMA_IFCR_CHTIF3_Pos)                   /*!< 0x00000400 */
#define DMA_IFCR_CHTIF3        DMA_IFCR_CHTIF3_Msk                             /*!< Channel 3 Half Transfer clear       */
#define DMA_IFCR_CTEIF3_Pos    (11U)                                           
#define DMA_IFCR_CTEIF3_Msk    (0x1U << DMA_IFCR_CTEIF3_Pos)                   /*!< 0x00000800 */
#define DMA_IFCR_CTEIF3        DMA_IFCR_CTEIF3_Msk                             /*!< Channel 3 Transfer Error clear      */
#define DMA_IFCR_CGIF4_Pos     (12U)                                           
#define DMA_IFCR_CGIF4_Msk     (0x1U << DMA_IFCR_CGIF4_Pos)                    /*!< 0x00001000 */
#define DMA_IFCR_CGIF4         DMA_IFCR_CGIF4_Msk                              /*!< Channel 4 Global interrupt clear    */
#define DMA_IFCR_CTCIF4_Pos    (13U)                                           
#define DMA_IFCR_CTCIF4_Msk    (0x1U << DMA_IFCR_CTCIF4_Pos)                   /*!< 0x00002000 */
#define DMA_IFCR_CTCIF4        DMA_IFCR_CTCIF4_Msk                             /*!< Channel 4 Transfer Complete clear   */
#define DMA_IFCR_CHTIF4_Pos    (14U)                                           
#define DMA_IFCR_CHTIF4_Msk    (0x1U << DMA_IFCR_CHTIF4_Pos)                   /*!< 0x00004000 */
#define DMA_IFCR_CHTIF4        DMA_IFCR_CHTIF4_Msk                             /*!< Channel 4 Half Transfer clear       */
#define DMA_IFCR_CTEIF4_Pos    (15U)                                           
#define DMA_IFCR_CTEIF4_Msk    (0x1U << DMA_IFCR_CTEIF4_Pos)                   /*!< 0x00008000 */
#define DMA_IFCR_CTEIF4        DMA_IFCR_CTEIF4_Msk                             /*!< Channel 4 Transfer Error clear      */
#define DMA_IFCR_CGIF5_Pos     (16U)                                           
#define DMA_IFCR_CGIF5_Msk     (0x1U << DMA_IFCR_CGIF5_Pos)                    /*!< 0x00010000 */
#define DMA_IFCR_CGIF5         DMA_IFCR_CGIF5_Msk                              /*!< Channel 5 Global interrupt clear    */
#define DMA_IFCR_CTCIF5_Pos    (17U)                                           
#define DMA_IFCR_CTCIF5_Msk    (0x1U << DMA_IFCR_CTCIF5_Pos)                   /*!< 0x00020000 */
#define DMA_IFCR_CTCIF5        DMA_IFCR_CTCIF5_Msk                             /*!< Channel 5 Transfer Complete clear   */
#define DMA_IFCR_CHTIF5_Pos    (18U)                                           
#define DMA_IFCR_CHTIF5_Msk    (0x1U << DMA_IFCR_CHTIF5_Pos)                   /*!< 0x00040000 */
#define DMA_IFCR_CHTIF5        DMA_IFCR_CHTIF5_Msk                             /*!< Channel 5 Half Transfer clear       */
#define DMA_IFCR_CTEIF5_Pos    (19U)                                           
#define DMA_IFCR_CTEIF5_Msk    (0x1U << DMA_IFCR_CTEIF5_Pos)                   /*!< 0x00080000 */
#define DMA_IFCR_CTEIF5        DMA_IFCR_CTEIF5_Msk                             /*!< Channel 5 Transfer Error clear      */
#define DMA_IFCR_CGIF6_Pos     (20U)                                           
#define DMA_IFCR_CGIF6_Msk     (0x1U << DMA_IFCR_CGIF6_Pos)                    /*!< 0x00100000 */
#define DMA_IFCR_CGIF6         DMA_IFCR_CGIF6_Msk                              /*!< Channel 6 Global interrupt clear    */
#define DMA_IFCR_CTCIF6_Pos    (21U)                                           
#define DMA_IFCR_CTCIF6_Msk    (0x1U << DMA_IFCR_CTCIF6_Pos)                   /*!< 0x00200000 */
#define DMA_IFCR_CTCIF6        DMA_IFCR_CTCIF6_Msk                             /*!< Channel 6 Transfer Complete clear   */
#define DMA_IFCR_CHTIF6_Pos    (22U)                                           
#define DMA_IFCR_CHTIF6_Msk    (0x1U << DMA_IFCR_CHTIF6_Pos)                   /*!< 0x00400000 */
#define DMA_IFCR_CHTIF6        DMA_IFCR_CHTIF6_Msk                             /*!< Channel 6 Half Transfer clear       */
#define DMA_IFCR_CTEIF6_Pos    (23U)                                           
#define DMA_IFCR_CTEIF6_Msk    (0x1U << DMA_IFCR_CTEIF6_Pos)                   /*!< 0x00800000 */
#define DMA_IFCR_CTEIF6        DMA_IFCR_CTEIF6_Msk                             /*!< Channel 6 Transfer Error clear      */
#define DMA_IFCR_CGIF7_Pos     (24U)                                           
#define DMA_IFCR_CGIF7_Msk     (0x1U << DMA_IFCR_CGIF7_Pos)                    /*!< 0x01000000 */
#define DMA_IFCR_CGIF7         DMA_IFCR_CGIF7_Msk                              /*!< Channel 7 Global interrupt clear    */
#define DMA_IFCR_CTCIF7_Pos    (25U)                                           
#define DMA_IFCR_CTCIF7_Msk    (0x1U << DMA_IFCR_CTCIF7_Pos)                   /*!< 0x02000000 */
#define DMA_IFCR_CTCIF7        DMA_IFCR_CTCIF7_Msk                             /*!< Channel 7 Transfer Complete clear   */
#define DMA_IFCR_CHTIF7_Pos    (26U)                                           
#define DMA_IFCR_CHTIF7_Msk    (0x1U << DMA_IFCR_CHTIF7_Pos)                   /*!< 0x04000000 */
#define DMA_IFCR_CHTIF7        DMA_IFCR_CHTIF7_Msk                             /*!< Channel 7 Half Transfer clear       */
#define DMA_IFCR_CTEIF7_Pos    (27U)                                           
#define DMA_IFCR_CTEIF7_Msk    (0x1U << DMA_IFCR_CTEIF7_Pos)                   /*!< 0x08000000 */
#define DMA_IFCR_CTEIF7        DMA_IFCR_CTEIF7_Msk                             /*!< Channel 7 Transfer Error clear      */

/*******************  Bit definition for DMA_CCR register  ********************/
#define DMA_CCR_EN_Pos         (0U)                                            
#define DMA_CCR_EN_Msk         (0x1U << DMA_CCR_EN_Pos)                        /*!< 0x00000001 */
#define DMA_CCR_EN             DMA_CCR_EN_Msk                                  /*!< Channel enable                      */
#define DMA_CCR_TCIE_Pos       (1U)                                            
#define DMA_CCR_TCIE_Msk       (0x1U << DMA_CCR_TCIE_Pos)                      /*!< 0x00000002 */
#define DMA_CCR_TCIE           DMA_CCR_TCIE_Msk                                /*!< Transfer complete interrupt enable  */
#define DMA_CCR_HTIE_Pos       (2U)                                            
#define DMA_CCR_HTIE_Msk       (0x1U << DMA_CCR_HTIE_Pos)                      /*!< 0x00000004 */
#define DMA_CCR_HTIE           DMA_CCR_HTIE_Msk                                /*!< Half Transfer interrupt enable      */
#define DMA_CCR_TEIE_Pos       (3U)                                            
#define DMA_CCR_TEIE_Msk       (0x1U << DMA_CCR_TEIE_Pos)                      /*!< 0x00000008 */
#define DMA_CCR_TEIE           DMA_CCR_TEIE_Msk                                /*!< Transfer error interrupt enable     */
#define DMA_CCR_DIR_Pos        (4U)                                            
#define DMA_CCR_DIR_Msk        (0x1U << DMA_CCR_DIR_Pos)                       /*!< 0x00000010 */
#define DMA_CCR_DIR            DMA_CCR_DIR_Msk                                 /*!< Data transfer direction             */
#define DMA_CCR_CIRC_Pos       (5U)                                            
#define DMA_CCR_CIRC_Msk       (0x1U << DMA_CCR_CIRC_Pos)                      /*!< 0x00000020 */
#define DMA_CCR_CIRC           DMA_CCR_CIRC_Msk                                /*!< Circular mode                       */
#define DMA_CCR_PINC_Pos       (6U)                                            
#define DMA_CCR_PINC_Msk       (0x1U << DMA_CCR_PINC_Pos)                      /*!< 0x00000040 */
#define DMA_CCR_PINC           DMA_CCR_PINC_Msk                                /*!< Peripheral increment mode           */
#define DMA_CCR_MINC_Pos       (7U)                                            
#define DMA_CCR_MINC_Msk       (0x1U << DMA_CCR_MINC_Pos)                      /*!< 0x00000080 */
#define DMA_CCR_MINC           DMA_CCR_MINC_Msk                                /*!< Memory increment mode               */

#define DMA_CCR_PSIZE_Pos      (8U)                                            
#define DMA_CCR_PSIZE_Msk      (0x3U << DMA_CCR_PSIZE_Pos)                     /*!< 0x00000300 */
#define DMA_CCR_PSIZE          DMA_CCR_PSIZE_Msk                               /*!< PSIZE[1:0] bits (Peripheral size)   */
#define DMA_CCR_PSIZE_0        (0x1U << DMA_CCR_PSIZE_Pos)                     /*!< 0x00000100 */
#define DMA_CCR_PSIZE_1        (0x2U << DMA_CCR_PSIZE_Pos)                     /*!< 0x00000200 */

#define DMA_CCR_MSIZE_Pos      (10U)                                           
#define DMA_CCR_MSIZE_Msk      (0x3U << DMA_CCR_MSIZE_Pos)                     /*!< 0x00000C00 */
#define DMA_CCR_MSIZE          DMA_CCR_MSIZE_Msk                               /*!< MSIZE[1:0] bits (Memory size)       */
#define DMA_CCR_MSIZE_0        (0x1U << DMA_CCR_MSIZE_Pos)                     /*!< 0x00000400 */
#define DMA_CCR_MSIZE_1        (0x2U << DMA_CCR_MSIZE_Pos)                     /*!< 0x00000800 */

#define DMA_CCR_PL_Pos         (12U)                                           
#define DMA_CCR_PL_Msk         (0x3U << DMA_CCR_PL_Pos)                        /*!< 0x00003000 */
#define DMA_CCR_PL             DMA_CCR_PL_Msk                                  /*!< PL[1:0] bits(Channel Priority level)*/
#define DMA_CCR_PL_0           (0x1U << DMA_CCR_PL_Pos)                        /*!< 0x00001000 */
#define DMA_CCR_PL_1           (0x2U << DMA_CCR_PL_Pos)                        /*!< 0x00002000 */

#define DMA_CCR_MEM2MEM_Pos    (14U)                                           
#define DMA_CCR_MEM2MEM_Msk    (0x1U << DMA_CCR_MEM2MEM_Pos)                   /*!< 0x00004000 */
#define DMA_CCR_MEM2MEM        DMA_CCR_MEM2MEM_Msk                             /*!< Memory to memory mode               */

/******************  Bit definition for DMA_CNDTR register  *******************/
#define DMA_CNDTR_NDT_Pos      (0U)                                            
#define DMA_CNDTR_NDT_Msk      (0xFFFFU << DMA_CNDTR_NDT_Pos)                  /*!< 0x0000FFFF */
#define DMA_CNDTR_NDT          DMA_CNDTR_NDT_Msk                               /*!< Number of data to Transfer          */

/******************  Bit definition for DMA_CPAR register  ********************/
#define DMA_CPAR_PA_Pos        (0U)                                            
#define DMA_CPAR_PA_Msk        (0xFFFFFFFFU << DMA_CPAR_PA_Pos)                /*!< 0xFFFFFFFF */
#define DMA_CPAR_PA            DMA_CPAR_PA_Msk                                 /*!< Peripheral Address                  */

/******************  Bit definition for DMA_CMAR register  ********************/
#define DMA_CMAR_MA_Pos        (0U)                                            
#define DMA_CMAR_MA_Msk        (0xFFFFFFFFU << DMA_CMAR_MA_Pos)                /*!< 0xFFFFFFFF */
#define DMA_CMAR_MA            DMA_CMAR_MA_Msk                                 /*!< Memory Address                      */

/******************  Bit definition for DMA1_CSELR register  ********************/
#define DMA_CSELR_C1S_Pos      (0U)                                            
#define DMA_CSELR_C1S_Msk      (0xFU << DMA_CSELR_C1S_Pos)                     /*!< 0x0000000F */
#define DMA_CSELR_C1S          DMA_CSELR_C1S_Msk                               /*!< Channel 1 Selection */
#define DMA_CSELR_C2S_Pos      (4U)                                            
#define DMA_CSELR_C2S_Msk      (0xFU << DMA_CSELR_C2S_Pos)                     /*!< 0x000000F0 */
#define DMA_CSELR_C2S          DMA_CSELR_C2S_Msk                               /*!< Channel 2 Selection */
#define DMA_CSELR_C3S_Pos      (8U)                                            
#define DMA_CSELR_C3S_Msk      (0xFU << DMA_CSELR_C3S_Pos)                     /*!< 0x00000F00 */
#define DMA_CSELR_C3S          DMA_CSELR_C3S_Msk                               /*!< Channel 3 Selection */
#define DMA_CSELR_C4S_Pos      (12U)                                           
#define DMA_CSELR_C4S_Msk      (0xFU << DMA_CSELR_C4S_Pos)                     /*!< 0x0000F000 */
#define DMA_CSELR_C4S          DMA_CSELR_C4S_Msk                               /*!< Channel 4 Selection */
#define DMA_CSELR_C5S_Pos      (16U)                                           
#define DMA_CSELR_C5S_Msk      (0xFU << DMA_CSELR_C5S_Pos)                     /*!< 0x000F0000 */
#define DMA_CSELR_C5S          DMA_CSELR_C5S_Msk                               /*!< Channel 5 Selection */
#define DMA_CSELR_C6S_Pos      (20U)                                           
#define DMA_CSELR_C6S_Msk      (0xFU << DMA_CSELR_C6S_Pos)                     /*!< 0x00F00000 */
#define DMA_CSELR_C6S          DMA_CSELR_C6S_Msk                               /*!< Channel 6 Selection */
#define DMA_CSELR_C7S_Pos      (24U)                                           
#define DMA_CSELR_C7S_Msk      (0xFU << DMA_CSELR_C7S_Pos)                     /*!< 0x0F000000 */
#define DMA_CSELR_C7S          DMA_CSELR_C7S_Msk                               /*!< Channel 7 Selection */

#define DMA1_CSELR_DEFAULT              (0x00000000U)                          /*!< Default remap position for DMA1 */
#define DMA1_CSELR_CH1_ADC_Pos          (0U)                                   
#define DMA1_CSELR_CH1_ADC_Msk          (0x1U << DMA1_CSELR_CH1_ADC_Pos)       /*!< 0x00000001 */
#define DMA1_CSELR_CH1_ADC              DMA1_CSELR_CH1_ADC_Msk                 /*!< Remap ADC on DMA1 Channel 1*/
#define DMA1_CSELR_CH1_TIM17_CH1_Pos    (0U)                                   
#define DMA1_CSELR_CH1_TIM17_CH1_Msk    (0x7U << DMA1_CSELR_CH1_TIM17_CH1_Pos) /*!< 0x00000007 */
#define DMA1_CSELR_CH1_TIM17_CH1        DMA1_CSELR_CH1_TIM17_CH1_Msk           /*!< Remap TIM17 channel 1 on DMA1 channel 1 */
#define DMA1_CSELR_CH1_TIM17_UP_Pos     (0U)                                   
#define DMA1_CSELR_CH1_TIM17_UP_Msk     (0x7U << DMA1_CSELR_CH1_TIM17_UP_Pos)  /*!< 0x00000007 */
#define DMA1_CSELR_CH1_TIM17_UP         DMA1_CSELR_CH1_TIM17_UP_Msk            /*!< Remap TIM17 up on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART1_RX_Pos    (3U)                                   
#define DMA1_CSELR_CH1_USART1_RX_Msk    (0x1U << DMA1_CSELR_CH1_USART1_RX_Pos) /*!< 0x00000008 */
#define DMA1_CSELR_CH1_USART1_RX        DMA1_CSELR_CH1_USART1_RX_Msk           /*!< Remap USART1 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART2_RX_Pos    (0U)                                   
#define DMA1_CSELR_CH1_USART2_RX_Msk    (0x9U << DMA1_CSELR_CH1_USART2_RX_Pos) /*!< 0x00000009 */
#define DMA1_CSELR_CH1_USART2_RX        DMA1_CSELR_CH1_USART2_RX_Msk           /*!< Remap USART2 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART3_RX_Pos    (1U)                                   
#define DMA1_CSELR_CH1_USART3_RX_Msk    (0x5U << DMA1_CSELR_CH1_USART3_RX_Pos) /*!< 0x0000000A */
#define DMA1_CSELR_CH1_USART3_RX        DMA1_CSELR_CH1_USART3_RX_Msk           /*!< Remap USART3 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART4_RX_Pos    (0U)                                   
#define DMA1_CSELR_CH1_USART4_RX_Msk    (0xBU << DMA1_CSELR_CH1_USART4_RX_Pos) /*!< 0x0000000B */
#define DMA1_CSELR_CH1_USART4_RX        DMA1_CSELR_CH1_USART4_RX_Msk           /*!< Remap USART4 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART5_RX_Pos    (2U)                                   
#define DMA1_CSELR_CH1_USART5_RX_Msk    (0x3U << DMA1_CSELR_CH1_USART5_RX_Pos) /*!< 0x0000000C */
#define DMA1_CSELR_CH1_USART5_RX        DMA1_CSELR_CH1_USART5_RX_Msk           /*!< Remap USART5 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART6_RX_Pos    (0U)                                   
#define DMA1_CSELR_CH1_USART6_RX_Msk    (0xDU << DMA1_CSELR_CH1_USART6_RX_Pos) /*!< 0x0000000D */
#define DMA1_CSELR_CH1_USART6_RX        DMA1_CSELR_CH1_USART6_RX_Msk           /*!< Remap USART6 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART7_RX_Pos    (1U)                                   
#define DMA1_CSELR_CH1_USART7_RX_Msk    (0x7U << DMA1_CSELR_CH1_USART7_RX_Pos) /*!< 0x0000000E */
#define DMA1_CSELR_CH1_USART7_RX        DMA1_CSELR_CH1_USART7_RX_Msk           /*!< Remap USART7 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH1_USART8_RX_Pos    (0U)                                   
#define DMA1_CSELR_CH1_USART8_RX_Msk    (0xFU << DMA1_CSELR_CH1_USART8_RX_Pos) /*!< 0x0000000F */
#define DMA1_CSELR_CH1_USART8_RX        DMA1_CSELR_CH1_USART8_RX_Msk           /*!< Remap USART8 Rx on DMA1 channel 1 */
#define DMA1_CSELR_CH2_ADC_Pos          (4U)                                   
#define DMA1_CSELR_CH2_ADC_Msk          (0x1U << DMA1_CSELR_CH2_ADC_Pos)       /*!< 0x00000010 */
#define DMA1_CSELR_CH2_ADC              DMA1_CSELR_CH2_ADC_Msk                 /*!< Remap ADC on DMA1 channel 2 */
#define DMA1_CSELR_CH2_I2C1_TX_Pos      (5U)                                   
#define DMA1_CSELR_CH2_I2C1_TX_Msk      (0x1U << DMA1_CSELR_CH2_I2C1_TX_Pos)   /*!< 0x00000020 */
#define DMA1_CSELR_CH2_I2C1_TX          DMA1_CSELR_CH2_I2C1_TX_Msk             /*!< Remap I2C1 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_SPI1_RX_Pos      (4U)                                   
#define DMA1_CSELR_CH2_SPI1_RX_Msk      (0x3U << DMA1_CSELR_CH2_SPI1_RX_Pos)   /*!< 0x00000030 */
#define DMA1_CSELR_CH2_SPI1_RX          DMA1_CSELR_CH2_SPI1_RX_Msk             /*!< Remap SPI1 Rx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_TIM1_CH1_Pos     (6U)                                   
#define DMA1_CSELR_CH2_TIM1_CH1_Msk     (0x1U << DMA1_CSELR_CH2_TIM1_CH1_Pos)  /*!< 0x00000040 */
#define DMA1_CSELR_CH2_TIM1_CH1         DMA1_CSELR_CH2_TIM1_CH1_Msk            /*!< Remap TIM1 channel 1 on DMA1 channel 2 */
#define DMA1_CSELR_CH2_TIM17_CH1_Pos    (4U)                                   
#define DMA1_CSELR_CH2_TIM17_CH1_Msk    (0x7U << DMA1_CSELR_CH2_TIM17_CH1_Pos) /*!< 0x00000070 */
#define DMA1_CSELR_CH2_TIM17_CH1        DMA1_CSELR_CH2_TIM17_CH1_Msk           /*!< Remap TIM17 channel 1 on DMA1 channel 2 */
#define DMA1_CSELR_CH2_TIM17_UP_Pos     (4U)                                   
#define DMA1_CSELR_CH2_TIM17_UP_Msk     (0x7U << DMA1_CSELR_CH2_TIM17_UP_Pos)  /*!< 0x00000070 */
#define DMA1_CSELR_CH2_TIM17_UP         DMA1_CSELR_CH2_TIM17_UP_Msk            /*!< Remap TIM17 up on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART1_TX_Pos    (7U)                                   
#define DMA1_CSELR_CH2_USART1_TX_Msk    (0x1U << DMA1_CSELR_CH2_USART1_TX_Pos) /*!< 0x00000080 */
#define DMA1_CSELR_CH2_USART1_TX        DMA1_CSELR_CH2_USART1_TX_Msk           /*!< Remap USART1 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART2_TX_Pos    (4U)                                   
#define DMA1_CSELR_CH2_USART2_TX_Msk    (0x9U << DMA1_CSELR_CH2_USART2_TX_Pos) /*!< 0x00000090 */
#define DMA1_CSELR_CH2_USART2_TX        DMA1_CSELR_CH2_USART2_TX_Msk           /*!< Remap USART2 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART3_TX_Pos    (5U)                                   
#define DMA1_CSELR_CH2_USART3_TX_Msk    (0x5U << DMA1_CSELR_CH2_USART3_TX_Pos) /*!< 0x000000A0 */
#define DMA1_CSELR_CH2_USART3_TX        DMA1_CSELR_CH2_USART3_TX_Msk           /*!< Remap USART3 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART4_TX_Pos    (4U)                                   
#define DMA1_CSELR_CH2_USART4_TX_Msk    (0xBU << DMA1_CSELR_CH2_USART4_TX_Pos) /*!< 0x000000B0 */
#define DMA1_CSELR_CH2_USART4_TX        DMA1_CSELR_CH2_USART4_TX_Msk           /*!< Remap USART4 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART5_TX_Pos    (6U)                                   
#define DMA1_CSELR_CH2_USART5_TX_Msk    (0x3U << DMA1_CSELR_CH2_USART5_TX_Pos) /*!< 0x000000C0 */
#define DMA1_CSELR_CH2_USART5_TX        DMA1_CSELR_CH2_USART5_TX_Msk           /*!< Remap USART5 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART6_TX_Pos    (4U)                                   
#define DMA1_CSELR_CH2_USART6_TX_Msk    (0xDU << DMA1_CSELR_CH2_USART6_TX_Pos) /*!< 0x000000D0 */
#define DMA1_CSELR_CH2_USART6_TX        DMA1_CSELR_CH2_USART6_TX_Msk           /*!< Remap USART6 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART7_TX_Pos    (5U)                                   
#define DMA1_CSELR_CH2_USART7_TX_Msk    (0x7U << DMA1_CSELR_CH2_USART7_TX_Pos) /*!< 0x000000E0 */
#define DMA1_CSELR_CH2_USART7_TX        DMA1_CSELR_CH2_USART7_TX_Msk           /*!< Remap USART7 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH2_USART8_TX_Pos    (4U)                                   
#define DMA1_CSELR_CH2_USART8_TX_Msk    (0xFU << DMA1_CSELR_CH2_USART8_TX_Pos) /*!< 0x000000F0 */
#define DMA1_CSELR_CH2_USART8_TX        DMA1_CSELR_CH2_USART8_TX_Msk           /*!< Remap USART8 Tx on DMA1 channel 2 */
#define DMA1_CSELR_CH3_TIM6_UP_Pos      (8U)                                   
#define DMA1_CSELR_CH3_TIM6_UP_Msk      (0x1U << DMA1_CSELR_CH3_TIM6_UP_Pos)   /*!< 0x00000100 */
#define DMA1_CSELR_CH3_TIM6_UP          DMA1_CSELR_CH3_TIM6_UP_Msk             /*!< Remap TIM6 up on DMA1 channel 3 */
#define DMA1_CSELR_CH3_DAC_CH1_Pos      (8U)                                   
#define DMA1_CSELR_CH3_DAC_CH1_Msk      (0x1U << DMA1_CSELR_CH3_DAC_CH1_Pos)   /*!< 0x00000100 */
#define DMA1_CSELR_CH3_DAC_CH1          DMA1_CSELR_CH3_DAC_CH1_Msk             /*!< Remap DAC Channel 1on DMA1 channel 3 */
#define DMA1_CSELR_CH3_I2C1_RX_Pos      (9U)                                   
#define DMA1_CSELR_CH3_I2C1_RX_Msk      (0x1U << DMA1_CSELR_CH3_I2C1_RX_Pos)   /*!< 0x00000200 */
#define DMA1_CSELR_CH3_I2C1_RX          DMA1_CSELR_CH3_I2C1_RX_Msk             /*!< Remap I2C1 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_SPI1_TX_Pos      (8U)                                   
#define DMA1_CSELR_CH3_SPI1_TX_Msk      (0x3U << DMA1_CSELR_CH3_SPI1_TX_Pos)   /*!< 0x00000300 */
#define DMA1_CSELR_CH3_SPI1_TX          DMA1_CSELR_CH3_SPI1_TX_Msk             /*!< Remap SPI1 Tx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_TIM1_CH2_Pos     (10U)                                  
#define DMA1_CSELR_CH3_TIM1_CH2_Msk     (0x1U << DMA1_CSELR_CH3_TIM1_CH2_Pos)  /*!< 0x00000400 */
#define DMA1_CSELR_CH3_TIM1_CH2         DMA1_CSELR_CH3_TIM1_CH2_Msk            /*!< Remap TIM1 channel 2 on DMA1 channel 3 */
#define DMA1_CSELR_CH3_TIM2_CH2_Pos     (8U)                                   
#define DMA1_CSELR_CH3_TIM2_CH2_Msk     (0x5U << DMA1_CSELR_CH3_TIM2_CH2_Pos)  /*!< 0x00000500 */
#define DMA1_CSELR_CH3_TIM2_CH2         DMA1_CSELR_CH3_TIM2_CH2_Msk            /*!< Remap TIM2 channel 2 on DMA1 channel 3 */
#define DMA1_CSELR_CH3_TIM16_CH1_Pos    (8U)                                   
#define DMA1_CSELR_CH3_TIM16_CH1_Msk    (0x7U << DMA1_CSELR_CH3_TIM16_CH1_Pos) /*!< 0x00000700 */
#define DMA1_CSELR_CH3_TIM16_CH1        DMA1_CSELR_CH3_TIM16_CH1_Msk           /*!< Remap TIM16 channel 1 on DMA1 channel 3 */
#define DMA1_CSELR_CH3_TIM16_UP_Pos     (8U)                                   
#define DMA1_CSELR_CH3_TIM16_UP_Msk     (0x7U << DMA1_CSELR_CH3_TIM16_UP_Pos)  /*!< 0x00000700 */
#define DMA1_CSELR_CH3_TIM16_UP         DMA1_CSELR_CH3_TIM16_UP_Msk            /*!< Remap TIM16 up on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART1_RX_Pos    (11U)                                  
#define DMA1_CSELR_CH3_USART1_RX_Msk    (0x1U << DMA1_CSELR_CH3_USART1_RX_Pos) /*!< 0x00000800 */
#define DMA1_CSELR_CH3_USART1_RX        DMA1_CSELR_CH3_USART1_RX_Msk           /*!< Remap USART1 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART2_RX_Pos    (8U)                                   
#define DMA1_CSELR_CH3_USART2_RX_Msk    (0x9U << DMA1_CSELR_CH3_USART2_RX_Pos) /*!< 0x00000900 */
#define DMA1_CSELR_CH3_USART2_RX        DMA1_CSELR_CH3_USART2_RX_Msk           /*!< Remap USART2 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART3_RX_Pos    (9U)                                   
#define DMA1_CSELR_CH3_USART3_RX_Msk    (0x5U << DMA1_CSELR_CH3_USART3_RX_Pos) /*!< 0x00000A00 */
#define DMA1_CSELR_CH3_USART3_RX        DMA1_CSELR_CH3_USART3_RX_Msk           /*!< Remap USART3 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART4_RX_Pos    (8U)                                   
#define DMA1_CSELR_CH3_USART4_RX_Msk    (0xBU << DMA1_CSELR_CH3_USART4_RX_Pos) /*!< 0x00000B00 */
#define DMA1_CSELR_CH3_USART4_RX        DMA1_CSELR_CH3_USART4_RX_Msk           /*!< Remap USART4 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART5_RX_Pos    (10U)                                  
#define DMA1_CSELR_CH3_USART5_RX_Msk    (0x3U << DMA1_CSELR_CH3_USART5_RX_Pos) /*!< 0x00000C00 */
#define DMA1_CSELR_CH3_USART5_RX        DMA1_CSELR_CH3_USART5_RX_Msk           /*!< Remap USART5 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART6_RX_Pos    (8U)                                   
#define DMA1_CSELR_CH3_USART6_RX_Msk    (0xDU << DMA1_CSELR_CH3_USART6_RX_Pos) /*!< 0x00000D00 */
#define DMA1_CSELR_CH3_USART6_RX        DMA1_CSELR_CH3_USART6_RX_Msk           /*!< Remap USART6 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART7_RX_Pos    (9U)                                   
#define DMA1_CSELR_CH3_USART7_RX_Msk    (0x7U << DMA1_CSELR_CH3_USART7_RX_Pos) /*!< 0x00000E00 */
#define DMA1_CSELR_CH3_USART7_RX        DMA1_CSELR_CH3_USART7_RX_Msk           /*!< Remap USART7 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH3_USART8_RX_Pos    (8U)                                   
#define DMA1_CSELR_CH3_USART8_RX_Msk    (0xFU << DMA1_CSELR_CH3_USART8_RX_Pos) /*!< 0x00000F00 */
#define DMA1_CSELR_CH3_USART8_RX        DMA1_CSELR_CH3_USART8_RX_Msk           /*!< Remap USART8 Rx on DMA1 channel 3 */
#define DMA1_CSELR_CH4_TIM7_UP_Pos      (12U)                                  
#define DMA1_CSELR_CH4_TIM7_UP_Msk      (0x1U << DMA1_CSELR_CH4_TIM7_UP_Pos)   /*!< 0x00001000 */
#define DMA1_CSELR_CH4_TIM7_UP          DMA1_CSELR_CH4_TIM7_UP_Msk             /*!< Remap TIM7 up on DMA1 channel 4 */
#define DMA1_CSELR_CH4_DAC_CH2_Pos      (12U)                                  
#define DMA1_CSELR_CH4_DAC_CH2_Msk      (0x1U << DMA1_CSELR_CH4_DAC_CH2_Pos)   /*!< 0x00001000 */
#define DMA1_CSELR_CH4_DAC_CH2          DMA1_CSELR_CH4_DAC_CH2_Msk             /*!< Remap DAC Channel 2 on DMA1 channel 4 */
#define DMA1_CSELR_CH4_I2C2_TX_Pos      (13U)                                  
#define DMA1_CSELR_CH4_I2C2_TX_Msk      (0x1U << DMA1_CSELR_CH4_I2C2_TX_Pos)   /*!< 0x00002000 */
#define DMA1_CSELR_CH4_I2C2_TX          DMA1_CSELR_CH4_I2C2_TX_Msk             /*!< Remap I2C2 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_SPI2_RX_Pos      (12U)                                  
#define DMA1_CSELR_CH4_SPI2_RX_Msk      (0x3U << DMA1_CSELR_CH4_SPI2_RX_Pos)   /*!< 0x00003000 */
#define DMA1_CSELR_CH4_SPI2_RX          DMA1_CSELR_CH4_SPI2_RX_Msk             /*!< Remap SPI2 Rx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_TIM2_CH4_Pos     (12U)                                  
#define DMA1_CSELR_CH4_TIM2_CH4_Msk     (0x5U << DMA1_CSELR_CH4_TIM2_CH4_Pos)  /*!< 0x00005000 */
#define DMA1_CSELR_CH4_TIM2_CH4         DMA1_CSELR_CH4_TIM2_CH4_Msk            /*!< Remap TIM2 channel 4 on DMA1 channel 4 */
#define DMA1_CSELR_CH4_TIM3_CH1_Pos     (13U)                                  
#define DMA1_CSELR_CH4_TIM3_CH1_Msk     (0x3U << DMA1_CSELR_CH4_TIM3_CH1_Pos)  /*!< 0x00006000 */
#define DMA1_CSELR_CH4_TIM3_CH1         DMA1_CSELR_CH4_TIM3_CH1_Msk            /*!< Remap TIM3 channel 1 on DMA1 channel 4 */
#define DMA1_CSELR_CH4_TIM3_TRIG_Pos    (13U)                                  
#define DMA1_CSELR_CH4_TIM3_TRIG_Msk    (0x3U << DMA1_CSELR_CH4_TIM3_TRIG_Pos) /*!< 0x00006000 */
#define DMA1_CSELR_CH4_TIM3_TRIG        DMA1_CSELR_CH4_TIM3_TRIG_Msk           /*!< Remap TIM3 Trig on DMA1 channel 4 */
#define DMA1_CSELR_CH4_TIM16_CH1_Pos    (12U)                                  
#define DMA1_CSELR_CH4_TIM16_CH1_Msk    (0x7U << DMA1_CSELR_CH4_TIM16_CH1_Pos) /*!< 0x00007000 */
#define DMA1_CSELR_CH4_TIM16_CH1        DMA1_CSELR_CH4_TIM16_CH1_Msk           /*!< Remap TIM16 channel 1 on DMA1 channel 4 */
#define DMA1_CSELR_CH4_TIM16_UP_Pos     (12U)                                  
#define DMA1_CSELR_CH4_TIM16_UP_Msk     (0x7U << DMA1_CSELR_CH4_TIM16_UP_Pos)  /*!< 0x00007000 */
#define DMA1_CSELR_CH4_TIM16_UP         DMA1_CSELR_CH4_TIM16_UP_Msk            /*!< Remap TIM16 up on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART1_TX_Pos    (15U)                                  
#define DMA1_CSELR_CH4_USART1_TX_Msk    (0x1U << DMA1_CSELR_CH4_USART1_TX_Pos) /*!< 0x00008000 */
#define DMA1_CSELR_CH4_USART1_TX        DMA1_CSELR_CH4_USART1_TX_Msk           /*!< Remap USART1 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART2_TX_Pos    (12U)                                  
#define DMA1_CSELR_CH4_USART2_TX_Msk    (0x9U << DMA1_CSELR_CH4_USART2_TX_Pos) /*!< 0x00009000 */
#define DMA1_CSELR_CH4_USART2_TX        DMA1_CSELR_CH4_USART2_TX_Msk           /*!< Remap USART2 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART3_TX_Pos    (13U)                                  
#define DMA1_CSELR_CH4_USART3_TX_Msk    (0x5U << DMA1_CSELR_CH4_USART3_TX_Pos) /*!< 0x0000A000 */
#define DMA1_CSELR_CH4_USART3_TX        DMA1_CSELR_CH4_USART3_TX_Msk           /*!< Remap USART3 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART4_TX_Pos    (12U)                                  
#define DMA1_CSELR_CH4_USART4_TX_Msk    (0xBU << DMA1_CSELR_CH4_USART4_TX_Pos) /*!< 0x0000B000 */
#define DMA1_CSELR_CH4_USART4_TX        DMA1_CSELR_CH4_USART4_TX_Msk           /*!< Remap USART4 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART5_TX_Pos    (14U)                                  
#define DMA1_CSELR_CH4_USART5_TX_Msk    (0x3U << DMA1_CSELR_CH4_USART5_TX_Pos) /*!< 0x0000C000 */
#define DMA1_CSELR_CH4_USART5_TX        DMA1_CSELR_CH4_USART5_TX_Msk           /*!< Remap USART5 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART6_TX_Pos    (12U)                                  
#define DMA1_CSELR_CH4_USART6_TX_Msk    (0xDU << DMA1_CSELR_CH4_USART6_TX_Pos) /*!< 0x0000D000 */
#define DMA1_CSELR_CH4_USART6_TX        DMA1_CSELR_CH4_USART6_TX_Msk           /*!< Remap USART6 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART7_TX_Pos    (13U)                                  
#define DMA1_CSELR_CH4_USART7_TX_Msk    (0x7U << DMA1_CSELR_CH4_USART7_TX_Pos) /*!< 0x0000E000 */
#define DMA1_CSELR_CH4_USART7_TX        DMA1_CSELR_CH4_USART7_TX_Msk           /*!< Remap USART7 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH4_USART8_TX_Pos    (12U)                                  
#define DMA1_CSELR_CH4_USART8_TX_Msk    (0xFU << DMA1_CSELR_CH4_USART8_TX_Pos) /*!< 0x0000F000 */
#define DMA1_CSELR_CH4_USART8_TX        DMA1_CSELR_CH4_USART8_TX_Msk           /*!< Remap USART8 Tx on DMA1 channel 4 */
#define DMA1_CSELR_CH5_I2C2_RX_Pos      (17U)                                  
#define DMA1_CSELR_CH5_I2C2_RX_Msk      (0x1U << DMA1_CSELR_CH5_I2C2_RX_Pos)   /*!< 0x00020000 */
#define DMA1_CSELR_CH5_I2C2_RX          DMA1_CSELR_CH5_I2C2_RX_Msk             /*!< Remap I2C2 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_SPI2_TX_Pos      (16U)                                  
#define DMA1_CSELR_CH5_SPI2_TX_Msk      (0x3U << DMA1_CSELR_CH5_SPI2_TX_Pos)   /*!< 0x00030000 */
#define DMA1_CSELR_CH5_SPI2_TX          DMA1_CSELR_CH5_SPI2_TX_Msk             /*!< Remap SPI1 Tx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_TIM1_CH3_Pos     (18U)                                  
#define DMA1_CSELR_CH5_TIM1_CH3_Msk     (0x1U << DMA1_CSELR_CH5_TIM1_CH3_Pos)  /*!< 0x00040000 */
#define DMA1_CSELR_CH5_TIM1_CH3         DMA1_CSELR_CH5_TIM1_CH3_Msk            /*!< Remap TIM1 channel 3 on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART1_RX_Pos    (19U)                                  
#define DMA1_CSELR_CH5_USART1_RX_Msk    (0x1U << DMA1_CSELR_CH5_USART1_RX_Pos) /*!< 0x00080000 */
#define DMA1_CSELR_CH5_USART1_RX        DMA1_CSELR_CH5_USART1_RX_Msk           /*!< Remap USART1 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART2_RX_Pos    (16U)                                  
#define DMA1_CSELR_CH5_USART2_RX_Msk    (0x9U << DMA1_CSELR_CH5_USART2_RX_Pos) /*!< 0x00090000 */
#define DMA1_CSELR_CH5_USART2_RX        DMA1_CSELR_CH5_USART2_RX_Msk           /*!< Remap USART2 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART3_RX_Pos    (17U)                                  
#define DMA1_CSELR_CH5_USART3_RX_Msk    (0x5U << DMA1_CSELR_CH5_USART3_RX_Pos) /*!< 0x000A0000 */
#define DMA1_CSELR_CH5_USART3_RX        DMA1_CSELR_CH5_USART3_RX_Msk           /*!< Remap USART3 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART4_RX_Pos    (16U)                                  
#define DMA1_CSELR_CH5_USART4_RX_Msk    (0xBU << DMA1_CSELR_CH5_USART4_RX_Pos) /*!< 0x000B0000 */
#define DMA1_CSELR_CH5_USART4_RX        DMA1_CSELR_CH5_USART4_RX_Msk           /*!< Remap USART4 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART5_RX_Pos    (18U)                                  
#define DMA1_CSELR_CH5_USART5_RX_Msk    (0x3U << DMA1_CSELR_CH5_USART5_RX_Pos) /*!< 0x000C0000 */
#define DMA1_CSELR_CH5_USART5_RX        DMA1_CSELR_CH5_USART5_RX_Msk           /*!< Remap USART5 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART6_RX_Pos    (16U)                                  
#define DMA1_CSELR_CH5_USART6_RX_Msk    (0xDU << DMA1_CSELR_CH5_USART6_RX_Pos) /*!< 0x000D0000 */
#define DMA1_CSELR_CH5_USART6_RX        DMA1_CSELR_CH5_USART6_RX_Msk           /*!< Remap USART6 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART7_RX_Pos    (17U)                                  
#define DMA1_CSELR_CH5_USART7_RX_Msk    (0x7U << DMA1_CSELR_CH5_USART7_RX_Pos) /*!< 0x000E0000 */
#define DMA1_CSELR_CH5_USART7_RX        DMA1_CSELR_CH5_USART7_RX_Msk           /*!< Remap USART7 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH5_USART8_RX_Pos    (16U)                                  
#define DMA1_CSELR_CH5_USART8_RX_Msk    (0xFU << DMA1_CSELR_CH5_USART8_RX_Pos) /*!< 0x000F0000 */
#define DMA1_CSELR_CH5_USART8_RX        DMA1_CSELR_CH5_USART8_RX_Msk           /*!< Remap USART8 Rx on DMA1 channel 5 */
#define DMA1_CSELR_CH6_I2C1_TX_Pos      (21U)                                  
#define DMA1_CSELR_CH6_I2C1_TX_Msk      (0x1U << DMA1_CSELR_CH6_I2C1_TX_Pos)   /*!< 0x00200000 */
#define DMA1_CSELR_CH6_I2C1_TX          DMA1_CSELR_CH6_I2C1_TX_Msk             /*!< Remap I2C1 Tx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_SPI2_RX_Pos      (20U)                                  
#define DMA1_CSELR_CH6_SPI2_RX_Msk      (0x3U << DMA1_CSELR_CH6_SPI2_RX_Pos)   /*!< 0x00300000 */
#define DMA1_CSELR_CH6_SPI2_RX          DMA1_CSELR_CH6_SPI2_RX_Msk             /*!< Remap SPI2 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM1_CH1_Pos     (22U)                                  
#define DMA1_CSELR_CH6_TIM1_CH1_Msk     (0x1U << DMA1_CSELR_CH6_TIM1_CH1_Pos)  /*!< 0x00400000 */
#define DMA1_CSELR_CH6_TIM1_CH1         DMA1_CSELR_CH6_TIM1_CH1_Msk            /*!< Remap TIM1 channel 1 on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM1_CH2_Pos     (22U)                                  
#define DMA1_CSELR_CH6_TIM1_CH2_Msk     (0x1U << DMA1_CSELR_CH6_TIM1_CH2_Pos)  /*!< 0x00400000 */
#define DMA1_CSELR_CH6_TIM1_CH2         DMA1_CSELR_CH6_TIM1_CH2_Msk            /*!< Remap TIM1 channel 2 on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM1_CH3_Pos     (22U)                                  
#define DMA1_CSELR_CH6_TIM1_CH3_Msk     (0x1U << DMA1_CSELR_CH6_TIM1_CH3_Pos)  /*!< 0x00400000 */
#define DMA1_CSELR_CH6_TIM1_CH3         DMA1_CSELR_CH6_TIM1_CH3_Msk            /*!< Remap TIM1 channel 3 on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM3_CH1_Pos     (21U)                                  
#define DMA1_CSELR_CH6_TIM3_CH1_Msk     (0x3U << DMA1_CSELR_CH6_TIM3_CH1_Pos)  /*!< 0x00600000 */
#define DMA1_CSELR_CH6_TIM3_CH1         DMA1_CSELR_CH6_TIM3_CH1_Msk            /*!< Remap TIM3 channel 1 on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM3_TRIG_Pos    (21U)                                  
#define DMA1_CSELR_CH6_TIM3_TRIG_Msk    (0x3U << DMA1_CSELR_CH6_TIM3_TRIG_Pos) /*!< 0x00600000 */
#define DMA1_CSELR_CH6_TIM3_TRIG        DMA1_CSELR_CH6_TIM3_TRIG_Msk           /*!< Remap TIM3 Trig on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM16_CH1_Pos    (20U)                                  
#define DMA1_CSELR_CH6_TIM16_CH1_Msk    (0x7U << DMA1_CSELR_CH6_TIM16_CH1_Pos) /*!< 0x00700000 */
#define DMA1_CSELR_CH6_TIM16_CH1        DMA1_CSELR_CH6_TIM16_CH1_Msk           /*!< Remap TIM16 channel 1 on DMA1 channel 6 */
#define DMA1_CSELR_CH6_TIM16_UP_Pos     (20U)                                  
#define DMA1_CSELR_CH6_TIM16_UP_Msk     (0x7U << DMA1_CSELR_CH6_TIM16_UP_Pos)  /*!< 0x00700000 */
#define DMA1_CSELR_CH6_TIM16_UP         DMA1_CSELR_CH6_TIM16_UP_Msk            /*!< Remap TIM16 up on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART1_RX_Pos    (23U)                                  
#define DMA1_CSELR_CH6_USART1_RX_Msk    (0x1U << DMA1_CSELR_CH6_USART1_RX_Pos) /*!< 0x00800000 */
#define DMA1_CSELR_CH6_USART1_RX        DMA1_CSELR_CH6_USART1_RX_Msk           /*!< Remap USART1 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART2_RX_Pos    (20U)                                  
#define DMA1_CSELR_CH6_USART2_RX_Msk    (0x9U << DMA1_CSELR_CH6_USART2_RX_Pos) /*!< 0x00900000 */
#define DMA1_CSELR_CH6_USART2_RX        DMA1_CSELR_CH6_USART2_RX_Msk           /*!< Remap USART2 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART3_RX_Pos    (21U)                                  
#define DMA1_CSELR_CH6_USART3_RX_Msk    (0x5U << DMA1_CSELR_CH6_USART3_RX_Pos) /*!< 0x00A00000 */
#define DMA1_CSELR_CH6_USART3_RX        DMA1_CSELR_CH6_USART3_RX_Msk           /*!< Remap USART3 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART4_RX_Pos    (20U)                                  
#define DMA1_CSELR_CH6_USART4_RX_Msk    (0xBU << DMA1_CSELR_CH6_USART4_RX_Pos) /*!< 0x00B00000 */
#define DMA1_CSELR_CH6_USART4_RX        DMA1_CSELR_CH6_USART4_RX_Msk           /*!< Remap USART4 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART5_RX_Pos    (22U)                                  
#define DMA1_CSELR_CH6_USART5_RX_Msk    (0x3U << DMA1_CSELR_CH6_USART5_RX_Pos) /*!< 0x00C00000 */
#define DMA1_CSELR_CH6_USART5_RX        DMA1_CSELR_CH6_USART5_RX_Msk           /*!< Remap USART5 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART6_RX_Pos    (20U)                                  
#define DMA1_CSELR_CH6_USART6_RX_Msk    (0xDU << DMA1_CSELR_CH6_USART6_RX_Pos) /*!< 0x00D00000 */
#define DMA1_CSELR_CH6_USART6_RX        DMA1_CSELR_CH6_USART6_RX_Msk           /*!< Remap USART6 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART7_RX_Pos    (21U)                                  
#define DMA1_CSELR_CH6_USART7_RX_Msk    (0x7U << DMA1_CSELR_CH6_USART7_RX_Pos) /*!< 0x00E00000 */
#define DMA1_CSELR_CH6_USART7_RX        DMA1_CSELR_CH6_USART7_RX_Msk           /*!< Remap USART7 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH6_USART8_RX_Pos    (20U)                                  
#define DMA1_CSELR_CH6_USART8_RX_Msk    (0xFU << DMA1_CSELR_CH6_USART8_RX_Pos) /*!< 0x00F00000 */
#define DMA1_CSELR_CH6_USART8_RX        DMA1_CSELR_CH6_USART8_RX_Msk           /*!< Remap USART8 Rx on DMA1 channel 6 */
#define DMA1_CSELR_CH7_I2C1_RX_Pos      (25U)                                  
#define DMA1_CSELR_CH7_I2C1_RX_Msk      (0x1U << DMA1_CSELR_CH7_I2C1_RX_Pos)   /*!< 0x02000000 */
#define DMA1_CSELR_CH7_I2C1_RX          DMA1_CSELR_CH7_I2C1_RX_Msk             /*!< Remap I2C1 Rx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_SPI2_TX_Pos      (24U)                                  
#define DMA1_CSELR_CH7_SPI2_TX_Msk      (0x3U << DMA1_CSELR_CH7_SPI2_TX_Pos)   /*!< 0x03000000 */
#define DMA1_CSELR_CH7_SPI2_TX          DMA1_CSELR_CH7_SPI2_TX_Msk             /*!< Remap SPI2 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_TIM2_CH2_Pos     (24U)                                  
#define DMA1_CSELR_CH7_TIM2_CH2_Msk     (0x5U << DMA1_CSELR_CH7_TIM2_CH2_Pos)  /*!< 0x05000000 */
#define DMA1_CSELR_CH7_TIM2_CH2         DMA1_CSELR_CH7_TIM2_CH2_Msk            /*!< Remap TIM2 channel 2 on DMA1 channel 7 */
#define DMA1_CSELR_CH7_TIM2_CH4_Pos     (24U)                                  
#define DMA1_CSELR_CH7_TIM2_CH4_Msk     (0x5U << DMA1_CSELR_CH7_TIM2_CH4_Pos)  /*!< 0x05000000 */
#define DMA1_CSELR_CH7_TIM2_CH4         DMA1_CSELR_CH7_TIM2_CH4_Msk            /*!< Remap TIM2 channel 4 on DMA1 channel 7 */
#define DMA1_CSELR_CH7_TIM17_CH1_Pos    (24U)                                  
#define DMA1_CSELR_CH7_TIM17_CH1_Msk    (0x7U << DMA1_CSELR_CH7_TIM17_CH1_Pos) /*!< 0x07000000 */
#define DMA1_CSELR_CH7_TIM17_CH1        DMA1_CSELR_CH7_TIM17_CH1_Msk           /*!< Remap TIM17 channel 1 on DMA1 channel 7 */
#define DMA1_CSELR_CH7_TIM17_UP_Pos     (24U)                                  
#define DMA1_CSELR_CH7_TIM17_UP_Msk     (0x7U << DMA1_CSELR_CH7_TIM17_UP_Pos)  /*!< 0x07000000 */
#define DMA1_CSELR_CH7_TIM17_UP         DMA1_CSELR_CH7_TIM17_UP_Msk            /*!< Remap TIM17 up on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART1_TX_Pos    (27U)                                  
#define DMA1_CSELR_CH7_USART1_TX_Msk    (0x1U << DMA1_CSELR_CH7_USART1_TX_Pos) /*!< 0x08000000 */
#define DMA1_CSELR_CH7_USART1_TX        DMA1_CSELR_CH7_USART1_TX_Msk           /*!< Remap USART1 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART2_TX_Pos    (24U)                                  
#define DMA1_CSELR_CH7_USART2_TX_Msk    (0x9U << DMA1_CSELR_CH7_USART2_TX_Pos) /*!< 0x09000000 */
#define DMA1_CSELR_CH7_USART2_TX        DMA1_CSELR_CH7_USART2_TX_Msk           /*!< Remap USART2 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART3_TX_Pos    (25U)                                  
#define DMA1_CSELR_CH7_USART3_TX_Msk    (0x5U << DMA1_CSELR_CH7_USART3_TX_Pos) /*!< 0x0A000000 */
#define DMA1_CSELR_CH7_USART3_TX        DMA1_CSELR_CH7_USART3_TX_Msk           /*!< Remap USART3 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART4_TX_Pos    (24U)                                  
#define DMA1_CSELR_CH7_USART4_TX_Msk    (0xBU << DMA1_CSELR_CH7_USART4_TX_Pos) /*!< 0x0B000000 */
#define DMA1_CSELR_CH7_USART4_TX        DMA1_CSELR_CH7_USART4_TX_Msk           /*!< Remap USART4 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART5_TX_Pos    (26U)                                  
#define DMA1_CSELR_CH7_USART5_TX_Msk    (0x3U << DMA1_CSELR_CH7_USART5_TX_Pos) /*!< 0x0C000000 */
#define DMA1_CSELR_CH7_USART5_TX        DMA1_CSELR_CH7_USART5_TX_Msk           /*!< Remap USART5 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART6_TX_Pos    (24U)                                  
#define DMA1_CSELR_CH7_USART6_TX_Msk    (0xDU << DMA1_CSELR_CH7_USART6_TX_Pos) /*!< 0x0D000000 */
#define DMA1_CSELR_CH7_USART6_TX        DMA1_CSELR_CH7_USART6_TX_Msk           /*!< Remap USART6 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART7_TX_Pos    (25U)                                  
#define DMA1_CSELR_CH7_USART7_TX_Msk    (0x7U << DMA1_CSELR_CH7_USART7_TX_Pos) /*!< 0x0E000000 */
#define DMA1_CSELR_CH7_USART7_TX        DMA1_CSELR_CH7_USART7_TX_Msk           /*!< Remap USART7 Tx on DMA1 channel 7 */
#define DMA1_CSELR_CH7_USART8_TX_Pos    (24U)                                  
#define DMA1_CSELR_CH7_USART8_TX_Msk    (0xFU << DMA1_CSELR_CH7_USART8_TX_Pos) /*!< 0x0F000000 */
#define DMA1_CSELR_CH7_USART8_TX        DMA1_CSELR_CH7_USART8_TX_Msk           /*!< Remap USART8 Tx on DMA1 channel 7 */

/******************  Bit definition for DMA2_CSELR register  ********************/
#define DMA2_CSELR_DEFAULT              (0x00000000U)                          /*!< Default remap position for DMA2 */
#define DMA2_CSELR_CH1_I2C2_TX_Pos      (1U)                                   
#define DMA2_CSELR_CH1_I2C2_TX_Msk      (0x1U << DMA2_CSELR_CH1_I2C2_TX_Pos)   /*!< 0x00000002 */
#define DMA2_CSELR_CH1_I2C2_TX          DMA2_CSELR_CH1_I2C2_TX_Msk             /*!< Remap I2C2 TX on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART1_TX_Pos    (3U)                                   
#define DMA2_CSELR_CH1_USART1_TX_Msk    (0x1U << DMA2_CSELR_CH1_USART1_TX_Pos) /*!< 0x00000008 */
#define DMA2_CSELR_CH1_USART1_TX        DMA2_CSELR_CH1_USART1_TX_Msk           /*!< Remap USART1 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART2_TX_Pos    (0U)                                   
#define DMA2_CSELR_CH1_USART2_TX_Msk    (0x9U << DMA2_CSELR_CH1_USART2_TX_Pos) /*!< 0x00000009 */
#define DMA2_CSELR_CH1_USART2_TX        DMA2_CSELR_CH1_USART2_TX_Msk           /*!< Remap USART2 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART3_TX_Pos    (1U)                                   
#define DMA2_CSELR_CH1_USART3_TX_Msk    (0x5U << DMA2_CSELR_CH1_USART3_TX_Pos) /*!< 0x0000000A */
#define DMA2_CSELR_CH1_USART3_TX        DMA2_CSELR_CH1_USART3_TX_Msk           /*!< Remap USART3 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART4_TX_Pos    (0U)                                   
#define DMA2_CSELR_CH1_USART4_TX_Msk    (0xBU << DMA2_CSELR_CH1_USART4_TX_Pos) /*!< 0x0000000B */
#define DMA2_CSELR_CH1_USART4_TX        DMA2_CSELR_CH1_USART4_TX_Msk           /*!< Remap USART4 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART5_TX_Pos    (2U)                                   
#define DMA2_CSELR_CH1_USART5_TX_Msk    (0x3U << DMA2_CSELR_CH1_USART5_TX_Pos) /*!< 0x0000000C */
#define DMA2_CSELR_CH1_USART5_TX        DMA2_CSELR_CH1_USART5_TX_Msk           /*!< Remap USART5 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART6_TX_Pos    (0U)                                   
#define DMA2_CSELR_CH1_USART6_TX_Msk    (0xDU << DMA2_CSELR_CH1_USART6_TX_Pos) /*!< 0x0000000D */
#define DMA2_CSELR_CH1_USART6_TX        DMA2_CSELR_CH1_USART6_TX_Msk           /*!< Remap USART6 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART7_TX_Pos    (1U)                                   
#define DMA2_CSELR_CH1_USART7_TX_Msk    (0x7U << DMA2_CSELR_CH1_USART7_TX_Pos) /*!< 0x0000000E */
#define DMA2_CSELR_CH1_USART7_TX        DMA2_CSELR_CH1_USART7_TX_Msk           /*!< Remap USART7 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH1_USART8_TX_Pos    (0U)                                   
#define DMA2_CSELR_CH1_USART8_TX_Msk    (0xFU << DMA2_CSELR_CH1_USART8_TX_Pos) /*!< 0x0000000F */
#define DMA2_CSELR_CH1_USART8_TX        DMA2_CSELR_CH1_USART8_TX_Msk           /*!< Remap USART8 Tx on DMA2 channel 1 */
#define DMA2_CSELR_CH2_I2C2_RX_Pos      (5U)                                   
#define DMA2_CSELR_CH2_I2C2_RX_Msk      (0x1U << DMA2_CSELR_CH2_I2C2_RX_Pos)   /*!< 0x00000020 */
#define DMA2_CSELR_CH2_I2C2_RX          DMA2_CSELR_CH2_I2C2_RX_Msk             /*!< Remap I2C2 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART1_RX_Pos    (7U)                                   
#define DMA2_CSELR_CH2_USART1_RX_Msk    (0x1U << DMA2_CSELR_CH2_USART1_RX_Pos) /*!< 0x00000080 */
#define DMA2_CSELR_CH2_USART1_RX        DMA2_CSELR_CH2_USART1_RX_Msk           /*!< Remap USART1 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART2_RX_Pos    (4U)                                   
#define DMA2_CSELR_CH2_USART2_RX_Msk    (0x9U << DMA2_CSELR_CH2_USART2_RX_Pos) /*!< 0x00000090 */
#define DMA2_CSELR_CH2_USART2_RX        DMA2_CSELR_CH2_USART2_RX_Msk           /*!< Remap USART2 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART3_RX_Pos    (5U)                                   
#define DMA2_CSELR_CH2_USART3_RX_Msk    (0x5U << DMA2_CSELR_CH2_USART3_RX_Pos) /*!< 0x000000A0 */
#define DMA2_CSELR_CH2_USART3_RX        DMA2_CSELR_CH2_USART3_RX_Msk           /*!< Remap USART3 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART4_RX_Pos    (4U)                                   
#define DMA2_CSELR_CH2_USART4_RX_Msk    (0xBU << DMA2_CSELR_CH2_USART4_RX_Pos) /*!< 0x000000B0 */
#define DMA2_CSELR_CH2_USART4_RX        DMA2_CSELR_CH2_USART4_RX_Msk           /*!< Remap USART4 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART5_RX_Pos    (6U)                                   
#define DMA2_CSELR_CH2_USART5_RX_Msk    (0x3U << DMA2_CSELR_CH2_USART5_RX_Pos) /*!< 0x000000C0 */
#define DMA2_CSELR_CH2_USART5_RX        DMA2_CSELR_CH2_USART5_RX_Msk           /*!< Remap USART5 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART6_RX_Pos    (4U)                                   
#define DMA2_CSELR_CH2_USART6_RX_Msk    (0xDU << DMA2_CSELR_CH2_USART6_RX_Pos) /*!< 0x000000D0 */
#define DMA2_CSELR_CH2_USART6_RX        DMA2_CSELR_CH2_USART6_RX_Msk           /*!< Remap USART6 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART7_RX_Pos    (5U)                                   
#define DMA2_CSELR_CH2_USART7_RX_Msk    (0x7U << DMA2_CSELR_CH2_USART7_RX_Pos) /*!< 0x000000E0 */
#define DMA2_CSELR_CH2_USART7_RX        DMA2_CSELR_CH2_USART7_RX_Msk           /*!< Remap USART7 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH2_USART8_RX_Pos    (4U)                                   
#define DMA2_CSELR_CH2_USART8_RX_Msk    (0xFU << DMA2_CSELR_CH2_USART8_RX_Pos) /*!< 0x000000F0 */
#define DMA2_CSELR_CH2_USART8_RX        DMA2_CSELR_CH2_USART8_RX_Msk           /*!< Remap USART8 Rx on DMA2 channel 2 */
#define DMA2_CSELR_CH3_TIM6_UP_Pos      (8U)                                   
#define DMA2_CSELR_CH3_TIM6_UP_Msk      (0x1U << DMA2_CSELR_CH3_TIM6_UP_Pos)   /*!< 0x00000100 */
#define DMA2_CSELR_CH3_TIM6_UP          DMA2_CSELR_CH3_TIM6_UP_Msk             /*!< Remap TIM6 up on DMA2 channel 3 */
#define DMA2_CSELR_CH3_DAC_CH1_Pos      (8U)                                   
#define DMA2_CSELR_CH3_DAC_CH1_Msk      (0x1U << DMA2_CSELR_CH3_DAC_CH1_Pos)   /*!< 0x00000100 */
#define DMA2_CSELR_CH3_DAC_CH1          DMA2_CSELR_CH3_DAC_CH1_Msk             /*!< Remap DAC channel 1 on DMA2 channel 3 */
#define DMA2_CSELR_CH3_SPI1_RX_Pos      (8U)                                   
#define DMA2_CSELR_CH3_SPI1_RX_Msk      (0x3U << DMA2_CSELR_CH3_SPI1_RX_Pos)   /*!< 0x00000300 */
#define DMA2_CSELR_CH3_SPI1_RX          DMA2_CSELR_CH3_SPI1_RX_Msk             /*!< Remap SPI1 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART1_RX_Pos    (11U)                                  
#define DMA2_CSELR_CH3_USART1_RX_Msk    (0x1U << DMA2_CSELR_CH3_USART1_RX_Pos) /*!< 0x00000800 */
#define DMA2_CSELR_CH3_USART1_RX        DMA2_CSELR_CH3_USART1_RX_Msk           /*!< Remap USART1 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART2_RX_Pos    (8U)                                   
#define DMA2_CSELR_CH3_USART2_RX_Msk    (0x9U << DMA2_CSELR_CH3_USART2_RX_Pos) /*!< 0x00000900 */
#define DMA2_CSELR_CH3_USART2_RX        DMA2_CSELR_CH3_USART2_RX_Msk           /*!< Remap USART2 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART3_RX_Pos    (9U)                                   
#define DMA2_CSELR_CH3_USART3_RX_Msk    (0x5U << DMA2_CSELR_CH3_USART3_RX_Pos) /*!< 0x00000A00 */
#define DMA2_CSELR_CH3_USART3_RX        DMA2_CSELR_CH3_USART3_RX_Msk           /*!< Remap USART3 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART4_RX_Pos    (8U)                                   
#define DMA2_CSELR_CH3_USART4_RX_Msk    (0xBU << DMA2_CSELR_CH3_USART4_RX_Pos) /*!< 0x00000B00 */
#define DMA2_CSELR_CH3_USART4_RX        DMA2_CSELR_CH3_USART4_RX_Msk           /*!< Remap USART4 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART5_RX_Pos    (10U)                                  
#define DMA2_CSELR_CH3_USART5_RX_Msk    (0x3U << DMA2_CSELR_CH3_USART5_RX_Pos) /*!< 0x00000C00 */
#define DMA2_CSELR_CH3_USART5_RX        DMA2_CSELR_CH3_USART5_RX_Msk           /*!< Remap USART5 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART6_RX_Pos    (8U)                                   
#define DMA2_CSELR_CH3_USART6_RX_Msk    (0xDU << DMA2_CSELR_CH3_USART6_RX_Pos) /*!< 0x00000D00 */
#define DMA2_CSELR_CH3_USART6_RX        DMA2_CSELR_CH3_USART6_RX_Msk           /*!< Remap USART6 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART7_RX_Pos    (9U)                                   
#define DMA2_CSELR_CH3_USART7_RX_Msk    (0x7U << DMA2_CSELR_CH3_USART7_RX_Pos) /*!< 0x00000E00 */
#define DMA2_CSELR_CH3_USART7_RX        DMA2_CSELR_CH3_USART7_RX_Msk           /*!< Remap USART7 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH3_USART8_RX_Pos    (8U)                                   
#define DMA2_CSELR_CH3_USART8_RX_Msk    (0xFU << DMA2_CSELR_CH3_USART8_RX_Pos) /*!< 0x00000F00 */
#define DMA2_CSELR_CH3_USART8_RX        DMA2_CSELR_CH3_USART8_RX_Msk           /*!< Remap USART8 Rx on DMA2 channel 3 */
#define DMA2_CSELR_CH4_TIM7_UP_Pos      (12U)                                  
#define DMA2_CSELR_CH4_TIM7_UP_Msk      (0x1U << DMA2_CSELR_CH4_TIM7_UP_Pos)   /*!< 0x00001000 */
#define DMA2_CSELR_CH4_TIM7_UP          DMA2_CSELR_CH4_TIM7_UP_Msk             /*!< Remap TIM7 up on DMA2 channel 4 */
#define DMA2_CSELR_CH4_DAC_CH2_Pos      (12U)                                  
#define DMA2_CSELR_CH4_DAC_CH2_Msk      (0x1U << DMA2_CSELR_CH4_DAC_CH2_Pos)   /*!< 0x00001000 */
#define DMA2_CSELR_CH4_DAC_CH2          DMA2_CSELR_CH4_DAC_CH2_Msk             /*!< Remap DAC channel 2 on DMA2 channel 4 */
#define DMA2_CSELR_CH4_SPI1_TX_Pos      (12U)                                  
#define DMA2_CSELR_CH4_SPI1_TX_Msk      (0x3U << DMA2_CSELR_CH4_SPI1_TX_Pos)   /*!< 0x00003000 */
#define DMA2_CSELR_CH4_SPI1_TX          DMA2_CSELR_CH4_SPI1_TX_Msk             /*!< Remap SPI1 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART1_TX_Pos    (15U)                                  
#define DMA2_CSELR_CH4_USART1_TX_Msk    (0x1U << DMA2_CSELR_CH4_USART1_TX_Pos) /*!< 0x00008000 */
#define DMA2_CSELR_CH4_USART1_TX        DMA2_CSELR_CH4_USART1_TX_Msk           /*!< Remap USART1 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART2_TX_Pos    (12U)                                  
#define DMA2_CSELR_CH4_USART2_TX_Msk    (0x9U << DMA2_CSELR_CH4_USART2_TX_Pos) /*!< 0x00009000 */
#define DMA2_CSELR_CH4_USART2_TX        DMA2_CSELR_CH4_USART2_TX_Msk           /*!< Remap USART2 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART3_TX_Pos    (13U)                                  
#define DMA2_CSELR_CH4_USART3_TX_Msk    (0x5U << DMA2_CSELR_CH4_USART3_TX_Pos) /*!< 0x0000A000 */
#define DMA2_CSELR_CH4_USART3_TX        DMA2_CSELR_CH4_USART3_TX_Msk           /*!< Remap USART3 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART4_TX_Pos    (12U)                                  
#define DMA2_CSELR_CH4_USART4_TX_Msk    (0xBU << DMA2_CSELR_CH4_USART4_TX_Pos) /*!< 0x0000B000 */
#define DMA2_CSELR_CH4_USART4_TX        DMA2_CSELR_CH4_USART4_TX_Msk           /*!< Remap USART4 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART5_TX_Pos    (14U)                                  
#define DMA2_CSELR_CH4_USART5_TX_Msk    (0x3U << DMA2_CSELR_CH4_USART5_TX_Pos) /*!< 0x0000C000 */
#define DMA2_CSELR_CH4_USART5_TX        DMA2_CSELR_CH4_USART5_TX_Msk           /*!< Remap USART5 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART6_TX_Pos    (12U)                                  
#define DMA2_CSELR_CH4_USART6_TX_Msk    (0xDU << DMA2_CSELR_CH4_USART6_TX_Pos) /*!< 0x0000D000 */
#define DMA2_CSELR_CH4_USART6_TX        DMA2_CSELR_CH4_USART6_TX_Msk           /*!< Remap USART6 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART7_TX_Pos    (13U)                                  
#define DMA2_CSELR_CH4_USART7_TX_Msk    (0x7U << DMA2_CSELR_CH4_USART7_TX_Pos) /*!< 0x0000E000 */
#define DMA2_CSELR_CH4_USART7_TX        DMA2_CSELR_CH4_USART7_TX_Msk           /*!< Remap USART7 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH4_USART8_TX_Pos    (12U)                                  
#define DMA2_CSELR_CH4_USART8_TX_Msk    (0xFU << DMA2_CSELR_CH4_USART8_TX_Pos) /*!< 0x0000F000 */
#define DMA2_CSELR_CH4_USART8_TX        DMA2_CSELR_CH4_USART8_TX_Msk           /*!< Remap USART8 Tx on DMA2 channel 4 */
#define DMA2_CSELR_CH5_ADC_Pos          (16U)                                  
#define DMA2_CSELR_CH5_ADC_Msk          (0x1U << DMA2_CSELR_CH5_ADC_Pos)       /*!< 0x00010000 */
#define DMA2_CSELR_CH5_ADC              DMA2_CSELR_CH5_ADC_Msk                 /*!< Remap ADC on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART1_TX_Pos    (19U)                                  
#define DMA2_CSELR_CH5_USART1_TX_Msk    (0x1U << DMA2_CSELR_CH5_USART1_TX_Pos) /*!< 0x00080000 */
#define DMA2_CSELR_CH5_USART1_TX        DMA2_CSELR_CH5_USART1_TX_Msk           /*!< Remap USART1 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART2_TX_Pos    (16U)                                  
#define DMA2_CSELR_CH5_USART2_TX_Msk    (0x9U << DMA2_CSELR_CH5_USART2_TX_Pos) /*!< 0x00090000 */
#define DMA2_CSELR_CH5_USART2_TX        DMA2_CSELR_CH5_USART2_TX_Msk           /*!< Remap USART2 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART3_TX_Pos    (17U)                                  
#define DMA2_CSELR_CH5_USART3_TX_Msk    (0x5U << DMA2_CSELR_CH5_USART3_TX_Pos) /*!< 0x000A0000 */
#define DMA2_CSELR_CH5_USART3_TX        DMA2_CSELR_CH5_USART3_TX_Msk           /*!< Remap USART3 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART4_TX_Pos    (16U)                                  
#define DMA2_CSELR_CH5_USART4_TX_Msk    (0xBU << DMA2_CSELR_CH5_USART4_TX_Pos) /*!< 0x000B0000 */
#define DMA2_CSELR_CH5_USART4_TX        DMA2_CSELR_CH5_USART4_TX_Msk           /*!< Remap USART4 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART5_TX_Pos    (18U)                                  
#define DMA2_CSELR_CH5_USART5_TX_Msk    (0x3U << DMA2_CSELR_CH5_USART5_TX_Pos) /*!< 0x000C0000 */
#define DMA2_CSELR_CH5_USART5_TX        DMA2_CSELR_CH5_USART5_TX_Msk           /*!< Remap USART5 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART6_TX_Pos    (16U)                                  
#define DMA2_CSELR_CH5_USART6_TX_Msk    (0xDU << DMA2_CSELR_CH5_USART6_TX_Pos) /*!< 0x000D0000 */
#define DMA2_CSELR_CH5_USART6_TX        DMA2_CSELR_CH5_USART6_TX_Msk           /*!< Remap USART6 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART7_TX_Pos    (17U)                                  
#define DMA2_CSELR_CH5_USART7_TX_Msk    (0x7U << DMA2_CSELR_CH5_USART7_TX_Pos) /*!< 0x000E0000 */
#define DMA2_CSELR_CH5_USART7_TX        DMA2_CSELR_CH5_USART7_TX_Msk           /*!< Remap USART7 Tx on DMA2 channel 5 */
#define DMA2_CSELR_CH5_USART8_TX_Pos    (16U)                                  
#define DMA2_CSELR_CH5_USART8_TX_Msk    (0xFU << DMA2_CSELR_CH5_USART8_TX_Pos) /*!< 0x000F0000 */
#define DMA2_CSELR_CH5_USART8_TX        DMA2_CSELR_CH5_USART8_TX_Msk           /*!< Remap USART8 Tx on DMA2 channel 5 */
