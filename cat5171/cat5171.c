
#include "cat5171.h"

void cat5171_write(uint8_t pos, uint8_t dev) 
{
	uint8_t data[2] = {
		0x00,
		pos
	};

	i2cm_write(CAT5171_ADDR | dev, data, 2);
}
