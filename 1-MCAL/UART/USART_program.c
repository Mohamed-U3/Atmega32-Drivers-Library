/*
 * USART_program.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Adel
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_register.h"
#include "USART_inteerface.h"

void USART_voidInit(void)
{
 u8 Local_u8UCSRCValue=0;                  // TO WRITE VALUES ON UCSRC
 SET_BIT(Local_u8UCSRCValue,7);



 CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);     // Asynchronous UART

 // SELECT PARITY DISABLE
 CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
 CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);

 CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);     //SELECT ONE STOP BIT

 // 8 BIT DATA SIZE
 SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
 SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);

 UCSRC=Local_u8UCSRCValue;

 //SETTING BAUD RATE
 //CLR_BIT(UCSRA,UCSRA_U2X)
 UBRRL=51;

 //ENABLE RX AND TX
 SET_BIT(UCSRB,UCSRB_TXEN);
 SET_BIT(UCSRB,UCSRB_RXEN);
}


u8 USART_voidRecieveData(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}

void USART_voidSend(u8 copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE==0));
	UDR=copy_u8Data;

}

