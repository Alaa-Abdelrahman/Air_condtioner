/************************************************************************/
/************************************************************************/
/*****************		Author: Alaa		      ***********************/
/*****************		Layer:	HAL			      ***********************/
/*****************		SWC:	LM35			  ***********************/
/*****************		Version:1.00			  ***********************/
/************************************************************************/

#include "STD_TYPES.h"
#include "ADC_interface.h"

/*********************************************************************
 * Function : LM35_u8GetTempSync();
 *//**
 * \b Description: used to get temperature  from LM35 as each change in
 *
 *PRE-CONDITION:ADC must initialize
 *PRE-CONDITION: pass none null pointer to store reading
 *PRE-CONDITION: Vref must be internal
 *
 * POST-CONDITION: get temperature
 *
 *@param : channel form ADC_CH0 to  ADC_CH7
 *@param : address to store the reading
 *
 *@return  error state

  **************************************************************************************************************************/

uint8_t LM35_u8GetTempSync(uint8_t channel , uint8_t * ptru8TempReading){
	uint8_t LocalError = 1;
	uint16 milliVolt;
	uint8_t LM35_read;


	if((ptru8TempReading != NULL) && (channel >= 0)&&(channel <= 7)){
		/*get the ADC read form LM35 */
		ADC_u8StartConversionSync(channel ,&LM35_read);
		*ptru8TempReading = LM35_read ;

	}
	else{
		LocalError = 0;
	}
	return LocalError;
}
