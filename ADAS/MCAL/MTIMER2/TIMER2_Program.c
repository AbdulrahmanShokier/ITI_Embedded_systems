/*
 * TIMER2_Program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TIMER2_Config.h"
#include "TIMER2_Interface.h"
#include "TIMER2_Private.h"
#include "TIMER2_Register.h"

static void (* GP_OvfCallBack)(void);
static void (* GP_OCMCallBack)(void);

void TMR2_VoidInit(void)
{
#if TIMER2_Mood==Normal_MOOD
	clear_bit(TIMER2_TCCR2,WGM20);
	clear_bit(TIMER2_TCCR2,WGM21);

#elif TIMER2_Mood==CTC_MOOD
	clear_bit(TIMER2_TCCR2,WGM20);
	set_bit(TIMER2_TCCR2,WGM21);
#elif TIMER2_Mood==PWM_PhaseCorrect_MOOD
	set_bit(TIMER2_TCCR2,WGM20);
	clear_bit(TIMER2_TCCR2,WGM21);
#elif TIMER2_Mood==FAST_PWM_MOOD
	set_bit(TIMER2_TCCR2,WGM20);
	set_bit(TIMER2_TCCR2,WGM21);
#else
#endif

#if Prescaler_Mood==NO_CLOCK_TIMER2
	clear_bit(TIMER2_TCCR2,CS20);
	clear_bit(TIMER2_TCCR2,CS21);
	clear_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==NO_PRESCALER_TIMER2
	set_bit(TIMER2_TCCR2,CS20);
	clear_bit(TIMER2_TCCR2,CS21);
	clear_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==PRESCALER_TIMER2_8
	clear_bit(TIMER2_TCCR2,CS20);
	set_bit(TIMER2_TCCR2,CS21);
	clear_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==PRESCALER_TIMER2_64
	set_bit(TIMER2_TCCR2,CS20);
	set_bit(TIMER2_TCCR2,CS21);
	clear_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==PRESCALER_TIMER2_256
	clear_bit(TIMER2_TCCR2,CS20);
	clear_bit(TIMER2_TCCR2,CS21);
	set_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==PRESCALER_TIMER2_1024
	set_bit(TIMER2_TCCR2,CS20);
	clear_bit(TIMER2_TCCR2,CS21);
	set_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==EXT_CLOCK_TIMER2_FALLING
	clear_bit(TIMER2_TCCR2,CS20);
	set_bit(TIMER2_TCCR2,CS21);
	set_bit(TIMER2_TCCR2,CS22);
#elif Prescaler_Mood==EXT_CLOCK_TIMER2_RISING
	set_bit(TIMER2_TCCR2,CS20);
	set_bit(TIMER2_TCCR2,CS21);
	set_bit(TIMER2_TCCR2,CS22);

#else
#endif
#if OC2_MOOD==Normal_port_operation
	clear_bit(TIMER2_TCCR2,COM20);
	clear_bit(TIMER2_TCCR2,COM21);
#elif OC2_MOOD==Toggle_OC2
	set_bit(TIMER2_TCCR2,COM20);
	clear_bit(TIMER2_TCCR2,COM21);
#elif OC2_MOOD==Clear_OC2
	clear_bit(TIMER2_TCCR2,COM20);
	set_bit(TIMER2_TCCR2,COM21);
#elif OC2_MOOD==Set_OC2
	set_bit(TIMER2_TCCR2,COM20);
	set_bit(TIMER2_TCCR2,COM21);
#else
#endif


}
void TMR2_VoidOVFInterruptEnable(void)
{
	set_bit(TIMER2_TIMSK,TOIE2);
}
void TMR2_VoidOCMInterruptEnable(void)
{
	set_bit(TIMER2_TIMSK,OCIE2);
}
void TMR2_VoidOVFInterruptDisable(void)
{
	clear_bit(TIMER2_TIMSK,TOIE2);
}
void TMR2_VoidOCMInterruptDisable(void)
{
	clear_bit(TIMER2_TIMSK,OCIE2);
}
void TMR2_VoidSetPreload(u8 A_u8PreLoading_Value)
{
	TIMER2_TCNT2=A_u8PreLoading_Value;
}
void TMR2_VoidSetOCMValue(u8 A_u8CompareMatchValue)
{
	TIMER2_OCR2=A_u8CompareMatchValue;
}
void TMR2_OFV_SetCallBack(void(*ptr)(void))
{
	GP_OvfCallBack=ptr;
}
void TMR2_OCM_SetCallBack(void(*ptr)(void))
{
	GP_OCMCallBack=ptr;
}
//OVF
void __vector_5 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_5 (void){

		GP_OvfCallBack();
}
//OCM
void __vector_4 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_4 (void){

		GP_OCMCallBack();

}


