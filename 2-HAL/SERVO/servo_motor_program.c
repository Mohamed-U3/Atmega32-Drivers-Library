/*
 * servo_motor_program.c
 *
 *  Created on: May 8, 2024
 *      Author: RD14
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "servo_motor_interface.h"
#include <util/delay.h>






//-90 1ms 0 1.5ms +90 2ms
//8Mhz/8 1Tick = 1us

//	TIMER1_voidSetChannelACompMatchValue(500);//-90 degree

void servo_on(void)
{
	TIMER1_voidSetChannelACompMatchValue(2500);// 90 degree
	_delay_ms(1500);

}
void servo_off(void)
{
	TIMER1_voidSetChannelACompMatchValue(1500);//0 degree
	_delay_ms(1500);
}
