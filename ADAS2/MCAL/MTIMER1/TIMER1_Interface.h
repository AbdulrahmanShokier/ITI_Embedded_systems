/*
 * TIMER1_Interface.h
 *
 *  Created on: Aug 14, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER1_TIMER1_INTERFACE_H_
#define MCAL_MTIMER1_TIMER1_INTERFACE_H_

/*Timer1 Modes*/

#define NormalMode						0
#define PwmPhaseCorrect_8 				1
#define PwmPhaseCorrect_9 				2
#define PwmPhaseCorrect_10 				3
#define CTC_OCR1A						4
#define PwmFast_8						5
#define PwmFast_9						6
#define PwmFast_10						7
#define PwmPhaseAndFreqCorrect_ICR1		8
#define PwmPhaseAndFreqCorrect_OCR1A	9
#define PwmPhaseCorrect_ICR1			10
#define PwmPhaseCorrect_OCR1A			11
#define CTC_ICR1						12
#define FastPwm_ICR1					13
#define FastPwm_OCR1A					14

/*Prescalars*/

#define NoClkSource						0
#define NoPrescaling					1
#define Prescaling_8					8
#define Prescaling_64					64
#define Prescaling_256					256
#define Prescaling_1024					1024
#define ExternalClk_Falling_edge		2
#define ExternalClk_Rising_edge			3



/*Compare Output Mode*/

#define NormalPortOperation				0
#define ToggleOnCM						1
#define ClearOnCM						2
#define SetOnCM							3


/*Functions*/

void MTIMER1_voidTimer1Init(void);
void MTIMER1_voidSetPreload(u16 A_u16PreloadValue);
void MTIMER1_voidSetOCR1A(u16 A_u16OCR1AValue);
void MTIMER1_voidSetOCR1B(u16 A_u16OCR1BValue);
void MTIMER1_voidSetICR1(u16 A_u16ICR1Value);
void MTIMER1_voidOvIntEnable(void);
void MTIMER1_voidOCR1AIntEnable(void);
void MTIMER1_voidOCR1BIntEnable(void);
void MTIMER1_voidICUIntEnable(void);
u16 MTIMER1_u16TonCalc(void);
void MTIMER1_voidOvCallBack(void (*ptr)(void));
void MTIMER1_voidOCR1ACallBack(void (*ptr)(void));
void MTIMER1_voidOCR1BCallBack(void (*ptr)(void));
void MTIMER1_voidOCapCallBack(void (*ptr)(void));

#endif /* MCAL_MTIMER1_TIMER1_INTERFACE_H_ */
