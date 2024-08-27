/*
 * LCD_Program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: DELL
 */

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/MDIO/DIO_Interface.h"
#include "../../MCAL/MDIO/DIO_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
#include "util/delay.h"

void HLCD_voidInit(void)
{
	_delay_ms(100);
	if(LCD_MODE==LCD_COM_8BitOperation)
	{
		HLCD_voidSendCom(LCD_COM_8BitOperation);
		_delay_ms(1);
		HLCD_voidSendCom(LCD_COM_DisplayOn_CursorOn);
		_delay_ms(1);
		HLCD_voidSendCom(LCD_COM_ClearDisplay);
		_delay_ms(10);
		HLCD_voidSendCom(LCD_COM_EntryMode);
		_delay_ms(1);
	}
	else if(LCD_MODE==LCD_COM_4BitOperation)
	{
		HLCD_voidSendCom(LCD_COM_4BitOperation);
		_delay_ms(1);
		HLCD_voidSendCom(LCD_COM_DisplayOn_CursorOn);
		_delay_ms(1);
		HLCD_voidSendCom(LCD_COM_ClearDisplay);
		_delay_ms(10);
		HLCD_voidSendCom(LCD_COM_EntryMode);
		_delay_ms(1);
	}
	else
	{
		//Do Nothing
	}
}
void HLCD_voidSendData(u8 A_u8Data)
{
	if(LCD_MODE==LCD_COM_8BitOperation)
	{
		MDIO_void_PortSetDir(LCD_DATA_PORT,PORT_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_E_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_OUTPUT);

		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
		MDIO_void_PortWrite(LCD_DATA_PORT,A_u8Data);

		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
		_delay_ms(1);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,LOW);

	}
	else if(LCD_MODE==LCD_COM_4BitOperation)
	{
		//Direction set of 4 high pins of data port
		MDIO_void_SetDir(LCD_DATA_PORT,PINA4,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_DATA_PORT,PINA5,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_DATA_PORT,PINA6,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_DATA_PORT,PINA7,PIN_OUTPUT);

		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_E_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_OUTPUT);

		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
		//sending the 4 high pins
		MDIO_void_PortWriteHigh(LCD_DATA_PORT,A_u8Data>>4);
		//trigger
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
		_delay_ms(1);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,LOW);
		//sending the four low pins
		MDIO_void_PortWriteHigh(LCD_DATA_PORT,A_u8Data);
		//trigger
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
		_delay_ms(1);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,LOW);

	}
	else
	{
		//Do Nothing
	}
}
void HLCD_voidSendCom(u8 A_u8Command)
{
	if(LCD_MODE==LCD_COM_8BitOperation)
	{
		MDIO_void_PortSetDir(LCD_DATA_PORT,PORT_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_E_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_OUTPUT);

		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
		MDIO_void_PortWrite(LCD_DATA_PORT,A_u8Command);

		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
		_delay_ms(1);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,LOW);

	}
	else if(LCD_MODE==LCD_COM_4BitOperation)
	{
		//Direction set of 4 high pins of data port
		MDIO_void_SetDir(LCD_DATA_PORT,PINA4,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_DATA_PORT,PINA5,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_DATA_PORT,PINA6,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_DATA_PORT,PINA7,PIN_OUTPUT);

		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_E_PIN,PIN_OUTPUT);
		MDIO_void_SetDir(LCD_CONTROL_PORT,LCD_RW_PIN,PIN_OUTPUT);

		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
		//sending the 4 high pins
		MDIO_void_PortWriteHigh(LCD_DATA_PORT,A_u8Command>>4);
		//trigger
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
		_delay_ms(1);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,LOW);
		//sending the four low pins
		MDIO_void_PortWriteHigh(LCD_DATA_PORT,A_u8Command);
		//trigger
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
		_delay_ms(1);
		MDIO_void_PinWrite(LCD_CONTROL_PORT,LCD_E_PIN,LOW);

	}
	else
	{
		//Do Nothing
	}
}
void HLCD_voidSendString(u8 *A_Pu8String)
{
	u8 *L_u8Incrementer=A_Pu8String;
	while(*L_u8Incrementer!=0)
	{
		HLCD_voidSendData(*L_u8Incrementer);
		L_u8Incrementer++;
	}
}

void HLCD_voidSetCursor_DDRAM(u8 A_u8RowNum,u8 A_u8ColNum)
{
	u8 L_u8DDramMemAddress;

	if((A_u8RowNum>=LCD_MinRowSize && A_u8RowNum<=LCD_MaxRowSize) && (A_u8ColNum>=LCD_MinCloSize && A_u8ColNum<=LCD_MaxColSize))
	{
		if (A_u8RowNum==LCD_ROW1)
		{
			L_u8DDramMemAddress=LCD_FirstRowStart+A_u8ColNum-1;
		}
		else if(A_u8RowNum==LCD_ROW2)
		{
			L_u8DDramMemAddress=LCD_SecondRowStart+A_u8ColNum-1;
		}
		else
		{
			//This part will be added if the lcd is changed to bigger one
		}
		HLCD_voidSendCom(L_u8DDramMemAddress);
	}
	else
	{
		//Do Nothing
	}
}


void HLCD_voidSendSpecial(u8 * A_u8PSpecialChar ,u8 A_u8BlockNum,u8 A_u8RowNum,u8 A_u8ColNum)
{
	u8 L_u8Incrementer;
	HLCD_voidSendCom(LCD_CgromStartAddress+A_u8BlockNum*LCD_CgromMaxBlockNumber);
	for(L_u8Incrementer=LCD_MinPixelsRowNo;L_u8Incrementer<LCD_MaxPixelsRowNo;L_u8Incrementer++)
	{
		HLCD_voidSendData(*(A_u8PSpecialChar+L_u8Incrementer));
	}
	HLCD_voidSetCursor_DDRAM(A_u8RowNum,A_u8ColNum);
	HLCD_voidSendData(A_u8BlockNum);
}
