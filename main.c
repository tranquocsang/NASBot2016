/**
 *	Raise your ARM 2015 sample code http://raiseyourarm.com/
 *	Author: Pay it forward club
 *	http://www.payitforward.edu.vn
 *  version 0.0.1
 */

/**
 * @file	main.c
 * @brief	main code
 */
#include "include.h"

extern uint32_t calib_white[CHANNEL_NUMBER], calib_black[CHANNEL_NUMBER];
enum calib_color
{
    CALIB_BLACK,
    CALIB_WHITE,
} calib_color;

/** \brief Button left interrupt handler
 *
 */
void ButtonLeftHandler(void)
{
	switch (system_GetState())
	{
		case SYSTEM_INITIALIZE:
			speed_Enable_Hbridge(false);
			system_SetState(SYSTEM_CALIB_SENSOR);
			bluetooth_print("Mode Calib Sensor\n");
            LED1_ON();
            LED2_OFF();
            LED3_OFF();
			break;
		case SYSTEM_CALIB_SENSOR:
			speed_Enable_Hbridge(false);
			bluetooth_print("Save Calib Data\n");
			system_SetState(SYSTEM_GET_MOTOR_MODEL);
			break;
		case SYSTEM_GET_MOTOR_MODEL:
			bluetooth_print("set speed motor\n");
			system_SetState(SYSTEM_ESTIMATE_MOTOR_MODEL);
			speed_Enable_Hbridge(true);
			SetPWM(PWM_MOTOR_LEFT, PWM_FREQUENCY, 20);
			SetPWM(PWM_MOTOR_RIGHT, PWM_FREQUENCY, 20);
			break;
		case SYSTEM_ESTIMATE_MOTOR_MODEL:
			bluetooth_print("Estimate motor\n");
			speed_Enable_Hbridge(false);
			system_SetState(SYSTEM_WAIT_TO_RUN);
			break;
		case SYSTEM_WAIT_TO_RUN:
			bluetooth_print("Mode Wait to run!\n");
			SysCtlDelay(SysCtlClockGet()/3);
			system_SetState(SYSTEM_RUN_SOLVE_MAZE);
			qei_setPosLeft(0);
			qei_setPosRight(0);
		case SYSTEM_RUN_SOLVE_MAZE:
		    speed_Enable_Hbridge(true);
			bluetooth_print("Run Slove Maze\n");
			break;
		default:
			break;
	}
}

/** \brief Button right interrupt handler
 *
 */
void ButtonRightHandler(void)
{
    int i;
	if (system_GetState() == SYSTEM_CALIB_SENSOR)
	{
	    LED2_TOGGLE();
        if(calib_color == CALIB_BLACK){
            Get_Value(calib_black);  // Update calib_black
            for(i=0;i<CHANNEL_NUMBER;i++){
                bluetooth_print("%04d ",calib_black[i]);
            }
            bluetooth_print("\r\n");
            calib_color = CALIB_WHITE;
            bluetooth_print("CALIB_WHITE: ");
        } else if(calib_color == CALIB_WHITE){
            Get_Value(calib_white);  // Update calib_black
            // Print ADC values
            for(i=0;i<CHANNEL_NUMBER;i++){
                bluetooth_print("%04d ",calib_white[i]);
            }
            bluetooth_print("\r\n");
            calib_color = CALIB_BLACK;
            bluetooth_print("CALIB_BLACK: ");
        }
	}
}


void main() {
	system_SetState(SYSTEM_INITIALIZE);
	calib_color = CALIB_WHITE;
	Config_System();
	Timer_Init();
	speed_control_init();
	qei_init(20);
	lineFollow_init();

	LED_Display_init();
	Button_init();
	Enable_Led_Sensor();
	ADC_Init();

	bluetooth_init(115200);
	bluetooth_print("Start!\r\n");


	ButtonRegisterCallback(BUTTON_LEFT, &ButtonLeftHandler);
	ButtonRegisterCallback(BUTTON_RIGHT, &ButtonRightHandler);

	qei_setPosLeft(0);
	qei_setPosRight(0);

	while (1)
	{
		system_Process_System_State();
	}
}
