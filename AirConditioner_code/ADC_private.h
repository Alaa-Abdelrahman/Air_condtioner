/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	ADC  			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define IDLE    1
#define BUSY    2

#define SINGLE_CHANNEL    1
#define CHAIN_ASYNCH      2

#define ADC_V_REF_AVCC           4
#define ADC_V_REF_INTERNAL       5
#define ADC_V_REF_EXTERNAL       6

 #define SET   7
 #define CLEAR 8


#define CLK_MASK         0b11111000

#define CLK_DIV_2        1
#define CLK_DIV_4        2
#define CLK_DIV_8        3
#define CLK_DIV_16       4
#define CLK_DIV_32       5
#define CLK_DIV_64       6
#define CLK_DIV_128      7

#define ADMUX_MASK      0b11100000
#endif
