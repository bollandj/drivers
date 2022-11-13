
#include "mcp42xx.h"

void mcp42xx_write(mcp42xx_t *mcp42xx, uint8_t value, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP42XX_MEM_ADDR(MCP42XX_MEM_ADDR_VW0_Val + pot) | MCP42XX_COMMAND_WRITE,
		value
	};

	mcp42xx->spi_write(data, 2);
}

void mcp42xx_write_nv(mcp42xx_t *mcp42xx, uint8_t value, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP42XX_MEM_ADDR(MCP42XX_MEM_ADDR_NVW0_Val + pot) | MCP42XX_COMMAND_WRITE,
		value
	};

	mcp42xx->spi_write(data, 2);
}
