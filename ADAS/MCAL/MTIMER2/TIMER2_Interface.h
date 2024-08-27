/*
 * TIMER0_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER2_TIMER2_INTERFACE_H_
#define MCAL_MTIMER2_TIMER2_INTERFACE_H_

/**********MOODS OF TIMER0*************/
/**************************/
#define  Normal_MOOD                      0
#define  PWM_PhaseCorrect_MOOD            1
#define  CTC_MOOD                         2
#define  FAST_PWM_MOOD                    3
/******************/

/********   PRESCALER MOODS   ************/
/***************************/
#define  NO_CLOCK_TIMER2               0
#define  NO_PRESCALER_TIMER2           1
#define  PRESCALER_TIMER2_8            2
#define  PRESCALER_TIMER2_64           3
#define  PRESCALER_TIMER2_256          4
#define  PRESCALER_TIMER2_1024         5
#define  EXT_CLOCK_TIMER2_FALLING      7
#define  EXT_CLOCK_TIMER2_RISING       6
/******************/

/**************************/
/**********Definitions of TIMER0 OC0_PIN*******/
/**************************/
#define  Normal_port_operation             0
#define  Toggle_OC2                        1
#define  Clear_OC2                         2
#define  Set_OC2                           3

/******************/

void TMR2_VoidInit(void);
void TMR2_VoidOVFInterruptEnable(void);
void TMR2_VoidOCMInterruptEnable(void);
void TMR2_VoidSetPreload(u8 A_u8PreLoading_Value);
void TMR2_VoidSetOCMValue(u8 A_u8CompareMatchValue);
void TMR2_OFV_SetCallBack(void(*ptr)(void));
void TMR2_OCM_SetCallBack(void(*ptr)(void));

#endif /* MCAL_MTIMER2_TIMER2_INTERFACE_H_ */
