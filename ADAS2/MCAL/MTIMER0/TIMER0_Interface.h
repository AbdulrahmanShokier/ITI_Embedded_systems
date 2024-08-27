/*
 * TIMER0_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER0_TIMER0_INTERFACE_H_
#define MCAL_MTIMER0_TIMER0_INTERFACE_H_

/**********MOODS OF TIMER0*************/
/**************************/
#define  Normal_MOOD                      0
#define  PWM_PhaseCorrect_MOOD            1
#define  CTC_MOOD                         2
#define  FAST_PWM_MOOD                    3
/******************/

/********   PRESCALER MOODS   ************/
/***************************/
#define  NO_CLOCK_TIMER0               0
#define  NO_PRESCALER_TIMER0           1
#define  PRESCALER_TIMER0_8            2
#define  PRESCALER_TIMER0_64           3
#define  PRESCALER_TIMER0_256          4
#define  PRESCALER_TIMER0_1024         5
#define  EXT_CLOCK_TIMER0_FALLING      7
#define  EXT_CLOCK_TIMER0_RISING       6
/******************/

/**************************/
/**********Definitions of TIMER0 OC0_PIN*******/
/**************************/
#define  Normal_port_operation             0
#define  Toggle_OC0                        1
#define  Clear_OC0                         2
#define  Set_OC0                           3

/******************/

void TMR0_VoidInit(void);
void TMR0_VoidOVFInterruptEnable(void);
void TMR0_VoidOCMInterruptEnable(void);
void TMR0_VoidOVFInterruptDisable(void);
void TMR0_VoidOCMInterruptDisable(void);
void TMR0_VoidSetPreload(u8 A_u8PreLoading_Value);
void TMR0_VoidSetOCMValue(u8 A_u8CompareMatchValue);
void TMR0_OFV_SetCallBack(void(*ptr)(void));
void TMR0_OCM_SetCallBack(void(*ptr)(void));
void TMR2_VoidOVFInterruptDisable(void);
void TMR2_VoidOCMInterruptDisable(void);

#endif /* MCAL_MTIMER0_TIMER0_INTERFACE_H_ */
