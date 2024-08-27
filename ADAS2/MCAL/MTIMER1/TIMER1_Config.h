/*
 * TIMER1_Config.h
 *
 *  Created on: Aug 14, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER1_TIMER1_CONFIG_H_
#define MCAL_MTIMER1_TIMER1_CONFIG_H_

/*
 Timer1 Modes:
NormalMode
PwmPhaseCorrect_8
PwmPhaseCorrect_9
PwmPhaseCorrect_10
CTC_OCR1A
PwmFast_8
PwmFast_9
PwmFast_10
PwmPhaseAndFreqCorrect_ICR1
PwmPhaseAndFreqCorrect_OCR1A
PwmPhaseCorrect_ICR1
PwmPhaseCorrect_OCR1A
CTC_ICR1
FastPwm_ICR1
FastPwm_OCR1A
 */

#define Timer1Mode		NormalMode
/*************************************/

/*
 Prescalars:
NoClkSource
NoPrescaling
Prescaling_8
Prescaling_64
Prescaling_256
Prescaling_1024
ExternalClk_Falling_edge
ExternalClk_Rising_edge
 */

#define Timer1Prescaling		NoPrescaling
/**********************************/

/*
 Compare Output Mode:
NormalPortOperation
ToggleOnCM
ClearOnCM
SetOnCM
*/

#define OC1A_CompareMode		ClearOnCM
#define OC1B_CompareMode		NormalPortOperation
/**********************************/
/*System Frequency*/
#define F_Sys	8000000.0
#endif /* MCAL_MTIMER1_TIMER1_CONFIG_H_ */
