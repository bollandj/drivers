
#ifndef PMS5003_H_
#define PMS5003_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct _pms5003_data_t 
{
		uint16_t pm1_0; // PM1.0 concentration (ug/m^3)
		uint16_t pm2_5; // PM2.5 concentration (ug/m^3)
		uint16_t pm10;  // PM10 concentration (ug/m^3)
		uint16_t n0_3;  // Number of particles >0.3um per 0.1L
		uint16_t n0_5;  // Number of particles >0.5um per 0.1L
		uint16_t n1_0;  // Number of particles >1.0um per 0.1L
		uint16_t n2_5;  // Number of particles >2.5um per 0.1L
		uint16_t n5_0;  // Number of particles >5.0um per 0.1L
		uint16_t n10;   // Number of particles >10um per 0.1L
} pms5003_data_t;

typedef struct _pms5003_t
{
	uint8_t buf[32];
	unsigned int buf_p;		
	bool data_ready;
	bool data_valid;

	pms5003_data_t data;
} pms5003_t;

void pms5003_init(pms5003_t *pms5003);
void pms5003_process_byte(pms5003_t *pms5003, uint8_t data);

inline bool pms5003_is_data_ready(pms5003_t *pms5003) { return pms5003->data_ready; }
inline bool pms5003_is_data_valid(pms5003_t *pms5003) { return pms5003->data_valid; }

inline pms5003_data_t pms5003_get_data(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data; }

inline uint16_t pms5003_get_pm1_0(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.pm1_0; }
inline uint16_t pms5003_get_pm2_5(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.pm2_5; }
inline uint16_t pms5003_get_pm10(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.pm10; }

inline uint16_t pms5003_get_n0_3(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.n0_3; }
inline uint16_t pms5003_get_n0_5(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.n0_5; }
inline uint16_t pms5003_get_n1_0(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.n1_0; }
inline uint16_t pms5003_get_n2_5(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.n2_5; }
inline uint16_t pms5003_get_n5_0(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.n5_0; }
inline uint16_t pms5003_get_n10(pms5003_t *pms5003) { pms5003->data_ready = false; return pms5003->data.n10; }

#endif /* PMS5003_H_ */
