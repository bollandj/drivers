
#ifndef MCP44XX_H_
#define MCP44XX_H_

#include <stdint.h>
#include <stddef.h>

/*
 * This driver should support the following devices:
 *
 *  - MCP4531/2: single, digital pot/rheostat, 7-bit, volatile memory
 *  - MCP4541/2: single, digital pot/rheostat, 7-bit, non-volatile memory
 *  - MCP4551/2: single, digital pot/rheostat, 8-bit, volatile memory
 *  - MCP4561/2: single, digital pot/rheostat, 8-bit, non-volatile memory
 * 
 *  - MCP4631/2: dual, digital pot/rheostat, 7-bit, volatile memory
 *  - MCP4641/2: dual, digital pot/rheostat, 7-bit, non-volatile memory
 *  - MCP4651/2: dual, digital pot/rheostat, 8-bit, volatile memory
 *  - MCP4661/2: dual, digital pot/rheostat, 8-bit, non-volatile memory
 * 
 *  - MCP4431/2: quad, digital pot/rheostat, 7-bit, volatile memory
 *  - MCP4441/2: quad, digital pot/rheostat, 7-bit, non-volatile memory
 *  - MCP4451/2: quad, digital pot/rheostat, 8-bit, volatile memory
 *  - MCP4461/2: quad, digital pot/rheostat, 8-bit, non-volatile memory
 */

/* I2C address (7-bit) */
#define MCP44XX_I2C_ADDR(a) (0x2C | (a))

/* Register definitions */

/* Address */
#define MCP44XX_MEM_ADDR_Pos        4
#define MCP44XX_MEM_ADDR_Msk        (0x0F << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR(value)     (MCP44XX_MEM_ADDR_Msk & ((value) << MCP44XX_MEM_ADDR_Pos))

#define MCP44XX_MEM_ADDR_VW0_Val    0   /**< \brief (MEM_ADDR) Volatile Wiper 0 */
#define MCP44XX_MEM_ADDR_VW1_Val    1   /**< \brief (MEM_ADDR) Volatile Wiper 1 */
#define MCP44XX_MEM_ADDR_NVW0_Val   2   /**< \brief (MEM_ADDR) NV Wiper 0 */
#define MCP44XX_MEM_ADDR_NVW1_Val   3   /**< \brief (MEM_ADDR) NV Wiper 1 */
#define MCP44XX_MEM_ADDR_TCON0_Val  4   /**< \brief (MEM_ADDR) Volatile TCON0 Register */
#define MCP44XX_MEM_ADDR_STATUS_Val 5   /**< \brief (MEM_ADDR) Status Register */
#define MCP44XX_MEM_ADDR_VW2_Val    6   /**< \brief (MEM_ADDR) Volatile Wiper 2 */
#define MCP44XX_MEM_ADDR_VW3_Val    7   /**< \brief (MEM_ADDR) Volatile Wiper 3 */
#define MCP44XX_MEM_ADDR_NVW2_Val   8   /**< \brief (MEM_ADDR) NV Wiper 2 */
#define MCP44XX_MEM_ADDR_NVW3_Val   9   /**< \brief (MEM_ADDR) NV Wiper 3 */
#define MCP44XX_MEM_ADDR_TCON1_Val  10  /**< \brief (MEM_ADDR) Volatile TCON1 Register */
#define MCP44XX_MEM_ADDR_VW0        (MCP44XX_MEM_ADDR_VW0_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_VW1        (MCP44XX_MEM_ADDR_VW1_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_NVW0       (MCP44XX_MEM_ADDR_NVW0_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_NVW1       (MCP44XX_MEM_ADDR_NVW1_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_TCON0       (MCP44XX_MEM_ADDR_TCON0_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_STATUS     (MCP44XX_MEM_ADDR_STATUS_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_VW2        (MCP44XX_MEM_ADDR_VW2_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_VW3        (MCP44XX_MEM_ADDR_VW3_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_NVW2       (MCP44XX_MEM_ADDR_NVW2_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_NVW3       (MCP44XX_MEM_ADDR_NVW3_Val << MCP44XX_MEM_ADDR_Pos)
#define MCP44XX_MEM_ADDR_TCON1       (MCP44XX_MEM_ADDR_TCON1_Val << MCP44XX_MEM_ADDR_Pos)

/* Command */
#define MCP44XX_COMMAND_Pos         2
#define MCP44XX_COMMAND_Msk         (0x03 << MCP44XX_COMMAND_Pos)
#define MCP44XX_COMMAND(value)      (MCP44XX_COMMAND_Msk & ((value) << MCP44XX_COMMAND_Pos))

#define MCP44XX_COMMAND_WRITE_Val   0   /**< \brief (COMMAND) Write Data */
#define MCP44XX_COMMAND_INC_Val     1   /**< \brief (COMMAND) Increment Wiper */
#define MCP44XX_COMMAND_DEC_Val     2   /**< \brief (COMMAND) Decrement Wiper */
#define MCP44XX_COMMAND_READ_Val    3   /**< \brief (COMMAND) Read Data */
#define MCP44XX_COMMAND_WRITE       (MCP44XX_COMMAND_WRITE_Val << MCP44XX_COMMAND_Pos)
#define MCP44XX_COMMAND_INC         (MCP44XX_COMMAND_INC_Val << MCP44XX_COMMAND_Pos)
#define MCP44XX_COMMAND_DEC         (MCP44XX_COMMAND_DEC_Val << MCP44XX_COMMAND_Pos)
#define MCP44XX_COMMAND_READ        (MCP44XX_COMMAND_READ_Val << MCP44XX_COMMAND_Pos)

typedef struct mcp44xx {
    void (*i2c_write)(uint8_t addr, const uint8_t *data, size_t len);
    uint8_t addr;
} mcp44xx_t;

void mcp44xx_init(mcp44xx_t *mcp44xx, uint8_t addr, void (*i2c_write)(uint8_t addr, const uint8_t *data, size_t len));
void mcp44xx_write(mcp44xx_t *mcp44xx, uint8_t value, uint8_t pot);
void mcp44xx_write_nv(mcp44xx_t *mcp44xx, uint8_t value, uint8_t pot);

#endif // MCP44XX_H_
