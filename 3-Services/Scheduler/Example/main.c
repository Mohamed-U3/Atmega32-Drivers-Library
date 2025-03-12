/**
* @file    main.c
* @brief   the main code of the prject where the application is witten
* @author  Eng. Mohamed Yousry
* @date    2024-03-08
* @copyright Copyright (c) 2025 Mohamed Yousry. See LICENSE for details.
*/


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO/DIO_interface.h"
#include "GIE/GIE_interface.h"
#include "Scheduler/Scheduler_interface.h"

void Task1();
void Task2();
void Task3();

int main(void)
{
	/* Set the DIO pins as OUTPUT */
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	
	/* Enable of Global Interrupt */
	GIE_voidEnable();
	
	Scheduler_u8CreateTask(0, 1000, 1000, &Task1);
	Scheduler_u8CreateTask(1, 2000, 0, &Task2);
	Scheduler_u8CreateTask(2, 5000, 0, &Task3);
	
	Scheduler_voidInit();
	
	while(1)
	{			}
	return 0;
}

void Task1()
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
		Local_u8Flag = 0;
	}
}

void Task2()
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_LOW);
		Local_u8Flag = 0;
	}
}

void Task3()
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_LOW);
		Local_u8Flag = 0;
	}
}