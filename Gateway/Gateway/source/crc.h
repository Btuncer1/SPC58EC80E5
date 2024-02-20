/*
 * crc.h
 *
 *  Created on: 21 Ara 2023
 *      Author: bayra
 */

#ifndef CRC_H_
#define CRC_H_

uint8_t Crc_CalculateCRC8H2F(const uint8_t *Crc_DataPtr, uint32_t Crc_Length,
		uint32_t adress);

void converto1byteorder(uint8_t * bytein4, uint8_t *byteout1);
void converto4byteorder(uint8_t * bytein1, uint8_t *byteout4);

#endif /* CRC_H_ */
