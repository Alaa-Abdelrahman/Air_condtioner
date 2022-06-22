/************************************************************************/
/************************************************************************/
/*****************		Author: Alaa		      ***********************/
/*****************		Layer:	HAL			      ***********************/
/*****************		SWC:	LM35			  ***********************/
/*****************		Version:1.00			  ***********************/
/************************************************************************/

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_


/*********************************************************************
 * Function : LM35_u8GetTempSync();
 *//**
 * \b Description: used to get temperature  from LM35
 *
 *PRE-CONDITION:ADC must initialize
 *PRE-CONDITION: pass none null pointer to store reading
 *PRE-CONDITION: Vref must be internal
 *
 *
 * POST-CONDITION: get temperature
 *
 *@param : channel
 *@param : address to store the reading
 *
 *@return  error state

  **************************************************************************************************************************/

uint8_t LM35_u8GetTempSync(uint8_t channel , uint8_t * ptru8TempReading);
#endif
