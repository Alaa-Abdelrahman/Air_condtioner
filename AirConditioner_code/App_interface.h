/***************************************************************************************
 * File Name  : Air conditioner
 * Version    : 1.00
 * Description: this simple Air conditioner consists of temperature sensor, KEYPAD,CLCD
 * 				and fan, when set temp the fan works until temp decrease o specified degree
 *
 * Author     : Alaa Abdelrahman
 *****************************************************************************************/

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_



void App_Init();

void App_SetTemp();

void App_GetStausOfTemp();

void App_ControlFan();

void App_Display();

void App_Update();

#endif
