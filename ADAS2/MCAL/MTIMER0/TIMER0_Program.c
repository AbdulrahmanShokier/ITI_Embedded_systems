/*
 * TIMER0_Program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TIMER0_Register.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Config.h"
#include "TIMER0_Private.h"

static void (* GP_OvfCallBack)(void);
static void (* GP_OCMCallBack)(void);

void TMR0_VoidInit(void)
{
#if TIMER0_Mood==Normal_MOOD
	clear_bit(TIMER0_TCCR0,WGM00);
	clear_bit(TIMER0_TCCR0,WGM01);

#elif TIMER0_Mood==CTC_MOOD
	clear_bit(TIMER0_TCCR0,WGM00);
	set_bit(TIMER0_TCCR0,WGM01);
#elif TIMER0_Mood==PWM_PhaseCorrect_MOOD
	set_bit(TIMER0_TCCR0,WGM00);
	clear_bit(TIMER0_TCCR0,WGM01);
#elif TIMER0_Mood==FAST_PWM_MOOD
	set_bit(TIMER0_TCCR0,WGM00);
	set_bit(TIMER0_TCCR0,WGM01);
#else
#endif

#if Prescaler_Mood0==NO_CLOCK_TIMER0
	clear_bit(TIMER0_TCCR0,CS00);
	clear_bit(TIMER0_TCCR0,CS01);
	clear_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==NO_PRESCALER_TIMER0
	set_bit(TIMER0_TCCR0,CS00);
	clear_bit(TIMER0_TCCR0,CS01);
	clear_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==PRESCALER_TIMER0_8
	clear_bit(TIMER0_TCCR0,CS00);
	set_bit(TIMER0_TCCR0,CS01);
	clear_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==PRESCALER_TIMER0_64
	set_bit(TIMER0_TCCR0,CS00);
	set_bit(TIMER0_TCCR0,CS01);
	clear_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==PRESCALER_TIMER0_256
	clear_bit(TIMER0_TCCR0,CS00);
	clear_bit(TIMER0_TCCR0,CS01);
	set_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==PRESCALER_TIMER0_1024
	set_bit(TIMER0_TCCR0,CS00);
	clear_bit(TIMER0_TCCR0,CS01);
	set_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==EXT_CLOCK_TIMER0_FALLING
	clear_bit(TIMER0_TCCR0,CS00);
	set_bit(TIMER0_TCCR0,CS01);
	set_bit(TIMER0_TCCR0,CS02);
#elif Prescaler_Mood0==EXT_CLOCK_TIMER0_RISING
	set_bit(TIMER0_TCCR0,CS00);
	set_bit(TIMER0_TCCR0,CS01);
	set_bit(TIMER0_TCCR0,CS02);

#else
#endif
#if OC0_MOOD==Normal_port_operation
	clear_bit(TIMER0_TCCR0,COM00);
	clear_bit(TIMER0_TCCR0,COM01);
#elif OC0_MOOD==Toggle_OC0
	set_bit(TIMER0_TCCR0,COM00);
	clear_bit(TIMER0_TCCR0,COM01);
#elif OC0_MOOD==Clear_OC0
	clear_bit(TIMER0_TCCR0,COM00);
	set_bit(TIMER0_TCCR0,COM01);
#elif OC0_MOOD==Set_OC0
	set_bit(TIMER0_TCCR0,COM00);
	set_bit(TIMER0_TCCR0,COM01);
#else
#endif


}
void TMR0_VoidOVFInterruptEnable(void)
{
	set_bit(TIMER0_TIMSK,TOIE0);
}
void TMR0_VoidOCMInterruptEnable(void)
{
	set_bit(TIMER0_TIMSK,OCIE0);
}
void TMR0_VoidOVFInterruptDisable(void)
{
	clear_bit(TIMER0_TIMSK,TOIE0);
}
void TMR0_VoidOCMInterruptDisable(void)
{
	clear_bit(TIMER0_TIMSK,OCIE0);
}
void TMR0_VoidSetPreload(u8 A_u8PreLoading_Value)
{
	TIMER0_TCNT0=A_u8PreLoading_Value;
}
void TMR0_VoidSetOCMValue(u8 A_u8CompareMatchValue)
{
	TIMER0_OCR0=A_u8CompareMatchValue;
}
void TMR0_OFV_SetCallBack(void(*ptr)(void))
{
	GP_OvfCallBack=ptr;
}
void TMR0_OCM_SetCallBack(void(*ptr)(void))
{
	GP_OCMCallBack=ptr;
}
//OVF
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void){

		GP_OvfCallBack();
}
//OCM
void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void){

		GP_OCMCallBack();

}


