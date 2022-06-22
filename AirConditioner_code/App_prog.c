/***************************************************************************************
 * File Name  : Air conditioner
 * Version    : 1.00
 * Description: this simple Air conditioner consists of temperature sensor, KEYPAD,CLCD
 * 				and fan, when set temp the fan works until temp decrease o specified degree
 *
 * Author     : Alaa Abdelrahman
 *****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMER1_interface.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "LM35_interface.h"
#include "L298_interface.h"


#include "App_interface.h"




Motor_Config_t fan = {PORTD,PIN6,PIN7,CHANNEL_A};

static uint8_t desiredTemp = 30;
static uint8_t currentTemp = 10;


void App_SetTemp(){

	uint8_t PressedKey = 0;
	static uint8_t Temp = 0;


	/*read the pressed key*/
	PressedKey= KPD_u8GetPressedKey();

	if(PressedKey == '=')
	{
		/*set the Desired Temp*/
		desiredTemp = Temp;
		Temp = 0;
		return;
	}
	else if (PressedKey == KPD_NO_PRESSED_KEY){
		return;
	}
	else{

		/*take temperature from the user */
		Temp =Temp*10+ PressedKey;
		CLCD_voidGoToXY(1,10);
		CLCD_voidSendNumber(Temp);
	}

}




void App_Display(){

	CLCD_Clear();
	CLCD_voidSendString("Curr TEMP: ");
	CLCD_voidGoToXY(0,10);
	CLCD_voidSendNumber(currentTemp);
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("Set  TEMP:    C");
	CLCD_voidGoToXY(1,10);
	CLCD_voidSendNumber(desiredTemp);



}

void App_GetStausOfTemp(){

	/*get the current state of temperature */
	LM35_u8GetTempSync(ADC_CH0,&currentTemp);

	CLCD_voidGoToXY(0,10);
	CLCD_voidSendNumber(currentTemp);

}
void App_ControlFan(){

	if(currentTemp >desiredTemp)
	{
		L298_runMotorCW(&fan,100);
	}
	else if(currentTemp <= desiredTemp)
	{
		L298_stopMotor(&fan);
	}
}

void App_Init(){

	/*Initialize the components of Project*/
	PORT_voidInit();

	ADC_voidInit();

	/*Initialize LCD*/
	CLCD_voidInit();

	PWM_Init();

	App_Display();

}


void App_Update(){


	/*set desired Temp*/
	App_SetTemp();

	/*check current temperature degree */
	App_GetStausOfTemp();

	/*control the fan based on degree*/
	App_ControlFan();




}
