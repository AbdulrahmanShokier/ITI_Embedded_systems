/*
 * ADC_Program.c
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "ADC_Register.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"

static void (* GP_AdcCallBack)(void);
void MADC_voidInit(void)
{
	//setting division factor
	if(ADC_DivFactor==ADC_2)
	{
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else if(ADC_DivFactor==ADC_4)
	{
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else if(ADC_DivFactor==ADC_8)
	{
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else if(ADC_DivFactor==ADC_16)
	{
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else if(ADC_DivFactor==ADC_32)
	{
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else if(ADC_DivFactor==ADC_64)
	{
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else if(ADC_DivFactor==ADC_128)
	{
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS0);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS1);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADPS2);
	}
	else
	{

	}
	//Setting RefVoltage
	if(ADC_RefVoltage==ADC_AREF)
	{
		clear_bit(ADC_ADMUX,ADC_ADMUX_REFS0);
		clear_bit(ADC_ADMUX,ADC_ADMUX_REFS0);
	}
	else if(ADC_RefVoltage==ADC_AVCC)
	{
		set_bit(ADC_ADMUX,ADC_ADMUX_REFS0);
		clear_bit(ADC_ADMUX,ADC_ADMUX_REFS0);
	}
	else if(ADC_RefVoltage==ADC_IntVoltage)
	{
		set_bit(ADC_ADMUX,ADC_ADMUX_REFS0);
		set_bit(ADC_ADMUX,ADC_ADMUX_REFS0);
	}
	else
	{

	}
	//Setting AdjMode
	if(ADC_AdjMode==ADC_RIGHT_LEFT)
	{
		clear_bit(ADC_ADMUX,ADC_ADMUX_ADLAR);
	}
	else if(ADC_AdjMode==ADC_LEFT_RIGHT)
	{
		set_bit(ADC_ADMUX,ADC_ADMUX_ADLAR);
	}
	else
	{

	}
	//Setting Conversion Mode
	if(ADC_ConvMode==ADC_Automatic)
	{
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADATE);
		if(ADC_TriggerMode==ADC_FreeRunning)
		{
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_AnalogComp)
		{
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_EXTI0)
		{
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_CompMatchA)
		{
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_Overflow0)
		{
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_CompMatchB)
		{
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_Overflow1)
		{
			clear_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else if(ADC_TriggerMode==ADC_CaptureEvent)
		{
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
			set_bit(ADC_SFIOR,ADC_SFIOR_ADTS0);
		}
		else
		{

		}
	}
	else if(ADC_ConvMode==ADC_Manual)
	{
		clear_bit(ADC_ADCSRA,ADC_ADCSRA_ADATE);
	}
	//check booling or interrupt
	if(ADC_OuputMode==ADC_INTERRUPT)
	{
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADIE);
	}

	//ADC Enable
	set_bit(ADC_ADCSRA,ADC_ADCSRA_ADEN);

}
void MADC_voidStartConv(void)
{
	//setting mux selections
	ADC_ADMUX &=ADC_ChannelStart;
	ADC_ADMUX |= ADC_CHANNEL;
	//start conv
	set_bit(ADC_ADCSRA,ADC_ADCSRA_ADSC);
	if(ADC_OuputMode==ADC_BOOLING)
	{
		while(read_bit(ADC_ADCSRA,ADC_ADCSRA_ADIF)==0);
		set_bit(ADC_ADCSRA,ADC_ADCSRA_ADIF);
	}
}
u16 MADC_u16ReadOut(void)
{
	u16 L_u16Temp;
	if(ADC_AdjMode==ADC_RIGHT_LEFT)
	{
		return ADC_ADCLH;
	}
	else if (ADC_AdjMode==ADC_LEFT_RIGHT)
	{
		L_u16Temp=ADC_ADCH;
		return L_u16Temp<<2;
	}
}

void MADC_voidAdcCallBack(void (*PTR)(void))
{
	GP_AdcCallBack=PTR;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_16 (void){
	GP_AdcCallBack();
}
