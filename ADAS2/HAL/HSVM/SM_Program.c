/*
 * SM_Program.c

 *
 *  Created on: Aug 12, 2024
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MDIO/DIO_Interface.h"
#include "../../MCAL/MDIO/DIO_Config.h"
#include "../../MCAL/MTIMER1/TIMER1_Interface.h"
#include "../../MCAL/MTIMER1/TIMER1_Config.h"
#include "SM_Interface.h"
#include "SM_Private.h"
#include "SM_Config.h"

void HServoMotor(f32 A_f32Angle)
{

	f32 L_f32OCRAValue;
	if(A_f32Angle>=0 &&A_f32Angle<=90 )
	{
		L_f32OCRAValue=1.5+A_f32Angle*Single_Angle_Time;
	}
	else if (A_f32Angle>=-90 && A_f32Angle<=0)
	{
		L_f32OCRAValue=1.5-A_f32Angle*-Single_Angle_Time;
	}
	else
	{

	}
	L_f32OCRAValue=(u16)((L_f32OCRAValue*0.001)/(((f32)Timer1Prescaling)/(8000000.0))); //Watch out of integer division
	MTIMER1_voidSetOCR1A(L_f32OCRAValue);
}
