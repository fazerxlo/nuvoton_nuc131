/**************************************************************************//**
 * @file     clk.h
 * @version  V3.0
 * $Revision: 17 $
 * $Date: 17/07/24 1:24p $
 * @brief    NUC131 Series Clock Control Driver Header File
 *
 * @note
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 *
 * @copyright Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __CLK_H__
#define __CLK_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup NUC131_Device_Driver NUC131 Device Driver
  @{
*/

/** @addtogroup NUC131_CLK_Driver CLK Driver
  @{
*/

/** @addtogroup NUC131_CLK_EXPORTED_CONSTANTS CLK Exported Constants
  @{
*/

#define FREQ_25MHZ         25000000
#define FREQ_50MHZ         50000000
#define FREQ_100MHZ       100000000
#define FREQ_200MHZ       200000000


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL0 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL0_HCLK_S_HXT          (0x0UL<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Setting HCLK clock source as external X'tal */
#define CLK_CLKSEL0_HCLK_S_PLL          (0x2UL<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Setting HCLK clock source as PLL output */
#define CLK_CLKSEL0_HCLK_S_LIRC         (0x3UL<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Setting HCLK clock source as internal 10KHz RC clock */
#define CLK_CLKSEL0_HCLK_S_HIRC         (0x7UL<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Setting HCLK clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL0_STCLK_S_HXT         (0x0UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting STCLK clock source as external X'tal */
#define CLK_CLKSEL0_STCLK_S_HXT_DIV2    (0x2UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting STCLK clock source as external X'tal/2 */
#define CLK_CLKSEL0_STCLK_S_HCLK_DIV2   (0x3UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting STCLK clock source as HCLK/2 */
#define CLK_CLKSEL0_STCLK_S_HIRC_DIV2   (0x7UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting STCLK clock source as internal 22.1184MHz RC clock/2 */
#define CLK_CLKSEL0_STCLK_S_HCLK        (0x1UL<<SysTick_CTRL_CLKSOURCE_Pos)  /*!< Setting STCLK clock source as HCLK */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL1_WDT_S_HCLK_DIV2048  (0x2UL<<CLK_CLKSEL1_WDT_S_Pos)    /*!< Setting WDT clock source as HCLK/2048 */
#define CLK_CLKSEL1_WDT_S_LIRC          (0x3UL<<CLK_CLKSEL1_WDT_S_Pos)    /*!< Setting WDT clock source as internal 10KHz RC clock */

#define CLK_CLKSEL1_ADC_S_HXT           (0x0UL<<CLK_CLKSEL1_ADC_S_Pos)    /*!< Setting ADC clock source as external X'tal */
#define CLK_CLKSEL1_ADC_S_PLL           (0x1UL<<CLK_CLKSEL1_ADC_S_Pos)    /*!< Setting ADC clock source as PLL */
#define CLK_CLKSEL1_ADC_S_HCLK          (0x2UL<<CLK_CLKSEL1_ADC_S_Pos)    /*!< Setting ADC clock source as HCLK */
#define CLK_CLKSEL1_ADC_S_HIRC          (0x3UL<<CLK_CLKSEL1_ADC_S_Pos)    /*!< Setting ADC clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_SPI0_S_PLL          (0x0UL<<CLK_CLKSEL1_SPI0_S_Pos)   /*!< Setting SPI0 clock source as PLL */
#define CLK_CLKSEL1_SPI0_S_HCLK         (0x1UL<<CLK_CLKSEL1_SPI0_S_Pos)   /*!< Setting SPI0 clock source as HCLK */

#define CLK_CLKSEL1_TMR0_S_HXT          (0x0UL<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Setting TMR0 clock source as external X'tal */
#define CLK_CLKSEL1_TMR0_S_HCLK         (0x2UL<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Setting TMR0 clock source as HCLK */
#define CLK_CLKSEL1_TMR0_S_EXT_TRG      (0x3UL<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Setting TMR0 clock source as external trigger */
#define CLK_CLKSEL1_TMR0_S_LIRC         (0x5UL<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Setting TMR0 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR0_S_HIRC         (0x7UL<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Setting TMR0 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL1_TMR1_S_HXT          (0x0UL<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Setting TMR1 clock source as external X'tal */
#define CLK_CLKSEL1_TMR1_S_HCLK         (0x2UL<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Setting TMR1 clock source as HCLK */
#define CLK_CLKSEL1_TMR1_S_EXT_TRG      (0x3UL<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Setting TMR1 clock source as external trigger */
#define CLK_CLKSEL1_TMR1_S_LIRC         (0x5UL<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Setting TMR1 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR1_S_HIRC         (0x7UL<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Setting TMR1 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL1_TMR2_S_HXT          (0x0UL<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Setting TMR2 clock source as external X'tal */
#define CLK_CLKSEL1_TMR2_S_HCLK         (0x2UL<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Setting TMR2 clock source as HCLK */
#define CLK_CLKSEL1_TMR2_S_EXT_TRG      (0x3UL<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Setting TMR2 clock source as external trigger */
#define CLK_CLKSEL1_TMR2_S_LIRC         (0x5UL<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Setting TMR2 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR2_S_HIRC         (0x7UL<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Setting TMR2 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL1_TMR3_S_HXT          (0x0UL<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Setting TMR3 clock source as external X'tal */
#define CLK_CLKSEL1_TMR3_S_HCLK         (0x2UL<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Setting TMR3 clock source as HCLK */
#define CLK_CLKSEL1_TMR3_S_EXT_TRG      (0x3UL<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Setting TMR3 clock source as external trigger */
#define CLK_CLKSEL1_TMR3_S_LIRC         (0x5UL<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Setting TMR3 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR3_S_HIRC         (0x7UL<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Setting TMR3 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_UART_S_HXT          (0x0UL<<CLK_CLKSEL1_UART_S_Pos)   /*!< Setting UART clock source as external X'tal */
#define CLK_CLKSEL1_UART_S_PLL          (0x1UL<<CLK_CLKSEL1_UART_S_Pos)   /*!< Setting UART clock source as external PLL */
#define CLK_CLKSEL1_UART_S_HIRC         (0x3UL<<CLK_CLKSEL1_UART_S_Pos)   /*!< Setting UART clock source as external internal 22.1184MHz RC clock */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL2 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL2_FRQDIV_S_HXT        (0x0UL<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Setting FRQDIV clock source as external X'tal */
#define CLK_CLKSEL2_FRQDIV_S_HCLK       (0x2UL<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Setting FRQDIV clock source as HCLK */
#define CLK_CLKSEL2_FRQDIV_S_HIRC       (0x3UL<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Setting FRQDIV clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL2_WWDT_S_HCLK_DIV2048 (0x2UL<<CLK_CLKSEL2_WWDT_S_Pos)   /*!< Setting WWDT clock source as HCLK/2048 */
#define CLK_CLKSEL2_WWDT_S_LIRC         (0x3UL<<CLK_CLKSEL2_WWDT_S_Pos)   /*!< Setting WWDT clock source as internal 10KHz RC clock */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL3 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL3_PWM0_S_PLL          (0x0UL<<CLK_CLKSEL3_PWM0_S_Pos)    /*!< Setting PWM0 clock source as PLL */
#define CLK_CLKSEL3_PWM0_S_PCLK         (0x1UL<<CLK_CLKSEL3_PWM0_S_Pos)    /*!< Setting PWM0 clock source as PCLK */
#define CLK_CLKSEL3_PWM1_S_PLL          (0x0UL<<CLK_CLKSEL3_PWM1_S_Pos)    /*!< Setting PWM1 clock source as PLL */
#define CLK_CLKSEL3_PWM1_S_PCLK         (0x1UL<<CLK_CLKSEL3_PWM1_S_Pos)    /*!< Setting PWM1 clock source as PCLK */

#define CLK_CLKSEL3_BPWM0_S_PLL         (0x0UL<<CLK_CLKSEL3_BPWM0_S_Pos)    /*!< Setting BPWM0 clock source as PLL */
#define CLK_CLKSEL3_BPWM0_S_PCLK        (0x1UL<<CLK_CLKSEL3_BPWM0_S_Pos)    /*!< Setting BPWM0 clock source as PCLK */
#define CLK_CLKSEL3_BPWM1_S_PLL         (0x0UL<<CLK_CLKSEL3_BPWM1_S_Pos)    /*!< Setting BPWM1 clock source as PLL */
#define CLK_CLKSEL3_BPWM1_S_PCLK        (0x1UL<<CLK_CLKSEL3_BPWM1_S_Pos)    /*!< Setting BPWM1 clock source as PCLK */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKDIV_HCLK(x)  ((x)-1)                             /*!< CLKDIV Setting for HCLK clock divider. It could be 1~16 */
#define CLK_CLKDIV_UART(x) (((x)-1) << CLK_CLKDIV_UART_N_Pos)   /*!< CLKDIV Setting for UART clock divider. It could be 1~16 */
#define CLK_CLKDIV_ADC(x)  (((x)-1) << CLK_CLKDIV_ADC_N_Pos)    /*!< CLKDIV Setting for ADC clock divider. It could be 1~256 */


/*---------------------------------------------------------------------------------------------------------*/
/*  PLLCON constant definitions. PLL = FIN * NF / NR / NO                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PLLCON_PLL_SRC_HXT   0x00000000UL    /*!< For PLL clock source is HXT.  3.2MHz < FIN < 150MHz */
#define CLK_PLLCON_PLL_SRC_HIRC  0x00080000UL    /*!< For PLL clock source is HIRC. 3.2MHz < FIN < 150MHz */

#define CLK_PLLCON_NR(x)         (((x)-2)<<9)    /*!< x must be constant and 2 <= x <= 33.  1.6MHz < FIN/NR < 15MHz */
#define CLK_PLLCON_NF(x)          ((x)-2)        /*!< x must be constant and 2 <= x <= 513. 100MHz < FIN*NF/NR < 200MHz. (120MHz < FIN*NF/NR < 200MHz is preferred.) */

#define CLK_PLLCON_NO_1          0x0000UL        /*!< For output divider is 1 */
#define CLK_PLLCON_NO_2          0x4000UL        /*!< For output divider is 2 */
#define CLK_PLLCON_NO_4          0xC000UL        /*!< For output divider is 4 */

#if (__HXT == 12000000)
#define CLK_PLLCON_50MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(3) | CLK_PLLCON_NF( 25) | CLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 50MHz PLL output with 12MHz X'tal */
#define CLK_PLLCON_48MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(7) | CLK_PLLCON_NF(112) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 48MHz PLL output with 12MHz X'tal */
#define CLK_PLLCON_36MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(7) | CLK_PLLCON_NF( 84) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 36MHz PLL output with 12MHz X'tal */
#define CLK_PLLCON_32MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(6) | CLK_PLLCON_NF( 64) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 32MHz PLL output with 12MHz X'tal */
#define CLK_PLLCON_25MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(3) | CLK_PLLCON_NF( 25) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 25MHz PLL output with 12MHz X'tal */
#else
# error "The PLL pre-definitions are only valid when external crystal is 12MHz"
#endif

#define CLK_PLLCON_50MHz_HIRC (CLK_PLLCON_PLL_SRC_HIRC | CLK_PLLCON_NR(13) | CLK_PLLCON_NF( 59) | CLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 50.1918MHz PLL output with 22.1184MHz IRC */
#define CLK_PLLCON_48MHz_HIRC (CLK_PLLCON_PLL_SRC_HIRC | CLK_PLLCON_NR(13) | CLK_PLLCON_NF(113) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 48.064985MHz PLL output with 22.1184MHz IRC*/
#define CLK_PLLCON_36MHz_HIRC (CLK_PLLCON_PLL_SRC_HIRC | CLK_PLLCON_NR(12) | CLK_PLLCON_NF( 78) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 35.9424MHz PLL output with 22.1184MHz IRC */
#define CLK_PLLCON_32MHz_HIRC (CLK_PLLCON_PLL_SRC_HIRC | CLK_PLLCON_NR( 9) | CLK_PLLCON_NF( 52) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 31.9488MHz PLL output with 22.1184MHz IRC*/
#define CLK_PLLCON_25MHz_HIRC (CLK_PLLCON_PLL_SRC_HIRC | CLK_PLLCON_NR(13) | CLK_PLLCON_NF( 59) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 25.0959MHz PLL output with 22.1184MHz IRC*/


/*---------------------------------------------------------------------------------------------------------*/
/*  MODULE constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/

/* APBCLK(31:30)|CLKSEL(29:28)|CLKSEL_Msk(27:25) |CLKSEL_Pos(24:20)|CLKDIV(19:18)|CLKDIV_Msk(17:10)|CLKDIV_Pos(9:5)|IP_EN_Pos(4:0) */

#define MODULE_APBCLK(x)        (((x) >>30) & 0x3)    /*!< Calculate APBCLK offset on MODULE index, 0x0:AHBCLK, 0x1:APBCLK, 0x2:APBCLK1 */
#define MODULE_CLKSEL(x)        (((x) >>28) & 0x3)    /*!< Calculate CLKSEL offset on MODULE index, 0x0:CLKSEL0, 0x1:CLKSEL1, 0x2:CLKSEL2, 0x3:CLKSEL3 */
#define MODULE_CLKSEL_Msk(x)    (((x) >>25) & 0x7)    /*!< Calculate CLKSEL mask offset on MODULE index */
#define MODULE_CLKSEL_Pos(x)    (((x) >>20) & 0x1f)   /*!< Calculate CLKSEL position offset on MODULE index */
#define MODULE_CLKDIV(x)        (((x) >>18) & 0x3)    /*!< Calculate APBCLK CLKDIV on MODULE index, 0x0:CLKDIV */
#define MODULE_CLKDIV_Msk(x)    (((x) >>10) & 0xff)   /*!< Calculate CLKDIV mask offset on MODULE index */
#define MODULE_CLKDIV_Pos(x)    (((x) >>5 ) & 0x1f)   /*!< Calculate CLKDIV position offset on MODULE index */
#define MODULE_IP_EN_Pos(x)     (((x) >>0 ) & 0x1f)   /*!< Calculate APBCLK offset on MODULE index */
#define MODULE_NoMsk            0x0                   /*!< Not mask on MODULE index */
#define NA                      MODULE_NoMsk          /*!< Not Available */

#define MODULE_APBCLK_ENC(x)        (((x) & 0x03) << 30)   /*!< MODULE index, 0x0:AHBCLK, 0x1:APBCLK, 0x2:APBCLK1 */
#define MODULE_CLKSEL_ENC(x)        (((x) & 0x03) << 28)   /*!< CLKSEL offset on MODULE index, 0x0:CLKSEL0, 0x1:CLKSEL1, 0x2:CLKSEL2, 0x3:CLKSEL3 */
#define MODULE_CLKSEL_Msk_ENC(x)    (((x) & 0x07) << 25)   /*!< CLKSEL mask offset on MODULE index */
#define MODULE_CLKSEL_Pos_ENC(x)    (((x) & 0x1f) << 20)   /*!< CLKSEL position offset on MODULE index */
#define MODULE_CLKDIV_ENC(x)        (((x) & 0x03) << 18)   /*!< APBCLK CLKDIV on MODULE index, 0x0:CLKDIV, 0x1:CLKDIV1 */
#define MODULE_CLKDIV_Msk_ENC(x)    (((x) & 0xff) << 10)   /*!< CLKDIV mask offset on MODULE index */
#define MODULE_CLKDIV_Pos_ENC(x)    (((x) & 0x1f) <<  5)   /*!< CLKDIV position offset on MODULE index */
#define MODULE_IP_EN_Pos_ENC(x)     (((x) & 0x1f) <<  0)   /*!< APBCLK offset on MODULE index */


#define ISP_MODULE     (MODULE_APBCLK_ENC( 0)|MODULE_IP_EN_Pos_ENC(CLK_AHBCLK_ISP_EN_Pos)  |\
                        MODULE_CLKSEL_ENC(NA)|MODULE_CLKSEL_Msk_ENC(NA)|MODULE_CLKSEL_Pos_ENC(NA)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< ISP Module */

#define WDT_MODULE     (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_WDT_EN_Pos)  |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC( 0)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< WDT Module */

#define TMR0_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_TMR0_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 7)|MODULE_CLKSEL_Pos_ENC( 8)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< TMR0 Module */

#define TMR1_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_TMR1_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 7)|MODULE_CLKSEL_Pos_ENC(12)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< TMR1 Module */

#define TMR2_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_TMR2_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 7)|MODULE_CLKSEL_Pos_ENC(16)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< TMR2 Module */

#define TMR3_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_TMR3_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 7)|MODULE_CLKSEL_Pos_ENC(20)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< TMR3 Module */

#define FDIV_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_FDIV_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 2)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC( 2)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< FDIV Module */

#define I2C0_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_I2C0_EN_Pos) |\
                        MODULE_CLKSEL_ENC(NA)|MODULE_CLKSEL_Msk_ENC(NA)|MODULE_CLKSEL_Pos_ENC(NA)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< I2C0 Module */

#define I2C1_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_I2C1_EN_Pos) |\
                        MODULE_CLKSEL_ENC(NA)|MODULE_CLKSEL_Msk_ENC(NA)|MODULE_CLKSEL_Pos_ENC(NA)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< I2C1 Module */

#define SPI0_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_SPI0_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 1)|MODULE_CLKSEL_Pos_ENC( 4)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< SPI0 Module */

#define UART0_MODULE   (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_UART0_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(24)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0x0F)|MODULE_CLKDIV_Pos_ENC( 8))    /*!< UART0 Module */

#define UART1_MODULE   (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_UART1_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(24)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0x0F)|MODULE_CLKDIV_Pos_ENC( 8))    /*!< UART1 Module */

#define UART2_MODULE   (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_UART2_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(24)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0x0F)|MODULE_CLKDIV_Pos_ENC( 8))    /*!< UART2 Module */

#define CAN0_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_CAN0_EN_Pos) |\
                        MODULE_CLKSEL_ENC(NA)|MODULE_CLKSEL_Msk_ENC(NA)|MODULE_CLKSEL_Pos_ENC(NA)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< CAN0 Module */

#define ADC_MODULE     (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_ADC_EN_Pos)  |\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC( 2)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0xFF)|MODULE_CLKDIV_Pos_ENC(16))    /*!< ADC Module */

#define WWDT_MODULE    (MODULE_APBCLK_ENC( 1)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK_WDT_EN_Pos) |\
                        MODULE_CLKSEL_ENC( 2)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(16)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< WWDT Module */

#define UART3_MODULE   (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_UART3_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(24)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0x0F)|MODULE_CLKDIV_Pos_ENC( 8))    /*!< UART3 Module */

#define UART4_MODULE   (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_UART4_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(24)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0x0F)|MODULE_CLKDIV_Pos_ENC( 8))    /*!< UART4 Module */

#define UART5_MODULE   (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_UART5_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 1)|MODULE_CLKSEL_Msk_ENC( 3)|MODULE_CLKSEL_Pos_ENC(24)|\
                        MODULE_CLKDIV_ENC( 0)|MODULE_CLKDIV_Msk_ENC(0x0F)|MODULE_CLKDIV_Pos_ENC( 8))    /*!< UART5 Module */

#define PWM0_MODULE    (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_PWM0_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 3)|MODULE_CLKSEL_Msk_ENC( 1)|MODULE_CLKSEL_Pos_ENC(16)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< PWM0 Module */

#define PWM1_MODULE    (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_PWM1_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 3)|MODULE_CLKSEL_Msk_ENC( 1)|MODULE_CLKSEL_Pos_ENC(17)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< PWM1 Module */

#define BPWM0_MODULE   (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_BPWM0_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 3)|MODULE_CLKSEL_Msk_ENC( 1)|MODULE_CLKSEL_Pos_ENC(18)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< BPWM0 Module */

#define BPWM1_MODULE   (MODULE_APBCLK_ENC(2UL)|MODULE_IP_EN_Pos_ENC(CLK_APBCLK1_BPWM1_EN_Pos)|\
                        MODULE_CLKSEL_ENC( 3)|MODULE_CLKSEL_Msk_ENC( 1)|MODULE_CLKSEL_Pos_ENC(19)|\
                        MODULE_CLKDIV_ENC(NA)|MODULE_CLKDIV_Msk_ENC(NA)|MODULE_CLKDIV_Pos_ENC(NA))      /*!< BPWM1 Module */


/*@}*/ /* end of group NUC131_CLK_EXPORTED_CONSTANTS */


/** @addtogroup NUC131_CLK_EXPORTED_FUNCTIONS CLK Exported Functions
  @{
*/


/**
  * @brief      Get PLL clock frequency
  * @param      None
  * @return     PLL frequency
  * @details    This function get PLL frequency. The frequency unit is Hz.
  */
__STATIC_INLINE uint32_t CLK_GetPLLClockFreq(void)
{
    uint32_t u32PllFreq = 0, u32PllReg;
    uint32_t u32FIN, u32NF, u32NR, u32NO;
    uint8_t au8NoTbl[4] = {1, 2, 2, 4};

    u32PllReg = CLK->PLLCON;

    if(u32PllReg & (CLK_PLLCON_PD_Msk | CLK_PLLCON_OE_Msk))
        return 0;           /* PLL is in power down mode or fix low */

    if(u32PllReg & CLK_PLLCON_PLL_SRC_HIRC)
        u32FIN = __HIRC;    /* PLL source clock from HIRC */
    else
        u32FIN = __HXT;     /* PLL source clock from HXT */

    if(u32PllReg & CLK_PLLCON_BP_Msk)
        return u32FIN;      /* PLL is in bypass mode */

    /* PLL is output enabled in normal work mode */
    u32NO = au8NoTbl[((u32PllReg & CLK_PLLCON_OUT_DV_Msk) >> CLK_PLLCON_OUT_DV_Pos)];
    u32NF = ((u32PllReg & CLK_PLLCON_FB_DV_Msk) >> CLK_PLLCON_FB_DV_Pos) + 2;
    u32NR = ((u32PllReg & CLK_PLLCON_IN_DV_Msk) >> CLK_PLLCON_IN_DV_Pos) + 2;

    /* u32FIN is shifted 2 bits to avoid overflow */
    u32PllFreq = (((u32FIN >> 2) * u32NF) / (u32NR * u32NO) << 2);

    return u32PllFreq;
}

/**
  * @brief      This function execute delay function.
  * @param[in]  us  Delay time. The Max value is 2^24 / CPU Clock(MHz). Ex:
  *                             50MHz => 335544us, 48MHz => 349525us, 28MHz => 699050us ...
  * @return     None
  * @details    Use the SysTick to generate the delay time and the UNIT is in us.
  *             The SysTick clock source is from HCLK, i.e the same as system core clock.
  *             User can use SystemCoreClockUpdate() to calculate CyclesPerUs automatically before using this function.
  */
__STATIC_INLINE void CLK_SysTickDelay(uint32_t us)
{
    SysTick->LOAD = us * CyclesPerUs;
    SysTick->VAL  = (0x00);
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    /* Waiting for down-count to zero */
    while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);

    /* Disable SysTick counter */
    SysTick->CTRL = 0;
}

/**
  * @brief      This function execute long delay function.
  * @param[in]  us  Delay time.
  * @return     None
  * @details    Use the SysTick to generate the long delay time and the UNIT is in us.
  *             The SysTick clock source is from HCLK, i.e the same as system core clock.
  *             User can use SystemCoreClockUpdate() to calculate CyclesPerUs automatically before using this function.
  */
__STATIC_INLINE void CLK_SysTickLongDelay(uint32_t us)
{
    uint32_t delay;

    /* It should <= 335544us for each delay loop */
    delay = 335544UL;

    do
    {
        if(us > delay)
        {
            us -= delay;
        }
        else
        {
            delay = us;
            us = 0UL;
        }

        SysTick->LOAD = delay * CyclesPerUs;
        SysTick->VAL  = (0x0UL);
        SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

        /* Waiting for down-count to zero */
        while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0UL);

        /* Disable SysTick counter */
        SysTick->CTRL = 0UL;

    }while(us > 0UL);

}



void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv, uint32_t u32ClkDivBy1En);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetPCLKFreq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetSysTickClockSrc(uint32_t u32ClkSrc);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);
void CLK_EnableSysTick(uint32_t u32ClkSrc, uint32_t u32Count);
void CLK_DisableSysTick(void);


/*@}*/ /* end of group NUC131_CLK_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC131_CLK_Driver */

/*@}*/ /* end of group NUC131_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__CLK_H__



/*** (C) COPYRIGHT 2014 Nuvoton Technology Corp. ***/
