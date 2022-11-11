
#include "mcp49xx.h"
#include "spi.h"

static uint8_t _mcp49xx_config=0x00;

void mcp49xx_config(uint8_t buf, uint8_t gain, uint8_t shutdown)
{
    _mcp49xx_config = MCP49XX_BUF(buf) | MCP49XX_GA(gain) | MCP49XX_SHDN(shutdown);

    uint8_t data[2] = 
	{
		_mcp49xx_config,
		0x00
	};

	spi_write(SERCOM0, data, 2);
}

void mcp49xx_write(uint16_t val, uint8_t dac)
{
	uint8_t data[2] = 
	{
		MCP49XX_AB(dac) | _mcp49xx_config | MCP49XX_D_UPPER(val >> 8),
		MCP49XX_D_LOWER(val)
	};

	spi_write(SERCOM0, data, 2);
}