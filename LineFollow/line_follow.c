/*
 * line_follow.c
 *
 *  Created on: Nov 25, 2016
 *      Author: TranQuocSang
 */


#include "../include.h"
#include "line_follow.h"

#define _DEBUG_

#define AVR_SPEED_SET 25
#define SENSOR_CASE 16
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

//* Private function prototype ----------------------------------------------*/
static void pid_process_callback(void);
static void pid_StopTimeout(void);
static TIMER_ID pid_Runtimeout(TIMER_CALLBACK_FUNC CallbackFcn, uint32_t msTime);

//* Private variables -------------------------------------------------------*/
static bool ControlFlag = false;
static uint32_t ui32_msLoop = 0;
static TIMER_ID pid_TimerID = INVALID_TIMER_ID;
static float lineError;
static int32_t avrSpeed;
//** PID Define herez
PID_PARAMETERS pid_line_follow = {.Kp = 0.1, .Kd = 0.0001, .Ki = 0.005,
        .Ts = 0.020, .PID_Saturation = 200, .e_=0, .e__=0, .u_=0};
extern uint32_t calib_white[CHANNEL_NUMBER], calib_black[CHANNEL_NUMBER];
const uint8_t LINE_SENSOR_VALUE[] = {
        0b00011000, // Center

        0b00010000, // Error Left
        0b00110000,
        0b00100000,
        0b01100000,
        0b01000000,
        0b11000000,
        0b10000000,

        0b00001000, //Error right
        0b00001100,
        0b00000100,
        0b00000110,
        0b00000010,
        0b00000011,
        0b00000001,

        0b00000000 //Can't detect line
};

const float error_value[] = {
        0,
        50,
        100,
        150,
        200,
        250,
        300,
        350,
        -50,
        -100,
        -150,
        -200,
        -250,
        -300,
        -350,
        0,
};
/**
 * @brief Init Wall follow controller
 */
static void pid_linefollow_init()
{
    ui32_msLoop =  pid_line_follow.Ts * 1000;
    pid_Runtimeout(&pid_process_callback, ui32_msLoop);

}
/**
 * @brief Init Wall follow controller
 */
void lineFollow_init()
{
    pid_linefollow_init();
    avrSpeed=AVR_SPEED_SET;
}
/**
 * @brief Wall follow controller
 */
static bool pid_wallfollow(float delta_line_sensor, float averageSpeed)
{
    static float error, u;
    int32_t set_speed[2];

    error = -delta_line_sensor;
    u = pid_process(&pid_line_follow,error);

    set_speed[0] = averageSpeed + (int32_t)(u / 2);
    set_speed[1] = averageSpeed - (int32_t)(u / 2);

#ifdef _DEBUG_
    bluetooth_print("Error: %f, Udk: %f, Speed left: %d, Speed right: %d \r\n",error,u,set_speed[0],set_speed[1]);
#endif

    SetPWM(PWM_MOTOR_LEFT, PWM_FREQUENCY, set_speed[1]);
    SetPWM(PWM_MOTOR_RIGHT, PWM_FREQUENCY, set_speed[0]);

    return true;
}

static void pid_process_callback(void)
{
    pid_TimerID = INVALID_TIMER_ID;
    ControlFlag = true;
    pid_Runtimeout(&pid_process_callback, ui32_msLoop);
}


static void pid_StopTimeout(void)
{
    if (pid_TimerID != INVALID_TIMER_ID)
        TIMER_UnregisterEvent(pid_TimerID);
    pid_TimerID = INVALID_TIMER_ID;
}

static TIMER_ID pid_Runtimeout(TIMER_CALLBACK_FUNC CallbackFcn, uint32_t msTime)
{
    pid_StopTimeout();
    pid_TimerID = TIMER_RegisterEvent(CallbackFcn, msTime);
    return pid_TimerID;
}

void pid_linefollow_process(void)
{
    uint8_t sensor_status,i;
    if (ControlFlag)
    {
        pid_Runtimeout(&pid_process_callback, ui32_msLoop);
        ControlFlag = false;

        sensor_status = Line_State();
#ifdef _DEBUG_
        bluetooth_print("Data sensor:"  BYTE_TO_BINARY_PATTERN " \r\n", BYTE_TO_BINARY(sensor_status));
#endif
        for(i=0;i<SENSOR_CASE;i++)
        {
            if (sensor_status == LINE_SENSOR_VALUE[i])
            {
                lineError = error_value[i];
                break;
            }
        }
        pid_wallfollow(lineError, avrSpeed);
    }
}



