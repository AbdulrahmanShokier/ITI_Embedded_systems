/*
 * app.h
 *
 *  Created on: Aug 22, 2024
 *      Author: DELL
 */

#ifndef APP_H_
#define APP_H_

#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"

#include "MCAL/MI2C/I2C_int.h"
#include "MCAL/MI2C/I2C_conf.h"
#include "MCAL/MDIO/DIO_Interface.h"
#include "MCAL/MDIO/DIO_Config.h"
#include "MCAL/MGINT/GINT_Interface.h"
#include "MCAL/MGINT/GINT_Config.h"
#include "MCAL/MTIMER0/TIMER0_Interface.h"
#include "MCAL/MTIMER0/TIMER0_Config.h"
#include "MCAL/MTIMER1/TIMER1_Interface.h"
#include "MCAL/MTIMER1/TIMER1_Config.h"
#include "MCAL/MTIMER2/TIMER2_Interface.h"
#include "MCAL/MTIMER2/TIMER2_Config.h"
#include "MCAL/MUART/UART_int.h"
#include "MCAL/MUART/UART_conf.h"

#include "HAL/EXT_EEPROM/EEPROM_init.h"
#include "HAL/EXT_EEPROM/EEPROM_conf.h"

#include "HAL/HKP/KP_Interface.h"
#include "HAL/HKP/KP_Config.h"

#include "HAL/HLCD/LCD_Interface.h"
#include "HAL/HLCD/LCD_Config.h"

#include "HAL/HSVM/SM_Interface.h"
#include "HAL/HSVM/SM_Config.h"

#include "util/delay.h"

extern u8 G_u8PressedValue;
void E2PROMStorePass(void);
void CheckPass(void);
void test(void);
void Time_Count_ClrScreen(void);
void Time_Count_RedLedToggle(void);
void Time_Count_GreenLedToggle(void);
void Time_Count_SVMReturn(void);


#endif /* APP_H_ */
