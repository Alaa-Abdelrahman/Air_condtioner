/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	TIMER			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

/**
 * PWM modes
 */

typedef enum{
	FAST_PWM_8Bit,
	FAST_PWM_9Bit,
	FAST_PWM_10Bit

}PWM_mode_t;


/**
 * PWM Channels Timer1 provide two Channel PWM
 */

typedef enum{
	CHANNEL_A,
	CHANNEL_B,
	BOTH_A_B

}PWM_channel_t;

/**
 * compare output mode for FAST PWM
 */

typedef enum{
	DIABLED,                               /**< Normal port operation. OC1A,OC1B is disabled */
	EN_CHANNEL_A_DIS_CHANNEL_B,
	CLR_ON_COMPARE_MATCH_SET_ON_TOP,
	SET_ON_COMPARE_MATCH_CLR_ON_TOP

}CompareOutMode_t;



/**
 * ClockSelect contain clock source for timer1 counter
 */

typedef enum{
	   TIM_NO_CLK                 ,
	   TIM_CLK_PRESC_0            ,
	   TIM_CLK_PRESC_8            ,
	   TIM_CLK_PRESC_64           ,
	   TIM_CLK_PRESC_256          ,
	   TIM_CLK_PRESC_1024         ,
	   TIM_CLK_EXT_FALLING_EDGE_T0,
	   TIM_CLK_EXT_RISING_EDGE_T0
}ClockSelect_t;




/*
 * Function: PWM_Init()
 /**
 * Description:  is used to select the source of clock for PWM and PWM mode
 *
 *
 * PRECONDTION: must choose the clock source in TIMER1_config.h
 * PRECONDTION: must choose  one of mode in PWM_mode enum in TIMER1_interface.h
 *
 * POSTCONDTION: The clock source of PWM is configured
 * POSTCONDTION: Mode of PWM is configured
 *
 * @param none
 *
 * @return void
 */
void PWM_Init(void);

/*
 * Function: PWM_SetDutyCycleChannelA(uint8_t DutyCycleValue ,PWM_mode_t Mode );
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
void PWM_SetDutyCycleChannelA(uint8_t DutyCycleValue,PWM_mode_t Mode  );

/*
 * Function: PWM_SetDutyCycleChannelB(uint8_t DutyCycleValue ,PWM_mode_t Mode )
 /**
 *Description: to set the duty cycle for channel B, note the frequency of waveform generated
 *Description: freq = (Freq of clock)  / (65,536 * prescaler)
 *
 *PRECONDTION: Duty cycle in range 0 to 100
 *PRECONDTION: Mode be one in PWM_ode_t enum
 *
 *POSTCONDTION: duty cycle is set

 *
 *@param DutyCycleValue
 *@param mode of pwm
 *
 *@return void
 */
void PWM_SetDutyCycleChannelB(uint8_t DutyCycleValue ,PWM_mode_t Mode );



void TIMER1_voidSetChannelACompareMatchVal(uint16 Copy_u8Value);

void TIMER1_voidSetTimerValue(uint16 Copy_u16Value);

uint16 TIMER1_voidReadTimerValue(void);





#endif
