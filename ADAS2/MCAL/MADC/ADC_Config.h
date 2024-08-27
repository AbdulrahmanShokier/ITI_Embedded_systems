/*
 * ADC_Config.h
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#ifndef MCAL_MADC_ADC_CONFIG_H_
#define MCAL_MADC_ADC_CONFIG_H_
//Select between 8 channels

#define ADC_CHANNEL		ADC_CHANNEL_0
#define ADC_AdjMode		ADC_RIGHT_LEFT
#define ADC_RefVoltage	ADC_AVCC
#define ADC_DivFactor	ADC_64
#define ADC_OuputMode	ADC_BOOLING

#define ADC_ConvMode	ADC_Manual
// in case of automatic convmode
#define ADC_TriggerMode	ADC_FreeRunning


#endif /* MCAL_MADC_ADC_CONFIG_H_ */
