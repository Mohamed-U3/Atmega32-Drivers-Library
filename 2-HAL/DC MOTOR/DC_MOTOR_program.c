#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_interface.h"


void DC_MOTOR_voidCW(void)
{
  DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_u8PIN_LOW);
  DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,DIO_u8PIN_HIGH);

}
void DC_MOTOR_voidCCW(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_u8PIN_HIGH);

}
