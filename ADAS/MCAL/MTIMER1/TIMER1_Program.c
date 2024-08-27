/*
 * TIMER1_Program.c
 *
 *  Created on: Aug 14, 2024
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"
#include "TIMER1_Register.h"
#include "TIMER1_Config.h"

void (* GP_OvCallback)(void);
void (* GP_CM1ACallback)(void);
void (* GP_CM1BCallback)(void);

void MTIMER1_voidTimer1Init(void)
{

	/*Select Timer1 Mode*/

#if Timer1Mode==NormalMode
	clear_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseCorrect_8
	set_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseCorrect_9
	clear_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseCorrect_10
	set_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==CTC_OCR1A
	clear_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmFast_8
	set_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmFast_9
	clear_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmFast_10
	set_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	clear_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseAndFreqCorrect_ICR1
	clear_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseAndFreqCorrect_OCR1A
	set_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseCorrect_OCR1A
	set_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#elif Timer1Mode==PwmPhaseCorrect_ICR1
	clear_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	clear_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#elif Timer1Mode==CTC_ICR1
	clear_bit(TCCR1A,WGM10);
	clear_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#elif Timer1Mode==FastPwm_ICR1
	clear_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#elif Timer1Mode==FastPwm_OCR1A
	set_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
#else
#error "Wrong input For Timer1 Mode"
#endif

	/*Select Prescalar*/
#if Timer1Prescaling==NoClkSource
	clear_bit(TCCR1B,CS10);
	clear_bit(TCCR1B,CS11);
	clear_bit(TCCR1B,CS12);
#elif Timer1Prescaling==NoPrescaling
	set_bit(TCCR1B,CS10);
	clear_bit(TCCR1B,CS11);
	clear_bit(TCCR1B,CS12);
#elif Timer1Prescaling==Prescaling_8
	clear_bit(TCCR1B,CS10);
	set_bit(TCCR1B,CS11);
	clear_bit(TCCR1B,CS12);
#elif Timer1Prescaling==Prescaling_64
	set_bit(TCCR1B,CS10);
	set_bit(TCCR1B,CS11);
	clear_bit(TCCR1B,CS12);
#elif Timer1Prescaling==Prescaling_256
	clear_bit(TCCR1B,CS10);
	clear_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
#elif Timer1Prescaling==Prescaling_1024
	set_bit(TCCR1B,CS10);
	clear_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
#elif Timer1Prescaling==ExternalClk_Falling_edge
	clear_bit(TCCR1B,CS10);
	set_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
#elif Timer1Prescaling==ExternalClk_Rising_edge
	set_bit(TCCR1B,CS10);
	set_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
#endif

	/*Select Compare Output Mode For OC1A*/

#if OC1A_CompareMode==NormalPortOperation
	clear_bit(TCCR1A,COM1A0);
	clear_bit(TCCR1A,COM1A1);
#elif OC1A_CompareMode==ToggleOnCM
	set_bit(TCCR1A,COM1A0);
	clear_bit(TCCR1A,COM1A1);
#elif OC1A_CompareMode==ClearOnCM
	clear_bit(TCCR1A,COM1A0);
	set_bit(TCCR1A,COM1A1);
#elif OC1A_CompareMode==SetOnCM
	set_bit(TCCR1A,COM1A0);
	set_bit(TCCR1A,COM1A1);
#endif

	/*Select Compare Output Mode For OC1B*/

#if OC1B_CompareMode==NormalPortOperation
	clear_bit(TCCR1A,COM1B0);
	clear_bit(TCCR1A,COM1B1);
#elif OC1B_CompareMode==ToggleOnCM
	set_bit(TCCR1A,COM1B0);
	clear_bit(TCCR1A,COM1B1);
#elif OC1B_CompareMode==ClearOnCM
	clear_bit(TCCR1A,COM1B0);
	set_bit(TCCR1A,COM1B1);
#elif OC1B_CompareMode==SetOnCM
	set_bit(TCCR1A,COM1B0);
	set_bit(TCCR1A,COM1B1);
#else
#endif

}

void MTIMER1_voidSetPreload(u16 A_u16PreloadValue)
{
	TCNT1=A_u16PreloadValue;
}
void MTIMER1_voidSetOCR1A(u16 A_u16OCR1AValue)
{
	OCR1A=A_u16OCR1AValue;
}
void MTIMER1_voidSetOCR1B(u16 A_u16OCR1BValue)
{
	OCR1B=A_u16OCR1BValue;
}
void MTIMER1_voidSetICR1(u16 A_u16ICR1Value)
{
	ICR1=A_u16ICR1Value;
}
void MTIMER1_voidOvIntEnable(void)
{
	set_bit(TIMSK,TOIE1);
}
void MTIMER1_voidOCR1AIntEnable(void)
{
	set_bit(TIMSK,OCIE1A);
}
void MTIMER1_voidOCR1BIntEnable(void)
{
	set_bit(TIMSK,OCIE1B);
}
void MTIMER1_voidICUIntEnable(void)
{
	set_bit(TIMSK,TICIE1);
}
void MTIMER1_voidOvCallBack(void (*ptr)(void))
{
	GP_OvCallback=ptr;
}
void MTIMER1_voidOCR1ACallBack(void (*ptr)(void))
{
	GP_CM1ACallback=ptr;
}
void MTIMER1_voidOCR1BCallBack(void (*ptr)(void))
{
	GP_CM1BCallback=ptr;
}

//We Will need to add another callback for icu and 4 isr one for each callback
