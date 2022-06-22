/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	TIMER			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/

#ifndef TIMER1_CONFIIG_H_
#define TIMER1_CONFIIG_H_

/**
 * Define the clock source options
 *
 *                      - TIM_NO_CLK
 *                      - TIM_CLK_PRESC_0
 *                      - TIM_CLK_PRESC_8
 *                      - TIM_CLK_PRESC_64
 *                      - TIM_CLK_PRESC_256
 *                      - TIM_CLK_PRESC_1024
 *                      - TIM_CLK_EXT_FALLING_EDGE_T0
 *                      - TIM_CLK_EXT_RISING_EDGE_T0
 *
 */


#define  CLOCK_SELECT    TIM_CLK_PRESC_8

/**
 * Define mode of PWM
 * Options: -FAST_PWM_8Bit
 *          -FAST_PWM_9Bit
 *          -FAST_PWM_10Bit
 *
 *
 */

#define PWM_MODE   FAST_PWM_8Bit

/**
 * Define Output compare mode for FAST PWM
 * Options: -DIABLED
 *          -EN_CHANNEL_A_DIS_CHANNEL_B
 *          -CLR_ON_COMPARE_MATCH_SET_ON_TOP
 *          -SET_ON_COMPARE_MATCH_CLR_ON_TOP
 *
 */
#define COMPARE_OUT_MODE     EN_CHANNEL_A_DIS_CHANNEL_B


/**
 * Define the channel for PWM
 * Options:
 *       - CHANNEL_A,
 *       - CHANNEL_B,
 *       - BOTH_A_B
 *
 */

#define PWM_CHANNEL   CHANNEL_A



#endif
