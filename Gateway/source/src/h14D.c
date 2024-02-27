/*
 * h14D.c
 *
 *  Created on: 21 ?ub 2024
 *      Author: bayram
 */

#include "h14D.h"

void manupilate_h14D(uint8_t * data,uint8_t hold,uint8_t relase, uint8_t main_switch)
{
	if(main_switch){
		data[7] |= 0b00110000;
	}
	else{
		data[7] &= 0b11001111;
	}
	if(hold){
		data[9] |= 0b00100000;
	}
	else{
		data[9] &= 0b11011111;
	}
	if(relase){
		data[9] |= 0b10000000;
	}
	else{
		data[9] &= 0b01111111;
	}

	data[0] = Crc_CalculateCRC8H2F(data, 32,0x14D);
}
