/***********		Author: Amgad Samir 	**************/
/***********		Layer: NCAL			 	**************/
/***********		Component: ADC	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 26-6/2020		 	**************/
/*********************************************************/

/*Preprocessor file guard*/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AVCC							1
#define AREF							2
#define INTERNAL_2_56v					3

#define PRESCALER_SELECTION_BIT_MASK	0b11111000
#define DIVIDE_BY_2						1
#define DIVIDE_BY_4						2
#define DIVIDE_BY_8						3
#define DIVIDE_BY_16					4
#define DIVIDE_BY_32					5
#define DIVIDE_BY_64					6
#define DIVIDE_BY_128					7

#define CHANNEL_SELECTION_BIT_MASK		0b11100000

#endif
