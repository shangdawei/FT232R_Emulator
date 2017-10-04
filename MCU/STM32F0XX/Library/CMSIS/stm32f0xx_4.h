
/******************************************************************************/
/*                                                                            */
/*                 External Interrupt/Event Controller (EXTI)                 */
/*                                                                            */
/******************************************************************************/


/******  EXTI_IMR_IM Definition ******************************************************************************/
#define EXTI_IMR_IM_Pos           (0U)

#if defined(STM32F030x6)
#define EXTI_IMR_IM_Msk           (0x8EFFFFU << EXTI_IMR_IM_Pos)               /*!< 0x008EFFFF */
#elif defined(STM32F030x8)
#define EXTI_IMR_IM_Msk           (0x8EFFFFU << EXTI_IMR_IM_Pos)               /*!< 0x008EFFFF */
#elif defined(STM32F030xC)
#define EXTI_IMR_IM_Msk           (0x9EFFFFU << EXTI_IMR_IM_Pos)               /*!< 0x009EFFFF */
#elif defined(STM32F031x6)
#define EXTI_IMR_IM_Msk           (0xAEFFFFFU << EXTI_IMR_IM_Pos)              /*!< 0x0AEFFFFF */
#elif defined(STM32F038xx)
#define EXTI_IMR_IM_Msk           (0xAEFFFFFU << EXTI_IMR_IM_Pos)              /*!< 0x0AEFFFFF */
#elif defined(STM32F042x6)
#define EXTI_IMR_IM_Msk           (0x8AEFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x8AEFFFFF */
#elif defined(STM32F048xx)
#define EXTI_IMR_IM_Msk           (0x8AEFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x8AEFFFFF */
#elif defined(STM32F051x8)
#define EXTI_IMR_IM_Msk           (0xAEFFFFFU << EXTI_IMR_IM_Pos)              /*!< 0x0AEFFFFF */
#elif defined(STM32F058xx)
#define EXTI_IMR_IM_Msk           (0xAEFFFFFU << EXTI_IMR_IM_Pos)              /*!< 0x0AEFFFFF */
#elif defined(STM32F070x6)
#define EXTI_IMR_IM_Msk           (0x8EFFFFU << EXTI_IMR_IM_Pos)               /*!< 0x008EFFFF */
#elif defined(STM32F070xB)
#define EXTI_IMR_IM_Msk           (0x9EFFFFU << EXTI_IMR_IM_Pos)               /*!< 0x009EFFFF */
#elif defined(STM32F071xB)
#define EXTI_IMR_IM_Msk           (0x8EFFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x8EFFFFFF */
#elif defined(STM32F072xB)
#define EXTI_IMR_IM_Msk           (0x8EFFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x8EFFFFFF */
#elif defined(STM32F078xx)
#define EXTI_IMR_IM_Msk           (0x8EFFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x8EFFFFFF */
#elif defined(STM32F091xC)
#define EXTI_IMR_IM_Msk           (0x9EFFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x9EFFFFFF */
#elif defined(STM32F098xx)
#define EXTI_IMR_IM_Msk           (0x9EFFFFFFU << EXTI_IMR_IM_Pos)             /*!< 0x9EFFFFFF */
#endif

#define EXTI_IMR_IM               EXTI_IMR_IM_Msk                              /*!< Interrupt Mask All */

/*******************  Bit definition for EXTI_IMR register  *******************/
#define EXTI_IMR_MR0_Pos          (0U)
#define EXTI_IMR_MR0_Msk          (0x1U << EXTI_IMR_MR0_Pos)                   /*!< 0x00000001 */
#define EXTI_IMR_MR0              EXTI_IMR_MR0_Msk                             /*!< Interrupt Mask on line 0  */
#define EXTI_IMR_MR1_Pos          (1U)
#define EXTI_IMR_MR1_Msk          (0x1U << EXTI_IMR_MR1_Pos)                   /*!< 0x00000002 */
#define EXTI_IMR_MR1              EXTI_IMR_MR1_Msk                             /*!< Interrupt Mask on line 1  */
#define EXTI_IMR_MR2_Pos          (2U)
#define EXTI_IMR_MR2_Msk          (0x1U << EXTI_IMR_MR2_Pos)                   /*!< 0x00000004 */
#define EXTI_IMR_MR2              EXTI_IMR_MR2_Msk                             /*!< Interrupt Mask on line 2  */
#define EXTI_IMR_MR3_Pos          (3U)
#define EXTI_IMR_MR3_Msk          (0x1U << EXTI_IMR_MR3_Pos)                   /*!< 0x00000008 */
#define EXTI_IMR_MR3              EXTI_IMR_MR3_Msk                             /*!< Interrupt Mask on line 3  */
#define EXTI_IMR_MR4_Pos          (4U)
#define EXTI_IMR_MR4_Msk          (0x1U << EXTI_IMR_MR4_Pos)                   /*!< 0x00000010 */
#define EXTI_IMR_MR4              EXTI_IMR_MR4_Msk                             /*!< Interrupt Mask on line 4  */
#define EXTI_IMR_MR5_Pos          (5U)
#define EXTI_IMR_MR5_Msk          (0x1U << EXTI_IMR_MR5_Pos)                   /*!< 0x00000020 */
#define EXTI_IMR_MR5              EXTI_IMR_MR5_Msk                             /*!< Interrupt Mask on line 5  */
#define EXTI_IMR_MR6_Pos          (6U)
#define EXTI_IMR_MR6_Msk          (0x1U << EXTI_IMR_MR6_Pos)                   /*!< 0x00000040 */
#define EXTI_IMR_MR6              EXTI_IMR_MR6_Msk                             /*!< Interrupt Mask on line 6  */
#define EXTI_IMR_MR7_Pos          (7U)
#define EXTI_IMR_MR7_Msk          (0x1U << EXTI_IMR_MR7_Pos)                   /*!< 0x00000080 */
#define EXTI_IMR_MR7              EXTI_IMR_MR7_Msk                             /*!< Interrupt Mask on line 7  */
#define EXTI_IMR_MR8_Pos          (8U)
#define EXTI_IMR_MR8_Msk          (0x1U << EXTI_IMR_MR8_Pos)                   /*!< 0x00000100 */
#define EXTI_IMR_MR8              EXTI_IMR_MR8_Msk                             /*!< Interrupt Mask on line 8  */
#define EXTI_IMR_MR9_Pos          (9U)
#define EXTI_IMR_MR9_Msk          (0x1U << EXTI_IMR_MR9_Pos)                   /*!< 0x00000200 */
#define EXTI_IMR_MR9              EXTI_IMR_MR9_Msk                             /*!< Interrupt Mask on line 9  */
#define EXTI_IMR_MR10_Pos         (10U)
#define EXTI_IMR_MR10_Msk         (0x1U << EXTI_IMR_MR10_Pos)                  /*!< 0x00000400 */
#define EXTI_IMR_MR10             EXTI_IMR_MR10_Msk                            /*!< Interrupt Mask on line 10 */
#define EXTI_IMR_MR11_Pos         (11U)
#define EXTI_IMR_MR11_Msk         (0x1U << EXTI_IMR_MR11_Pos)                  /*!< 0x00000800 */
#define EXTI_IMR_MR11             EXTI_IMR_MR11_Msk                            /*!< Interrupt Mask on line 11 */
#define EXTI_IMR_MR12_Pos         (12U)
#define EXTI_IMR_MR12_Msk         (0x1U << EXTI_IMR_MR12_Pos)                  /*!< 0x00001000 */
#define EXTI_IMR_MR12             EXTI_IMR_MR12_Msk                            /*!< Interrupt Mask on line 12 */
#define EXTI_IMR_MR13_Pos         (13U)
#define EXTI_IMR_MR13_Msk         (0x1U << EXTI_IMR_MR13_Pos)                  /*!< 0x00002000 */
#define EXTI_IMR_MR13             EXTI_IMR_MR13_Msk                            /*!< Interrupt Mask on line 13 */
#define EXTI_IMR_MR14_Pos         (14U)
#define EXTI_IMR_MR14_Msk         (0x1U << EXTI_IMR_MR14_Pos)                  /*!< 0x00004000 */
#define EXTI_IMR_MR14             EXTI_IMR_MR14_Msk                            /*!< Interrupt Mask on line 14 */
#define EXTI_IMR_MR15_Pos         (15U)
#define EXTI_IMR_MR15_Msk         (0x1U << EXTI_IMR_MR15_Pos)                  /*!< 0x00008000 */
#define EXTI_IMR_MR15             EXTI_IMR_MR15_Msk                            /*!< Interrupt Mask on line 15 */
#define EXTI_IMR_MR16_Pos         (16U)
#define EXTI_IMR_MR16_Msk         (0x1U << EXTI_IMR_MR16_Pos)                  /*!< 0x00010000 */
#define EXTI_IMR_MR16             EXTI_IMR_MR16_Msk                            /*!< Interrupt Mask on line 16 */
#define EXTI_IMR_MR17_Pos         (17U)
#define EXTI_IMR_MR17_Msk         (0x1U << EXTI_IMR_MR17_Pos)                  /*!< 0x00020000 */
#define EXTI_IMR_MR17             EXTI_IMR_MR17_Msk                            /*!< Interrupt Mask on line 17 */
#define EXTI_IMR_MR18_Pos         (18U)
#define EXTI_IMR_MR18_Msk         (0x1U << EXTI_IMR_MR18_Pos)                  /*!< 0x00040000 */
#define EXTI_IMR_MR18             EXTI_IMR_MR18_Msk                            /*!< Interrupt Mask on line 18 */
#define EXTI_IMR_MR19_Pos         (19U)
#define EXTI_IMR_MR19_Msk         (0x1U << EXTI_IMR_MR19_Pos)                  /*!< 0x00080000 */
#define EXTI_IMR_MR19             EXTI_IMR_MR19_Msk                            /*!< Interrupt Mask on line 19 */
#define EXTI_IMR_MR20_Pos         (20U)
#define EXTI_IMR_MR20_Msk         (0x1U << EXTI_IMR_MR20_Pos)                  /*!< 0x00100000 */
#define EXTI_IMR_MR20             EXTI_IMR_MR20_Msk                            /*!< Interrupt Mask on line 20 */
#define EXTI_IMR_MR21_Pos         (21U)
#define EXTI_IMR_MR21_Msk         (0x1U << EXTI_IMR_MR21_Pos)                  /*!< 0x00200000 */
#define EXTI_IMR_MR21             EXTI_IMR_MR21_Msk                            /*!< Interrupt Mask on line 21 */
#define EXTI_IMR_MR22_Pos         (22U)
#define EXTI_IMR_MR22_Msk         (0x1U << EXTI_IMR_MR22_Pos)                  /*!< 0x00400000 */
#define EXTI_IMR_MR22             EXTI_IMR_MR22_Msk                            /*!< Interrupt Mask on line 22 */
#define EXTI_IMR_MR23_Pos         (23U)
#define EXTI_IMR_MR23_Msk         (0x1U << EXTI_IMR_MR23_Pos)                  /*!< 0x00800000 */
#define EXTI_IMR_MR23             EXTI_IMR_MR23_Msk                            /*!< Interrupt Mask on line 23 */
#define EXTI_IMR_MR25_Pos         (25U)
#define EXTI_IMR_MR25_Msk         (0x1U << EXTI_IMR_MR25_Pos)                  /*!< 0x02000000 */
#define EXTI_IMR_MR25             EXTI_IMR_MR25_Msk                            /*!< Interrupt Mask on line 25 */
#define EXTI_IMR_MR26_Pos         (26U)
#define EXTI_IMR_MR26_Msk         (0x1U << EXTI_IMR_MR26_Pos)                  /*!< 0x04000000 */
#define EXTI_IMR_MR26             EXTI_IMR_MR26_Msk                            /*!< Interrupt Mask on line 26 */
#define EXTI_IMR_MR27_Pos         (27U)
#define EXTI_IMR_MR27_Msk         (0x1U << EXTI_IMR_MR27_Pos)                  /*!< 0x08000000 */
#define EXTI_IMR_MR27             EXTI_IMR_MR27_Msk                            /*!< Interrupt Mask on line 27 */
#define EXTI_IMR_MR28_Pos         (28U)
#define EXTI_IMR_MR28_Msk         (0x1U << EXTI_IMR_MR28_Pos)                  /*!< 0x10000000 */
#define EXTI_IMR_MR28             EXTI_IMR_MR28_Msk                            /*!< Interrupt Mask on line 28 */
#define EXTI_IMR_MR31_Pos         (31U)
#define EXTI_IMR_MR31_Msk         (0x1U << EXTI_IMR_MR31_Pos)                  /*!< 0x80000000 */
#define EXTI_IMR_MR31             EXTI_IMR_MR31_Msk                            /*!< Interrupt Mask on line 31 */

/* References Defines */
#define  EXTI_IMR_IM0  						EXTI_IMR_MR0
#define  EXTI_IMR_IM1  						EXTI_IMR_MR1
#define  EXTI_IMR_IM2  						EXTI_IMR_MR2
#define  EXTI_IMR_IM3  						EXTI_IMR_MR3
#define  EXTI_IMR_IM4  						EXTI_IMR_MR4
#define  EXTI_IMR_IM5  						EXTI_IMR_MR5
#define  EXTI_IMR_IM6  						EXTI_IMR_MR6
#define  EXTI_IMR_IM7  						EXTI_IMR_MR7
#define  EXTI_IMR_IM8  						EXTI_IMR_MR8
#define  EXTI_IMR_IM9  						EXTI_IMR_MR9
#define  EXTI_IMR_IM10 						EXTI_IMR_MR10
#define  EXTI_IMR_IM11 						EXTI_IMR_MR11
#define  EXTI_IMR_IM12 						EXTI_IMR_MR12
#define  EXTI_IMR_IM13 						EXTI_IMR_MR13
#define  EXTI_IMR_IM14 						EXTI_IMR_MR14
#define  EXTI_IMR_IM15 						EXTI_IMR_MR15
#define  EXTI_IMR_IM16 						EXTI_IMR_MR16
#define  EXTI_IMR_IM17 						EXTI_IMR_MR17
#define  EXTI_IMR_IM18 						EXTI_IMR_MR18
#define  EXTI_IMR_IM19 						EXTI_IMR_MR19
#define  EXTI_IMR_IM20 						EXTI_IMR_MR20
#define  EXTI_IMR_IM21 						EXTI_IMR_MR21
#define  EXTI_IMR_IM22 						EXTI_IMR_MR22
#define  EXTI_IMR_IM23 						EXTI_IMR_MR23
#define  EXTI_IMR_IM25 						EXTI_IMR_MR25
#define  EXTI_IMR_IM26 						EXTI_IMR_MR26
#define  EXTI_IMR_IM27 						EXTI_IMR_MR27
#define  EXTI_IMR_IM28 						EXTI_IMR_MR28
#define  EXTI_IMR_IM31 						EXTI_IMR_MR31

/******************  Bit definition for EXTI_EMR register  ********************/
#define EXTI_EMR_MR0_Pos          (0U)
#define EXTI_EMR_MR0_Msk          (0x1U << EXTI_EMR_MR0_Pos)                   /*!< 0x00000001 */
#define EXTI_EMR_MR0              EXTI_EMR_MR0_Msk                             /*!< Event Mask on line 0  */
#define EXTI_EMR_MR1_Pos          (1U)
#define EXTI_EMR_MR1_Msk          (0x1U << EXTI_EMR_MR1_Pos)                   /*!< 0x00000002 */
#define EXTI_EMR_MR1              EXTI_EMR_MR1_Msk                             /*!< Event Mask on line 1  */
#define EXTI_EMR_MR2_Pos          (2U)
#define EXTI_EMR_MR2_Msk          (0x1U << EXTI_EMR_MR2_Pos)                   /*!< 0x00000004 */
#define EXTI_EMR_MR2              EXTI_EMR_MR2_Msk                             /*!< Event Mask on line 2  */
#define EXTI_EMR_MR3_Pos          (3U)
#define EXTI_EMR_MR3_Msk          (0x1U << EXTI_EMR_MR3_Pos)                   /*!< 0x00000008 */
#define EXTI_EMR_MR3              EXTI_EMR_MR3_Msk                             /*!< Event Mask on line 3  */
#define EXTI_EMR_MR4_Pos          (4U)
#define EXTI_EMR_MR4_Msk          (0x1U << EXTI_EMR_MR4_Pos)                   /*!< 0x00000010 */
#define EXTI_EMR_MR4              EXTI_EMR_MR4_Msk                             /*!< Event Mask on line 4  */
#define EXTI_EMR_MR5_Pos          (5U)
#define EXTI_EMR_MR5_Msk          (0x1U << EXTI_EMR_MR5_Pos)                   /*!< 0x00000020 */
#define EXTI_EMR_MR5              EXTI_EMR_MR5_Msk                             /*!< Event Mask on line 5  */
#define EXTI_EMR_MR6_Pos          (6U)
#define EXTI_EMR_MR6_Msk          (0x1U << EXTI_EMR_MR6_Pos)                   /*!< 0x00000040 */
#define EXTI_EMR_MR6              EXTI_EMR_MR6_Msk                             /*!< Event Mask on line 6  */
#define EXTI_EMR_MR7_Pos          (7U)
#define EXTI_EMR_MR7_Msk          (0x1U << EXTI_EMR_MR7_Pos)                   /*!< 0x00000080 */
#define EXTI_EMR_MR7              EXTI_EMR_MR7_Msk                             /*!< Event Mask on line 7  */
#define EXTI_EMR_MR8_Pos          (8U)
#define EXTI_EMR_MR8_Msk          (0x1U << EXTI_EMR_MR8_Pos)                   /*!< 0x00000100 */
#define EXTI_EMR_MR8              EXTI_EMR_MR8_Msk                             /*!< Event Mask on line 8  */
#define EXTI_EMR_MR9_Pos          (9U)
#define EXTI_EMR_MR9_Msk          (0x1U << EXTI_EMR_MR9_Pos)                   /*!< 0x00000200 */
#define EXTI_EMR_MR9              EXTI_EMR_MR9_Msk                             /*!< Event Mask on line 9  */
#define EXTI_EMR_MR10_Pos         (10U)
#define EXTI_EMR_MR10_Msk         (0x1U << EXTI_EMR_MR10_Pos)                  /*!< 0x00000400 */
#define EXTI_EMR_MR10             EXTI_EMR_MR10_Msk                            /*!< Event Mask on line 10 */
#define EXTI_EMR_MR11_Pos         (11U)
#define EXTI_EMR_MR11_Msk         (0x1U << EXTI_EMR_MR11_Pos)                  /*!< 0x00000800 */
#define EXTI_EMR_MR11             EXTI_EMR_MR11_Msk                            /*!< Event Mask on line 11 */
#define EXTI_EMR_MR12_Pos         (12U)
#define EXTI_EMR_MR12_Msk         (0x1U << EXTI_EMR_MR12_Pos)                  /*!< 0x00001000 */
#define EXTI_EMR_MR12             EXTI_EMR_MR12_Msk                            /*!< Event Mask on line 12 */
#define EXTI_EMR_MR13_Pos         (13U)
#define EXTI_EMR_MR13_Msk         (0x1U << EXTI_EMR_MR13_Pos)                  /*!< 0x00002000 */
#define EXTI_EMR_MR13             EXTI_EMR_MR13_Msk                            /*!< Event Mask on line 13 */
#define EXTI_EMR_MR14_Pos         (14U)
#define EXTI_EMR_MR14_Msk         (0x1U << EXTI_EMR_MR14_Pos)                  /*!< 0x00004000 */
#define EXTI_EMR_MR14             EXTI_EMR_MR14_Msk                            /*!< Event Mask on line 14 */
#define EXTI_EMR_MR15_Pos         (15U)
#define EXTI_EMR_MR15_Msk         (0x1U << EXTI_EMR_MR15_Pos)                  /*!< 0x00008000 */
#define EXTI_EMR_MR15             EXTI_EMR_MR15_Msk                            /*!< Event Mask on line 15 */
#define EXTI_EMR_MR16_Pos         (16U)
#define EXTI_EMR_MR16_Msk         (0x1U << EXTI_EMR_MR16_Pos)                  /*!< 0x00010000 */
#define EXTI_EMR_MR16             EXTI_EMR_MR16_Msk                            /*!< Event Mask on line 16 */
#define EXTI_EMR_MR17_Pos         (17U)
#define EXTI_EMR_MR17_Msk         (0x1U << EXTI_EMR_MR17_Pos)                  /*!< 0x00020000 */
#define EXTI_EMR_MR17             EXTI_EMR_MR17_Msk                            /*!< Event Mask on line 17 */
#define EXTI_EMR_MR18_Pos         (18U)
#define EXTI_EMR_MR18_Msk         (0x1U << EXTI_EMR_MR18_Pos)                  /*!< 0x00040000 */
#define EXTI_EMR_MR18             EXTI_EMR_MR18_Msk                            /*!< Event Mask on line 18 */
#define EXTI_EMR_MR19_Pos         (19U)
#define EXTI_EMR_MR19_Msk         (0x1U << EXTI_EMR_MR19_Pos)                  /*!< 0x00080000 */
#define EXTI_EMR_MR19             EXTI_EMR_MR19_Msk                            /*!< Event Mask on line 19 */
#define EXTI_EMR_MR20_Pos         (20U)
#define EXTI_EMR_MR20_Msk         (0x1U << EXTI_EMR_MR20_Pos)                  /*!< 0x00100000 */
#define EXTI_EMR_MR20             EXTI_EMR_MR20_Msk                            /*!< Event Mask on line 20 */
#define EXTI_EMR_MR21_Pos         (21U)
#define EXTI_EMR_MR21_Msk         (0x1U << EXTI_EMR_MR21_Pos)                  /*!< 0x00200000 */
#define EXTI_EMR_MR21             EXTI_EMR_MR21_Msk                            /*!< Event Mask on line 21 */
#define EXTI_EMR_MR22_Pos         (22U)
#define EXTI_EMR_MR22_Msk         (0x1U << EXTI_EMR_MR22_Pos)                  /*!< 0x00400000 */
#define EXTI_EMR_MR22             EXTI_EMR_MR22_Msk                            /*!< Event Mask on line 22 */
#define EXTI_EMR_MR23_Pos         (23U)
#define EXTI_EMR_MR23_Msk         (0x1U << EXTI_EMR_MR23_Pos)                  /*!< 0x00800000 */
#define EXTI_EMR_MR23             EXTI_EMR_MR23_Msk                            /*!< Event Mask on line 23 */
#define EXTI_EMR_MR25_Pos         (25U)
#define EXTI_EMR_MR25_Msk         (0x1U << EXTI_EMR_MR25_Pos)                  /*!< 0x02000000 */
#define EXTI_EMR_MR25             EXTI_EMR_MR25_Msk                            /*!< Event Mask on line 25 */
#define EXTI_EMR_MR26_Pos         (26U)
#define EXTI_EMR_MR26_Msk         (0x1U << EXTI_EMR_MR26_Pos)                  /*!< 0x04000000 */
#define EXTI_EMR_MR26             EXTI_EMR_MR26_Msk                            /*!< Event Mask on line 26 */
#define EXTI_EMR_MR27_Pos         (27U)
#define EXTI_EMR_MR27_Msk         (0x1U << EXTI_EMR_MR27_Pos)                  /*!< 0x08000000 */
#define EXTI_EMR_MR27             EXTI_EMR_MR27_Msk                            /*!< Event Mask on line 27 */
#define EXTI_EMR_MR28_Pos         (28U)
#define EXTI_EMR_MR28_Msk         (0x1U << EXTI_EMR_MR28_Pos)                  /*!< 0x10000000 */
#define EXTI_EMR_MR28             EXTI_EMR_MR28_Msk                            /*!< Event Mask on line 28 */
#define EXTI_EMR_MR31_Pos         (31U)
#define EXTI_EMR_MR31_Msk         (0x1U << EXTI_EMR_MR31_Pos)                  /*!< 0x80000000 */
#define EXTI_EMR_MR31             EXTI_EMR_MR31_Msk                            /*!< Event Mask on line 31 */

/* References Defines */
#define  EXTI_EMR_EM0 EXTI_EMR_MR0
#define  EXTI_EMR_EM1 EXTI_EMR_MR1
#define  EXTI_EMR_EM2 EXTI_EMR_MR2
#define  EXTI_EMR_EM3 EXTI_EMR_MR3
#define  EXTI_EMR_EM4 EXTI_EMR_MR4
#define  EXTI_EMR_EM5 EXTI_EMR_MR5
#define  EXTI_EMR_EM6 EXTI_EMR_MR6
#define  EXTI_EMR_EM7 EXTI_EMR_MR7
#define  EXTI_EMR_EM8 EXTI_EMR_MR8
#define  EXTI_EMR_EM9 EXTI_EMR_MR9
#define  EXTI_EMR_EM10 EXTI_EMR_MR10
#define  EXTI_EMR_EM11 EXTI_EMR_MR11
#define  EXTI_EMR_EM12 EXTI_EMR_MR12
#define  EXTI_EMR_EM13 EXTI_EMR_MR13
#define  EXTI_EMR_EM14 EXTI_EMR_MR14
#define  EXTI_EMR_EM15 EXTI_EMR_MR15
#define  EXTI_EMR_EM16 EXTI_EMR_MR16
#define  EXTI_EMR_EM17 EXTI_EMR_MR17
#define  EXTI_EMR_EM18 EXTI_EMR_MR18
#define  EXTI_EMR_EM19 EXTI_EMR_MR19
#define  EXTI_EMR_EM20 EXTI_EMR_MR20
#define  EXTI_EMR_EM21 EXTI_EMR_MR21
#define  EXTI_EMR_EM22 EXTI_EMR_MR22
#define  EXTI_EMR_EM23 EXTI_EMR_MR23
#define  EXTI_EMR_EM25 EXTI_EMR_MR25
#define  EXTI_EMR_EM26 EXTI_EMR_MR26
#define  EXTI_EMR_EM27 EXTI_EMR_MR27
#define  EXTI_EMR_EM28 EXTI_EMR_MR28
#define  EXTI_EMR_EM31 EXTI_EMR_MR31

/*******************  Bit definition for EXTI_RTSR register  ******************/
#define EXTI_RTSR_TR0_Pos         (0U)
#define EXTI_RTSR_TR0_Msk         (0x1U << EXTI_RTSR_TR0_Pos)                  /*!< 0x00000001 */
#define EXTI_RTSR_TR0             EXTI_RTSR_TR0_Msk                            /*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR_TR1_Pos         (1U)
#define EXTI_RTSR_TR1_Msk         (0x1U << EXTI_RTSR_TR1_Pos)                  /*!< 0x00000002 */
#define EXTI_RTSR_TR1             EXTI_RTSR_TR1_Msk                            /*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR_TR2_Pos         (2U)
#define EXTI_RTSR_TR2_Msk         (0x1U << EXTI_RTSR_TR2_Pos)                  /*!< 0x00000004 */
#define EXTI_RTSR_TR2             EXTI_RTSR_TR2_Msk                            /*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR_TR3_Pos         (3U)
#define EXTI_RTSR_TR3_Msk         (0x1U << EXTI_RTSR_TR3_Pos)                  /*!< 0x00000008 */
#define EXTI_RTSR_TR3             EXTI_RTSR_TR3_Msk                            /*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR_TR4_Pos         (4U)
#define EXTI_RTSR_TR4_Msk         (0x1U << EXTI_RTSR_TR4_Pos)                  /*!< 0x00000010 */
#define EXTI_RTSR_TR4             EXTI_RTSR_TR4_Msk                            /*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR_TR5_Pos         (5U)
#define EXTI_RTSR_TR5_Msk         (0x1U << EXTI_RTSR_TR5_Pos)                  /*!< 0x00000020 */
#define EXTI_RTSR_TR5             EXTI_RTSR_TR5_Msk                            /*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR_TR6_Pos         (6U)
#define EXTI_RTSR_TR6_Msk         (0x1U << EXTI_RTSR_TR6_Pos)                  /*!< 0x00000040 */
#define EXTI_RTSR_TR6             EXTI_RTSR_TR6_Msk                            /*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR_TR7_Pos         (7U)
#define EXTI_RTSR_TR7_Msk         (0x1U << EXTI_RTSR_TR7_Pos)                  /*!< 0x00000080 */
#define EXTI_RTSR_TR7             EXTI_RTSR_TR7_Msk                            /*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR_TR8_Pos         (8U)
#define EXTI_RTSR_TR8_Msk         (0x1U << EXTI_RTSR_TR8_Pos)                  /*!< 0x00000100 */
#define EXTI_RTSR_TR8             EXTI_RTSR_TR8_Msk                            /*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR_TR9_Pos         (9U)
#define EXTI_RTSR_TR9_Msk         (0x1U << EXTI_RTSR_TR9_Pos)                  /*!< 0x00000200 */
#define EXTI_RTSR_TR9             EXTI_RTSR_TR9_Msk                            /*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR_TR10_Pos        (10U)
#define EXTI_RTSR_TR10_Msk        (0x1U << EXTI_RTSR_TR10_Pos)                 /*!< 0x00000400 */
#define EXTI_RTSR_TR10            EXTI_RTSR_TR10_Msk                           /*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR_TR11_Pos        (11U)
#define EXTI_RTSR_TR11_Msk        (0x1U << EXTI_RTSR_TR11_Pos)                 /*!< 0x00000800 */
#define EXTI_RTSR_TR11            EXTI_RTSR_TR11_Msk                           /*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR_TR12_Pos        (12U)
#define EXTI_RTSR_TR12_Msk        (0x1U << EXTI_RTSR_TR12_Pos)                 /*!< 0x00001000 */
#define EXTI_RTSR_TR12            EXTI_RTSR_TR12_Msk                           /*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR_TR13_Pos        (13U)
#define EXTI_RTSR_TR13_Msk        (0x1U << EXTI_RTSR_TR13_Pos)                 /*!< 0x00002000 */
#define EXTI_RTSR_TR13            EXTI_RTSR_TR13_Msk                           /*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR_TR14_Pos        (14U)
#define EXTI_RTSR_TR14_Msk        (0x1U << EXTI_RTSR_TR14_Pos)                 /*!< 0x00004000 */
#define EXTI_RTSR_TR14            EXTI_RTSR_TR14_Msk                           /*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR_TR15_Pos        (15U)
#define EXTI_RTSR_TR15_Msk        (0x1U << EXTI_RTSR_TR15_Pos)                 /*!< 0x00008000 */
#define EXTI_RTSR_TR15            EXTI_RTSR_TR15_Msk                           /*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR_TR16_Pos        (16U)
#define EXTI_RTSR_TR16_Msk        (0x1U << EXTI_RTSR_TR16_Pos)                 /*!< 0x00010000 */
#define EXTI_RTSR_TR16            EXTI_RTSR_TR16_Msk                           /*!< Rising trigger event configuration bit of line 16 */
#define EXTI_RTSR_TR17_Pos        (17U)
#define EXTI_RTSR_TR17_Msk        (0x1U << EXTI_RTSR_TR17_Pos)                 /*!< 0x00020000 */
#define EXTI_RTSR_TR17            EXTI_RTSR_TR17_Msk                           /*!< Rising trigger event configuration bit of line 17 */
#define EXTI_RTSR_TR19_Pos        (19U)
#define EXTI_RTSR_TR19_Msk        (0x1U << EXTI_RTSR_TR19_Pos)                 /*!< 0x00080000 */
#define EXTI_RTSR_TR19            EXTI_RTSR_TR19_Msk                           /*!< Rising trigger event configuration bit of line 19 */
#define EXTI_RTSR_TR20_Pos        (20U)
#define EXTI_RTSR_TR20_Msk        (0x1U << EXTI_RTSR_TR20_Pos)                 /*!< 0x00100000 */
#define EXTI_RTSR_TR20            EXTI_RTSR_TR20_Msk                           /*!< Rising trigger event configuration bit of line 20 */
#define EXTI_RTSR_TR21_Pos        (21U)
#define EXTI_RTSR_TR21_Msk        (0x1U << EXTI_RTSR_TR21_Pos)                 /*!< 0x00200000 */
#define EXTI_RTSR_TR21            EXTI_RTSR_TR21_Msk                           /*!< Rising trigger event configuration bit of line 21 */
#define EXTI_RTSR_TR22_Pos        (22U)
#define EXTI_RTSR_TR22_Msk        (0x1U << EXTI_RTSR_TR22_Pos)                 /*!< 0x00400000 */
#define EXTI_RTSR_TR22            EXTI_RTSR_TR22_Msk                           /*!< Rising trigger event configuration bit of line 22 */
#define EXTI_RTSR_TR31_Pos        (31U)
#define EXTI_RTSR_TR31_Msk        (0x1U << EXTI_RTSR_TR31_Pos)                 /*!< 0x80000000 */
#define EXTI_RTSR_TR31            EXTI_RTSR_TR31_Msk                           /*!< Rising trigger event configuration bit of line 31 */

/* References Defines */
#define EXTI_RTSR_RT0 EXTI_RTSR_TR0
#define EXTI_RTSR_RT1 EXTI_RTSR_TR1
#define EXTI_RTSR_RT2 EXTI_RTSR_TR2
#define EXTI_RTSR_RT3 EXTI_RTSR_TR3
#define EXTI_RTSR_RT4 EXTI_RTSR_TR4
#define EXTI_RTSR_RT5 EXTI_RTSR_TR5
#define EXTI_RTSR_RT6 EXTI_RTSR_TR6
#define EXTI_RTSR_RT7 EXTI_RTSR_TR7
#define EXTI_RTSR_RT8 EXTI_RTSR_TR8
#define EXTI_RTSR_RT9 EXTI_RTSR_TR9
#define EXTI_RTSR_RT10 EXTI_RTSR_TR10
#define EXTI_RTSR_RT11 EXTI_RTSR_TR11
#define EXTI_RTSR_RT12 EXTI_RTSR_TR12
#define EXTI_RTSR_RT13 EXTI_RTSR_TR13
#define EXTI_RTSR_RT14 EXTI_RTSR_TR14
#define EXTI_RTSR_RT15 EXTI_RTSR_TR15
#define EXTI_RTSR_RT16 EXTI_RTSR_TR16
#define EXTI_RTSR_RT17 EXTI_RTSR_TR17
#define EXTI_RTSR_RT19 EXTI_RTSR_TR19
#define EXTI_RTSR_RT20 EXTI_RTSR_TR20
#define EXTI_RTSR_RT21 EXTI_RTSR_TR21
#define EXTI_RTSR_RT22 EXTI_RTSR_TR22
#define  EXTI_RTSR_RT31 EXTI_RTSR_TR31

/*******************  Bit definition for EXTI_FTSR register *******************/
#define EXTI_FTSR_TR0_Pos         (0U)
#define EXTI_FTSR_TR0_Msk         (0x1U << EXTI_FTSR_TR0_Pos)                  /*!< 0x00000001 */
#define EXTI_FTSR_TR0             EXTI_FTSR_TR0_Msk                            /*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR_TR1_Pos         (1U)
#define EXTI_FTSR_TR1_Msk         (0x1U << EXTI_FTSR_TR1_Pos)                  /*!< 0x00000002 */
#define EXTI_FTSR_TR1             EXTI_FTSR_TR1_Msk                            /*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR_TR2_Pos         (2U)
#define EXTI_FTSR_TR2_Msk         (0x1U << EXTI_FTSR_TR2_Pos)                  /*!< 0x00000004 */
#define EXTI_FTSR_TR2             EXTI_FTSR_TR2_Msk                            /*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR_TR3_Pos         (3U)
#define EXTI_FTSR_TR3_Msk         (0x1U << EXTI_FTSR_TR3_Pos)                  /*!< 0x00000008 */
#define EXTI_FTSR_TR3             EXTI_FTSR_TR3_Msk                            /*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR_TR4_Pos         (4U)
#define EXTI_FTSR_TR4_Msk         (0x1U << EXTI_FTSR_TR4_Pos)                  /*!< 0x00000010 */
#define EXTI_FTSR_TR4             EXTI_FTSR_TR4_Msk                            /*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR_TR5_Pos         (5U)
#define EXTI_FTSR_TR5_Msk         (0x1U << EXTI_FTSR_TR5_Pos)                  /*!< 0x00000020 */
#define EXTI_FTSR_TR5             EXTI_FTSR_TR5_Msk                            /*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR_TR6_Pos         (6U)
#define EXTI_FTSR_TR6_Msk         (0x1U << EXTI_FTSR_TR6_Pos)                  /*!< 0x00000040 */
#define EXTI_FTSR_TR6             EXTI_FTSR_TR6_Msk                            /*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR_TR7_Pos         (7U)
#define EXTI_FTSR_TR7_Msk         (0x1U << EXTI_FTSR_TR7_Pos)                  /*!< 0x00000080 */
#define EXTI_FTSR_TR7             EXTI_FTSR_TR7_Msk                            /*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR_TR8_Pos         (8U)
#define EXTI_FTSR_TR8_Msk         (0x1U << EXTI_FTSR_TR8_Pos)                  /*!< 0x00000100 */
#define EXTI_FTSR_TR8             EXTI_FTSR_TR8_Msk                            /*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR_TR9_Pos         (9U)
#define EXTI_FTSR_TR9_Msk         (0x1U << EXTI_FTSR_TR9_Pos)                  /*!< 0x00000200 */
#define EXTI_FTSR_TR9             EXTI_FTSR_TR9_Msk                            /*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR_TR10_Pos        (10U)
#define EXTI_FTSR_TR10_Msk        (0x1U << EXTI_FTSR_TR10_Pos)                 /*!< 0x00000400 */
#define EXTI_FTSR_TR10            EXTI_FTSR_TR10_Msk                           /*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR_TR11_Pos        (11U)
#define EXTI_FTSR_TR11_Msk        (0x1U << EXTI_FTSR_TR11_Pos)                 /*!< 0x00000800 */
#define EXTI_FTSR_TR11            EXTI_FTSR_TR11_Msk                           /*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR_TR12_Pos        (12U)
#define EXTI_FTSR_TR12_Msk        (0x1U << EXTI_FTSR_TR12_Pos)                 /*!< 0x00001000 */
#define EXTI_FTSR_TR12            EXTI_FTSR_TR12_Msk                           /*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR_TR13_Pos        (13U)
#define EXTI_FTSR_TR13_Msk        (0x1U << EXTI_FTSR_TR13_Pos)                 /*!< 0x00002000 */
#define EXTI_FTSR_TR13            EXTI_FTSR_TR13_Msk                           /*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR_TR14_Pos        (14U)
#define EXTI_FTSR_TR14_Msk        (0x1U << EXTI_FTSR_TR14_Pos)                 /*!< 0x00004000 */
#define EXTI_FTSR_TR14            EXTI_FTSR_TR14_Msk                           /*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR_TR15_Pos        (15U)
#define EXTI_FTSR_TR15_Msk        (0x1U << EXTI_FTSR_TR15_Pos)                 /*!< 0x00008000 */
#define EXTI_FTSR_TR15            EXTI_FTSR_TR15_Msk                           /*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR_TR16_Pos        (16U)
#define EXTI_FTSR_TR16_Msk        (0x1U << EXTI_FTSR_TR16_Pos)                 /*!< 0x00010000 */
#define EXTI_FTSR_TR16            EXTI_FTSR_TR16_Msk                           /*!< Falling trigger event configuration bit of line 16 */
#define EXTI_FTSR_TR17_Pos        (17U)
#define EXTI_FTSR_TR17_Msk        (0x1U << EXTI_FTSR_TR17_Pos)                 /*!< 0x00020000 */
#define EXTI_FTSR_TR17            EXTI_FTSR_TR17_Msk                           /*!< Falling trigger event configuration bit of line 17 */
#define EXTI_FTSR_TR19_Pos        (19U)
#define EXTI_FTSR_TR19_Msk        (0x1U << EXTI_FTSR_TR19_Pos)                 /*!< 0x00080000 */
#define EXTI_FTSR_TR19            EXTI_FTSR_TR19_Msk                           /*!< Falling trigger event configuration bit of line 19 */
#define EXTI_FTSR_TR20_Pos        (20U)
#define EXTI_FTSR_TR20_Msk        (0x1U << EXTI_FTSR_TR20_Pos)                 /*!< 0x00100000 */
#define EXTI_FTSR_TR20            EXTI_FTSR_TR20_Msk                           /*!< Falling trigger event configuration bit of line 20 */
#define EXTI_FTSR_TR21_Pos        (21U)
#define EXTI_FTSR_TR21_Msk        (0x1U << EXTI_FTSR_TR21_Pos)                 /*!< 0x00200000 */
#define EXTI_FTSR_TR21            EXTI_FTSR_TR21_Msk                           /*!< Falling trigger event configuration bit of line 21 */
#define EXTI_FTSR_TR22_Pos        (22U)
#define EXTI_FTSR_TR22_Msk        (0x1U << EXTI_FTSR_TR22_Pos)                 /*!< 0x00400000 */
#define EXTI_FTSR_TR22            EXTI_FTSR_TR22_Msk                           /*!< Falling trigger event configuration bit of line 22 */
#define EXTI_FTSR_TR31_Pos        (31U)
#define EXTI_FTSR_TR31_Msk        (0x1U << EXTI_FTSR_TR31_Pos)                 /*!< 0x80000000 */
#define EXTI_FTSR_TR31            EXTI_FTSR_TR31_Msk                           /*!< Falling trigger event configuration bit of line 31 */

/* References Defines */
#define EXTI_FTSR_FT0 EXTI_FTSR_TR0
#define EXTI_FTSR_FT1 EXTI_FTSR_TR1
#define EXTI_FTSR_FT2 EXTI_FTSR_TR2
#define EXTI_FTSR_FT3 EXTI_FTSR_TR3
#define EXTI_FTSR_FT4 EXTI_FTSR_TR4
#define EXTI_FTSR_FT5 EXTI_FTSR_TR5
#define EXTI_FTSR_FT6 EXTI_FTSR_TR6
#define EXTI_FTSR_FT7 EXTI_FTSR_TR7
#define EXTI_FTSR_FT8 EXTI_FTSR_TR8
#define EXTI_FTSR_FT9 EXTI_FTSR_TR9
#define EXTI_FTSR_FT10 EXTI_FTSR_TR10
#define EXTI_FTSR_FT11 EXTI_FTSR_TR11
#define EXTI_FTSR_FT12 EXTI_FTSR_TR12
#define EXTI_FTSR_FT13 EXTI_FTSR_TR13
#define EXTI_FTSR_FT14 EXTI_FTSR_TR14
#define EXTI_FTSR_FT15 EXTI_FTSR_TR15
#define EXTI_FTSR_FT16 EXTI_FTSR_TR16
#define EXTI_FTSR_FT17 EXTI_FTSR_TR17
#define EXTI_FTSR_FT19 EXTI_FTSR_TR19
#define EXTI_FTSR_FT20 EXTI_FTSR_TR20
#define EXTI_FTSR_FT21 EXTI_FTSR_TR21
#define EXTI_FTSR_FT22 EXTI_FTSR_TR22
#define EXTI_FTSR_FT31 EXTI_FTSR_TR31

/******************* Bit definition for EXTI_SWIER register *******************/
#define EXTI_SWIER_SWIER0_Pos     (0U)
#define EXTI_SWIER_SWIER0_Msk     (0x1U << EXTI_SWIER_SWIER0_Pos)              /*!< 0x00000001 */
#define EXTI_SWIER_SWIER0         EXTI_SWIER_SWIER0_Msk                        /*!< Software Interrupt on line 0  */
#define EXTI_SWIER_SWIER1_Pos     (1U)
#define EXTI_SWIER_SWIER1_Msk     (0x1U << EXTI_SWIER_SWIER1_Pos)              /*!< 0x00000002 */
#define EXTI_SWIER_SWIER1         EXTI_SWIER_SWIER1_Msk                        /*!< Software Interrupt on line 1  */
#define EXTI_SWIER_SWIER2_Pos     (2U)
#define EXTI_SWIER_SWIER2_Msk     (0x1U << EXTI_SWIER_SWIER2_Pos)              /*!< 0x00000004 */
#define EXTI_SWIER_SWIER2         EXTI_SWIER_SWIER2_Msk                        /*!< Software Interrupt on line 2  */
#define EXTI_SWIER_SWIER3_Pos     (3U)
#define EXTI_SWIER_SWIER3_Msk     (0x1U << EXTI_SWIER_SWIER3_Pos)              /*!< 0x00000008 */
#define EXTI_SWIER_SWIER3         EXTI_SWIER_SWIER3_Msk                        /*!< Software Interrupt on line 3  */
#define EXTI_SWIER_SWIER4_Pos     (4U)
#define EXTI_SWIER_SWIER4_Msk     (0x1U << EXTI_SWIER_SWIER4_Pos)              /*!< 0x00000010 */
#define EXTI_SWIER_SWIER4         EXTI_SWIER_SWIER4_Msk                        /*!< Software Interrupt on line 4  */
#define EXTI_SWIER_SWIER5_Pos     (5U)
#define EXTI_SWIER_SWIER5_Msk     (0x1U << EXTI_SWIER_SWIER5_Pos)              /*!< 0x00000020 */
#define EXTI_SWIER_SWIER5         EXTI_SWIER_SWIER5_Msk                        /*!< Software Interrupt on line 5  */
#define EXTI_SWIER_SWIER6_Pos     (6U)
#define EXTI_SWIER_SWIER6_Msk     (0x1U << EXTI_SWIER_SWIER6_Pos)              /*!< 0x00000040 */
#define EXTI_SWIER_SWIER6         EXTI_SWIER_SWIER6_Msk                        /*!< Software Interrupt on line 6  */
#define EXTI_SWIER_SWIER7_Pos     (7U)
#define EXTI_SWIER_SWIER7_Msk     (0x1U << EXTI_SWIER_SWIER7_Pos)              /*!< 0x00000080 */
#define EXTI_SWIER_SWIER7         EXTI_SWIER_SWIER7_Msk                        /*!< Software Interrupt on line 7  */
#define EXTI_SWIER_SWIER8_Pos     (8U)
#define EXTI_SWIER_SWIER8_Msk     (0x1U << EXTI_SWIER_SWIER8_Pos)              /*!< 0x00000100 */
#define EXTI_SWIER_SWIER8         EXTI_SWIER_SWIER8_Msk                        /*!< Software Interrupt on line 8  */
#define EXTI_SWIER_SWIER9_Pos     (9U)
#define EXTI_SWIER_SWIER9_Msk     (0x1U << EXTI_SWIER_SWIER9_Pos)              /*!< 0x00000200 */
#define EXTI_SWIER_SWIER9         EXTI_SWIER_SWIER9_Msk                        /*!< Software Interrupt on line 9  */
#define EXTI_SWIER_SWIER10_Pos    (10U)
#define EXTI_SWIER_SWIER10_Msk    (0x1U << EXTI_SWIER_SWIER10_Pos)             /*!< 0x00000400 */
#define EXTI_SWIER_SWIER10        EXTI_SWIER_SWIER10_Msk                       /*!< Software Interrupt on line 10 */
#define EXTI_SWIER_SWIER11_Pos    (11U)
#define EXTI_SWIER_SWIER11_Msk    (0x1U << EXTI_SWIER_SWIER11_Pos)             /*!< 0x00000800 */
#define EXTI_SWIER_SWIER11        EXTI_SWIER_SWIER11_Msk                       /*!< Software Interrupt on line 11 */
#define EXTI_SWIER_SWIER12_Pos    (12U)
#define EXTI_SWIER_SWIER12_Msk    (0x1U << EXTI_SWIER_SWIER12_Pos)             /*!< 0x00001000 */
#define EXTI_SWIER_SWIER12        EXTI_SWIER_SWIER12_Msk                       /*!< Software Interrupt on line 12 */
#define EXTI_SWIER_SWIER13_Pos    (13U)
#define EXTI_SWIER_SWIER13_Msk    (0x1U << EXTI_SWIER_SWIER13_Pos)             /*!< 0x00002000 */
#define EXTI_SWIER_SWIER13        EXTI_SWIER_SWIER13_Msk                       /*!< Software Interrupt on line 13 */
#define EXTI_SWIER_SWIER14_Pos    (14U)
#define EXTI_SWIER_SWIER14_Msk    (0x1U << EXTI_SWIER_SWIER14_Pos)             /*!< 0x00004000 */
#define EXTI_SWIER_SWIER14        EXTI_SWIER_SWIER14_Msk                       /*!< Software Interrupt on line 14 */
#define EXTI_SWIER_SWIER15_Pos    (15U)
#define EXTI_SWIER_SWIER15_Msk    (0x1U << EXTI_SWIER_SWIER15_Pos)             /*!< 0x00008000 */
#define EXTI_SWIER_SWIER15        EXTI_SWIER_SWIER15_Msk                       /*!< Software Interrupt on line 15 */
#define EXTI_SWIER_SWIER16_Pos    (16U)
#define EXTI_SWIER_SWIER16_Msk    (0x1U << EXTI_SWIER_SWIER16_Pos)             /*!< 0x00010000 */
#define EXTI_SWIER_SWIER16        EXTI_SWIER_SWIER16_Msk                       /*!< Software Interrupt on line 16 */
#define EXTI_SWIER_SWIER17_Pos    (17U)
#define EXTI_SWIER_SWIER17_Msk    (0x1U << EXTI_SWIER_SWIER17_Pos)             /*!< 0x00020000 */
#define EXTI_SWIER_SWIER17        EXTI_SWIER_SWIER17_Msk                       /*!< Software Interrupt on line 17 */
#define EXTI_SWIER_SWIER19_Pos    (19U)
#define EXTI_SWIER_SWIER19_Msk    (0x1U << EXTI_SWIER_SWIER19_Pos)             /*!< 0x00080000 */
#define EXTI_SWIER_SWIER19        EXTI_SWIER_SWIER19_Msk                       /*!< Software Interrupt on line 19 */
#define EXTI_SWIER_SWIER20_Pos    (20U)
#define EXTI_SWIER_SWIER20_Msk    (0x1U << EXTI_SWIER_SWIER20_Pos)             /*!< 0x00100000 */
#define EXTI_SWIER_SWIER20        EXTI_SWIER_SWIER20_Msk                       /*!< Software Interrupt on line 20 */
#define EXTI_SWIER_SWIER21_Pos    (21U)
#define EXTI_SWIER_SWIER21_Msk    (0x1U << EXTI_SWIER_SWIER21_Pos)             /*!< 0x00200000 */
#define EXTI_SWIER_SWIER21        EXTI_SWIER_SWIER21_Msk                       /*!< Software Interrupt on line 21 */
#define EXTI_SWIER_SWIER22_Pos    (22U)
#define EXTI_SWIER_SWIER22_Msk    (0x1U << EXTI_SWIER_SWIER22_Pos)             /*!< 0x00400000 */
#define EXTI_SWIER_SWIER22        EXTI_SWIER_SWIER22_Msk                       /*!< Software Interrupt on line 22 */
#define EXTI_SWIER_SWIER31_Pos    (31U)
#define EXTI_SWIER_SWIER31_Msk    (0x1U << EXTI_SWIER_SWIER31_Pos)             /*!< 0x80000000 */
#define EXTI_SWIER_SWIER31        EXTI_SWIER_SWIER31_Msk                       /*!< Software Interrupt on line 31 */

/* References Defines */
#define EXTI_SWIER_SWI0 EXTI_SWIER_SWIER0
#define EXTI_SWIER_SWI1 EXTI_SWIER_SWIER1
#define EXTI_SWIER_SWI2 EXTI_SWIER_SWIER2
#define EXTI_SWIER_SWI3 EXTI_SWIER_SWIER3
#define EXTI_SWIER_SWI4 EXTI_SWIER_SWIER4
#define EXTI_SWIER_SWI5 EXTI_SWIER_SWIER5
#define EXTI_SWIER_SWI6 EXTI_SWIER_SWIER6
#define EXTI_SWIER_SWI7 EXTI_SWIER_SWIER7
#define EXTI_SWIER_SWI8 EXTI_SWIER_SWIER8
#define EXTI_SWIER_SWI9 EXTI_SWIER_SWIER9
#define EXTI_SWIER_SWI10 EXTI_SWIER_SWIER10
#define EXTI_SWIER_SWI11 EXTI_SWIER_SWIER11
#define EXTI_SWIER_SWI12 EXTI_SWIER_SWIER12
#define EXTI_SWIER_SWI13 EXTI_SWIER_SWIER13
#define EXTI_SWIER_SWI14 EXTI_SWIER_SWIER14
#define EXTI_SWIER_SWI15 EXTI_SWIER_SWIER15
#define EXTI_SWIER_SWI16 EXTI_SWIER_SWIER16
#define EXTI_SWIER_SWI17 EXTI_SWIER_SWIER17
#define EXTI_SWIER_SWI19 EXTI_SWIER_SWIER19
#define EXTI_SWIER_SWI20 EXTI_SWIER_SWIER20
#define EXTI_SWIER_SWI21 EXTI_SWIER_SWIER21
#define EXTI_SWIER_SWI22 EXTI_SWIER_SWIER22
#define  EXTI_SWIER_SWI31 EXTI_SWIER_SWIER31

/******************  Bit definition for EXTI_PR register  *********************/
#define EXTI_PR_PR0_Pos           (0U)
#define EXTI_PR_PR0_Msk           (0x1U << EXTI_PR_PR0_Pos)                    /*!< 0x00000001 */
#define EXTI_PR_PR0               EXTI_PR_PR0_Msk                              /*!< Pending bit 0  */
#define EXTI_PR_PR1_Pos           (1U)
#define EXTI_PR_PR1_Msk           (0x1U << EXTI_PR_PR1_Pos)                    /*!< 0x00000002 */
#define EXTI_PR_PR1               EXTI_PR_PR1_Msk                              /*!< Pending bit 1  */
#define EXTI_PR_PR2_Pos           (2U)
#define EXTI_PR_PR2_Msk           (0x1U << EXTI_PR_PR2_Pos)                    /*!< 0x00000004 */
#define EXTI_PR_PR2               EXTI_PR_PR2_Msk                              /*!< Pending bit 2  */
#define EXTI_PR_PR3_Pos           (3U)
#define EXTI_PR_PR3_Msk           (0x1U << EXTI_PR_PR3_Pos)                    /*!< 0x00000008 */
#define EXTI_PR_PR3               EXTI_PR_PR3_Msk                              /*!< Pending bit 3  */
#define EXTI_PR_PR4_Pos           (4U)
#define EXTI_PR_PR4_Msk           (0x1U << EXTI_PR_PR4_Pos)                    /*!< 0x00000010 */
#define EXTI_PR_PR4               EXTI_PR_PR4_Msk                              /*!< Pending bit 4  */
#define EXTI_PR_PR5_Pos           (5U)
#define EXTI_PR_PR5_Msk           (0x1U << EXTI_PR_PR5_Pos)                    /*!< 0x00000020 */
#define EXTI_PR_PR5               EXTI_PR_PR5_Msk                              /*!< Pending bit 5  */
#define EXTI_PR_PR6_Pos           (6U)
#define EXTI_PR_PR6_Msk           (0x1U << EXTI_PR_PR6_Pos)                    /*!< 0x00000040 */
#define EXTI_PR_PR6               EXTI_PR_PR6_Msk                              /*!< Pending bit 6  */
#define EXTI_PR_PR7_Pos           (7U)
#define EXTI_PR_PR7_Msk           (0x1U << EXTI_PR_PR7_Pos)                    /*!< 0x00000080 */
#define EXTI_PR_PR7               EXTI_PR_PR7_Msk                              /*!< Pending bit 7  */
#define EXTI_PR_PR8_Pos           (8U)
#define EXTI_PR_PR8_Msk           (0x1U << EXTI_PR_PR8_Pos)                    /*!< 0x00000100 */
#define EXTI_PR_PR8               EXTI_PR_PR8_Msk                              /*!< Pending bit 8  */
#define EXTI_PR_PR9_Pos           (9U)
#define EXTI_PR_PR9_Msk           (0x1U << EXTI_PR_PR9_Pos)                    /*!< 0x00000200 */
#define EXTI_PR_PR9               EXTI_PR_PR9_Msk                              /*!< Pending bit 9  */
#define EXTI_PR_PR10_Pos          (10U)
#define EXTI_PR_PR10_Msk          (0x1U << EXTI_PR_PR10_Pos)                   /*!< 0x00000400 */
#define EXTI_PR_PR10              EXTI_PR_PR10_Msk                             /*!< Pending bit 10 */
#define EXTI_PR_PR11_Pos          (11U)
#define EXTI_PR_PR11_Msk          (0x1U << EXTI_PR_PR11_Pos)                   /*!< 0x00000800 */
#define EXTI_PR_PR11              EXTI_PR_PR11_Msk                             /*!< Pending bit 11 */
#define EXTI_PR_PR12_Pos          (12U)
#define EXTI_PR_PR12_Msk          (0x1U << EXTI_PR_PR12_Pos)                   /*!< 0x00001000 */
#define EXTI_PR_PR12              EXTI_PR_PR12_Msk                             /*!< Pending bit 12 */
#define EXTI_PR_PR13_Pos          (13U)
#define EXTI_PR_PR13_Msk          (0x1U << EXTI_PR_PR13_Pos)                   /*!< 0x00002000 */
#define EXTI_PR_PR13              EXTI_PR_PR13_Msk                             /*!< Pending bit 13 */
#define EXTI_PR_PR14_Pos          (14U)
#define EXTI_PR_PR14_Msk          (0x1U << EXTI_PR_PR14_Pos)                   /*!< 0x00004000 */
#define EXTI_PR_PR14              EXTI_PR_PR14_Msk                             /*!< Pending bit 14 */
#define EXTI_PR_PR15_Pos          (15U)
#define EXTI_PR_PR15_Msk          (0x1U << EXTI_PR_PR15_Pos)                   /*!< 0x00008000 */
#define EXTI_PR_PR15              EXTI_PR_PR15_Msk                             /*!< Pending bit 15 */
#define EXTI_PR_PR16_Pos          (16U)
#define EXTI_PR_PR16_Msk          (0x1U << EXTI_PR_PR16_Pos)                   /*!< 0x00010000 */
#define EXTI_PR_PR16              EXTI_PR_PR16_Msk                             /*!< Pending bit 16 */
#define EXTI_PR_PR17_Pos          (17U)
#define EXTI_PR_PR17_Msk          (0x1U << EXTI_PR_PR17_Pos)                   /*!< 0x00020000 */
#define EXTI_PR_PR17              EXTI_PR_PR17_Msk                             /*!< Pending bit 17 */
#define EXTI_PR_PR19_Pos          (19U)
#define EXTI_PR_PR19_Msk          (0x1U << EXTI_PR_PR19_Pos)                   /*!< 0x00080000 */
#define EXTI_PR_PR19              EXTI_PR_PR19_Msk                             /*!< Pending bit 19 */
#define EXTI_PR_PR20_Pos          (20U)
#define EXTI_PR_PR20_Msk          (0x1U << EXTI_PR_PR20_Pos)                   /*!< 0x00100000 */
#define EXTI_PR_PR20              EXTI_PR_PR20_Msk                             /*!< Pending bit 20 */
#define EXTI_PR_PR21_Pos          (21U)
#define EXTI_PR_PR21_Msk          (0x1U << EXTI_PR_PR21_Pos)                   /*!< 0x00200000 */
#define EXTI_PR_PR21              EXTI_PR_PR21_Msk                             /*!< Pending bit 21 */
#define EXTI_PR_PR22_Pos          (22U)
#define EXTI_PR_PR22_Msk          (0x1U << EXTI_PR_PR22_Pos)                   /*!< 0x00400000 */
#define EXTI_PR_PR22              EXTI_PR_PR22_Msk                             /*!< Pending bit 22 */
#define EXTI_PR_PR31_Pos          (31U)
#define EXTI_PR_PR31_Msk          (0x1U << EXTI_PR_PR31_Pos)                   /*!< 0x80000000 */
#define EXTI_PR_PR31              EXTI_PR_PR31_Msk                             /*!< Pending bit 31 */

/* References Defines */
#define EXTI_PR_PIF0 EXTI_PR_PR0
#define EXTI_PR_PIF1 EXTI_PR_PR1
#define EXTI_PR_PIF2 EXTI_PR_PR2
#define EXTI_PR_PIF3 EXTI_PR_PR3
#define EXTI_PR_PIF4 EXTI_PR_PR4
#define EXTI_PR_PIF5 EXTI_PR_PR5
#define EXTI_PR_PIF6 EXTI_PR_PR6
#define EXTI_PR_PIF7 EXTI_PR_PR7
#define EXTI_PR_PIF8 EXTI_PR_PR8
#define EXTI_PR_PIF9 EXTI_PR_PR9
#define EXTI_PR_PIF10 EXTI_PR_PR10
#define EXTI_PR_PIF11 EXTI_PR_PR11
#define EXTI_PR_PIF12 EXTI_PR_PR12
#define EXTI_PR_PIF13 EXTI_PR_PR13
#define EXTI_PR_PIF14 EXTI_PR_PR14
#define EXTI_PR_PIF15 EXTI_PR_PR15
#define EXTI_PR_PIF16 EXTI_PR_PR16
#define EXTI_PR_PIF17 EXTI_PR_PR17
#define EXTI_PR_PIF19 EXTI_PR_PR19
#define EXTI_PR_PIF20 EXTI_PR_PR20
#define EXTI_PR_PIF21 EXTI_PR_PR21
#define EXTI_PR_PIF22 EXTI_PR_PR22
#define EXTI_PR_PIF31 EXTI_PR_PR31

/******************************************************************************/
/*                                                                            */
/*                      FLASH and Option Bytes Registers                      */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for FLASH_ACR register  ******************/
#define FLASH_ACR_LATENCY_Pos             (0U)
#define FLASH_ACR_LATENCY_Msk             (0x1U << FLASH_ACR_LATENCY_Pos)      /*!< 0x00000001 */
#define FLASH_ACR_LATENCY                 FLASH_ACR_LATENCY_Msk                /*!< LATENCY bit (Latency) */

#define FLASH_ACR_PRFTBE_Pos              (4U)
#define FLASH_ACR_PRFTBE_Msk              (0x1U << FLASH_ACR_PRFTBE_Pos)       /*!< 0x00000010 */
#define FLASH_ACR_PRFTBE                  FLASH_ACR_PRFTBE_Msk                 /*!< Prefetch Buffer Enable */
#define FLASH_ACR_PRFTBS_Pos              (5U)
#define FLASH_ACR_PRFTBS_Msk              (0x1U << FLASH_ACR_PRFTBS_Pos)       /*!< 0x00000020 */
#define FLASH_ACR_PRFTBS                  FLASH_ACR_PRFTBS_Msk                 /*!< Prefetch Buffer Status */

/******************  Bit definition for FLASH_KEYR register  ******************/
#define FLASH_KEYR_FKEYR_Pos              (0U)
#define FLASH_KEYR_FKEYR_Msk              (0xFFFFFFFFU << FLASH_KEYR_FKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_KEYR_FKEYR                  FLASH_KEYR_FKEYR_Msk                 /*!< FPEC Key */

/*****************  Bit definition for FLASH_OPTKEYR register  ****************/
#define FLASH_OPTKEYR_OPTKEYR_Pos         (0U)
#define FLASH_OPTKEYR_OPTKEYR_Msk         (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEYR             FLASH_OPTKEYR_OPTKEYR_Msk            /*!< Option Byte Key */

/******************  FLASH Keys  **********************************************/
#define FLASH_KEY1_Pos                    (0U)
#define FLASH_KEY1_Msk                    (0x45670123U << FLASH_KEY1_Pos)      /*!< 0x45670123 */
#define FLASH_KEY1                        FLASH_KEY1_Msk                       /*!< Flash program erase key1 */
#define FLASH_KEY2_Pos                    (0U)
#define FLASH_KEY2_Msk                    (0xCDEF89ABU << FLASH_KEY2_Pos)      /*!< 0xCDEF89AB */
#define FLASH_KEY2                        FLASH_KEY2_Msk                       /*!< Flash program erase key2: used with FLASH_PEKEY1
                                                                                to unlock the write access to the FPEC. */

#define FLASH_OPTKEY1_Pos                 (0U)
#define FLASH_OPTKEY1_Msk                 (0x45670123U << FLASH_OPTKEY1_Pos)   /*!< 0x45670123 */
#define FLASH_OPTKEY1                     FLASH_OPTKEY1_Msk                    /*!< Flash option key1 */
#define FLASH_OPTKEY2_Pos                 (0U)
#define FLASH_OPTKEY2_Msk                 (0xCDEF89ABU << FLASH_OPTKEY2_Pos)   /*!< 0xCDEF89AB */
#define FLASH_OPTKEY2                     FLASH_OPTKEY2_Msk                    /*!< Flash option key2: used with FLASH_OPTKEY1 to
                                                                                unlock the write access to the option byte block */

/******************  Bit definition for FLASH_SR register  *******************/
#define FLASH_SR_BSY_Pos                  (0U)
#define FLASH_SR_BSY_Msk                  (0x1U << FLASH_SR_BSY_Pos)           /*!< 0x00000001 */
#define FLASH_SR_BSY                      FLASH_SR_BSY_Msk                     /*!< Busy */
#define FLASH_SR_PGERR_Pos                (2U)
#define FLASH_SR_PGERR_Msk                (0x1U << FLASH_SR_PGERR_Pos)         /*!< 0x00000004 */
#define FLASH_SR_PGERR                    FLASH_SR_PGERR_Msk                   /*!< Programming Error */
#define FLASH_SR_WRPRTERR_Pos             (4U)
#define FLASH_SR_WRPRTERR_Msk             (0x1U << FLASH_SR_WRPRTERR_Pos)      /*!< 0x00000010 */
#define FLASH_SR_WRPRTERR                 FLASH_SR_WRPRTERR_Msk                /*!< Write Protection Error */
#define FLASH_SR_EOP_Pos                  (5U)
#define FLASH_SR_EOP_Msk                  (0x1U << FLASH_SR_EOP_Pos)           /*!< 0x00000020 */
#define FLASH_SR_EOP                      FLASH_SR_EOP_Msk                     /*!< End of operation */
#define  FLASH_SR_WRPERR                     FLASH_SR_WRPRTERR             /*!< Legacy of Write Protection Error */

/*******************  Bit definition for FLASH_CR register  *******************/
#define FLASH_CR_PG_Pos                   (0U)
#define FLASH_CR_PG_Msk                   (0x1U << FLASH_CR_PG_Pos)            /*!< 0x00000001 */
#define FLASH_CR_PG                       FLASH_CR_PG_Msk                      /*!< Programming */
#define FLASH_CR_PER_Pos                  (1U)
#define FLASH_CR_PER_Msk                  (0x1U << FLASH_CR_PER_Pos)           /*!< 0x00000002 */
#define FLASH_CR_PER                      FLASH_CR_PER_Msk                     /*!< Page Erase */
#define FLASH_CR_MER_Pos                  (2U)
#define FLASH_CR_MER_Msk                  (0x1U << FLASH_CR_MER_Pos)           /*!< 0x00000004 */
#define FLASH_CR_MER                      FLASH_CR_MER_Msk                     /*!< Mass Erase */
#define FLASH_CR_OPTPG_Pos                (4U)
#define FLASH_CR_OPTPG_Msk                (0x1U << FLASH_CR_OPTPG_Pos)         /*!< 0x00000010 */
#define FLASH_CR_OPTPG                    FLASH_CR_OPTPG_Msk                   /*!< Option Byte Programming */
#define FLASH_CR_OPTER_Pos                (5U)
#define FLASH_CR_OPTER_Msk                (0x1U << FLASH_CR_OPTER_Pos)         /*!< 0x00000020 */
#define FLASH_CR_OPTER                    FLASH_CR_OPTER_Msk                   /*!< Option Byte Erase */
#define FLASH_CR_STRT_Pos                 (6U)
#define FLASH_CR_STRT_Msk                 (0x1U << FLASH_CR_STRT_Pos)          /*!< 0x00000040 */
#define FLASH_CR_STRT                     FLASH_CR_STRT_Msk                    /*!< Start */
#define FLASH_CR_LOCK_Pos                 (7U)
#define FLASH_CR_LOCK_Msk                 (0x1U << FLASH_CR_LOCK_Pos)          /*!< 0x00000080 */
#define FLASH_CR_LOCK                     FLASH_CR_LOCK_Msk                    /*!< Lock */
#define FLASH_CR_OPTWRE_Pos               (9U)
#define FLASH_CR_OPTWRE_Msk               (0x1U << FLASH_CR_OPTWRE_Pos)        /*!< 0x00000200 */
#define FLASH_CR_OPTWRE                   FLASH_CR_OPTWRE_Msk                  /*!< Option Bytes Write Enable */
#define FLASH_CR_ERRIE_Pos                (10U)
#define FLASH_CR_ERRIE_Msk                (0x1U << FLASH_CR_ERRIE_Pos)         /*!< 0x00000400 */
#define FLASH_CR_ERRIE                    FLASH_CR_ERRIE_Msk                   /*!< Error Interrupt Enable */
#define FLASH_CR_EOPIE_Pos                (12U)
#define FLASH_CR_EOPIE_Msk                (0x1U << FLASH_CR_EOPIE_Pos)         /*!< 0x00001000 */
#define FLASH_CR_EOPIE                    FLASH_CR_EOPIE_Msk                   /*!< End of operation interrupt enable */
#define FLASH_CR_OBL_LAUNCH_Pos           (13U)
#define FLASH_CR_OBL_LAUNCH_Msk           (0x1U << FLASH_CR_OBL_LAUNCH_Pos)    /*!< 0x00002000 */
#define FLASH_CR_OBL_LAUNCH               FLASH_CR_OBL_LAUNCH_Msk              /*!< Option Bytes Loader Launch */

/*******************  Bit definition for FLASH_AR register  *******************/
#define FLASH_AR_FAR_Pos                  (0U)
#define FLASH_AR_FAR_Msk                  (0xFFFFFFFFU << FLASH_AR_FAR_Pos)    /*!< 0xFFFFFFFF */
#define FLASH_AR_FAR                      FLASH_AR_FAR_Msk                     /*!< Flash Address */

/******************  Bit definition for FLASH_OBR register  *******************/
#define FLASH_OBR_OPTERR_Pos              (0U)
#define FLASH_OBR_OPTERR_Msk              (0x1U << FLASH_OBR_OPTERR_Pos)       /*!< 0x00000001 */
#define FLASH_OBR_OPTERR                  FLASH_OBR_OPTERR_Msk                 /*!< Option Byte Error */
#define FLASH_OBR_RDPRT1_Pos              (1U)
#define FLASH_OBR_RDPRT1_Msk              (0x1U << FLASH_OBR_RDPRT1_Pos)       /*!< 0x00000002 */
#define FLASH_OBR_RDPRT1                  FLASH_OBR_RDPRT1_Msk                 /*!< Read protection Level 1 */
#define FLASH_OBR_RDPRT2_Pos              (2U)
#define FLASH_OBR_RDPRT2_Msk              (0x1U << FLASH_OBR_RDPRT2_Pos)       /*!< 0x00000004 */
#define FLASH_OBR_RDPRT2                  FLASH_OBR_RDPRT2_Msk                 /*!< Read protection Level 2 */


#define FLASH_OBR_USER_Pos                (8U)
#if defined(STM32F091xC) || defined(STM32F098xx)
#define FLASH_OBR_USER_Msk                (0xFFU << FLASH_OBR_USER_Pos)        /*!< 0x0000FF00 : BOOT_SEL and nBOOT1 */
#else
#define FLASH_OBR_USER_Msk                (0x77U << FLASH_OBR_USER_Pos)        /*!< 0x00007700 */
#endif
#define FLASH_OBR_USER                    FLASH_OBR_USER_Msk                   /*!< User Option Bytes */

#define FLASH_OBR_IWDG_SW_Pos             (8U)
#define FLASH_OBR_IWDG_SW_Msk             (0x1U << FLASH_OBR_IWDG_SW_Pos)      /*!< 0x00000100 */
#define FLASH_OBR_IWDG_SW                 FLASH_OBR_IWDG_SW_Msk                /*!< IWDG SW */
#define FLASH_OBR_nRST_STOP_Pos           (9U)
#define FLASH_OBR_nRST_STOP_Msk           (0x1U << FLASH_OBR_nRST_STOP_Pos)    /*!< 0x00000200 */
#define FLASH_OBR_nRST_STOP               FLASH_OBR_nRST_STOP_Msk              /*!< nRST_STOP */
#define FLASH_OBR_nRST_STDBY_Pos          (10U)
#define FLASH_OBR_nRST_STDBY_Msk          (0x1U << FLASH_OBR_nRST_STDBY_Pos)   /*!< 0x00000400 */
#define FLASH_OBR_nRST_STDBY              FLASH_OBR_nRST_STDBY_Msk             /*!< nRST_STDBY */
#define FLASH_OBR_nBOOT0_Pos              (11U)
#define FLASH_OBR_nBOOT0_Msk              (0x1U << FLASH_OBR_nBOOT0_Pos)       /*!< 0x00000800 */
#define FLASH_OBR_nBOOT0                  FLASH_OBR_nBOOT0_Msk                 /*!< nBOOT0 */
#define FLASH_OBR_nBOOT1_Pos              (12U)
#define FLASH_OBR_nBOOT1_Msk              (0x1U << FLASH_OBR_nBOOT1_Pos)       /*!< 0x00001000 */
#define FLASH_OBR_nBOOT1                  FLASH_OBR_nBOOT1_Msk                 /*!< nBOOT1 */
#define FLASH_OBR_VDDA_MONITOR_Pos        (13U)
#define FLASH_OBR_VDDA_MONITOR_Msk        (0x1U << FLASH_OBR_VDDA_MONITOR_Pos) /*!< 0x00002000 */
#define FLASH_OBR_VDDA_MONITOR            FLASH_OBR_VDDA_MONITOR_Msk           /*!< VDDA power supply supervisor */
#define FLASH_OBR_RAM_PARITY_CHECK_Pos    (14U)
#define FLASH_OBR_RAM_PARITY_CHECK_Msk    (0x1U << FLASH_OBR_RAM_PARITY_CHECK_Pos) /*!< 0x00004000 */
#define FLASH_OBR_RAM_PARITY_CHECK        FLASH_OBR_RAM_PARITY_CHECK_Msk       /*!< RAM parity check */
#define FLASH_OBR_BOOT_SEL_Pos            (15U)
#define FLASH_OBR_BOOT_SEL_Msk            (0x1U << FLASH_OBR_BOOT_SEL_Pos)     /*!< 0x00008000 */
#define FLASH_OBR_BOOT_SEL                FLASH_OBR_BOOT_SEL_Msk               /*!< BOOT selection */
#define FLASH_OBR_DATA0_Pos               (16U)
#define FLASH_OBR_DATA0_Msk               (0xFFU << FLASH_OBR_DATA0_Pos)       /*!< 0x00FF0000 */
#define FLASH_OBR_DATA0                   FLASH_OBR_DATA0_Msk                  /*!< Data0 */
#define FLASH_OBR_DATA1_Pos               (24U)
#define FLASH_OBR_DATA1_Msk               (0xFFU << FLASH_OBR_DATA1_Pos)       /*!< 0xFF000000 */
#define FLASH_OBR_DATA1                   FLASH_OBR_DATA1_Msk                  /*!< Data1 */

/* Old BOOT1 bit definition, maintained for legacy purpose */
#define FLASH_OBR_BOOT1                      FLASH_OBR_nBOOT1

/* Old OBR_VDDA bit definition, maintained for legacy purpose */
#define FLASH_OBR_VDDA_ANALOG                FLASH_OBR_VDDA_MONITOR

/******************  Bit definition for FLASH_WRPR register  ******************/
#define FLASH_WRPR_WRP_Pos                (0U)
#define FLASH_WRPR_WRP_Msk                (0xFFFFU << FLASH_WRPR_WRP_Pos)      /*!< 0x0000FFFF */
#define FLASH_WRPR_WRP                    FLASH_WRPR_WRP_Msk                   /*!< Write Protect */

/*----------------------------------------------------------------------------*/

/******************  Bit definition for OB_RDP register  **********************/
#define OB_RDP_RDP_Pos       (0U)
#define OB_RDP_RDP_Msk       (0xFFU << OB_RDP_RDP_Pos)                         /*!< 0x000000FF */
#define OB_RDP_RDP           OB_RDP_RDP_Msk                                    /*!< Read protection option byte */
#define OB_RDP_nRDP_Pos      (8U)
#define OB_RDP_nRDP_Msk      (0xFFU << OB_RDP_nRDP_Pos)                        /*!< 0x0000FF00 */
#define OB_RDP_nRDP          OB_RDP_nRDP_Msk                                   /*!< Read protection complemented option byte */

/******************  Bit definition for OB_USER register  *********************/
#define OB_USER_USER_Pos     (16U)
#define OB_USER_USER_Msk     (0xFFU << OB_USER_USER_Pos)                       /*!< 0x00FF0000 */
#define OB_USER_USER         OB_USER_USER_Msk                                  /*!< User option byte */
#define OB_USER_nUSER_Pos    (24U)
#define OB_USER_nUSER_Msk    (0xFFU << OB_USER_nUSER_Pos)                      /*!< 0xFF000000 */
#define OB_USER_nUSER        OB_USER_nUSER_Msk                                 /*!< User complemented option byte */

/******************  Bit definition for OB_WRP0 register  *********************/
#define OB_WRP0_WRP0_Pos     (0U)
#define OB_WRP0_WRP0_Msk     (0xFFU << OB_WRP0_WRP0_Pos)                       /*!< 0x000000FF */
#define OB_WRP0_WRP0         OB_WRP0_WRP0_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP0_nWRP0_Pos    (8U)
#define OB_WRP0_nWRP0_Msk    (0xFFU << OB_WRP0_nWRP0_Pos)                      /*!< 0x0000FF00 */
#define OB_WRP0_nWRP0        OB_WRP0_nWRP0_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP1 register  *********************/
#define OB_WRP1_WRP1_Pos     (16U)
#define OB_WRP1_WRP1_Msk     (0xFFU << OB_WRP1_WRP1_Pos)                       /*!< 0x00FF0000 */
#define OB_WRP1_WRP1         OB_WRP1_WRP1_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP1_nWRP1_Pos    (24U)
#define OB_WRP1_nWRP1_Msk    (0xFFU << OB_WRP1_nWRP1_Pos)                      /*!< 0xFF000000 */
#define OB_WRP1_nWRP1        OB_WRP1_nWRP1_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP2 register  *********************/
#define OB_WRP2_WRP2_Pos     (0U)
#define OB_WRP2_WRP2_Msk     (0xFFU << OB_WRP2_WRP2_Pos)                       /*!< 0x000000FF */
#define OB_WRP2_WRP2         OB_WRP2_WRP2_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP2_nWRP2_Pos    (8U)
#define OB_WRP2_nWRP2_Msk    (0xFFU << OB_WRP2_nWRP2_Pos)                      /*!< 0x0000FF00 */
#define OB_WRP2_nWRP2        OB_WRP2_nWRP2_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP3 register  *********************/
#define OB_WRP3_WRP3_Pos     (16U)
#define OB_WRP3_WRP3_Msk     (0xFFU << OB_WRP3_WRP3_Pos)                       /*!< 0x00FF0000 */
#define OB_WRP3_WRP3         OB_WRP3_WRP3_Msk                                  /*!< Flash memory write protection option bytes */
#define OB_WRP3_nWRP3_Pos    (24U)
#define OB_WRP3_nWRP3_Msk    (0xFFU << OB_WRP3_nWRP3_Pos)                      /*!< 0xFF000000 */
#define OB_WRP3_nWRP3        OB_WRP3_nWRP3_Msk                                 /*!< Flash memory write protection complemented option bytes */

/******************************************************************************/
/*                                                                            */
/*                       General Purpose IOs (GPIO)                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0_Pos           (0U)
#define GPIO_MODER_MODER0_Msk           (0x3U << GPIO_MODER_MODER0_Pos)        /*!< 0x00000003 */
#define GPIO_MODER_MODER0               GPIO_MODER_MODER0_Msk
#define GPIO_MODER_MODER0_0             (0x1U << GPIO_MODER_MODER0_Pos)        /*!< 0x00000001 */
#define GPIO_MODER_MODER0_1             (0x2U << GPIO_MODER_MODER0_Pos)        /*!< 0x00000002 */
#define GPIO_MODER_MODER1_Pos           (2U)
#define GPIO_MODER_MODER1_Msk           (0x3U << GPIO_MODER_MODER1_Pos)        /*!< 0x0000000C */
#define GPIO_MODER_MODER1               GPIO_MODER_MODER1_Msk
#define GPIO_MODER_MODER1_0             (0x1U << GPIO_MODER_MODER1_Pos)        /*!< 0x00000004 */
#define GPIO_MODER_MODER1_1             (0x2U << GPIO_MODER_MODER1_Pos)        /*!< 0x00000008 */
#define GPIO_MODER_MODER2_Pos           (4U)
#define GPIO_MODER_MODER2_Msk           (0x3U << GPIO_MODER_MODER2_Pos)        /*!< 0x00000030 */
#define GPIO_MODER_MODER2               GPIO_MODER_MODER2_Msk
#define GPIO_MODER_MODER2_0             (0x1U << GPIO_MODER_MODER2_Pos)        /*!< 0x00000010 */
#define GPIO_MODER_MODER2_1             (0x2U << GPIO_MODER_MODER2_Pos)        /*!< 0x00000020 */
#define GPIO_MODER_MODER3_Pos           (6U)
#define GPIO_MODER_MODER3_Msk           (0x3U << GPIO_MODER_MODER3_Pos)        /*!< 0x000000C0 */
#define GPIO_MODER_MODER3               GPIO_MODER_MODER3_Msk
#define GPIO_MODER_MODER3_0             (0x1U << GPIO_MODER_MODER3_Pos)        /*!< 0x00000040 */
#define GPIO_MODER_MODER3_1             (0x2U << GPIO_MODER_MODER3_Pos)        /*!< 0x00000080 */
#define GPIO_MODER_MODER4_Pos           (8U)
#define GPIO_MODER_MODER4_Msk           (0x3U << GPIO_MODER_MODER4_Pos)        /*!< 0x00000300 */
#define GPIO_MODER_MODER4               GPIO_MODER_MODER4_Msk
#define GPIO_MODER_MODER4_0             (0x1U << GPIO_MODER_MODER4_Pos)        /*!< 0x00000100 */
#define GPIO_MODER_MODER4_1             (0x2U << GPIO_MODER_MODER4_Pos)        /*!< 0x00000200 */
#define GPIO_MODER_MODER5_Pos           (10U)
#define GPIO_MODER_MODER5_Msk           (0x3U << GPIO_MODER_MODER5_Pos)        /*!< 0x00000C00 */
#define GPIO_MODER_MODER5               GPIO_MODER_MODER5_Msk
#define GPIO_MODER_MODER5_0             (0x1U << GPIO_MODER_MODER5_Pos)        /*!< 0x00000400 */
#define GPIO_MODER_MODER5_1             (0x2U << GPIO_MODER_MODER5_Pos)        /*!< 0x00000800 */
#define GPIO_MODER_MODER6_Pos           (12U)
#define GPIO_MODER_MODER6_Msk           (0x3U << GPIO_MODER_MODER6_Pos)        /*!< 0x00003000 */
#define GPIO_MODER_MODER6               GPIO_MODER_MODER6_Msk
#define GPIO_MODER_MODER6_0             (0x1U << GPIO_MODER_MODER6_Pos)        /*!< 0x00001000 */
#define GPIO_MODER_MODER6_1             (0x2U << GPIO_MODER_MODER6_Pos)        /*!< 0x00002000 */
#define GPIO_MODER_MODER7_Pos           (14U)
#define GPIO_MODER_MODER7_Msk           (0x3U << GPIO_MODER_MODER7_Pos)        /*!< 0x0000C000 */
#define GPIO_MODER_MODER7               GPIO_MODER_MODER7_Msk
#define GPIO_MODER_MODER7_0             (0x1U << GPIO_MODER_MODER7_Pos)        /*!< 0x00004000 */
#define GPIO_MODER_MODER7_1             (0x2U << GPIO_MODER_MODER7_Pos)        /*!< 0x00008000 */
#define GPIO_MODER_MODER8_Pos           (16U)
#define GPIO_MODER_MODER8_Msk           (0x3U << GPIO_MODER_MODER8_Pos)        /*!< 0x00030000 */
#define GPIO_MODER_MODER8               GPIO_MODER_MODER8_Msk
#define GPIO_MODER_MODER8_0             (0x1U << GPIO_MODER_MODER8_Pos)        /*!< 0x00010000 */
#define GPIO_MODER_MODER8_1             (0x2U << GPIO_MODER_MODER8_Pos)        /*!< 0x00020000 */
#define GPIO_MODER_MODER9_Pos           (18U)
#define GPIO_MODER_MODER9_Msk           (0x3U << GPIO_MODER_MODER9_Pos)        /*!< 0x000C0000 */
#define GPIO_MODER_MODER9               GPIO_MODER_MODER9_Msk
#define GPIO_MODER_MODER9_0             (0x1U << GPIO_MODER_MODER9_Pos)        /*!< 0x00040000 */
#define GPIO_MODER_MODER9_1             (0x2U << GPIO_MODER_MODER9_Pos)        /*!< 0x00080000 */
#define GPIO_MODER_MODER10_Pos          (20U)
#define GPIO_MODER_MODER10_Msk          (0x3U << GPIO_MODER_MODER10_Pos)       /*!< 0x00300000 */
#define GPIO_MODER_MODER10              GPIO_MODER_MODER10_Msk
#define GPIO_MODER_MODER10_0            (0x1U << GPIO_MODER_MODER10_Pos)       /*!< 0x00100000 */
#define GPIO_MODER_MODER10_1            (0x2U << GPIO_MODER_MODER10_Pos)       /*!< 0x00200000 */
#define GPIO_MODER_MODER11_Pos          (22U)
#define GPIO_MODER_MODER11_Msk          (0x3U << GPIO_MODER_MODER11_Pos)       /*!< 0x00C00000 */
#define GPIO_MODER_MODER11              GPIO_MODER_MODER11_Msk
#define GPIO_MODER_MODER11_0            (0x1U << GPIO_MODER_MODER11_Pos)       /*!< 0x00400000 */
#define GPIO_MODER_MODER11_1            (0x2U << GPIO_MODER_MODER11_Pos)       /*!< 0x00800000 */
#define GPIO_MODER_MODER12_Pos          (24U)
#define GPIO_MODER_MODER12_Msk          (0x3U << GPIO_MODER_MODER12_Pos)       /*!< 0x03000000 */
#define GPIO_MODER_MODER12              GPIO_MODER_MODER12_Msk
#define GPIO_MODER_MODER12_0            (0x1U << GPIO_MODER_MODER12_Pos)       /*!< 0x01000000 */
#define GPIO_MODER_MODER12_1            (0x2U << GPIO_MODER_MODER12_Pos)       /*!< 0x02000000 */
#define GPIO_MODER_MODER13_Pos          (26U)
#define GPIO_MODER_MODER13_Msk          (0x3U << GPIO_MODER_MODER13_Pos)       /*!< 0x0C000000 */
#define GPIO_MODER_MODER13              GPIO_MODER_MODER13_Msk
#define GPIO_MODER_MODER13_0            (0x1U << GPIO_MODER_MODER13_Pos)       /*!< 0x04000000 */
#define GPIO_MODER_MODER13_1            (0x2U << GPIO_MODER_MODER13_Pos)       /*!< 0x08000000 */
#define GPIO_MODER_MODER14_Pos          (28U)
#define GPIO_MODER_MODER14_Msk          (0x3U << GPIO_MODER_MODER14_Pos)       /*!< 0x30000000 */
#define GPIO_MODER_MODER14              GPIO_MODER_MODER14_Msk
#define GPIO_MODER_MODER14_0            (0x1U << GPIO_MODER_MODER14_Pos)       /*!< 0x10000000 */
#define GPIO_MODER_MODER14_1            (0x2U << GPIO_MODER_MODER14_Pos)       /*!< 0x20000000 */
#define GPIO_MODER_MODER15_Pos          (30U)
#define GPIO_MODER_MODER15_Msk          (0x3U << GPIO_MODER_MODER15_Pos)       /*!< 0xC0000000 */
#define GPIO_MODER_MODER15              GPIO_MODER_MODER15_Msk
#define GPIO_MODER_MODER15_0            (0x1U << GPIO_MODER_MODER15_Pos)       /*!< 0x40000000 */
#define GPIO_MODER_MODER15_1            (0x2U << GPIO_MODER_MODER15_Pos)       /*!< 0x80000000 */

/******************  Bit definition for GPIO_OTYPER register  *****************/
#define GPIO_OTYPER_OT_0                (0x00000001U)
#define GPIO_OTYPER_OT_1                (0x00000002U)
#define GPIO_OTYPER_OT_2                (0x00000004U)
#define GPIO_OTYPER_OT_3                (0x00000008U)
#define GPIO_OTYPER_OT_4                (0x00000010U)
#define GPIO_OTYPER_OT_5                (0x00000020U)
#define GPIO_OTYPER_OT_6                (0x00000040U)
#define GPIO_OTYPER_OT_7                (0x00000080U)
#define GPIO_OTYPER_OT_8                (0x00000100U)
#define GPIO_OTYPER_OT_9                (0x00000200U)
#define GPIO_OTYPER_OT_10               (0x00000400U)
#define GPIO_OTYPER_OT_11               (0x00000800U)
#define GPIO_OTYPER_OT_12               (0x00001000U)
#define GPIO_OTYPER_OT_13               (0x00002000U)
#define GPIO_OTYPER_OT_14               (0x00004000U)
#define GPIO_OTYPER_OT_15               (0x00008000U)

/****************  Bit definition for GPIO_OSPEEDR register  ******************/
#define GPIO_OSPEEDR_OSPEEDR0_Pos       (0U)
#define GPIO_OSPEEDR_OSPEEDR0_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR0_Pos)    /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEEDR0           GPIO_OSPEEDR_OSPEEDR0_Msk
#define GPIO_OSPEEDR_OSPEEDR0_0         (0x1U << GPIO_OSPEEDR_OSPEEDR0_Pos)    /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEEDR0_1         (0x2U << GPIO_OSPEEDR_OSPEEDR0_Pos)    /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEEDR1_Pos       (2U)
#define GPIO_OSPEEDR_OSPEEDR1_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR1_Pos)    /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEEDR1           GPIO_OSPEEDR_OSPEEDR1_Msk
#define GPIO_OSPEEDR_OSPEEDR1_0         (0x1U << GPIO_OSPEEDR_OSPEEDR1_Pos)    /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEEDR1_1         (0x2U << GPIO_OSPEEDR_OSPEEDR1_Pos)    /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEEDR2_Pos       (4U)
#define GPIO_OSPEEDR_OSPEEDR2_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR2_Pos)    /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEEDR2           GPIO_OSPEEDR_OSPEEDR2_Msk
#define GPIO_OSPEEDR_OSPEEDR2_0         (0x1U << GPIO_OSPEEDR_OSPEEDR2_Pos)    /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEEDR2_1         (0x2U << GPIO_OSPEEDR_OSPEEDR2_Pos)    /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEEDR3_Pos       (6U)
#define GPIO_OSPEEDR_OSPEEDR3_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR3_Pos)    /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEEDR3           GPIO_OSPEEDR_OSPEEDR3_Msk
#define GPIO_OSPEEDR_OSPEEDR3_0         (0x1U << GPIO_OSPEEDR_OSPEEDR3_Pos)    /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEEDR3_1         (0x2U << GPIO_OSPEEDR_OSPEEDR3_Pos)    /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEEDR4_Pos       (8U)
#define GPIO_OSPEEDR_OSPEEDR4_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR4_Pos)    /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEEDR4           GPIO_OSPEEDR_OSPEEDR4_Msk
#define GPIO_OSPEEDR_OSPEEDR4_0         (0x1U << GPIO_OSPEEDR_OSPEEDR4_Pos)    /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEEDR4_1         (0x2U << GPIO_OSPEEDR_OSPEEDR4_Pos)    /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEEDR5_Pos       (10U)
#define GPIO_OSPEEDR_OSPEEDR5_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR5_Pos)    /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEEDR5           GPIO_OSPEEDR_OSPEEDR5_Msk
#define GPIO_OSPEEDR_OSPEEDR5_0         (0x1U << GPIO_OSPEEDR_OSPEEDR5_Pos)    /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEEDR5_1         (0x2U << GPIO_OSPEEDR_OSPEEDR5_Pos)    /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEEDR6_Pos       (12U)
#define GPIO_OSPEEDR_OSPEEDR6_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR6_Pos)    /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEEDR6           GPIO_OSPEEDR_OSPEEDR6_Msk
#define GPIO_OSPEEDR_OSPEEDR6_0         (0x1U << GPIO_OSPEEDR_OSPEEDR6_Pos)    /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEEDR6_1         (0x2U << GPIO_OSPEEDR_OSPEEDR6_Pos)    /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEEDR7_Pos       (14U)
#define GPIO_OSPEEDR_OSPEEDR7_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR7_Pos)    /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEEDR7           GPIO_OSPEEDR_OSPEEDR7_Msk
#define GPIO_OSPEEDR_OSPEEDR7_0         (0x1U << GPIO_OSPEEDR_OSPEEDR7_Pos)    /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEEDR7_1         (0x2U << GPIO_OSPEEDR_OSPEEDR7_Pos)    /*!< 0x00008000 */
#define GPIO_OSPEEDR_OSPEEDR8_Pos       (16U)
#define GPIO_OSPEEDR_OSPEEDR8_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR8_Pos)    /*!< 0x00030000 */
#define GPIO_OSPEEDR_OSPEEDR8           GPIO_OSPEEDR_OSPEEDR8_Msk
#define GPIO_OSPEEDR_OSPEEDR8_0         (0x1U << GPIO_OSPEEDR_OSPEEDR8_Pos)    /*!< 0x00010000 */
#define GPIO_OSPEEDR_OSPEEDR8_1         (0x2U << GPIO_OSPEEDR_OSPEEDR8_Pos)    /*!< 0x00020000 */
#define GPIO_OSPEEDR_OSPEEDR9_Pos       (18U)
#define GPIO_OSPEEDR_OSPEEDR9_Msk       (0x3U << GPIO_OSPEEDR_OSPEEDR9_Pos)    /*!< 0x000C0000 */
#define GPIO_OSPEEDR_OSPEEDR9           GPIO_OSPEEDR_OSPEEDR9_Msk
#define GPIO_OSPEEDR_OSPEEDR9_0         (0x1U << GPIO_OSPEEDR_OSPEEDR9_Pos)    /*!< 0x00040000 */
#define GPIO_OSPEEDR_OSPEEDR9_1         (0x2U << GPIO_OSPEEDR_OSPEEDR9_Pos)    /*!< 0x00080000 */
#define GPIO_OSPEEDR_OSPEEDR10_Pos      (20U)
#define GPIO_OSPEEDR_OSPEEDR10_Msk      (0x3U << GPIO_OSPEEDR_OSPEEDR10_Pos)   /*!< 0x00300000 */
#define GPIO_OSPEEDR_OSPEEDR10          GPIO_OSPEEDR_OSPEEDR10_Msk
#define GPIO_OSPEEDR_OSPEEDR10_0        (0x1U << GPIO_OSPEEDR_OSPEEDR10_Pos)   /*!< 0x00100000 */
#define GPIO_OSPEEDR_OSPEEDR10_1        (0x2U << GPIO_OSPEEDR_OSPEEDR10_Pos)   /*!< 0x00200000 */
#define GPIO_OSPEEDR_OSPEEDR11_Pos      (22U)
#define GPIO_OSPEEDR_OSPEEDR11_Msk      (0x3U << GPIO_OSPEEDR_OSPEEDR11_Pos)   /*!< 0x00C00000 */
#define GPIO_OSPEEDR_OSPEEDR11          GPIO_OSPEEDR_OSPEEDR11_Msk
#define GPIO_OSPEEDR_OSPEEDR11_0        (0x1U << GPIO_OSPEEDR_OSPEEDR11_Pos)   /*!< 0x00400000 */
#define GPIO_OSPEEDR_OSPEEDR11_1        (0x2U << GPIO_OSPEEDR_OSPEEDR11_Pos)   /*!< 0x00800000 */
#define GPIO_OSPEEDR_OSPEEDR12_Pos      (24U)
#define GPIO_OSPEEDR_OSPEEDR12_Msk      (0x3U << GPIO_OSPEEDR_OSPEEDR12_Pos)   /*!< 0x03000000 */
#define GPIO_OSPEEDR_OSPEEDR12          GPIO_OSPEEDR_OSPEEDR12_Msk
#define GPIO_OSPEEDR_OSPEEDR12_0        (0x1U << GPIO_OSPEEDR_OSPEEDR12_Pos)   /*!< 0x01000000 */
#define GPIO_OSPEEDR_OSPEEDR12_1        (0x2U << GPIO_OSPEEDR_OSPEEDR12_Pos)   /*!< 0x02000000 */
#define GPIO_OSPEEDR_OSPEEDR13_Pos      (26U)
#define GPIO_OSPEEDR_OSPEEDR13_Msk      (0x3U << GPIO_OSPEEDR_OSPEEDR13_Pos)   /*!< 0x0C000000 */
#define GPIO_OSPEEDR_OSPEEDR13          GPIO_OSPEEDR_OSPEEDR13_Msk
#define GPIO_OSPEEDR_OSPEEDR13_0        (0x1U << GPIO_OSPEEDR_OSPEEDR13_Pos)   /*!< 0x04000000 */
#define GPIO_OSPEEDR_OSPEEDR13_1        (0x2U << GPIO_OSPEEDR_OSPEEDR13_Pos)   /*!< 0x08000000 */
#define GPIO_OSPEEDR_OSPEEDR14_Pos      (28U)
#define GPIO_OSPEEDR_OSPEEDR14_Msk      (0x3U << GPIO_OSPEEDR_OSPEEDR14_Pos)   /*!< 0x30000000 */
#define GPIO_OSPEEDR_OSPEEDR14          GPIO_OSPEEDR_OSPEEDR14_Msk
#define GPIO_OSPEEDR_OSPEEDR14_0        (0x1U << GPIO_OSPEEDR_OSPEEDR14_Pos)   /*!< 0x10000000 */
#define GPIO_OSPEEDR_OSPEEDR14_1        (0x2U << GPIO_OSPEEDR_OSPEEDR14_Pos)   /*!< 0x20000000 */
#define GPIO_OSPEEDR_OSPEEDR15_Pos      (30U)
#define GPIO_OSPEEDR_OSPEEDR15_Msk      (0x3U << GPIO_OSPEEDR_OSPEEDR15_Pos)   /*!< 0xC0000000 */
#define GPIO_OSPEEDR_OSPEEDR15          GPIO_OSPEEDR_OSPEEDR15_Msk
#define GPIO_OSPEEDR_OSPEEDR15_0        (0x1U << GPIO_OSPEEDR_OSPEEDR15_Pos)   /*!< 0x40000000 */
#define GPIO_OSPEEDR_OSPEEDR15_1        (0x2U << GPIO_OSPEEDR_OSPEEDR15_Pos)   /*!< 0x80000000 */

/* Old Bit definition for GPIO_OSPEEDR register maintained for legacy purpose */
#define GPIO_OSPEEDER_OSPEEDR0     GPIO_OSPEEDR_OSPEEDR0
#define GPIO_OSPEEDER_OSPEEDR0_0   GPIO_OSPEEDR_OSPEEDR0_0
#define GPIO_OSPEEDER_OSPEEDR0_1   GPIO_OSPEEDR_OSPEEDR0_1
#define GPIO_OSPEEDER_OSPEEDR1     GPIO_OSPEEDR_OSPEEDR1
#define GPIO_OSPEEDER_OSPEEDR1_0   GPIO_OSPEEDR_OSPEEDR1_0
#define GPIO_OSPEEDER_OSPEEDR1_1   GPIO_OSPEEDR_OSPEEDR1_1
#define GPIO_OSPEEDER_OSPEEDR2     GPIO_OSPEEDR_OSPEEDR2
#define GPIO_OSPEEDER_OSPEEDR2_0   GPIO_OSPEEDR_OSPEEDR2_0
#define GPIO_OSPEEDER_OSPEEDR2_1   GPIO_OSPEEDR_OSPEEDR2_1
#define GPIO_OSPEEDER_OSPEEDR3     GPIO_OSPEEDR_OSPEEDR3
#define GPIO_OSPEEDER_OSPEEDR3_0   GPIO_OSPEEDR_OSPEEDR3_0
#define GPIO_OSPEEDER_OSPEEDR3_1   GPIO_OSPEEDR_OSPEEDR3_1
#define GPIO_OSPEEDER_OSPEEDR4     GPIO_OSPEEDR_OSPEEDR4
#define GPIO_OSPEEDER_OSPEEDR4_0   GPIO_OSPEEDR_OSPEEDR4_0
#define GPIO_OSPEEDER_OSPEEDR4_1   GPIO_OSPEEDR_OSPEEDR4_1
#define GPIO_OSPEEDER_OSPEEDR5     GPIO_OSPEEDR_OSPEEDR5
#define GPIO_OSPEEDER_OSPEEDR5_0   GPIO_OSPEEDR_OSPEEDR5_0
#define GPIO_OSPEEDER_OSPEEDR5_1   GPIO_OSPEEDR_OSPEEDR5_1
#define GPIO_OSPEEDER_OSPEEDR6     GPIO_OSPEEDR_OSPEEDR6
#define GPIO_OSPEEDER_OSPEEDR6_0   GPIO_OSPEEDR_OSPEEDR6_0
#define GPIO_OSPEEDER_OSPEEDR6_1   GPIO_OSPEEDR_OSPEEDR6_1
#define GPIO_OSPEEDER_OSPEEDR7     GPIO_OSPEEDR_OSPEEDR7
#define GPIO_OSPEEDER_OSPEEDR7_0   GPIO_OSPEEDR_OSPEEDR7_0
#define GPIO_OSPEEDER_OSPEEDR7_1   GPIO_OSPEEDR_OSPEEDR7_1
#define GPIO_OSPEEDER_OSPEEDR8     GPIO_OSPEEDR_OSPEEDR8
#define GPIO_OSPEEDER_OSPEEDR8_0   GPIO_OSPEEDR_OSPEEDR8_0
#define GPIO_OSPEEDER_OSPEEDR8_1   GPIO_OSPEEDR_OSPEEDR8_1
#define GPIO_OSPEEDER_OSPEEDR9     GPIO_OSPEEDR_OSPEEDR9
#define GPIO_OSPEEDER_OSPEEDR9_0   GPIO_OSPEEDR_OSPEEDR9_0
#define GPIO_OSPEEDER_OSPEEDR9_1   GPIO_OSPEEDR_OSPEEDR9_1
#define GPIO_OSPEEDER_OSPEEDR10    GPIO_OSPEEDR_OSPEEDR10
#define GPIO_OSPEEDER_OSPEEDR10_0  GPIO_OSPEEDR_OSPEEDR10_0
#define GPIO_OSPEEDER_OSPEEDR10_1  GPIO_OSPEEDR_OSPEEDR10_1
#define GPIO_OSPEEDER_OSPEEDR11    GPIO_OSPEEDR_OSPEEDR11
#define GPIO_OSPEEDER_OSPEEDR11_0  GPIO_OSPEEDR_OSPEEDR11_0
#define GPIO_OSPEEDER_OSPEEDR11_1  GPIO_OSPEEDR_OSPEEDR11_1
#define GPIO_OSPEEDER_OSPEEDR12    GPIO_OSPEEDR_OSPEEDR12
#define GPIO_OSPEEDER_OSPEEDR12_0  GPIO_OSPEEDR_OSPEEDR12_0
#define GPIO_OSPEEDER_OSPEEDR12_1  GPIO_OSPEEDR_OSPEEDR12_1
#define GPIO_OSPEEDER_OSPEEDR13    GPIO_OSPEEDR_OSPEEDR13
#define GPIO_OSPEEDER_OSPEEDR13_0  GPIO_OSPEEDR_OSPEEDR13_0
#define GPIO_OSPEEDER_OSPEEDR13_1  GPIO_OSPEEDR_OSPEEDR13_1
#define GPIO_OSPEEDER_OSPEEDR14    GPIO_OSPEEDR_OSPEEDR14
#define GPIO_OSPEEDER_OSPEEDR14_0  GPIO_OSPEEDR_OSPEEDR14_0
#define GPIO_OSPEEDER_OSPEEDR14_1  GPIO_OSPEEDR_OSPEEDR14_1
#define GPIO_OSPEEDER_OSPEEDR15    GPIO_OSPEEDR_OSPEEDR15
#define GPIO_OSPEEDER_OSPEEDR15_0  GPIO_OSPEEDR_OSPEEDR15_0
#define GPIO_OSPEEDER_OSPEEDR15_1  GPIO_OSPEEDR_OSPEEDR15_1

/*******************  Bit definition for GPIO_PUPDR register ******************/
#define GPIO_PUPDR_PUPDR0_Pos           (0U)
#define GPIO_PUPDR_PUPDR0_Msk           (0x3U << GPIO_PUPDR_PUPDR0_Pos)        /*!< 0x00000003 */
#define GPIO_PUPDR_PUPDR0               GPIO_PUPDR_PUPDR0_Msk
#define GPIO_PUPDR_PUPDR0_0             (0x1U << GPIO_PUPDR_PUPDR0_Pos)        /*!< 0x00000001 */
#define GPIO_PUPDR_PUPDR0_1             (0x2U << GPIO_PUPDR_PUPDR0_Pos)        /*!< 0x00000002 */
#define GPIO_PUPDR_PUPDR1_Pos           (2U)
#define GPIO_PUPDR_PUPDR1_Msk           (0x3U << GPIO_PUPDR_PUPDR1_Pos)        /*!< 0x0000000C */
#define GPIO_PUPDR_PUPDR1               GPIO_PUPDR_PUPDR1_Msk
#define GPIO_PUPDR_PUPDR1_0             (0x1U << GPIO_PUPDR_PUPDR1_Pos)        /*!< 0x00000004 */
#define GPIO_PUPDR_PUPDR1_1             (0x2U << GPIO_PUPDR_PUPDR1_Pos)        /*!< 0x00000008 */
#define GPIO_PUPDR_PUPDR2_Pos           (4U)
#define GPIO_PUPDR_PUPDR2_Msk           (0x3U << GPIO_PUPDR_PUPDR2_Pos)        /*!< 0x00000030 */
#define GPIO_PUPDR_PUPDR2               GPIO_PUPDR_PUPDR2_Msk
#define GPIO_PUPDR_PUPDR2_0             (0x1U << GPIO_PUPDR_PUPDR2_Pos)        /*!< 0x00000010 */
#define GPIO_PUPDR_PUPDR2_1             (0x2U << GPIO_PUPDR_PUPDR2_Pos)        /*!< 0x00000020 */
#define GPIO_PUPDR_PUPDR3_Pos           (6U)
#define GPIO_PUPDR_PUPDR3_Msk           (0x3U << GPIO_PUPDR_PUPDR3_Pos)        /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPDR3               GPIO_PUPDR_PUPDR3_Msk
#define GPIO_PUPDR_PUPDR3_0             (0x1U << GPIO_PUPDR_PUPDR3_Pos)        /*!< 0x00000040 */
#define GPIO_PUPDR_PUPDR3_1             (0x2U << GPIO_PUPDR_PUPDR3_Pos)        /*!< 0x00000080 */
#define GPIO_PUPDR_PUPDR4_Pos           (8U)
#define GPIO_PUPDR_PUPDR4_Msk           (0x3U << GPIO_PUPDR_PUPDR4_Pos)        /*!< 0x00000300 */
#define GPIO_PUPDR_PUPDR4               GPIO_PUPDR_PUPDR4_Msk
#define GPIO_PUPDR_PUPDR4_0             (0x1U << GPIO_PUPDR_PUPDR4_Pos)        /*!< 0x00000100 */
#define GPIO_PUPDR_PUPDR4_1             (0x2U << GPIO_PUPDR_PUPDR4_Pos)        /*!< 0x00000200 */
#define GPIO_PUPDR_PUPDR5_Pos           (10U)
#define GPIO_PUPDR_PUPDR5_Msk           (0x3U << GPIO_PUPDR_PUPDR5_Pos)        /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPDR5               GPIO_PUPDR_PUPDR5_Msk
#define GPIO_PUPDR_PUPDR5_0             (0x1U << GPIO_PUPDR_PUPDR5_Pos)        /*!< 0x00000400 */
#define GPIO_PUPDR_PUPDR5_1             (0x2U << GPIO_PUPDR_PUPDR5_Pos)        /*!< 0x00000800 */
#define GPIO_PUPDR_PUPDR6_Pos           (12U)
#define GPIO_PUPDR_PUPDR6_Msk           (0x3U << GPIO_PUPDR_PUPDR6_Pos)        /*!< 0x00003000 */
#define GPIO_PUPDR_PUPDR6               GPIO_PUPDR_PUPDR6_Msk
#define GPIO_PUPDR_PUPDR6_0             (0x1U << GPIO_PUPDR_PUPDR6_Pos)        /*!< 0x00001000 */
#define GPIO_PUPDR_PUPDR6_1             (0x2U << GPIO_PUPDR_PUPDR6_Pos)        /*!< 0x00002000 */
#define GPIO_PUPDR_PUPDR7_Pos           (14U)
#define GPIO_PUPDR_PUPDR7_Msk           (0x3U << GPIO_PUPDR_PUPDR7_Pos)        /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPDR7               GPIO_PUPDR_PUPDR7_Msk
#define GPIO_PUPDR_PUPDR7_0             (0x1U << GPIO_PUPDR_PUPDR7_Pos)        /*!< 0x00004000 */
#define GPIO_PUPDR_PUPDR7_1             (0x2U << GPIO_PUPDR_PUPDR7_Pos)        /*!< 0x00008000 */
#define GPIO_PUPDR_PUPDR8_Pos           (16U)
#define GPIO_PUPDR_PUPDR8_Msk           (0x3U << GPIO_PUPDR_PUPDR8_Pos)        /*!< 0x00030000 */
#define GPIO_PUPDR_PUPDR8               GPIO_PUPDR_PUPDR8_Msk
#define GPIO_PUPDR_PUPDR8_0             (0x1U << GPIO_PUPDR_PUPDR8_Pos)        /*!< 0x00010000 */
#define GPIO_PUPDR_PUPDR8_1             (0x2U << GPIO_PUPDR_PUPDR8_Pos)        /*!< 0x00020000 */
#define GPIO_PUPDR_PUPDR9_Pos           (18U)
#define GPIO_PUPDR_PUPDR9_Msk           (0x3U << GPIO_PUPDR_PUPDR9_Pos)        /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPDR9               GPIO_PUPDR_PUPDR9_Msk
#define GPIO_PUPDR_PUPDR9_0             (0x1U << GPIO_PUPDR_PUPDR9_Pos)        /*!< 0x00040000 */
#define GPIO_PUPDR_PUPDR9_1             (0x2U << GPIO_PUPDR_PUPDR9_Pos)        /*!< 0x00080000 */
#define GPIO_PUPDR_PUPDR10_Pos          (20U)
#define GPIO_PUPDR_PUPDR10_Msk          (0x3U << GPIO_PUPDR_PUPDR10_Pos)       /*!< 0x00300000 */
#define GPIO_PUPDR_PUPDR10              GPIO_PUPDR_PUPDR10_Msk
#define GPIO_PUPDR_PUPDR10_0            (0x1U << GPIO_PUPDR_PUPDR10_Pos)       /*!< 0x00100000 */
#define GPIO_PUPDR_PUPDR10_1            (0x2U << GPIO_PUPDR_PUPDR10_Pos)       /*!< 0x00200000 */
#define GPIO_PUPDR_PUPDR11_Pos          (22U)
#define GPIO_PUPDR_PUPDR11_Msk          (0x3U << GPIO_PUPDR_PUPDR11_Pos)       /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPDR11              GPIO_PUPDR_PUPDR11_Msk
#define GPIO_PUPDR_PUPDR11_0            (0x1U << GPIO_PUPDR_PUPDR11_Pos)       /*!< 0x00400000 */
#define GPIO_PUPDR_PUPDR11_1            (0x2U << GPIO_PUPDR_PUPDR11_Pos)       /*!< 0x00800000 */
#define GPIO_PUPDR_PUPDR12_Pos          (24U)
#define GPIO_PUPDR_PUPDR12_Msk          (0x3U << GPIO_PUPDR_PUPDR12_Pos)       /*!< 0x03000000 */
#define GPIO_PUPDR_PUPDR12              GPIO_PUPDR_PUPDR12_Msk
#define GPIO_PUPDR_PUPDR12_0            (0x1U << GPIO_PUPDR_PUPDR12_Pos)       /*!< 0x01000000 */
#define GPIO_PUPDR_PUPDR12_1            (0x2U << GPIO_PUPDR_PUPDR12_Pos)       /*!< 0x02000000 */
#define GPIO_PUPDR_PUPDR13_Pos          (26U)
#define GPIO_PUPDR_PUPDR13_Msk          (0x3U << GPIO_PUPDR_PUPDR13_Pos)       /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPDR13              GPIO_PUPDR_PUPDR13_Msk
#define GPIO_PUPDR_PUPDR13_0            (0x1U << GPIO_PUPDR_PUPDR13_Pos)       /*!< 0x04000000 */
#define GPIO_PUPDR_PUPDR13_1            (0x2U << GPIO_PUPDR_PUPDR13_Pos)       /*!< 0x08000000 */
#define GPIO_PUPDR_PUPDR14_Pos          (28U)
#define GPIO_PUPDR_PUPDR14_Msk          (0x3U << GPIO_PUPDR_PUPDR14_Pos)       /*!< 0x30000000 */
#define GPIO_PUPDR_PUPDR14              GPIO_PUPDR_PUPDR14_Msk
#define GPIO_PUPDR_PUPDR14_0            (0x1U << GPIO_PUPDR_PUPDR14_Pos)       /*!< 0x10000000 */
#define GPIO_PUPDR_PUPDR14_1            (0x2U << GPIO_PUPDR_PUPDR14_Pos)       /*!< 0x20000000 */
#define GPIO_PUPDR_PUPDR15_Pos          (30U)
#define GPIO_PUPDR_PUPDR15_Msk          (0x3U << GPIO_PUPDR_PUPDR15_Pos)       /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPDR15              GPIO_PUPDR_PUPDR15_Msk
#define GPIO_PUPDR_PUPDR15_0            (0x1U << GPIO_PUPDR_PUPDR15_Pos)       /*!< 0x40000000 */
#define GPIO_PUPDR_PUPDR15_1            (0x2U << GPIO_PUPDR_PUPDR15_Pos)       /*!< 0x80000000 */

/*******************  Bit definition for GPIO_IDR register  *******************/
#define GPIO_IDR_0                      (0x00000001U)
#define GPIO_IDR_1                      (0x00000002U)
#define GPIO_IDR_2                      (0x00000004U)
#define GPIO_IDR_3                      (0x00000008U)
#define GPIO_IDR_4                      (0x00000010U)
#define GPIO_IDR_5                      (0x00000020U)
#define GPIO_IDR_6                      (0x00000040U)
#define GPIO_IDR_7                      (0x00000080U)
#define GPIO_IDR_8                      (0x00000100U)
#define GPIO_IDR_9                      (0x00000200U)
#define GPIO_IDR_10                     (0x00000400U)
#define GPIO_IDR_11                     (0x00000800U)
#define GPIO_IDR_12                     (0x00001000U)
#define GPIO_IDR_13                     (0x00002000U)
#define GPIO_IDR_14                     (0x00004000U)
#define GPIO_IDR_15                     (0x00008000U)

/******************  Bit definition for GPIO_ODR register  ********************/
#define GPIO_ODR_0                      (0x00000001U)
#define GPIO_ODR_1                      (0x00000002U)
#define GPIO_ODR_2                      (0x00000004U)
#define GPIO_ODR_3                      (0x00000008U)
#define GPIO_ODR_4                      (0x00000010U)
#define GPIO_ODR_5                      (0x00000020U)
#define GPIO_ODR_6                      (0x00000040U)
#define GPIO_ODR_7                      (0x00000080U)
#define GPIO_ODR_8                      (0x00000100U)
#define GPIO_ODR_9                      (0x00000200U)
#define GPIO_ODR_10                     (0x00000400U)
#define GPIO_ODR_11                     (0x00000800U)
#define GPIO_ODR_12                     (0x00001000U)
#define GPIO_ODR_13                     (0x00002000U)
#define GPIO_ODR_14                     (0x00004000U)
#define GPIO_ODR_15                     (0x00008000U)

/****************** Bit definition for GPIO_BSRR register  ********************/
#define GPIO_BSRR_BS_0                  (0x00000001U)
#define GPIO_BSRR_BS_1                  (0x00000002U)
#define GPIO_BSRR_BS_2                  (0x00000004U)
#define GPIO_BSRR_BS_3                  (0x00000008U)
#define GPIO_BSRR_BS_4                  (0x00000010U)
#define GPIO_BSRR_BS_5                  (0x00000020U)
#define GPIO_BSRR_BS_6                  (0x00000040U)
#define GPIO_BSRR_BS_7                  (0x00000080U)
#define GPIO_BSRR_BS_8                  (0x00000100U)
#define GPIO_BSRR_BS_9                  (0x00000200U)
#define GPIO_BSRR_BS_10                 (0x00000400U)
#define GPIO_BSRR_BS_11                 (0x00000800U)
#define GPIO_BSRR_BS_12                 (0x00001000U)
#define GPIO_BSRR_BS_13                 (0x00002000U)
#define GPIO_BSRR_BS_14                 (0x00004000U)
#define GPIO_BSRR_BS_15                 (0x00008000U)
#define GPIO_BSRR_BR_0                  (0x00010000U)
#define GPIO_BSRR_BR_1                  (0x00020000U)
#define GPIO_BSRR_BR_2                  (0x00040000U)
#define GPIO_BSRR_BR_3                  (0x00080000U)
#define GPIO_BSRR_BR_4                  (0x00100000U)
#define GPIO_BSRR_BR_5                  (0x00200000U)
#define GPIO_BSRR_BR_6                  (0x00400000U)
#define GPIO_BSRR_BR_7                  (0x00800000U)
#define GPIO_BSRR_BR_8                  (0x01000000U)
#define GPIO_BSRR_BR_9                  (0x02000000U)
#define GPIO_BSRR_BR_10                 (0x04000000U)
#define GPIO_BSRR_BR_11                 (0x08000000U)
#define GPIO_BSRR_BR_12                 (0x10000000U)
#define GPIO_BSRR_BR_13                 (0x20000000U)
#define GPIO_BSRR_BR_14                 (0x40000000U)
#define GPIO_BSRR_BR_15                 (0x80000000U)

/****************** Bit definition for GPIO_LCKR register  ********************/
#define GPIO_LCKR_LCK0_Pos              (0U)
#define GPIO_LCKR_LCK0_Msk              (0x1U << GPIO_LCKR_LCK0_Pos)           /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                  GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos              (1U)
#define GPIO_LCKR_LCK1_Msk              (0x1U << GPIO_LCKR_LCK1_Pos)           /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                  GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos              (2U)
#define GPIO_LCKR_LCK2_Msk              (0x1U << GPIO_LCKR_LCK2_Pos)           /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                  GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos              (3U)
#define GPIO_LCKR_LCK3_Msk              (0x1U << GPIO_LCKR_LCK3_Pos)           /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                  GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos              (4U)
#define GPIO_LCKR_LCK4_Msk              (0x1U << GPIO_LCKR_LCK4_Pos)           /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                  GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos              (5U)
#define GPIO_LCKR_LCK5_Msk              (0x1U << GPIO_LCKR_LCK5_Pos)           /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                  GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos              (6U)
#define GPIO_LCKR_LCK6_Msk              (0x1U << GPIO_LCKR_LCK6_Pos)           /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                  GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos              (7U)
#define GPIO_LCKR_LCK7_Msk              (0x1U << GPIO_LCKR_LCK7_Pos)           /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                  GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos              (8U)
#define GPIO_LCKR_LCK8_Msk              (0x1U << GPIO_LCKR_LCK8_Pos)           /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                  GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos              (9U)
#define GPIO_LCKR_LCK9_Msk              (0x1U << GPIO_LCKR_LCK9_Pos)           /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                  GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos             (10U)
#define GPIO_LCKR_LCK10_Msk             (0x1U << GPIO_LCKR_LCK10_Pos)          /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                 GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos             (11U)
#define GPIO_LCKR_LCK11_Msk             (0x1U << GPIO_LCKR_LCK11_Pos)          /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                 GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos             (12U)
#define GPIO_LCKR_LCK12_Msk             (0x1U << GPIO_LCKR_LCK12_Pos)          /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                 GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos             (13U)
#define GPIO_LCKR_LCK13_Msk             (0x1U << GPIO_LCKR_LCK13_Pos)          /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                 GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos             (14U)
#define GPIO_LCKR_LCK14_Msk             (0x1U << GPIO_LCKR_LCK14_Pos)          /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                 GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos             (15U)
#define GPIO_LCKR_LCK15_Msk             (0x1U << GPIO_LCKR_LCK15_Pos)          /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                 GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos              (16U)
#define GPIO_LCKR_LCKK_Msk              (0x1U << GPIO_LCKR_LCKK_Pos)           /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                  GPIO_LCKR_LCKK_Msk

/****************** Bit definition for GPIO_AFRL register  ********************/
#define GPIO_AFRL_AFRL0_Pos             (0U)
#define GPIO_AFRL_AFRL0_Msk             (0xFU << GPIO_AFRL_AFRL0_Pos)          /*!< 0x0000000F */
#define GPIO_AFRL_AFRL0                 GPIO_AFRL_AFRL0_Msk
#define GPIO_AFRL_AFRL1_Pos             (4U)
#define GPIO_AFRL_AFRL1_Msk             (0xFU << GPIO_AFRL_AFRL1_Pos)          /*!< 0x000000F0 */
#define GPIO_AFRL_AFRL1                 GPIO_AFRL_AFRL1_Msk
#define GPIO_AFRL_AFRL2_Pos             (8U)
#define GPIO_AFRL_AFRL2_Msk             (0xFU << GPIO_AFRL_AFRL2_Pos)          /*!< 0x00000F00 */
#define GPIO_AFRL_AFRL2                 GPIO_AFRL_AFRL2_Msk
#define GPIO_AFRL_AFRL3_Pos             (12U)
#define GPIO_AFRL_AFRL3_Msk             (0xFU << GPIO_AFRL_AFRL3_Pos)          /*!< 0x0000F000 */
#define GPIO_AFRL_AFRL3                 GPIO_AFRL_AFRL3_Msk
#define GPIO_AFRL_AFRL4_Pos             (16U)
#define GPIO_AFRL_AFRL4_Msk             (0xFU << GPIO_AFRL_AFRL4_Pos)          /*!< 0x000F0000 */
#define GPIO_AFRL_AFRL4                 GPIO_AFRL_AFRL4_Msk
#define GPIO_AFRL_AFRL5_Pos             (20U)
#define GPIO_AFRL_AFRL5_Msk             (0xFU << GPIO_AFRL_AFRL5_Pos)          /*!< 0x00F00000 */
#define GPIO_AFRL_AFRL5                 GPIO_AFRL_AFRL5_Msk
#define GPIO_AFRL_AFRL6_Pos             (24U)
#define GPIO_AFRL_AFRL6_Msk             (0xFU << GPIO_AFRL_AFRL6_Pos)          /*!< 0x0F000000 */
#define GPIO_AFRL_AFRL6                 GPIO_AFRL_AFRL6_Msk
#define GPIO_AFRL_AFRL7_Pos             (28U)
#define GPIO_AFRL_AFRL7_Msk             (0xFU << GPIO_AFRL_AFRL7_Pos)          /*!< 0xF0000000 */
#define GPIO_AFRL_AFRL7                 GPIO_AFRL_AFRL7_Msk

/****************** Bit definition for GPIO_AFRH register  ********************/
#define GPIO_AFRH_AFRH0_Pos             (0U)
#define GPIO_AFRH_AFRH0_Msk             (0xFU << GPIO_AFRH_AFRH0_Pos)          /*!< 0x0000000F */
#define GPIO_AFRH_AFRH0                 GPIO_AFRH_AFRH0_Msk
#define GPIO_AFRH_AFRH1_Pos             (4U)
#define GPIO_AFRH_AFRH1_Msk             (0xFU << GPIO_AFRH_AFRH1_Pos)          /*!< 0x000000F0 */
#define GPIO_AFRH_AFRH1                 GPIO_AFRH_AFRH1_Msk
#define GPIO_AFRH_AFRH2_Pos             (8U)
#define GPIO_AFRH_AFRH2_Msk             (0xFU << GPIO_AFRH_AFRH2_Pos)          /*!< 0x00000F00 */
#define GPIO_AFRH_AFRH2                 GPIO_AFRH_AFRH2_Msk
#define GPIO_AFRH_AFRH3_Pos             (12U)
#define GPIO_AFRH_AFRH3_Msk             (0xFU << GPIO_AFRH_AFRH3_Pos)          /*!< 0x0000F000 */
#define GPIO_AFRH_AFRH3                 GPIO_AFRH_AFRH3_Msk
#define GPIO_AFRH_AFRH4_Pos             (16U)
#define GPIO_AFRH_AFRH4_Msk             (0xFU << GPIO_AFRH_AFRH4_Pos)          /*!< 0x000F0000 */
#define GPIO_AFRH_AFRH4                 GPIO_AFRH_AFRH4_Msk
#define GPIO_AFRH_AFRH5_Pos             (20U)
#define GPIO_AFRH_AFRH5_Msk             (0xFU << GPIO_AFRH_AFRH5_Pos)          /*!< 0x00F00000 */
#define GPIO_AFRH_AFRH5                 GPIO_AFRH_AFRH5_Msk
#define GPIO_AFRH_AFRH6_Pos             (24U)
#define GPIO_AFRH_AFRH6_Msk             (0xFU << GPIO_AFRH_AFRH6_Pos)          /*!< 0x0F000000 */
#define GPIO_AFRH_AFRH6                 GPIO_AFRH_AFRH6_Msk
#define GPIO_AFRH_AFRH7_Pos             (28U)
#define GPIO_AFRH_AFRH7_Msk             (0xFU << GPIO_AFRH_AFRH7_Pos)          /*!< 0xF0000000 */
#define GPIO_AFRH_AFRH7                 GPIO_AFRH_AFRH7_Msk

/****************** Bit definition for GPIO_BRR register  *********************/
#define GPIO_BRR_BR_0                   (0x00000001U)
#define GPIO_BRR_BR_1                   (0x00000002U)
#define GPIO_BRR_BR_2                   (0x00000004U)
#define GPIO_BRR_BR_3                   (0x00000008U)
#define GPIO_BRR_BR_4                   (0x00000010U)
#define GPIO_BRR_BR_5                   (0x00000020U)
#define GPIO_BRR_BR_6                   (0x00000040U)
#define GPIO_BRR_BR_7                   (0x00000080U)
#define GPIO_BRR_BR_8                   (0x00000100U)
#define GPIO_BRR_BR_9                   (0x00000200U)
#define GPIO_BRR_BR_10                  (0x00000400U)
#define GPIO_BRR_BR_11                  (0x00000800U)
#define GPIO_BRR_BR_12                  (0x00001000U)
#define GPIO_BRR_BR_13                  (0x00002000U)
#define GPIO_BRR_BR_14                  (0x00004000U)
#define GPIO_BRR_BR_15                  (0x00008000U)


/******************************************************************************/
/*                                                                            */
/*                   Inter-integrated Circuit Interface (I2C)                 */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for I2C_CR1 register  *******************/
#define I2C_CR1_PE_Pos               (0U)
#define I2C_CR1_PE_Msk               (0x1U << I2C_CR1_PE_Pos)                  /*!< 0x00000001 */
#define I2C_CR1_PE                   I2C_CR1_PE_Msk                            /*!< Peripheral enable */
#define I2C_CR1_TXIE_Pos             (1U)
#define I2C_CR1_TXIE_Msk             (0x1U << I2C_CR1_TXIE_Pos)                /*!< 0x00000002 */
#define I2C_CR1_TXIE                 I2C_CR1_TXIE_Msk                          /*!< TX interrupt enable */
#define I2C_CR1_RXIE_Pos             (2U)
#define I2C_CR1_RXIE_Msk             (0x1U << I2C_CR1_RXIE_Pos)                /*!< 0x00000004 */
#define I2C_CR1_RXIE                 I2C_CR1_RXIE_Msk                          /*!< RX interrupt enable */
#define I2C_CR1_ADDRIE_Pos           (3U)
#define I2C_CR1_ADDRIE_Msk           (0x1U << I2C_CR1_ADDRIE_Pos)              /*!< 0x00000008 */
#define I2C_CR1_ADDRIE               I2C_CR1_ADDRIE_Msk                        /*!< Address match interrupt enable */
#define I2C_CR1_NACKIE_Pos           (4U)
#define I2C_CR1_NACKIE_Msk           (0x1U << I2C_CR1_NACKIE_Pos)              /*!< 0x00000010 */
#define I2C_CR1_NACKIE               I2C_CR1_NACKIE_Msk                        /*!< NACK received interrupt enable */
#define I2C_CR1_STOPIE_Pos           (5U)
#define I2C_CR1_STOPIE_Msk           (0x1U << I2C_CR1_STOPIE_Pos)              /*!< 0x00000020 */
#define I2C_CR1_STOPIE               I2C_CR1_STOPIE_Msk                        /*!< STOP detection interrupt enable */
#define I2C_CR1_TCIE_Pos             (6U)
#define I2C_CR1_TCIE_Msk             (0x1U << I2C_CR1_TCIE_Pos)                /*!< 0x00000040 */
#define I2C_CR1_TCIE                 I2C_CR1_TCIE_Msk                          /*!< Transfer complete interrupt enable */
#define I2C_CR1_ERRIE_Pos            (7U)
#define I2C_CR1_ERRIE_Msk            (0x1U << I2C_CR1_ERRIE_Pos)               /*!< 0x00000080 */
#define I2C_CR1_ERRIE                I2C_CR1_ERRIE_Msk                         /*!< Errors interrupt enable */
#define I2C_CR1_DNF_Pos              (8U)
#define I2C_CR1_DNF_Msk              (0xFU << I2C_CR1_DNF_Pos)                 /*!< 0x00000F00 */
#define I2C_CR1_DNF                  I2C_CR1_DNF_Msk                           /*!< Digital noise filter */
#define I2C_CR1_ANFOFF_Pos           (12U)
#define I2C_CR1_ANFOFF_Msk           (0x1U << I2C_CR1_ANFOFF_Pos)              /*!< 0x00001000 */
#define I2C_CR1_ANFOFF               I2C_CR1_ANFOFF_Msk                        /*!< Analog noise filter OFF */
#define I2C_CR1_SWRST_Pos            (13U)
#define I2C_CR1_SWRST_Msk            (0x1U << I2C_CR1_SWRST_Pos)               /*!< 0x00002000 */
#define I2C_CR1_SWRST                I2C_CR1_SWRST_Msk                         /*!< Software reset */
#define I2C_CR1_TXDMAEN_Pos          (14U)
#define I2C_CR1_TXDMAEN_Msk          (0x1U << I2C_CR1_TXDMAEN_Pos)             /*!< 0x00004000 */
#define I2C_CR1_TXDMAEN              I2C_CR1_TXDMAEN_Msk                       /*!< DMA transmission requests enable */
#define I2C_CR1_RXDMAEN_Pos          (15U)
#define I2C_CR1_RXDMAEN_Msk          (0x1U << I2C_CR1_RXDMAEN_Pos)             /*!< 0x00008000 */
#define I2C_CR1_RXDMAEN              I2C_CR1_RXDMAEN_Msk                       /*!< DMA reception requests enable */
#define I2C_CR1_SBC_Pos              (16U)
#define I2C_CR1_SBC_Msk              (0x1U << I2C_CR1_SBC_Pos)                 /*!< 0x00010000 */
#define I2C_CR1_SBC                  I2C_CR1_SBC_Msk                           /*!< Slave byte control */
#define I2C_CR1_NOSTRETCH_Pos        (17U)
#define I2C_CR1_NOSTRETCH_Msk        (0x1U << I2C_CR1_NOSTRETCH_Pos)           /*!< 0x00020000 */
#define I2C_CR1_NOSTRETCH            I2C_CR1_NOSTRETCH_Msk                     /*!< Clock stretching disable */
#define I2C_CR1_WUPEN_Pos            (18U)
#define I2C_CR1_WUPEN_Msk            (0x1U << I2C_CR1_WUPEN_Pos)               /*!< 0x00040000 */
#define I2C_CR1_WUPEN                I2C_CR1_WUPEN_Msk                         /*!< Wakeup from STOP enable */
#define I2C_CR1_GCEN_Pos             (19U)
#define I2C_CR1_GCEN_Msk             (0x1U << I2C_CR1_GCEN_Pos)                /*!< 0x00080000 */
#define I2C_CR1_GCEN                 I2C_CR1_GCEN_Msk                          /*!< General call enable */
#define I2C_CR1_SMBHEN_Pos           (20U)
#define I2C_CR1_SMBHEN_Msk           (0x1U << I2C_CR1_SMBHEN_Pos)              /*!< 0x00100000 */
#define I2C_CR1_SMBHEN               I2C_CR1_SMBHEN_Msk                        /*!< SMBus host address enable */
#define I2C_CR1_SMBDEN_Pos           (21U)
#define I2C_CR1_SMBDEN_Msk           (0x1U << I2C_CR1_SMBDEN_Pos)              /*!< 0x00200000 */
#define I2C_CR1_SMBDEN               I2C_CR1_SMBDEN_Msk                        /*!< SMBus device default address enable */
#define I2C_CR1_ALERTEN_Pos          (22U)
#define I2C_CR1_ALERTEN_Msk          (0x1U << I2C_CR1_ALERTEN_Pos)             /*!< 0x00400000 */
#define I2C_CR1_ALERTEN              I2C_CR1_ALERTEN_Msk                       /*!< SMBus alert enable */
#define I2C_CR1_PECEN_Pos            (23U)
#define I2C_CR1_PECEN_Msk            (0x1U << I2C_CR1_PECEN_Pos)               /*!< 0x00800000 */
#define I2C_CR1_PECEN                I2C_CR1_PECEN_Msk                         /*!< PEC enable */

/******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_SADD_Pos             (0U)
#define I2C_CR2_SADD_Msk             (0x3FFU << I2C_CR2_SADD_Pos)              /*!< 0x000003FF */
#define I2C_CR2_SADD                 I2C_CR2_SADD_Msk                          /*!< Slave address (master mode) */
#define I2C_CR2_RD_WRN_Pos           (10U)
#define I2C_CR2_RD_WRN_Msk           (0x1U << I2C_CR2_RD_WRN_Pos)              /*!< 0x00000400 */
#define I2C_CR2_RD_WRN               I2C_CR2_RD_WRN_Msk                        /*!< Transfer direction (master mode) */
#define I2C_CR2_ADD10_Pos            (11U)
#define I2C_CR2_ADD10_Msk            (0x1U << I2C_CR2_ADD10_Pos)               /*!< 0x00000800 */
#define I2C_CR2_ADD10                I2C_CR2_ADD10_Msk                         /*!< 10-bit addressing mode (master mode) */
#define I2C_CR2_HEAD10R_Pos          (12U)
#define I2C_CR2_HEAD10R_Msk          (0x1U << I2C_CR2_HEAD10R_Pos)             /*!< 0x00001000 */
#define I2C_CR2_HEAD10R              I2C_CR2_HEAD10R_Msk                       /*!< 10-bit address header only read direction (master mode) */
#define I2C_CR2_START_Pos            (13U)
#define I2C_CR2_START_Msk            (0x1U << I2C_CR2_START_Pos)               /*!< 0x00002000 */
#define I2C_CR2_START                I2C_CR2_START_Msk                         /*!< START generation */
#define I2C_CR2_STOP_Pos             (14U)
#define I2C_CR2_STOP_Msk             (0x1U << I2C_CR2_STOP_Pos)                /*!< 0x00004000 */
#define I2C_CR2_STOP                 I2C_CR2_STOP_Msk                          /*!< STOP generation (master mode) */
#define I2C_CR2_NACK_Pos             (15U)
#define I2C_CR2_NACK_Msk             (0x1U << I2C_CR2_NACK_Pos)                /*!< 0x00008000 */
#define I2C_CR2_NACK                 I2C_CR2_NACK_Msk                          /*!< NACK generation (slave mode) */
#define I2C_CR2_NBYTES_Pos           (16U)
#define I2C_CR2_NBYTES_Msk           (0xFFU << I2C_CR2_NBYTES_Pos)             /*!< 0x00FF0000 */
#define I2C_CR2_NBYTES               I2C_CR2_NBYTES_Msk                        /*!< Number of bytes */
#define I2C_CR2_RELOAD_Pos           (24U)
#define I2C_CR2_RELOAD_Msk           (0x1U << I2C_CR2_RELOAD_Pos)              /*!< 0x01000000 */
#define I2C_CR2_RELOAD               I2C_CR2_RELOAD_Msk                        /*!< NBYTES reload mode */
#define I2C_CR2_AUTOEND_Pos          (25U)
#define I2C_CR2_AUTOEND_Msk          (0x1U << I2C_CR2_AUTOEND_Pos)             /*!< 0x02000000 */
#define I2C_CR2_AUTOEND              I2C_CR2_AUTOEND_Msk                       /*!< Automatic end mode (master mode) */
#define I2C_CR2_PECBYTE_Pos          (26U)
#define I2C_CR2_PECBYTE_Msk          (0x1U << I2C_CR2_PECBYTE_Pos)             /*!< 0x04000000 */
#define I2C_CR2_PECBYTE              I2C_CR2_PECBYTE_Msk                       /*!< Packet error checking byte */

/*******************  Bit definition for I2C_OAR1 register  ******************/
#define I2C_OAR1_OA1_Pos             (0U)
#define I2C_OAR1_OA1_Msk             (0x3FFU << I2C_OAR1_OA1_Pos)              /*!< 0x000003FF */
#define I2C_OAR1_OA1                 I2C_OAR1_OA1_Msk                          /*!< Interface own address 1 */
#define I2C_OAR1_OA1MODE_Pos         (10U)
#define I2C_OAR1_OA1MODE_Msk         (0x1U << I2C_OAR1_OA1MODE_Pos)            /*!< 0x00000400 */
#define I2C_OAR1_OA1MODE             I2C_OAR1_OA1MODE_Msk                      /*!< Own address 1 10-bit mode */
#define I2C_OAR1_OA1EN_Pos           (15U)
#define I2C_OAR1_OA1EN_Msk           (0x1U << I2C_OAR1_OA1EN_Pos)              /*!< 0x00008000 */
#define I2C_OAR1_OA1EN               I2C_OAR1_OA1EN_Msk                        /*!< Own address 1 enable */

/*******************  Bit definition for I2C_OAR2 register  ******************/
#define I2C_OAR2_OA2_Pos             (1U)
#define I2C_OAR2_OA2_Msk             (0x7FU << I2C_OAR2_OA2_Pos)               /*!< 0x000000FE */
#define I2C_OAR2_OA2                 I2C_OAR2_OA2_Msk                          /*!< Interface own address 2 */
#define I2C_OAR2_OA2MSK_Pos          (8U)
#define I2C_OAR2_OA2MSK_Msk          (0x7U << I2C_OAR2_OA2MSK_Pos)             /*!< 0x00000700 */
#define I2C_OAR2_OA2MSK              I2C_OAR2_OA2MSK_Msk                       /*!< Own address 2 masks */
#define I2C_OAR2_OA2NOMASK           (0x00000000U)                             /*!< No mask                                        */
#define I2C_OAR2_OA2MASK01_Pos       (8U)
#define I2C_OAR2_OA2MASK01_Msk       (0x1U << I2C_OAR2_OA2MASK01_Pos)          /*!< 0x00000100 */
#define I2C_OAR2_OA2MASK01           I2C_OAR2_OA2MASK01_Msk                    /*!< OA2[1] is masked, Only OA2[7:2] are compared   */
#define I2C_OAR2_OA2MASK02_Pos       (9U)
#define I2C_OAR2_OA2MASK02_Msk       (0x1U << I2C_OAR2_OA2MASK02_Pos)          /*!< 0x00000200 */
#define I2C_OAR2_OA2MASK02           I2C_OAR2_OA2MASK02_Msk                    /*!< OA2[2:1] is masked, Only OA2[7:3] are compared */
#define I2C_OAR2_OA2MASK03_Pos       (8U)
#define I2C_OAR2_OA2MASK03_Msk       (0x3U << I2C_OAR2_OA2MASK03_Pos)          /*!< 0x00000300 */
#define I2C_OAR2_OA2MASK03           I2C_OAR2_OA2MASK03_Msk                    /*!< OA2[3:1] is masked, Only OA2[7:4] are compared */
#define I2C_OAR2_OA2MASK04_Pos       (10U)
#define I2C_OAR2_OA2MASK04_Msk       (0x1U << I2C_OAR2_OA2MASK04_Pos)          /*!< 0x00000400 */
#define I2C_OAR2_OA2MASK04           I2C_OAR2_OA2MASK04_Msk                    /*!< OA2[4:1] is masked, Only OA2[7:5] are compared */
#define I2C_OAR2_OA2MASK05_Pos       (8U)
#define I2C_OAR2_OA2MASK05_Msk       (0x5U << I2C_OAR2_OA2MASK05_Pos)          /*!< 0x00000500 */
#define I2C_OAR2_OA2MASK05           I2C_OAR2_OA2MASK05_Msk                    /*!< OA2[5:1] is masked, Only OA2[7:6] are compared */
#define I2C_OAR2_OA2MASK06_Pos       (9U)
#define I2C_OAR2_OA2MASK06_Msk       (0x3U << I2C_OAR2_OA2MASK06_Pos)          /*!< 0x00000600 */
#define I2C_OAR2_OA2MASK06           I2C_OAR2_OA2MASK06_Msk                    /*!< OA2[6:1] is masked, Only OA2[7] are compared   */
#define I2C_OAR2_OA2MASK07_Pos       (8U)
#define I2C_OAR2_OA2MASK07_Msk       (0x7U << I2C_OAR2_OA2MASK07_Pos)          /*!< 0x00000700 */
#define I2C_OAR2_OA2MASK07           I2C_OAR2_OA2MASK07_Msk                    /*!< OA2[7:1] is masked, No comparison is done      */
#define I2C_OAR2_OA2EN_Pos           (15U)
#define I2C_OAR2_OA2EN_Msk           (0x1U << I2C_OAR2_OA2EN_Pos)              /*!< 0x00008000 */
#define I2C_OAR2_OA2EN               I2C_OAR2_OA2EN_Msk                        /*!< Own address 2 enable */

/*******************  Bit definition for I2C_TIMINGR register ****************/
#define I2C_TIMINGR_SCLL_Pos         (0U)
#define I2C_TIMINGR_SCLL_Msk         (0xFFU << I2C_TIMINGR_SCLL_Pos)           /*!< 0x000000FF */
#define I2C_TIMINGR_SCLL             I2C_TIMINGR_SCLL_Msk                      /*!< SCL low period (master mode) */
#define I2C_TIMINGR_SCLH_Pos         (8U)
#define I2C_TIMINGR_SCLH_Msk         (0xFFU << I2C_TIMINGR_SCLH_Pos)           /*!< 0x0000FF00 */
#define I2C_TIMINGR_SCLH             I2C_TIMINGR_SCLH_Msk                      /*!< SCL high period (master mode) */
#define I2C_TIMINGR_SDADEL_Pos       (16U)
#define I2C_TIMINGR_SDADEL_Msk       (0xFU << I2C_TIMINGR_SDADEL_Pos)          /*!< 0x000F0000 */
#define I2C_TIMINGR_SDADEL           I2C_TIMINGR_SDADEL_Msk                    /*!< Data hold time */
#define I2C_TIMINGR_SCLDEL_Pos       (20U)
#define I2C_TIMINGR_SCLDEL_Msk       (0xFU << I2C_TIMINGR_SCLDEL_Pos)          /*!< 0x00F00000 */
#define I2C_TIMINGR_SCLDEL           I2C_TIMINGR_SCLDEL_Msk                    /*!< Data setup time */
#define I2C_TIMINGR_PRESC_Pos        (28U)
#define I2C_TIMINGR_PRESC_Msk        (0xFU << I2C_TIMINGR_PRESC_Pos)           /*!< 0xF0000000 */
#define I2C_TIMINGR_PRESC            I2C_TIMINGR_PRESC_Msk                     /*!< Timings prescaler */

/******************* Bit definition for I2C_TIMEOUTR register ****************/
#define I2C_TIMEOUTR_TIMEOUTA_Pos    (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk    (0xFFFU << I2C_TIMEOUTR_TIMEOUTA_Pos)     /*!< 0x00000FFF */
#define I2C_TIMEOUTR_TIMEOUTA        I2C_TIMEOUTR_TIMEOUTA_Msk                 /*!< Bus timeout A */
#define I2C_TIMEOUTR_TIDLE_Pos       (12U)
#define I2C_TIMEOUTR_TIDLE_Msk       (0x1U << I2C_TIMEOUTR_TIDLE_Pos)          /*!< 0x00001000 */
#define I2C_TIMEOUTR_TIDLE           I2C_TIMEOUTR_TIDLE_Msk                    /*!< Idle clock timeout detection */
#define I2C_TIMEOUTR_TIMOUTEN_Pos    (15U)
#define I2C_TIMEOUTR_TIMOUTEN_Msk    (0x1U << I2C_TIMEOUTR_TIMOUTEN_Pos)       /*!< 0x00008000 */
#define I2C_TIMEOUTR_TIMOUTEN        I2C_TIMEOUTR_TIMOUTEN_Msk                 /*!< Clock timeout enable */
#define I2C_TIMEOUTR_TIMEOUTB_Pos    (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk    (0xFFFU << I2C_TIMEOUTR_TIMEOUTB_Pos)     /*!< 0x0FFF0000 */
#define I2C_TIMEOUTR_TIMEOUTB        I2C_TIMEOUTR_TIMEOUTB_Msk                 /*!< Bus timeout B*/
#define I2C_TIMEOUTR_TEXTEN_Pos      (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk      (0x1U << I2C_TIMEOUTR_TEXTEN_Pos)         /*!< 0x80000000 */
#define I2C_TIMEOUTR_TEXTEN          I2C_TIMEOUTR_TEXTEN_Msk                   /*!< Extended clock timeout enable */

/******************  Bit definition for I2C_ISR register  ********************/
#define I2C_ISR_TXE_Pos              (0U)
#define I2C_ISR_TXE_Msk              (0x1U << I2C_ISR_TXE_Pos)                 /*!< 0x00000001 */
#define I2C_ISR_TXE                  I2C_ISR_TXE_Msk                           /*!< Transmit data register empty */
#define I2C_ISR_TXIS_Pos             (1U)
#define I2C_ISR_TXIS_Msk             (0x1U << I2C_ISR_TXIS_Pos)                /*!< 0x00000002 */
#define I2C_ISR_TXIS                 I2C_ISR_TXIS_Msk                          /*!< Transmit interrupt status */
#define I2C_ISR_RXNE_Pos             (2U)
#define I2C_ISR_RXNE_Msk             (0x1U << I2C_ISR_RXNE_Pos)                /*!< 0x00000004 */
#define I2C_ISR_RXNE                 I2C_ISR_RXNE_Msk                          /*!< Receive data register not empty */
#define I2C_ISR_ADDR_Pos             (3U)
#define I2C_ISR_ADDR_Msk             (0x1U << I2C_ISR_ADDR_Pos)                /*!< 0x00000008 */
#define I2C_ISR_ADDR                 I2C_ISR_ADDR_Msk                          /*!< Address matched (slave mode)*/
#define I2C_ISR_NACKF_Pos            (4U)
#define I2C_ISR_NACKF_Msk            (0x1U << I2C_ISR_NACKF_Pos)               /*!< 0x00000010 */
#define I2C_ISR_NACKF                I2C_ISR_NACKF_Msk                         /*!< NACK received flag */
#define I2C_ISR_STOPF_Pos            (5U)
#define I2C_ISR_STOPF_Msk            (0x1U << I2C_ISR_STOPF_Pos)               /*!< 0x00000020 */
#define I2C_ISR_STOPF                I2C_ISR_STOPF_Msk                         /*!< STOP detection flag */
#define I2C_ISR_TC_Pos               (6U)
#define I2C_ISR_TC_Msk               (0x1U << I2C_ISR_TC_Pos)                  /*!< 0x00000040 */
#define I2C_ISR_TC                   I2C_ISR_TC_Msk                            /*!< Transfer complete (master mode) */
#define I2C_ISR_TCR_Pos              (7U)
#define I2C_ISR_TCR_Msk              (0x1U << I2C_ISR_TCR_Pos)                 /*!< 0x00000080 */
#define I2C_ISR_TCR                  I2C_ISR_TCR_Msk                           /*!< Transfer complete reload */
#define I2C_ISR_BERR_Pos             (8U)
#define I2C_ISR_BERR_Msk             (0x1U << I2C_ISR_BERR_Pos)                /*!< 0x00000100 */
#define I2C_ISR_BERR                 I2C_ISR_BERR_Msk                          /*!< Bus error */
#define I2C_ISR_ARLO_Pos             (9U)
#define I2C_ISR_ARLO_Msk             (0x1U << I2C_ISR_ARLO_Pos)                /*!< 0x00000200 */
#define I2C_ISR_ARLO                 I2C_ISR_ARLO_Msk                          /*!< Arbitration lost */
#define I2C_ISR_OVR_Pos              (10U)
#define I2C_ISR_OVR_Msk              (0x1U << I2C_ISR_OVR_Pos)                 /*!< 0x00000400 */
#define I2C_ISR_OVR                  I2C_ISR_OVR_Msk                           /*!< Overrun/Underrun */
#define I2C_ISR_PECERR_Pos           (11U)
#define I2C_ISR_PECERR_Msk           (0x1U << I2C_ISR_PECERR_Pos)              /*!< 0x00000800 */
#define I2C_ISR_PECERR               I2C_ISR_PECERR_Msk                        /*!< PEC error in reception */
#define I2C_ISR_TIMEOUT_Pos          (12U)
#define I2C_ISR_TIMEOUT_Msk          (0x1U << I2C_ISR_TIMEOUT_Pos)             /*!< 0x00001000 */
#define I2C_ISR_TIMEOUT              I2C_ISR_TIMEOUT_Msk                       /*!< Timeout or Tlow detection flag */
#define I2C_ISR_ALERT_Pos            (13U)
#define I2C_ISR_ALERT_Msk            (0x1U << I2C_ISR_ALERT_Pos)               /*!< 0x00002000 */
#define I2C_ISR_ALERT                I2C_ISR_ALERT_Msk                         /*!< SMBus alert */
#define I2C_ISR_BUSY_Pos             (15U)
#define I2C_ISR_BUSY_Msk             (0x1U << I2C_ISR_BUSY_Pos)                /*!< 0x00008000 */
#define I2C_ISR_BUSY                 I2C_ISR_BUSY_Msk                          /*!< Bus busy */
#define I2C_ISR_DIR_Pos              (16U)
#define I2C_ISR_DIR_Msk              (0x1U << I2C_ISR_DIR_Pos)                 /*!< 0x00010000 */
#define I2C_ISR_DIR                  I2C_ISR_DIR_Msk                           /*!< Transfer direction (slave mode) */
#define I2C_ISR_ADDCODE_Pos          (17U)
#define I2C_ISR_ADDCODE_Msk          (0x7FU << I2C_ISR_ADDCODE_Pos)            /*!< 0x00FE0000 */
#define I2C_ISR_ADDCODE              I2C_ISR_ADDCODE_Msk                       /*!< Address match code (slave mode) */

/******************  Bit definition for I2C_ICR register  ********************/
#define I2C_ICR_ADDRCF_Pos           (3U)
#define I2C_ICR_ADDRCF_Msk           (0x1U << I2C_ICR_ADDRCF_Pos)              /*!< 0x00000008 */
#define I2C_ICR_ADDRCF               I2C_ICR_ADDRCF_Msk                        /*!< Address matched clear flag */
#define I2C_ICR_NACKCF_Pos           (4U)
#define I2C_ICR_NACKCF_Msk           (0x1U << I2C_ICR_NACKCF_Pos)              /*!< 0x00000010 */
#define I2C_ICR_NACKCF               I2C_ICR_NACKCF_Msk                        /*!< NACK clear flag */
#define I2C_ICR_STOPCF_Pos           (5U)
#define I2C_ICR_STOPCF_Msk           (0x1U << I2C_ICR_STOPCF_Pos)              /*!< 0x00000020 */
#define I2C_ICR_STOPCF               I2C_ICR_STOPCF_Msk                        /*!< STOP detection clear flag */
#define I2C_ICR_BERRCF_Pos           (8U)
#define I2C_ICR_BERRCF_Msk           (0x1U << I2C_ICR_BERRCF_Pos)              /*!< 0x00000100 */
#define I2C_ICR_BERRCF               I2C_ICR_BERRCF_Msk                        /*!< Bus error clear flag */
#define I2C_ICR_ARLOCF_Pos           (9U)
#define I2C_ICR_ARLOCF_Msk           (0x1U << I2C_ICR_ARLOCF_Pos)              /*!< 0x00000200 */
#define I2C_ICR_ARLOCF               I2C_ICR_ARLOCF_Msk                        /*!< Arbitration lost clear flag */
#define I2C_ICR_OVRCF_Pos            (10U)
#define I2C_ICR_OVRCF_Msk            (0x1U << I2C_ICR_OVRCF_Pos)               /*!< 0x00000400 */
#define I2C_ICR_OVRCF                I2C_ICR_OVRCF_Msk                         /*!< Overrun/Underrun clear flag */
#define I2C_ICR_PECCF_Pos            (11U)
#define I2C_ICR_PECCF_Msk            (0x1U << I2C_ICR_PECCF_Pos)               /*!< 0x00000800 */
#define I2C_ICR_PECCF                I2C_ICR_PECCF_Msk                         /*!< PAC error clear flag */
#define I2C_ICR_TIMOUTCF_Pos         (12U)
#define I2C_ICR_TIMOUTCF_Msk         (0x1U << I2C_ICR_TIMOUTCF_Pos)            /*!< 0x00001000 */
#define I2C_ICR_TIMOUTCF             I2C_ICR_TIMOUTCF_Msk                      /*!< Timeout clear flag */
#define I2C_ICR_ALERTCF_Pos          (13U)
#define I2C_ICR_ALERTCF_Msk          (0x1U << I2C_ICR_ALERTCF_Pos)             /*!< 0x00002000 */
#define I2C_ICR_ALERTCF              I2C_ICR_ALERTCF_Msk                       /*!< Alert clear flag */

/******************  Bit definition for I2C_PECR register  *******************/
#define I2C_PECR_PEC_Pos             (0U)
#define I2C_PECR_PEC_Msk             (0xFFU << I2C_PECR_PEC_Pos)               /*!< 0x000000FF */
#define I2C_PECR_PEC                 I2C_PECR_PEC_Msk                          /*!< PEC register */

/******************  Bit definition for I2C_RXDR register  *********************/
#define I2C_RXDR_RXDATA_Pos          (0U)
#define I2C_RXDR_RXDATA_Msk          (0xFFU << I2C_RXDR_RXDATA_Pos)            /*!< 0x000000FF */
#define I2C_RXDR_RXDATA              I2C_RXDR_RXDATA_Msk                       /*!< 8-bit receive data */

/******************  Bit definition for I2C_TXDR register  *******************/
#define I2C_TXDR_TXDATA_Pos          (0U)
#define I2C_TXDR_TXDATA_Msk          (0xFFU << I2C_TXDR_TXDATA_Pos)            /*!< 0x000000FF */
#define I2C_TXDR_TXDATA              I2C_TXDR_TXDATA_Msk                       /*!< 8-bit transmit data */


/*****************************************************************************/
/*                                                                           */
/*                        Independent WATCHDOG (IWDG)                        */
/*                                                                           */
/*****************************************************************************/
/*******************  Bit definition for IWDG_KR register  *******************/
#define IWDG_KR_KEY_Pos      (0U)
#define IWDG_KR_KEY_Msk      (0xFFFFU << IWDG_KR_KEY_Pos)                      /*!< 0x0000FFFF */
#define IWDG_KR_KEY          IWDG_KR_KEY_Msk                                   /*!< Key value (write only, read 0000h) */

/*******************  Bit definition for IWDG_PR register  *******************/
#define IWDG_PR_PR_Pos       (0U)
#define IWDG_PR_PR_Msk       (0x7U << IWDG_PR_PR_Pos)                          /*!< 0x00000007 */
#define IWDG_PR_PR           IWDG_PR_PR_Msk                                    /*!< PR[2:0] (Prescaler divider) */
#define IWDG_PR_PR_0         (0x1U << IWDG_PR_PR_Pos)                          /*!< 0x01 */
#define IWDG_PR_PR_1         (0x2U << IWDG_PR_PR_Pos)                          /*!< 0x02 */
#define IWDG_PR_PR_2         (0x4U << IWDG_PR_PR_Pos)                          /*!< 0x04 */

/*******************  Bit definition for IWDG_RLR register  ******************/
#define IWDG_RLR_RL_Pos      (0U)
#define IWDG_RLR_RL_Msk      (0xFFFU << IWDG_RLR_RL_Pos)                       /*!< 0x00000FFF */
#define IWDG_RLR_RL          IWDG_RLR_RL_Msk                                   /*!< Watchdog counter reload value */

/*******************  Bit definition for IWDG_SR register  *******************/
#define IWDG_SR_PVU_Pos      (0U)
#define IWDG_SR_PVU_Msk      (0x1U << IWDG_SR_PVU_Pos)                         /*!< 0x00000001 */
#define IWDG_SR_PVU          IWDG_SR_PVU_Msk                                   /*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos      (1U)
#define IWDG_SR_RVU_Msk      (0x1U << IWDG_SR_RVU_Pos)                         /*!< 0x00000002 */
#define IWDG_SR_RVU          IWDG_SR_RVU_Msk                                   /*!< Watchdog counter reload value update */
#define IWDG_SR_WVU_Pos      (2U)
#define IWDG_SR_WVU_Msk      (0x1U << IWDG_SR_WVU_Pos)                         /*!< 0x00000004 */
#define IWDG_SR_WVU          IWDG_SR_WVU_Msk                                   /*!< Watchdog counter window value update */

/*******************  Bit definition for IWDG_KR register  *******************/
#define IWDG_WINR_WIN_Pos    (0U)
#define IWDG_WINR_WIN_Msk    (0xFFFU << IWDG_WINR_WIN_Pos)                     /*!< 0x00000FFF */
#define IWDG_WINR_WIN        IWDG_WINR_WIN_Msk                                 /*!< Watchdog counter window value */

/*****************************************************************************/
/*                                                                           */
/*                          Power Control (PWR)                              */
/*                                                                           */
/*****************************************************************************/

#define PWR_PVD_SUPPORT                       /*!< PWR feature available only on specific devices: Power Voltage Detection feature */


/********************  Bit definition for PWR_CR register  *******************/
#define PWR_CR_LPDS_Pos            (0U)
#define PWR_CR_LPDS_Msk            (0x1U << PWR_CR_LPDS_Pos)                   /*!< 0x00000001 */
#define PWR_CR_LPDS                PWR_CR_LPDS_Msk                             /*!< Low-power Deepsleep */
#define PWR_CR_PDDS_Pos            (1U)
#define PWR_CR_PDDS_Msk            (0x1U << PWR_CR_PDDS_Pos)                   /*!< 0x00000002 */
#define PWR_CR_PDDS                PWR_CR_PDDS_Msk                             /*!< Power Down Deepsleep */
#define PWR_CR_CWUF_Pos            (2U)
#define PWR_CR_CWUF_Msk            (0x1U << PWR_CR_CWUF_Pos)                   /*!< 0x00000004 */
#define PWR_CR_CWUF                PWR_CR_CWUF_Msk                             /*!< Clear Wakeup Flag */
#define PWR_CR_CSBF_Pos            (3U)
#define PWR_CR_CSBF_Msk            (0x1U << PWR_CR_CSBF_Pos)                   /*!< 0x00000008 */
#define PWR_CR_CSBF                PWR_CR_CSBF_Msk                             /*!< Clear Standby Flag */
#define PWR_CR_PVDE_Pos            (4U)
#define PWR_CR_PVDE_Msk            (0x1U << PWR_CR_PVDE_Pos)                   /*!< 0x00000010 */
#define PWR_CR_PVDE                PWR_CR_PVDE_Msk                             /*!< Power Voltage Detector Enable */

#define PWR_CR_PLS_Pos             (5U)
#define PWR_CR_PLS_Msk             (0x7U << PWR_CR_PLS_Pos)                    /*!< 0x000000E0 */
#define PWR_CR_PLS                 PWR_CR_PLS_Msk                              /*!< PLS[2:0] bits (PVD Level Selection) */
#define PWR_CR_PLS_0               (0x1U << PWR_CR_PLS_Pos)                    /*!< 0x00000020 */
#define PWR_CR_PLS_1               (0x2U << PWR_CR_PLS_Pos)                    /*!< 0x00000040 */
#define PWR_CR_PLS_2               (0x4U << PWR_CR_PLS_Pos)                    /*!< 0x00000080 */

/*!< PVD level configuration */
#define PWR_CR_PLS_LEV0            (0x00000000U)                               /*!< PVD level 0 */
#define PWR_CR_PLS_LEV1            (0x00000020U)                               /*!< PVD level 1 */
#define PWR_CR_PLS_LEV2            (0x00000040U)                               /*!< PVD level 2 */
#define PWR_CR_PLS_LEV3            (0x00000060U)                               /*!< PVD level 3 */
#define PWR_CR_PLS_LEV4            (0x00000080U)                               /*!< PVD level 4 */
#define PWR_CR_PLS_LEV5            (0x000000A0U)                               /*!< PVD level 5 */
#define PWR_CR_PLS_LEV6            (0x000000C0U)                               /*!< PVD level 6 */
#define PWR_CR_PLS_LEV7            (0x000000E0U)                               /*!< PVD level 7 */

#define PWR_CR_DBP_Pos             (8U)
#define PWR_CR_DBP_Msk             (0x1U << PWR_CR_DBP_Pos)                    /*!< 0x00000100 */
#define PWR_CR_DBP                 PWR_CR_DBP_Msk                              /*!< Disable Backup Domain write protection */

/*******************  Bit definition for PWR_CSR register  *******************/
#define PWR_CSR_WUF_Pos            (0U)
#define PWR_CSR_WUF_Msk            (0x1U << PWR_CSR_WUF_Pos)                   /*!< 0x00000001 */
#define PWR_CSR_WUF                PWR_CSR_WUF_Msk                             /*!< Wakeup Flag */
#define PWR_CSR_SBF_Pos            (1U)
#define PWR_CSR_SBF_Msk            (0x1U << PWR_CSR_SBF_Pos)                   /*!< 0x00000002 */
#define PWR_CSR_SBF                PWR_CSR_SBF_Msk                             /*!< Standby Flag */
#define PWR_CSR_PVDO_Pos           (2U)
#define PWR_CSR_PVDO_Msk           (0x1U << PWR_CSR_PVDO_Pos)                  /*!< 0x00000004 */
#define PWR_CSR_PVDO               PWR_CSR_PVDO_Msk                            /*!< PVD Output */
#define PWR_CSR_VREFINTRDYF_Pos    (3U)
#define PWR_CSR_VREFINTRDYF_Msk    (0x1U << PWR_CSR_VREFINTRDYF_Pos)           /*!< 0x00000008 */
#define PWR_CSR_VREFINTRDYF        PWR_CSR_VREFINTRDYF_Msk                     /*!< Internal voltage reference (VREFINT) ready flag */

#define PWR_CSR_EWUP1_Pos          (8U)
#define PWR_CSR_EWUP1_Msk          (0x1U << PWR_CSR_EWUP1_Pos)                 /*!< 0x00000100 */
#define PWR_CSR_EWUP1              PWR_CSR_EWUP1_Msk                           /*!< Enable WKUP pin 1 */
#define PWR_CSR_EWUP2_Pos          (9U)
#define PWR_CSR_EWUP2_Msk          (0x1U << PWR_CSR_EWUP2_Pos)                 /*!< 0x00000200 */
#define PWR_CSR_EWUP2              PWR_CSR_EWUP2_Msk                           /*!< Enable WKUP pin 2 */
#define PWR_CSR_EWUP3_Pos          (10U)
#define PWR_CSR_EWUP3_Msk          (0x1U << PWR_CSR_EWUP3_Pos)                 /*!< 0x00000400 */
#define PWR_CSR_EWUP3              PWR_CSR_EWUP3_Msk                           /*!< Enable WKUP pin 3 */
#define PWR_CSR_EWUP4_Pos          (11U)
#define PWR_CSR_EWUP4_Msk          (0x1U << PWR_CSR_EWUP4_Pos)                 /*!< 0x00000800 */
#define PWR_CSR_EWUP4              PWR_CSR_EWUP4_Msk                           /*!< Enable WKUP pin 4 */
#define PWR_CSR_EWUP5_Pos          (12U)
#define PWR_CSR_EWUP5_Msk          (0x1U << PWR_CSR_EWUP5_Pos)                 /*!< 0x00001000 */
#define PWR_CSR_EWUP5              PWR_CSR_EWUP5_Msk                           /*!< Enable WKUP pin 5 */
#define PWR_CSR_EWUP6_Pos          (13U)
#define PWR_CSR_EWUP6_Msk          (0x1U << PWR_CSR_EWUP6_Pos)                 /*!< 0x00002000 */
#define PWR_CSR_EWUP6              PWR_CSR_EWUP6_Msk                           /*!< Enable WKUP pin 6 */
#define PWR_CSR_EWUP7_Pos          (14U)
#define PWR_CSR_EWUP7_Msk          (0x1U << PWR_CSR_EWUP7_Pos)                 /*!< 0x00004000 */
#define PWR_CSR_EWUP7              PWR_CSR_EWUP7_Msk                           /*!< Enable WKUP pin 7 */
#define PWR_CSR_EWUP8_Pos          (15U)
#define PWR_CSR_EWUP8_Msk          (0x1U << PWR_CSR_EWUP8_Pos)                 /*!< 0x00008000 */
#define PWR_CSR_EWUP8              PWR_CSR_EWUP8_Msk                           /*!< Enable WKUP pin 8 */
