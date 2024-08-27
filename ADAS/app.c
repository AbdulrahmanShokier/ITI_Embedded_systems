/*
 * app.c
 *
 *  Created on: Aug 22, 2024
 *      Author: DELL
 */
#include "app.h"

void E2PROMStorePass(void)
{
	HEEPROM_voidInit(90000);
	for(u32 i=0;i<4;i++)
	{
		HEEPROM_voidWriteByte(i,'1'+i);
	}
}

void CheckPass(void)
{
	HLCD_voidInit();
	HKP_voidKpInit();
	u8 L_u8PressedValue=255,L_u8CopyPressedValue,L_u8Check=1,L_u8Counter=0;
	while(L_u8Check==1)
	{
		L_u8PressedValue=HKP_u8GetPressedValue();
		G_u8PressedValue=255;
		if(L_u8PressedValue =='=')
		{
			HLCD_voidSendData(L_u8PressedValue);
			if(L_u8Counter==0 || L_u8Counter>1)
			{
				HLCD_voidSetCursor_DDRAM(1,1);
				HLCD_voidSendString("Incorrect");
				L_u8Counter=0;
				/*Timer Clear Screen After 1 Sec*/
				TMR2_VoidInit();
				TMR2_OCM_SetCallBack(Time_Count_ClrScreen);
				TMR2_VoidSetOCMValue(200);
				TMR2_VoidOCMInterruptEnable();
				MGINT_voidGlobalIntEnable();
				/*Turning on red led for 700 ms*/
				MDIO_void_SetDir(DIO_PORTC,PINC7,PIN_OUTPUT);
				MDIO_void_PinWrite(DIO_PORTC,PINC7,HIGH);
				TMR0_VoidInit();
				TMR0_OCM_SetCallBack(Time_Count_RedLedToggle);
				TMR0_VoidSetOCMValue(140);
				TMR0_VoidOCMInterruptEnable();
				MGINT_voidGlobalIntEnable();

			}
			else if (L_u8Counter==1)
			{
				for (u32 i=0;i<4;i++)
				{
					if(L_u8CopyPressedValue==HEEPROM_u8ReadByte(i))
					{
						HLCD_voidSetCursor_DDRAM(1,1);
						HLCD_voidSendString("Correct");
						/*Turning on green led for 700 ms*/
						MDIO_void_SetDir(DIO_PORTC,PINC6,PIN_OUTPUT);
						MDIO_void_PinWrite(DIO_PORTC,PINC6,HIGH);
						TMR0_VoidInit();
						TMR0_OCM_SetCallBack(Time_Count_GreenLedToggle);
						TMR0_VoidSetOCMValue(140);
						TMR0_VoidOCMInterruptEnable();
						MGINT_voidGlobalIntEnable();
						/*Moving SVM*/
						MDIO_void_SetDir(DIO_PORTD,PIND5,PIN_OUTPUT);
						MTIMER1_voidTimer1Init();
						MTIMER1_voidSetICR1((u16)SV_Period_Value);
						HServoMotor(90);
						TMR2_VoidInit();
						TMR2_OCM_SetCallBack(Time_Count_SVMReturn);
						TMR2_VoidSetOCMValue(200);
						TMR2_VoidOCMInterruptEnable();
						MGINT_voidGlobalIntEnable();
						/*Sending Char A through Uart*/

						MDIO_void_SetDir(DIO_PORTD,PIND0,PIN_INPUT);
						MDIO_void_SetDir(DIO_PORTD,PIND1,PIN_OUTPUT);
						MDIO_void_SetDir(DIO_PORTC,PIND2,PIN_OUTPUT);
						MDIO_void_PinWrite(DIO_PORTC,PIND2,HIGH);

							MUART_voidUartSend('A');
							MDIO_void_SetDir(DIO_PORTC,PINC2,PIN_OUTPUT);//
							MDIO_void_PinWrite(DIO_PORTC,PINC2,HIGH);//

						/*breaking from for and while loops*/
						L_u8Check=0;
						break;
					}

				}
				if(L_u8Check==1)
				{
					HLCD_voidSetCursor_DDRAM(1,1);
					HLCD_voidSendString("Incorrect");
					L_u8Counter=0;
					/*Timer Clear Screen After 1 Sec*/
					TMR2_VoidInit();
					TMR2_OCM_SetCallBack(Time_Count_ClrScreen);
					TMR2_VoidSetOCMValue(200);
					TMR2_VoidOCMInterruptEnable();
					MGINT_voidGlobalIntEnable();
					/*Turning on red led for 700 ms*/
					MDIO_void_SetDir(DIO_PORTC,PINC7,PIN_OUTPUT);
					MDIO_void_PinWrite(DIO_PORTC,PINC7,HIGH);
					TMR0_VoidInit();
					TMR0_OCM_SetCallBack(Time_Count_RedLedToggle);
					TMR0_VoidSetOCMValue(140);
					TMR0_VoidOCMInterruptEnable();
					MGINT_voidGlobalIntEnable();
				}
			}
		}
		else if(L_u8PressedValue!=255 && L_u8PressedValue!='+' && L_u8PressedValue!='-' && L_u8PressedValue!='x' && L_u8PressedValue!='/' && L_u8PressedValue!='O')
		{
			L_u8Counter++;
			HLCD_voidSendData(L_u8PressedValue);
			L_u8CopyPressedValue=L_u8PressedValue;
		}

	}
}

void test(void)
{
	HLCD_voidInit();
	HEEPROM_voidInit(90000);
	for (int i=0;i<3;i++)
	{
		HEEPROM_voidWriteByte(0+i,'1'+i);
	}
	for (int i=0;i<3;i++)
	{
		HLCD_voidSendData(HEEPROM_u8ReadByte(0+i));
	}

}

void Time_Count_ClrScreen(void)
{
	static u32 L_u32Counter=0;
	L_u32Counter++;
	if(L_u32Counter==5000)
	{
		HLCD_voidSetCursor_DDRAM(1,1);
		HLCD_voidSendString("                ");
		HLCD_voidSetCursor_DDRAM(1,1);
		L_u32Counter=0;
		TMR2_VoidOCMInterruptDisable();
	}
}

void Time_Count_SVMReturn(void)
{
	static u32 L_u32Counter=0;
	L_u32Counter++;
	if(L_u32Counter==5000)
	{
		HServoMotor(0);
		L_u32Counter=0;
		TMR2_VoidOCMInterruptDisable();
	}
}

void Time_Count_RedLedToggle(void)
{
	static u32 L_u32Counter=0;
	L_u32Counter++;
	if(L_u32Counter==5000)
	{
		MDIO_void_PinToggle(DIO_PORTC,PINC7);
		L_u32Counter=0;
		TMR0_VoidOCMInterruptDisable();
	}
}

void Time_Count_GreenLedToggle(void)
{
	static u32 L_u32Counter=0;
	L_u32Counter++;
	if(L_u32Counter==5000)
	{
		MDIO_void_PinToggle(DIO_PORTC,PINC6);
		L_u32Counter=0;
		TMR0_VoidOCMInterruptDisable();
	}
}

