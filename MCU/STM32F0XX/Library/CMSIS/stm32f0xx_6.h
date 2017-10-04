
/*****************************************************************************/
/*                                                                           */
/*                           Real-Time Clock (RTC)                           */
/*                                                                           */
/*****************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32F0 serie)
*/
#define RTC_TAMPER1_SUPPORT  /*!< TAMPER 1 feature support */
#define RTC_TAMPER2_SUPPORT  /*!< TAMPER 2 feature support */
#define RTC_TAMPER3_SUPPORT  /*!< TAMPER 3 feature support */
#define RTC_BACKUP_SUPPORT   /*!< BACKUP register feature support */
#define RTC_WAKEUP_SUPPORT   /*!< WAKEUP feature support */

/********************  Bits definition for RTC_TR register  ******************/
#define RTC_TR_PM_Pos                (22U)                                     
#define RTC_TR_PM_Msk                (0x1U << RTC_TR_PM_Pos)                   /*!< 0x00400000 */
#define RTC_TR_PM                    RTC_TR_PM_Msk                             
#define RTC_TR_HT_Pos                (20U)                                     
#define RTC_TR_HT_Msk                (0x3U << RTC_TR_HT_Pos)                   /*!< 0x00300000 */
#define RTC_TR_HT                    RTC_TR_HT_Msk                             
#define RTC_TR_HT_0                  (0x1U << RTC_TR_HT_Pos)                   /*!< 0x00100000 */
#define RTC_TR_HT_1                  (0x2U << RTC_TR_HT_Pos)                   /*!< 0x00200000 */
#define RTC_TR_HU_Pos                (16U)                                     
#define RTC_TR_HU_Msk                (0xFU << RTC_TR_HU_Pos)                   /*!< 0x000F0000 */
#define RTC_TR_HU                    RTC_TR_HU_Msk                             
#define RTC_TR_HU_0                  (0x1U << RTC_TR_HU_Pos)                   /*!< 0x00010000 */
#define RTC_TR_HU_1                  (0x2U << RTC_TR_HU_Pos)                   /*!< 0x00020000 */
#define RTC_TR_HU_2                  (0x4U << RTC_TR_HU_Pos)                   /*!< 0x00040000 */
#define RTC_TR_HU_3                  (0x8U << RTC_TR_HU_Pos)                   /*!< 0x00080000 */
#define RTC_TR_MNT_Pos               (12U)                                     
#define RTC_TR_MNT_Msk               (0x7U << RTC_TR_MNT_Pos)                  /*!< 0x00007000 */
#define RTC_TR_MNT                   RTC_TR_MNT_Msk                            
#define RTC_TR_MNT_0                 (0x1U << RTC_TR_MNT_Pos)                  /*!< 0x00001000 */
#define RTC_TR_MNT_1                 (0x2U << RTC_TR_MNT_Pos)                  /*!< 0x00002000 */
#define RTC_TR_MNT_2                 (0x4U << RTC_TR_MNT_Pos)                  /*!< 0x00004000 */
#define RTC_TR_MNU_Pos               (8U)                                      
#define RTC_TR_MNU_Msk               (0xFU << RTC_TR_MNU_Pos)                  /*!< 0x00000F00 */
#define RTC_TR_MNU                   RTC_TR_MNU_Msk                            
#define RTC_TR_MNU_0                 (0x1U << RTC_TR_MNU_Pos)                  /*!< 0x00000100 */
#define RTC_TR_MNU_1                 (0x2U << RTC_TR_MNU_Pos)                  /*!< 0x00000200 */
#define RTC_TR_MNU_2                 (0x4U << RTC_TR_MNU_Pos)                  /*!< 0x00000400 */
#define RTC_TR_MNU_3                 (0x8U << RTC_TR_MNU_Pos)                  /*!< 0x00000800 */
#define RTC_TR_ST_Pos                (4U)                                      
#define RTC_TR_ST_Msk                (0x7U << RTC_TR_ST_Pos)                   /*!< 0x00000070 */
#define RTC_TR_ST                    RTC_TR_ST_Msk                             
#define RTC_TR_ST_0                  (0x1U << RTC_TR_ST_Pos)                   /*!< 0x00000010 */
#define RTC_TR_ST_1                  (0x2U << RTC_TR_ST_Pos)                   /*!< 0x00000020 */
#define RTC_TR_ST_2                  (0x4U << RTC_TR_ST_Pos)                   /*!< 0x00000040 */
#define RTC_TR_SU_Pos                (0U)                                      
#define RTC_TR_SU_Msk                (0xFU << RTC_TR_SU_Pos)                   /*!< 0x0000000F */
#define RTC_TR_SU                    RTC_TR_SU_Msk                             
#define RTC_TR_SU_0                  (0x1U << RTC_TR_SU_Pos)                   /*!< 0x00000001 */
#define RTC_TR_SU_1                  (0x2U << RTC_TR_SU_Pos)                   /*!< 0x00000002 */
#define RTC_TR_SU_2                  (0x4U << RTC_TR_SU_Pos)                   /*!< 0x00000004 */
#define RTC_TR_SU_3                  (0x8U << RTC_TR_SU_Pos)                   /*!< 0x00000008 */

/********************  Bits definition for RTC_DR register  ******************/
#define RTC_DR_YT_Pos                (20U)                                     
#define RTC_DR_YT_Msk                (0xFU << RTC_DR_YT_Pos)                   /*!< 0x00F00000 */
#define RTC_DR_YT                    RTC_DR_YT_Msk                             
#define RTC_DR_YT_0                  (0x1U << RTC_DR_YT_Pos)                   /*!< 0x00100000 */
#define RTC_DR_YT_1                  (0x2U << RTC_DR_YT_Pos)                   /*!< 0x00200000 */
#define RTC_DR_YT_2                  (0x4U << RTC_DR_YT_Pos)                   /*!< 0x00400000 */
#define RTC_DR_YT_3                  (0x8U << RTC_DR_YT_Pos)                   /*!< 0x00800000 */
#define RTC_DR_YU_Pos                (16U)                                     
#define RTC_DR_YU_Msk                (0xFU << RTC_DR_YU_Pos)                   /*!< 0x000F0000 */
#define RTC_DR_YU                    RTC_DR_YU_Msk                             
#define RTC_DR_YU_0                  (0x1U << RTC_DR_YU_Pos)                   /*!< 0x00010000 */
#define RTC_DR_YU_1                  (0x2U << RTC_DR_YU_Pos)                   /*!< 0x00020000 */
#define RTC_DR_YU_2                  (0x4U << RTC_DR_YU_Pos)                   /*!< 0x00040000 */
#define RTC_DR_YU_3                  (0x8U << RTC_DR_YU_Pos)                   /*!< 0x00080000 */
#define RTC_DR_WDU_Pos               (13U)                                     
#define RTC_DR_WDU_Msk               (0x7U << RTC_DR_WDU_Pos)                  /*!< 0x0000E000 */
#define RTC_DR_WDU                   RTC_DR_WDU_Msk                            
#define RTC_DR_WDU_0                 (0x1U << RTC_DR_WDU_Pos)                  /*!< 0x00002000 */
#define RTC_DR_WDU_1                 (0x2U << RTC_DR_WDU_Pos)                  /*!< 0x00004000 */
#define RTC_DR_WDU_2                 (0x4U << RTC_DR_WDU_Pos)                  /*!< 0x00008000 */
#define RTC_DR_MT_Pos                (12U)                                     
#define RTC_DR_MT_Msk                (0x1U << RTC_DR_MT_Pos)                   /*!< 0x00001000 */
#define RTC_DR_MT                    RTC_DR_MT_Msk                             
#define RTC_DR_MU_Pos                (8U)                                      
#define RTC_DR_MU_Msk                (0xFU << RTC_DR_MU_Pos)                   /*!< 0x00000F00 */
#define RTC_DR_MU                    RTC_DR_MU_Msk                             
#define RTC_DR_MU_0                  (0x1U << RTC_DR_MU_Pos)                   /*!< 0x00000100 */
#define RTC_DR_MU_1                  (0x2U << RTC_DR_MU_Pos)                   /*!< 0x00000200 */
#define RTC_DR_MU_2                  (0x4U << RTC_DR_MU_Pos)                   /*!< 0x00000400 */
#define RTC_DR_MU_3                  (0x8U << RTC_DR_MU_Pos)                   /*!< 0x00000800 */
#define RTC_DR_DT_Pos                (4U)                                      
#define RTC_DR_DT_Msk                (0x3U << RTC_DR_DT_Pos)                   /*!< 0x00000030 */
#define RTC_DR_DT                    RTC_DR_DT_Msk                             
#define RTC_DR_DT_0                  (0x1U << RTC_DR_DT_Pos)                   /*!< 0x00000010 */
#define RTC_DR_DT_1                  (0x2U << RTC_DR_DT_Pos)                   /*!< 0x00000020 */
#define RTC_DR_DU_Pos                (0U)                                      
#define RTC_DR_DU_Msk                (0xFU << RTC_DR_DU_Pos)                   /*!< 0x0000000F */
#define RTC_DR_DU                    RTC_DR_DU_Msk                             
#define RTC_DR_DU_0                  (0x1U << RTC_DR_DU_Pos)                   /*!< 0x00000001 */
#define RTC_DR_DU_1                  (0x2U << RTC_DR_DU_Pos)                   /*!< 0x00000002 */
#define RTC_DR_DU_2                  (0x4U << RTC_DR_DU_Pos)                   /*!< 0x00000004 */
#define RTC_DR_DU_3                  (0x8U << RTC_DR_DU_Pos)                   /*!< 0x00000008 */

/********************  Bits definition for RTC_CR register  ******************/
#define RTC_CR_COE_Pos               (23U)                                     
#define RTC_CR_COE_Msk               (0x1U << RTC_CR_COE_Pos)                  /*!< 0x00800000 */
#define RTC_CR_COE                   RTC_CR_COE_Msk                            
#define RTC_CR_OSEL_Pos              (21U)                                     
#define RTC_CR_OSEL_Msk              (0x3U << RTC_CR_OSEL_Pos)                 /*!< 0x00600000 */
#define RTC_CR_OSEL                  RTC_CR_OSEL_Msk                           
#define RTC_CR_OSEL_0                (0x1U << RTC_CR_OSEL_Pos)                 /*!< 0x00200000 */
#define RTC_CR_OSEL_1                (0x2U << RTC_CR_OSEL_Pos)                 /*!< 0x00400000 */
#define RTC_CR_POL_Pos               (20U)                                     
#define RTC_CR_POL_Msk               (0x1U << RTC_CR_POL_Pos)                  /*!< 0x00100000 */
#define RTC_CR_POL                   RTC_CR_POL_Msk                            
#define RTC_CR_COSEL_Pos             (19U)                                     
#define RTC_CR_COSEL_Msk             (0x1U << RTC_CR_COSEL_Pos)                /*!< 0x00080000 */
#define RTC_CR_COSEL                 RTC_CR_COSEL_Msk                          
#define RTC_CR_BCK_Pos               (18U)                                     
#define RTC_CR_BCK_Msk               (0x1U << RTC_CR_BCK_Pos)                  /*!< 0x00040000 */
#define RTC_CR_BCK                   RTC_CR_BCK_Msk                            
#define RTC_CR_SUB1H_Pos             (17U)                                     
#define RTC_CR_SUB1H_Msk             (0x1U << RTC_CR_SUB1H_Pos)                /*!< 0x00020000 */
#define RTC_CR_SUB1H                 RTC_CR_SUB1H_Msk                          
#define RTC_CR_ADD1H_Pos             (16U)                                     
#define RTC_CR_ADD1H_Msk             (0x1U << RTC_CR_ADD1H_Pos)                /*!< 0x00010000 */
#define RTC_CR_ADD1H                 RTC_CR_ADD1H_Msk                          
#define RTC_CR_TSIE_Pos              (15U)                                     
#define RTC_CR_TSIE_Msk              (0x1U << RTC_CR_TSIE_Pos)                 /*!< 0x00008000 */
#define RTC_CR_TSIE                  RTC_CR_TSIE_Msk                           
#define RTC_CR_WUTIE_Pos             (14U)                                     
#define RTC_CR_WUTIE_Msk             (0x1U << RTC_CR_WUTIE_Pos)                /*!< 0x00004000 */
#define RTC_CR_WUTIE                 RTC_CR_WUTIE_Msk                          
#define RTC_CR_ALRAIE_Pos            (12U)                                     
#define RTC_CR_ALRAIE_Msk            (0x1U << RTC_CR_ALRAIE_Pos)               /*!< 0x00001000 */
#define RTC_CR_ALRAIE                RTC_CR_ALRAIE_Msk                         
#define RTC_CR_TSE_Pos               (11U)                                     
#define RTC_CR_TSE_Msk               (0x1U << RTC_CR_TSE_Pos)                  /*!< 0x00000800 */
#define RTC_CR_TSE                   RTC_CR_TSE_Msk                            
#define RTC_CR_WUTE_Pos              (10U)                                     
#define RTC_CR_WUTE_Msk              (0x1U << RTC_CR_WUTE_Pos)                 /*!< 0x00000400 */
#define RTC_CR_WUTE                  RTC_CR_WUTE_Msk                           
#define RTC_CR_ALRAE_Pos             (8U)                                      
#define RTC_CR_ALRAE_Msk             (0x1U << RTC_CR_ALRAE_Pos)                /*!< 0x00000100 */
#define RTC_CR_ALRAE                 RTC_CR_ALRAE_Msk                          
#define RTC_CR_FMT_Pos               (6U)                                      
#define RTC_CR_FMT_Msk               (0x1U << RTC_CR_FMT_Pos)                  /*!< 0x00000040 */
#define RTC_CR_FMT                   RTC_CR_FMT_Msk                            
#define RTC_CR_BYPSHAD_Pos           (5U)                                      
#define RTC_CR_BYPSHAD_Msk           (0x1U << RTC_CR_BYPSHAD_Pos)              /*!< 0x00000020 */
#define RTC_CR_BYPSHAD               RTC_CR_BYPSHAD_Msk                        
#define RTC_CR_REFCKON_Pos           (4U)                                      
#define RTC_CR_REFCKON_Msk           (0x1U << RTC_CR_REFCKON_Pos)              /*!< 0x00000010 */
#define RTC_CR_REFCKON               RTC_CR_REFCKON_Msk                        
#define RTC_CR_TSEDGE_Pos            (3U)                                      
#define RTC_CR_TSEDGE_Msk            (0x1U << RTC_CR_TSEDGE_Pos)               /*!< 0x00000008 */
#define RTC_CR_TSEDGE                RTC_CR_TSEDGE_Msk                         
#define RTC_CR_WUCKSEL_Pos           (0U)                                      
#define RTC_CR_WUCKSEL_Msk           (0x7U << RTC_CR_WUCKSEL_Pos)              /*!< 0x00000007 */
#define RTC_CR_WUCKSEL               RTC_CR_WUCKSEL_Msk                        
#define RTC_CR_WUCKSEL_0             (0x1U << RTC_CR_WUCKSEL_Pos)              /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1             (0x2U << RTC_CR_WUCKSEL_Pos)              /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2             (0x4U << RTC_CR_WUCKSEL_Pos)              /*!< 0x00000004 */

/********************  Bits definition for RTC_ISR register  *****************/
#define RTC_ISR_RECALPF_Pos          (16U)                                     
#define RTC_ISR_RECALPF_Msk          (0x1U << RTC_ISR_RECALPF_Pos)             /*!< 0x00010000 */
#define RTC_ISR_RECALPF              RTC_ISR_RECALPF_Msk                       
#define RTC_ISR_TAMP3F_Pos           (15U)                                     
#define RTC_ISR_TAMP3F_Msk           (0x1U << RTC_ISR_TAMP3F_Pos)              /*!< 0x00008000 */
#define RTC_ISR_TAMP3F               RTC_ISR_TAMP3F_Msk                        
#define RTC_ISR_TAMP2F_Pos           (14U)                                     
#define RTC_ISR_TAMP2F_Msk           (0x1U << RTC_ISR_TAMP2F_Pos)              /*!< 0x00004000 */
#define RTC_ISR_TAMP2F               RTC_ISR_TAMP2F_Msk                        
#define RTC_ISR_TAMP1F_Pos           (13U)                                     
#define RTC_ISR_TAMP1F_Msk           (0x1U << RTC_ISR_TAMP1F_Pos)              /*!< 0x00002000 */
#define RTC_ISR_TAMP1F               RTC_ISR_TAMP1F_Msk                        
#define RTC_ISR_TSOVF_Pos            (12U)                                     
#define RTC_ISR_TSOVF_Msk            (0x1U << RTC_ISR_TSOVF_Pos)               /*!< 0x00001000 */
#define RTC_ISR_TSOVF                RTC_ISR_TSOVF_Msk                         
#define RTC_ISR_TSF_Pos              (11U)                                     
#define RTC_ISR_TSF_Msk              (0x1U << RTC_ISR_TSF_Pos)                 /*!< 0x00000800 */
#define RTC_ISR_TSF                  RTC_ISR_TSF_Msk                           
#define RTC_ISR_WUTF_Pos             (10U)                                     
#define RTC_ISR_WUTF_Msk             (0x1U << RTC_ISR_WUTF_Pos)                /*!< 0x00000400 */
#define RTC_ISR_WUTF                 RTC_ISR_WUTF_Msk                          
#define RTC_ISR_ALRAF_Pos            (8U)                                      
#define RTC_ISR_ALRAF_Msk            (0x1U << RTC_ISR_ALRAF_Pos)               /*!< 0x00000100 */
#define RTC_ISR_ALRAF                RTC_ISR_ALRAF_Msk                         
#define RTC_ISR_INIT_Pos             (7U)                                      
#define RTC_ISR_INIT_Msk             (0x1U << RTC_ISR_INIT_Pos)                /*!< 0x00000080 */
#define RTC_ISR_INIT                 RTC_ISR_INIT_Msk                          
#define RTC_ISR_INITF_Pos            (6U)                                      
#define RTC_ISR_INITF_Msk            (0x1U << RTC_ISR_INITF_Pos)               /*!< 0x00000040 */
#define RTC_ISR_INITF                RTC_ISR_INITF_Msk                         
#define RTC_ISR_RSF_Pos              (5U)                                      
#define RTC_ISR_RSF_Msk              (0x1U << RTC_ISR_RSF_Pos)                 /*!< 0x00000020 */
#define RTC_ISR_RSF                  RTC_ISR_RSF_Msk                           
#define RTC_ISR_INITS_Pos            (4U)                                      
#define RTC_ISR_INITS_Msk            (0x1U << RTC_ISR_INITS_Pos)               /*!< 0x00000010 */
#define RTC_ISR_INITS                RTC_ISR_INITS_Msk                         
#define RTC_ISR_SHPF_Pos             (3U)                                      
#define RTC_ISR_SHPF_Msk             (0x1U << RTC_ISR_SHPF_Pos)                /*!< 0x00000008 */
#define RTC_ISR_SHPF                 RTC_ISR_SHPF_Msk                          
#define RTC_ISR_WUTWF_Pos            (2U)                                      
#define RTC_ISR_WUTWF_Msk            (0x1U << RTC_ISR_WUTWF_Pos)               /*!< 0x00000004 */
#define RTC_ISR_WUTWF                RTC_ISR_WUTWF_Msk                         
#define RTC_ISR_ALRAWF_Pos           (0U)                                      
#define RTC_ISR_ALRAWF_Msk           (0x1U << RTC_ISR_ALRAWF_Pos)              /*!< 0x00000001 */
#define RTC_ISR_ALRAWF               RTC_ISR_ALRAWF_Msk                        

/********************  Bits definition for RTC_PRER register  ****************/
#define RTC_PRER_PREDIV_A_Pos        (16U)                                     
#define RTC_PRER_PREDIV_A_Msk        (0x7FU << RTC_PRER_PREDIV_A_Pos)          /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A            RTC_PRER_PREDIV_A_Msk                     
#define RTC_PRER_PREDIV_S_Pos        (0U)                                      
#define RTC_PRER_PREDIV_S_Msk        (0x7FFFU << RTC_PRER_PREDIV_S_Pos)        /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S            RTC_PRER_PREDIV_S_Msk                     

/********************  Bits definition for RTC_WUTR register  ****************/
#define RTC_WUTR_WUT_Pos             (0U)                                      
#define RTC_WUTR_WUT_Msk             (0xFFFFU << RTC_WUTR_WUT_Pos)             /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                 RTC_WUTR_WUT_Msk                          

/********************  Bits definition for RTC_ALRMAR register  **************/
#define RTC_ALRMAR_MSK4_Pos          (31U)                                     
#define RTC_ALRMAR_MSK4_Msk          (0x1U << RTC_ALRMAR_MSK4_Pos)             /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4              RTC_ALRMAR_MSK4_Msk                       
#define RTC_ALRMAR_WDSEL_Pos         (30U)                                     
#define RTC_ALRMAR_WDSEL_Msk         (0x1U << RTC_ALRMAR_WDSEL_Pos)            /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL             RTC_ALRMAR_WDSEL_Msk                      
#define RTC_ALRMAR_DT_Pos            (28U)                                     
#define RTC_ALRMAR_DT_Msk            (0x3U << RTC_ALRMAR_DT_Pos)               /*!< 0x30000000 */
#define RTC_ALRMAR_DT                RTC_ALRMAR_DT_Msk                         
#define RTC_ALRMAR_DT_0              (0x1U << RTC_ALRMAR_DT_Pos)               /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1              (0x2U << RTC_ALRMAR_DT_Pos)               /*!< 0x20000000 */
#define RTC_ALRMAR_DU_Pos            (24U)                                     
#define RTC_ALRMAR_DU_Msk            (0xFU << RTC_ALRMAR_DU_Pos)               /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                RTC_ALRMAR_DU_Msk                         
#define RTC_ALRMAR_DU_0              (0x1U << RTC_ALRMAR_DU_Pos)               /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1              (0x2U << RTC_ALRMAR_DU_Pos)               /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2              (0x4U << RTC_ALRMAR_DU_Pos)               /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3              (0x8U << RTC_ALRMAR_DU_Pos)               /*!< 0x08000000 */
#define RTC_ALRMAR_MSK3_Pos          (23U)                                     
#define RTC_ALRMAR_MSK3_Msk          (0x1U << RTC_ALRMAR_MSK3_Pos)             /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3              RTC_ALRMAR_MSK3_Msk                       
#define RTC_ALRMAR_PM_Pos            (22U)                                     
#define RTC_ALRMAR_PM_Msk            (0x1U << RTC_ALRMAR_PM_Pos)               /*!< 0x00400000 */
#define RTC_ALRMAR_PM                RTC_ALRMAR_PM_Msk                         
#define RTC_ALRMAR_HT_Pos            (20U)                                     
#define RTC_ALRMAR_HT_Msk            (0x3U << RTC_ALRMAR_HT_Pos)               /*!< 0x00300000 */
#define RTC_ALRMAR_HT                RTC_ALRMAR_HT_Msk                         
#define RTC_ALRMAR_HT_0              (0x1U << RTC_ALRMAR_HT_Pos)               /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1              (0x2U << RTC_ALRMAR_HT_Pos)               /*!< 0x00200000 */
#define RTC_ALRMAR_HU_Pos            (16U)                                     
#define RTC_ALRMAR_HU_Msk            (0xFU << RTC_ALRMAR_HU_Pos)               /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                RTC_ALRMAR_HU_Msk                         
#define RTC_ALRMAR_HU_0              (0x1U << RTC_ALRMAR_HU_Pos)               /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1              (0x2U << RTC_ALRMAR_HU_Pos)               /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2              (0x4U << RTC_ALRMAR_HU_Pos)               /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3              (0x8U << RTC_ALRMAR_HU_Pos)               /*!< 0x00080000 */
#define RTC_ALRMAR_MSK2_Pos          (15U)                                     
#define RTC_ALRMAR_MSK2_Msk          (0x1U << RTC_ALRMAR_MSK2_Pos)             /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2              RTC_ALRMAR_MSK2_Msk                       
#define RTC_ALRMAR_MNT_Pos           (12U)                                     
#define RTC_ALRMAR_MNT_Msk           (0x7U << RTC_ALRMAR_MNT_Pos)              /*!< 0x00007000 */
#define RTC_ALRMAR_MNT               RTC_ALRMAR_MNT_Msk                        
#define RTC_ALRMAR_MNT_0             (0x1U << RTC_ALRMAR_MNT_Pos)              /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1             (0x2U << RTC_ALRMAR_MNT_Pos)              /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2             (0x4U << RTC_ALRMAR_MNT_Pos)              /*!< 0x00004000 */
#define RTC_ALRMAR_MNU_Pos           (8U)                                      
#define RTC_ALRMAR_MNU_Msk           (0xFU << RTC_ALRMAR_MNU_Pos)              /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU               RTC_ALRMAR_MNU_Msk                        
#define RTC_ALRMAR_MNU_0             (0x1U << RTC_ALRMAR_MNU_Pos)              /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1             (0x2U << RTC_ALRMAR_MNU_Pos)              /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2             (0x4U << RTC_ALRMAR_MNU_Pos)              /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3             (0x8U << RTC_ALRMAR_MNU_Pos)              /*!< 0x00000800 */
#define RTC_ALRMAR_MSK1_Pos          (7U)                                      
#define RTC_ALRMAR_MSK1_Msk          (0x1U << RTC_ALRMAR_MSK1_Pos)             /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1              RTC_ALRMAR_MSK1_Msk                       
#define RTC_ALRMAR_ST_Pos            (4U)                                      
#define RTC_ALRMAR_ST_Msk            (0x7U << RTC_ALRMAR_ST_Pos)               /*!< 0x00000070 */
#define RTC_ALRMAR_ST                RTC_ALRMAR_ST_Msk                         
#define RTC_ALRMAR_ST_0              (0x1U << RTC_ALRMAR_ST_Pos)               /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1              (0x2U << RTC_ALRMAR_ST_Pos)               /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2              (0x4U << RTC_ALRMAR_ST_Pos)               /*!< 0x00000040 */
#define RTC_ALRMAR_SU_Pos            (0U)                                      
#define RTC_ALRMAR_SU_Msk            (0xFU << RTC_ALRMAR_SU_Pos)               /*!< 0x0000000F */
#define RTC_ALRMAR_SU                RTC_ALRMAR_SU_Msk                         
#define RTC_ALRMAR_SU_0              (0x1U << RTC_ALRMAR_SU_Pos)               /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1              (0x2U << RTC_ALRMAR_SU_Pos)               /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2              (0x4U << RTC_ALRMAR_SU_Pos)               /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3              (0x8U << RTC_ALRMAR_SU_Pos)               /*!< 0x00000008 */

/********************  Bits definition for RTC_WPR register  *****************/
#define RTC_WPR_KEY_Pos              (0U)                                      
#define RTC_WPR_KEY_Msk              (0xFFU << RTC_WPR_KEY_Pos)                /*!< 0x000000FF */
#define RTC_WPR_KEY                  RTC_WPR_KEY_Msk                           

/********************  Bits definition for RTC_SSR register  *****************/
#define RTC_SSR_SS_Pos               (0U)                                      
#define RTC_SSR_SS_Msk               (0xFFFFU << RTC_SSR_SS_Pos)               /*!< 0x0000FFFF */
#define RTC_SSR_SS                   RTC_SSR_SS_Msk                            

/********************  Bits definition for RTC_SHIFTR register  **************/
#define RTC_SHIFTR_SUBFS_Pos         (0U)                                      
#define RTC_SHIFTR_SUBFS_Msk         (0x7FFFU << RTC_SHIFTR_SUBFS_Pos)         /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS             RTC_SHIFTR_SUBFS_Msk                      
#define RTC_SHIFTR_ADD1S_Pos         (31U)                                     
#define RTC_SHIFTR_ADD1S_Msk         (0x1U << RTC_SHIFTR_ADD1S_Pos)            /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S             RTC_SHIFTR_ADD1S_Msk                      

/********************  Bits definition for RTC_TSTR register  ****************/
#define RTC_TSTR_PM_Pos              (22U)                                     
#define RTC_TSTR_PM_Msk              (0x1U << RTC_TSTR_PM_Pos)                 /*!< 0x00400000 */
#define RTC_TSTR_PM                  RTC_TSTR_PM_Msk                           
#define RTC_TSTR_HT_Pos              (20U)                                     
#define RTC_TSTR_HT_Msk              (0x3U << RTC_TSTR_HT_Pos)                 /*!< 0x00300000 */
#define RTC_TSTR_HT                  RTC_TSTR_HT_Msk                           
#define RTC_TSTR_HT_0                (0x1U << RTC_TSTR_HT_Pos)                 /*!< 0x00100000 */
#define RTC_TSTR_HT_1                (0x2U << RTC_TSTR_HT_Pos)                 /*!< 0x00200000 */
#define RTC_TSTR_HU_Pos              (16U)                                     
#define RTC_TSTR_HU_Msk              (0xFU << RTC_TSTR_HU_Pos)                 /*!< 0x000F0000 */
#define RTC_TSTR_HU                  RTC_TSTR_HU_Msk                           
#define RTC_TSTR_HU_0                (0x1U << RTC_TSTR_HU_Pos)                 /*!< 0x00010000 */
#define RTC_TSTR_HU_1                (0x2U << RTC_TSTR_HU_Pos)                 /*!< 0x00020000 */
#define RTC_TSTR_HU_2                (0x4U << RTC_TSTR_HU_Pos)                 /*!< 0x00040000 */
#define RTC_TSTR_HU_3                (0x8U << RTC_TSTR_HU_Pos)                 /*!< 0x00080000 */
#define RTC_TSTR_MNT_Pos             (12U)                                     
#define RTC_TSTR_MNT_Msk             (0x7U << RTC_TSTR_MNT_Pos)                /*!< 0x00007000 */
#define RTC_TSTR_MNT                 RTC_TSTR_MNT_Msk                          
#define RTC_TSTR_MNT_0               (0x1U << RTC_TSTR_MNT_Pos)                /*!< 0x00001000 */
#define RTC_TSTR_MNT_1               (0x2U << RTC_TSTR_MNT_Pos)                /*!< 0x00002000 */
#define RTC_TSTR_MNT_2               (0x4U << RTC_TSTR_MNT_Pos)                /*!< 0x00004000 */
#define RTC_TSTR_MNU_Pos             (8U)                                      
#define RTC_TSTR_MNU_Msk             (0xFU << RTC_TSTR_MNU_Pos)                /*!< 0x00000F00 */
#define RTC_TSTR_MNU                 RTC_TSTR_MNU_Msk                          
#define RTC_TSTR_MNU_0               (0x1U << RTC_TSTR_MNU_Pos)                /*!< 0x00000100 */
#define RTC_TSTR_MNU_1               (0x2U << RTC_TSTR_MNU_Pos)                /*!< 0x00000200 */
#define RTC_TSTR_MNU_2               (0x4U << RTC_TSTR_MNU_Pos)                /*!< 0x00000400 */
#define RTC_TSTR_MNU_3               (0x8U << RTC_TSTR_MNU_Pos)                /*!< 0x00000800 */
#define RTC_TSTR_ST_Pos              (4U)                                      
#define RTC_TSTR_ST_Msk              (0x7U << RTC_TSTR_ST_Pos)                 /*!< 0x00000070 */
#define RTC_TSTR_ST                  RTC_TSTR_ST_Msk                           
#define RTC_TSTR_ST_0                (0x1U << RTC_TSTR_ST_Pos)                 /*!< 0x00000010 */
#define RTC_TSTR_ST_1                (0x2U << RTC_TSTR_ST_Pos)                 /*!< 0x00000020 */
#define RTC_TSTR_ST_2                (0x4U << RTC_TSTR_ST_Pos)                 /*!< 0x00000040 */
#define RTC_TSTR_SU_Pos              (0U)                                      
#define RTC_TSTR_SU_Msk              (0xFU << RTC_TSTR_SU_Pos)                 /*!< 0x0000000F */
#define RTC_TSTR_SU                  RTC_TSTR_SU_Msk                           
#define RTC_TSTR_SU_0                (0x1U << RTC_TSTR_SU_Pos)                 /*!< 0x00000001 */
#define RTC_TSTR_SU_1                (0x2U << RTC_TSTR_SU_Pos)                 /*!< 0x00000002 */
#define RTC_TSTR_SU_2                (0x4U << RTC_TSTR_SU_Pos)                 /*!< 0x00000004 */
#define RTC_TSTR_SU_3                (0x8U << RTC_TSTR_SU_Pos)                 /*!< 0x00000008 */

/********************  Bits definition for RTC_TSDR register  ****************/
#define RTC_TSDR_WDU_Pos             (13U)                                     
#define RTC_TSDR_WDU_Msk             (0x7U << RTC_TSDR_WDU_Pos)                /*!< 0x0000E000 */
#define RTC_TSDR_WDU                 RTC_TSDR_WDU_Msk                          
#define RTC_TSDR_WDU_0               (0x1U << RTC_TSDR_WDU_Pos)                /*!< 0x00002000 */
#define RTC_TSDR_WDU_1               (0x2U << RTC_TSDR_WDU_Pos)                /*!< 0x00004000 */
#define RTC_TSDR_WDU_2               (0x4U << RTC_TSDR_WDU_Pos)                /*!< 0x00008000 */
#define RTC_TSDR_MT_Pos              (12U)                                     
#define RTC_TSDR_MT_Msk              (0x1U << RTC_TSDR_MT_Pos)                 /*!< 0x00001000 */
#define RTC_TSDR_MT                  RTC_TSDR_MT_Msk                           
#define RTC_TSDR_MU_Pos              (8U)                                      
#define RTC_TSDR_MU_Msk              (0xFU << RTC_TSDR_MU_Pos)                 /*!< 0x00000F00 */
#define RTC_TSDR_MU                  RTC_TSDR_MU_Msk                           
#define RTC_TSDR_MU_0                (0x1U << RTC_TSDR_MU_Pos)                 /*!< 0x00000100 */
#define RTC_TSDR_MU_1                (0x2U << RTC_TSDR_MU_Pos)                 /*!< 0x00000200 */
#define RTC_TSDR_MU_2                (0x4U << RTC_TSDR_MU_Pos)                 /*!< 0x00000400 */
#define RTC_TSDR_MU_3                (0x8U << RTC_TSDR_MU_Pos)                 /*!< 0x00000800 */
#define RTC_TSDR_DT_Pos              (4U)                                      
#define RTC_TSDR_DT_Msk              (0x3U << RTC_TSDR_DT_Pos)                 /*!< 0x00000030 */
#define RTC_TSDR_DT                  RTC_TSDR_DT_Msk                           
#define RTC_TSDR_DT_0                (0x1U << RTC_TSDR_DT_Pos)                 /*!< 0x00000010 */
#define RTC_TSDR_DT_1                (0x2U << RTC_TSDR_DT_Pos)                 /*!< 0x00000020 */
#define RTC_TSDR_DU_Pos              (0U)                                      
#define RTC_TSDR_DU_Msk              (0xFU << RTC_TSDR_DU_Pos)                 /*!< 0x0000000F */
#define RTC_TSDR_DU                  RTC_TSDR_DU_Msk                           
#define RTC_TSDR_DU_0                (0x1U << RTC_TSDR_DU_Pos)                 /*!< 0x00000001 */
#define RTC_TSDR_DU_1                (0x2U << RTC_TSDR_DU_Pos)                 /*!< 0x00000002 */
#define RTC_TSDR_DU_2                (0x4U << RTC_TSDR_DU_Pos)                 /*!< 0x00000004 */
#define RTC_TSDR_DU_3                (0x8U << RTC_TSDR_DU_Pos)                 /*!< 0x00000008 */

/********************  Bits definition for RTC_TSSSR register  ***************/
#define RTC_TSSSR_SS_Pos             (0U)                                      
#define RTC_TSSSR_SS_Msk             (0xFFFFU << RTC_TSSSR_SS_Pos)             /*!< 0x0000FFFF */
#define RTC_TSSSR_SS                 RTC_TSSSR_SS_Msk                          

/********************  Bits definition for RTC_CALR register  ****************/
#define RTC_CALR_CALP_Pos            (15U)                                     
#define RTC_CALR_CALP_Msk            (0x1U << RTC_CALR_CALP_Pos)               /*!< 0x00008000 */
#define RTC_CALR_CALP                RTC_CALR_CALP_Msk                         
#define RTC_CALR_CALW8_Pos           (14U)                                     
#define RTC_CALR_CALW8_Msk           (0x1U << RTC_CALR_CALW8_Pos)              /*!< 0x00004000 */
#define RTC_CALR_CALW8               RTC_CALR_CALW8_Msk                        
#define RTC_CALR_CALW16_Pos          (13U)                                     
#define RTC_CALR_CALW16_Msk          (0x1U << RTC_CALR_CALW16_Pos)             /*!< 0x00002000 */
#define RTC_CALR_CALW16              RTC_CALR_CALW16_Msk                       
#define RTC_CALR_CALM_Pos            (0U)                                      
#define RTC_CALR_CALM_Msk            (0x1FFU << RTC_CALR_CALM_Pos)             /*!< 0x000001FF */
#define RTC_CALR_CALM                RTC_CALR_CALM_Msk                         
#define RTC_CALR_CALM_0              (0x001U << RTC_CALR_CALM_Pos)             /*!< 0x00000001 */
#define RTC_CALR_CALM_1              (0x002U << RTC_CALR_CALM_Pos)             /*!< 0x00000002 */
#define RTC_CALR_CALM_2              (0x004U << RTC_CALR_CALM_Pos)             /*!< 0x00000004 */
#define RTC_CALR_CALM_3              (0x008U << RTC_CALR_CALM_Pos)             /*!< 0x00000008 */
#define RTC_CALR_CALM_4              (0x010U << RTC_CALR_CALM_Pos)             /*!< 0x00000010 */
#define RTC_CALR_CALM_5              (0x020U << RTC_CALR_CALM_Pos)             /*!< 0x00000020 */
#define RTC_CALR_CALM_6              (0x040U << RTC_CALR_CALM_Pos)             /*!< 0x00000040 */
#define RTC_CALR_CALM_7              (0x080U << RTC_CALR_CALM_Pos)             /*!< 0x00000080 */
#define RTC_CALR_CALM_8              (0x100U << RTC_CALR_CALM_Pos)             /*!< 0x00000100 */

/********************  Bits definition for RTC_TAFCR register  ***************/
#define RTC_TAFCR_PC15MODE_Pos       (23U)                                     
#define RTC_TAFCR_PC15MODE_Msk       (0x1U << RTC_TAFCR_PC15MODE_Pos)          /*!< 0x00800000 */
#define RTC_TAFCR_PC15MODE           RTC_TAFCR_PC15MODE_Msk                    
#define RTC_TAFCR_PC15VALUE_Pos      (22U)                                     
#define RTC_TAFCR_PC15VALUE_Msk      (0x1U << RTC_TAFCR_PC15VALUE_Pos)         /*!< 0x00400000 */
#define RTC_TAFCR_PC15VALUE          RTC_TAFCR_PC15VALUE_Msk                   
#define RTC_TAFCR_PC14MODE_Pos       (21U)                                     
#define RTC_TAFCR_PC14MODE_Msk       (0x1U << RTC_TAFCR_PC14MODE_Pos)          /*!< 0x00200000 */
#define RTC_TAFCR_PC14MODE           RTC_TAFCR_PC14MODE_Msk                    
#define RTC_TAFCR_PC14VALUE_Pos      (20U)                                     
#define RTC_TAFCR_PC14VALUE_Msk      (0x1U << RTC_TAFCR_PC14VALUE_Pos)         /*!< 0x00100000 */
#define RTC_TAFCR_PC14VALUE          RTC_TAFCR_PC14VALUE_Msk                   
#define RTC_TAFCR_PC13MODE_Pos       (19U)                                     
#define RTC_TAFCR_PC13MODE_Msk       (0x1U << RTC_TAFCR_PC13MODE_Pos)          /*!< 0x00080000 */
#define RTC_TAFCR_PC13MODE           RTC_TAFCR_PC13MODE_Msk                    
#define RTC_TAFCR_PC13VALUE_Pos      (18U)                                     
#define RTC_TAFCR_PC13VALUE_Msk      (0x1U << RTC_TAFCR_PC13VALUE_Pos)         /*!< 0x00040000 */
#define RTC_TAFCR_PC13VALUE          RTC_TAFCR_PC13VALUE_Msk                   
#define RTC_TAFCR_TAMPPUDIS_Pos      (15U)                                     
#define RTC_TAFCR_TAMPPUDIS_Msk      (0x1U << RTC_TAFCR_TAMPPUDIS_Pos)         /*!< 0x00008000 */
#define RTC_TAFCR_TAMPPUDIS          RTC_TAFCR_TAMPPUDIS_Msk                   
#define RTC_TAFCR_TAMPPRCH_Pos       (13U)                                     
#define RTC_TAFCR_TAMPPRCH_Msk       (0x3U << RTC_TAFCR_TAMPPRCH_Pos)          /*!< 0x00006000 */
#define RTC_TAFCR_TAMPPRCH           RTC_TAFCR_TAMPPRCH_Msk                    
#define RTC_TAFCR_TAMPPRCH_0         (0x1U << RTC_TAFCR_TAMPPRCH_Pos)          /*!< 0x00002000 */
#define RTC_TAFCR_TAMPPRCH_1         (0x2U << RTC_TAFCR_TAMPPRCH_Pos)          /*!< 0x00004000 */
#define RTC_TAFCR_TAMPFLT_Pos        (11U)                                     
#define RTC_TAFCR_TAMPFLT_Msk        (0x3U << RTC_TAFCR_TAMPFLT_Pos)           /*!< 0x00001800 */
#define RTC_TAFCR_TAMPFLT            RTC_TAFCR_TAMPFLT_Msk                     
#define RTC_TAFCR_TAMPFLT_0          (0x1U << RTC_TAFCR_TAMPFLT_Pos)           /*!< 0x00000800 */
#define RTC_TAFCR_TAMPFLT_1          (0x2U << RTC_TAFCR_TAMPFLT_Pos)           /*!< 0x00001000 */
#define RTC_TAFCR_TAMPFREQ_Pos       (8U)                                      
#define RTC_TAFCR_TAMPFREQ_Msk       (0x7U << RTC_TAFCR_TAMPFREQ_Pos)          /*!< 0x00000700 */
#define RTC_TAFCR_TAMPFREQ           RTC_TAFCR_TAMPFREQ_Msk                    
#define RTC_TAFCR_TAMPFREQ_0         (0x1U << RTC_TAFCR_TAMPFREQ_Pos)          /*!< 0x00000100 */
#define RTC_TAFCR_TAMPFREQ_1         (0x2U << RTC_TAFCR_TAMPFREQ_Pos)          /*!< 0x00000200 */
#define RTC_TAFCR_TAMPFREQ_2         (0x4U << RTC_TAFCR_TAMPFREQ_Pos)          /*!< 0x00000400 */
#define RTC_TAFCR_TAMPTS_Pos         (7U)                                      
#define RTC_TAFCR_TAMPTS_Msk         (0x1U << RTC_TAFCR_TAMPTS_Pos)            /*!< 0x00000080 */
#define RTC_TAFCR_TAMPTS             RTC_TAFCR_TAMPTS_Msk                      
#define RTC_TAFCR_TAMP3TRG_Pos       (6U)                                      
#define RTC_TAFCR_TAMP3TRG_Msk       (0x1U << RTC_TAFCR_TAMP3TRG_Pos)          /*!< 0x00000040 */
#define RTC_TAFCR_TAMP3TRG           RTC_TAFCR_TAMP3TRG_Msk                    
#define RTC_TAFCR_TAMP3E_Pos         (5U)                                      
#define RTC_TAFCR_TAMP3E_Msk         (0x1U << RTC_TAFCR_TAMP3E_Pos)            /*!< 0x00000020 */
#define RTC_TAFCR_TAMP3E             RTC_TAFCR_TAMP3E_Msk                      
#define RTC_TAFCR_TAMP2TRG_Pos       (4U)                                      
#define RTC_TAFCR_TAMP2TRG_Msk       (0x1U << RTC_TAFCR_TAMP2TRG_Pos)          /*!< 0x00000010 */
#define RTC_TAFCR_TAMP2TRG           RTC_TAFCR_TAMP2TRG_Msk                    
#define RTC_TAFCR_TAMP2E_Pos         (3U)                                      
#define RTC_TAFCR_TAMP2E_Msk         (0x1U << RTC_TAFCR_TAMP2E_Pos)            /*!< 0x00000008 */
#define RTC_TAFCR_TAMP2E             RTC_TAFCR_TAMP2E_Msk                      
#define RTC_TAFCR_TAMPIE_Pos         (2U)                                      
#define RTC_TAFCR_TAMPIE_Msk         (0x1U << RTC_TAFCR_TAMPIE_Pos)            /*!< 0x00000004 */
#define RTC_TAFCR_TAMPIE             RTC_TAFCR_TAMPIE_Msk                      
#define RTC_TAFCR_TAMP1TRG_Pos       (1U)                                      
#define RTC_TAFCR_TAMP1TRG_Msk       (0x1U << RTC_TAFCR_TAMP1TRG_Pos)          /*!< 0x00000002 */
#define RTC_TAFCR_TAMP1TRG           RTC_TAFCR_TAMP1TRG_Msk                    
#define RTC_TAFCR_TAMP1E_Pos         (0U)                                      
#define RTC_TAFCR_TAMP1E_Msk         (0x1U << RTC_TAFCR_TAMP1E_Pos)            /*!< 0x00000001 */
#define RTC_TAFCR_TAMP1E             RTC_TAFCR_TAMP1E_Msk                      

/* Reference defines */
#define RTC_TAFCR_ALARMOUTTYPE               RTC_TAFCR_PC13VALUE

/********************  Bits definition for RTC_ALRMASSR register  ************/
#define RTC_ALRMASSR_MASKSS_Pos      (24U)                                     
#define RTC_ALRMASSR_MASKSS_Msk      (0xFU << RTC_ALRMASSR_MASKSS_Pos)         /*!< 0x0F000000 */
#define RTC_ALRMASSR_MASKSS          RTC_ALRMASSR_MASKSS_Msk                   
#define RTC_ALRMASSR_MASKSS_0        (0x1U << RTC_ALRMASSR_MASKSS_Pos)         /*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1        (0x2U << RTC_ALRMASSR_MASKSS_Pos)         /*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2        (0x4U << RTC_ALRMASSR_MASKSS_Pos)         /*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3        (0x8U << RTC_ALRMASSR_MASKSS_Pos)         /*!< 0x08000000 */
#define RTC_ALRMASSR_SS_Pos          (0U)                                      
#define RTC_ALRMASSR_SS_Msk          (0x7FFFU << RTC_ALRMASSR_SS_Pos)          /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS              RTC_ALRMASSR_SS_Msk                       

/********************  Bits definition for RTC_BKP0R register  ***************/
#define RTC_BKP0R_Pos                (0U)                                      
#define RTC_BKP0R_Msk                (0xFFFFFFFFU << RTC_BKP0R_Pos)            /*!< 0xFFFFFFFF */
#define RTC_BKP0R                    RTC_BKP0R_Msk                             

/********************  Bits definition for RTC_BKP1R register  ***************/
#define RTC_BKP1R_Pos                (0U)                                      
#define RTC_BKP1R_Msk                (0xFFFFFFFFU << RTC_BKP1R_Pos)            /*!< 0xFFFFFFFF */
#define RTC_BKP1R                    RTC_BKP1R_Msk                             

/********************  Bits definition for RTC_BKP2R register  ***************/
#define RTC_BKP2R_Pos                (0U)                                      
#define RTC_BKP2R_Msk                (0xFFFFFFFFU << RTC_BKP2R_Pos)            /*!< 0xFFFFFFFF */
#define RTC_BKP2R                    RTC_BKP2R_Msk                             

/********************  Bits definition for RTC_BKP3R register  ***************/
#define RTC_BKP3R_Pos                (0U)                                      
#define RTC_BKP3R_Msk                (0xFFFFFFFFU << RTC_BKP3R_Pos)            /*!< 0xFFFFFFFF */
#define RTC_BKP3R                    RTC_BKP3R_Msk                             

/********************  Bits definition for RTC_BKP4R register  ***************/
#define RTC_BKP4R_Pos                (0U)                                      
#define RTC_BKP4R_Msk                (0xFFFFFFFFU << RTC_BKP4R_Pos)            /*!< 0xFFFFFFFF */
#define RTC_BKP4R                    RTC_BKP4R_Msk                             

/******************** Number of backup registers ******************************/
#define RTC_BKP_NUMBER                       0x00000005U

/*****************************************************************************/
/*                                                                           */
/*                        Serial Peripheral Interface (SPI)                  */
/*                                                                           */
/*****************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F0 serie)
 */
#define SPI_I2S_SUPPORT                       /*!< I2S support */

/*******************  Bit definition for SPI_CR1 register  *******************/
#define SPI_CR1_CPHA_Pos            (0U)                                       
#define SPI_CR1_CPHA_Msk            (0x1U << SPI_CR1_CPHA_Pos)                 /*!< 0x00000001 */
#define SPI_CR1_CPHA                SPI_CR1_CPHA_Msk                           /*!< Clock Phase */
#define SPI_CR1_CPOL_Pos            (1U)                                       
#define SPI_CR1_CPOL_Msk            (0x1U << SPI_CR1_CPOL_Pos)                 /*!< 0x00000002 */
#define SPI_CR1_CPOL                SPI_CR1_CPOL_Msk                           /*!< Clock Polarity */
#define SPI_CR1_MSTR_Pos            (2U)                                       
#define SPI_CR1_MSTR_Msk            (0x1U << SPI_CR1_MSTR_Pos)                 /*!< 0x00000004 */
#define SPI_CR1_MSTR                SPI_CR1_MSTR_Msk                           /*!< Master Selection */
#define SPI_CR1_BR_Pos              (3U)                                       
#define SPI_CR1_BR_Msk              (0x7U << SPI_CR1_BR_Pos)                   /*!< 0x00000038 */
#define SPI_CR1_BR                  SPI_CR1_BR_Msk                             /*!< BR[2:0] bits (Baud Rate Control) */
#define SPI_CR1_BR_0                (0x1U << SPI_CR1_BR_Pos)                   /*!< 0x00000008 */
#define SPI_CR1_BR_1                (0x2U << SPI_CR1_BR_Pos)                   /*!< 0x00000010 */
#define SPI_CR1_BR_2                (0x4U << SPI_CR1_BR_Pos)                   /*!< 0x00000020 */
#define SPI_CR1_SPE_Pos             (6U)                                       
#define SPI_CR1_SPE_Msk             (0x1U << SPI_CR1_SPE_Pos)                  /*!< 0x00000040 */
#define SPI_CR1_SPE                 SPI_CR1_SPE_Msk                            /*!< SPI Enable */
#define SPI_CR1_LSBFIRST_Pos        (7U)                                       
#define SPI_CR1_LSBFIRST_Msk        (0x1U << SPI_CR1_LSBFIRST_Pos)             /*!< 0x00000080 */
#define SPI_CR1_LSBFIRST            SPI_CR1_LSBFIRST_Msk                       /*!< Frame Format */
#define SPI_CR1_SSI_Pos             (8U)                                       
#define SPI_CR1_SSI_Msk             (0x1U << SPI_CR1_SSI_Pos)                  /*!< 0x00000100 */
#define SPI_CR1_SSI                 SPI_CR1_SSI_Msk                            /*!< Internal slave select */
#define SPI_CR1_SSM_Pos             (9U)                                       
#define SPI_CR1_SSM_Msk             (0x1U << SPI_CR1_SSM_Pos)                  /*!< 0x00000200 */
#define SPI_CR1_SSM                 SPI_CR1_SSM_Msk                            /*!< Software slave management */
#define SPI_CR1_RXONLY_Pos          (10U)                                      
#define SPI_CR1_RXONLY_Msk          (0x1U << SPI_CR1_RXONLY_Pos)               /*!< 0x00000400 */
#define SPI_CR1_RXONLY              SPI_CR1_RXONLY_Msk                         /*!< Receive only */
#define SPI_CR1_CRCL_Pos            (11U)                                      
#define SPI_CR1_CRCL_Msk            (0x1U << SPI_CR1_CRCL_Pos)                 /*!< 0x00000800 */
#define SPI_CR1_CRCL                SPI_CR1_CRCL_Msk                           /*!< CRC Length */
#define SPI_CR1_CRCNEXT_Pos         (12U)                                      
#define SPI_CR1_CRCNEXT_Msk         (0x1U << SPI_CR1_CRCNEXT_Pos)              /*!< 0x00001000 */
#define SPI_CR1_CRCNEXT             SPI_CR1_CRCNEXT_Msk                        /*!< Transmit CRC next */
#define SPI_CR1_CRCEN_Pos           (13U)                                      
#define SPI_CR1_CRCEN_Msk           (0x1U << SPI_CR1_CRCEN_Pos)                /*!< 0x00002000 */
#define SPI_CR1_CRCEN               SPI_CR1_CRCEN_Msk                          /*!< Hardware CRC calculation enable */
#define SPI_CR1_BIDIOE_Pos          (14U)                                      
#define SPI_CR1_BIDIOE_Msk          (0x1U << SPI_CR1_BIDIOE_Pos)               /*!< 0x00004000 */
#define SPI_CR1_BIDIOE              SPI_CR1_BIDIOE_Msk                         /*!< Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE_Pos        (15U)                                      
#define SPI_CR1_BIDIMODE_Msk        (0x1U << SPI_CR1_BIDIMODE_Pos)             /*!< 0x00008000 */
#define SPI_CR1_BIDIMODE            SPI_CR1_BIDIMODE_Msk                       /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CR2 register  *******************/
#define SPI_CR2_RXDMAEN_Pos         (0U)                                       
#define SPI_CR2_RXDMAEN_Msk         (0x1U << SPI_CR2_RXDMAEN_Pos)              /*!< 0x00000001 */
#define SPI_CR2_RXDMAEN             SPI_CR2_RXDMAEN_Msk                        /*!< Rx Buffer DMA Enable */
#define SPI_CR2_TXDMAEN_Pos         (1U)                                       
#define SPI_CR2_TXDMAEN_Msk         (0x1U << SPI_CR2_TXDMAEN_Pos)              /*!< 0x00000002 */
#define SPI_CR2_TXDMAEN             SPI_CR2_TXDMAEN_Msk                        /*!< Tx Buffer DMA Enable */
#define SPI_CR2_SSOE_Pos            (2U)                                       
#define SPI_CR2_SSOE_Msk            (0x1U << SPI_CR2_SSOE_Pos)                 /*!< 0x00000004 */
#define SPI_CR2_SSOE                SPI_CR2_SSOE_Msk                           /*!< SS Output Enable */
#define SPI_CR2_NSSP_Pos            (3U)                                       
#define SPI_CR2_NSSP_Msk            (0x1U << SPI_CR2_NSSP_Pos)                 /*!< 0x00000008 */
#define SPI_CR2_NSSP                SPI_CR2_NSSP_Msk                           /*!< NSS pulse management Enable */
#define SPI_CR2_FRF_Pos             (4U)                                       
#define SPI_CR2_FRF_Msk             (0x1U << SPI_CR2_FRF_Pos)                  /*!< 0x00000010 */
#define SPI_CR2_FRF                 SPI_CR2_FRF_Msk                            /*!< Frame Format Enable */
#define SPI_CR2_ERRIE_Pos           (5U)                                       
#define SPI_CR2_ERRIE_Msk           (0x1U << SPI_CR2_ERRIE_Pos)                /*!< 0x00000020 */
#define SPI_CR2_ERRIE               SPI_CR2_ERRIE_Msk                          /*!< Error Interrupt Enable */
#define SPI_CR2_RXNEIE_Pos          (6U)                                       
#define SPI_CR2_RXNEIE_Msk          (0x1U << SPI_CR2_RXNEIE_Pos)               /*!< 0x00000040 */
#define SPI_CR2_RXNEIE              SPI_CR2_RXNEIE_Msk                         /*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CR2_TXEIE_Pos           (7U)                                       
#define SPI_CR2_TXEIE_Msk           (0x1U << SPI_CR2_TXEIE_Pos)                /*!< 0x00000080 */
#define SPI_CR2_TXEIE               SPI_CR2_TXEIE_Msk                          /*!< Tx buffer Empty Interrupt Enable */
#define SPI_CR2_DS_Pos              (8U)                                       
#define SPI_CR2_DS_Msk              (0xFU << SPI_CR2_DS_Pos)                   /*!< 0x00000F00 */
#define SPI_CR2_DS                  SPI_CR2_DS_Msk                             /*!< DS[3:0] Data Size */
#define SPI_CR2_DS_0                (0x1U << SPI_CR2_DS_Pos)                   /*!< 0x00000100 */
#define SPI_CR2_DS_1                (0x2U << SPI_CR2_DS_Pos)                   /*!< 0x00000200 */
#define SPI_CR2_DS_2                (0x4U << SPI_CR2_DS_Pos)                   /*!< 0x00000400 */
#define SPI_CR2_DS_3                (0x8U << SPI_CR2_DS_Pos)                   /*!< 0x00000800 */
#define SPI_CR2_FRXTH_Pos           (12U)                                      
#define SPI_CR2_FRXTH_Msk           (0x1U << SPI_CR2_FRXTH_Pos)                /*!< 0x00001000 */
#define SPI_CR2_FRXTH               SPI_CR2_FRXTH_Msk                          /*!< FIFO reception Threshold */
#define SPI_CR2_LDMARX_Pos          (13U)                                      
#define SPI_CR2_LDMARX_Msk          (0x1U << SPI_CR2_LDMARX_Pos)               /*!< 0x00002000 */
#define SPI_CR2_LDMARX              SPI_CR2_LDMARX_Msk                         /*!< Last DMA transfer for reception */
#define SPI_CR2_LDMATX_Pos          (14U)                                      
#define SPI_CR2_LDMATX_Msk          (0x1U << SPI_CR2_LDMATX_Pos)               /*!< 0x00004000 */
#define SPI_CR2_LDMATX              SPI_CR2_LDMATX_Msk                         /*!< Last DMA transfer for transmission */

/********************  Bit definition for SPI_SR register  *******************/
#define SPI_SR_RXNE_Pos             (0U)                                       
#define SPI_SR_RXNE_Msk             (0x1U << SPI_SR_RXNE_Pos)                  /*!< 0x00000001 */
#define SPI_SR_RXNE                 SPI_SR_RXNE_Msk                            /*!< Receive buffer Not Empty */
#define SPI_SR_TXE_Pos              (1U)                                       
#define SPI_SR_TXE_Msk              (0x1U << SPI_SR_TXE_Pos)                   /*!< 0x00000002 */
#define SPI_SR_TXE                  SPI_SR_TXE_Msk                             /*!< Transmit buffer Empty */
#define SPI_SR_CHSIDE_Pos           (2U)                                       
#define SPI_SR_CHSIDE_Msk           (0x1U << SPI_SR_CHSIDE_Pos)                /*!< 0x00000004 */
#define SPI_SR_CHSIDE               SPI_SR_CHSIDE_Msk                          /*!< Channel side */
#define SPI_SR_UDR_Pos              (3U)                                       
#define SPI_SR_UDR_Msk              (0x1U << SPI_SR_UDR_Pos)                   /*!< 0x00000008 */
#define SPI_SR_UDR                  SPI_SR_UDR_Msk                             /*!< Underrun flag */
#define SPI_SR_CRCERR_Pos           (4U)                                       
#define SPI_SR_CRCERR_Msk           (0x1U << SPI_SR_CRCERR_Pos)                /*!< 0x00000010 */
#define SPI_SR_CRCERR               SPI_SR_CRCERR_Msk                          /*!< CRC Error flag */
#define SPI_SR_MODF_Pos             (5U)                                       
#define SPI_SR_MODF_Msk             (0x1U << SPI_SR_MODF_Pos)                  /*!< 0x00000020 */
#define SPI_SR_MODF                 SPI_SR_MODF_Msk                            /*!< Mode fault */
#define SPI_SR_OVR_Pos              (6U)                                       
#define SPI_SR_OVR_Msk              (0x1U << SPI_SR_OVR_Pos)                   /*!< 0x00000040 */
#define SPI_SR_OVR                  SPI_SR_OVR_Msk                             /*!< Overrun flag */
#define SPI_SR_BSY_Pos              (7U)                                       
#define SPI_SR_BSY_Msk              (0x1U << SPI_SR_BSY_Pos)                   /*!< 0x00000080 */
#define SPI_SR_BSY                  SPI_SR_BSY_Msk                             /*!< Busy flag */
#define SPI_SR_FRE_Pos              (8U)                                       
#define SPI_SR_FRE_Msk              (0x1U << SPI_SR_FRE_Pos)                   /*!< 0x00000100 */
#define SPI_SR_FRE                  SPI_SR_FRE_Msk                             /*!< TI frame format error */
#define SPI_SR_FRLVL_Pos            (9U)                                       
#define SPI_SR_FRLVL_Msk            (0x3U << SPI_SR_FRLVL_Pos)                 /*!< 0x00000600 */
#define SPI_SR_FRLVL                SPI_SR_FRLVL_Msk                           /*!< FIFO Reception Level */
#define SPI_SR_FRLVL_0              (0x1U << SPI_SR_FRLVL_Pos)                 /*!< 0x00000200 */
#define SPI_SR_FRLVL_1              (0x2U << SPI_SR_FRLVL_Pos)                 /*!< 0x00000400 */
#define SPI_SR_FTLVL_Pos            (11U)                                      
#define SPI_SR_FTLVL_Msk            (0x3U << SPI_SR_FTLVL_Pos)                 /*!< 0x00001800 */
#define SPI_SR_FTLVL                SPI_SR_FTLVL_Msk                           /*!< FIFO Transmission Level */
#define SPI_SR_FTLVL_0              (0x1U << SPI_SR_FTLVL_Pos)                 /*!< 0x00000800 */
#define SPI_SR_FTLVL_1              (0x2U << SPI_SR_FTLVL_Pos)                 /*!< 0x00001000 */

/********************  Bit definition for SPI_DR register  *******************/
#define SPI_DR_DR_Pos               (0U)                                       
#define SPI_DR_DR_Msk               (0xFFFFFFFFU << SPI_DR_DR_Pos)             /*!< 0xFFFFFFFF */
#define SPI_DR_DR                   SPI_DR_DR_Msk                              /*!< Data Register */

/*******************  Bit definition for SPI_CRCPR register  *****************/
#define SPI_CRCPR_CRCPOLY_Pos       (0U)                                       
#define SPI_CRCPR_CRCPOLY_Msk       (0xFFFFFFFFU << SPI_CRCPR_CRCPOLY_Pos)     /*!< 0xFFFFFFFF */
#define SPI_CRCPR_CRCPOLY           SPI_CRCPR_CRCPOLY_Msk                      /*!< CRC polynomial register */

/******************  Bit definition for SPI_RXCRCR register  *****************/
#define SPI_RXCRCR_RXCRC_Pos        (0U)                                       
#define SPI_RXCRCR_RXCRC_Msk        (0xFFFFFFFFU << SPI_RXCRCR_RXCRC_Pos)      /*!< 0xFFFFFFFF */
#define SPI_RXCRCR_RXCRC            SPI_RXCRCR_RXCRC_Msk                       /*!< Rx CRC Register */

/******************  Bit definition for SPI_TXCRCR register  *****************/
#define SPI_TXCRCR_TXCRC_Pos        (0U)                                       
#define SPI_TXCRCR_TXCRC_Msk        (0xFFFFFFFFU << SPI_TXCRCR_TXCRC_Pos)      /*!< 0xFFFFFFFF */
#define SPI_TXCRCR_TXCRC            SPI_TXCRCR_TXCRC_Msk                       /*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCFGR register  ****************/
#define SPI_I2SCFGR_CHLEN_Pos       (0U)                                       
#define SPI_I2SCFGR_CHLEN_Msk       (0x1U << SPI_I2SCFGR_CHLEN_Pos)            /*!< 0x00000001 */
#define SPI_I2SCFGR_CHLEN           SPI_I2SCFGR_CHLEN_Msk                      /*!<Channel length (number of bits per audio channel) */
#define SPI_I2SCFGR_DATLEN_Pos      (1U)                                       
#define SPI_I2SCFGR_DATLEN_Msk      (0x3U << SPI_I2SCFGR_DATLEN_Pos)           /*!< 0x00000006 */
#define SPI_I2SCFGR_DATLEN          SPI_I2SCFGR_DATLEN_Msk                     /*!<DATLEN[1:0] bits (Data length to be transferred) */
#define SPI_I2SCFGR_DATLEN_0        (0x1U << SPI_I2SCFGR_DATLEN_Pos)           /*!< 0x00000002 */
#define SPI_I2SCFGR_DATLEN_1        (0x2U << SPI_I2SCFGR_DATLEN_Pos)           /*!< 0x00000004 */
#define SPI_I2SCFGR_CKPOL_Pos       (3U)                                       
#define SPI_I2SCFGR_CKPOL_Msk       (0x1U << SPI_I2SCFGR_CKPOL_Pos)            /*!< 0x00000008 */
#define SPI_I2SCFGR_CKPOL           SPI_I2SCFGR_CKPOL_Msk                      /*!<steady state clock polarity */
#define SPI_I2SCFGR_I2SSTD_Pos      (4U)                                       
#define SPI_I2SCFGR_I2SSTD_Msk      (0x3U << SPI_I2SCFGR_I2SSTD_Pos)           /*!< 0x00000030 */
#define SPI_I2SCFGR_I2SSTD          SPI_I2SCFGR_I2SSTD_Msk                     /*!<I2SSTD[1:0] bits (I2S standard selection) */
#define SPI_I2SCFGR_I2SSTD_0        (0x1U << SPI_I2SCFGR_I2SSTD_Pos)           /*!< 0x00000010 */
#define SPI_I2SCFGR_I2SSTD_1        (0x2U << SPI_I2SCFGR_I2SSTD_Pos)           /*!< 0x00000020 */
#define SPI_I2SCFGR_PCMSYNC_Pos     (7U)                                       
#define SPI_I2SCFGR_PCMSYNC_Msk     (0x1U << SPI_I2SCFGR_PCMSYNC_Pos)          /*!< 0x00000080 */
#define SPI_I2SCFGR_PCMSYNC         SPI_I2SCFGR_PCMSYNC_Msk                    /*!<PCM frame synchronization */
#define SPI_I2SCFGR_I2SCFG_Pos      (8U)                                       
#define SPI_I2SCFGR_I2SCFG_Msk      (0x3U << SPI_I2SCFGR_I2SCFG_Pos)           /*!< 0x00000300 */
#define SPI_I2SCFGR_I2SCFG          SPI_I2SCFGR_I2SCFG_Msk                     /*!<I2SCFG[1:0] bits (I2S configuration mode) */
#define SPI_I2SCFGR_I2SCFG_0        (0x1U << SPI_I2SCFGR_I2SCFG_Pos)           /*!< 0x00000100 */
#define SPI_I2SCFGR_I2SCFG_1        (0x2U << SPI_I2SCFGR_I2SCFG_Pos)           /*!< 0x00000200 */
#define SPI_I2SCFGR_I2SE_Pos        (10U)                                      
#define SPI_I2SCFGR_I2SE_Msk        (0x1U << SPI_I2SCFGR_I2SE_Pos)             /*!< 0x00000400 */
#define SPI_I2SCFGR_I2SE            SPI_I2SCFGR_I2SE_Msk                       /*!<I2S Enable */
#define SPI_I2SCFGR_I2SMOD_Pos      (11U)                                      
#define SPI_I2SCFGR_I2SMOD_Msk      (0x1U << SPI_I2SCFGR_I2SMOD_Pos)           /*!< 0x00000800 */
#define SPI_I2SCFGR_I2SMOD          SPI_I2SCFGR_I2SMOD_Msk                     /*!<I2S mode selection */

/******************  Bit definition for SPI_I2SPR register  ******************/
#define SPI_I2SPR_I2SDIV_Pos        (0U)                                       
#define SPI_I2SPR_I2SDIV_Msk        (0xFFU << SPI_I2SPR_I2SDIV_Pos)            /*!< 0x000000FF */
#define SPI_I2SPR_I2SDIV            SPI_I2SPR_I2SDIV_Msk                       /*!<I2S Linear prescaler */
#define SPI_I2SPR_ODD_Pos           (8U)                                       
#define SPI_I2SPR_ODD_Msk           (0x1U << SPI_I2SPR_ODD_Pos)                /*!< 0x00000100 */
#define SPI_I2SPR_ODD               SPI_I2SPR_ODD_Msk                          /*!<Odd factor for the prescaler */
#define SPI_I2SPR_MCKOE_Pos         (9U)                                       
#define SPI_I2SPR_MCKOE_Msk         (0x1U << SPI_I2SPR_MCKOE_Pos)              /*!< 0x00000200 */
#define SPI_I2SPR_MCKOE             SPI_I2SPR_MCKOE_Msk                        /*!<Master Clock Output Enable */

/*****************************************************************************/
/*                                                                           */
/*                       System Configuration (SYSCFG)                       */
/*                                                                           */
/*****************************************************************************/

/******  RCC_CFGR Definition *********************************************************************************/

#if defined(STM32F030x6)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */
#elif defined(STM32F030x8)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */

#elif defined(STM32F030xC)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */


#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F031x6)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F038xx)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F042x6)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR1_PA11_PA12_RMP_Pos       (4U)                              
#define SYSCFG_CFGR1_PA11_PA12_RMP_Msk       (0x1U << SYSCFG_CFGR1_PA11_PA12_RMP_Pos) /*!< 0x00000010 */
#define SYSCFG_CFGR1_PA11_PA12_RMP           SYSCFG_CFGR1_PA11_PA12_RMP_Msk    /*!< PA11 and PA12 remap on QFN28 and TSSOP20 packages */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F048xx)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR1_PA11_PA12_RMP_Pos       (4U)                              
#define SYSCFG_CFGR1_PA11_PA12_RMP_Msk       (0x1U << SYSCFG_CFGR1_PA11_PA12_RMP_Pos) /*!< 0x00000010 */
#define SYSCFG_CFGR1_PA11_PA12_RMP           SYSCFG_CFGR1_PA11_PA12_RMP_Msk    /*!< PA11 and PA12 remap on QFN28 and TSSOP20 packages */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F051x8)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */

#elif defined(STM32F058xx)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */

#elif defined(STM32F070x6)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR1_PA11_PA12_RMP_Pos       (4U)                              
#define SYSCFG_CFGR1_PA11_PA12_RMP_Msk       (0x1U << SYSCFG_CFGR1_PA11_PA12_RMP_Pos) /*!< 0x00000010 */
#define SYSCFG_CFGR1_PA11_PA12_RMP           SYSCFG_CFGR1_PA11_PA12_RMP_Msk    /*!< PA11 and PA12 remap on QFN28 and TSSOP20 packages */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x00001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F070xB)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x4001FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x04001F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_USART3_DMA_RMP_Pos      (26U)                             
#define SYSCFG_CFGR1_USART3_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART3_DMA_RMP_Pos) /*!< 0x04000000 */
#define SYSCFG_CFGR1_USART3_DMA_RMP          SYSCFG_CFGR1_USART3_DMA_RMP_Msk   /*!< USART3 DMA remap  */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */

#elif defined(STM32F071xB)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x7F007FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x7F007F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2_Pos      (13U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP2_Msk      (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP2_Pos) /*!< 0x00002000 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2          SYSCFG_CFGR1_TIM16_DMA_RMP2_Msk   /*!< Timer 16 DMA remap 2  */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2_Pos      (14U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP2_Msk      (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP2_Pos) /*!< 0x00004000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2          SYSCFG_CFGR1_TIM17_DMA_RMP2_Msk   /*!< Timer 17 DMA remap 2  */
#define SYSCFG_CFGR1_SPI2_DMA_RMP_Pos        (24U)                             
#define SYSCFG_CFGR1_SPI2_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_SPI2_DMA_RMP_Pos) /*!< 0x01000000 */
#define SYSCFG_CFGR1_SPI2_DMA_RMP            SYSCFG_CFGR1_SPI2_DMA_RMP_Msk     /*!< SPI2 DMA remap  */
#define SYSCFG_CFGR1_USART2_DMA_RMP_Pos      (25U)                             
#define SYSCFG_CFGR1_USART2_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART2_DMA_RMP_Pos) /*!< 0x02000000 */
#define SYSCFG_CFGR1_USART2_DMA_RMP          SYSCFG_CFGR1_USART2_DMA_RMP_Msk   /*!< USART2 DMA remap  */
#define SYSCFG_CFGR1_USART3_DMA_RMP_Pos      (26U)                             
#define SYSCFG_CFGR1_USART3_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART3_DMA_RMP_Pos) /*!< 0x04000000 */
#define SYSCFG_CFGR1_USART3_DMA_RMP          SYSCFG_CFGR1_USART3_DMA_RMP_Msk   /*!< USART3 DMA remap  */
#define SYSCFG_CFGR1_I2C1_DMA_RMP_Pos        (27U)                             
#define SYSCFG_CFGR1_I2C1_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_I2C1_DMA_RMP_Pos) /*!< 0x08000000 */
#define SYSCFG_CFGR1_I2C1_DMA_RMP            SYSCFG_CFGR1_I2C1_DMA_RMP_Msk     /*!< I2C1 DMA remap  */
#define SYSCFG_CFGR1_TIM1_DMA_RMP_Pos        (28U)                             
#define SYSCFG_CFGR1_TIM1_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM1_DMA_RMP_Pos) /*!< 0x10000000 */
#define SYSCFG_CFGR1_TIM1_DMA_RMP            SYSCFG_CFGR1_TIM1_DMA_RMP_Msk     /*!< TIM1 DMA remap  */
#define SYSCFG_CFGR1_TIM2_DMA_RMP_Pos        (29U)                             
#define SYSCFG_CFGR1_TIM2_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM2_DMA_RMP_Pos) /*!< 0x20000000 */
#define SYSCFG_CFGR1_TIM2_DMA_RMP            SYSCFG_CFGR1_TIM2_DMA_RMP_Msk     /*!< TIM2 DMA remap  */
#define SYSCFG_CFGR1_TIM3_DMA_RMP_Pos        (30U)                             
#define SYSCFG_CFGR1_TIM3_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM3_DMA_RMP_Pos) /*!< 0x40000000 */
#define SYSCFG_CFGR1_TIM3_DMA_RMP            SYSCFG_CFGR1_TIM3_DMA_RMP_Msk     /*!< TIM3 DMA remap  */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */

#elif defined(STM32F072xB)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x7F007FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x7F007F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2_Pos      (13U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP2_Msk      (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP2_Pos) /*!< 0x00002000 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2          SYSCFG_CFGR1_TIM16_DMA_RMP2_Msk   /*!< Timer 16 DMA remap 2  */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2_Pos      (14U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP2_Msk      (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP2_Pos) /*!< 0x00004000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2          SYSCFG_CFGR1_TIM17_DMA_RMP2_Msk   /*!< Timer 17 DMA remap 2  */
#define SYSCFG_CFGR1_SPI2_DMA_RMP_Pos        (24U)                             
#define SYSCFG_CFGR1_SPI2_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_SPI2_DMA_RMP_Pos) /*!< 0x01000000 */
#define SYSCFG_CFGR1_SPI2_DMA_RMP            SYSCFG_CFGR1_SPI2_DMA_RMP_Msk     /*!< SPI2 DMA remap  */
#define SYSCFG_CFGR1_USART2_DMA_RMP_Pos      (25U)                             
#define SYSCFG_CFGR1_USART2_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART2_DMA_RMP_Pos) /*!< 0x02000000 */
#define SYSCFG_CFGR1_USART2_DMA_RMP          SYSCFG_CFGR1_USART2_DMA_RMP_Msk   /*!< USART2 DMA remap  */
#define SYSCFG_CFGR1_USART3_DMA_RMP_Pos      (26U)                             
#define SYSCFG_CFGR1_USART3_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART3_DMA_RMP_Pos) /*!< 0x04000000 */
#define SYSCFG_CFGR1_USART3_DMA_RMP          SYSCFG_CFGR1_USART3_DMA_RMP_Msk   /*!< USART3 DMA remap  */
#define SYSCFG_CFGR1_I2C1_DMA_RMP_Pos        (27U)                             
#define SYSCFG_CFGR1_I2C1_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_I2C1_DMA_RMP_Pos) /*!< 0x08000000 */
#define SYSCFG_CFGR1_I2C1_DMA_RMP            SYSCFG_CFGR1_I2C1_DMA_RMP_Msk     /*!< I2C1 DMA remap  */
#define SYSCFG_CFGR1_TIM1_DMA_RMP_Pos        (28U)                             
#define SYSCFG_CFGR1_TIM1_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM1_DMA_RMP_Pos) /*!< 0x10000000 */
#define SYSCFG_CFGR1_TIM1_DMA_RMP            SYSCFG_CFGR1_TIM1_DMA_RMP_Msk     /*!< TIM1 DMA remap  */
#define SYSCFG_CFGR1_TIM2_DMA_RMP_Pos        (29U)                             
#define SYSCFG_CFGR1_TIM2_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM2_DMA_RMP_Pos) /*!< 0x20000000 */
#define SYSCFG_CFGR1_TIM2_DMA_RMP            SYSCFG_CFGR1_TIM2_DMA_RMP_Msk     /*!< TIM2 DMA remap  */
#define SYSCFG_CFGR1_TIM3_DMA_RMP_Pos        (30U)                             
#define SYSCFG_CFGR1_TIM3_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM3_DMA_RMP_Pos) /*!< 0x40000000 */
#define SYSCFG_CFGR1_TIM3_DMA_RMP            SYSCFG_CFGR1_TIM3_DMA_RMP_Msk     /*!< TIM3 DMA remap  */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */

#elif defined(STM32F078xx)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */

#define SYSCFG_CFGR1_DMA_RMP_Pos             (8U)                              
#define SYSCFG_CFGR1_DMA_RMP_Msk             (0x7F007FU << SYSCFG_CFGR1_DMA_RMP_Pos) /*!< 0x7F007F00 */
#define SYSCFG_CFGR1_DMA_RMP                 SYSCFG_CFGR1_DMA_RMP_Msk          /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC_DMA_RMP_Pos         (8U)                              
#define SYSCFG_CFGR1_ADC_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_ADC_DMA_RMP_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR1_ADC_DMA_RMP             SYSCFG_CFGR1_ADC_DMA_RMP_Msk      /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos    (9U)                              
#define SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos) /*!< 0x00000200 */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP        SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos    (10U)                             
#define SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk    (0x1U << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos) /*!< 0x00000400 */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP        SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos       (11U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos) /*!< 0x00000800 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP           SYSCFG_CFGR1_TIM16_DMA_RMP_Msk    /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos       (12U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk       (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos) /*!< 0x00001000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP           SYSCFG_CFGR1_TIM17_DMA_RMP_Msk    /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2_Pos      (13U)                             
#define SYSCFG_CFGR1_TIM16_DMA_RMP2_Msk      (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP2_Pos) /*!< 0x00002000 */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2          SYSCFG_CFGR1_TIM16_DMA_RMP2_Msk   /*!< Timer 16 DMA remap 2  */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2_Pos      (14U)                             
#define SYSCFG_CFGR1_TIM17_DMA_RMP2_Msk      (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP2_Pos) /*!< 0x00004000 */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2          SYSCFG_CFGR1_TIM17_DMA_RMP2_Msk   /*!< Timer 17 DMA remap 2  */
#define SYSCFG_CFGR1_SPI2_DMA_RMP_Pos        (24U)                             
#define SYSCFG_CFGR1_SPI2_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_SPI2_DMA_RMP_Pos) /*!< 0x01000000 */
#define SYSCFG_CFGR1_SPI2_DMA_RMP            SYSCFG_CFGR1_SPI2_DMA_RMP_Msk     /*!< SPI2 DMA remap  */
#define SYSCFG_CFGR1_USART2_DMA_RMP_Pos      (25U)                             
#define SYSCFG_CFGR1_USART2_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART2_DMA_RMP_Pos) /*!< 0x02000000 */
#define SYSCFG_CFGR1_USART2_DMA_RMP          SYSCFG_CFGR1_USART2_DMA_RMP_Msk   /*!< USART2 DMA remap  */
#define SYSCFG_CFGR1_USART3_DMA_RMP_Pos      (26U)                             
#define SYSCFG_CFGR1_USART3_DMA_RMP_Msk      (0x1U << SYSCFG_CFGR1_USART3_DMA_RMP_Pos) /*!< 0x04000000 */
#define SYSCFG_CFGR1_USART3_DMA_RMP          SYSCFG_CFGR1_USART3_DMA_RMP_Msk   /*!< USART3 DMA remap  */
#define SYSCFG_CFGR1_I2C1_DMA_RMP_Pos        (27U)                             
#define SYSCFG_CFGR1_I2C1_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_I2C1_DMA_RMP_Pos) /*!< 0x08000000 */
#define SYSCFG_CFGR1_I2C1_DMA_RMP            SYSCFG_CFGR1_I2C1_DMA_RMP_Msk     /*!< I2C1 DMA remap  */
#define SYSCFG_CFGR1_TIM1_DMA_RMP_Pos        (28U)                             
#define SYSCFG_CFGR1_TIM1_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM1_DMA_RMP_Pos) /*!< 0x10000000 */
#define SYSCFG_CFGR1_TIM1_DMA_RMP            SYSCFG_CFGR1_TIM1_DMA_RMP_Msk     /*!< TIM1 DMA remap  */
#define SYSCFG_CFGR1_TIM2_DMA_RMP_Pos        (29U)                             
#define SYSCFG_CFGR1_TIM2_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM2_DMA_RMP_Pos) /*!< 0x20000000 */
#define SYSCFG_CFGR1_TIM2_DMA_RMP            SYSCFG_CFGR1_TIM2_DMA_RMP_Msk     /*!< TIM2 DMA remap  */
#define SYSCFG_CFGR1_TIM3_DMA_RMP_Pos        (30U)                             
#define SYSCFG_CFGR1_TIM3_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR1_TIM3_DMA_RMP_Pos) /*!< 0x40000000 */
#define SYSCFG_CFGR1_TIM3_DMA_RMP            SYSCFG_CFGR1_TIM3_DMA_RMP_Msk     /*!< TIM3 DMA remap  */

#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */

#elif defined(STM32F091xC)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR1_IR_MOD_Pos              (6U)                              
#define SYSCFG_CFGR1_IR_MOD_Msk              (0x3U << SYSCFG_CFGR1_IR_MOD_Pos) /*!< 0x000000C0 */
#define SYSCFG_CFGR1_IR_MOD                  SYSCFG_CFGR1_IR_MOD_Msk           /*!< IR_MOD config */
#define SYSCFG_CFGR1_IR_MOD_0                (0x1U << SYSCFG_CFGR1_IR_MOD_Pos) /*!< 0x00000040 */
#define SYSCFG_CFGR1_IR_MOD_1                (0x2U << SYSCFG_CFGR1_IR_MOD_Pos) /*!< 0x00000080 */

/* Alias for legacy purposes */
#define SYSCFG_CFGR1_IRDA_ENV_SEL            SYSCFG_CFGR1_IR_MOD 
#define SYSCFG_CFGR1_IRDA_ENV_SEL_0          SYSCFG_CFGR1_IR_MOD_0
#define SYSCFG_CFGR1_IRDA_ENV_SEL_1          SYSCFG_CFGR1_IR_MOD_1



#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#elif defined(STM32F098xx)
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE_Pos            (0U)                              
#define SYSCFG_CFGR1_MEM_MODE_Msk            (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000003 */
#define SYSCFG_CFGR1_MEM_MODE                SYSCFG_CFGR1_MEM_MODE_Msk           /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0              (0x1U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE_1              (0x2U << SYSCFG_CFGR1_MEM_MODE_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR1_IR_MOD_Pos              (6U)                              
#define SYSCFG_CFGR1_IR_MOD_Msk              (0x3U << SYSCFG_CFGR1_IR_MOD_Pos) /*!< 0x000000C0 */
#define SYSCFG_CFGR1_IR_MOD                  SYSCFG_CFGR1_IR_MOD_Msk           /*!< IR_MOD config */
#define SYSCFG_CFGR1_IR_MOD_0                (0x1U << SYSCFG_CFGR1_IR_MOD_Pos) /*!< 0x00000040 */
#define SYSCFG_CFGR1_IR_MOD_1                (0x2U << SYSCFG_CFGR1_IR_MOD_Pos) /*!< 0x00000080 */

/* Alias for legacy purposes */
#define SYSCFG_CFGR1_IRDA_ENV_SEL            SYSCFG_CFGR1_IR_MOD 
#define SYSCFG_CFGR1_IRDA_ENV_SEL_0          SYSCFG_CFGR1_IR_MOD_0
#define SYSCFG_CFGR1_IRDA_ENV_SEL_1          SYSCFG_CFGR1_IR_MOD_1



#define SYSCFG_CFGR1_I2C_FMP_PB6_Pos         (16U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB6_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB6_Pos) /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_FMP_PB6             SYSCFG_CFGR1_I2C_FMP_PB6_Msk      /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7_Pos         (17U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB7_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB7_Pos) /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_FMP_PB7             SYSCFG_CFGR1_I2C_FMP_PB7_Msk      /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8_Pos         (18U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB8_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB8_Pos) /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_FMP_PB8             SYSCFG_CFGR1_I2C_FMP_PB8_Msk      /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9_Pos         (19U)                             
#define SYSCFG_CFGR1_I2C_FMP_PB9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PB9_Pos) /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_FMP_PB9             SYSCFG_CFGR1_I2C_FMP_PB9_Msk      /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Pos        (20U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C1_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos) /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C1            SYSCFG_CFGR1_I2C_FMP_I2C1_Msk     /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7  */
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Pos        (21U)                             
#define SYSCFG_CFGR1_I2C_FMP_I2C2_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_I2C2_Pos) /*!< 0x00200000 */
#define SYSCFG_CFGR1_I2C_FMP_I2C2            SYSCFG_CFGR1_I2C_FMP_I2C2_Msk     /*!< Enable I2C2 Fast mode plus  */
#define SYSCFG_CFGR1_I2C_FMP_PA9_Pos         (22U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA9_Msk         (0x1U << SYSCFG_CFGR1_I2C_FMP_PA9_Pos) /*!< 0x00400000 */
#define SYSCFG_CFGR1_I2C_FMP_PA9             SYSCFG_CFGR1_I2C_FMP_PA9_Msk      /*!< Enable Fast Mode Plus on PA9  */
#define SYSCFG_CFGR1_I2C_FMP_PA10_Pos        (23U)                             
#define SYSCFG_CFGR1_I2C_FMP_PA10_Msk        (0x1U << SYSCFG_CFGR1_I2C_FMP_PA10_Pos) /*!< 0x00800000 */
#define SYSCFG_CFGR1_I2C_FMP_PA10            SYSCFG_CFGR1_I2C_FMP_PA10_Msk     /*!< Enable Fast Mode Plus on PA10 */

#endif


/*****************  Bit definition for SYSCFG_EXTICR1 register  **************/
#define SYSCFG_EXTICR1_EXTI0_Pos             (0U)                              
#define SYSCFG_EXTICR1_EXTI0_Msk             (0xFU << SYSCFG_EXTICR1_EXTI0_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR1_EXTI0                 SYSCFG_EXTICR1_EXTI0_Msk          /*!< EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1_Pos             (4U)                              
#define SYSCFG_EXTICR1_EXTI1_Msk             (0xFU << SYSCFG_EXTICR1_EXTI1_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR1_EXTI1                 SYSCFG_EXTICR1_EXTI1_Msk          /*!< EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2_Pos             (8U)                              
#define SYSCFG_EXTICR1_EXTI2_Msk             (0xFU << SYSCFG_EXTICR1_EXTI2_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR1_EXTI2                 SYSCFG_EXTICR1_EXTI2_Msk          /*!< EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3_Pos             (12U)                             
#define SYSCFG_EXTICR1_EXTI3_Msk             (0xFU << SYSCFG_EXTICR1_EXTI3_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR1_EXTI3                 SYSCFG_EXTICR1_EXTI3_Msk          /*!< EXTI 3 configuration */

/** 
  * @brief  EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA              (0x00000000U)                     /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB              (0x00000001U)                     /*!< PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC              (0x00000002U)                     /*!< PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD              (0x00000003U)                     /*!< PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE              (0x00000004U)                     /*!< PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF              (0x00000005U)                     /*!< PF[0] pin */

/** 
  * @brief  EXTI1 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI1_PA              (0x00000000U)                     /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB              (0x00000010U)                     /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC              (0x00000020U)                     /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD              (0x00000030U)                     /*!< PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE              (0x00000040U)                     /*!< PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF              (0x00000050U)                     /*!< PF[1] pin */

/** 
  * @brief  EXTI2 configuration  
  */
#define SYSCFG_EXTICR1_EXTI2_PA              (0x00000000U)                     /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB              (0x00000100U)                     /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC              (0x00000200U)                     /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD              (0x00000300U)                     /*!< PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE              (0x00000400U)                     /*!< PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF              (0x00000500U)                     /*!< PF[2] pin */

/** 
  * @brief  EXTI3 configuration  
  */
#define SYSCFG_EXTICR1_EXTI3_PA              (0x00000000U)                     /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB              (0x00001000U)                     /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC              (0x00002000U)                     /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD              (0x00003000U)                     /*!< PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE              (0x00004000U)                     /*!< PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF              (0x00005000U)                     /*!< PF[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  **************/
#define SYSCFG_EXTICR2_EXTI4_Pos             (0U)                              
#define SYSCFG_EXTICR2_EXTI4_Msk             (0xFU << SYSCFG_EXTICR2_EXTI4_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR2_EXTI4                 SYSCFG_EXTICR2_EXTI4_Msk          /*!< EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5_Pos             (4U)                              
#define SYSCFG_EXTICR2_EXTI5_Msk             (0xFU << SYSCFG_EXTICR2_EXTI5_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR2_EXTI5                 SYSCFG_EXTICR2_EXTI5_Msk          /*!< EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6_Pos             (8U)                              
#define SYSCFG_EXTICR2_EXTI6_Msk             (0xFU << SYSCFG_EXTICR2_EXTI6_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR2_EXTI6                 SYSCFG_EXTICR2_EXTI6_Msk          /*!< EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7_Pos             (12U)                             
#define SYSCFG_EXTICR2_EXTI7_Msk             (0xFU << SYSCFG_EXTICR2_EXTI7_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR2_EXTI7                 SYSCFG_EXTICR2_EXTI7_Msk          /*!< EXTI 7 configuration */

/** 
  * @brief  EXTI4 configuration  
  */
#define SYSCFG_EXTICR2_EXTI4_PA              (0x00000000U)                     /*!< PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB              (0x00000001U)                     /*!< PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC              (0x00000002U)                     /*!< PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD              (0x00000003U)                     /*!< PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE              (0x00000004U)                     /*!< PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF              (0x00000005U)                     /*!< PF[4] pin */

/** 
  * @brief  EXTI5 configuration  
  */
#define SYSCFG_EXTICR2_EXTI5_PA              (0x00000000U)                     /*!< PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB              (0x00000010U)                     /*!< PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC              (0x00000020U)                     /*!< PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD              (0x00000030U)                     /*!< PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE              (0x00000040U)                     /*!< PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF              (0x00000050U)                     /*!< PF[5] pin */

/** 
  * @brief  EXTI6 configuration  
  */
#define SYSCFG_EXTICR2_EXTI6_PA              (0x00000000U)                     /*!< PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB              (0x00000100U)                     /*!< PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC              (0x00000200U)                     /*!< PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD              (0x00000300U)                     /*!< PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE              (0x00000400U)                     /*!< PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF              (0x00000500U)                     /*!< PF[6] pin */

/** 
  * @brief  EXTI7 configuration  
  */
#define SYSCFG_EXTICR2_EXTI7_PA              (0x00000000U)                     /*!< PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB              (0x00001000U)                     /*!< PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC              (0x00002000U)                     /*!< PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD              (0x00003000U)                     /*!< PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE              (0x00004000U)                     /*!< PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF              (0x00005000U)                     /*!< PF[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  **************/
#define SYSCFG_EXTICR3_EXTI8_Pos             (0U)                              
#define SYSCFG_EXTICR3_EXTI8_Msk             (0xFU << SYSCFG_EXTICR3_EXTI8_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR3_EXTI8                 SYSCFG_EXTICR3_EXTI8_Msk          /*!< EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9_Pos             (4U)                              
#define SYSCFG_EXTICR3_EXTI9_Msk             (0xFU << SYSCFG_EXTICR3_EXTI9_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR3_EXTI9                 SYSCFG_EXTICR3_EXTI9_Msk          /*!< EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10_Pos            (8U)                              
#define SYSCFG_EXTICR3_EXTI10_Msk            (0xFU << SYSCFG_EXTICR3_EXTI10_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR3_EXTI10                SYSCFG_EXTICR3_EXTI10_Msk         /*!< EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11_Pos            (12U)                             
#define SYSCFG_EXTICR3_EXTI11_Msk            (0xFU << SYSCFG_EXTICR3_EXTI11_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR3_EXTI11                SYSCFG_EXTICR3_EXTI11_Msk         /*!< EXTI 11 configuration */

/** 
  * @brief  EXTI8 configuration  
  */
#define SYSCFG_EXTICR3_EXTI8_PA              (0x00000000U)                     /*!< PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB              (0x00000001U)                     /*!< PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC              (0x00000002U)                     /*!< PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD              (0x00000003U)                     /*!< PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE              (0x00000004U)                     /*!< PE[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PF              (0x00000005U)                     /*!< PF[8] pin */


/** 
  * @brief  EXTI9 configuration  
  */
#define SYSCFG_EXTICR3_EXTI9_PA              (0x00000000U)                     /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB              (0x00000010U)                     /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC              (0x00000020U)                     /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD              (0x00000030U)                     /*!< PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE              (0x00000040U)                     /*!< PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF              (0x00000050U)                     /*!< PF[9] pin */

/** 
  * @brief  EXTI10 configuration  
  */
#define SYSCFG_EXTICR3_EXTI10_PA             (0x00000000U)                     /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB             (0x00000100U)                     /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC             (0x00000200U)                     /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD             (0x00000300U)                     /*!< PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE             (0x00000400U)                     /*!< PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF             (0x00000500U)                     /*!< PF[10] pin */

/** 
  * @brief  EXTI11 configuration  
  */
#define SYSCFG_EXTICR3_EXTI11_PA             (0x00000000U)                     /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB             (0x00001000U)                     /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC             (0x00002000U)                     /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD             (0x00003000U)                     /*!< PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE             (0x00004000U)                     /*!< PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF             (0x00005000U)                     /*!< PF[11] pin */

/*****************  Bit definition for SYSCFG_EXTICR4 register  **************/
#define SYSCFG_EXTICR4_EXTI12_Pos            (0U)                              
#define SYSCFG_EXTICR4_EXTI12_Msk            (0xFU << SYSCFG_EXTICR4_EXTI12_Pos) /*!< 0x0000000F */
#define SYSCFG_EXTICR4_EXTI12                SYSCFG_EXTICR4_EXTI12_Msk         /*!< EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13_Pos            (4U)                              
#define SYSCFG_EXTICR4_EXTI13_Msk            (0xFU << SYSCFG_EXTICR4_EXTI13_Pos) /*!< 0x000000F0 */
#define SYSCFG_EXTICR4_EXTI13                SYSCFG_EXTICR4_EXTI13_Msk         /*!< EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14_Pos            (8U)                              
#define SYSCFG_EXTICR4_EXTI14_Msk            (0xFU << SYSCFG_EXTICR4_EXTI14_Pos) /*!< 0x00000F00 */
#define SYSCFG_EXTICR4_EXTI14                SYSCFG_EXTICR4_EXTI14_Msk         /*!< EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15_Pos            (12U)                             
#define SYSCFG_EXTICR4_EXTI15_Msk            (0xFU << SYSCFG_EXTICR4_EXTI15_Pos) /*!< 0x0000F000 */
#define SYSCFG_EXTICR4_EXTI15                SYSCFG_EXTICR4_EXTI15_Msk         /*!< EXTI 15 configuration */

/** 
  * @brief  EXTI12 configuration  
  */
#define SYSCFG_EXTICR4_EXTI12_PA             (0x00000000U)                     /*!< PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB             (0x00000001U)                     /*!< PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC             (0x00000002U)                     /*!< PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD             (0x00000003U)                     /*!< PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE             (0x00000004U)                     /*!< PE[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PF             (0x00000005U)                     /*!< PF[12] pin */

/** 
  * @brief  EXTI13 configuration  
  */
#define SYSCFG_EXTICR4_EXTI13_PA             (0x00000000U)                     /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB             (0x00000010U)                     /*!< PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC             (0x00000020U)                     /*!< PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD             (0x00000030U)                     /*!< PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE             (0x00000040U)                     /*!< PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF             (0x00000050U)                     /*!< PF[13] pin */

/** 
  * @brief  EXTI14 configuration  
  */
#define SYSCFG_EXTICR4_EXTI14_PA             (0x00000000U)                     /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB             (0x00000100U)                     /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC             (0x00000200U)                     /*!< PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD             (0x00000300U)                     /*!< PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE             (0x00000400U)                     /*!< PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF             (0x00000500U)                     /*!< PF[14] pin */

/** 
  * @brief  EXTI15 configuration  
  */
#define SYSCFG_EXTICR4_EXTI15_PA             (0x00000000U)                     /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB             (0x00001000U)                     /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC             (0x00002000U)                     /*!< PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD             (0x00003000U)                     /*!< PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE             (0x00004000U)                     /*!< PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF             (0x00005000U)                     /*!< PF[15] pin */

/*****************  Bit definition for SYSCFG_CFGR2 register  ****************/
#define SYSCFG_CFGR2_LOCKUP_LOCK_Pos         (0U)                              
#define SYSCFG_CFGR2_LOCKUP_LOCK_Msk         (0x1U << SYSCFG_CFGR2_LOCKUP_LOCK_Pos) /*!< 0x00000001 */
#define SYSCFG_CFGR2_LOCKUP_LOCK             SYSCFG_CFGR2_LOCKUP_LOCK_Msk      /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM0 with Break Input of TIMER1 */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos    (1U)                              
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk    (0x1U << SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos) /*!< 0x00000002 */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK        SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMER1 */
#define SYSCFG_CFGR2_PVD_LOCK_Pos            (2U)                              
#define SYSCFG_CFGR2_PVD_LOCK_Msk            (0x1U << SYSCFG_CFGR2_PVD_LOCK_Pos) /*!< 0x00000004 */
#define SYSCFG_CFGR2_PVD_LOCK                SYSCFG_CFGR2_PVD_LOCK_Msk         /*!< Enables and locks the PVD connection with Timer1 Break Input and also the PVD_EN and PVDSEL[2:0] bits of the Power Control Interface */
#define SYSCFG_CFGR2_SRAM_PEF_Pos            (8U)                              
#define SYSCFG_CFGR2_SRAM_PEF_Msk            (0x1U << SYSCFG_CFGR2_SRAM_PEF_Pos) /*!< 0x00000100 */
#define SYSCFG_CFGR2_SRAM_PEF                SYSCFG_CFGR2_SRAM_PEF_Msk         /*!< SRAM Parity error flag */
#define SYSCFG_CFGR2_SRAM_PE                 SYSCFG_CFGR2_SRAM_PEF  /*!< SRAM Parity error flag (define maintained for legacy purpose) */

/*****************  Bit definition for SYSCFG_xxx ISR Wrapper register  ****************/
#define SYSCFG_ITLINE0_SR_EWDG_Pos           (0U)                              
#define SYSCFG_ITLINE0_SR_EWDG_Msk           (0x1U << SYSCFG_ITLINE0_SR_EWDG_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE0_SR_EWDG               SYSCFG_ITLINE0_SR_EWDG_Msk        /*!< EWDG interrupt */
#define SYSCFG_ITLINE1_SR_PVDOUT_Pos         (0U)                              
#define SYSCFG_ITLINE1_SR_PVDOUT_Msk         (0x1U << SYSCFG_ITLINE1_SR_PVDOUT_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE1_SR_PVDOUT             SYSCFG_ITLINE1_SR_PVDOUT_Msk      /*!< Power voltage detection -> exti[31] Interrupt */
#define SYSCFG_ITLINE1_SR_VDDIO2_Pos         (1U)                              
#define SYSCFG_ITLINE1_SR_VDDIO2_Msk         (0x1U << SYSCFG_ITLINE1_SR_VDDIO2_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE1_SR_VDDIO2             SYSCFG_ITLINE1_SR_VDDIO2_Msk      /*!< VDDIO2 -> exti[16] Interrupt */
#define SYSCFG_ITLINE2_SR_RTC_ALRA_Pos       (0U)                              
#define SYSCFG_ITLINE2_SR_RTC_ALRA_Msk       (0x1U << SYSCFG_ITLINE2_SR_RTC_ALRA_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE2_SR_RTC_ALRA           SYSCFG_ITLINE2_SR_RTC_ALRA_Msk    /*!< RTC Alarm -> exti[17] interrupt .... */
#define SYSCFG_ITLINE2_SR_RTC_TSTAMP_Pos     (1U)                              
#define SYSCFG_ITLINE2_SR_RTC_TSTAMP_Msk     (0x1U << SYSCFG_ITLINE2_SR_RTC_TSTAMP_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE2_SR_RTC_TSTAMP         SYSCFG_ITLINE2_SR_RTC_TSTAMP_Msk  /*!< RTC Time Stamp -> exti[19] interrupt */
#define SYSCFG_ITLINE2_SR_RTC_WAKEUP_Pos     (2U)                              
#define SYSCFG_ITLINE2_SR_RTC_WAKEUP_Msk     (0x1U << SYSCFG_ITLINE2_SR_RTC_WAKEUP_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE2_SR_RTC_WAKEUP         SYSCFG_ITLINE2_SR_RTC_WAKEUP_Msk  /*!< RTC WAKEUP -> exti[20] Interrupt */
#define SYSCFG_ITLINE3_SR_FLASH_ITF_Pos      (0U)                              
#define SYSCFG_ITLINE3_SR_FLASH_ITF_Msk      (0x1U << SYSCFG_ITLINE3_SR_FLASH_ITF_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE3_SR_FLASH_ITF          SYSCFG_ITLINE3_SR_FLASH_ITF_Msk   /*!< Flash ITF Interrupt */
#define SYSCFG_ITLINE4_SR_CRS_Pos            (0U)                              
#define SYSCFG_ITLINE4_SR_CRS_Msk            (0x1U << SYSCFG_ITLINE4_SR_CRS_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE4_SR_CRS                SYSCFG_ITLINE4_SR_CRS_Msk         /*!< CRS interrupt */
#define SYSCFG_ITLINE4_SR_CLK_CTRL_Pos       (1U)                              
#define SYSCFG_ITLINE4_SR_CLK_CTRL_Msk       (0x1U << SYSCFG_ITLINE4_SR_CLK_CTRL_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE4_SR_CLK_CTRL           SYSCFG_ITLINE4_SR_CLK_CTRL_Msk    /*!< CLK CTRL interrupt */
#define SYSCFG_ITLINE5_SR_EXTI0_Pos          (0U)                              
#define SYSCFG_ITLINE5_SR_EXTI0_Msk          (0x1U << SYSCFG_ITLINE5_SR_EXTI0_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE5_SR_EXTI0              SYSCFG_ITLINE5_SR_EXTI0_Msk       /*!< External Interrupt 0 */
#define SYSCFG_ITLINE5_SR_EXTI1_Pos          (1U)                              
#define SYSCFG_ITLINE5_SR_EXTI1_Msk          (0x1U << SYSCFG_ITLINE5_SR_EXTI1_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE5_SR_EXTI1              SYSCFG_ITLINE5_SR_EXTI1_Msk       /*!< External Interrupt 1 */
#define SYSCFG_ITLINE6_SR_EXTI2_Pos          (0U)                              
#define SYSCFG_ITLINE6_SR_EXTI2_Msk          (0x1U << SYSCFG_ITLINE6_SR_EXTI2_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE6_SR_EXTI2              SYSCFG_ITLINE6_SR_EXTI2_Msk       /*!< External Interrupt 2 */
#define SYSCFG_ITLINE6_SR_EXTI3_Pos          (1U)                              
#define SYSCFG_ITLINE6_SR_EXTI3_Msk          (0x1U << SYSCFG_ITLINE6_SR_EXTI3_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE6_SR_EXTI3              SYSCFG_ITLINE6_SR_EXTI3_Msk       /*!< External Interrupt 3 */
#define SYSCFG_ITLINE7_SR_EXTI4_Pos          (0U)                              
#define SYSCFG_ITLINE7_SR_EXTI4_Msk          (0x1U << SYSCFG_ITLINE7_SR_EXTI4_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE7_SR_EXTI4              SYSCFG_ITLINE7_SR_EXTI4_Msk       /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI5_Pos          (1U)                              
#define SYSCFG_ITLINE7_SR_EXTI5_Msk          (0x1U << SYSCFG_ITLINE7_SR_EXTI5_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE7_SR_EXTI5              SYSCFG_ITLINE7_SR_EXTI5_Msk       /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI6_Pos          (2U)                              
#define SYSCFG_ITLINE7_SR_EXTI6_Msk          (0x1U << SYSCFG_ITLINE7_SR_EXTI6_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE7_SR_EXTI6              SYSCFG_ITLINE7_SR_EXTI6_Msk       /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI7_Pos          (3U)                              
#define SYSCFG_ITLINE7_SR_EXTI7_Msk          (0x1U << SYSCFG_ITLINE7_SR_EXTI7_Pos) /*!< 0x00000008 */
#define SYSCFG_ITLINE7_SR_EXTI7              SYSCFG_ITLINE7_SR_EXTI7_Msk       /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI8_Pos          (4U)                              
#define SYSCFG_ITLINE7_SR_EXTI8_Msk          (0x1U << SYSCFG_ITLINE7_SR_EXTI8_Pos) /*!< 0x00000010 */
#define SYSCFG_ITLINE7_SR_EXTI8              SYSCFG_ITLINE7_SR_EXTI8_Msk       /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI9_Pos          (5U)                              
#define SYSCFG_ITLINE7_SR_EXTI9_Msk          (0x1U << SYSCFG_ITLINE7_SR_EXTI9_Pos) /*!< 0x00000020 */
#define SYSCFG_ITLINE7_SR_EXTI9              SYSCFG_ITLINE7_SR_EXTI9_Msk       /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI10_Pos         (6U)                              
#define SYSCFG_ITLINE7_SR_EXTI10_Msk         (0x1U << SYSCFG_ITLINE7_SR_EXTI10_Pos) /*!< 0x00000040 */
#define SYSCFG_ITLINE7_SR_EXTI10             SYSCFG_ITLINE7_SR_EXTI10_Msk      /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI11_Pos         (7U)                              
#define SYSCFG_ITLINE7_SR_EXTI11_Msk         (0x1U << SYSCFG_ITLINE7_SR_EXTI11_Pos) /*!< 0x00000080 */
#define SYSCFG_ITLINE7_SR_EXTI11             SYSCFG_ITLINE7_SR_EXTI11_Msk      /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI12_Pos         (8U)                              
#define SYSCFG_ITLINE7_SR_EXTI12_Msk         (0x1U << SYSCFG_ITLINE7_SR_EXTI12_Pos) /*!< 0x00000100 */
#define SYSCFG_ITLINE7_SR_EXTI12             SYSCFG_ITLINE7_SR_EXTI12_Msk      /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI13_Pos         (9U)                              
#define SYSCFG_ITLINE7_SR_EXTI13_Msk         (0x1U << SYSCFG_ITLINE7_SR_EXTI13_Pos) /*!< 0x00000200 */
#define SYSCFG_ITLINE7_SR_EXTI13             SYSCFG_ITLINE7_SR_EXTI13_Msk      /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI14_Pos         (10U)                             
#define SYSCFG_ITLINE7_SR_EXTI14_Msk         (0x1U << SYSCFG_ITLINE7_SR_EXTI14_Pos) /*!< 0x00000400 */
#define SYSCFG_ITLINE7_SR_EXTI14             SYSCFG_ITLINE7_SR_EXTI14_Msk      /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE7_SR_EXTI15_Pos         (11U)                             
#define SYSCFG_ITLINE7_SR_EXTI15_Msk         (0x1U << SYSCFG_ITLINE7_SR_EXTI15_Pos) /*!< 0x00000800 */
#define SYSCFG_ITLINE7_SR_EXTI15             SYSCFG_ITLINE7_SR_EXTI15_Msk      /*!< External Interrupt 15 to 4 */
#define SYSCFG_ITLINE8_SR_TSC_EOA_Pos        (0U)                              
#define SYSCFG_ITLINE8_SR_TSC_EOA_Msk        (0x1U << SYSCFG_ITLINE8_SR_TSC_EOA_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE8_SR_TSC_EOA            SYSCFG_ITLINE8_SR_TSC_EOA_Msk     /*!< Touch control EOA Interrupt */
#define SYSCFG_ITLINE8_SR_TSC_MCE_Pos        (1U)                              
#define SYSCFG_ITLINE8_SR_TSC_MCE_Msk        (0x1U << SYSCFG_ITLINE8_SR_TSC_MCE_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE8_SR_TSC_MCE            SYSCFG_ITLINE8_SR_TSC_MCE_Msk     /*!< Touch control MCE Interrupt */
#define SYSCFG_ITLINE9_SR_DMA1_CH1_Pos       (0U)                              
#define SYSCFG_ITLINE9_SR_DMA1_CH1_Msk       (0x1U << SYSCFG_ITLINE9_SR_DMA1_CH1_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE9_SR_DMA1_CH1           SYSCFG_ITLINE9_SR_DMA1_CH1_Msk    /*!< DMA1 Channel 1 Interrupt */
#define SYSCFG_ITLINE10_SR_DMA1_CH2_Pos      (0U)                              
#define SYSCFG_ITLINE10_SR_DMA1_CH2_Msk      (0x1U << SYSCFG_ITLINE10_SR_DMA1_CH2_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE10_SR_DMA1_CH2          SYSCFG_ITLINE10_SR_DMA1_CH2_Msk   /*!< DMA1 Channel 2 Interrupt */
#define SYSCFG_ITLINE10_SR_DMA1_CH3_Pos      (1U)                              
#define SYSCFG_ITLINE10_SR_DMA1_CH3_Msk      (0x1U << SYSCFG_ITLINE10_SR_DMA1_CH3_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE10_SR_DMA1_CH3          SYSCFG_ITLINE10_SR_DMA1_CH3_Msk   /*!< DMA2 Channel 3 Interrupt */
#define SYSCFG_ITLINE10_SR_DMA2_CH1_Pos      (2U)                              
#define SYSCFG_ITLINE10_SR_DMA2_CH1_Msk      (0x1U << SYSCFG_ITLINE10_SR_DMA2_CH1_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE10_SR_DMA2_CH1          SYSCFG_ITLINE10_SR_DMA2_CH1_Msk   /*!< DMA2 Channel 1 Interrupt */
#define SYSCFG_ITLINE10_SR_DMA2_CH2_Pos      (3U)                              
#define SYSCFG_ITLINE10_SR_DMA2_CH2_Msk      (0x1U << SYSCFG_ITLINE10_SR_DMA2_CH2_Pos) /*!< 0x00000008 */
#define SYSCFG_ITLINE10_SR_DMA2_CH2          SYSCFG_ITLINE10_SR_DMA2_CH2_Msk   /*!< DMA2 Channel 2 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA1_CH4_Pos      (0U)                              
#define SYSCFG_ITLINE11_SR_DMA1_CH4_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA1_CH4_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE11_SR_DMA1_CH4          SYSCFG_ITLINE11_SR_DMA1_CH4_Msk   /*!< DMA1 Channel 4 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA1_CH5_Pos      (1U)                              
#define SYSCFG_ITLINE11_SR_DMA1_CH5_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA1_CH5_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE11_SR_DMA1_CH5          SYSCFG_ITLINE11_SR_DMA1_CH5_Msk   /*!< DMA1 Channel 5 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA1_CH6_Pos      (2U)                              
#define SYSCFG_ITLINE11_SR_DMA1_CH6_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA1_CH6_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE11_SR_DMA1_CH6          SYSCFG_ITLINE11_SR_DMA1_CH6_Msk   /*!< DMA1 Channel 6 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA1_CH7_Pos      (3U)                              
#define SYSCFG_ITLINE11_SR_DMA1_CH7_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA1_CH7_Pos) /*!< 0x00000008 */
#define SYSCFG_ITLINE11_SR_DMA1_CH7          SYSCFG_ITLINE11_SR_DMA1_CH7_Msk   /*!< DMA1 Channel 7 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA2_CH3_Pos      (4U)                              
#define SYSCFG_ITLINE11_SR_DMA2_CH3_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA2_CH3_Pos) /*!< 0x00000010 */
#define SYSCFG_ITLINE11_SR_DMA2_CH3          SYSCFG_ITLINE11_SR_DMA2_CH3_Msk   /*!< DMA2 Channel 3 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA2_CH4_Pos      (5U)                              
#define SYSCFG_ITLINE11_SR_DMA2_CH4_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA2_CH4_Pos) /*!< 0x00000020 */
#define SYSCFG_ITLINE11_SR_DMA2_CH4          SYSCFG_ITLINE11_SR_DMA2_CH4_Msk   /*!< DMA2 Channel 4 Interrupt */
#define SYSCFG_ITLINE11_SR_DMA2_CH5_Pos      (6U)                              
#define SYSCFG_ITLINE11_SR_DMA2_CH5_Msk      (0x1U << SYSCFG_ITLINE11_SR_DMA2_CH5_Pos) /*!< 0x00000040 */
#define SYSCFG_ITLINE11_SR_DMA2_CH5          SYSCFG_ITLINE11_SR_DMA2_CH5_Msk   /*!< DMA2 Channel 5 Interrupt */
#define SYSCFG_ITLINE12_SR_ADC_Pos           (0U)                              
#define SYSCFG_ITLINE12_SR_ADC_Msk           (0x1U << SYSCFG_ITLINE12_SR_ADC_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE12_SR_ADC               SYSCFG_ITLINE12_SR_ADC_Msk        /*!< ADC Interrupt */
#define SYSCFG_ITLINE12_SR_COMP1_Pos         (1U)                              
#define SYSCFG_ITLINE12_SR_COMP1_Msk         (0x1U << SYSCFG_ITLINE12_SR_COMP1_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE12_SR_COMP1             SYSCFG_ITLINE12_SR_COMP1_Msk      /*!< COMP1 Interrupt -> exti[21] */
#define SYSCFG_ITLINE12_SR_COMP2_Pos         (2U)                              
#define SYSCFG_ITLINE12_SR_COMP2_Msk         (0x1U << SYSCFG_ITLINE12_SR_COMP2_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE12_SR_COMP2             SYSCFG_ITLINE12_SR_COMP2_Msk      /*!< COMP2 Interrupt -> exti[22] */
#define SYSCFG_ITLINE13_SR_TIM1_BRK_Pos      (0U)                              
#define SYSCFG_ITLINE13_SR_TIM1_BRK_Msk      (0x1U << SYSCFG_ITLINE13_SR_TIM1_BRK_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE13_SR_TIM1_BRK          SYSCFG_ITLINE13_SR_TIM1_BRK_Msk   /*!< TIM1 BRK Interrupt */
#define SYSCFG_ITLINE13_SR_TIM1_UPD_Pos      (1U)                              
#define SYSCFG_ITLINE13_SR_TIM1_UPD_Msk      (0x1U << SYSCFG_ITLINE13_SR_TIM1_UPD_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE13_SR_TIM1_UPD          SYSCFG_ITLINE13_SR_TIM1_UPD_Msk   /*!< TIM1 UPD Interrupt */
#define SYSCFG_ITLINE13_SR_TIM1_TRG_Pos      (2U)                              
#define SYSCFG_ITLINE13_SR_TIM1_TRG_Msk      (0x1U << SYSCFG_ITLINE13_SR_TIM1_TRG_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE13_SR_TIM1_TRG          SYSCFG_ITLINE13_SR_TIM1_TRG_Msk   /*!< TIM1 TRG Interrupt */
#define SYSCFG_ITLINE13_SR_TIM1_CCU_Pos      (3U)                              
#define SYSCFG_ITLINE13_SR_TIM1_CCU_Msk      (0x1U << SYSCFG_ITLINE13_SR_TIM1_CCU_Pos) /*!< 0x00000008 */
#define SYSCFG_ITLINE13_SR_TIM1_CCU          SYSCFG_ITLINE13_SR_TIM1_CCU_Msk   /*!< TIM1 CCU Interrupt */
#define SYSCFG_ITLINE14_SR_TIM1_CC_Pos       (0U)                              
#define SYSCFG_ITLINE14_SR_TIM1_CC_Msk       (0x1U << SYSCFG_ITLINE14_SR_TIM1_CC_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE14_SR_TIM1_CC           SYSCFG_ITLINE14_SR_TIM1_CC_Msk    /*!< TIM1 CC Interrupt */
#define SYSCFG_ITLINE15_SR_TIM2_GLB_Pos      (0U)                              
#define SYSCFG_ITLINE15_SR_TIM2_GLB_Msk      (0x1U << SYSCFG_ITLINE15_SR_TIM2_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE15_SR_TIM2_GLB          SYSCFG_ITLINE15_SR_TIM2_GLB_Msk   /*!< TIM2 GLB Interrupt */
#define SYSCFG_ITLINE16_SR_TIM3_GLB_Pos      (0U)                              
#define SYSCFG_ITLINE16_SR_TIM3_GLB_Msk      (0x1U << SYSCFG_ITLINE16_SR_TIM3_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE16_SR_TIM3_GLB          SYSCFG_ITLINE16_SR_TIM3_GLB_Msk   /*!< TIM3 GLB Interrupt */
#define SYSCFG_ITLINE17_SR_DAC_Pos           (0U)                              
#define SYSCFG_ITLINE17_SR_DAC_Msk           (0x1U << SYSCFG_ITLINE17_SR_DAC_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE17_SR_DAC               SYSCFG_ITLINE17_SR_DAC_Msk        /*!< DAC Interrupt */
#define SYSCFG_ITLINE17_SR_TIM6_GLB_Pos      (1U)                              
#define SYSCFG_ITLINE17_SR_TIM6_GLB_Msk      (0x1U << SYSCFG_ITLINE17_SR_TIM6_GLB_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE17_SR_TIM6_GLB          SYSCFG_ITLINE17_SR_TIM6_GLB_Msk   /*!< TIM6 GLB Interrupt */
#define SYSCFG_ITLINE18_SR_TIM7_GLB_Pos      (0U)                              
#define SYSCFG_ITLINE18_SR_TIM7_GLB_Msk      (0x1U << SYSCFG_ITLINE18_SR_TIM7_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE18_SR_TIM7_GLB          SYSCFG_ITLINE18_SR_TIM7_GLB_Msk   /*!< TIM7 GLB Interrupt */
#define SYSCFG_ITLINE19_SR_TIM14_GLB_Pos     (0U)                              
#define SYSCFG_ITLINE19_SR_TIM14_GLB_Msk     (0x1U << SYSCFG_ITLINE19_SR_TIM14_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE19_SR_TIM14_GLB         SYSCFG_ITLINE19_SR_TIM14_GLB_Msk  /*!< TIM14 GLB Interrupt */
#define SYSCFG_ITLINE20_SR_TIM15_GLB_Pos     (0U)                              
#define SYSCFG_ITLINE20_SR_TIM15_GLB_Msk     (0x1U << SYSCFG_ITLINE20_SR_TIM15_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE20_SR_TIM15_GLB         SYSCFG_ITLINE20_SR_TIM15_GLB_Msk  /*!< TIM15 GLB Interrupt */
#define SYSCFG_ITLINE21_SR_TIM16_GLB_Pos     (0U)                              
#define SYSCFG_ITLINE21_SR_TIM16_GLB_Msk     (0x1U << SYSCFG_ITLINE21_SR_TIM16_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE21_SR_TIM16_GLB         SYSCFG_ITLINE21_SR_TIM16_GLB_Msk  /*!< TIM16 GLB Interrupt */
#define SYSCFG_ITLINE22_SR_TIM17_GLB_Pos     (0U)                              
#define SYSCFG_ITLINE22_SR_TIM17_GLB_Msk     (0x1U << SYSCFG_ITLINE22_SR_TIM17_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE22_SR_TIM17_GLB         SYSCFG_ITLINE22_SR_TIM17_GLB_Msk  /*!< TIM17 GLB Interrupt */
#define SYSCFG_ITLINE23_SR_I2C1_GLB_Pos      (0U)                              
#define SYSCFG_ITLINE23_SR_I2C1_GLB_Msk      (0x1U << SYSCFG_ITLINE23_SR_I2C1_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE23_SR_I2C1_GLB          SYSCFG_ITLINE23_SR_I2C1_GLB_Msk   /*!< I2C1 GLB Interrupt -> exti[23] */
#define SYSCFG_ITLINE24_SR_I2C2_GLB_Pos      (0U)                              
#define SYSCFG_ITLINE24_SR_I2C2_GLB_Msk      (0x1U << SYSCFG_ITLINE24_SR_I2C2_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE24_SR_I2C2_GLB          SYSCFG_ITLINE24_SR_I2C2_GLB_Msk   /*!< I2C2 GLB Interrupt */
#define SYSCFG_ITLINE25_SR_SPI1_Pos          (0U)                              
#define SYSCFG_ITLINE25_SR_SPI1_Msk          (0x1U << SYSCFG_ITLINE25_SR_SPI1_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE25_SR_SPI1              SYSCFG_ITLINE25_SR_SPI1_Msk       /*!< SPI1 Interrupt */
#define SYSCFG_ITLINE26_SR_SPI2_Pos          (0U)                              
#define SYSCFG_ITLINE26_SR_SPI2_Msk          (0x1U << SYSCFG_ITLINE26_SR_SPI2_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE26_SR_SPI2              SYSCFG_ITLINE26_SR_SPI2_Msk       /*!< SPI2  Interrupt */
#define SYSCFG_ITLINE27_SR_USART1_GLB_Pos    (0U)                              
#define SYSCFG_ITLINE27_SR_USART1_GLB_Msk    (0x1U << SYSCFG_ITLINE27_SR_USART1_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE27_SR_USART1_GLB        SYSCFG_ITLINE27_SR_USART1_GLB_Msk /*!< USART1 GLB Interrupt -> exti[25] */
#define SYSCFG_ITLINE28_SR_USART2_GLB_Pos    (0U)                              
#define SYSCFG_ITLINE28_SR_USART2_GLB_Msk    (0x1U << SYSCFG_ITLINE28_SR_USART2_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE28_SR_USART2_GLB        SYSCFG_ITLINE28_SR_USART2_GLB_Msk /*!< USART2 GLB Interrupt -> exti[26] */
#define SYSCFG_ITLINE29_SR_USART3_GLB_Pos    (0U)                              
#define SYSCFG_ITLINE29_SR_USART3_GLB_Msk    (0x1U << SYSCFG_ITLINE29_SR_USART3_GLB_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE29_SR_USART3_GLB        SYSCFG_ITLINE29_SR_USART3_GLB_Msk /*!< USART3 GLB Interrupt -> exti[28] */
#define SYSCFG_ITLINE29_SR_USART4_GLB_Pos    (1U)                              
#define SYSCFG_ITLINE29_SR_USART4_GLB_Msk    (0x1U << SYSCFG_ITLINE29_SR_USART4_GLB_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE29_SR_USART4_GLB        SYSCFG_ITLINE29_SR_USART4_GLB_Msk /*!< USART4 GLB Interrupt */
#define SYSCFG_ITLINE29_SR_USART5_GLB_Pos    (2U)                              
#define SYSCFG_ITLINE29_SR_USART5_GLB_Msk    (0x1U << SYSCFG_ITLINE29_SR_USART5_GLB_Pos) /*!< 0x00000004 */
#define SYSCFG_ITLINE29_SR_USART5_GLB        SYSCFG_ITLINE29_SR_USART5_GLB_Msk /*!< USART5 GLB Interrupt */
#define SYSCFG_ITLINE29_SR_USART6_GLB_Pos    (3U)                              
#define SYSCFG_ITLINE29_SR_USART6_GLB_Msk    (0x1U << SYSCFG_ITLINE29_SR_USART6_GLB_Pos) /*!< 0x00000008 */
#define SYSCFG_ITLINE29_SR_USART6_GLB        SYSCFG_ITLINE29_SR_USART6_GLB_Msk /*!< USART6 GLB Interrupt */
#define SYSCFG_ITLINE29_SR_USART7_GLB_Pos    (4U)                              
#define SYSCFG_ITLINE29_SR_USART7_GLB_Msk    (0x1U << SYSCFG_ITLINE29_SR_USART7_GLB_Pos) /*!< 0x00000010 */
#define SYSCFG_ITLINE29_SR_USART7_GLB        SYSCFG_ITLINE29_SR_USART7_GLB_Msk /*!< USART7 GLB Interrupt */
#define SYSCFG_ITLINE29_SR_USART8_GLB_Pos    (5U)                              
#define SYSCFG_ITLINE29_SR_USART8_GLB_Msk    (0x1U << SYSCFG_ITLINE29_SR_USART8_GLB_Pos) /*!< 0x00000020 */
#define SYSCFG_ITLINE29_SR_USART8_GLB        SYSCFG_ITLINE29_SR_USART8_GLB_Msk /*!< USART8 GLB Interrupt */
#define SYSCFG_ITLINE30_SR_CAN_Pos           (0U)                              
#define SYSCFG_ITLINE30_SR_CAN_Msk           (0x1U << SYSCFG_ITLINE30_SR_CAN_Pos) /*!< 0x00000001 */
#define SYSCFG_ITLINE30_SR_CAN               SYSCFG_ITLINE30_SR_CAN_Msk        /*!< CAN Interrupt */
#define SYSCFG_ITLINE30_SR_CEC_Pos           (1U)                              
#define SYSCFG_ITLINE30_SR_CEC_Msk           (0x1U << SYSCFG_ITLINE30_SR_CEC_Pos) /*!< 0x00000002 */
#define SYSCFG_ITLINE30_SR_CEC               SYSCFG_ITLINE30_SR_CEC_Msk        /*!< CEC Interrupt */
