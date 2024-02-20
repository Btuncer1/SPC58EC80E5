/*
 * h10B.h
 *
 *  Created on: 26 Ara 2023
 *      Author: bayra
 */

#ifndef INC_H10B_H_
#define INC_H10B_H_


#include "crc.h"
#include "stdint.h"
#include "stdio.h"


void manupilate_h10B(uint8_t * Data,uint8_t Throttle, uint16_t Brake,uint8_t Jerk);


#endif /* INC_H10B_H_ */
