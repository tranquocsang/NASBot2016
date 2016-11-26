/*
 * Line_Sensor.c
 *
 *  Created on: Nov 15, 2016
 *      Author: TranQuocSang
 */

#include "../include.h"
#include "speed_control.h"
#define _DEBUG_SPEED_

//* Private function prototype ----------------------------------------------*/
static void Config_PWM(void);
//* Private variables -------------------------------------------------------*/
uint32_t ui32Load;
uint32_t ui32PWMClock;

void speed_control_init(void)
{
	Config_PWM();
	SetPWM(PWM_MOTOR_LEFT, PWM_FREQUENCY, 0);
	SetPWM(PWM_MOTOR_RIGHT, PWM_FREQUENCY, 0);
}

static void Config_PWM(void)
{
    // PWM
    SysCtlPWMClockSet(SYSCTL_PWMDIV_1);             // PWM Clock = SystemCLK/1
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);        // PWM Channel: PA6,7

    // PWM Configuration
    ui32PWMClock = 80000000;    // Calculate PWM clock
    ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;

    // 2 PWM channels: PA6, PA7 (module 1, generator 1)
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6);
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_7);

    GPIOPinConfigure(GPIO_PA6_M1PWM2);
    GPIOPinConfigure(GPIO_PA7_M1PWM3);


    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, ui32Load);

    PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
    PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true);

    PWMGenEnable(PWM1_BASE, PWM_GEN_1);

    //======================================//

	ROM_SysCtlPeripheralEnable(DRV_ENABLE_LEFT_CHN_PERIPHERAL);
	ROM_SysCtlPeripheralEnable(DRV_ENABLE_RIGHT_CHN_PERIPHERAL);
	ROM_GPIOPinTypeGPIOOutput(DRV_ENABLE_LEFT_CHN_PORT, DRV_ENABLE_LEFT_CHN_PIN);
	ROM_GPIOPinTypeGPIOOutput(DRV_ENABLE_RIGHT_CHN_PORT, DRV_ENABLE_RIGHT_CHN_PIN);
	ROM_GPIOPinWrite(DRV_ENABLE_LEFT_CHN_PORT, DRV_ENABLE_LEFT_CHN_PIN, 0);
	ROM_GPIOPinWrite(DRV_ENABLE_RIGHT_CHN_PORT, DRV_ENABLE_RIGHT_CHN_PIN, 0);
}

/**
 * @brief Control Hbridge
 */
void speed_Enable_Hbridge(bool Enable)
{
	if (Enable)
	{
		ROM_GPIOPinWrite(DRV_ENABLE_LEFT_CHN_PORT, DRV_ENABLE_LEFT_CHN_PIN, DRV_ENABLE_LEFT_CHN_PIN);
		ROM_GPIOPinWrite(DRV_ENABLE_RIGHT_CHN_PORT, DRV_ENABLE_RIGHT_CHN_PIN, DRV_ENABLE_RIGHT_CHN_PIN);
	}
	else
	{
		ROM_GPIOPinWrite(DRV_ENABLE_LEFT_CHN_PORT, DRV_ENABLE_LEFT_CHN_PIN, 0);
		ROM_GPIOPinWrite(DRV_ENABLE_RIGHT_CHN_PORT, DRV_ENABLE_RIGHT_CHN_PIN, 0);
	}
}

void SetPWM(uint32_t ulBaseAddr, uint32_t ulTimer, uint32_t ulFrequency, int32_t ucDutyCycle)
{
	if (ucDutyCycle > 90)
		ucDutyCycle = 90;
	else if (ucDutyCycle < -90)
		ucDutyCycle = -90;
	PWMPulseWidthSet(ulBaseAddr, ulTimer, (100 + ucDutyCycle) * ui32Load / 200);
}
