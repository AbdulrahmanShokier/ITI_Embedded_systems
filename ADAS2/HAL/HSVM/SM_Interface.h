/*
 * SM_Interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: DELL
 */

#ifndef HAL_HSERVOMOTOR_SM_INTERFACE_H_
#define HAL_HSERVOMOTOR_SM_INTERFACE_H_

#define SV_Period_Value		((20*0.001)/((f32)Timer1Prescaling/8000000.0))-1

void HServoMotor(f32 A_f32Angle);
#endif /* HAL_HSERVOMOTOR_SM_INTERFACE_H_ */
