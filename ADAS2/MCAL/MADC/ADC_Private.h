/*
 * ADC_Private.h
 *
 *  Created on: Aug 10, 2024
 *      Author: DELL
 */

#ifndef MCAL_MADC_ADC_PRIVATE_H_
#define MCAL_MADC_ADC_PRIVATE_H_

#define ADC_ADMUX_ADLAR		5
#define ADC_ADMUX_REFS0		6
#define ADC_ADMUX_REFS1		7

#define ADC_ADCSRA_ADPS0	0
#define ADC_ADCSRA_ADPS1	1
#define ADC_ADCSRA_ADPS2	2
#define ADC_ADCSRA_ADIE		3
#define ADC_ADCSRA_ADIF		4
#define ADC_ADCSRA_ADATE	5
#define ADC_ADCSRA_ADSC		6
#define ADC_ADCSRA_ADEN		7

#define ADC_SFIOR_ADTS0		5
#define ADC_SFIOR_ADTS1		6
#define ADC_SFIOR_ADTS2		7

#define ADC_ChannelStart 0b11100000




#endif /* MCAL_MADC_ADC_PRIVATE_H_ */
