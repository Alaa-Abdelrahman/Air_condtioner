/****************************************************************************/
/****************************************************************************/
/*****************		Author  : Alaa Abdelrahman    ***********************/
/*****************		Layer	:	HAL		     	  ***********************/
/*****************		SWC		:	L298				  ***********************/
/*****************		Version :   1.00			  ***********************/
/*****************		Date    :   12/9			  ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef L298_INTERFACE_H
#define L298_INTERFACE_H

/**
 * Define motor A input pins used to control
 * the spinning direction of Motor A
 */
#define PORT        PORTA

#define IN1         PIN0
#define IN2         PIN1


/**
 * Define motor B input pins used to control
 * the spinning direction of Motor B
 */
#define IN3         PIN2
#define IN4         PIN3


/**
 *define  parameters  for each motor
 */

typedef struct {
	uint8_t MOTOR_PORT; /**<define the port that control the motor */
	uint8_t MOTOR_IN1;  /**<define pin1 control the motor direction*/
	uint8_t MOTOR_IN2;  /**<define pin2 control the motor direction */
	uint8_t MOTOR_EN ;  /**<define pwm pin  control the motor direction */
}Motor_Config_t;

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
 *@return ErrorState_t
 */

ErrorState_t L298_runMotorCW(Motor_Config_t* Motor,uint8_t Speed);

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
 *@return ErrorState_t
 *************************************************************************************/
ErrorState_t L298_runMotorACW(Motor_Config_t *Motor,uint8_t Speed);


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
ErrorState_t L298_stopMotor(Motor_Config_t *Motor);







#endif
