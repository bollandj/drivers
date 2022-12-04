
#ifndef MCP43XX_H_
#define MCP43XX_H_

#include <stdint.h>
#include <stddef.h>

/*
 * This driver should support the following devices:
 *
 *  - MCP4131/2: single, digital pot/rheostat, 7-bit, volatile memory
 *  - MCP4141/2: single, digital pot/rheostat, 7-bit, non-volatile memory
 *  - MCP4151/2: single, digital pot/rheostat, 8-bit, volatile memory
 *  - MCP4161/2: single, digital pot/rheostat, 8-bit, non-volatile memory
 * 
 *  - MCP4231/2: dual, digital pot/rheostat, 7-bit, volatile memory
 *  - MCP4241/2: dual, digital pot/rheostat, 7-bit, non-volatile memory
 *  - MCP4251/2: dual, digital pot/rheostat, 8-bit, volatile memory
 *  - MCP4261/2: dual, digital pot/rheostat, 8-bit, non-volatile memory
 * 
 *  - MCP4331/2: quad, digital pot/rheostat, 7-bit, volatile memory
 *  - MCP4341/2: quad, digital pot/rheostat, 7-bit, non-volatile memory
 *  - MCP4351/2: quad, digital pot/rheostat, 8-bit, volatile memory
 *  - MCP4361/2: quad, digital pot/rheostat, 8-bit, non-volatile memory
 */

/* Register definitions */

/* Address */
#define MCP43XX_MEM_ADDR_Pos        4
#define MCP43XX_MEM_ADDR_Msk        (0x0F << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR(value)     (MCP43XX_MEM_ADDR_Msk & ((value) << MCP43XX_MEM_ADDR_Pos))

#define MCP43XX_MEM_ADDR_VW0_Val    0   /**< \brief (MEM_ADDR) Volatile Wiper 0 */
#define MCP43XX_MEM_ADDR_VW1_Val    1   /**< \brief (MEM_ADDR) Volatile Wiper 1 */
#define MCP43XX_MEM_ADDR_NVW0_Val   2   /**< \brief (MEM_ADDR) NV Wiper 0 */
#define MCP43XX_MEM_ADDR_NVW1_Val   3   /**< \brief (MEM_ADDR) NV Wiper 1 */
#define MCP43XX_MEM_ADDR_TCON0_Val  4   /**< \brief (MEM_ADDR) Volatile TCON0 Register */
#define MCP43XX_MEM_ADDR_STATUS_Val 5   /**< \brief (MEM_ADDR) Status Register */
#define MCP43XX_MEM_ADDR_VW2_Val    6   /**< \brief (MEM_ADDR) Volatile Wiper 2 */
#define MCP43XX_MEM_ADDR_VW3_Val    7   /**< \brief (MEM_ADDR) Volatile Wiper 3 */
#define MCP43XX_MEM_ADDR_NVW2_Val   8   /**< \brief (MEM_ADDR) NV Wiper 2 */
#define MCP43XX_MEM_ADDR_NVW3_Val   9   /**< \brief (MEM_ADDR) NV Wiper 3 */
#define MCP43XX_MEM_ADDR_TCON1_Val  10  /**< \brief (MEM_ADDR) Volatile TCON1 Register */
#define MCP43XX_MEM_ADDR_VW0        (MCP43XX_MEM_ADDR_VW0_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_VW1        (MCP43XX_MEM_ADDR_VW1_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_NVW0       (MCP43XX_MEM_ADDR_NVW0_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_NVW1       (MCP43XX_MEM_ADDR_NVW1_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_TCON0       (MCP43XX_MEM_ADDR_TCON0_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_STATUS     (MCP43XX_MEM_ADDR_STATUS_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_VW2        (MCP43XX_MEM_ADDR_VW2_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_VW3        (MCP43XX_MEM_ADDR_VW3_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_NVW2       (MCP43XX_MEM_ADDR_NVW2_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_NVW3       (MCP43XX_MEM_ADDR_NVW3_Val << MCP43XX_MEM_ADDR_Pos)
#define MCP43XX_MEM_ADDR_TCON1       (MCP43XX_MEM_ADDR_TCON1_Val << MCP43XX_MEM_ADDR_Pos)

/* Command */
#define MCP43XX_COMMAND_Pos         2
#define MCP43XX_COMMAND_Msk         (0x03 << MCP43XX_COMMAND_Pos)
#define MCP43XX_COMMAND(value)      (MCP43XX_COMMAND_Msk & ((value) << MCP43XX_COMMAND_Pos))

#define MCP43XX_COMMAND_WRITE_Val   0   /**< \brief (COMMAND) Write Data */
#define MCP43XX_COMMAND_INC_Val     1   /**< \brief (COMMAND) Increment Wiper */
#define MCP43XX_COMMAND_DEC_Val     2   /**< \brief (COMMAND) Decrement Wiper */
#define MCP43XX_COMMAND_READ_Val    3   /**< \brief (COMMAND) Read Data */
#define MCP43XX_COMMAND_WRITE       (MCP43XX_COMMAND_WRITE_Val << MCP43XX_COMMAND_Pos)
#define MCP43XX_COMMAND_INC         (MCP43XX_COMMAND_INC_Val << MCP43XX_COMMAND_Pos)
#define MCP43XX_COMMAND_DEC         (MCP43XX_COMMAND_DEC_Val << MCP43XX_COMMAND_Pos)
#define MCP43XX_COMMAND_READ        (MCP43XX_COMMAND_READ_Val << MCP43XX_COMMAND_Pos)

typedef struct mcp43xx {
    void (*spi_write)(const uint8_t *data, size_t len);
} mcp43xx_t;

void mcp43xx_init(mcp43xx_t *mcp43xx, void (*spi_write)(const uint8_t *data, size_t len));
void mcp43xx_write(mcp43xx_t *mcp43xx, uint8_t value, uint8_t pot);
void mcp43xx_write_nv(mcp43xx_t *mcp43xx, uint8_t value, uint8_t pot);

#endif // MCP43XX_H_
