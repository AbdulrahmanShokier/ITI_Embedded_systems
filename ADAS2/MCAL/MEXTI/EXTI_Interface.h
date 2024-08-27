/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#ifndef MCAL_MEXTI_EXTI_INTERFACE_H_
#define MCAL_MEXTI_EXTI_INTERFACE_H_

#define EXTI_LOW	0
#define EXTI_IOC	1
#define EXTI_FallingEdge	2
#define EXTI_RisingEdge		3

#define EXTI_EXTI0		0
#define EXTI_EXTI1		1
#define EXTI_EXTI2		2


void MEXTI_voidExtInit(void);
void MEXTI_voidExtEnable(u8 A_u8ExtiNum);
void MEXTI_voidExtDisable(u8 A_u8ExtiNum);
void MEXTI_voidExt0CallBack(void (*ptr)(void));
void MEXTI_voidExt1CallBack(void (*ptr)(void));
void MEXTI_voidExt2CallBack(void (*ptr)(void));



#endif /* MCAL_MEXTI_EXTI_INTERFACE_H_ */
