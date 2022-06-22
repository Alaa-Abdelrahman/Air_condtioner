/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	ADC  			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/**
 * for chain conversion
 */
typedef struct
{
	uint8_t * Channel;
	uint16 * Result ;
	uint8_t Size ;
	void (*NotificationFunc)(void);
}Chain_t;


#define ADC_CH0       0
#define ADC_CH1       1
#define ADC_CH2       2
#define ADC_CH3       3
#define ADC_CH4       4
#define ADC_CH5       5
#define ADC_CH6       6
#define ADC_CH7       7


/*********************************************************************
* Function : ADC_voidInit()
*//**
* \b Description: used to configure ADC settings such as:
*                                                    -Reference voltage
*                                                    -Left Adjust  Result
*                                                    -clock source for ADC
*                                                    -enable ADC
* PRE-CONDITION: Configuration must set in config.h file<br>
*
*
* POST-CONDITION: The ADC  peripheral is set up with the configuration
* settings.
*
* @param : none
* @return  void

**************************************************************************************************************************/
void ADC_voidInit();
/*********************************************************************
* Function : ADC_u8StartConversionSync();
*//**
* \b Description: used to start conversion values by ADC and polling until result
* 				 use timeout technique o avoid waiting for infinity
*
*PRE-CONDITION:ADC channel is chosen form available channel in interface file
*PRE-CONDITION: pass none null pointer to store reading
*
*
* POST-CONDITION: The ADC reading is get
*
*@param : ADC channel
*@param : address to store the reading
*
*@return  error state

**************************************************************************************************************************/
uint8_t ADC_u8StartConversionSync(uint8_t Copy_u8Channel,uint8_t *Copy_pu8Reading);
/*********************************************************************
 * Function :ADC_u8StartConversionAsync();
 *//**
 * \b Description: used to start conversion  by ADC and
 *  				  enable interrupt that happen when event complete
 *
 *PRE-CONDITION:ADC channel is chosen form available channel in interface file
 *PRE-CONDITION: pass none null pointer to store reading
 *PRE-CONDITION: pointer to notify function
 *
 *
 * POST-CONDITION: The ADC conversion run in background
 *
 *@param : ADC channel
 *@param : address to store the reading
 *@param pointer to function
 *
 *@return  error state

  **************************************************************************************************************************/
uint8_t ADC_u8StartConversionAsync(uint8_t Copy_u8Channel,uint8_t *Copy_pu8Reading,void(*Copy_pvNotification(void)));

uint8_t ADC_u8StartChainAsync(Chain_t * Copy_Chain);
#endif
