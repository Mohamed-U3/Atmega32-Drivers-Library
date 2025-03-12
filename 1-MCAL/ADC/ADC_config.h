/***********		Author: Amgad Samir 	**************/
/***********		Layer: NCAL			 	**************/
/***********		Component: ADC	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 26-6/2020		 	**************/
/*********************************************************/

/*Preprocessor file guard*/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*options:  1- AREF
 * 			2- AVCC
 * 			3- INTERNAL_2_56v
 * */
#define ADC_u8_REF_SELECTION	AVCC

/*options:	1-DIVIDE_BY_2
 * 			2-DIVIDE_BY_4
 * 			3-DIVIDE_BY_8
 * 			4-DIVIDE_BY_16
 * 			5-DIVIDE_BY_32
 * 			6-DIVIDE_BY_64
 * 			7-DIVIDE_BY_128
 * */
#define ADC_u8_PRESCALER_SELECTION 	DIVIDE_BY_128


#endif
