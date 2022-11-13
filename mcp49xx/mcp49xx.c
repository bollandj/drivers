
#include "mcp49xx.h"

void mcp49xx_init(mcp49xx_t *mcp49xx, void (*spi_write)(uint8_t *data, size_t len), mcp49xx_buf_t buf, mcp49xx_ga_t gain)
{
    mcp49xx->config = MCP49XX_BUF(buf) | MCP49XX_GA(gain) | MCP49XX_SHDN(MCP49XX_SHDN_ENABLE_Val);

    uint8_t data[2] = 
	{
		mcp49xx->config,
		0x00
	};

	mcp49xx->spi_write(data, 2);
}

void mcp49xx_write(mcp49xx_t *mcp49xx, uint16_t value, mcp49xx_ab_t channel)
{
	uint8_t data[2] = 
	{
		MCP49XX_AB(channel) | mcp49xx->config | MCP49XX_D_UPPER(value >> 8),
		MCP49XX_D_LOWER(value)
	};

	mcp49xx->spi_write(data, 2);
}