
#include "pms5003.h"

static bool _pms5003_checksum(pms5003_t *pms5003)
{
    uint16_t checksum = 0x0000;
    for (int i=0; i<30; i++)
        checksum += pms5003->buf[i];

    if (checksum == (pms5003->buf[30] << 8 | pms5003->buf[31]))
        return true;
    else    
        return false;
}

static void _pms5003_parse_data(pms5003_t *pms5003)
{
    pms5003->data.pm1_0 = pms5003->buf[4] << 8 | pms5003->buf[5];
    pms5003->data.pm2_5 = pms5003->buf[6] << 8 | pms5003->buf[7];
    pms5003->data.pm10 = pms5003->buf[8] << 8 | pms5003->buf[9];
    pms5003->data.n0_3 = pms5003->buf[16] << 8 | pms5003->buf[17];
    pms5003->data.n0_5 = pms5003->buf[18] << 8 | pms5003->buf[19];
    pms5003->data.n1_0 = pms5003->buf[20] << 8 | pms5003->buf[21];
    pms5003->data.n2_5 = pms5003->buf[22] << 8 | pms5003->buf[23];
    pms5003->data.n5_0 = pms5003->buf[24] << 8 | pms5003->buf[25];
    pms5003->data.n10 = pms5003->buf[26] << 8 | pms5003->buf[27];
}

void pms5003_init(pms5003_t *pms5003)
{
    pms5003->buf_p = 0;
    pms5003->data_ready = false;
}

void pms5003_process_byte(pms5003_t *pms5003, uint8_t data)
{
    pms5003->buf[pms5003->buf_p] = data;   

    if (pms5003->buf_p == 0)
    {
        if (pms5003->buf[0] == 0x42) 
            pms5003->buf_p++;
    }
    else if (pms5003->buf_p == 1)
    {
        if (pms5003->buf[1] == 0x4D) 
            pms5003->buf_p++;
        else
            pms5003->buf_p = 0;
    }
    else
    {
        pms5003->buf_p++;

        if (pms5003->buf_p == 32)
        {
            pms5003->data_valid = _pms5003_checksum(pms5003);
            _pms5003_parse_data(pms5003);
            pms5003->data_ready = true;
            pms5003->buf_p = 0; 
        }
    }
}