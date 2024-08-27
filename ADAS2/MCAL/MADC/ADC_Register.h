/*
 * ADC_Register.h
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#ifndef MCAL_MADC_ADC_REGISTER_H_
#define MCAL_MADC_ADC_REGISTER_H_

#define ADC_ADMUX		*((volatile u8 *)(0X27))
#define ADC_ADCSRA		*((volatile u8 *)(0X26))
#define ADC_SFIOR		*((volatile u8 *)(0X50))
#define ADC_ADCH		*((volatile u8 *)(0X25))
#define ADC_ADCL		*((volatile u8 *)(0X24))
#define ADC_ADCLH		*((volatile u16 *)(0X24))





#endif /* MCAL_MADC_ADC_REGISTER_H_ */
