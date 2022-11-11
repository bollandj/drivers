
#ifndef CAT5171_H_
#define CAT5171_H_

#include <stdint.h>

/* 7-bit I2C address */
/* LSB can be 0 or 1 based on the state of the AD0 pin */
#define CAT5171_ADDR 0b00101100

/* Register definitions */
#define CAT5171_SD_Pos 5
#define CAT5171_SD (0x01 << CAT5171_SD_Pos)

#define CAT5171_RS_Pos 6
#define CAT5171_RS (0x01 << CAT5171_RS_Pos)

void cat5171_write(uint8_t pos, uint8_t dev);

#endif // CAT5171_H_
