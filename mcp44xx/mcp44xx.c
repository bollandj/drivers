
#include "mcp44xx.h"

void mcp44xx_init(mcp44xx_t *mcp44xx, uint8_t addr, void (*i2c_write)(uint8_t addr, const uint8_t *data, size_t len))
{
	mcp44xx->i2c_write = i2c_write;
	mcp44xx->addr = addr;
}

void mcp44xx_write(mcp44xx_t *mcp44xx, uint8_t value, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP44XX_MEM_ADDR(MCP44XX_MEM_ADDR_VW0_Val + pot) | MCP44XX_COMMAND_WRITE,
		value
	};

	mcp44xx->i2c_write(mcp44xx->addr, data, 2);
}

void mcp44xx_write_nv(mcp44xx_t *mcp44xx, uint8_t value, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP44XX_MEM_ADDR(MCP44XX_MEM_ADDR_NVW0_Val + pot) | MCP44XX_COMMAND_WRITE,
		value
	};

	mcp44xx->i2c_write(mcp44xx->addr, data, 2);
}
