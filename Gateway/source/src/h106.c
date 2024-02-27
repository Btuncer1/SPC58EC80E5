/*
 * h106.c
 *
 *  Created on: 21 ?ub 2024
 *      Author: bayra
 */

#include"h106.h"

void manupilate_h106(uint8_t * data,uint8_t fakebrake)
{
	if(fakebrake)
	{
		data[3] |= 0x04;
	}

	Crc_CalculateCRC8H2F(data, 8,0x106);

}
