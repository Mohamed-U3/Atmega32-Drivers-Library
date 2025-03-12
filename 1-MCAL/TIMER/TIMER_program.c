#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;

static void (*ICU_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{

#if TIMER0_WAVE_GENERATION_MODE == NORMAL_MODE

	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);


#elif TIMER0_WAVE_GENERATION_MODE == CTC_MODE

	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

#elif TIMER0_WAVE_GENERATION_MODE == PWM_PHASECORRECT_MODE

	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);


#elif TIMER0_WAVE_GENERATION_MODE == FASTPWM_MODE

	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);


#endif


#if TIMER0_COMPARE_OUTPUT_MODE == FIRST_MODE

	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

#elif TIMER0_COMPARE_OUTPUT_MODE == SECOND_MODE

	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

#elif TIMER0_COMPARE_OUTPUT_MODE == THIRD_MODE

	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#elif TIMER0_COMPARE_OUTPUT_MODE == FOURTH_MODE

	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#endif


#if TIMER0_PRESCALAR == NO_DIV

	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_PRESCALAR == DIV_BY_8

	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_PRESCALAR == DIV_BY_64

	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_PRESCALAR == DIV_BY_256

	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_PRESCALAR == DIV_BY_1024

	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#endif

	SET_BIT(TIMSK,TIMSK_OCIE0);
}

u8 TIMER0_u8ReadTimerValue(void)
{
	return TCNT0;
}

void TIMER0_voidSetTimerValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0=Copy_u8Value;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}

}

void TIMER1_voidInit(void)
{

#if TIMER1_WAVE_GENERATION_MODE == MODE_0

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_1

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_2

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_3

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_4

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_5

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_6

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_7

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_8

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_9

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_10

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_11

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_12

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_14

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#elif TIMER1_WAVE_GENERATION_MODE == MODE_15

	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#endif

#if TIMER1_COMPARE_OUTPUT_MODE == TMR1_FIRST_MODE

	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);

#elif TIMER1_COMPARE_OUTPUT_MODE == TMR1_SECOND_MODE

	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);

#elif TIMER1_COMPARE_OUTPUT_MODE == TMR1_THIRD_MODE

	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#elif TIMER1_COMPARE_OUTPUT_MODE == TMR1_FOURTH_MODE

	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#endif

#if TIMER1_PRESCALAR == TMR1_NO_DIV

	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

#elif TIMER1_PRESCALAR == TMR1_DIV_BY_8

	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

#elif TIMER1_PRESCALAR == TMR1_DIV_BY_64

	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

#elif TIMER1_PRESCALAR == TMR1_DIV_BY_256

	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);

#elif TIMER1_PRESCALAR == TMR1_DIV_BY_1024

	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);

#endif
}

void TIMER2_voidInit(void)
{

#if TIMER2_WAVE_GENERATION_MODE == TMR2_NORMAL_MODE

	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

#elif TIMER2_WAVE_GENERATION_MODE == TMR2_PWM_PHASECORRECT_MODE

	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

#elif TIMER2_WAVE_GENERATION_MODE == TMR2_CTC_MODE

	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#elif TIMER2_WAVE_GENERATION_MODE == TMR2_FASTPWM_MODE

	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#endif

#if TIMER2_COMPARE_OUTPUT_MODE == TMR2_FIRST_MODE

	CLR_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);

#elif TIMER2_COMPARE_OUTPUT_MODE == TMR2_SECOND_MODE

	SET_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);

#elif TIMER2_COMPARE_OUTPUT_MODE == TMR2_THIRD_MODE

	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif TIMER2_COMPARE_OUTPUT_MODE == TMR2_FOURTH_MODE

	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#endif

#if TIMER2_PRESCALAR == TMR2_NO_DIV

	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALAR == TMR2_DIV_BY_8

	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALAR == TMR2_DIV_BY_32

	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALAR == TMR2_DIV_BY_64

	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALAR == TMR2_DIV_BY_128

	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALAR == TMR2_DIV_BY_256

	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALAR == TMR2_DIV_BY_1024

	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#endif
}

void ICU_voidInit(void)
{
	/*Set trigger source to rising edge initially*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Enable input capture interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState=OK;

	if(Copy_u8Edge==ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 ICU_u16ReadInputCapture(void)
{
	return ICR1;
}

u8 ICU_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1=Copy_u16Value;
}

u16 TIMER1_u16ReadTimerValue(void)
{
	return TCNT1;
}

void TIMER1_voidSetTopValue(u16 Copy_u16Value)
{
	ICR1=Copy_u16Value;
}


void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value)
{
	OCR1A=Copy_u16Value;
}





