/*
 * EXTI_Register.h
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#ifndef MCAL_MEXTI_EXTI_REGISTER_H_
#define MCAL_MEXTI_EXTI_REGISTER_H_

#define EXTI_MCUCR	*((volatile u8 *)(0X55))
#define EXTI_MCUCSR	*((volatile u8 *)(0X54))
#define EXTI_GICR	*((volatile u8 *)(0X5B))
#define EXTI_GIFR	*((volatile u8 *)(0X5A))


#endif /* MCAL_MEXTI_EXTI_REGISTER_H_ */
