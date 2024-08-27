/*
 * TIMER2_Register.h
 *
 *  Created on: Aug 11, 2024
 *      Author: DELL
 */

#ifndef MCAL_MTIMER2_TIMER2_REGISTER_H_
#define MCAL_MTIMER2_TIMER2_REGISTER_H_

#define	TIMER2_TCNT2	*((volatile u8 *)(0x44))
#define	TIMER2_TCCR2	*((volatile u8 *)(0x45))
#define	TIMER2_TIFR		*((volatile u8 *)(0x58))
#define	TIMER2_TIMSK	*((volatile u8 *)(0x59))
#define	TIMER2_OCR2		*((volatile u8 *)(0x43))

#endif /* MCAL_MTIMER2_TIMER2_REGISTER_H_ */
