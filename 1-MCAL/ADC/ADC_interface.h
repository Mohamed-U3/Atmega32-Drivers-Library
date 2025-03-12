/***********		Author: Amgad Samir 	**************/
/***********		Layer: NCAL			 	**************/
/***********		Component: ADC	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 26-6/2020		 	**************/
/*********************************************************/

/*Preprocessor file guard*/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


void ADC_voidInit(void);

u16 ADC_u16GetChannelReading(u8 Copy_u8Channel);

#endif