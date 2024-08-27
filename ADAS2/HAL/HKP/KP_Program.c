/*
 * KP_Program.c
 *
 *  Created on: Aug 6, 2024
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MDIO/DIO_Config.h"
#include "../../MCAL/MDIO/DIO_Interface.h"
#include "KP_Interface.h"
#include "KP_Config.h"
#include "KP_Private.h"
#include "util/delay.h"

u8 G_u8PressedValue=NoValueEntered;
u8 G_u8KpChars [4][4]={{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'O','0','=','+'}};
void HKP_voidKpInit(void)
{
	MDIO_void_PortWrite(KP_PORT,KP_ALL_PINS_HIGH);
	if(KP_COL_START==PIN0 && KP_ROW_START==PIN4)
	{
		MDIO_void_PortSetDir(KP_PORT,KP_LOWER_HIGH);
	}
	else if(KP_COL_START==PIN4 && KP_ROW_START==PIN0)
	{
		MDIO_void_PortWrite(KP_PORT,KP_UPPER_HIGH);
	}
	else
	{

	}
}

u8 HKP_u8GetPressedValue(void)
{
	u8 L_u8ColIncrementer;
	u8 L_u8RowIncrementer;
	for(L_u8ColIncrementer=KP_COL_START;L_u8ColIncrementer<=KP_COL_END;L_u8ColIncrementer++)
	{
		MDIO_void_PinWrite(KP_PORT,L_u8ColIncrementer,LOW);
		for(L_u8RowIncrementer=KP_ROW_START;L_u8RowIncrementer<=KP_ROW_END;L_u8RowIncrementer++)
		{
			if(MDIO_u8_PinRead(KP_PORT,L_u8RowIncrementer)==PRESSED)
			{
				G_u8PressedValue=G_u8KpChars[L_u8RowIncrementer-KP_ROW_START][L_u8ColIncrementer-KP_COL_START];
				while(MDIO_u8_PinRead(KP_PORT,L_u8RowIncrementer)==PRESSED);
				_delay_ms(10); //delay for bouncing
			}
		}
		MDIO_void_PinWrite(KP_PORT,L_u8ColIncrementer,HIGH);
	}
	return G_u8PressedValue;
}

