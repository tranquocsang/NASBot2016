/*
 * Line_Sensor.h
 *
 *  Created on: Nov 15, 2016
 *      Author: TranQuocSang
 */

#ifndef LINE_SENSOR_H_
#define LINE_SENSOR_H_

#define CHANNEL_NUMBER      8
#define DELTA               80


void ADC_Init();
void Get_Value(uint32_t * adc_raw);
uint8_t Line_State();
void Enable_Led_Sensor();

#endif /* LINE_SENSOR_H_ */
