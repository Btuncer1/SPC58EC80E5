/*
 * CANparse.h
 *
 *  Created on: 23 Oca 2024
 *      Author: bayra
 */

#ifndef INC_CANPARSE_H_
#define INC_CANPARSE_H_

#include "stdint.h"
/*
 * LWI 0x86 ID
 */
float GetSteeringWheelAngle(const uint8_t* data);
int16_t GetSteeringWheelRate(const uint8_t* data);

/*
 * Motor_11 0xA7
 */
int16_t GetTargetMotorTorqueFiltered(const uint8_t* data);
int16_t GetTargetMotorTorqueTotal(const uint8_t* data);
int16_t GetTargetMotorTorqueRaw(const uint8_t* data);

/*
 * Motor_12 0xA8
 */
uint16_t GetMotorRPM(const uint8_t* data);

/*
 * 0xAD
 */
uint8_t GetTargetGearLevel(const uint8_t* data);


/*
 * ESP_19 0xB2
 */
float Get_WheelSpeed_FR(const uint8_t* data); // km/h
float Get_WheelSpeed_FL(const uint8_t* data); // km/h
float Get_WheelSpeed_BR(const uint8_t* data); // km/h
float Get_WheelSpeed_BL(const uint8_t* data); // km/h

/*
 * ESP_02 0x101
 */
float GetLateralACC(const uint8_t* data);// g
float GetLongitudinalACC(const uint8_t* data);// m/s^2


/*
 * ESP_05 0x106
 */
float GetBrakePressure(const uint8_t* data);// bar
uint8_t GetDriverBrake(const uint8_t* data);
/*
 * EPB_01 0x104
 */
uint8_t GetEPBStatus(const uint8_t* data);
/*
 * Motor_20 0x121
 */
float GetThrottlePedalRawValue(const uint8_t* data);
/*
 * 0x176
 */
uint8_t GetBrakePedalPos(const uint8_t* data);
/*
 * 0x394
 */
uint8_t GetGear(const uint8_t* data);//D N R P
uint8_t GetGearLevel(const uint8_t* data);//Not works all the time
/*
 * 0x3BE Motor_14
 */
uint8_t GetKL75status(const uint8_t* data);
/*
 * 0x65F Motor 16
 */
uint16_t GetVehicleMassEst(const uint8_t* data);//kg
float GetPitchVal(const uint8_t* data);
/*
 * 0x6B7 Kombi_02
 */
uint8_t GetFuelLevel(const uint8_t* data);//liter


#endif /* INC_CANPARSE_H_ */
