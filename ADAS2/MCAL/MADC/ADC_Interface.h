/*
 * ADC_Interface.h
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#ifndef MCAL_MADC_ADC_INTERFACE_H_
#define MCAL_MADC_ADC_INTERFACE_H_

#define ADC_CHANNEL_0	0
#define ADC_CHANNEL_1	1
#define ADC_CHANNEL_2	2
#define ADC_CHANNEL_3	3
#define ADC_CHANNEL_4	4
#define ADC_CHANNEL_5	5
#define ADC_CHANNEL_6	6
#define ADC_CHANNEL_7	7

#define ADC_RIGHT_LEFT 	0
#define ADC_LEFT_RIGHT	1

#define ADC_AVCC		1
#define ADC_AREF		0
#define ADC_IntVoltage	3

#define ADC_2			0
#define ADC_4			1
#define ADC_8			2
#define ADC_16			3
#define ADC_32			4
#define ADC_64			5
#define ADC_128			6

#define ADC_BOOLING		0
#define ADC_INTERRUPT	1

#define ADC_Manual		0
#define ADC_Automatic	1
#define ADC_FreeRunning 0
#define ADC_AnalogComp  1
#define ADC_EXTI0		2
#define ADC_CompMatchA  3
#define ADC_Overflow0	4
#define ADC_CompMatchB 	5
#define ADC_Overflow1	6
#define ADC_CaptureEvent 7
void MADC_voidInit(void);
void MADC_voidStartConv(void);
u16 MADC_u16ReadOut(void);
void MADC_voidAdcCallBack(void (*PTR)(void));


#endif /* MCAL_MADC_ADC_INTERFACE_H_ */
