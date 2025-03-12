
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGotoXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition)
{
	u8 Local_u8Addres;

	if(Copy_u8Xposition==0)
	{
		Local_u8Addres=Copy_u8Yposition;
	}
	if(Copy_u8Xposition==1)
	{
		Local_u8Addres=Copy_u8Yposition+0x40;

	}
	CLCD_voidSendCommand(Local_u8Addres+128);



}

void CLCD_voidWritenumber(u32 Copy_u32Number)
{
	u32 Local_u32Number=Copy_u32Number;
	u32 Local_u32Number2=Local_u32Number;
	u32 Local_u32reminder;
	u8 Local_u32counter =0;
	s8 s ;
    u8 Local_u32counter2;

if(Copy_u32Number==0) {

 CLCD_voidSendData('0');
}
else {
	while(Local_u32Number2!=0)
	{
		Local_u32Number2=Local_u32Number2/10;
		Local_u32counter++;
	}
    u8 arr[Local_u32counter];

    //static u8* ptr=arr;
    //ptr=arr;



	//Local_u32counter2 =Local_u32counter ;

	for (s=0 ; s<Local_u32counter  ;s++)
	{
		Local_u32reminder= Local_u32Number%10 ;
		arr[s]=Local_u32reminder;
		Local_u32Number=Local_u32Number/10;
        //ptr++;

	}




	for(s=Local_u32counter-1;s>=0;s--){

		CLCD_voidSendData(arr[s]+48);
	}


/*
	u8 LOCAL_STATE_EROOR=0 ;
	if (Local_u32Number==0)
	{

		CLCD_voidSendData('0');
	}


	else
	{


	for (s=ptr ; s<Local_u32counter2  ;s++)
	{
	switch(ptr[s])
	{

	case 0 : CLCD_voidSendData('0'); break;
	case 1 : CLCD_voidSendData('1'); break;
	case 2: CLCD_voidSendData('2'); break;
	case 3 : CLCD_voidSendData('3'); break;
	case 4 : CLCD_voidSendData('4'); break;
	case 5 : CLCD_voidSendData('5'); break;
	case 6 : CLCD_voidSendData('6'); break;
	case 7 : CLCD_voidSendData('7'); break;
	case 8 : CLCD_voidSendData('8'); break;
	case 9 : CLCD_voidSendData('9'); break;
	default : LOCAL_STATE_EROOR =1 ; break;



	}
			}*/
	}
}






