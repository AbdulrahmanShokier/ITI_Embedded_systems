/*
 * app.c
 *
 *  Created on: Aug 23, 2024
 *      Author: DELL
 */
#include "app.h"
u8 G_u8SystemMode=0;
u8 G_u8SlMode=0;
u8 G_u8CSSMode=0;
u16 G_u16Kilometers=0;
u8 G_Timer2IntEnabled=0;
u8 G_BuzzerEnabled=0;
f64 DMS_Counter=0;
/*N=0
 * P=1
 * R=2
 * D=3
 * */
void Waiting_For_Password(void)
{
	MUART_voidUartInit();
	MDIO_void_SetDir(DIO_PORTD,PIND0,PIN_INPUT);
	MDIO_void_SetDir(DIO_PORTD,PIND1,PIN_OUTPUT);
	MDIO_void_SetDir(DIO_PORTA,PINA2,PIN_INPUT);
	while(MUART_u8UartRecieve()!='A' && MDIO_u8_PinRead(DIO_PORTA,PINA2)!=1);
}

void Detecting_BasSystem(void)
{
	G_u8SystemMode++;
	if(G_u8SystemMode==4)
		G_u8SystemMode=0;
}
void Detecting_SlSystem(void)
{

		G_u8SlMode++;
			if(G_u8SlMode==2)
				G_u8SlMode=0;

}
void Detecting_CSSSystem(void)
{

			G_u8CSSMode++;
			if(G_u8CSSMode==2)
				G_u8CSSMode=0;


}

void Break_Assistance_System(void)
{
	u8 L_u8CalculatedDistance;

	//L_u8CalculatedDistance=HUS_u16CalcDistancd();
	L_u8CalculatedDistance=7;
	if(L_u8CalculatedDistance>10)
	{
		HLCD_voidSetCursor_DDRAM(1,1);
		HLCD_voidSendString("BAS: ON");
		MDIO_void_SetDir(DIO_PORTB,PINB4,PIN_OUTPUT);
		MDIO_void_PinWrite(DIO_PORTB,PINB4,LOW);
	}
	else if (L_u8CalculatedDistance>5)
	{
		HLCD_voidSetCursor_DDRAM(1,1);
		HLCD_voidSendString("BAS: ON");
		MDIO_void_SetDir(DIO_PORTB,PINB4,PIN_OUTPUT);
		MDIO_void_PinToggle(DIO_PORTB,PINB4);
		/*Timer toggle After 100 mSec*/
		/*
		MDIO_void_PinToggle(DIO_PORTB,PINB4);
		TMR2_VoidInit();
		TMR2_OCM_SetCallBack(Time_Count_ToggleLed);
		TMR2_VoidSetOCMValue(20);
		TMR2_VoidOCMInterruptEnable();
		MGINT_voidGlobalIntEnable();
		 */

		//_delay_ms(110);
	}
	else
	{
		HLCD_voidSetCursor_DDRAM(1,1);
		HLCD_voidSendString("BAS: ON");
		MDIO_void_SetDir(DIO_PORTB,PINB4,PIN_OUTPUT);
		MDIO_void_PinWrite(DIO_PORTB,PINB4,HIGH);
	}
}

void SL_System(void)
{
	HLCD_voidSetCursor_DDRAM(2,1);
	HLCD_voidSendString("SL: ON");
	//MDIO_void_SetDir(DIO_PORTB,PINB1,PIN_OUTPUT);
	MDIO_void_PinWrite(DIO_PORTB,PINB1,HIGH);
}
void CSS_System(void)
{
	HLCD_voidSetCursor_DDRAM(1,9);
	HLCD_voidSendString("CSS: ON");
	//MDIO_void_SetDir(DIO_PORTB,PINB0,PIN_OUTPUT);
	MDIO_void_PinWrite(DIO_PORTB,PINB0,HIGH);
}
void Drive_Monitoring_System(void)
{
	/*
	if(G_Timer2IntEnabled==0)
	{

		TMR2_VoidInit();
		TMR2_OFV_SetCallBack(Time_Count_SameState);
		TMR2_VoidOCMInterruptEnable();
		TMR2_VoidSetOCMValue(125);
		MGINT_voidGlobalIntEnable();
		G_Timer2IntEnabled=1;
	}
	*/
	DMS_Counter++;
	if(DMS_Counter==50)
	{
		G_BuzzerEnabled=1;
		DMS_Counter=0;
	}
	if(G_BuzzerEnabled==1)
	{
		/*Buzzer Enable*/
		MDIO_void_SetDir(DIO_PORTA,PINA1,PIN_OUTPUT);
		MDIO_void_PinToggle(DIO_PORTA,PINA1);
	}
}
/*
void Time_Count_ToggleLed(void)
{
	static u32 L_u32Counter=0;
	L_u32Counter++;
	if(L_u32Counter==5000)
	{
		MDIO_void_PinToggle(DIO_PORTB,PINB4);
		L_u32Counter=0;
		TMR2_VoidOCMInterruptDisable();
	}
}
void Time_Count_KilometersInc1(void)
{
	static u8 L_u32Counter2=0;
	L_u32Counter2++;
	if(L_u32Counter2==23438)
	{
		G_u16Kilometers++;
		L_u32Counter2=0;
		TMR0_VoidSetPreload(128);
	}
}
void Time_Count_KilometersInc2(void)
{
	static u8 L_u32Counter3=0;
	L_u32Counter3++;
	if(L_u32Counter3==11719)
	{
		G_u16Kilometers++;
		L_u32Counter3=0;
		TMR0_VoidSetPreload(191);
	}
}
void Time_Count_KilometersInc3(void)
{
	static u8 L_u32Counter4=0;
	L_u32Counter4++;
	if(L_u32Counter4==3907)
	{
		G_u16Kilometers++;
		L_u32Counter4=0;
		TMR0_VoidSetPreload(64);
	}
}
*/
void Time_Count_SameState(void)
{
	static u8 L_u32Counter1=0;
	L_u32Counter1++;
	if(L_u32Counter1==5000)
	{
		if(G_u8SystemMode==3)
		{
			G_BuzzerEnabled=1;
		}
		else
		{
			G_BuzzerEnabled=0;
			G_Timer2IntEnabled=0;
			TMR2_VoidOCMInterruptDisable();
		}
		L_u32Counter1=0;
	}
}
