/*
 * Line_Sensor.c
 *
 *  Created on: Nov 15, 2016
 *      Author: TranQuocSang
 */


#ifndef STR_SPEED_CONTROL_H_
#define STR_SPEED_CONTROL_H_

#define PWM_MOTOR_LEFT			PWM1_BASE, PWM_OUT_3
#define PWM_MOTOR_RIGHT			PWM1_BASE, PWM_OUT_2
#define PWM_FREQUENCY       20000

typedef enum
{
	MOTOR_LEFT = 0,
	MOTOR_RIGHT
} MOTOR_SELECT;

extern void speed_control_init(void);
extern void speed_Enable_Hbridge(bool Enable);
void SetPWM(uint32_t ulBaseAddr, uint32_t ulTimer, uint32_t ulFrequency, int32_t ucDutyCycle);

#endif /* STR_SPEED_CONTROL_H_ */
