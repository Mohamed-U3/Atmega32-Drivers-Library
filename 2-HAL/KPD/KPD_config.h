/*********************************************************/
/***********		Author: khaled elnaggar 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: KEYPAD 		**************/
/***********		Version: 1.00		 	**************/
/*********************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_port          DIO_u8PORTD

#define KPD_COLMN0_PIN    DIO_u8PIN0
#define KPD_COLMN1_PIN    DIO_u8PIN1
#define KPD_COLMN2_PIN    DIO_u8PIN2
#define KPD_COLMN3_PIN    DIO_u8PIN3


#define KPD_ROW0_PIN    DIO_u8PIN4
#define KPD_ROW1_PIN    DIO_u8PIN5
#define KPD_ROW2_PIN    DIO_u8PIN6
#define KPD_ROW3_PIN    DIO_u8PIN7

#define KPD_NO_PRESSED_KEY    0xff

#define KPD_ARR_VAL          {{'+',1,2,3},{'-',4,5,6},{'*',7,8,9},{'/',0,'.','='}}




#endif
