/*
 * main.c
 *
 *  Created on: Aug 23, 2024
 *      Author: DELL
 */

#include "app.h"
extern u8 G_u8SystemMode;
extern u8 G_u8SlMode;
extern u8 G_u8CSSMode;
extern u16 G_u16Kilometers;
extern u8 G_BuzzerEnabled;
extern f64 DMS_Counter;
int main(void)
{
	Waiting_For_Password();
	/*External Interrups setting*/
	MDIO_void_SetDir(DIO_PORTD,PIND2,PIN_INPUT);
	MDIO_void_SetDir(DIO_PORTD,PIND3,PIN_INPUT);
	MDIO_void_SetDir(DIO_PORTB,PINB2,PIN_INPUT);
	MDIO_void_PinWrite(DIO_PORTD,PIND2,HIGH);
	MDIO_void_PinWrite(DIO_PORTD,PIND3,HIGH);
	MDIO_void_PinWrite(DIO_PORTB,PINB2,HIGH);
	MEXTI_voidExt0CallBack(Detecting_BasSystem);
	MEXTI_voidExt1CallBack(Detecting_SlSystem);
	MEXTI_voidExt2CallBack(Detecting_CSSSystem);
	MEXTI_voidExtInit();
	MEXTI_voidExtEnable(EXTI_EXTI0);
	MEXTI_voidExtEnable(EXTI_EXTI1);
	MEXTI_voidExtEnable(EXTI_EXTI2);
	MGINT_voidGlobalIntEnable();

	MDIO_void_SetDir(DIO_PORTB,PINB0,PIN_OUTPUT);
	MDIO_void_SetDir(DIO_PORTB,PINB1,PIN_OUTPUT);

	/*LCD start*/
	HLCD_voidInit();

	/*US Initialization*/

	MTIMER1_voidTimer1Init();
	MTIMER1_voidOvCallBack(HUS_voidOvCounter);
	MTIMER1_voidOvIntEnable();
	MGINT_voidGlobalIntEnable();
	HUS_voidUsInit();
	/*ADC*/
	MDIO_void_SetDir(DIO_PORTA,PINA0,PIN_INPUT);
	u32 L_u32ADCReadPrev=0,L_u32ADCReadLast=0;
	MADC_voidInit();
	MADC_voidStartConv();
	L_u32ADCReadLast=MADC_u16ReadOut();
	L_u32ADCReadPrev=L_u32ADCReadLast;
	/*Kilometer Printing*/

	u8 L_u8KilometersSt[8];
	//u8 L_u8Tim1=1,L_u8Tim2=1,L_u8Tim3=1;
	u32 L_f64LoopCounter=0;
	while(1)
	{
		MADC_voidStartConv();
		L_u32ADCReadLast=MADC_u16ReadOut();
		if(G_u8SystemMode==3)
		{
			Break_Assistance_System();
			Drive_Monitoring_System();
		}
		if(G_u8SystemMode==3 && G_u8SlMode==1)
		{
			SL_System();
		}
		if(G_u8SystemMode==3 && G_u8CSSMode==1 && L_u32ADCReadLast-L_u32ADCReadPrev==0)
		{
			CSS_System();
		}
		if(G_u8SystemMode!=3)
		{
			/*Turn off all leds and lcd on*/
			HLCD_voidSetCursor_DDRAM(1,1);
			HLCD_voidSendString("BAS:OFF");
			HLCD_voidSetCursor_DDRAM(2,1);
			HLCD_voidSendString("SL:OFF");
			HLCD_voidSetCursor_DDRAM(1,9);
			HLCD_voidSendString("CSS:OFF");
			MDIO_void_SetDir(DIO_PORTB,PINB4,PIN_OUTPUT);
			MDIO_void_PinWrite(DIO_PORTB,PINB4,LOW);
			MDIO_void_SetDir(DIO_PORTB,PINB1,PIN_OUTPUT);
			MDIO_void_PinWrite(DIO_PORTB,PINB1,LOW);
			MDIO_void_SetDir(DIO_PORTB,PINB0,PIN_OUTPUT);
			MDIO_void_PinWrite(DIO_PORTB,PINB0,LOW);
			G_BuzzerEnabled=0;
			DMS_Counter=0;
			MDIO_void_PinWrite(DIO_PORTA,PINA1,LOW);
		}
		if(G_u8SlMode==0 && G_u8SystemMode==3)
		{
			/*turn off sl */
			HLCD_voidSetCursor_DDRAM(2,1);
			HLCD_voidSendString("SL:OFF");
			MDIO_void_SetDir(DIO_PORTB,PINB1,PIN_OUTPUT);
			MDIO_void_PinWrite(DIO_PORTB,PINB1,LOW);
		}
		if((G_u8CSSMode==0 || ((L_u32ADCReadLast-L_u32ADCReadPrev>3) && (L_u32ADCReadLast-L_u32ADCReadPrev<-3) )) && G_u8SystemMode==3)
		{
			if(L_u32ADCReadLast-L_u32ADCReadPrev!=0)
				G_u8CSSMode=0;
			/*turn off css*/
			HLCD_voidSetCursor_DDRAM(1,9);
			HLCD_voidSendString("CSS:OFF");
			MDIO_void_SetDir(DIO_PORTB,PINB0,PIN_OUTPUT);
			MDIO_void_PinWrite(DIO_PORTB,PINB0,LOW);
		}
		/*
		if (L_u32ADCReadLast>0 && L_u32ADCReadLast<350 && G_u8SystemMode!=0 && G_u8SystemMode!=1 && L_u8Tim1==1)
		{

			L_u8Tim2=1;
			L_u8Tim3=1;
			L_u8Tim1=0;

			TMR0_VoidInit();
			TMR0_OFV_SetCallBack(Time_Count_KilometersInc1);
			TMR0_VoidOVFInterruptEnable();
			TMR0_VoidSetPreload(128);
			MGINT_voidGlobalIntEnable();
		}
		else if (L_u32ADCReadLast>=350 && L_u32ADCReadLast<700 && G_u8SystemMode!=0 && G_u8SystemMode!=1 &&L_u8Tim2==1 )
		{

			L_u8Tim2=0;
			L_u8Tim3=1;
			L_u8Tim1=1;

			TMR0_VoidInit();
			TMR0_OFV_SetCallBack(Time_Count_KilometersInc2);
			TMR0_VoidOVFInterruptEnable();
			TMR0_VoidSetPreload(191);
			MGINT_voidGlobalIntEnable();
		}
		else if (L_u32ADCReadLast>=700 && L_u32ADCReadLast<1000 && G_u8SystemMode!=0 && G_u8SystemMode!=1  && L_u8Tim3==1)
		{

			L_u8Tim2=1;
			L_u8Tim3=0;
			L_u8Tim1=1;

			TMR0_VoidInit();
			TMR0_OFV_SetCallBack(Time_Count_KilometersInc3);
			TMR0_VoidOVFInterruptEnable();
			TMR0_VoidSetPreload(64);
			MGINT_voidGlobalIntEnable();
		}
		 */
		if(L_u32ADCReadLast>0 && L_u32ADCReadLast<350 && G_u8SystemMode!=0 && G_u8SystemMode!=1)
		{
			if(L_f64LoopCounter % 100==0)
			{
				G_u16Kilometers++;
			}
		}
		else if (L_u32ADCReadLast>=350 && L_u32ADCReadLast<700 && G_u8SystemMode!=0 && G_u8SystemMode!=1 )
		{
			if(L_f64LoopCounter % 50==0)
			{
				G_u16Kilometers++;
			}
		}
		else if (L_u32ADCReadLast>=700 && L_u32ADCReadLast<1100 && G_u8SystemMode!=0 && G_u8SystemMode!=1 )
		{
			if(L_f64LoopCounter % 25==0)
			{
				G_u16Kilometers++;
			}
		}
		itoa(G_u16Kilometers,L_u8KilometersSt,10);
		HLCD_voidSetCursor_DDRAM(2,9);
		HLCD_voidSendString("D=");
		HLCD_voidSendString(L_u8KilometersSt);

		if(G_u8SystemMode==0)
		{
			HLCD_voidSendString(" N");

		}
		else if(G_u8SystemMode==1)
		{
			HLCD_voidSendString(" P");
		}
		else if(G_u8SystemMode==2)
		{
			HLCD_voidSendString(" R");
		}
		else if(G_u8SystemMode==3)
		{
			HLCD_voidSendString(" D");
		}


		L_u32ADCReadPrev=L_u32ADCReadLast;
		L_f64LoopCounter++;
		_delay_ms(110);
	}
	return 0;
}
