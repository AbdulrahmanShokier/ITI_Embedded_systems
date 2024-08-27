/*
 * LCD_Config.h
 *
 *  Created on: Aug 4, 2024
 *      Author: DELL
 */

#ifndef HAL_HLCD_LCD_CONFIG_H_
#define HAL_HLCD_LCD_CONFIG_H_

#define LCD_MODE LCD_COM_8BitOperation

#define LCD_DATA_PORT 		DIO_PORTC
#define LCD_CONTROL_PORT 	DIO_PORTB

#define LCD_RS_PIN 			PINB5
#define LCD_RW_PIN			PINB6
#define LCD_E_PIN			PINB7

#define LCD_MaxRowSize 		2
#define LCD_MinRowSize 		1
#define LCD_MaxColSize 		16
#define LCD_MinCloSize 		1


#endif /* HAL_HLCD_LCD_CONFIG_H_ */
