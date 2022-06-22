/****************************************************************************/
/****************************************************************************/
/*****************		Author  : Alaa Abdelrahman    ***********************/
/*****************		Layer	:	HAL		     	  ***********************/
/*****************		SWC		:	L298				  ***********************/
/*****************		Version :   1.00			  ***********************/
/*****************		Date    :   12/9			  ***********************/
/****************************************************************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "L298_interface.h"
#include "TIMER1_interface.h"


/**
 *Function :L298_runMotorCW(uint8_t Speed)
 ***
 *Description: used to run motor with the desired speed in
 *				clock wise direction
 *
 *PRECONDTION: configure PWM with desired configure
 *PRECONDTION: set the chhannelA or channelB or both in PWM
 *
 *POSTCONDTION: the motor will run in desired direction with desired speed
 *
 *@param Motor
 *@param speed
 *
 *@return void
 */

ErrorState_t L298_runMotorCW(Motor_Config_t *Motor,uint8_t Speed){
	ErrorState_t Local_Error = DONE;

	if(Motor != NULL)
	{
		/* Check channel to set PWM that control speed */
		if(Motor->MOTOR_EN == CHANNEL_A){

		PWM_SetDutyCycleChannelA(Speed,FAST_PWM_8Bit);
		}
		else if(Motor->MOTOR_EN == CHANNEL_B){
			PWM_SetDutyCycleChannelB(Speed,FAST_PWM_8Bit);
		}
		else if (Motor->MOTOR_EN == BOTH_A_B)
		{
			PWM_SetDutyCycleChannelA(Speed,FAST_PWM_8Bit);
			PWM_SetDutyCycleChannelB(Speed,FAST_PWM_8Bit);
		}
		else {
			Local_Error = PIN_NOT_FOUND;
			}
		/*Set the Dirction for Motor*/

		DIO_SetPinValue(Motor->MOTOR_PORT,Motor->MOTOR_IN1,DIO_HIGH);
		DIO_SetPinValue(Motor->MOTOR_PORT,Motor->MOTOR_IN2,DIO_LOW);

	}
	else {
		Local_Error = NULLPTR;
	}
	return Local_Error;
}

/************************************************************************************
 *Function :L298_runMotorCW(uint8_t Speed)
 /**
 *Description: used to run motor with the desired speed in
 *				clock wise direction
 *
 *PRECONDTION: configure PWM with desired configure
 *PRECONDTION: set the chhannelA or channelB or both in PWM
 *
 *POSTCONDTION: the motor will run in desired direction with desired speed
 *
 *@param Motor
 *@param speed
 *
 *@return void
 *************************************************************************************/
ErrorState_t L298_runMotorACW(Motor_Config_t *Motor,uint8_t Speed){
	ErrorState_t Local_Error = DONE;

		if(Motor != NULL)
		{
			/* Check channel to set PWM that control speed */
			if(Motor->MOTOR_EN == CHANNEL_A){

			PWM_SetDutyCycleChannelA(Speed,FAST_PWM_8Bit);
			}
			else if(Motor->MOTOR_EN == CHANNEL_B){
				PWM_SetDutyCycleChannelB(Speed,FAST_PWM_8Bit);
			}
			else if (Motor->MOTOR_EN == BOTH_A_B)
			{
				PWM_SetDutyCycleChannelA(Speed,FAST_PWM_8Bit);
				PWM_SetDutyCycleChannelB(Speed,FAST_PWM_8Bit);
			}
			else {
				Local_Error = PIN_NOT_FOUND;
				}
			/*Set the Dirction for Motor*/

			DIO_SetPinValue(Motor->MOTOR_PORT,Motor->MOTOR_IN1,DIO_LOW);
			DIO_SetPinValue(Motor->MOTOR_PORT,Motor->MOTOR_IN2,DIO_HIGH);

		}
		else {
			Local_Error = NULLPTR;
		}
		return Local_Error;
}

/************************************************************************************
 *Function :L298_stopMotor(Motor_Config_t *Motor,uint8_t Speed)
 /**
 *Description: used to stop motor with braking
 *
 *PRECONDTION: motor must be initialized
 *
 *POSTCONDTION: the motor stop
 *
 *@param Motor
 *@param
 *
 *@return ErrorState_t
 *************************************************************************************/
ErrorState_t L298_stopMotor(Motor_Config_t *Motor){

	ErrorState_t Local_Error = DONE;

	if(Motor != NULL){
	DIO_SetPinValue(Motor->MOTOR_PORT,Motor->MOTOR_IN1,DIO_HIGH);
	DIO_SetPinValue(Motor->MOTOR_PORT,Motor->MOTOR_IN2,DIO_HIGH);
	}
	else {
		Local_Error =NULLPTR;
	}
	return Local_Error;

}


