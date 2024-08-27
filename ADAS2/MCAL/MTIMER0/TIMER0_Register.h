/*
 * TIMER0_Register.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER0_TIMER0_REGISTER_H_
#define MCAL_MTIMER0_TIMER0_REGISTER_H_

#define	TIMER0_TCNT0	*((volatile u8 *)(0x52))
#define	TIMER0_TCCR0	*((volatile u8 *)(0x53))
#define	TIMER0_TIFR		*((volatile u8 *)(0x58))
#define	TIMER0_TIMSK	*((volatile u8 *)(0x59))
#define	TIMER0_OCR0		*((volatile u8 *)(0x5C))

#endif /* MCAL_MTIMER0_TIMER0_REGISTER_H_ */
