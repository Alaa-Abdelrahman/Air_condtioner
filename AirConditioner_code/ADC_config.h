/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	ADC			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/**
 * define  Timeout for Synchronous function
 */
#define ADC_u32TIMEOUT   10000

/**
 * define voltage reference for ADC options:
 *                                       _ADC_V_REF_AVCC
 *                                       _ADC_V_REF_INTERNAL
 *                                       _ADC_V_REF_EXTERNAL
 */
#define ADC_VOLT_REFRENCE     ADC_V_REF_INTERNAL

/**
 * LEFT_ADJUST_RESULT options:
 * 						-SET
 * 						-CLEAR
 */

#define LEFT_ADJUST_RESULT SET

/**
 * define prescaler  options:
 *                        -CLK_DIV_2
 *                        -CLK_DIV_4
 *                        -CLK_DIV_8
 *                        -CLK_DIV_16
 *                        -CLK_DIV_32
 *                        -CLK_DIV_64
 *                        -CLK_DIV_128
 *
 */

#define ADC_CLK_SRC        CLK_DIV_128

#endif
