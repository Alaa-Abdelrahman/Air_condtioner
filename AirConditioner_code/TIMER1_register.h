/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	TIMER			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/


#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_


#define TIMSK             *((volatile uint8_t*)0x59)    /* timer mask  */
#define TIMSK_OCIE0       1                             /* Output compare 0 interrupt enable  */


#define TCCR1A             *((volatile uint8_t*)0x4f)    /* TIMER1A control register */
#define TCCR1A_WGM10     0
#define TCCR1A_WGM11     1
#define TCCR1A_COM1B0    6
#define TCCR1A_COM1B1    7
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1A1    7


#define TCCR1B             *((volatile uint8_t*)0x4e)    /* TIMER1B control register */
#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2
#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4

#define ICR1               *((volatile uint16*)0x46)     /* input capture unit */

#define OCR1A              *((volatile uint16*)0x4a)     /* Output compare Register Channel A  */
#define OCR1B              *((volatile uint16*)0x48)     /* Output compare Register Channel B  */

#define TCNT1              *((volatile uint16*)0x4C)     /* TIMER Register 1  */










#endif 
