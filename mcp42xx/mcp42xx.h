
#ifndef MCP42XX_H_
#define MCP42XX_H_

#include <stdint.h>
#include <stddef.h>

/* Register definitions */

/* Address */
#define MCP42XX_MEM_ADDR_Pos        4
#define MCP42XX_MEM_ADDR_Msk        (0x0F << MCP42XX_MEM_ADDR_Pos)
#define MCP42XX_MEM_ADDR(value)     (MCP42XX_MEM_ADDR_Msk & ((value) << MCP42XX_MEM_ADDR_Pos))

#define MCP42XX_MEM_ADDR_VW0_Val    0   /**< \brief (MEM_ADDR) Volatile Wiper 0 */
#define MCP42XX_MEM_ADDR_VW1_Val    1   /**< \brief (MEM_ADDR) Volatile Wiper 1 */
#define MCP42XX_MEM_ADDR_NVW0_Val   2   /**< \brief (MEM_ADDR) NV Wiper 0 */
#define MCP42XX_MEM_ADDR_NVW1_Val   3   /**< \brief (MEM_ADDR) NV Wiper 1 */
#define MCP42XX_MEM_ADDR_TCON_Val   4   /**< \brief (MEM_ADDR) Volatile TCON Register */
#define MCP42XX_MEM_ADDR_STATUS_Val 5   /**< \brief (MEM_ADDR) Status Register */
#define MCP42XX_MEM_ADDR_VW0        (MCP42XX_MEM_ADDR_VW0_Val << MCP42XX_MEM_ADDR_Pos)
#define MCP42XX_MEM_ADDR_VW1        (MCP42XX_MEM_ADDR_VW1_Val << MCP42XX_MEM_ADDR_Pos)
#define MCP42XX_MEM_ADDR_NVW0       (MCP42XX_MEM_ADDR_NVW0_Val << MCP42XX_MEM_ADDR_Pos)
#define MCP42XX_MEM_ADDR_NVW1       (MCP42XX_MEM_ADDR_NVW1_Val << MCP42XX_MEM_ADDR_Pos)
#define MCP42XX_MEM_ADDR_TCON       (MCP42XX_MEM_ADDR_TCON_Val << MCP42XX_MEM_ADDR_Pos)
#define MCP42XX_MEM_ADDR_STATUS     (MCP42XX_MEM_ADDR_STATUS_Val << MCP42XX_MEM_ADDR_Pos)

/* Command */
#define MCP42XX_COMMAND_Pos         2
#define MCP42XX_COMMAND_Msk         (0x03 << MCP42XX_COMMAND_Pos)
#define MCP42XX_COMMAND(value)      (MCP42XX_COMMAND_Msk & ((value) << MCP42XX_COMMAND_Pos))

#define MCP42XX_COMMAND_WRITE_Val   0   /**< \brief (COMMAND) Write Data */
#define MCP42XX_COMMAND_INC_Val     1   /**< \brief (COMMAND) Increment Wiper */
#define MCP42XX_COMMAND_DEC_Val     2   /**< \brief (COMMAND) Decrement Wiper */
#define MCP42XX_COMMAND_READ_Val    3   /**< \brief (COMMAND) Read Data */
#define MCP42XX_COMMAND_WRITE       (MCP42XX_COMMAND_WRITE_Val << MCP42XX_COMMAND_Pos)
#define MCP42XX_COMMAND_INC         (MCP42XX_COMMAND_INC_Val << MCP42XX_COMMAND_Pos)
#define MCP42XX_COMMAND_DEC         (MCP42XX_COMMAND_DEC_Val << MCP42XX_COMMAND_Pos)
#define MCP42XX_COMMAND_READ        (MCP42XX_COMMAND_READ_Val << MCP42XX_COMMAND_Pos)

typedef struct mcp42xx {
    void (*spi_write)(const uint8_t *data, size_t len);
} mcp42xx_t;

void mcp42xx_init(mcp42xx_t *mcp42xx, void (*spi_write)(const uint8_t *data, size_t len));
void mcp42xx_write(mcp42xx_t *mcp42xx, uint8_t value, uint8_t dev);
void mcp42xx_write_nv(mcp42xx_t *mcp42xx, uint8_t value, uint8_t pot);

#endif // MCP42XX_H_
