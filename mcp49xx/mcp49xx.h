
#ifndef MCP49XX_H_
#define MCP4922_H_

#include <stdint.h>

/* Register definitions */

/* ~A/B - DAC A or DAC B Select bit */
#define MCP49XX_AB_Pos              7
#define MCP49XX_AB_Msk              (0x01 << MCP49XX_AB_Pos)
#define MCP49XX_AB(value)           (MCP49XX_AB_Msk & ((value) << MCP49XX_AB_Pos))

#define MCP49XX_AB_A_Val            0   /**< \brief (AB) Write to DAC A */
#define MCP49XX_AB_B_Val            1   /**< \brief (AB) Write to DAC B */
#define MCP49XX_AB_A                (MCP49XX_AB_A_Val   << MCP49XX_AB_Pos)
#define MCP49XX_AB_B                (MCP49XX_AB_B_Val   << MCP49XX_AB_Pos)

/* BUF - Vref Input Buffer Control bit */
#define MCP49XX_BUF_Pos             6
#define MCP49XX_BUF_Msk             (0x01 << MCP49XX_BUF_Pos)
#define MCP49XX_BUF(value)          (MCP49XX_BUF_Msk & ((value) << MCP49XX_BUF_Pos))

#define MCP49XX_BUF_UNBUF_Val       0   /**< \brief (BUF) Unbuffered */
#define MCP49XX_BUF_BUF_Val         1   /**< \brief (BUF) Buffered */
#define MCP49XX_BUF_UNBUF           (MCP49XX_BUF_UNBUF_Val << MCP49XX_BUF_Pos)
#define MCP49XX_BUF_BUF             (MCP49XX_BUF_BUF_Val << MCP49XX_BUF_Pos)

/* ~GA - Output Gain Select bit */
#define MCP49XX_GA_Pos              5
#define MCP49XX_GA_Msk              (0x01 << MCP49XX_GA_Pos)
#define MCP49XX_GA(value)           (MCP49XX_GA_Msk & ((value) << MCP49XX_GA_Pos))

#define MCP49XX_GA_2X_Val           0   /**< \brief (GA) 2x */
#define MCP49XX_GA_1X_Val           1   /**< \brief (GA) 1x */
#define MCP49XX_GA_2X               (MCP49XX_GA_2X_Val << MCP49XX_GA_Pos)
#define MCP49XX_GA_1X               (MCP49XX_GA_1X_Val << MCP49XX_GA_Pos)

/* ~SHDN - Output Power Down Control bit */
#define MCP49XX_SHDN_Pos            4
#define MCP49XX_SHDN_Msk            (0x01 << MCP49XX_SHDN_Pos)
#define MCP49XX_SHDN(value)         (MCP49XX_SHDN_Msk & ((value) << MCP49XX_SHDN_Pos))

#define MCP49XX_SHDN_DISABLE_Val    0   /**< \brief (SHDN) Output buffer disabled, output is high Z */
#define MCP49XX_SHDN_ENABLE_Val     1   /**< \brief (SHDN) Output buffer enabled */
#define MCP49XX_SHDN_DISABLE        (MCP49XX_SHDN_DISABLE_Val << MCP49XX_SHDN_Pos)
#define MCP49XX_SHDN_ENABLE         (MCP49XX_SHDN_ENABLE_Val << MCP49XX_SHDN_Pos)

/* D - DAC Data bits (upper) */
#define MCP49XX_D_UPPER_Pos         0
#define MCP49XX_D_UPPER_Msk         (0x0F << MCP49XX_D_UPPER_Pos)
#define MCP49XX_D_UPPER(value)      (MCP49XX_D_UPPER_Msk & ((value) << MCP49XX_D_UPPER_Pos))

/* D - DAC Data bits (lower) */
#define MCP49XX_D_LOWER_Pos         0
#define MCP49XX_D_LOWER_Msk         (0xFF << MCP49XX_D_LOWER_Pos)
#define MCP49XX_D_LOWER(value)      (MCP49XX_D_LOWER_Msk & ((value) << MCP49XX_D_LOWER_Pos))

void mcp49xx_init(uint8_t buf, uint8_t gain);
void mcp49xx_write(uint16_t val, uint8_t dac);
void mcp49xx_shutdown(uint8_t shutdown);

#endif // MCP49XX_H_
