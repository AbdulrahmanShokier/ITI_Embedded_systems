/*
 * LCD_Interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: DELL
 */

#ifndef HAL_HLCD_LCD_INTERFACE_H_
#define HAL_HLCD_LCD_INTERFACE_H_


#define LCD_ROW1	1
#define LCD_ROW2 	2

#define LCD_COL1 	1
#define LCD_COL2 	2
#define LCD_COL3 	3
#define LCD_COL4 	4
#define LCD_COL5 	5
#define LCD_COL6 	6
#define LCD_COL7 	7
#define LCD_COL8 	8
#define LCD_COL9 	9
#define LCD_COL10 	10
#define LCD_COL11 	11
#define LCD_COL12 	12
#define LCD_COL13 	13
#define LCD_COL14 	14
#define LCD_COL15 	15
#define LCD_COL16 	16

#define LCD_CgramBlock1		0
#define LCD_CgramBlock2		1
#define LCD_CgramBlock3		2
#define LCD_CgramBlock4		3
#define LCD_CgramBlock5		4
#define LCD_CgramBlock6		5
#define LCD_CgramBlock7		6
#define LCD_CgramBlock8		7


void HLCD_voidInit(void);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidSendCom(u8 A_u8Command);
void HLCD_voidSendString(u8 *A_Pu8String);
void HLCD_voidSetCursor_DDRAM(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidSendSpecial(u8 * A_u8PSpecialChar ,u8 A_u8BlockNum,u8 A_u8RowNum,u8 A_u8ColNum);
#endif /* HAL_HLCD_LCD_INTERFACE_H_ */
