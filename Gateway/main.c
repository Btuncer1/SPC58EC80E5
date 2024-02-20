/****************************************************************************
*
* Copyright © 2015-2021 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/* Inclusion of the main header files of all the imported components in the
   order specified in the application wizard. The file is generated
   automatically.*/
#include "components.h"
#include "can_lld_cfg.h"
#include "can_lld.h"
#include "crc.h"
#include "FreeRTOS.h"
#include "task.h"
#include "math.h"
#include "CANparse.h"
/*
 * Application entry point.
 *
 */
struct {
	uint8_t Enable;
	uint8_t Throttle_Pedal_Pos;
	uint16_t Brake_force;
	uint8_t Brake_jerk;

}h10Bst = {0,0,0,125};

struct{
	uint8_t Enable;
	uint8_t Main_switch;
	uint8_t Hold;
	uint8_t Relase;
}h14Dst = {0,1,0,0};

struct{
	uint8_t Enable;
	uint8_t SteeringTorque;
	float SteeringAngle;
}h303st = {0,0,0};

void can_start(void) {
  /* Start CAN */
  can_lld_start(&CAND2, &can_config_can1);
  can_lld_start(&CAND7, &can_config_can4);
}
CANTxFrame tx;
CANRxFrame rx;
uint32_t rtr;
uint32_t core0cnt=0;
uint32_t rtoscnt=0;
portTASK_FUNCTION( vTaskh303, pvParameters )
{
  ( void ) pvParameters;
  TickType_t xLastWakeTime = xTaskGetTickCount();
  for ( ;; ) {
	  CANTxFrame h303tx;
	  uint8_t h303buffer[64] = {0};
	  static uint8_t lastEnable = 0;

	  h303tx.LENGTH = 24;
	  h303tx.ID = 0x303;
	  h303tx.OPERATION = 1;
	  h303tx.TYPE  = 0;
	  if(h303st.Enable)
	  {
		  h303buffer[1] = 0x40;
		  h303buffer[2] = h303st.SteeringTorque;
		  uint16_t Setsteeringangle = fabs(h303st.SteeringAngle) / 0.0184f ;
		  h303buffer[3] = (uint8_t)(Setsteeringangle & 0x00FF);
		  h303buffer[4] = (uint8_t)((Setsteeringangle & 0xFF00) >> 8);

		  if(h303st.SteeringAngle > 0)
		  {
			  h303buffer[4] |= 0b10000000;
		  }
		  else
		  {
			  h303buffer[4] &= 0b01111111;
		  }
		  h303buffer[8] = 4;
		  converto4byteorder(h303buffer, h303tx.data8);
		  can_lld_transmit(&CAND7, CAN_DEDICATED_TXBUFFER, &h303tx);
	  }

	  if(lastEnable == 1 && h303st.Enable == 0)
	  {
		  h303buffer[1] = 0x20;
		  converto4byteorder(h303buffer, h303tx.data8);
		  can_lld_transmit(&CAND7, CAN_DEDICATED_TXBUFFER, &h303tx);
	  }

	  lastEnable = h303st.Enable;
	rtoscnt++;
    vTaskDelayUntil( &xLastWakeTime, 20 );

  }
}
int main(void) {

  /* Initialization of all the imported components in the order specified in
     the application wizard. The function is generated automatically.*/
  componentsInit();

  can_lld_init();
  can_start();
  /* Uncomment the below routine to Enable Interrupts. */
   irqIsrEnable();
   h10Bst.Brake_jerk = 125;
   h10Bst.Brake_force = 0;
   h10Bst.Enable = 0;
   h10Bst.Throttle_Pedal_Pos = 0;

   xTaskCreate( vTaskh303,
                (const char * const)"task #1",
                configMINIMAL_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 1,
                NULL );

   /* Start the FreeRTOS scheduler */
   vTaskStartScheduler();
  //can_start();
  /* Application main loop.*/
  for ( ; ; ) {
	  tx.DLC=8;
	  tx.ID=123;
	  static uint32_t cnt = 0;
	  tx.data32[0] = cnt++;
	  tx.OPERATION=CAN_OP_CANFD;

	  //rtr=can_lld_transmit(&CAND2, CAN_DEDICATED_TXBUFFER, &tx);
	  //rtr = can_lld_transmit(&CAND7, CAN_DEDICATED_TXBUFFER, &tx);
	 // osalThreadDelayMilliseconds(500);
	 // can_lld_receive(&CAND2, CAN_ANY_RXBUFFER, &rx);

  }
}


CANTxFrame  tx10B;
CANTxFrame  tx14D;
CANRxFrame  rx10B;

can1_Can1new(uint32_t msgbuf, CANRxFrame crfp){

		static int cnt = 0;
		cnt++;
		CANTxFrame  tx2;

		if(crfp.ID == 0x10B && h10Bst.Enable)
		{
			tx10B.DLC = crfp.DLC;
			tx10B.ID = crfp.ID;
			tx10B.LENGTH = crfp.LENGTH;
			tx10B.OPERATION = crfp.OPERATION;
			tx10B.TYPE = crfp.TYPE;
			uint8_t h10Bbuffer[64] = {0};
			converto1byteorder(crfp.data8, h10Bbuffer);

			if(h10Bst.Throttle_Pedal_Pos >= 1)
			{
				uint8_t gas[2]={0};

				gas[0] = h10Bbuffer[1] & 0x0F;
				gas[0] |= (h10Bst.Throttle_Pedal_Pos & 0x0F) << 4 ;
				gas[1] = (h10Bst.Throttle_Pedal_Pos & 0xF0) >> 4;

				h10Bbuffer[1] = gas[0];
				h10Bbuffer[2] = (h10Bbuffer[2] & 0xF0) | gas[1];
			}
			h10Bbuffer[9] = (h10Bst.Brake_force & 0x0000F) << 4;
			h10Bbuffer[10] = (h10Bst.Brake_force & 0x0FF0) >> 4;
			if (h10Bst.Brake_force > 5) {
				h10Bbuffer[11] = 0x53;
			} else {
				h10Bbuffer[11] = 0x13;
			}
			h10Bbuffer[13] = 0x18;
			h10Bbuffer[31] = h10Bst.Brake_jerk;
			h10Bbuffer[0] = Crc_CalculateCRC8H2F(h10Bbuffer, 32,0x10B);
			converto4byteorder(h10Bbuffer, tx10B.data8);
			can_lld_transmit(&CAND7, CAN_DEDICATED_TXBUFFER, &tx10B);
		}
		else if(crfp.ID == 0x14D && h14Dst.Enable)
		{
			tx14D.DLC = crfp.DLC;
			tx14D.ID = crfp.ID;
			tx14D.LENGTH = crfp.LENGTH;
			tx14D.OPERATION = crfp.OPERATION;
			tx14D.TYPE = crfp.TYPE;

			uint8_t h14Dbuffer[64] = {0};
			converto1byteorder(crfp.data8, h14Dbuffer);
			if(h14Dst.Main_switch){
				h14Dbuffer[7] |= 0b00110000;
			}
			else{
				h14Dbuffer[7] &= 0b11001111;
			}
			if(h14Dst.Hold){
				h14Dbuffer[9] |= 0b00100000;
			}
			else{
				h14Dbuffer[9] &= 0b11011111;
			}
			if(h14Dst.Relase){
				h14Dbuffer[9] |= 0b10000000;
			}
			else{
				h14Dbuffer[9] &= 0b01111111;
			}

			h14Dbuffer[0] = Crc_CalculateCRC8H2F(h14Dbuffer, 32,0x14D);
			converto4byteorder(h14Dbuffer, tx14D.data8);
			can_lld_transmit(&CAND7, CAN_DEDICATED_TXBUFFER, &tx14D);

		}
		else if(crfp.ID == 0x303 && h303st.Enable){}
		else{

			tx2.DLC = crfp.DLC;
			tx2.ID = crfp.ID;
			tx2.LENGTH = crfp.LENGTH;
			tx2.OPERATION = crfp.OPERATION;
			tx2.TYPE = crfp.TYPE;
		for(int i = 0; i<16;i++)
		{
			tx2.data32[i] = crfp.data32[i];
		}
			can_lld_transmit(&CAND7, CAN_DEDICATED_TXBUFFER, &tx2);
		}





}
float steeringangle;
int16_t steeringrate;
int16_t motortork;
uint16_t RPM;
can4_Can4rx_new(uint32_t msgbuf, CANRxFrame crfp){
	static int cnt = 0;
	cnt++;
	CANTxFrame  tx2;
	tx2.DLC = crfp.DLC;
	tx2.ID = crfp.ID;
	tx2.LENGTH = crfp.LENGTH;
	tx2.OPERATION = crfp.OPERATION;
	tx2.TYPE = crfp.TYPE;
	for(int i = 0; i<16;i++)
	{
		tx2.data32[i] = crfp.data32[i];
	}
	uint8_t buffer[64];
	converto1byteorder(crfp.data8, buffer);

	switch(crfp.ID)
	{

	case 0x86:
		steeringangle = GetSteeringWheelAngle(buffer);
		steeringrate = GetSteeringWheelRate(buffer);
		break;
	case 0xA7:
		motortork = GetMotorTorque(buffer);
		break;
	case 0xA8:
		RPM = GetMotorRPM(buffer);
		break;

	default:
		break;
	}


	//can_lld_transmit(&CAND2, CAN_DEDICATED_TXBUFFER, &tx2);
}


can1_can1rx(uint32_t msgbuf, CANRxFrame crfp)
{
	static int cnt = 0;
	cnt++;
	rx = crfp;
}
can4_can4rx(uint32_t msgbuf, CANRxFrame crfp)
{
	static int cnt = 0;
	cnt++;
}

