/*
 * DIO_Program.c
 *
 *  Created on: Aug 2, 2024
 *      Author: DELL
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"
#include"DIO_Interface.h"
#include"DIO_Config.h"
#include"DIO_Private.h"
#include"DIO_Register.h"

void MDIO_void_SetDir(u8 A_u8_PortNum,u8 A_u8_PinNum,u8 A_u8_PinDir)
{
	if(PIN_OUTPUT==A_u8_PinDir)
	{
		switch(A_u8_PortNum)
		{
		case DIO_PORTA:set_bit(DIO_u8_DDRA,A_u8_PinNum);break;
		case DIO_PORTB:set_bit(DIO_u8_DDRB,A_u8_PinNum);break;
		case DIO_PORTC:set_bit(DIO_u8_DDRC,A_u8_PinNum);break;
		case DIO_PORTD:set_bit(DIO_u8_DDRD,A_u8_PinNum);break;
		default:break;
		}
	}
	else if(PIN_INPUT==A_u8_PinDir)
	{
		switch(A_u8_PortNum)
		{
		case DIO_PORTA:clear_bit(DIO_u8_DDRA,A_u8_PinNum);break;
		case DIO_PORTB:clear_bit(DIO_u8_DDRB,A_u8_PinNum);break;
		case DIO_PORTC:clear_bit(DIO_u8_DDRC,A_u8_PinNum);break;
		case DIO_PORTD:clear_bit(DIO_u8_DDRD,A_u8_PinNum);break;
		default:break;
		}
	}
	else
	{

	}
}
void MDIO_void_PinWrite(u8 A_u8_PortNum,u8 A_u8_PinNum,u8 A_u8_PinValue)
{
	if(HIGH==A_u8_PinValue)
	{
		switch(A_u8_PortNum)
		{
		case DIO_PORTA:set_bit(DIO_u8_PORTA,A_u8_PinNum);break;
		case DIO_PORTB:set_bit(DIO_u8_PORTB,A_u8_PinNum);break;
		case DIO_PORTC:set_bit(DIO_u8_PORTC,A_u8_PinNum);break;
		case DIO_PORTD:set_bit(DIO_u8_PORTD,A_u8_PinNum);break;
		default:break;
		}
	}
	else if(LOW==A_u8_PinValue)
	{
		switch(A_u8_PortNum){
		case DIO_PORTA:clear_bit(DIO_u8_PORTA,A_u8_PinNum);break;
		case DIO_PORTB:clear_bit(DIO_u8_PORTB,A_u8_PinNum);break;
		case DIO_PORTC:clear_bit(DIO_u8_PORTC,A_u8_PinNum);break;
		case DIO_PORTD:clear_bit(DIO_u8_PORTD,A_u8_PinNum);break;
		default:break;
		}
	}
	else
	{

	}
}
u8 MDIO_u8_PinRead(u8 A_u8_PortNum,u8 A_u8_PinNum)
{
	u8 L_u8_PinValue;
	switch(A_u8_PortNum)
	{
	case DIO_PORTA:L_u8_PinValue=read_bit(DIO_u8_PINA,A_u8_PinNum);break;
	case DIO_PORTB:L_u8_PinValue=read_bit(DIO_u8_PINB,A_u8_PinNum);break;
	case DIO_PORTC:L_u8_PinValue=read_bit(DIO_u8_PINC,A_u8_PinNum);break;
	case DIO_PORTD:L_u8_PinValue=read_bit(DIO_u8_PIND,A_u8_PinNum);break;
	default:break;
	}

	return L_u8_PinValue;
}
void MDIO_void_PinToggle(u8 A_u8_PortNum,u8 A_u8_PinNum)
{
	switch(A_u8_PortNum)
	{
	case DIO_PORTA:toggle_bit(DIO_u8_PORTA,A_u8_PinNum);break;
	case DIO_PORTB:toggle_bit(DIO_u8_PORTB,A_u8_PinNum);break;
	case DIO_PORTC:toggle_bit(DIO_u8_PORTC,A_u8_PinNum);break;
	case DIO_PORTD:toggle_bit(DIO_u8_PORTD,A_u8_PinNum);break;
	default:break;
	}
}
void MDIO_void_PortSetDir(u8 A_u8_PortNum,u8 A_u8_PortDir)
{
	switch(A_u8_PortNum)
	{
	case DIO_PORTA:DIO_u8_DDRA=A_u8_PortDir;break;
	case DIO_PORTB:DIO_u8_DDRB=A_u8_PortDir;break;
	case DIO_PORTC:DIO_u8_DDRC=A_u8_PortDir;break;
	case DIO_PORTD:DIO_u8_DDRD=A_u8_PortDir;break;
	default:break;
	}
}
void MDIO_void_PortWrite(u8 A_u8_PortNum,u8 A_u8_PortValue)
{
	switch(A_u8_PortNum)
	{
	case DIO_PORTA:DIO_u8_PORTA=A_u8_PortValue;break;
	case DIO_PORTB:DIO_u8_PORTB=A_u8_PortValue;break;
	case DIO_PORTC:DIO_u8_PORTC=A_u8_PortValue;break;
	case DIO_PORTD:DIO_u8_PORTD=A_u8_PortValue;break;
	default:break;
	}
}
u8 MDIO_u8_PortRead(u8 A_u8_PortNum)
{
	u8 L_u8_PortValue;
	switch(A_u8_PortNum)
	{
	case DIO_PORTA:L_u8_PortValue=DIO_u8_PORTA;break;
	case DIO_PORTB:L_u8_PortValue=DIO_u8_PORTB;break;
	case DIO_PORTC:L_u8_PortValue=DIO_u8_PORTC;break;
	case DIO_PORTD:L_u8_PortValue=DIO_u8_PORTD;break;
	default:break;
	}
	return L_u8_PortValue;
}
void MDIO_void_PortWriteHigh(u8 A_u8_PortNum,u8 A_u8_PortValue)
{
	MDIO_void_PortWrite(A_u8_PortNum,A_u8_PortValue<<4);
}
