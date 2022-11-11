
#include "mcp42xx.h"
#include "spi.h"

void mcp42xx_write(uint8_t pos, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP42XX_MEM_ADDR(MCP42XX_MEM_ADDR_VW0_Val + pot) | MCP42XX_COMMAND_WRITE,
		pos
	};

	spi_write(SERCOM0, data, 2);
}

void mcp42xx_write_nv(uint8_t pos, uint8_t pot) 
{
	uint8_t data[2] = 
	{
		MCP42XX_MEM_ADDR(MCP42XX_MEM_ADDR_NVW0_Val + pot) | MCP42XX_COMMAND_WRITE,
		pos
	};

	spi_write(SERCOM0, data, 2);
}
