/*
 * CANparse.h
 *
 *  Created on: 23 Oca 2024
 *      Author: bayra
 */

#ifndef INC_CANPARSE_H_
#define INC_CANPARSE_H_

#include "stdint.h"
float GetSteeringWheelAngle(const uint8_t* data);


int16_t GetSteeringWheelRate(const uint8_t* data);


int16_t GetTargetMotorTorqueFiltered(const uint8_t* data);
int16_t GetTargetMotorTorqueTotal(const uint8_t* data);
int16_t GetTargetMotorTorqueRaw(const uint8_t* data);


uint16_t GetMotorRPM(const uint8_t* data);


float Get_WheelSpeed_FR(const uint8_t* data); // km/h

float Get_WheelSpeed_FL(const uint8_t* data); // km/h

float Get_WheelSpeed_BR(const uint8_t* data); // km/h

float Get_WheelSpeed_BL(const uint8_t* data); // km/h

float GetLateralACC(const uint8_t* data);// g


float GetLongitudinalACC(const uint8_t* data);// m/s^2



float GetBrakePressure(const uint8_t* data);// bar


uint8_t GetDriverBrake(const uint8_t* data);


#endif /* INC_CANPARSE_H_ */
