/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	ADC  			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
  



#define ADMUX        *((volatile uint8_t*)0x27) /*ADC multiplexer selection register */
#define ADMUX_REFS1  7                          /*Reference selection bit0 */
#define ADMUX_REFS0  6                         /*Reference selection bit1 */
#define ADMUX_ADLAR  5                        /*ADC left adjust result */


#define ADCSRA        *((volatile uint8_t*)0x26)  /*ADC control and status Register A */

#define ADCSRA_ADEN     7      /* ADC enable */
#define ADCSRA_ADSC     6      /* Start conversion */
#define ADCSRA_ADATA    5      /* Auto trigger Enable */
#define ADCSRA_ADIF     4      /* Interrupt Flag */
#define ADCSRA_ADIE     3      /* Interrupt Flag */
#define ADCSRA_ADSPS2   2      /*  prescaler bit0 */
#define ADCSRA_ADSPS1   1      /*  prescaler bit1 */
#define ADCSRA_ADSPS0   0      /*  prescaler bit2 */



#define ADCH        *((volatile uint8_t*)0x25) /*ADC high register */

#define ADCL        *((volatile uint8_t*)0x24) /*ADC low register */

#endif 
