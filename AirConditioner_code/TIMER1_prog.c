/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	TIMER			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TIMER1_interface.h"
#include "TIMER1_register.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"


/**
 * Function: PWM_Init()
 /**
 *Description:  is used to select the source of clock for PWM and PWM mode
 *
 *PRECONDTION: must configure the clock source in TIMER1_config.h
 *PRECONDTION: must configure PWM_MODE in TIMER1_config.h
 *PRECONDTION: must configure PWM_CHANNEL  in TIMER1_config.h
 *PRECONDTION: must configure COMPARE OUT MODE  in TIMER1_config.h
 *
 *
 *POSTCONDTION: The clock source of PWM is configured
 *POSTCONDTION: Mode of PWM is configured
 *POSTCONDTION: PWM_CHANNEL is configured
 *POSTCONDTION: Compare out mode is configured
 *
 *
 *@param none
 *
 *@return void
 */
void PWM_Init(void){

	/*Choose the mode of PWM */

#if PWM_MODE == FAST_PWM_8Bit
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif PWM_MODE == FAST_PWM_9Bit
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif PWM_MODE == FAST_PWM_10Bit
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#endif

	/*Choose the channel and Action  */
#if PWM_CHANNEL == CHANNEL_A
#if COMPARE_OUT_MODE == CLR_ON_COMPARE_MATCH_SET_ON_TOP
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif COMPARE_OUT_MODE == SET_ON_COMPARE_MATCH_CLR_ON_TOP
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif COMPARE_OUT_MODE == DIABLED
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);

#endif
#elif PWM_CHANNEL == CHANNEL_B
#if COMPARE_OUT_MODE == CLR_ON_COMPARE_MATCH_SET_ON_TOP
	CLR_BIT(TCCR1B,TCCR1B_COM1B0);
	SET_BIT(TCCR1B,TCCR1B_COM1B1);
#elif COMPARE_OUT_MODE == SET_ON_COMPARE_MATCH_CLR_ON_TOP
	SET_BIT(TCCR1B,TCCR1B_COM1B0);
	SET_BIT(TCCR1B,TCCR1B_COM1B1);
#elif COMPARE_OUT_MODE == DIABLED
	CLR_BIT(TCCR1B,TCCR1B_COM1B0);
	CLR_BIT(TCCR1B,TCCR1B_COM1B1);
#endif

#elif PWM_CHANNEL == BOTH_A_B
#if COMPARE_OUT_MODE == CLR_ON_COMPARE_MATCH_SET_ON_TOP
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1B,TCCR1B_COM1B0);
	SET_BIT(TCCR1B,TCCR1B_COM1B1);
#elif COMPARE_OUT_MODE == SET_ON_COMPARE_MATCH_CLR_ON_TOP
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	SET_BIT(TCCR1B,TCCR1B_COM1B0);
	SET_BIT(TCCR1B,TCCR1B_COM1B1);
#elif COMPARE_OUT_MODE == DIABLED
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1B,TCCR1B_COM1B0);
	CLR_BIT(TCCR1B,TCCR1B_COM1B1);
#endif

#endif

	/* clear the bits that control clock source*/
	TCCR1B &= CLK_MASK;
	/* Set the clock source */
	TCCR1B |= CLOCK_SELECT;

}

/*
 * Function: PWM_SetDutyCycle(uint16 DutyCycle );
 /**
 *Description: to set the duty cycle for channel A, note the frequency of waveform generated
 *Description: freq = (Freq of clock)  / (65,536 * prescaler)
 *
 *PRECONDTION: Duty cycle in range 0 to 100
 *
 *POSTCONDTION: duty cycle is set
 *POSTCONDTION: Mode be one in PWM_ode_t enum
 *
 *@param DutyCycleValue
 *@param mode of pwm
 *
 *@return void
 */
void PWM_SetDutyCycleChannelA(uint8_t DutyCycleValue,PWM_mode_t Mode ){

	if(Mode == FAST_PWM_8Bit)
	{
		/* Set the value of  OCR1A */
		OCR1A = (255 * (( sfloat32_t)DutyCycleValue/100));
	}
	else if(Mode == FAST_PWM_9Bit)
	{
		/* Set the value of  OCR1A */
		OCR1A = (511 * (( sfloat32_t)DutyCycleValue/100));
	}
	else if(Mode == FAST_PWM_10Bit)
		{
			/* Set the value of  OCR1A */
			OCR1A = (1023 * (( sfloat32_t)DutyCycleValue/100));
		}


}
/*
 * Function: PWM_SetDutyCycle(uint16 DutyCycle );
 /**
 *Description: to set the duty cycle for channel B, note the frequency of waveform generated
 *Description: freq = (Freq of clock)  / (65,536 * prescaler)
 *
 *PRECONDTION: Duty cycle in range 0 to 100
 *PRECONDTION: Mode be one in PWM_ode_t enum
 *
 *POSTCONDTION: duty cycle is set
 *
 * @param DutyCycleValue
 *
 * @return void
 */
void PWM_SetDutyCycleChannelB(uint8_t DutyCycleValue,PWM_mode_t Mode ){

	if(Mode == FAST_PWM_8Bit)
		{
			/* Set the value of  OCR1A */
			OCR1B = (255 * (( sfloat32_t)DutyCycleValue/100));
		}
		else if(Mode == FAST_PWM_9Bit)
		{
			/* Set the value of  OCR1A */
			OCR1B = (511 * (( sfloat32_t)DutyCycleValue/100));
		}
		else if(Mode == FAST_PWM_10Bit)
			{
				/* Set the value of  OCR1A */
				OCR1B = (1023 * (( sfloat32_t)DutyCycleValue/100));
			}
}



void TIMER1_voidSetTimerValue(uint16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

uint16 TIMER1_voidReadTimerValue(void)
{
	return TCNT1;
}

void TIMER1_voidSetChannelACompareMatchVal(uint16 Copy_u8Value)
{
	OCR1A = Copy_u8Value;
}






