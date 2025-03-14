#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

//							/************************************/
							/********* TIMER0 Configration ******/
							/************************************/

/*Choose TIMER0 wave generation mode*/
/* You can choose from [ NORMAL_MODE - PWM_PHASECORRECT_MODE - CTC_MODE - FASTPWM_MODE ]*/
#define TIMER0_WAVE_GENERATION_MODE  CTC_MODE

/*Choose TIMER0 compare output mode*/
#define TIMER0_COMPARE_OUTPUT_MODE   THIRD_MODE

/*Choose TIMER0 PRESCALAR*/
#define TIMER0_PRESCALAR             DIV_BY_8


//							/************************************/
							/********* TIMER1 Configration ******/
							/************************************/

/*Choose TIMER1 wave generation mode*/
#define TIMER1_WAVE_GENERATION_MODE  MODE_14

/*Choose TIMER1 compare output mode*/
#define TIMER1_COMPARE_OUTPUT_MODE   TMR1_THIRD_MODE

/*Choose TIMER1 PRESCALAR*/
#define TIMER1_PRESCALAR             TMR1_DIV_BY_8


//							/************************************/
							/********* TIMER2 Configration ******/
							/************************************/

/*Choose TIMER2 wave generation mode*/
#define TIMER2_WAVE_GENERATION_MODE  TMR2_NORMAL_MODE

/*Choose TIMER2 compare output mode*/
#define TIMER2_COMPARE_OUTPUT_MODE   TMR2_FIRST_MODE

/*Choose TIMER2 PRESCALAR*/
#define TIMER2_PRESCALAR             TMR2_NO_DIV

#endif
