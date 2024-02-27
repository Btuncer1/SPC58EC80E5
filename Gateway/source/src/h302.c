/*
 * h302.c
 *
 *  Created on: 27 ?ub 2024
 *      Author: bayra
 */

/*
 * 0x302 lane assist
 * 0x303 park assist
 *
 * they use same msg struct
 */

#include "h302.h"

void Steering_assist(uint8_t *data, float steeringangle,uint8_t steertorque,uint8_t enable)
{
	if(enable)
	{
		uint8_t torque = 0;
		torque = steertorque > 250 ? 250 : steertorque;

		float steerangle = 0;
		steerangle = steeringangle > 475.0f ? 475.0f : steeringangle;
		steerangle = steeringangle <-475.0f ? -475.0f : steeringangle;

		uint16_t setsteer_u16 = 0;
		setsteer_u16 = (uint16_t)(fabs(steerangle) / 0.0184);

		data[1] = 0x40;
		data[2] = torque;
		data[3] = 0;
		data[4] = (setsteer_u16 & 0xFF00) >> 8;
		data[3] = setsteer_u16 & 0x00FF;
		data[8] = 0x04;
		if(steerangle > 0)
		{
			data[4] |= 0x80;
		}
		else
		{
			data[4] &= 0x7F;
		}
	}
	else
	{
		for(int i = 0; i<24; i++)
		{
			data[i] = 0;
		}
		data[1] = 0x20;
	}
}
