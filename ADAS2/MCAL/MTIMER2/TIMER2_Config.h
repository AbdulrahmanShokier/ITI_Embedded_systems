/*
 * TIMER0_Config.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER2_TIMER2_CONFIG_H_
#define MCAL_MTIMER2_TIMER2_CONFIG_H_
/**************************/
/**********MOODS OF TIMER2*************/
/**************************/
/* OPTIONS
 * Normal_MOOD
 * CTC_MOOD
 * PWM_PhaseCorrect_MOOD
 * FAST_PWM_MOOD
 */
/******************/
#define TIMER2_Mood          CTC_MOOD
/******************/

/********   PRESCALER MOODS   ************/
/***************************/
/* OPTIONS
 * NO_CLOCK_TIMER0
 * NO_PRESCALER_TIMER0
 * PRESCALER_TIMER0_8
 * PRESCALER_TIMER0_64
 * PRESCALER_TIMER0_256
 * PRESCALER_TIMER0_1024
 * EXT_CLOCK_TIMER0_FALLING
 * EXT_CLOCK_TIMER0_RISING
 */
/******************/
#define Prescaler_Mood         PRESCALER_TIMER0_64
/*******************/


/**********Definitions of TIMER0 OC0_PIN*******/
/**************************/
/* OPTIONS
 * Normal_port_operation
 * Toggle_OC2
 * Clear_OC2
 * Set_OC2
 * Reserved
*/
/******************/
//Hint -> You Can't Select Toggle Mode When Using Pwm Modes (It Will Do Nothing)
#define OC2_MOOD         Normal_port_operation
/******************/


#endif /* MCAL_MTIMER2_TIMER2_CONFIG_H_ */
