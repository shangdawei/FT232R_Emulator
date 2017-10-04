  
/*****************************************************************************/
/*                                                                           */
/*                               Timers (TIM)                                */
/*                                                                           */
/*****************************************************************************/
/*******************  Bit definition for TIM_CR1 register  *******************/
#define TIM_CR1_CEN_Pos           (0U)                                         
#define TIM_CR1_CEN_Msk           (0x1U << TIM_CR1_CEN_Pos)                    /*!< 0x00000001 */
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk                              /*!<Counter enable */
#define TIM_CR1_UDIS_Pos          (1U)                                         
#define TIM_CR1_UDIS_Msk          (0x1U << TIM_CR1_UDIS_Pos)                   /*!< 0x00000002 */
#define TIM_CR1_UDIS              TIM_CR1_UDIS_Msk                             /*!<Update disable */
#define TIM_CR1_URS_Pos           (2U)                                         
#define TIM_CR1_URS_Msk           (0x1U << TIM_CR1_URS_Pos)                    /*!< 0x00000004 */
#define TIM_CR1_URS               TIM_CR1_URS_Msk                              /*!<Update request source */
#define TIM_CR1_OPM_Pos           (3U)                                         
#define TIM_CR1_OPM_Msk           (0x1U << TIM_CR1_OPM_Pos)                    /*!< 0x00000008 */
#define TIM_CR1_OPM               TIM_CR1_OPM_Msk                              /*!<One pulse mode */
#define TIM_CR1_DIR_Pos           (4U)                                         
#define TIM_CR1_DIR_Msk           (0x1U << TIM_CR1_DIR_Pos)                    /*!< 0x00000010 */
#define TIM_CR1_DIR               TIM_CR1_DIR_Msk                              /*!<Direction */

#define TIM_CR1_CMS_Pos           (5U)                                         
#define TIM_CR1_CMS_Msk           (0x3U << TIM_CR1_CMS_Pos)                    /*!< 0x00000060 */
#define TIM_CR1_CMS               TIM_CR1_CMS_Msk                              /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0             (0x1U << TIM_CR1_CMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR1_CMS_1             (0x2U << TIM_CR1_CMS_Pos)                    /*!< 0x00000040 */

#define TIM_CR1_ARPE_Pos          (7U)                                         
#define TIM_CR1_ARPE_Msk          (0x1U << TIM_CR1_ARPE_Pos)                   /*!< 0x00000080 */
#define TIM_CR1_ARPE              TIM_CR1_ARPE_Msk                             /*!<Auto-reload preload enable */

#define TIM_CR1_CKD_Pos           (8U)                                         
#define TIM_CR1_CKD_Msk           (0x3U << TIM_CR1_CKD_Pos)                    /*!< 0x00000300 */
#define TIM_CR1_CKD               TIM_CR1_CKD_Msk                              /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0             (0x1U << TIM_CR1_CKD_Pos)                    /*!< 0x00000100 */
#define TIM_CR1_CKD_1             (0x2U << TIM_CR1_CKD_Pos)                    /*!< 0x00000200 */

/*******************  Bit definition for TIM_CR2 register  *******************/
#define TIM_CR2_CCPC_Pos          (0U)                                         
#define TIM_CR2_CCPC_Msk          (0x1U << TIM_CR2_CCPC_Pos)                   /*!< 0x00000001 */
#define TIM_CR2_CCPC              TIM_CR2_CCPC_Msk                             /*!<Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos          (2U)                                         
#define TIM_CR2_CCUS_Msk          (0x1U << TIM_CR2_CCUS_Pos)                   /*!< 0x00000004 */
#define TIM_CR2_CCUS              TIM_CR2_CCUS_Msk                             /*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos          (3U)                                         
#define TIM_CR2_CCDS_Msk          (0x1U << TIM_CR2_CCDS_Pos)                   /*!< 0x00000008 */
#define TIM_CR2_CCDS              TIM_CR2_CCDS_Msk                             /*!<Capture/Compare DMA Selection */

#define TIM_CR2_MMS_Pos           (4U)                                         
#define TIM_CR2_MMS_Msk           (0x7U << TIM_CR2_MMS_Pos)                    /*!< 0x00000070 */
#define TIM_CR2_MMS               TIM_CR2_MMS_Msk                              /*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_0             (0x1U << TIM_CR2_MMS_Pos)                    /*!< 0x00000010 */
#define TIM_CR2_MMS_1             (0x2U << TIM_CR2_MMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR2_MMS_2             (0x4U << TIM_CR2_MMS_Pos)                    /*!< 0x00000040 */

#define TIM_CR2_TI1S_Pos          (7U)                                         
#define TIM_CR2_TI1S_Msk          (0x1U << TIM_CR2_TI1S_Pos)                   /*!< 0x00000080 */
#define TIM_CR2_TI1S              TIM_CR2_TI1S_Msk                             /*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos          (8U)                                         
#define TIM_CR2_OIS1_Msk          (0x1U << TIM_CR2_OIS1_Pos)                   /*!< 0x00000100 */
#define TIM_CR2_OIS1              TIM_CR2_OIS1_Msk                             /*!<Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos         (9U)                                         
#define TIM_CR2_OIS1N_Msk         (0x1U << TIM_CR2_OIS1N_Pos)                  /*!< 0x00000200 */
#define TIM_CR2_OIS1N             TIM_CR2_OIS1N_Msk                            /*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos          (10U)                                        
#define TIM_CR2_OIS2_Msk          (0x1U << TIM_CR2_OIS2_Pos)                   /*!< 0x00000400 */
#define TIM_CR2_OIS2              TIM_CR2_OIS2_Msk                             /*!<Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos         (11U)                                        
#define TIM_CR2_OIS2N_Msk         (0x1U << TIM_CR2_OIS2N_Pos)                  /*!< 0x00000800 */
#define TIM_CR2_OIS2N             TIM_CR2_OIS2N_Msk                            /*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos          (12U)                                        
#define TIM_CR2_OIS3_Msk          (0x1U << TIM_CR2_OIS3_Pos)                   /*!< 0x00001000 */
#define TIM_CR2_OIS3              TIM_CR2_OIS3_Msk                             /*!<Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos         (13U)                                        
#define TIM_CR2_OIS3N_Msk         (0x1U << TIM_CR2_OIS3N_Pos)                  /*!< 0x00002000 */
#define TIM_CR2_OIS3N             TIM_CR2_OIS3N_Msk                            /*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos          (14U)                                        
#define TIM_CR2_OIS4_Msk          (0x1U << TIM_CR2_OIS4_Pos)                   /*!< 0x00004000 */
#define TIM_CR2_OIS4              TIM_CR2_OIS4_Msk                             /*!<Output Idle state 4 (OC4 output) */

/*******************  Bit definition for TIM_SMCR register  ******************/
#define TIM_SMCR_SMS_Pos          (0U)                                         
#define TIM_SMCR_SMS_Msk          (0x7U << TIM_SMCR_SMS_Pos)                   /*!< 0x00000007 */
#define TIM_SMCR_SMS              TIM_SMCR_SMS_Msk                             /*!<SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_0            (0x1U << TIM_SMCR_SMS_Pos)                   /*!< 0x00000001 */
#define TIM_SMCR_SMS_1            (0x2U << TIM_SMCR_SMS_Pos)                   /*!< 0x00000002 */
#define TIM_SMCR_SMS_2            (0x4U << TIM_SMCR_SMS_Pos)                   /*!< 0x00000004 */

#define TIM_SMCR_OCCS_Pos         (3U)                                         
#define TIM_SMCR_OCCS_Msk         (0x1U << TIM_SMCR_OCCS_Pos)                  /*!< 0x00000008 */
#define TIM_SMCR_OCCS             TIM_SMCR_OCCS_Msk                            /*!< OCREF clear selection */

#define TIM_SMCR_TS_Pos           (4U)                                         
#define TIM_SMCR_TS_Msk           (0x7U << TIM_SMCR_TS_Pos)                    /*!< 0x00000070 */
#define TIM_SMCR_TS               TIM_SMCR_TS_Msk                              /*!<TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_0             (0x1U << TIM_SMCR_TS_Pos)                    /*!< 0x00000010 */
#define TIM_SMCR_TS_1             (0x2U << TIM_SMCR_TS_Pos)                    /*!< 0x00000020 */
#define TIM_SMCR_TS_2             (0x4U << TIM_SMCR_TS_Pos)                    /*!< 0x00000040 */

#define TIM_SMCR_MSM_Pos          (7U)                                         
#define TIM_SMCR_MSM_Msk          (0x1U << TIM_SMCR_MSM_Pos)                   /*!< 0x00000080 */
#define TIM_SMCR_MSM              TIM_SMCR_MSM_Msk                             /*!<Master/slave mode */

#define TIM_SMCR_ETF_Pos          (8U)                                         
#define TIM_SMCR_ETF_Msk          (0xFU << TIM_SMCR_ETF_Pos)                   /*!< 0x00000F00 */
#define TIM_SMCR_ETF              TIM_SMCR_ETF_Msk                             /*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0            (0x1U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000100 */
#define TIM_SMCR_ETF_1            (0x2U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000200 */
#define TIM_SMCR_ETF_2            (0x4U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000400 */
#define TIM_SMCR_ETF_3            (0x8U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000800 */

#define TIM_SMCR_ETPS_Pos         (12U)                                        
#define TIM_SMCR_ETPS_Msk         (0x3U << TIM_SMCR_ETPS_Pos)                  /*!< 0x00003000 */
#define TIM_SMCR_ETPS             TIM_SMCR_ETPS_Msk                            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0           (0x1U << TIM_SMCR_ETPS_Pos)                  /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1           (0x2U << TIM_SMCR_ETPS_Pos)                  /*!< 0x00002000 */

#define TIM_SMCR_ECE_Pos          (14U)                                        
#define TIM_SMCR_ECE_Msk          (0x1U << TIM_SMCR_ECE_Pos)                   /*!< 0x00004000 */
#define TIM_SMCR_ECE              TIM_SMCR_ECE_Msk                             /*!<External clock enable */
#define TIM_SMCR_ETP_Pos          (15U)                                        
#define TIM_SMCR_ETP_Msk          (0x1U << TIM_SMCR_ETP_Pos)                   /*!< 0x00008000 */
#define TIM_SMCR_ETP              TIM_SMCR_ETP_Msk                             /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  ******************/
#define TIM_DIER_UIE_Pos          (0U)                                         
#define TIM_DIER_UIE_Msk          (0x1U << TIM_DIER_UIE_Pos)                   /*!< 0x00000001 */
#define TIM_DIER_UIE              TIM_DIER_UIE_Msk                             /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos        (1U)                                         
#define TIM_DIER_CC1IE_Msk        (0x1U << TIM_DIER_CC1IE_Pos)                 /*!< 0x00000002 */
#define TIM_DIER_CC1IE            TIM_DIER_CC1IE_Msk                           /*!<Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos        (2U)                                         
#define TIM_DIER_CC2IE_Msk        (0x1U << TIM_DIER_CC2IE_Pos)                 /*!< 0x00000004 */
#define TIM_DIER_CC2IE            TIM_DIER_CC2IE_Msk                           /*!<Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos        (3U)                                         
#define TIM_DIER_CC3IE_Msk        (0x1U << TIM_DIER_CC3IE_Pos)                 /*!< 0x00000008 */
#define TIM_DIER_CC3IE            TIM_DIER_CC3IE_Msk                           /*!<Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos        (4U)                                         
#define TIM_DIER_CC4IE_Msk        (0x1U << TIM_DIER_CC4IE_Pos)                 /*!< 0x00000010 */
#define TIM_DIER_CC4IE            TIM_DIER_CC4IE_Msk                           /*!<Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos        (5U)                                         
#define TIM_DIER_COMIE_Msk        (0x1U << TIM_DIER_COMIE_Pos)                 /*!< 0x00000020 */
#define TIM_DIER_COMIE            TIM_DIER_COMIE_Msk                           /*!<COM interrupt enable */
#define TIM_DIER_TIE_Pos          (6U)                                         
#define TIM_DIER_TIE_Msk          (0x1U << TIM_DIER_TIE_Pos)                   /*!< 0x00000040 */
#define TIM_DIER_TIE              TIM_DIER_TIE_Msk                             /*!<Trigger interrupt enable */
#define TIM_DIER_BIE_Pos          (7U)                                         
#define TIM_DIER_BIE_Msk          (0x1U << TIM_DIER_BIE_Pos)                   /*!< 0x00000080 */
#define TIM_DIER_BIE              TIM_DIER_BIE_Msk                             /*!<Break interrupt enable */
#define TIM_DIER_UDE_Pos          (8U)                                         
#define TIM_DIER_UDE_Msk          (0x1U << TIM_DIER_UDE_Pos)                   /*!< 0x00000100 */
#define TIM_DIER_UDE              TIM_DIER_UDE_Msk                             /*!<Update DMA request enable */
#define TIM_DIER_CC1DE_Pos        (9U)                                         
#define TIM_DIER_CC1DE_Msk        (0x1U << TIM_DIER_CC1DE_Pos)                 /*!< 0x00000200 */
#define TIM_DIER_CC1DE            TIM_DIER_CC1DE_Msk                           /*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos        (10U)                                        
#define TIM_DIER_CC2DE_Msk        (0x1U << TIM_DIER_CC2DE_Pos)                 /*!< 0x00000400 */
#define TIM_DIER_CC2DE            TIM_DIER_CC2DE_Msk                           /*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos        (11U)                                        
#define TIM_DIER_CC3DE_Msk        (0x1U << TIM_DIER_CC3DE_Pos)                 /*!< 0x00000800 */
#define TIM_DIER_CC3DE            TIM_DIER_CC3DE_Msk                           /*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos        (12U)                                        
#define TIM_DIER_CC4DE_Msk        (0x1U << TIM_DIER_CC4DE_Pos)                 /*!< 0x00001000 */
#define TIM_DIER_CC4DE            TIM_DIER_CC4DE_Msk                           /*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos        (13U)                                        
#define TIM_DIER_COMDE_Msk        (0x1U << TIM_DIER_COMDE_Pos)                 /*!< 0x00002000 */
#define TIM_DIER_COMDE            TIM_DIER_COMDE_Msk                           /*!<COM DMA request enable */
#define TIM_DIER_TDE_Pos          (14U)                                        
#define TIM_DIER_TDE_Msk          (0x1U << TIM_DIER_TDE_Pos)                   /*!< 0x00004000 */
#define TIM_DIER_TDE              TIM_DIER_TDE_Msk                             /*!<Trigger DMA request enable */

/********************  Bit definition for TIM_SR register  *******************/
#define TIM_SR_UIF_Pos            (0U)                                         
#define TIM_SR_UIF_Msk            (0x1U << TIM_SR_UIF_Pos)                     /*!< 0x00000001 */
#define TIM_SR_UIF                TIM_SR_UIF_Msk                               /*!<Update interrupt Flag */
#define TIM_SR_CC1IF_Pos          (1U)                                         
#define TIM_SR_CC1IF_Msk          (0x1U << TIM_SR_CC1IF_Pos)                   /*!< 0x00000002 */
#define TIM_SR_CC1IF              TIM_SR_CC1IF_Msk                             /*!<Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos          (2U)                                         
#define TIM_SR_CC2IF_Msk          (0x1U << TIM_SR_CC2IF_Pos)                   /*!< 0x00000004 */
#define TIM_SR_CC2IF              TIM_SR_CC2IF_Msk                             /*!<Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos          (3U)                                         
#define TIM_SR_CC3IF_Msk          (0x1U << TIM_SR_CC3IF_Pos)                   /*!< 0x00000008 */
#define TIM_SR_CC3IF              TIM_SR_CC3IF_Msk                             /*!<Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos          (4U)                                         
#define TIM_SR_CC4IF_Msk          (0x1U << TIM_SR_CC4IF_Pos)                   /*!< 0x00000010 */
#define TIM_SR_CC4IF              TIM_SR_CC4IF_Msk                             /*!<Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos          (5U)                                         
#define TIM_SR_COMIF_Msk          (0x1U << TIM_SR_COMIF_Pos)                   /*!< 0x00000020 */
#define TIM_SR_COMIF              TIM_SR_COMIF_Msk                             /*!<COM interrupt Flag */
#define TIM_SR_TIF_Pos            (6U)                                         
#define TIM_SR_TIF_Msk            (0x1U << TIM_SR_TIF_Pos)                     /*!< 0x00000040 */
#define TIM_SR_TIF                TIM_SR_TIF_Msk                               /*!<Trigger interrupt Flag */
#define TIM_SR_BIF_Pos            (7U)                                         
#define TIM_SR_BIF_Msk            (0x1U << TIM_SR_BIF_Pos)                     /*!< 0x00000080 */
#define TIM_SR_BIF                TIM_SR_BIF_Msk                               /*!<Break interrupt Flag */
#define TIM_SR_CC1OF_Pos          (9U)                                         
#define TIM_SR_CC1OF_Msk          (0x1U << TIM_SR_CC1OF_Pos)                   /*!< 0x00000200 */
#define TIM_SR_CC1OF              TIM_SR_CC1OF_Msk                             /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos          (10U)                                        
#define TIM_SR_CC2OF_Msk          (0x1U << TIM_SR_CC2OF_Pos)                   /*!< 0x00000400 */
#define TIM_SR_CC2OF              TIM_SR_CC2OF_Msk                             /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos          (11U)                                        
#define TIM_SR_CC3OF_Msk          (0x1U << TIM_SR_CC3OF_Pos)                   /*!< 0x00000800 */
#define TIM_SR_CC3OF              TIM_SR_CC3OF_Msk                             /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos          (12U)                                        
#define TIM_SR_CC4OF_Msk          (0x1U << TIM_SR_CC4OF_Pos)                   /*!< 0x00001000 */
#define TIM_SR_CC4OF              TIM_SR_CC4OF_Msk                             /*!<Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIM_EGR register  *******************/
#define TIM_EGR_UG_Pos            (0U)                                         
#define TIM_EGR_UG_Msk            (0x1U << TIM_EGR_UG_Pos)                     /*!< 0x00000001 */
#define TIM_EGR_UG                TIM_EGR_UG_Msk                               /*!<Update Generation */
#define TIM_EGR_CC1G_Pos          (1U)                                         
#define TIM_EGR_CC1G_Msk          (0x1U << TIM_EGR_CC1G_Pos)                   /*!< 0x00000002 */
#define TIM_EGR_CC1G              TIM_EGR_CC1G_Msk                             /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos          (2U)                                         
#define TIM_EGR_CC2G_Msk          (0x1U << TIM_EGR_CC2G_Pos)                   /*!< 0x00000004 */
#define TIM_EGR_CC2G              TIM_EGR_CC2G_Msk                             /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos          (3U)                                         
#define TIM_EGR_CC3G_Msk          (0x1U << TIM_EGR_CC3G_Pos)                   /*!< 0x00000008 */
#define TIM_EGR_CC3G              TIM_EGR_CC3G_Msk                             /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos          (4U)                                         
#define TIM_EGR_CC4G_Msk          (0x1U << TIM_EGR_CC4G_Pos)                   /*!< 0x00000010 */
#define TIM_EGR_CC4G              TIM_EGR_CC4G_Msk                             /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos          (5U)                                         
#define TIM_EGR_COMG_Msk          (0x1U << TIM_EGR_COMG_Pos)                   /*!< 0x00000020 */
#define TIM_EGR_COMG              TIM_EGR_COMG_Msk                             /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos            (6U)                                         
#define TIM_EGR_TG_Msk            (0x1U << TIM_EGR_TG_Pos)                     /*!< 0x00000040 */
#define TIM_EGR_TG                TIM_EGR_TG_Msk                               /*!<Trigger Generation */
#define TIM_EGR_BG_Pos            (7U)                                         
#define TIM_EGR_BG_Msk            (0x1U << TIM_EGR_BG_Pos)                     /*!< 0x00000080 */
#define TIM_EGR_BG                TIM_EGR_BG_Msk                               /*!<Break Generation */

/******************  Bit definition for TIM_CCMR1 register  ******************/
#define TIM_CCMR1_CC1S_Pos        (0U)                                         
#define TIM_CCMR1_CC1S_Msk        (0x3U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR1_CC1S            TIM_CCMR1_CC1S_Msk                           /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0          (0x1U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1          (0x2U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos       (2U)                                         
#define TIM_CCMR1_OC1FE_Msk       (0x1U << TIM_CCMR1_OC1FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE           TIM_CCMR1_OC1FE_Msk                          /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos       (3U)                                         
#define TIM_CCMR1_OC1PE_Msk       (0x1U << TIM_CCMR1_OC1PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE           TIM_CCMR1_OC1PE_Msk                          /*!<Output Compare 1 Preload enable */

#define TIM_CCMR1_OC1M_Pos        (4U)                                         
#define TIM_CCMR1_OC1M_Msk        (0x7U << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000070 */
#define TIM_CCMR1_OC1M            TIM_CCMR1_OC1M_Msk                           /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0          (0x1U << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1          (0x2U << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2          (0x4U << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000040 */

#define TIM_CCMR1_OC1CE_Pos       (7U)                                         
#define TIM_CCMR1_OC1CE_Msk       (0x1U << TIM_CCMR1_OC1CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE           TIM_CCMR1_OC1CE_Msk                          /*!<Output Compare 1Clear Enable */

#define TIM_CCMR1_CC2S_Pos        (8U)                                         
#define TIM_CCMR1_CC2S_Msk        (0x3U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR1_CC2S            TIM_CCMR1_CC2S_Msk                           /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0          (0x1U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1          (0x2U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos       (10U)                                        
#define TIM_CCMR1_OC2FE_Msk       (0x1U << TIM_CCMR1_OC2FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE           TIM_CCMR1_OC2FE_Msk                          /*!<Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos       (11U)                                        
#define TIM_CCMR1_OC2PE_Msk       (0x1U << TIM_CCMR1_OC2PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE           TIM_CCMR1_OC2PE_Msk                          /*!<Output Compare 2 Preload enable */

#define TIM_CCMR1_OC2M_Pos        (12U)                                        
#define TIM_CCMR1_OC2M_Msk        (0x7U << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00007000 */
#define TIM_CCMR1_OC2M            TIM_CCMR1_OC2M_Msk                           /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0          (0x1U << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1          (0x2U << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2          (0x4U << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00004000 */

#define TIM_CCMR1_OC2CE_Pos       (15U)                                        
#define TIM_CCMR1_OC2CE_Msk       (0x1U << TIM_CCMR1_OC2CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE           TIM_CCMR1_OC2CE_Msk                          /*!<Output Compare 2 Clear Enable */

/*---------------------------------------------------------------------------*/

#define TIM_CCMR1_IC1PSC_Pos      (2U)                                         
#define TIM_CCMR1_IC1PSC_Msk      (0x3U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC          TIM_CCMR1_IC1PSC_Msk                         /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0        (0x1U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1        (0x2U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR1_IC1F_Pos        (4U)                                         
#define TIM_CCMR1_IC1F_Msk        (0xFU << TIM_CCMR1_IC1F_Pos)                 /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F            TIM_CCMR1_IC1F_Msk                           /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0          (0x1U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1          (0x2U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2          (0x4U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3          (0x8U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR1_IC2PSC_Pos      (10U)                                        
#define TIM_CCMR1_IC2PSC_Msk      (0x3U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC          TIM_CCMR1_IC2PSC_Msk                         /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_0        (0x1U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1        (0x2U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR1_IC2F_Pos        (12U)                                        
#define TIM_CCMR1_IC2F_Msk        (0xFU << TIM_CCMR1_IC2F_Pos)                 /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F            TIM_CCMR1_IC2F_Msk                           /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0          (0x1U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1          (0x2U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2          (0x4U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3          (0x8U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR2 register  ******************/
#define TIM_CCMR2_CC3S_Pos        (0U)                                         
#define TIM_CCMR2_CC3S_Msk        (0x3U << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR2_CC3S            TIM_CCMR2_CC3S_Msk                           /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_0          (0x1U << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1          (0x2U << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR2_OC3FE_Pos       (2U)                                         
#define TIM_CCMR2_OC3FE_Msk       (0x1U << TIM_CCMR2_OC3FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE           TIM_CCMR2_OC3FE_Msk                          /*!<Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos       (3U)                                         
#define TIM_CCMR2_OC3PE_Msk       (0x1U << TIM_CCMR2_OC3PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE           TIM_CCMR2_OC3PE_Msk                          /*!<Output Compare 3 Preload enable */

#define TIM_CCMR2_OC3M_Pos        (4U)                                         
#define TIM_CCMR2_OC3M_Msk        (0x7U << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000070 */
#define TIM_CCMR2_OC3M            TIM_CCMR2_OC3M_Msk                           /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0          (0x1U << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1          (0x2U << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2          (0x4U << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000040 */

#define TIM_CCMR2_OC3CE_Pos       (7U)                                         
#define TIM_CCMR2_OC3CE_Msk       (0x1U << TIM_CCMR2_OC3CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE           TIM_CCMR2_OC3CE_Msk                          /*!<Output Compare 3 Clear Enable */

#define TIM_CCMR2_CC4S_Pos        (8U)                                         
#define TIM_CCMR2_CC4S_Msk        (0x3U << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR2_CC4S            TIM_CCMR2_CC4S_Msk                           /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0          (0x1U << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1          (0x2U << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR2_OC4FE_Pos       (10U)                                        
#define TIM_CCMR2_OC4FE_Msk       (0x1U << TIM_CCMR2_OC4FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE           TIM_CCMR2_OC4FE_Msk                          /*!<Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos       (11U)                                        
#define TIM_CCMR2_OC4PE_Msk       (0x1U << TIM_CCMR2_OC4PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE           TIM_CCMR2_OC4PE_Msk                          /*!<Output Compare 4 Preload enable */

#define TIM_CCMR2_OC4M_Pos        (12U)                                        
#define TIM_CCMR2_OC4M_Msk        (0x7U << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00007000 */
#define TIM_CCMR2_OC4M            TIM_CCMR2_OC4M_Msk                           /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0          (0x1U << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1          (0x2U << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2          (0x4U << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00004000 */

#define TIM_CCMR2_OC4CE_Pos       (15U)                                        
#define TIM_CCMR2_OC4CE_Msk       (0x1U << TIM_CCMR2_OC4CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE           TIM_CCMR2_OC4CE_Msk                          /*!<Output Compare 4 Clear Enable */

/*---------------------------------------------------------------------------*/

#define TIM_CCMR2_IC3PSC_Pos      (2U)                                         
#define TIM_CCMR2_IC3PSC_Msk      (0x3U << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC          TIM_CCMR2_IC3PSC_Msk                         /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0        (0x1U << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1        (0x2U << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR2_IC3F_Pos        (4U)                                         
#define TIM_CCMR2_IC3F_Msk        (0xFU << TIM_CCMR2_IC3F_Pos)                 /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F            TIM_CCMR2_IC3F_Msk                           /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0          (0x1U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1          (0x2U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2          (0x4U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3          (0x8U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR2_IC4PSC_Pos      (10U)                                        
#define TIM_CCMR2_IC4PSC_Msk      (0x3U << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC          TIM_CCMR2_IC4PSC_Msk                         /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0        (0x1U << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1        (0x2U << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR2_IC4F_Pos        (12U)                                        
#define TIM_CCMR2_IC4F_Msk        (0xFU << TIM_CCMR2_IC4F_Pos)                 /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F            TIM_CCMR2_IC4F_Msk                           /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0          (0x1U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1          (0x2U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2          (0x4U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3          (0x8U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00008000 */

/*******************  Bit definition for TIM_CCER register  ******************/
#define TIM_CCER_CC1E_Pos         (0U)                                         
#define TIM_CCER_CC1E_Msk         (0x1U << TIM_CCER_CC1E_Pos)                  /*!< 0x00000001 */
#define TIM_CCER_CC1E             TIM_CCER_CC1E_Msk                            /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos         (1U)                                         
#define TIM_CCER_CC1P_Msk         (0x1U << TIM_CCER_CC1P_Pos)                  /*!< 0x00000002 */
#define TIM_CCER_CC1P             TIM_CCER_CC1P_Msk                            /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos        (2U)                                         
#define TIM_CCER_CC1NE_Msk        (0x1U << TIM_CCER_CC1NE_Pos)                 /*!< 0x00000004 */
#define TIM_CCER_CC1NE            TIM_CCER_CC1NE_Msk                           /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos        (3U)                                         
#define TIM_CCER_CC1NP_Msk        (0x1U << TIM_CCER_CC1NP_Pos)                 /*!< 0x00000008 */
#define TIM_CCER_CC1NP            TIM_CCER_CC1NP_Msk                           /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos         (4U)                                         
#define TIM_CCER_CC2E_Msk         (0x1U << TIM_CCER_CC2E_Pos)                  /*!< 0x00000010 */
#define TIM_CCER_CC2E             TIM_CCER_CC2E_Msk                            /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos         (5U)                                         
#define TIM_CCER_CC2P_Msk         (0x1U << TIM_CCER_CC2P_Pos)                  /*!< 0x00000020 */
#define TIM_CCER_CC2P             TIM_CCER_CC2P_Msk                            /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos        (6U)                                         
#define TIM_CCER_CC2NE_Msk        (0x1U << TIM_CCER_CC2NE_Pos)                 /*!< 0x00000040 */
#define TIM_CCER_CC2NE            TIM_CCER_CC2NE_Msk                           /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos        (7U)                                         
#define TIM_CCER_CC2NP_Msk        (0x1U << TIM_CCER_CC2NP_Pos)                 /*!< 0x00000080 */
#define TIM_CCER_CC2NP            TIM_CCER_CC2NP_Msk                           /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos         (8U)                                         
#define TIM_CCER_CC3E_Msk         (0x1U << TIM_CCER_CC3E_Pos)                  /*!< 0x00000100 */
#define TIM_CCER_CC3E             TIM_CCER_CC3E_Msk                            /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos         (9U)                                         
#define TIM_CCER_CC3P_Msk         (0x1U << TIM_CCER_CC3P_Pos)                  /*!< 0x00000200 */
#define TIM_CCER_CC3P             TIM_CCER_CC3P_Msk                            /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos        (10U)                                        
#define TIM_CCER_CC3NE_Msk        (0x1U << TIM_CCER_CC3NE_Pos)                 /*!< 0x00000400 */
#define TIM_CCER_CC3NE            TIM_CCER_CC3NE_Msk                           /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos        (11U)                                        
#define TIM_CCER_CC3NP_Msk        (0x1U << TIM_CCER_CC3NP_Pos)                 /*!< 0x00000800 */
#define TIM_CCER_CC3NP            TIM_CCER_CC3NP_Msk                           /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos         (12U)                                        
#define TIM_CCER_CC4E_Msk         (0x1U << TIM_CCER_CC4E_Pos)                  /*!< 0x00001000 */
#define TIM_CCER_CC4E             TIM_CCER_CC4E_Msk                            /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos         (13U)                                        
#define TIM_CCER_CC4P_Msk         (0x1U << TIM_CCER_CC4P_Pos)                  /*!< 0x00002000 */
#define TIM_CCER_CC4P             TIM_CCER_CC4P_Msk                            /*!<Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NP_Pos        (15U)                                        
#define TIM_CCER_CC4NP_Msk        (0x1U << TIM_CCER_CC4NP_Pos)                 /*!< 0x00008000 */
#define TIM_CCER_CC4NP            TIM_CCER_CC4NP_Msk                           /*!<Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIM_CNT register  *******************/
#define TIM_CNT_CNT_Pos           (0U)                                         
#define TIM_CNT_CNT_Msk           (0xFFFFFFFFU << TIM_CNT_CNT_Pos)             /*!< 0xFFFFFFFF */
#define TIM_CNT_CNT               TIM_CNT_CNT_Msk                              /*!<Counter Value */

/*******************  Bit definition for TIM_PSC register  *******************/
#define TIM_PSC_PSC_Pos           (0U)                                         
#define TIM_PSC_PSC_Msk           (0xFFFFU << TIM_PSC_PSC_Pos)                 /*!< 0x0000FFFF */
#define TIM_PSC_PSC               TIM_PSC_PSC_Msk                              /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  *******************/
#define TIM_ARR_ARR_Pos           (0U)                                         
#define TIM_ARR_ARR_Msk           (0xFFFFFFFFU << TIM_ARR_ARR_Pos)             /*!< 0xFFFFFFFF */
#define TIM_ARR_ARR               TIM_ARR_ARR_Msk                              /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  *******************/
#define TIM_RCR_REP_Pos           (0U)                                         
#define TIM_RCR_REP_Msk           (0xFFU << TIM_RCR_REP_Pos)                   /*!< 0x000000FF */
#define TIM_RCR_REP               TIM_RCR_REP_Msk                              /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  ******************/
#define TIM_CCR1_CCR1_Pos         (0U)                                         
#define TIM_CCR1_CCR1_Msk         (0xFFFFU << TIM_CCR1_CCR1_Pos)               /*!< 0x0000FFFF */
#define TIM_CCR1_CCR1             TIM_CCR1_CCR1_Msk                            /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  ******************/
#define TIM_CCR2_CCR2_Pos         (0U)                                         
#define TIM_CCR2_CCR2_Msk         (0xFFFFU << TIM_CCR2_CCR2_Pos)               /*!< 0x0000FFFF */
#define TIM_CCR2_CCR2             TIM_CCR2_CCR2_Msk                            /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  ******************/
#define TIM_CCR3_CCR3_Pos         (0U)                                         
#define TIM_CCR3_CCR3_Msk         (0xFFFFU << TIM_CCR3_CCR3_Pos)               /*!< 0x0000FFFF */
#define TIM_CCR3_CCR3             TIM_CCR3_CCR3_Msk                            /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  ******************/
#define TIM_CCR4_CCR4_Pos         (0U)                                         
#define TIM_CCR4_CCR4_Msk         (0xFFFFU << TIM_CCR4_CCR4_Pos)               /*!< 0x0000FFFF */
#define TIM_CCR4_CCR4             TIM_CCR4_CCR4_Msk                            /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIM_BDTR register  ******************/
#define TIM_BDTR_DTG_Pos          (0U)                                         
#define TIM_BDTR_DTG_Msk          (0xFFU << TIM_BDTR_DTG_Pos)                  /*!< 0x000000FF */
#define TIM_BDTR_DTG              TIM_BDTR_DTG_Msk                             /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0            (0x01U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000001 */
#define TIM_BDTR_DTG_1            (0x02U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000002 */
#define TIM_BDTR_DTG_2            (0x04U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000004 */
#define TIM_BDTR_DTG_3            (0x08U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000008 */
#define TIM_BDTR_DTG_4            (0x10U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000010 */
#define TIM_BDTR_DTG_5            (0x20U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000020 */
#define TIM_BDTR_DTG_6            (0x40U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000040 */
#define TIM_BDTR_DTG_7            (0x80U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000080 */

#define TIM_BDTR_LOCK_Pos         (8U)                                         
#define TIM_BDTR_LOCK_Msk         (0x3U << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000300 */
#define TIM_BDTR_LOCK             TIM_BDTR_LOCK_Msk                            /*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0           (0x1U << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1           (0x2U << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000200 */

#define TIM_BDTR_OSSI_Pos         (10U)                                        
#define TIM_BDTR_OSSI_Msk         (0x1U << TIM_BDTR_OSSI_Pos)                  /*!< 0x00000400 */
#define TIM_BDTR_OSSI             TIM_BDTR_OSSI_Msk                            /*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos         (11U)                                        
#define TIM_BDTR_OSSR_Msk         (0x1U << TIM_BDTR_OSSR_Pos)                  /*!< 0x00000800 */
#define TIM_BDTR_OSSR             TIM_BDTR_OSSR_Msk                            /*!<Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos          (12U)                                        
#define TIM_BDTR_BKE_Msk          (0x1U << TIM_BDTR_BKE_Pos)                   /*!< 0x00001000 */
#define TIM_BDTR_BKE              TIM_BDTR_BKE_Msk                             /*!<Break enable */
#define TIM_BDTR_BKP_Pos          (13U)                                        
#define TIM_BDTR_BKP_Msk          (0x1U << TIM_BDTR_BKP_Pos)                   /*!< 0x00002000 */
#define TIM_BDTR_BKP              TIM_BDTR_BKP_Msk                             /*!<Break Polarity */
#define TIM_BDTR_AOE_Pos          (14U)                                        
#define TIM_BDTR_AOE_Msk          (0x1U << TIM_BDTR_AOE_Pos)                   /*!< 0x00004000 */
#define TIM_BDTR_AOE              TIM_BDTR_AOE_Msk                             /*!<Automatic Output enable */
#define TIM_BDTR_MOE_Pos          (15U)                                        
#define TIM_BDTR_MOE_Msk          (0x1U << TIM_BDTR_MOE_Pos)                   /*!< 0x00008000 */
#define TIM_BDTR_MOE              TIM_BDTR_MOE_Msk                             /*!<Main Output enable */

/*******************  Bit definition for TIM_DCR register  *******************/
#define TIM_DCR_DBA_Pos           (0U)                                         
#define TIM_DCR_DBA_Msk           (0x1FU << TIM_DCR_DBA_Pos)                   /*!< 0x0000001F */
#define TIM_DCR_DBA               TIM_DCR_DBA_Msk                              /*!<DBA[4:0] bits (DMA Base Address) */
#define TIM_DCR_DBA_0             (0x01U << TIM_DCR_DBA_Pos)                   /*!< 0x00000001 */
#define TIM_DCR_DBA_1             (0x02U << TIM_DCR_DBA_Pos)                   /*!< 0x00000002 */
#define TIM_DCR_DBA_2             (0x04U << TIM_DCR_DBA_Pos)                   /*!< 0x00000004 */
#define TIM_DCR_DBA_3             (0x08U << TIM_DCR_DBA_Pos)                   /*!< 0x00000008 */
#define TIM_DCR_DBA_4             (0x10U << TIM_DCR_DBA_Pos)                   /*!< 0x00000010 */

#define TIM_DCR_DBL_Pos           (8U)                                         
#define TIM_DCR_DBL_Msk           (0x1FU << TIM_DCR_DBL_Pos)                   /*!< 0x00001F00 */
#define TIM_DCR_DBL               TIM_DCR_DBL_Msk                              /*!<DBL[4:0] bits (DMA Burst Length) */
#define TIM_DCR_DBL_0             (0x01U << TIM_DCR_DBL_Pos)                   /*!< 0x00000100 */
#define TIM_DCR_DBL_1             (0x02U << TIM_DCR_DBL_Pos)                   /*!< 0x00000200 */
#define TIM_DCR_DBL_2             (0x04U << TIM_DCR_DBL_Pos)                   /*!< 0x00000400 */
#define TIM_DCR_DBL_3             (0x08U << TIM_DCR_DBL_Pos)                   /*!< 0x00000800 */
#define TIM_DCR_DBL_4             (0x10U << TIM_DCR_DBL_Pos)                   /*!< 0x00001000 */

/*******************  Bit definition for TIM_DMAR register  ******************/
#define TIM_DMAR_DMAB_Pos         (0U)                                         
#define TIM_DMAR_DMAB_Msk         (0xFFFFU << TIM_DMAR_DMAB_Pos)               /*!< 0x0000FFFF */
#define TIM_DMAR_DMAB             TIM_DMAR_DMAB_Msk                            /*!<DMA register for burst accesses */

/*******************  Bit definition for TIM14_OR register  ********************/
#define TIM14_OR_TI1_RMP_Pos      (0U)                                         
#define TIM14_OR_TI1_RMP_Msk      (0x3U << TIM14_OR_TI1_RMP_Pos)               /*!< 0x00000003 */
#define TIM14_OR_TI1_RMP          TIM14_OR_TI1_RMP_Msk                         /*!<TI1_RMP[1:0] bits (TIM14 Input 4 remap) */
#define TIM14_OR_TI1_RMP_0        (0x1U << TIM14_OR_TI1_RMP_Pos)               /*!< 0x00000001 */
#define TIM14_OR_TI1_RMP_1        (0x2U << TIM14_OR_TI1_RMP_Pos)               /*!< 0x00000002 */

/******************************************************************************/
/*                                                                            */
/*                          Touch Sensing Controller (TSC)                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TSC_CR register  *********************/
#define TSC_CR_TSCE_Pos          (0U)                                          
#define TSC_CR_TSCE_Msk          (0x1U << TSC_CR_TSCE_Pos)                     /*!< 0x00000001 */
#define TSC_CR_TSCE              TSC_CR_TSCE_Msk                               /*!<Touch sensing controller enable */
#define TSC_CR_START_Pos         (1U)                                          
#define TSC_CR_START_Msk         (0x1U << TSC_CR_START_Pos)                    /*!< 0x00000002 */
#define TSC_CR_START             TSC_CR_START_Msk                              /*!<Start acquisition */
#define TSC_CR_AM_Pos            (2U)                                          
#define TSC_CR_AM_Msk            (0x1U << TSC_CR_AM_Pos)                       /*!< 0x00000004 */
#define TSC_CR_AM                TSC_CR_AM_Msk                                 /*!<Acquisition mode */
#define TSC_CR_SYNCPOL_Pos       (3U)                                          
#define TSC_CR_SYNCPOL_Msk       (0x1U << TSC_CR_SYNCPOL_Pos)                  /*!< 0x00000008 */
#define TSC_CR_SYNCPOL           TSC_CR_SYNCPOL_Msk                            /*!<Synchronization pin polarity */
#define TSC_CR_IODEF_Pos         (4U)                                          
#define TSC_CR_IODEF_Msk         (0x1U << TSC_CR_IODEF_Pos)                    /*!< 0x00000010 */
#define TSC_CR_IODEF             TSC_CR_IODEF_Msk                              /*!<IO default mode */

#define TSC_CR_MCV_Pos           (5U)                                          
#define TSC_CR_MCV_Msk           (0x7U << TSC_CR_MCV_Pos)                      /*!< 0x000000E0 */
#define TSC_CR_MCV               TSC_CR_MCV_Msk                                /*!<MCV[2:0] bits (Max Count Value) */
#define TSC_CR_MCV_0             (0x1U << TSC_CR_MCV_Pos)                      /*!< 0x00000020 */
#define TSC_CR_MCV_1             (0x2U << TSC_CR_MCV_Pos)                      /*!< 0x00000040 */
#define TSC_CR_MCV_2             (0x4U << TSC_CR_MCV_Pos)                      /*!< 0x00000080 */

#define TSC_CR_PGPSC_Pos         (12U)                                         
#define TSC_CR_PGPSC_Msk         (0x7U << TSC_CR_PGPSC_Pos)                    /*!< 0x00007000 */
#define TSC_CR_PGPSC             TSC_CR_PGPSC_Msk                              /*!<PGPSC[2:0] bits (Pulse Generator Prescaler) */
#define TSC_CR_PGPSC_0           (0x1U << TSC_CR_PGPSC_Pos)                    /*!< 0x00001000 */
#define TSC_CR_PGPSC_1           (0x2U << TSC_CR_PGPSC_Pos)                    /*!< 0x00002000 */
#define TSC_CR_PGPSC_2           (0x4U << TSC_CR_PGPSC_Pos)                    /*!< 0x00004000 */

#define TSC_CR_SSPSC_Pos         (15U)                                         
#define TSC_CR_SSPSC_Msk         (0x1U << TSC_CR_SSPSC_Pos)                    /*!< 0x00008000 */
#define TSC_CR_SSPSC             TSC_CR_SSPSC_Msk                              /*!<Spread Spectrum Prescaler */
#define TSC_CR_SSE_Pos           (16U)                                         
#define TSC_CR_SSE_Msk           (0x1U << TSC_CR_SSE_Pos)                      /*!< 0x00010000 */
#define TSC_CR_SSE               TSC_CR_SSE_Msk                                /*!<Spread Spectrum Enable */

#define TSC_CR_SSD_Pos           (17U)                                         
#define TSC_CR_SSD_Msk           (0x7FU << TSC_CR_SSD_Pos)                     /*!< 0x00FE0000 */
#define TSC_CR_SSD               TSC_CR_SSD_Msk                                /*!<SSD[6:0] bits (Spread Spectrum Deviation) */
#define TSC_CR_SSD_0             (0x01U << TSC_CR_SSD_Pos)                     /*!< 0x00020000 */
#define TSC_CR_SSD_1             (0x02U << TSC_CR_SSD_Pos)                     /*!< 0x00040000 */
#define TSC_CR_SSD_2             (0x04U << TSC_CR_SSD_Pos)                     /*!< 0x00080000 */
#define TSC_CR_SSD_3             (0x08U << TSC_CR_SSD_Pos)                     /*!< 0x00100000 */
#define TSC_CR_SSD_4             (0x10U << TSC_CR_SSD_Pos)                     /*!< 0x00200000 */
#define TSC_CR_SSD_5             (0x20U << TSC_CR_SSD_Pos)                     /*!< 0x00400000 */
#define TSC_CR_SSD_6             (0x40U << TSC_CR_SSD_Pos)                     /*!< 0x00800000 */

#define TSC_CR_CTPL_Pos          (24U)                                         
#define TSC_CR_CTPL_Msk          (0xFU << TSC_CR_CTPL_Pos)                     /*!< 0x0F000000 */
#define TSC_CR_CTPL              TSC_CR_CTPL_Msk                               /*!<CTPL[3:0] bits (Charge Transfer pulse low) */
#define TSC_CR_CTPL_0            (0x1U << TSC_CR_CTPL_Pos)                     /*!< 0x01000000 */
#define TSC_CR_CTPL_1            (0x2U << TSC_CR_CTPL_Pos)                     /*!< 0x02000000 */
#define TSC_CR_CTPL_2            (0x4U << TSC_CR_CTPL_Pos)                     /*!< 0x04000000 */
#define TSC_CR_CTPL_3            (0x8U << TSC_CR_CTPL_Pos)                     /*!< 0x08000000 */

#define TSC_CR_CTPH_Pos          (28U)                                         
#define TSC_CR_CTPH_Msk          (0xFU << TSC_CR_CTPH_Pos)                     /*!< 0xF0000000 */
#define TSC_CR_CTPH              TSC_CR_CTPH_Msk                               /*!<CTPH[3:0] bits (Charge Transfer pulse high) */
#define TSC_CR_CTPH_0            (0x1U << TSC_CR_CTPH_Pos)                     /*!< 0x10000000 */
#define TSC_CR_CTPH_1            (0x2U << TSC_CR_CTPH_Pos)                     /*!< 0x20000000 */
#define TSC_CR_CTPH_2            (0x4U << TSC_CR_CTPH_Pos)                     /*!< 0x40000000 */
#define TSC_CR_CTPH_3            (0x8U << TSC_CR_CTPH_Pos)                     /*!< 0x80000000 */

/*******************  Bit definition for TSC_IER register  ********************/
#define TSC_IER_EOAIE_Pos        (0U)                                          
#define TSC_IER_EOAIE_Msk        (0x1U << TSC_IER_EOAIE_Pos)                   /*!< 0x00000001 */
#define TSC_IER_EOAIE            TSC_IER_EOAIE_Msk                             /*!<End of acquisition interrupt enable */
#define TSC_IER_MCEIE_Pos        (1U)                                          
#define TSC_IER_MCEIE_Msk        (0x1U << TSC_IER_MCEIE_Pos)                   /*!< 0x00000002 */
#define TSC_IER_MCEIE            TSC_IER_MCEIE_Msk                             /*!<Max count error interrupt enable */

/*******************  Bit definition for TSC_ICR register  ********************/
#define TSC_ICR_EOAIC_Pos        (0U)                                          
#define TSC_ICR_EOAIC_Msk        (0x1U << TSC_ICR_EOAIC_Pos)                   /*!< 0x00000001 */
#define TSC_ICR_EOAIC            TSC_ICR_EOAIC_Msk                             /*!<End of acquisition interrupt clear */
#define TSC_ICR_MCEIC_Pos        (1U)                                          
#define TSC_ICR_MCEIC_Msk        (0x1U << TSC_ICR_MCEIC_Pos)                   /*!< 0x00000002 */
#define TSC_ICR_MCEIC            TSC_ICR_MCEIC_Msk                             /*!<Max count error interrupt clear */

/*******************  Bit definition for TSC_ISR register  ********************/
#define TSC_ISR_EOAF_Pos         (0U)                                          
#define TSC_ISR_EOAF_Msk         (0x1U << TSC_ISR_EOAF_Pos)                    /*!< 0x00000001 */
#define TSC_ISR_EOAF             TSC_ISR_EOAF_Msk                              /*!<End of acquisition flag */
#define TSC_ISR_MCEF_Pos         (1U)                                          
#define TSC_ISR_MCEF_Msk         (0x1U << TSC_ISR_MCEF_Pos)                    /*!< 0x00000002 */
#define TSC_ISR_MCEF             TSC_ISR_MCEF_Msk                              /*!<Max count error flag */

/*******************  Bit definition for TSC_IOHCR register  ******************/
#define TSC_IOHCR_G1_IO1_Pos     (0U)                                          
#define TSC_IOHCR_G1_IO1_Msk     (0x1U << TSC_IOHCR_G1_IO1_Pos)                /*!< 0x00000001 */
#define TSC_IOHCR_G1_IO1         TSC_IOHCR_G1_IO1_Msk                          /*!<GROUP1_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO2_Pos     (1U)                                          
#define TSC_IOHCR_G1_IO2_Msk     (0x1U << TSC_IOHCR_G1_IO2_Pos)                /*!< 0x00000002 */
#define TSC_IOHCR_G1_IO2         TSC_IOHCR_G1_IO2_Msk                          /*!<GROUP1_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO3_Pos     (2U)                                          
#define TSC_IOHCR_G1_IO3_Msk     (0x1U << TSC_IOHCR_G1_IO3_Pos)                /*!< 0x00000004 */
#define TSC_IOHCR_G1_IO3         TSC_IOHCR_G1_IO3_Msk                          /*!<GROUP1_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO4_Pos     (3U)                                          
#define TSC_IOHCR_G1_IO4_Msk     (0x1U << TSC_IOHCR_G1_IO4_Pos)                /*!< 0x00000008 */
#define TSC_IOHCR_G1_IO4         TSC_IOHCR_G1_IO4_Msk                          /*!<GROUP1_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO1_Pos     (4U)                                          
#define TSC_IOHCR_G2_IO1_Msk     (0x1U << TSC_IOHCR_G2_IO1_Pos)                /*!< 0x00000010 */
#define TSC_IOHCR_G2_IO1         TSC_IOHCR_G2_IO1_Msk                          /*!<GROUP2_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO2_Pos     (5U)                                          
#define TSC_IOHCR_G2_IO2_Msk     (0x1U << TSC_IOHCR_G2_IO2_Pos)                /*!< 0x00000020 */
#define TSC_IOHCR_G2_IO2         TSC_IOHCR_G2_IO2_Msk                          /*!<GROUP2_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO3_Pos     (6U)                                          
#define TSC_IOHCR_G2_IO3_Msk     (0x1U << TSC_IOHCR_G2_IO3_Pos)                /*!< 0x00000040 */
#define TSC_IOHCR_G2_IO3         TSC_IOHCR_G2_IO3_Msk                          /*!<GROUP2_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO4_Pos     (7U)                                          
#define TSC_IOHCR_G2_IO4_Msk     (0x1U << TSC_IOHCR_G2_IO4_Pos)                /*!< 0x00000080 */
#define TSC_IOHCR_G2_IO4         TSC_IOHCR_G2_IO4_Msk                          /*!<GROUP2_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO1_Pos     (8U)                                          
#define TSC_IOHCR_G3_IO1_Msk     (0x1U << TSC_IOHCR_G3_IO1_Pos)                /*!< 0x00000100 */
#define TSC_IOHCR_G3_IO1         TSC_IOHCR_G3_IO1_Msk                          /*!<GROUP3_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO2_Pos     (9U)                                          
#define TSC_IOHCR_G3_IO2_Msk     (0x1U << TSC_IOHCR_G3_IO2_Pos)                /*!< 0x00000200 */
#define TSC_IOHCR_G3_IO2         TSC_IOHCR_G3_IO2_Msk                          /*!<GROUP3_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO3_Pos     (10U)                                         
#define TSC_IOHCR_G3_IO3_Msk     (0x1U << TSC_IOHCR_G3_IO3_Pos)                /*!< 0x00000400 */
#define TSC_IOHCR_G3_IO3         TSC_IOHCR_G3_IO3_Msk                          /*!<GROUP3_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO4_Pos     (11U)                                         
#define TSC_IOHCR_G3_IO4_Msk     (0x1U << TSC_IOHCR_G3_IO4_Pos)                /*!< 0x00000800 */
#define TSC_IOHCR_G3_IO4         TSC_IOHCR_G3_IO4_Msk                          /*!<GROUP3_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO1_Pos     (12U)                                         
#define TSC_IOHCR_G4_IO1_Msk     (0x1U << TSC_IOHCR_G4_IO1_Pos)                /*!< 0x00001000 */
#define TSC_IOHCR_G4_IO1         TSC_IOHCR_G4_IO1_Msk                          /*!<GROUP4_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO2_Pos     (13U)                                         
#define TSC_IOHCR_G4_IO2_Msk     (0x1U << TSC_IOHCR_G4_IO2_Pos)                /*!< 0x00002000 */
#define TSC_IOHCR_G4_IO2         TSC_IOHCR_G4_IO2_Msk                          /*!<GROUP4_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO3_Pos     (14U)                                         
#define TSC_IOHCR_G4_IO3_Msk     (0x1U << TSC_IOHCR_G4_IO3_Pos)                /*!< 0x00004000 */
#define TSC_IOHCR_G4_IO3         TSC_IOHCR_G4_IO3_Msk                          /*!<GROUP4_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO4_Pos     (15U)                                         
#define TSC_IOHCR_G4_IO4_Msk     (0x1U << TSC_IOHCR_G4_IO4_Pos)                /*!< 0x00008000 */
#define TSC_IOHCR_G4_IO4         TSC_IOHCR_G4_IO4_Msk                          /*!<GROUP4_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO1_Pos     (16U)                                         
#define TSC_IOHCR_G5_IO1_Msk     (0x1U << TSC_IOHCR_G5_IO1_Pos)                /*!< 0x00010000 */
#define TSC_IOHCR_G5_IO1         TSC_IOHCR_G5_IO1_Msk                          /*!<GROUP5_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO2_Pos     (17U)                                         
#define TSC_IOHCR_G5_IO2_Msk     (0x1U << TSC_IOHCR_G5_IO2_Pos)                /*!< 0x00020000 */
#define TSC_IOHCR_G5_IO2         TSC_IOHCR_G5_IO2_Msk                          /*!<GROUP5_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO3_Pos     (18U)                                         
#define TSC_IOHCR_G5_IO3_Msk     (0x1U << TSC_IOHCR_G5_IO3_Pos)                /*!< 0x00040000 */
#define TSC_IOHCR_G5_IO3         TSC_IOHCR_G5_IO3_Msk                          /*!<GROUP5_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO4_Pos     (19U)                                         
#define TSC_IOHCR_G5_IO4_Msk     (0x1U << TSC_IOHCR_G5_IO4_Pos)                /*!< 0x00080000 */
#define TSC_IOHCR_G5_IO4         TSC_IOHCR_G5_IO4_Msk                          /*!<GROUP5_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO1_Pos     (20U)                                         
#define TSC_IOHCR_G6_IO1_Msk     (0x1U << TSC_IOHCR_G6_IO1_Pos)                /*!< 0x00100000 */
#define TSC_IOHCR_G6_IO1         TSC_IOHCR_G6_IO1_Msk                          /*!<GROUP6_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO2_Pos     (21U)                                         
#define TSC_IOHCR_G6_IO2_Msk     (0x1U << TSC_IOHCR_G6_IO2_Pos)                /*!< 0x00200000 */
#define TSC_IOHCR_G6_IO2         TSC_IOHCR_G6_IO2_Msk                          /*!<GROUP6_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO3_Pos     (22U)                                         
#define TSC_IOHCR_G6_IO3_Msk     (0x1U << TSC_IOHCR_G6_IO3_Pos)                /*!< 0x00400000 */
#define TSC_IOHCR_G6_IO3         TSC_IOHCR_G6_IO3_Msk                          /*!<GROUP6_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO4_Pos     (23U)                                         
#define TSC_IOHCR_G6_IO4_Msk     (0x1U << TSC_IOHCR_G6_IO4_Pos)                /*!< 0x00800000 */
#define TSC_IOHCR_G6_IO4         TSC_IOHCR_G6_IO4_Msk                          /*!<GROUP6_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO1_Pos     (24U)                                         
#define TSC_IOHCR_G7_IO1_Msk     (0x1U << TSC_IOHCR_G7_IO1_Pos)                /*!< 0x01000000 */
#define TSC_IOHCR_G7_IO1         TSC_IOHCR_G7_IO1_Msk                          /*!<GROUP7_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO2_Pos     (25U)                                         
#define TSC_IOHCR_G7_IO2_Msk     (0x1U << TSC_IOHCR_G7_IO2_Pos)                /*!< 0x02000000 */
#define TSC_IOHCR_G7_IO2         TSC_IOHCR_G7_IO2_Msk                          /*!<GROUP7_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO3_Pos     (26U)                                         
#define TSC_IOHCR_G7_IO3_Msk     (0x1U << TSC_IOHCR_G7_IO3_Pos)                /*!< 0x04000000 */
#define TSC_IOHCR_G7_IO3         TSC_IOHCR_G7_IO3_Msk                          /*!<GROUP7_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO4_Pos     (27U)                                         
#define TSC_IOHCR_G7_IO4_Msk     (0x1U << TSC_IOHCR_G7_IO4_Pos)                /*!< 0x08000000 */
#define TSC_IOHCR_G7_IO4         TSC_IOHCR_G7_IO4_Msk                          /*!<GROUP7_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G8_IO1_Pos     (28U)                                         
#define TSC_IOHCR_G8_IO1_Msk     (0x1U << TSC_IOHCR_G8_IO1_Pos)                /*!< 0x10000000 */
#define TSC_IOHCR_G8_IO1         TSC_IOHCR_G8_IO1_Msk                          /*!<GROUP8_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G8_IO2_Pos     (29U)                                         
#define TSC_IOHCR_G8_IO2_Msk     (0x1U << TSC_IOHCR_G8_IO2_Pos)                /*!< 0x20000000 */
#define TSC_IOHCR_G8_IO2         TSC_IOHCR_G8_IO2_Msk                          /*!<GROUP8_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G8_IO3_Pos     (30U)                                         
#define TSC_IOHCR_G8_IO3_Msk     (0x1U << TSC_IOHCR_G8_IO3_Pos)                /*!< 0x40000000 */
#define TSC_IOHCR_G8_IO3         TSC_IOHCR_G8_IO3_Msk                          /*!<GROUP8_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G8_IO4_Pos     (31U)                                         
#define TSC_IOHCR_G8_IO4_Msk     (0x1U << TSC_IOHCR_G8_IO4_Pos)                /*!< 0x80000000 */
#define TSC_IOHCR_G8_IO4         TSC_IOHCR_G8_IO4_Msk                          /*!<GROUP8_IO4 schmitt trigger hysteresis mode */

/*******************  Bit definition for TSC_IOASCR register  *****************/
#define TSC_IOASCR_G1_IO1_Pos    (0U)                                          
#define TSC_IOASCR_G1_IO1_Msk    (0x1U << TSC_IOASCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOASCR_G1_IO1        TSC_IOASCR_G1_IO1_Msk                         /*!<GROUP1_IO1 analog switch enable */
#define TSC_IOASCR_G1_IO2_Pos    (1U)                                          
#define TSC_IOASCR_G1_IO2_Msk    (0x1U << TSC_IOASCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOASCR_G1_IO2        TSC_IOASCR_G1_IO2_Msk                         /*!<GROUP1_IO2 analog switch enable */
#define TSC_IOASCR_G1_IO3_Pos    (2U)                                          
#define TSC_IOASCR_G1_IO3_Msk    (0x1U << TSC_IOASCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOASCR_G1_IO3        TSC_IOASCR_G1_IO3_Msk                         /*!<GROUP1_IO3 analog switch enable */
#define TSC_IOASCR_G1_IO4_Pos    (3U)                                          
#define TSC_IOASCR_G1_IO4_Msk    (0x1U << TSC_IOASCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOASCR_G1_IO4        TSC_IOASCR_G1_IO4_Msk                         /*!<GROUP1_IO4 analog switch enable */
#define TSC_IOASCR_G2_IO1_Pos    (4U)                                          
#define TSC_IOASCR_G2_IO1_Msk    (0x1U << TSC_IOASCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOASCR_G2_IO1        TSC_IOASCR_G2_IO1_Msk                         /*!<GROUP2_IO1 analog switch enable */
#define TSC_IOASCR_G2_IO2_Pos    (5U)                                          
#define TSC_IOASCR_G2_IO2_Msk    (0x1U << TSC_IOASCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOASCR_G2_IO2        TSC_IOASCR_G2_IO2_Msk                         /*!<GROUP2_IO2 analog switch enable */
#define TSC_IOASCR_G2_IO3_Pos    (6U)                                          
#define TSC_IOASCR_G2_IO3_Msk    (0x1U << TSC_IOASCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOASCR_G2_IO3        TSC_IOASCR_G2_IO3_Msk                         /*!<GROUP2_IO3 analog switch enable */
#define TSC_IOASCR_G2_IO4_Pos    (7U)                                          
#define TSC_IOASCR_G2_IO4_Msk    (0x1U << TSC_IOASCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOASCR_G2_IO4        TSC_IOASCR_G2_IO4_Msk                         /*!<GROUP2_IO4 analog switch enable */
#define TSC_IOASCR_G3_IO1_Pos    (8U)                                          
#define TSC_IOASCR_G3_IO1_Msk    (0x1U << TSC_IOASCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOASCR_G3_IO1        TSC_IOASCR_G3_IO1_Msk                         /*!<GROUP3_IO1 analog switch enable */
#define TSC_IOASCR_G3_IO2_Pos    (9U)                                          
#define TSC_IOASCR_G3_IO2_Msk    (0x1U << TSC_IOASCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOASCR_G3_IO2        TSC_IOASCR_G3_IO2_Msk                         /*!<GROUP3_IO2 analog switch enable */
#define TSC_IOASCR_G3_IO3_Pos    (10U)                                         
#define TSC_IOASCR_G3_IO3_Msk    (0x1U << TSC_IOASCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOASCR_G3_IO3        TSC_IOASCR_G3_IO3_Msk                         /*!<GROUP3_IO3 analog switch enable */
#define TSC_IOASCR_G3_IO4_Pos    (11U)                                         
#define TSC_IOASCR_G3_IO4_Msk    (0x1U << TSC_IOASCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOASCR_G3_IO4        TSC_IOASCR_G3_IO4_Msk                         /*!<GROUP3_IO4 analog switch enable */
#define TSC_IOASCR_G4_IO1_Pos    (12U)                                         
#define TSC_IOASCR_G4_IO1_Msk    (0x1U << TSC_IOASCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOASCR_G4_IO1        TSC_IOASCR_G4_IO1_Msk                         /*!<GROUP4_IO1 analog switch enable */
#define TSC_IOASCR_G4_IO2_Pos    (13U)                                         
#define TSC_IOASCR_G4_IO2_Msk    (0x1U << TSC_IOASCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOASCR_G4_IO2        TSC_IOASCR_G4_IO2_Msk                         /*!<GROUP4_IO2 analog switch enable */
#define TSC_IOASCR_G4_IO3_Pos    (14U)                                         
#define TSC_IOASCR_G4_IO3_Msk    (0x1U << TSC_IOASCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOASCR_G4_IO3        TSC_IOASCR_G4_IO3_Msk                         /*!<GROUP4_IO3 analog switch enable */
#define TSC_IOASCR_G4_IO4_Pos    (15U)                                         
#define TSC_IOASCR_G4_IO4_Msk    (0x1U << TSC_IOASCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOASCR_G4_IO4        TSC_IOASCR_G4_IO4_Msk                         /*!<GROUP4_IO4 analog switch enable */
#define TSC_IOASCR_G5_IO1_Pos    (16U)                                         
#define TSC_IOASCR_G5_IO1_Msk    (0x1U << TSC_IOASCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOASCR_G5_IO1        TSC_IOASCR_G5_IO1_Msk                         /*!<GROUP5_IO1 analog switch enable */
#define TSC_IOASCR_G5_IO2_Pos    (17U)                                         
#define TSC_IOASCR_G5_IO2_Msk    (0x1U << TSC_IOASCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOASCR_G5_IO2        TSC_IOASCR_G5_IO2_Msk                         /*!<GROUP5_IO2 analog switch enable */
#define TSC_IOASCR_G5_IO3_Pos    (18U)                                         
#define TSC_IOASCR_G5_IO3_Msk    (0x1U << TSC_IOASCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOASCR_G5_IO3        TSC_IOASCR_G5_IO3_Msk                         /*!<GROUP5_IO3 analog switch enable */
#define TSC_IOASCR_G5_IO4_Pos    (19U)                                         
#define TSC_IOASCR_G5_IO4_Msk    (0x1U << TSC_IOASCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOASCR_G5_IO4        TSC_IOASCR_G5_IO4_Msk                         /*!<GROUP5_IO4 analog switch enable */
#define TSC_IOASCR_G6_IO1_Pos    (20U)                                         
#define TSC_IOASCR_G6_IO1_Msk    (0x1U << TSC_IOASCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOASCR_G6_IO1        TSC_IOASCR_G6_IO1_Msk                         /*!<GROUP6_IO1 analog switch enable */
#define TSC_IOASCR_G6_IO2_Pos    (21U)                                         
#define TSC_IOASCR_G6_IO2_Msk    (0x1U << TSC_IOASCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOASCR_G6_IO2        TSC_IOASCR_G6_IO2_Msk                         /*!<GROUP6_IO2 analog switch enable */
#define TSC_IOASCR_G6_IO3_Pos    (22U)                                         
#define TSC_IOASCR_G6_IO3_Msk    (0x1U << TSC_IOASCR_G6_IO3_Pos)               /*!< 0x00400000 */
#define TSC_IOASCR_G6_IO3        TSC_IOASCR_G6_IO3_Msk                         /*!<GROUP6_IO3 analog switch enable */
#define TSC_IOASCR_G6_IO4_Pos    (23U)                                         
#define TSC_IOASCR_G6_IO4_Msk    (0x1U << TSC_IOASCR_G6_IO4_Pos)               /*!< 0x00800000 */
#define TSC_IOASCR_G6_IO4        TSC_IOASCR_G6_IO4_Msk                         /*!<GROUP6_IO4 analog switch enable */
#define TSC_IOASCR_G7_IO1_Pos    (24U)                                         
#define TSC_IOASCR_G7_IO1_Msk    (0x1U << TSC_IOASCR_G7_IO1_Pos)               /*!< 0x01000000 */
#define TSC_IOASCR_G7_IO1        TSC_IOASCR_G7_IO1_Msk                         /*!<GROUP7_IO1 analog switch enable */
#define TSC_IOASCR_G7_IO2_Pos    (25U)                                         
#define TSC_IOASCR_G7_IO2_Msk    (0x1U << TSC_IOASCR_G7_IO2_Pos)               /*!< 0x02000000 */
#define TSC_IOASCR_G7_IO2        TSC_IOASCR_G7_IO2_Msk                         /*!<GROUP7_IO2 analog switch enable */
#define TSC_IOASCR_G7_IO3_Pos    (26U)                                         
#define TSC_IOASCR_G7_IO3_Msk    (0x1U << TSC_IOASCR_G7_IO3_Pos)               /*!< 0x04000000 */
#define TSC_IOASCR_G7_IO3        TSC_IOASCR_G7_IO3_Msk                         /*!<GROUP7_IO3 analog switch enable */
#define TSC_IOASCR_G7_IO4_Pos    (27U)                                         
#define TSC_IOASCR_G7_IO4_Msk    (0x1U << TSC_IOASCR_G7_IO4_Pos)               /*!< 0x08000000 */
#define TSC_IOASCR_G7_IO4        TSC_IOASCR_G7_IO4_Msk                         /*!<GROUP7_IO4 analog switch enable */
#define TSC_IOASCR_G8_IO1_Pos    (28U)                                         
#define TSC_IOASCR_G8_IO1_Msk    (0x1U << TSC_IOASCR_G8_IO1_Pos)               /*!< 0x10000000 */
#define TSC_IOASCR_G8_IO1        TSC_IOASCR_G8_IO1_Msk                         /*!<GROUP8_IO1 analog switch enable */
#define TSC_IOASCR_G8_IO2_Pos    (29U)                                         
#define TSC_IOASCR_G8_IO2_Msk    (0x1U << TSC_IOASCR_G8_IO2_Pos)               /*!< 0x20000000 */
#define TSC_IOASCR_G8_IO2        TSC_IOASCR_G8_IO2_Msk                         /*!<GROUP8_IO2 analog switch enable */
#define TSC_IOASCR_G8_IO3_Pos    (30U)                                         
#define TSC_IOASCR_G8_IO3_Msk    (0x1U << TSC_IOASCR_G8_IO3_Pos)               /*!< 0x40000000 */
#define TSC_IOASCR_G8_IO3        TSC_IOASCR_G8_IO3_Msk                         /*!<GROUP8_IO3 analog switch enable */
#define TSC_IOASCR_G8_IO4_Pos    (31U)                                         
#define TSC_IOASCR_G8_IO4_Msk    (0x1U << TSC_IOASCR_G8_IO4_Pos)               /*!< 0x80000000 */
#define TSC_IOASCR_G8_IO4        TSC_IOASCR_G8_IO4_Msk                         /*!<GROUP8_IO4 analog switch enable */

/*******************  Bit definition for TSC_IOSCR register  ******************/
#define TSC_IOSCR_G1_IO1_Pos     (0U)                                          
#define TSC_IOSCR_G1_IO1_Msk     (0x1U << TSC_IOSCR_G1_IO1_Pos)                /*!< 0x00000001 */
#define TSC_IOSCR_G1_IO1         TSC_IOSCR_G1_IO1_Msk                          /*!<GROUP1_IO1 sampling mode */
#define TSC_IOSCR_G1_IO2_Pos     (1U)                                          
#define TSC_IOSCR_G1_IO2_Msk     (0x1U << TSC_IOSCR_G1_IO2_Pos)                /*!< 0x00000002 */
#define TSC_IOSCR_G1_IO2         TSC_IOSCR_G1_IO2_Msk                          /*!<GROUP1_IO2 sampling mode */
#define TSC_IOSCR_G1_IO3_Pos     (2U)                                          
#define TSC_IOSCR_G1_IO3_Msk     (0x1U << TSC_IOSCR_G1_IO3_Pos)                /*!< 0x00000004 */
#define TSC_IOSCR_G1_IO3         TSC_IOSCR_G1_IO3_Msk                          /*!<GROUP1_IO3 sampling mode */
#define TSC_IOSCR_G1_IO4_Pos     (3U)                                          
#define TSC_IOSCR_G1_IO4_Msk     (0x1U << TSC_IOSCR_G1_IO4_Pos)                /*!< 0x00000008 */
#define TSC_IOSCR_G1_IO4         TSC_IOSCR_G1_IO4_Msk                          /*!<GROUP1_IO4 sampling mode */
#define TSC_IOSCR_G2_IO1_Pos     (4U)                                          
#define TSC_IOSCR_G2_IO1_Msk     (0x1U << TSC_IOSCR_G2_IO1_Pos)                /*!< 0x00000010 */
#define TSC_IOSCR_G2_IO1         TSC_IOSCR_G2_IO1_Msk                          /*!<GROUP2_IO1 sampling mode */
#define TSC_IOSCR_G2_IO2_Pos     (5U)                                          
#define TSC_IOSCR_G2_IO2_Msk     (0x1U << TSC_IOSCR_G2_IO2_Pos)                /*!< 0x00000020 */
#define TSC_IOSCR_G2_IO2         TSC_IOSCR_G2_IO2_Msk                          /*!<GROUP2_IO2 sampling mode */
#define TSC_IOSCR_G2_IO3_Pos     (6U)                                          
#define TSC_IOSCR_G2_IO3_Msk     (0x1U << TSC_IOSCR_G2_IO3_Pos)                /*!< 0x00000040 */
#define TSC_IOSCR_G2_IO3         TSC_IOSCR_G2_IO3_Msk                          /*!<GROUP2_IO3 sampling mode */
#define TSC_IOSCR_G2_IO4_Pos     (7U)                                          
#define TSC_IOSCR_G2_IO4_Msk     (0x1U << TSC_IOSCR_G2_IO4_Pos)                /*!< 0x00000080 */
#define TSC_IOSCR_G2_IO4         TSC_IOSCR_G2_IO4_Msk                          /*!<GROUP2_IO4 sampling mode */
#define TSC_IOSCR_G3_IO1_Pos     (8U)                                          
#define TSC_IOSCR_G3_IO1_Msk     (0x1U << TSC_IOSCR_G3_IO1_Pos)                /*!< 0x00000100 */
#define TSC_IOSCR_G3_IO1         TSC_IOSCR_G3_IO1_Msk                          /*!<GROUP3_IO1 sampling mode */
#define TSC_IOSCR_G3_IO2_Pos     (9U)                                          
#define TSC_IOSCR_G3_IO2_Msk     (0x1U << TSC_IOSCR_G3_IO2_Pos)                /*!< 0x00000200 */
#define TSC_IOSCR_G3_IO2         TSC_IOSCR_G3_IO2_Msk                          /*!<GROUP3_IO2 sampling mode */
#define TSC_IOSCR_G3_IO3_Pos     (10U)                                         
#define TSC_IOSCR_G3_IO3_Msk     (0x1U << TSC_IOSCR_G3_IO3_Pos)                /*!< 0x00000400 */
#define TSC_IOSCR_G3_IO3         TSC_IOSCR_G3_IO3_Msk                          /*!<GROUP3_IO3 sampling mode */
#define TSC_IOSCR_G3_IO4_Pos     (11U)                                         
#define TSC_IOSCR_G3_IO4_Msk     (0x1U << TSC_IOSCR_G3_IO4_Pos)                /*!< 0x00000800 */
#define TSC_IOSCR_G3_IO4         TSC_IOSCR_G3_IO4_Msk                          /*!<GROUP3_IO4 sampling mode */
#define TSC_IOSCR_G4_IO1_Pos     (12U)                                         
#define TSC_IOSCR_G4_IO1_Msk     (0x1U << TSC_IOSCR_G4_IO1_Pos)                /*!< 0x00001000 */
#define TSC_IOSCR_G4_IO1         TSC_IOSCR_G4_IO1_Msk                          /*!<GROUP4_IO1 sampling mode */
#define TSC_IOSCR_G4_IO2_Pos     (13U)                                         
#define TSC_IOSCR_G4_IO2_Msk     (0x1U << TSC_IOSCR_G4_IO2_Pos)                /*!< 0x00002000 */
#define TSC_IOSCR_G4_IO2         TSC_IOSCR_G4_IO2_Msk                          /*!<GROUP4_IO2 sampling mode */
#define TSC_IOSCR_G4_IO3_Pos     (14U)                                         
#define TSC_IOSCR_G4_IO3_Msk     (0x1U << TSC_IOSCR_G4_IO3_Pos)                /*!< 0x00004000 */
#define TSC_IOSCR_G4_IO3         TSC_IOSCR_G4_IO3_Msk                          /*!<GROUP4_IO3 sampling mode */
#define TSC_IOSCR_G4_IO4_Pos     (15U)                                         
#define TSC_IOSCR_G4_IO4_Msk     (0x1U << TSC_IOSCR_G4_IO4_Pos)                /*!< 0x00008000 */
#define TSC_IOSCR_G4_IO4         TSC_IOSCR_G4_IO4_Msk                          /*!<GROUP4_IO4 sampling mode */
#define TSC_IOSCR_G5_IO1_Pos     (16U)                                         
#define TSC_IOSCR_G5_IO1_Msk     (0x1U << TSC_IOSCR_G5_IO1_Pos)                /*!< 0x00010000 */
#define TSC_IOSCR_G5_IO1         TSC_IOSCR_G5_IO1_Msk                          /*!<GROUP5_IO1 sampling mode */
#define TSC_IOSCR_G5_IO2_Pos     (17U)                                         
#define TSC_IOSCR_G5_IO2_Msk     (0x1U << TSC_IOSCR_G5_IO2_Pos)                /*!< 0x00020000 */
#define TSC_IOSCR_G5_IO2         TSC_IOSCR_G5_IO2_Msk                          /*!<GROUP5_IO2 sampling mode */
#define TSC_IOSCR_G5_IO3_Pos     (18U)                                         
#define TSC_IOSCR_G5_IO3_Msk     (0x1U << TSC_IOSCR_G5_IO3_Pos)                /*!< 0x00040000 */
#define TSC_IOSCR_G5_IO3         TSC_IOSCR_G5_IO3_Msk                          /*!<GROUP5_IO3 sampling mode */
#define TSC_IOSCR_G5_IO4_Pos     (19U)                                         
#define TSC_IOSCR_G5_IO4_Msk     (0x1U << TSC_IOSCR_G5_IO4_Pos)                /*!< 0x00080000 */
#define TSC_IOSCR_G5_IO4         TSC_IOSCR_G5_IO4_Msk                          /*!<GROUP5_IO4 sampling mode */
#define TSC_IOSCR_G6_IO1_Pos     (20U)                                         
#define TSC_IOSCR_G6_IO1_Msk     (0x1U << TSC_IOSCR_G6_IO1_Pos)                /*!< 0x00100000 */
#define TSC_IOSCR_G6_IO1         TSC_IOSCR_G6_IO1_Msk                          /*!<GROUP6_IO1 sampling mode */
#define TSC_IOSCR_G6_IO2_Pos     (21U)                                         
#define TSC_IOSCR_G6_IO2_Msk     (0x1U << TSC_IOSCR_G6_IO2_Pos)                /*!< 0x00200000 */
#define TSC_IOSCR_G6_IO2         TSC_IOSCR_G6_IO2_Msk                          /*!<GROUP6_IO2 sampling mode */
#define TSC_IOSCR_G6_IO3_Pos     (22U)                                         
#define TSC_IOSCR_G6_IO3_Msk     (0x1U << TSC_IOSCR_G6_IO3_Pos)                /*!< 0x00400000 */
#define TSC_IOSCR_G6_IO3         TSC_IOSCR_G6_IO3_Msk                          /*!<GROUP6_IO3 sampling mode */
#define TSC_IOSCR_G6_IO4_Pos     (23U)                                         
#define TSC_IOSCR_G6_IO4_Msk     (0x1U << TSC_IOSCR_G6_IO4_Pos)                /*!< 0x00800000 */
#define TSC_IOSCR_G6_IO4         TSC_IOSCR_G6_IO4_Msk                          /*!<GROUP6_IO4 sampling mode */
#define TSC_IOSCR_G7_IO1_Pos     (24U)                                         
#define TSC_IOSCR_G7_IO1_Msk     (0x1U << TSC_IOSCR_G7_IO1_Pos)                /*!< 0x01000000 */
#define TSC_IOSCR_G7_IO1         TSC_IOSCR_G7_IO1_Msk                          /*!<GROUP7_IO1 sampling mode */
#define TSC_IOSCR_G7_IO2_Pos     (25U)                                         
#define TSC_IOSCR_G7_IO2_Msk     (0x1U << TSC_IOSCR_G7_IO2_Pos)                /*!< 0x02000000 */
#define TSC_IOSCR_G7_IO2         TSC_IOSCR_G7_IO2_Msk                          /*!<GROUP7_IO2 sampling mode */
#define TSC_IOSCR_G7_IO3_Pos     (26U)                                         
#define TSC_IOSCR_G7_IO3_Msk     (0x1U << TSC_IOSCR_G7_IO3_Pos)                /*!< 0x04000000 */
#define TSC_IOSCR_G7_IO3         TSC_IOSCR_G7_IO3_Msk                          /*!<GROUP7_IO3 sampling mode */
#define TSC_IOSCR_G7_IO4_Pos     (27U)                                         
#define TSC_IOSCR_G7_IO4_Msk     (0x1U << TSC_IOSCR_G7_IO4_Pos)                /*!< 0x08000000 */
#define TSC_IOSCR_G7_IO4         TSC_IOSCR_G7_IO4_Msk                          /*!<GROUP7_IO4 sampling mode */
#define TSC_IOSCR_G8_IO1_Pos     (28U)                                         
#define TSC_IOSCR_G8_IO1_Msk     (0x1U << TSC_IOSCR_G8_IO1_Pos)                /*!< 0x10000000 */
#define TSC_IOSCR_G8_IO1         TSC_IOSCR_G8_IO1_Msk                          /*!<GROUP8_IO1 sampling mode */
#define TSC_IOSCR_G8_IO2_Pos     (29U)                                         
#define TSC_IOSCR_G8_IO2_Msk     (0x1U << TSC_IOSCR_G8_IO2_Pos)                /*!< 0x20000000 */
#define TSC_IOSCR_G8_IO2         TSC_IOSCR_G8_IO2_Msk                          /*!<GROUP8_IO2 sampling mode */
#define TSC_IOSCR_G8_IO3_Pos     (30U)                                         
#define TSC_IOSCR_G8_IO3_Msk     (0x1U << TSC_IOSCR_G8_IO3_Pos)                /*!< 0x40000000 */
#define TSC_IOSCR_G8_IO3         TSC_IOSCR_G8_IO3_Msk                          /*!<GROUP8_IO3 sampling mode */
#define TSC_IOSCR_G8_IO4_Pos     (31U)                                         
#define TSC_IOSCR_G8_IO4_Msk     (0x1U << TSC_IOSCR_G8_IO4_Pos)                /*!< 0x80000000 */
#define TSC_IOSCR_G8_IO4         TSC_IOSCR_G8_IO4_Msk                          /*!<GROUP8_IO4 sampling mode */

/*******************  Bit definition for TSC_IOCCR register  ******************/
#define TSC_IOCCR_G1_IO1_Pos     (0U)                                          
#define TSC_IOCCR_G1_IO1_Msk     (0x1U << TSC_IOCCR_G1_IO1_Pos)                /*!< 0x00000001 */
#define TSC_IOCCR_G1_IO1         TSC_IOCCR_G1_IO1_Msk                          /*!<GROUP1_IO1 channel mode */
#define TSC_IOCCR_G1_IO2_Pos     (1U)                                          
#define TSC_IOCCR_G1_IO2_Msk     (0x1U << TSC_IOCCR_G1_IO2_Pos)                /*!< 0x00000002 */
#define TSC_IOCCR_G1_IO2         TSC_IOCCR_G1_IO2_Msk                          /*!<GROUP1_IO2 channel mode */
#define TSC_IOCCR_G1_IO3_Pos     (2U)                                          
#define TSC_IOCCR_G1_IO3_Msk     (0x1U << TSC_IOCCR_G1_IO3_Pos)                /*!< 0x00000004 */
#define TSC_IOCCR_G1_IO3         TSC_IOCCR_G1_IO3_Msk                          /*!<GROUP1_IO3 channel mode */
#define TSC_IOCCR_G1_IO4_Pos     (3U)                                          
#define TSC_IOCCR_G1_IO4_Msk     (0x1U << TSC_IOCCR_G1_IO4_Pos)                /*!< 0x00000008 */
#define TSC_IOCCR_G1_IO4         TSC_IOCCR_G1_IO4_Msk                          /*!<GROUP1_IO4 channel mode */
#define TSC_IOCCR_G2_IO1_Pos     (4U)                                          
#define TSC_IOCCR_G2_IO1_Msk     (0x1U << TSC_IOCCR_G2_IO1_Pos)                /*!< 0x00000010 */
#define TSC_IOCCR_G2_IO1         TSC_IOCCR_G2_IO1_Msk                          /*!<GROUP2_IO1 channel mode */
#define TSC_IOCCR_G2_IO2_Pos     (5U)                                          
#define TSC_IOCCR_G2_IO2_Msk     (0x1U << TSC_IOCCR_G2_IO2_Pos)                /*!< 0x00000020 */
#define TSC_IOCCR_G2_IO2         TSC_IOCCR_G2_IO2_Msk                          /*!<GROUP2_IO2 channel mode */
#define TSC_IOCCR_G2_IO3_Pos     (6U)                                          
#define TSC_IOCCR_G2_IO3_Msk     (0x1U << TSC_IOCCR_G2_IO3_Pos)                /*!< 0x00000040 */
#define TSC_IOCCR_G2_IO3         TSC_IOCCR_G2_IO3_Msk                          /*!<GROUP2_IO3 channel mode */
#define TSC_IOCCR_G2_IO4_Pos     (7U)                                          
#define TSC_IOCCR_G2_IO4_Msk     (0x1U << TSC_IOCCR_G2_IO4_Pos)                /*!< 0x00000080 */
#define TSC_IOCCR_G2_IO4         TSC_IOCCR_G2_IO4_Msk                          /*!<GROUP2_IO4 channel mode */
#define TSC_IOCCR_G3_IO1_Pos     (8U)                                          
#define TSC_IOCCR_G3_IO1_Msk     (0x1U << TSC_IOCCR_G3_IO1_Pos)                /*!< 0x00000100 */
#define TSC_IOCCR_G3_IO1         TSC_IOCCR_G3_IO1_Msk                          /*!<GROUP3_IO1 channel mode */
#define TSC_IOCCR_G3_IO2_Pos     (9U)                                          
#define TSC_IOCCR_G3_IO2_Msk     (0x1U << TSC_IOCCR_G3_IO2_Pos)                /*!< 0x00000200 */
#define TSC_IOCCR_G3_IO2         TSC_IOCCR_G3_IO2_Msk                          /*!<GROUP3_IO2 channel mode */
#define TSC_IOCCR_G3_IO3_Pos     (10U)                                         
#define TSC_IOCCR_G3_IO3_Msk     (0x1U << TSC_IOCCR_G3_IO3_Pos)                /*!< 0x00000400 */
#define TSC_IOCCR_G3_IO3         TSC_IOCCR_G3_IO3_Msk                          /*!<GROUP3_IO3 channel mode */
#define TSC_IOCCR_G3_IO4_Pos     (11U)                                         
#define TSC_IOCCR_G3_IO4_Msk     (0x1U << TSC_IOCCR_G3_IO4_Pos)                /*!< 0x00000800 */
#define TSC_IOCCR_G3_IO4         TSC_IOCCR_G3_IO4_Msk                          /*!<GROUP3_IO4 channel mode */
#define TSC_IOCCR_G4_IO1_Pos     (12U)                                         
#define TSC_IOCCR_G4_IO1_Msk     (0x1U << TSC_IOCCR_G4_IO1_Pos)                /*!< 0x00001000 */
#define TSC_IOCCR_G4_IO1         TSC_IOCCR_G4_IO1_Msk                          /*!<GROUP4_IO1 channel mode */
#define TSC_IOCCR_G4_IO2_Pos     (13U)                                         
#define TSC_IOCCR_G4_IO2_Msk     (0x1U << TSC_IOCCR_G4_IO2_Pos)                /*!< 0x00002000 */
#define TSC_IOCCR_G4_IO2         TSC_IOCCR_G4_IO2_Msk                          /*!<GROUP4_IO2 channel mode */
#define TSC_IOCCR_G4_IO3_Pos     (14U)                                         
#define TSC_IOCCR_G4_IO3_Msk     (0x1U << TSC_IOCCR_G4_IO3_Pos)                /*!< 0x00004000 */
#define TSC_IOCCR_G4_IO3         TSC_IOCCR_G4_IO3_Msk                          /*!<GROUP4_IO3 channel mode */
#define TSC_IOCCR_G4_IO4_Pos     (15U)                                         
#define TSC_IOCCR_G4_IO4_Msk     (0x1U << TSC_IOCCR_G4_IO4_Pos)                /*!< 0x00008000 */
#define TSC_IOCCR_G4_IO4         TSC_IOCCR_G4_IO4_Msk                          /*!<GROUP4_IO4 channel mode */
#define TSC_IOCCR_G5_IO1_Pos     (16U)                                         
#define TSC_IOCCR_G5_IO1_Msk     (0x1U << TSC_IOCCR_G5_IO1_Pos)                /*!< 0x00010000 */
#define TSC_IOCCR_G5_IO1         TSC_IOCCR_G5_IO1_Msk                          /*!<GROUP5_IO1 channel mode */
#define TSC_IOCCR_G5_IO2_Pos     (17U)                                         
#define TSC_IOCCR_G5_IO2_Msk     (0x1U << TSC_IOCCR_G5_IO2_Pos)                /*!< 0x00020000 */
#define TSC_IOCCR_G5_IO2         TSC_IOCCR_G5_IO2_Msk                          /*!<GROUP5_IO2 channel mode */
#define TSC_IOCCR_G5_IO3_Pos     (18U)                                         
#define TSC_IOCCR_G5_IO3_Msk     (0x1U << TSC_IOCCR_G5_IO3_Pos)                /*!< 0x00040000 */
#define TSC_IOCCR_G5_IO3         TSC_IOCCR_G5_IO3_Msk                          /*!<GROUP5_IO3 channel mode */
#define TSC_IOCCR_G5_IO4_Pos     (19U)                                         
#define TSC_IOCCR_G5_IO4_Msk     (0x1U << TSC_IOCCR_G5_IO4_Pos)                /*!< 0x00080000 */
#define TSC_IOCCR_G5_IO4         TSC_IOCCR_G5_IO4_Msk                          /*!<GROUP5_IO4 channel mode */
#define TSC_IOCCR_G6_IO1_Pos     (20U)                                         
#define TSC_IOCCR_G6_IO1_Msk     (0x1U << TSC_IOCCR_G6_IO1_Pos)                /*!< 0x00100000 */
#define TSC_IOCCR_G6_IO1         TSC_IOCCR_G6_IO1_Msk                          /*!<GROUP6_IO1 channel mode */
#define TSC_IOCCR_G6_IO2_Pos     (21U)                                         
#define TSC_IOCCR_G6_IO2_Msk     (0x1U << TSC_IOCCR_G6_IO2_Pos)                /*!< 0x00200000 */
#define TSC_IOCCR_G6_IO2         TSC_IOCCR_G6_IO2_Msk                          /*!<GROUP6_IO2 channel mode */
#define TSC_IOCCR_G6_IO3_Pos     (22U)                                         
#define TSC_IOCCR_G6_IO3_Msk     (0x1U << TSC_IOCCR_G6_IO3_Pos)                /*!< 0x00400000 */
#define TSC_IOCCR_G6_IO3         TSC_IOCCR_G6_IO3_Msk                          /*!<GROUP6_IO3 channel mode */
#define TSC_IOCCR_G6_IO4_Pos     (23U)                                         
#define TSC_IOCCR_G6_IO4_Msk     (0x1U << TSC_IOCCR_G6_IO4_Pos)                /*!< 0x00800000 */
#define TSC_IOCCR_G6_IO4         TSC_IOCCR_G6_IO4_Msk                          /*!<GROUP6_IO4 channel mode */
#define TSC_IOCCR_G7_IO1_Pos     (24U)                                         
#define TSC_IOCCR_G7_IO1_Msk     (0x1U << TSC_IOCCR_G7_IO1_Pos)                /*!< 0x01000000 */
#define TSC_IOCCR_G7_IO1         TSC_IOCCR_G7_IO1_Msk                          /*!<GROUP7_IO1 channel mode */
#define TSC_IOCCR_G7_IO2_Pos     (25U)                                         
#define TSC_IOCCR_G7_IO2_Msk     (0x1U << TSC_IOCCR_G7_IO2_Pos)                /*!< 0x02000000 */
#define TSC_IOCCR_G7_IO2         TSC_IOCCR_G7_IO2_Msk                          /*!<GROUP7_IO2 channel mode */
#define TSC_IOCCR_G7_IO3_Pos     (26U)                                         
#define TSC_IOCCR_G7_IO3_Msk     (0x1U << TSC_IOCCR_G7_IO3_Pos)                /*!< 0x04000000 */
#define TSC_IOCCR_G7_IO3         TSC_IOCCR_G7_IO3_Msk                          /*!<GROUP7_IO3 channel mode */
#define TSC_IOCCR_G7_IO4_Pos     (27U)                                         
#define TSC_IOCCR_G7_IO4_Msk     (0x1U << TSC_IOCCR_G7_IO4_Pos)                /*!< 0x08000000 */
#define TSC_IOCCR_G7_IO4         TSC_IOCCR_G7_IO4_Msk                          /*!<GROUP7_IO4 channel mode */
#define TSC_IOCCR_G8_IO1_Pos     (28U)                                         
#define TSC_IOCCR_G8_IO1_Msk     (0x1U << TSC_IOCCR_G8_IO1_Pos)                /*!< 0x10000000 */
#define TSC_IOCCR_G8_IO1         TSC_IOCCR_G8_IO1_Msk                          /*!<GROUP8_IO1 channel mode */
#define TSC_IOCCR_G8_IO2_Pos     (29U)                                         
#define TSC_IOCCR_G8_IO2_Msk     (0x1U << TSC_IOCCR_G8_IO2_Pos)                /*!< 0x20000000 */
#define TSC_IOCCR_G8_IO2         TSC_IOCCR_G8_IO2_Msk                          /*!<GROUP8_IO2 channel mode */
#define TSC_IOCCR_G8_IO3_Pos     (30U)                                         
#define TSC_IOCCR_G8_IO3_Msk     (0x1U << TSC_IOCCR_G8_IO3_Pos)                /*!< 0x40000000 */
#define TSC_IOCCR_G8_IO3         TSC_IOCCR_G8_IO3_Msk                          /*!<GROUP8_IO3 channel mode */
#define TSC_IOCCR_G8_IO4_Pos     (31U)                                         
#define TSC_IOCCR_G8_IO4_Msk     (0x1U << TSC_IOCCR_G8_IO4_Pos)                /*!< 0x80000000 */
#define TSC_IOCCR_G8_IO4         TSC_IOCCR_G8_IO4_Msk                          /*!<GROUP8_IO4 channel mode */

/*******************  Bit definition for TSC_IOGCSR register  *****************/
#define TSC_IOGCSR_G1E_Pos       (0U)                                          
#define TSC_IOGCSR_G1E_Msk       (0x1U << TSC_IOGCSR_G1E_Pos)                  /*!< 0x00000001 */
#define TSC_IOGCSR_G1E           TSC_IOGCSR_G1E_Msk                            /*!<Analog IO GROUP1 enable */
#define TSC_IOGCSR_G2E_Pos       (1U)                                          
#define TSC_IOGCSR_G2E_Msk       (0x1U << TSC_IOGCSR_G2E_Pos)                  /*!< 0x00000002 */
#define TSC_IOGCSR_G2E           TSC_IOGCSR_G2E_Msk                            /*!<Analog IO GROUP2 enable */
#define TSC_IOGCSR_G3E_Pos       (2U)                                          
#define TSC_IOGCSR_G3E_Msk       (0x1U << TSC_IOGCSR_G3E_Pos)                  /*!< 0x00000004 */
#define TSC_IOGCSR_G3E           TSC_IOGCSR_G3E_Msk                            /*!<Analog IO GROUP3 enable */
#define TSC_IOGCSR_G4E_Pos       (3U)                                          
#define TSC_IOGCSR_G4E_Msk       (0x1U << TSC_IOGCSR_G4E_Pos)                  /*!< 0x00000008 */
#define TSC_IOGCSR_G4E           TSC_IOGCSR_G4E_Msk                            /*!<Analog IO GROUP4 enable */
#define TSC_IOGCSR_G5E_Pos       (4U)                                          
#define TSC_IOGCSR_G5E_Msk       (0x1U << TSC_IOGCSR_G5E_Pos)                  /*!< 0x00000010 */
#define TSC_IOGCSR_G5E           TSC_IOGCSR_G5E_Msk                            /*!<Analog IO GROUP5 enable */
#define TSC_IOGCSR_G6E_Pos       (5U)                                          
#define TSC_IOGCSR_G6E_Msk       (0x1U << TSC_IOGCSR_G6E_Pos)                  /*!< 0x00000020 */
#define TSC_IOGCSR_G6E           TSC_IOGCSR_G6E_Msk                            /*!<Analog IO GROUP6 enable */
#define TSC_IOGCSR_G7E_Pos       (6U)                                          
#define TSC_IOGCSR_G7E_Msk       (0x1U << TSC_IOGCSR_G7E_Pos)                  /*!< 0x00000040 */
#define TSC_IOGCSR_G7E           TSC_IOGCSR_G7E_Msk                            /*!<Analog IO GROUP7 enable */
#define TSC_IOGCSR_G8E_Pos       (7U)                                          
#define TSC_IOGCSR_G8E_Msk       (0x1U << TSC_IOGCSR_G8E_Pos)                  /*!< 0x00000080 */
#define TSC_IOGCSR_G8E           TSC_IOGCSR_G8E_Msk                            /*!<Analog IO GROUP8 enable */
#define TSC_IOGCSR_G1S_Pos       (16U)                                         
#define TSC_IOGCSR_G1S_Msk       (0x1U << TSC_IOGCSR_G1S_Pos)                  /*!< 0x00010000 */
#define TSC_IOGCSR_G1S           TSC_IOGCSR_G1S_Msk                            /*!<Analog IO GROUP1 status */
#define TSC_IOGCSR_G2S_Pos       (17U)                                         
#define TSC_IOGCSR_G2S_Msk       (0x1U << TSC_IOGCSR_G2S_Pos)                  /*!< 0x00020000 */
#define TSC_IOGCSR_G2S           TSC_IOGCSR_G2S_Msk                            /*!<Analog IO GROUP2 status */
#define TSC_IOGCSR_G3S_Pos       (18U)                                         
#define TSC_IOGCSR_G3S_Msk       (0x1U << TSC_IOGCSR_G3S_Pos)                  /*!< 0x00040000 */
#define TSC_IOGCSR_G3S           TSC_IOGCSR_G3S_Msk                            /*!<Analog IO GROUP3 status */
#define TSC_IOGCSR_G4S_Pos       (19U)                                         
#define TSC_IOGCSR_G4S_Msk       (0x1U << TSC_IOGCSR_G4S_Pos)                  /*!< 0x00080000 */
#define TSC_IOGCSR_G4S           TSC_IOGCSR_G4S_Msk                            /*!<Analog IO GROUP4 status */
#define TSC_IOGCSR_G5S_Pos       (20U)                                         
#define TSC_IOGCSR_G5S_Msk       (0x1U << TSC_IOGCSR_G5S_Pos)                  /*!< 0x00100000 */
#define TSC_IOGCSR_G5S           TSC_IOGCSR_G5S_Msk                            /*!<Analog IO GROUP5 status */
#define TSC_IOGCSR_G6S_Pos       (21U)                                         
#define TSC_IOGCSR_G6S_Msk       (0x1U << TSC_IOGCSR_G6S_Pos)                  /*!< 0x00200000 */
#define TSC_IOGCSR_G6S           TSC_IOGCSR_G6S_Msk                            /*!<Analog IO GROUP6 status */
#define TSC_IOGCSR_G7S_Pos       (22U)                                         
#define TSC_IOGCSR_G7S_Msk       (0x1U << TSC_IOGCSR_G7S_Pos)                  /*!< 0x00400000 */
#define TSC_IOGCSR_G7S           TSC_IOGCSR_G7S_Msk                            /*!<Analog IO GROUP7 status */
#define TSC_IOGCSR_G8S_Pos       (23U)                                         
#define TSC_IOGCSR_G8S_Msk       (0x1U << TSC_IOGCSR_G8S_Pos)                  /*!< 0x00800000 */
#define TSC_IOGCSR_G8S           TSC_IOGCSR_G8S_Msk                            /*!<Analog IO GROUP8 status */

/*******************  Bit definition for TSC_IOGXCR register  *****************/
#define TSC_IOGXCR_CNT_Pos       (0U)                                          
#define TSC_IOGXCR_CNT_Msk       (0x3FFFU << TSC_IOGXCR_CNT_Pos)               /*!< 0x00003FFF */
#define TSC_IOGXCR_CNT           TSC_IOGXCR_CNT_Msk                            /*!<CNT[13:0] bits (Counter value) */

/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/

/*
* @brief Specific device feature definitions (not present on all devices in the STM32F0 serie)
*/

/* Support of 7 bits data length feature */
#define USART_7BITS_SUPPORT

/* Support of LIN feature */
#define USART_LIN_SUPPORT

/* Support of Smartcard feature */
#define USART_SMARTCARD_SUPPORT

/* Support of Irda feature */
#define USART_IRDA_SUPPORT

/* Support of Wake Up from Stop Mode feature */
#define USART_WUSM_SUPPORT

/* Support of Full Auto Baud rate feature (4 modes) activation */
#define USART_FABR_SUPPORT

/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_UE_Pos              (0U)                                     
#define USART_CR1_UE_Msk              (0x1U << USART_CR1_UE_Pos)               /*!< 0x00000001 */
#define USART_CR1_UE                  USART_CR1_UE_Msk                         /*!< USART Enable */
#define USART_CR1_UESM_Pos            (1U)                                     
#define USART_CR1_UESM_Msk            (0x1U << USART_CR1_UESM_Pos)             /*!< 0x00000002 */
#define USART_CR1_UESM                USART_CR1_UESM_Msk                       /*!< USART Enable in STOP Mode */
#define USART_CR1_RE_Pos              (2U)                                     
#define USART_CR1_RE_Msk              (0x1U << USART_CR1_RE_Pos)               /*!< 0x00000004 */
#define USART_CR1_RE                  USART_CR1_RE_Msk                         /*!< Receiver Enable */
#define USART_CR1_TE_Pos              (3U)                                     
#define USART_CR1_TE_Msk              (0x1U << USART_CR1_TE_Pos)               /*!< 0x00000008 */
#define USART_CR1_TE                  USART_CR1_TE_Msk                         /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos          (4U)                                     
#define USART_CR1_IDLEIE_Msk          (0x1U << USART_CR1_IDLEIE_Pos)           /*!< 0x00000010 */
#define USART_CR1_IDLEIE              USART_CR1_IDLEIE_Msk                     /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos          (5U)                                     
#define USART_CR1_RXNEIE_Msk          (0x1U << USART_CR1_RXNEIE_Pos)           /*!< 0x00000020 */
#define USART_CR1_RXNEIE              USART_CR1_RXNEIE_Msk                     /*!< RXNE Interrupt Enable */
#define USART_CR1_TCIE_Pos            (6U)                                     
#define USART_CR1_TCIE_Msk            (0x1U << USART_CR1_TCIE_Pos)             /*!< 0x00000040 */
#define USART_CR1_TCIE                USART_CR1_TCIE_Msk                       /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos           (7U)                                     
#define USART_CR1_TXEIE_Msk           (0x1U << USART_CR1_TXEIE_Pos)            /*!< 0x00000080 */
#define USART_CR1_TXEIE               USART_CR1_TXEIE_Msk                      /*!< TXE Interrupt Enable */
#define USART_CR1_PEIE_Pos            (8U)                                     
#define USART_CR1_PEIE_Msk            (0x1U << USART_CR1_PEIE_Pos)             /*!< 0x00000100 */
#define USART_CR1_PEIE                USART_CR1_PEIE_Msk                       /*!< PE Interrupt Enable */
#define USART_CR1_PS_Pos              (9U)                                     
#define USART_CR1_PS_Msk              (0x1U << USART_CR1_PS_Pos)               /*!< 0x00000200 */
#define USART_CR1_PS                  USART_CR1_PS_Msk                         /*!< Parity Selection */
#define USART_CR1_PCE_Pos             (10U)                                    
#define USART_CR1_PCE_Msk             (0x1U << USART_CR1_PCE_Pos)              /*!< 0x00000400 */
#define USART_CR1_PCE                 USART_CR1_PCE_Msk                        /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos            (11U)                                    
#define USART_CR1_WAKE_Msk            (0x1U << USART_CR1_WAKE_Pos)             /*!< 0x00000800 */
#define USART_CR1_WAKE                USART_CR1_WAKE_Msk                       /*!< Receiver Wakeup method */
#define USART_CR1_M_Pos               (12U)                                    
#define USART_CR1_M_Msk               (0x10001U << USART_CR1_M_Pos)            /*!< 0x10001000 */
#define USART_CR1_M                   USART_CR1_M_Msk                          /*!< [M1:M0] Word length */
#define USART_CR1_M0_Pos              (12U)                                    
#define USART_CR1_M0_Msk              (0x1U << USART_CR1_M0_Pos)               /*!< 0x00001000 */
#define USART_CR1_M0                  USART_CR1_M0_Msk                         /*!< Word length bit 0 */
#define USART_CR1_MME_Pos             (13U)                                    
#define USART_CR1_MME_Msk             (0x1U << USART_CR1_MME_Pos)              /*!< 0x00002000 */
#define USART_CR1_MME                 USART_CR1_MME_Msk                        /*!< Mute Mode Enable */
#define USART_CR1_CMIE_Pos            (14U)                                    
#define USART_CR1_CMIE_Msk            (0x1U << USART_CR1_CMIE_Pos)             /*!< 0x00004000 */
#define USART_CR1_CMIE                USART_CR1_CMIE_Msk                       /*!< Character match interrupt enable */
#define USART_CR1_OVER8_Pos           (15U)                                    
#define USART_CR1_OVER8_Msk           (0x1U << USART_CR1_OVER8_Pos)            /*!< 0x00008000 */
#define USART_CR1_OVER8               USART_CR1_OVER8_Msk                      /*!< Oversampling by 8-bit or 16-bit mode */
#define USART_CR1_DEDT_Pos            (16U)                                    
#define USART_CR1_DEDT_Msk            (0x1FU << USART_CR1_DEDT_Pos)            /*!< 0x001F0000 */
#define USART_CR1_DEDT                USART_CR1_DEDT_Msk                       /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define USART_CR1_DEDT_0              (0x01U << USART_CR1_DEDT_Pos)            /*!< 0x00010000 */
#define USART_CR1_DEDT_1              (0x02U << USART_CR1_DEDT_Pos)            /*!< 0x00020000 */
#define USART_CR1_DEDT_2              (0x04U << USART_CR1_DEDT_Pos)            /*!< 0x00040000 */
#define USART_CR1_DEDT_3              (0x08U << USART_CR1_DEDT_Pos)            /*!< 0x00080000 */
#define USART_CR1_DEDT_4              (0x10U << USART_CR1_DEDT_Pos)            /*!< 0x00100000 */
#define USART_CR1_DEAT_Pos            (21U)                                    
#define USART_CR1_DEAT_Msk            (0x1FU << USART_CR1_DEAT_Pos)            /*!< 0x03E00000 */
#define USART_CR1_DEAT                USART_CR1_DEAT_Msk                       /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define USART_CR1_DEAT_0              (0x01U << USART_CR1_DEAT_Pos)            /*!< 0x00200000 */
#define USART_CR1_DEAT_1              (0x02U << USART_CR1_DEAT_Pos)            /*!< 0x00400000 */
#define USART_CR1_DEAT_2              (0x04U << USART_CR1_DEAT_Pos)            /*!< 0x00800000 */
#define USART_CR1_DEAT_3              (0x08U << USART_CR1_DEAT_Pos)            /*!< 0x01000000 */
#define USART_CR1_DEAT_4              (0x10U << USART_CR1_DEAT_Pos)            /*!< 0x02000000 */
#define USART_CR1_RTOIE_Pos           (26U)                                    
#define USART_CR1_RTOIE_Msk           (0x1U << USART_CR1_RTOIE_Pos)            /*!< 0x04000000 */
#define USART_CR1_RTOIE               USART_CR1_RTOIE_Msk                      /*!< Receive Time Out interrupt enable */
#define USART_CR1_EOBIE_Pos           (27U)                                    
#define USART_CR1_EOBIE_Msk           (0x1U << USART_CR1_EOBIE_Pos)            /*!< 0x08000000 */
#define USART_CR1_EOBIE               USART_CR1_EOBIE_Msk                      /*!< End of Block interrupt enable */
#define USART_CR1_M1_Pos              (28U)                                    
#define USART_CR1_M1_Msk              (0x1U << USART_CR1_M1_Pos)               /*!< 0x10000000 */
#define USART_CR1_M1                  USART_CR1_M1_Msk                         /*!< Word length bit 1 */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_ADDM7_Pos           (4U)                                     
#define USART_CR2_ADDM7_Msk           (0x1U << USART_CR2_ADDM7_Pos)            /*!< 0x00000010 */
#define USART_CR2_ADDM7               USART_CR2_ADDM7_Msk                      /*!< 7-bit or 4-bit Address Detection */
#define USART_CR2_LBDL_Pos            (5U)                                     
#define USART_CR2_LBDL_Msk            (0x1U << USART_CR2_LBDL_Pos)             /*!< 0x00000020 */
#define USART_CR2_LBDL                USART_CR2_LBDL_Msk                       /*!< LIN Break Detection Length */
#define USART_CR2_LBDIE_Pos           (6U)                                     
#define USART_CR2_LBDIE_Msk           (0x1U << USART_CR2_LBDIE_Pos)            /*!< 0x00000040 */
#define USART_CR2_LBDIE               USART_CR2_LBDIE_Msk                      /*!< LIN Break Detection Interrupt Enable */
#define USART_CR2_LBCL_Pos            (8U)                                     
#define USART_CR2_LBCL_Msk            (0x1U << USART_CR2_LBCL_Pos)             /*!< 0x00000100 */
#define USART_CR2_LBCL                USART_CR2_LBCL_Msk                       /*!< Last Bit Clock pulse */
#define USART_CR2_CPHA_Pos            (9U)                                     
#define USART_CR2_CPHA_Msk            (0x1U << USART_CR2_CPHA_Pos)             /*!< 0x00000200 */
#define USART_CR2_CPHA                USART_CR2_CPHA_Msk                       /*!< Clock Phase */
#define USART_CR2_CPOL_Pos            (10U)                                    
#define USART_CR2_CPOL_Msk            (0x1U << USART_CR2_CPOL_Pos)             /*!< 0x00000400 */
#define USART_CR2_CPOL                USART_CR2_CPOL_Msk                       /*!< Clock Polarity */
#define USART_CR2_CLKEN_Pos           (11U)                                    
#define USART_CR2_CLKEN_Msk           (0x1U << USART_CR2_CLKEN_Pos)            /*!< 0x00000800 */
#define USART_CR2_CLKEN               USART_CR2_CLKEN_Msk                      /*!< Clock Enable */
#define USART_CR2_STOP_Pos            (12U)                                    
#define USART_CR2_STOP_Msk            (0x3U << USART_CR2_STOP_Pos)             /*!< 0x00003000 */
#define USART_CR2_STOP                USART_CR2_STOP_Msk                       /*!< STOP[1:0] bits (STOP bits) */
#define USART_CR2_STOP_0              (0x1U << USART_CR2_STOP_Pos)             /*!< 0x00001000 */
#define USART_CR2_STOP_1              (0x2U << USART_CR2_STOP_Pos)             /*!< 0x00002000 */
#define USART_CR2_LINEN_Pos           (14U)                                    
#define USART_CR2_LINEN_Msk           (0x1U << USART_CR2_LINEN_Pos)            /*!< 0x00004000 */
#define USART_CR2_LINEN               USART_CR2_LINEN_Msk                      /*!< LIN mode enable */
#define USART_CR2_SWAP_Pos            (15U)                                    
#define USART_CR2_SWAP_Msk            (0x1U << USART_CR2_SWAP_Pos)             /*!< 0x00008000 */
#define USART_CR2_SWAP                USART_CR2_SWAP_Msk                       /*!< SWAP TX/RX pins */
#define USART_CR2_RXINV_Pos           (16U)                                    
#define USART_CR2_RXINV_Msk           (0x1U << USART_CR2_RXINV_Pos)            /*!< 0x00010000 */
#define USART_CR2_RXINV               USART_CR2_RXINV_Msk                      /*!< RX pin active level inversion */
#define USART_CR2_TXINV_Pos           (17U)                                    
#define USART_CR2_TXINV_Msk           (0x1U << USART_CR2_TXINV_Pos)            /*!< 0x00020000 */
#define USART_CR2_TXINV               USART_CR2_TXINV_Msk                      /*!< TX pin active level inversion */
#define USART_CR2_DATAINV_Pos         (18U)                                    
#define USART_CR2_DATAINV_Msk         (0x1U << USART_CR2_DATAINV_Pos)          /*!< 0x00040000 */
#define USART_CR2_DATAINV             USART_CR2_DATAINV_Msk                    /*!< Binary data inversion */
#define USART_CR2_MSBFIRST_Pos        (19U)                                    
#define USART_CR2_MSBFIRST_Msk        (0x1U << USART_CR2_MSBFIRST_Pos)         /*!< 0x00080000 */
#define USART_CR2_MSBFIRST            USART_CR2_MSBFIRST_Msk                   /*!< Most Significant Bit First */
#define USART_CR2_ABREN_Pos           (20U)                                    
#define USART_CR2_ABREN_Msk           (0x1U << USART_CR2_ABREN_Pos)            /*!< 0x00100000 */
#define USART_CR2_ABREN               USART_CR2_ABREN_Msk                      /*!< Auto Baud-Rate Enable*/
#define USART_CR2_ABRMODE_Pos         (21U)                                    
#define USART_CR2_ABRMODE_Msk         (0x3U << USART_CR2_ABRMODE_Pos)          /*!< 0x00600000 */
#define USART_CR2_ABRMODE             USART_CR2_ABRMODE_Msk                    /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define USART_CR2_ABRMODE_0           (0x1U << USART_CR2_ABRMODE_Pos)          /*!< 0x00200000 */
#define USART_CR2_ABRMODE_1           (0x2U << USART_CR2_ABRMODE_Pos)          /*!< 0x00400000 */
#define USART_CR2_RTOEN_Pos           (23U)                                    
#define USART_CR2_RTOEN_Msk           (0x1U << USART_CR2_RTOEN_Pos)            /*!< 0x00800000 */
#define USART_CR2_RTOEN               USART_CR2_RTOEN_Msk                      /*!< Receiver Time-Out enable */
#define USART_CR2_ADD_Pos             (24U)                                    
#define USART_CR2_ADD_Msk             (0xFFU << USART_CR2_ADD_Pos)             /*!< 0xFF000000 */
#define USART_CR2_ADD                 USART_CR2_ADD_Msk                        /*!< Address of the USART node */

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos             (0U)                                     
#define USART_CR3_EIE_Msk             (0x1U << USART_CR3_EIE_Pos)              /*!< 0x00000001 */
#define USART_CR3_EIE                 USART_CR3_EIE_Msk                        /*!< Error Interrupt Enable */
#define USART_CR3_IREN_Pos            (1U)                                     
#define USART_CR3_IREN_Msk            (0x1U << USART_CR3_IREN_Pos)             /*!< 0x00000002 */
#define USART_CR3_IREN                USART_CR3_IREN_Msk                       /*!< IrDA mode Enable */
#define USART_CR3_IRLP_Pos            (2U)                                     
#define USART_CR3_IRLP_Msk            (0x1U << USART_CR3_IRLP_Pos)             /*!< 0x00000004 */
#define USART_CR3_IRLP                USART_CR3_IRLP_Msk                       /*!< IrDA Low-Power */
#define USART_CR3_HDSEL_Pos           (3U)                                     
#define USART_CR3_HDSEL_Msk           (0x1U << USART_CR3_HDSEL_Pos)            /*!< 0x00000008 */
#define USART_CR3_HDSEL               USART_CR3_HDSEL_Msk                      /*!< Half-Duplex Selection */
#define USART_CR3_NACK_Pos            (4U)                                     
#define USART_CR3_NACK_Msk            (0x1U << USART_CR3_NACK_Pos)             /*!< 0x00000010 */
#define USART_CR3_NACK                USART_CR3_NACK_Msk                       /*!< SmartCard NACK enable */
#define USART_CR3_SCEN_Pos            (5U)                                     
#define USART_CR3_SCEN_Msk            (0x1U << USART_CR3_SCEN_Pos)             /*!< 0x00000020 */
#define USART_CR3_SCEN                USART_CR3_SCEN_Msk                       /*!< SmartCard mode enable */
#define USART_CR3_DMAR_Pos            (6U)                                     
#define USART_CR3_DMAR_Msk            (0x1U << USART_CR3_DMAR_Pos)             /*!< 0x00000040 */
#define USART_CR3_DMAR                USART_CR3_DMAR_Msk                       /*!< DMA Enable Receiver */
#define USART_CR3_DMAT_Pos            (7U)                                     
#define USART_CR3_DMAT_Msk            (0x1U << USART_CR3_DMAT_Pos)             /*!< 0x00000080 */
#define USART_CR3_DMAT                USART_CR3_DMAT_Msk                       /*!< DMA Enable Transmitter */
#define USART_CR3_RTSE_Pos            (8U)                                     
#define USART_CR3_RTSE_Msk            (0x1U << USART_CR3_RTSE_Pos)             /*!< 0x00000100 */
#define USART_CR3_RTSE                USART_CR3_RTSE_Msk                       /*!< RTS Enable */
#define USART_CR3_CTSE_Pos            (9U)                                     
#define USART_CR3_CTSE_Msk            (0x1U << USART_CR3_CTSE_Pos)             /*!< 0x00000200 */
#define USART_CR3_CTSE                USART_CR3_CTSE_Msk                       /*!< CTS Enable */
#define USART_CR3_CTSIE_Pos           (10U)                                    
#define USART_CR3_CTSIE_Msk           (0x1U << USART_CR3_CTSIE_Pos)            /*!< 0x00000400 */
#define USART_CR3_CTSIE               USART_CR3_CTSIE_Msk                      /*!< CTS Interrupt Enable */
#define USART_CR3_ONEBIT_Pos          (11U)                                    
#define USART_CR3_ONEBIT_Msk          (0x1U << USART_CR3_ONEBIT_Pos)           /*!< 0x00000800 */
#define USART_CR3_ONEBIT              USART_CR3_ONEBIT_Msk                     /*!< One sample bit method enable */
#define USART_CR3_OVRDIS_Pos          (12U)                                    
#define USART_CR3_OVRDIS_Msk          (0x1U << USART_CR3_OVRDIS_Pos)           /*!< 0x00001000 */
#define USART_CR3_OVRDIS              USART_CR3_OVRDIS_Msk                     /*!< Overrun Disable */
#define USART_CR3_DDRE_Pos            (13U)                                    
#define USART_CR3_DDRE_Msk            (0x1U << USART_CR3_DDRE_Pos)             /*!< 0x00002000 */
#define USART_CR3_DDRE                USART_CR3_DDRE_Msk                       /*!< DMA Disable on Reception Error */
#define USART_CR3_DEM_Pos             (14U)                                    
#define USART_CR3_DEM_Msk             (0x1U << USART_CR3_DEM_Pos)              /*!< 0x00004000 */
#define USART_CR3_DEM                 USART_CR3_DEM_Msk                        /*!< Driver Enable Mode */
#define USART_CR3_DEP_Pos             (15U)                                    
#define USART_CR3_DEP_Msk             (0x1U << USART_CR3_DEP_Pos)              /*!< 0x00008000 */
#define USART_CR3_DEP                 USART_CR3_DEP_Msk                        /*!< Driver Enable Polarity Selection */
#define USART_CR3_SCARCNT_Pos         (17U)                                    
#define USART_CR3_SCARCNT_Msk         (0x7U << USART_CR3_SCARCNT_Pos)          /*!< 0x000E0000 */
#define USART_CR3_SCARCNT             USART_CR3_SCARCNT_Msk                    /*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define USART_CR3_SCARCNT_0           (0x1U << USART_CR3_SCARCNT_Pos)          /*!< 0x00020000 */
#define USART_CR3_SCARCNT_1           (0x2U << USART_CR3_SCARCNT_Pos)          /*!< 0x00040000 */
#define USART_CR3_SCARCNT_2           (0x4U << USART_CR3_SCARCNT_Pos)          /*!< 0x00080000 */
#define USART_CR3_WUS_Pos             (20U)                                    
#define USART_CR3_WUS_Msk             (0x3U << USART_CR3_WUS_Pos)              /*!< 0x00300000 */
#define USART_CR3_WUS                 USART_CR3_WUS_Msk                        /*!< WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
#define USART_CR3_WUS_0               (0x1U << USART_CR3_WUS_Pos)              /*!< 0x00100000 */
#define USART_CR3_WUS_1               (0x2U << USART_CR3_WUS_Pos)              /*!< 0x00200000 */
#define USART_CR3_WUFIE_Pos           (22U)                                    
#define USART_CR3_WUFIE_Msk           (0x1U << USART_CR3_WUFIE_Pos)            /*!< 0x00400000 */
#define USART_CR3_WUFIE               USART_CR3_WUFIE_Msk                      /*!< Wake Up Interrupt Enable */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_FRACTION_Pos    (0U)                                     
#define USART_BRR_DIV_FRACTION_Msk    (0xFU << USART_BRR_DIV_FRACTION_Pos)     /*!< 0x0000000F */
#define USART_BRR_DIV_FRACTION        USART_BRR_DIV_FRACTION_Msk               /*!< Fraction of USARTDIV */
#define USART_BRR_DIV_MANTISSA_Pos    (4U)                                     
#define USART_BRR_DIV_MANTISSA_Msk    (0xFFFU << USART_BRR_DIV_MANTISSA_Pos)   /*!< 0x0000FFF0 */
#define USART_BRR_DIV_MANTISSA        USART_BRR_DIV_MANTISSA_Msk               /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC_Pos            (0U)                                     
#define USART_GTPR_PSC_Msk            (0xFFU << USART_GTPR_PSC_Pos)            /*!< 0x000000FF */
#define USART_GTPR_PSC                USART_GTPR_PSC_Msk                       /*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_GT_Pos             (8U)                                     
#define USART_GTPR_GT_Msk             (0xFFU << USART_GTPR_GT_Pos)             /*!< 0x0000FF00 */
#define USART_GTPR_GT                 USART_GTPR_GT_Msk                        /*!< GT[7:0] bits (Guard time value) */


/*******************  Bit definition for USART_RTOR register  *****************/
#define USART_RTOR_RTO_Pos            (0U)                                     
#define USART_RTOR_RTO_Msk            (0xFFFFFFU << USART_RTOR_RTO_Pos)        /*!< 0x00FFFFFF */
#define USART_RTOR_RTO                USART_RTOR_RTO_Msk                       /*!< Receiver Time Out Value */
#define USART_RTOR_BLEN_Pos           (24U)                                    
#define USART_RTOR_BLEN_Msk           (0xFFU << USART_RTOR_BLEN_Pos)           /*!< 0xFF000000 */
#define USART_RTOR_BLEN               USART_RTOR_BLEN_Msk                      /*!< Block Length */

/*******************  Bit definition for USART_RQR register  ******************/
#define USART_RQR_ABRRQ_Pos           (0U)                                     
#define USART_RQR_ABRRQ_Msk           (0x1U << USART_RQR_ABRRQ_Pos)            /*!< 0x00000001 */
#define USART_RQR_ABRRQ               USART_RQR_ABRRQ_Msk                      /*!< Auto-Baud Rate Request */
#define USART_RQR_SBKRQ_Pos           (1U)                                     
#define USART_RQR_SBKRQ_Msk           (0x1U << USART_RQR_SBKRQ_Pos)            /*!< 0x00000002 */
#define USART_RQR_SBKRQ               USART_RQR_SBKRQ_Msk                      /*!< Send Break Request */
#define USART_RQR_MMRQ_Pos            (2U)                                     
#define USART_RQR_MMRQ_Msk            (0x1U << USART_RQR_MMRQ_Pos)             /*!< 0x00000004 */
#define USART_RQR_MMRQ                USART_RQR_MMRQ_Msk                       /*!< Mute Mode Request */
#define USART_RQR_RXFRQ_Pos           (3U)                                     
#define USART_RQR_RXFRQ_Msk           (0x1U << USART_RQR_RXFRQ_Pos)            /*!< 0x00000008 */
#define USART_RQR_RXFRQ               USART_RQR_RXFRQ_Msk                      /*!< Receive Data flush Request */
#define USART_RQR_TXFRQ_Pos           (4U)                                     
#define USART_RQR_TXFRQ_Msk           (0x1U << USART_RQR_TXFRQ_Pos)            /*!< 0x00000010 */
#define USART_RQR_TXFRQ               USART_RQR_TXFRQ_Msk                      /*!< Transmit data flush Request */

/*******************  Bit definition for USART_ISR register  ******************/
#define USART_ISR_PE_Pos              (0U)                                     
#define USART_ISR_PE_Msk              (0x1U << USART_ISR_PE_Pos)               /*!< 0x00000001 */
#define USART_ISR_PE                  USART_ISR_PE_Msk                         /*!< Parity Error */
#define USART_ISR_FE_Pos              (1U)                                     
#define USART_ISR_FE_Msk              (0x1U << USART_ISR_FE_Pos)               /*!< 0x00000002 */
#define USART_ISR_FE                  USART_ISR_FE_Msk                         /*!< Framing Error */
#define USART_ISR_NE_Pos              (2U)                                     
#define USART_ISR_NE_Msk              (0x1U << USART_ISR_NE_Pos)               /*!< 0x00000004 */
#define USART_ISR_NE                  USART_ISR_NE_Msk                         /*!< Noise detected Flag */
#define USART_ISR_ORE_Pos             (3U)                                     
#define USART_ISR_ORE_Msk             (0x1U << USART_ISR_ORE_Pos)              /*!< 0x00000008 */
#define USART_ISR_ORE                 USART_ISR_ORE_Msk                        /*!< OverRun Error */
#define USART_ISR_IDLE_Pos            (4U)                                     
#define USART_ISR_IDLE_Msk            (0x1U << USART_ISR_IDLE_Pos)             /*!< 0x00000010 */
#define USART_ISR_IDLE                USART_ISR_IDLE_Msk                       /*!< IDLE line detected */
#define USART_ISR_RXNE_Pos            (5U)                                     
#define USART_ISR_RXNE_Msk            (0x1U << USART_ISR_RXNE_Pos)             /*!< 0x00000020 */
#define USART_ISR_RXNE                USART_ISR_RXNE_Msk                       /*!< Read Data Register Not Empty */
#define USART_ISR_TC_Pos              (6U)                                     
#define USART_ISR_TC_Msk              (0x1U << USART_ISR_TC_Pos)               /*!< 0x00000040 */
#define USART_ISR_TC                  USART_ISR_TC_Msk                         /*!< Transmission Complete */
#define USART_ISR_TXE_Pos             (7U)                                     
#define USART_ISR_TXE_Msk             (0x1U << USART_ISR_TXE_Pos)              /*!< 0x00000080 */
#define USART_ISR_TXE                 USART_ISR_TXE_Msk                        /*!< Transmit Data Register Empty */
#define USART_ISR_LBDF_Pos            (8U)                                     
#define USART_ISR_LBDF_Msk            (0x1U << USART_ISR_LBDF_Pos)             /*!< 0x00000100 */
#define USART_ISR_LBDF                USART_ISR_LBDF_Msk                       /*!< LIN Break Detection Flag */
#define USART_ISR_CTSIF_Pos           (9U)                                     
#define USART_ISR_CTSIF_Msk           (0x1U << USART_ISR_CTSIF_Pos)            /*!< 0x00000200 */
#define USART_ISR_CTSIF               USART_ISR_CTSIF_Msk                      /*!< CTS interrupt flag */
#define USART_ISR_CTS_Pos             (10U)                                    
#define USART_ISR_CTS_Msk             (0x1U << USART_ISR_CTS_Pos)              /*!< 0x00000400 */
#define USART_ISR_CTS                 USART_ISR_CTS_Msk                        /*!< CTS flag */
#define USART_ISR_RTOF_Pos            (11U)                                    
#define USART_ISR_RTOF_Msk            (0x1U << USART_ISR_RTOF_Pos)             /*!< 0x00000800 */
#define USART_ISR_RTOF                USART_ISR_RTOF_Msk                       /*!< Receiver Time Out */
#define USART_ISR_EOBF_Pos            (12U)                                    
#define USART_ISR_EOBF_Msk            (0x1U << USART_ISR_EOBF_Pos)             /*!< 0x00001000 */
#define USART_ISR_EOBF                USART_ISR_EOBF_Msk                       /*!< End Of Block Flag */
#define USART_ISR_ABRE_Pos            (14U)                                    
#define USART_ISR_ABRE_Msk            (0x1U << USART_ISR_ABRE_Pos)             /*!< 0x00004000 */
#define USART_ISR_ABRE                USART_ISR_ABRE_Msk                       /*!< Auto-Baud Rate Error */
#define USART_ISR_ABRF_Pos            (15U)                                    
#define USART_ISR_ABRF_Msk            (0x1U << USART_ISR_ABRF_Pos)             /*!< 0x00008000 */
#define USART_ISR_ABRF                USART_ISR_ABRF_Msk                       /*!< Auto-Baud Rate Flag */
#define USART_ISR_BUSY_Pos            (16U)                                    
#define USART_ISR_BUSY_Msk            (0x1U << USART_ISR_BUSY_Pos)             /*!< 0x00010000 */
#define USART_ISR_BUSY                USART_ISR_BUSY_Msk                       /*!< Busy Flag */
#define USART_ISR_CMF_Pos             (17U)                                    
#define USART_ISR_CMF_Msk             (0x1U << USART_ISR_CMF_Pos)              /*!< 0x00020000 */
#define USART_ISR_CMF                 USART_ISR_CMF_Msk                        /*!< Character Match Flag */
#define USART_ISR_SBKF_Pos            (18U)                                    
#define USART_ISR_SBKF_Msk            (0x1U << USART_ISR_SBKF_Pos)             /*!< 0x00040000 */
#define USART_ISR_SBKF                USART_ISR_SBKF_Msk                       /*!< Send Break Flag */
#define USART_ISR_RWU_Pos             (19U)                                    
#define USART_ISR_RWU_Msk             (0x1U << USART_ISR_RWU_Pos)              /*!< 0x00080000 */
#define USART_ISR_RWU                 USART_ISR_RWU_Msk                        /*!< Receive Wake Up from mute mode Flag */
#define USART_ISR_WUF_Pos             (20U)                                    
#define USART_ISR_WUF_Msk             (0x1U << USART_ISR_WUF_Pos)              /*!< 0x00100000 */
#define USART_ISR_WUF                 USART_ISR_WUF_Msk                        /*!< Wake Up from stop mode Flag */
#define USART_ISR_TEACK_Pos           (21U)                                    
#define USART_ISR_TEACK_Msk           (0x1U << USART_ISR_TEACK_Pos)            /*!< 0x00200000 */
#define USART_ISR_TEACK               USART_ISR_TEACK_Msk                      /*!< Transmit Enable Acknowledge Flag */
#define USART_ISR_REACK_Pos           (22U)                                    
#define USART_ISR_REACK_Msk           (0x1U << USART_ISR_REACK_Pos)            /*!< 0x00400000 */
#define USART_ISR_REACK               USART_ISR_REACK_Msk                      /*!< Receive Enable Acknowledge Flag */

/*******************  Bit definition for USART_ICR register  ******************/
#define USART_ICR_PECF_Pos            (0U)                                     
#define USART_ICR_PECF_Msk            (0x1U << USART_ICR_PECF_Pos)             /*!< 0x00000001 */
#define USART_ICR_PECF                USART_ICR_PECF_Msk                       /*!< Parity Error Clear Flag */
#define USART_ICR_FECF_Pos            (1U)                                     
#define USART_ICR_FECF_Msk            (0x1U << USART_ICR_FECF_Pos)             /*!< 0x00000002 */
#define USART_ICR_FECF                USART_ICR_FECF_Msk                       /*!< Framing Error Clear Flag */
#define USART_ICR_NCF_Pos             (2U)                                     
#define USART_ICR_NCF_Msk             (0x1U << USART_ICR_NCF_Pos)              /*!< 0x00000004 */
#define USART_ICR_NCF                 USART_ICR_NCF_Msk                        /*!< Noise detected Clear Flag */
#define USART_ICR_ORECF_Pos           (3U)                                     
#define USART_ICR_ORECF_Msk           (0x1U << USART_ICR_ORECF_Pos)            /*!< 0x00000008 */
#define USART_ICR_ORECF               USART_ICR_ORECF_Msk                      /*!< OverRun Error Clear Flag */
#define USART_ICR_IDLECF_Pos          (4U)                                     
#define USART_ICR_IDLECF_Msk          (0x1U << USART_ICR_IDLECF_Pos)           /*!< 0x00000010 */
#define USART_ICR_IDLECF              USART_ICR_IDLECF_Msk                     /*!< IDLE line detected Clear Flag */
#define USART_ICR_TCCF_Pos            (6U)                                     
#define USART_ICR_TCCF_Msk            (0x1U << USART_ICR_TCCF_Pos)             /*!< 0x00000040 */
#define USART_ICR_TCCF                USART_ICR_TCCF_Msk                       /*!< Transmission Complete Clear Flag */
#define USART_ICR_LBDCF_Pos           (8U)                                     
#define USART_ICR_LBDCF_Msk           (0x1U << USART_ICR_LBDCF_Pos)            /*!< 0x00000100 */
#define USART_ICR_LBDCF               USART_ICR_LBDCF_Msk                      /*!< LIN Break Detection Clear Flag */
#define USART_ICR_CTSCF_Pos           (9U)                                     
#define USART_ICR_CTSCF_Msk           (0x1U << USART_ICR_CTSCF_Pos)            /*!< 0x00000200 */
#define USART_ICR_CTSCF               USART_ICR_CTSCF_Msk                      /*!< CTS Interrupt Clear Flag */
#define USART_ICR_RTOCF_Pos           (11U)                                    
#define USART_ICR_RTOCF_Msk           (0x1U << USART_ICR_RTOCF_Pos)            /*!< 0x00000800 */
#define USART_ICR_RTOCF               USART_ICR_RTOCF_Msk                      /*!< Receiver Time Out Clear Flag */
#define USART_ICR_EOBCF_Pos           (12U)                                    
#define USART_ICR_EOBCF_Msk           (0x1U << USART_ICR_EOBCF_Pos)            /*!< 0x00001000 */
#define USART_ICR_EOBCF               USART_ICR_EOBCF_Msk                      /*!< End Of Block Clear Flag */
#define USART_ICR_CMCF_Pos            (17U)                                    
#define USART_ICR_CMCF_Msk            (0x1U << USART_ICR_CMCF_Pos)             /*!< 0x00020000 */
#define USART_ICR_CMCF                USART_ICR_CMCF_Msk                       /*!< Character Match Clear Flag */
#define USART_ICR_WUCF_Pos            (20U)                                    
#define USART_ICR_WUCF_Msk            (0x1U << USART_ICR_WUCF_Pos)             /*!< 0x00100000 */
#define USART_ICR_WUCF                USART_ICR_WUCF_Msk                       /*!< Wake Up from stop mode Clear Flag */

/*******************  Bit definition for USART_RDR register  ******************/
#define USART_RDR_RDR                 ((uint16_t)0x01FFU)                      /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define USART_TDR_TDR                 ((uint16_t)0x01FFU)                      /*!< TDR[8:0] bits (Transmit Data value) */

