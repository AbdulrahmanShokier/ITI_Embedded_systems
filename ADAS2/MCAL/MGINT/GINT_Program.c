/*
 * GINT_Program.c
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "GINT_Register.h"
#include "GINT_Interface.h"
#include "GINT_Private.h"
#include "GINT_Config.h"

void MGINT_voidGlobalIntEnable(void)
{
	set_bit(GINT_SREG,GINT_GieBit);
}
void MGINT_voidGlobalIntDisable(void)
{
	clear_bit(GINT_SREG,GINT_GieBit);
}
