/*
 * TIMER1_Private.h
 *
 *  Created on: Aug 14, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER1_TIMER1_PRIVATE_H_
#define MCAL_MTIMER1_TIMER1_PRIVATE_H_

/*TCCR1A PINS*/
#define WGM10  0
#define WGM11  1
#define FOC1B  2
#define FOC1A  3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

/*TCCR1B PINS*/
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

/*TIMSK PINS*/
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1  5

/*TIFR PINS*/
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1  5

#define ICR1_OVF				65535
#define ICR1_RestartCounting	0
#define ICR1_NotCaptured		0
#endif /* MCAL_MTIMER1_TIMER1_PRIVATE_H_ */
