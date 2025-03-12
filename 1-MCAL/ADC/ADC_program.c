/***********		Author: Amgad Samir 	**************/
/***********		Layer: NCAL			 	**************/
/***********		Component: ADC	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 26-6/2020		 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

void ADC_voidInit(void)
{
	/*1- Set reference voltage*/
#if ADC_u8_REF_SELECTION==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8_REF_SELECTION== AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8_REF_SELECTION==INTERNAL_2_56v
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "Wrong ADC_u8_REF_SELECTION Configuration"
#endif

	/*activate left adjust result for 8 bit Data*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Set the prescaler configuration*/
	ADCSRA &= PRESCALER_SELECTION_BIT_MASK;
	ADCSRA|=ADC_u8_PRESCALER_SELECTION;

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u16 ADC_u16GetChannelReading(u8 Copy_u8Channel)
{
	/*Set the required channel*/
	ADMUX &= CHANNEL_SELECTION_BIT_MASK;
	ADMUX|=Copy_u8Channel;

	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Busy waiting(polling) until the conversion completes*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/*Clear the interrupt flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADCH;
}
