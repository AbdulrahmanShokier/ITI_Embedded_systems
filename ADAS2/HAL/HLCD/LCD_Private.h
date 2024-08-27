/*
 * LCD_Private.h
 *
 *  Created on: Aug 4, 2024
 *      Author: DELL
 */

#ifndef HAL_HLCD_LCD_PRIVATE_H_
#define HAL_HLCD_LCD_PRIVATE_H_

#define LCD_COM_ClearDisplay			0X01
#define LCD_COM_ReturnHome				0X02
#define LCD_COM_EntryMode				0X06
#define LCD_COM_DisplayOn_CursorOff		0X0C
#define LCD_COM_DisplayOff_CursorOn		0X0A
#define LCD_COM_DisplayOn_CursorOn		0X0E
#define LCD_COM_DisplayOff_CursorOff	0X08
#define LCD_COM_CursorShl				0X10
#define LCD_COM_CursorShr				0X14
#define LCD_COM_DisplayShl				0X18
#define LCD_COM_DisplayShr				0X1C
#define LCD_COM_8BitOperation			0X38
#define LCD_COM_4BitOperation			0X28

#define LCD_FirstRowStart				0X80
#define LCD_SecondRowStart				0XC0

#define LCD_CgromStartAddress			0X40
#define LCD_CgromMaxBlockNumber			8
#define LCD_MinPixelsRowNo				0
#define LCD_MaxPixelsRowNo				8
#endif /* HAL_HLCD_LCD_PRIVATE_H_ */
