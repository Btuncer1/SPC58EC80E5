/*
 * h10B.c
 *
 *  Created on: 26 Ara 2023
 *      Author: bayra
 */
#include"h10B.h"

void manupilate_h10B(uint8_t * Data,uint8_t Throttle, uint16_t Brake,uint8_t Jerk)
{
	if(Throttle >= 1)
	{
		uint8_t gas[2]={0};

		gas[0] = Data[1] & 0x0F;
		gas[0] |= (Throttle & 0x0F) << 4 ;
		gas[1] = (Throttle & 0xF0) >> 4;

		Data[1] = gas[0];
		Data[2] = (Data[2] & 0xF0) | gas[1];
	}
	Data[9] = (Brake & 0x0000F) << 4;
	Data[10] = (Brake & 0x0FF0) >> 4;
	if (Brake > 5) {
		Data[11] = 0x53;
	} else {
		Data[11] = 0x13;
	}
	Data[13] = 0x18;
	Data[31] = Jerk;
	Data[0] = Crc_CalculateCRC8H2F(Data, 32,0x10B);
}
