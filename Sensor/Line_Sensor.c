/*
 * Line_Sensor.c
 *
 *  Created on: Nov 15, 2016
 *      Author: TranQuocSang
 */

#include "../include.h"

uint32_t calib_white[CHANNEL_NUMBER], calib_black[CHANNEL_NUMBER];
uint32_t raw_ADC[CHANNEL_NUMBER];

void ADC_Init()
{
    // ADC
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);        // ADC_IN: PD0,1,2,3 - AIN7,6,5,4
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);        // ADC_IN: PE0,1,2,3 - AIN3,2,1,0

    ADCHardwareOversampleConfigure(ADC0_BASE, 64);

    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);           //SS0: Depth 8
    ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH1);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH2);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH3);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 4, ADC_CTL_CH4);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 5, ADC_CTL_CH5);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 6, ADC_CTL_CH6);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 7, ADC_CTL_CH7 | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 0);
}

void Get_Value(uint32_t * adc_raw)
{
    ADCIntClear(ADC0_BASE, 0);                  // Reset ADC Interrupt Flag
    ADCProcessorTrigger(ADC0_BASE, 0);          // Start new ADC cycle
    while(!ADCIntStatus(ADC0_BASE, 0, false)){} // Wait for Conversion
    ADCSequenceDataGet(ADC0_BASE, 0, adc_raw);  // Update calib_black
}

uint8_t Line_State()
{
    uint8_t sensor_state;
    int i;
    ADCIntClear(ADC0_BASE, 0);                  // Reset ADC Interrupt Flag
    ADCProcessorTrigger(ADC0_BASE, 0);          // Start new ADC cycle
    while(!ADCIntStatus(ADC0_BASE, 0, false)){} // Wait for Conversion
    ADCSequenceDataGet(ADC0_BASE, 0, raw_ADC);  // Update ADC buffer

    for(i=0;i<CHANNEL_NUMBER;i++) {
        if(raw_ADC[i] < (calib_white[i]+DELTA)){
            sensor_state |= (1<<i);
        }
        else {
            sensor_state &= ~(1<<i);
        }
    }
    return sensor_state;
}

void Enable_Led_Sensor()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);
}


