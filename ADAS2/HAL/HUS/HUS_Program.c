/*
 * HUS_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MDIO/DIO_Interface.h"
#include "../../MCAL/MDIO/DIO_Config.h"
#include "../../MCAL/MTIMER1/TIMER1_Interface.h"
#include "../../MCAL/MTIMER1/TIMER1_Config.h"
#include "HUS_Config.h"
#include "HUS_Interface.h"
#include "HUS_Private.h"
#include "util/delay.h"

extern u32 G_u32Counter;
void HUS_voidUsInit(void)
{
	//MDIO_void_SetDir(DIO_PORTD,PIND6,PIN_INPUT);
	MDIO_void_SetDir(Trigger_Port,Trigger_Pin,PIN_OUTPUT);
}
u16 HUS_u16CalcDistancd(void)
{
	u16 L_u16Distance=0;
	MDIO_void_PinWrite(Trigger_Port,Trigger_Pin,HIGH);
	_delay_us(50);
	MDIO_void_PinWrite(Trigger_Port,Trigger_Pin,LOW);
	L_u16Distance=(US_WaveSpeed/2.0);
	L_u16Distance=L_u16Distance*(f32)MTIMER1_u16TonCalc();
	return L_u16Distance;
}
void HUS_voidOvCounter(void)
{
	G_u32Counter++;
}



