/*********************************************************/
/***********		Author: khaled elnaggar 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: STEPPER MOTOR 		**************/
/***********		Version: 1.00		 	**************/
/*********************************************************/

#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

void Stepper_u8CW(void);

void Stepper_u8ACW(void);

void Stepper_u8Degree_CW(u16 degree);

void Stepper_u8Degree_ACW(f32 degree);

#define STEPPER_U8PORT     DIO_u8PORTB

#define STEPPER_U8PIN0     DIO_u8PIN0
#define STEPPER_U8PIN1     DIO_u8PIN1
#define STEPPER_U8PIN2    DIO_u8PIN2
#define STEPPER_U8PIN3     DIO_u8PIN3

#endif
