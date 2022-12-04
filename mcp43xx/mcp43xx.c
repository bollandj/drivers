
#include "mcp43xx.h"

void mcp43xx_init(mcp43xx_t *mcp43xx, void (*spi_write)(const uint8_t *data, size_t len))
{
	mcp43xx->spi_write = spi_write;
}

void mcp43xx_write(mcp43xx_t *mcp43xx, uint8_t value, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP43XX_MEM_ADDR(MCP43XX_MEM_ADDR_VW0_Val + pot) | MCP43XX_COMMAND_WRITE,
		value
	};

	mcp43xx->spi_write(data, 2);
}

void mcp43xx_write_nv(mcp43xx_t *mcp43xx, uint8_t value, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP43XX_MEM_ADDR(MCP43XX_MEM_ADDR_NVW0_Val + pot) | MCP43XX_COMMAND_WRITE,
		value
	};

	mcp43xx->spi_write(data, 2);
}
