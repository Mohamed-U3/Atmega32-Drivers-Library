/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: NCAL			 	**************/
/***********		Component: ADC	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 26-6/2020		 	**************/
/*********************************************************/

/*Preprocessor file guard*/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX		*((volatile u8*)0x27)		/*ADC Multiplexer selection register*/
#define ADMUX_REFS1	7							/*reference selection bit1*/
#define ADMUX_REFS0	6							/*reference selection bit0*/
#define ADMUX_ADLAR	5							/*Left Adjust result*/

#define ADCSRA		*((volatile u8*)0x26)		/*ADC control and status regiter*/
#define ADCSRA_ADEN	 7							/*ADC Enable*/
#define ADCSRA_ADSC	 6							/*ADC Start Conversion*/
#define ADCSRA_ADATE 5							/*ADC Auto trigger enable*/
#define ADCSRA_ADIF	 4							/*ADC interrupt flag*/
#define ADCSRA_ADIE	 3							/*ADC interrupt enable*/


#define ADCH		*((volatile u8*)0x25)		/*ADC High data register*/
#define ADCL		*((volatile u8*)0x24)		/*ADC Low data register*/
#define ADC			*((volatile u16*)0x24)		/*ADC data register*/

#define SFIOR		*((volatile u8*)0x50)		/*Special function Input Output register*/

#endif
