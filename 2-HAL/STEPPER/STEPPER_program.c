#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "STEPPER_interface.h"
#include "STEPPER_congif.h"
#include <util/delay.h>


// IN CASE FULL STEP ANGEL

void Stepper_u8CW(void)
{

	u8 COUNTER =0 ;
	DIO_u8SetPortDirection(STEPPER_U8PORT ,DIO_u8PORT_OUTPUT);
	for (COUNTER=0 ; COUNTER<250 ; COUNTER ++)
	{



		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2.5);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2.5);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2.5);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_HIGH);

		_delay_ms(2.5);



	}


}



void Stepper_u8ACW(void)
{

	u8 COUNTER =0 ;
	DIO_u8SetPortDirection(STEPPER_U8PORT ,DIO_u8PORT_OUTPUT);
	for (COUNTER=0 ; COUNTER<250 ; COUNTER ++)
	{


		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_HIGH);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);


	}

}

void Stepper_u8Degree_CW(u16 degree)
{

	u16 COUNTER =0 ;
	u16 NUM_STEPS ;

	DIO_u8SetPortDirection(STEPPER_U8PORT ,DIO_u8PORT_OUTPUT);

	NUM_STEPS = ((degree /0.175)/4);

	for (COUNTER=0 ; COUNTER<=NUM_STEPS ; COUNTER ++)
	{

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_HIGH);

		_delay_ms(2);



	}

}


void Stepper_u8Degree_ACW(f32 degree)
{
	u8 COUNTER =0 ;
	u16 NUM_STEPS ;

	DIO_u8SetPortDirection(STEPPER_U8PORT ,DIO_u8PORT_OUTPUT);

	NUM_STEPS = ((degree /0.175)/4);


	for (COUNTER=0 ; COUNTER<=NUM_STEPS ; COUNTER ++)
	{


		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_HIGH);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_U8PORT,STEPPER_U8PIN3,DIO_u8PIN_LOW);

		_delay_ms(2);

	}
}

