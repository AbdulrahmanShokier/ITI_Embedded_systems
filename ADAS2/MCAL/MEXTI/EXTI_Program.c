/*
 * EXTI_Program.c
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "EXTI_Register.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

void (* GP_EXTI0CallBack)(void);
void (* GP_EXTI1CallBack)(void);
void (* GP_EXTI2CallBack)(void);

void MEXTI_voidExtInit(void)
{
#if EXTI0_TriggerMode==EXTI_LOW
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
#elif EXTI0_TriggerMode==EXTI_IOC
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
#elif EXTI0_TriggerMode==EXTI_FallingEdge
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
#elif EXTI0_TriggerMode==EXTI_RisingEdge
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
#endif

#if EXTI1_TriggerMode==EXTI_LOW
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
#elif EXTI1_TriggerMode==EXTI_IOC
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
#elif EXTI1_TriggerMode==EXTI_FallingEdge
	clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
#elif EXTI1_TriggerMode==EXTI_RisingEdge
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
#endif

#if EXTI2_TriggerMode==EXTI_FallingEdge
	clear_bit(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);
#elif EXTI2_TriggerMode==EXTI_FallingEdge
	set_bit(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);
#endif


}
void MEXTI_voidExtEnable(u8 A_u8ExtiNum)
{
	switch(A_u8ExtiNum)
	{
	case EXTI_EXTI0:set_bit(EXTI_GICR,EXTI_GICR_INT0);break;
	case EXTI_EXTI1:set_bit(EXTI_GICR,EXTI_GICR_INT1);break;
	case EXTI_EXTI2:set_bit(EXTI_GICR,EXTI_GICR_INT2);break;
	default:break;
	}
}
void MEXTI_voidExtDisable(u8 A_u8ExtiNum)
{
	switch(A_u8ExtiNum)
	{
	case EXTI_EXTI0:clear_bit(EXTI_GICR,EXTI_GICR_INT0);break;
	case EXTI_EXTI1:clear_bit(EXTI_GICR,EXTI_GICR_INT1);break;
	case EXTI_EXTI2:clear_bit(EXTI_GICR,EXTI_GICR_INT2);break;
	default:break;
	}
}

void MEXTI_voidExt0CallBack(void (*ptr)(void))
{
	GP_EXTI0CallBack=ptr;
}
void MEXTI_voidExt1CallBack(void (*ptr)(void))
{
	GP_EXTI1CallBack=ptr;
}
void MEXTI_voidExt2CallBack(void (*ptr)(void))
{
	GP_EXTI2CallBack=ptr;
}

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_1 (void){
	GP_EXTI0CallBack();
}

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_2 (void){
	GP_EXTI1CallBack();
}

void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_3 (void){
	GP_EXTI2CallBack();
}
