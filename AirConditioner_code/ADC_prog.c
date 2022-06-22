/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	ADC 			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"


static void (*ADC_pvCallBackNotification)(void) = NULL;

uint8_t ADC_u8BusyState = IDLE;

static uint8_t* ADC_pu8ChainChannelArr = NULL;

static uint8_t* ADC_pu8ChainResultArr = NULL;

static  uint8_t ADC_u8ChainSize;
static  uint8_t ADC_u8Index = 0 ;



static uint8_t *ADC_pu8Reading = NULL;

static uint8_t ADC_u8ISRSource;

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

void ADC_voidInit()
{
	/*set reference voltage  */
#if ADC_VOLT_REFRENCE == ADC_V_REF_AVCC
	CLR_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLT_REFRENCE == ADC_V_REF_EXTERNAL
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLT_REFRENCE == ADC_V_REF_INTERNAL
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif

	/*define status of left adjust result */
#if	LEFT_ADJUST_RESULT == SET
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif	LEFT_ADJUST_RESULT == CLEAR
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#endif

	/*define prescaler */
	ADCSRA &= CLK_MASK;
	ADCSRA |= ADC_CLK_SRC;

	/*Enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

/*********************************************************************
 * Function : ADC_u8StartConversionSync();
 *//**
 * \b Description: used to start conversion  by ADC and polling until result
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
 *@return  error state

  **************************************************************************************************************************/

uint8_t ADC_u8StartConversionSync(uint8_t Copy_u8Channel,uint8_t *Copy_pu8Reading)
{
	uint8_t Local_u8Errorstatus=1;
	uint32 Local_u32Counter=0;

	/*Clear the MUX bits in ADMUX register */
	ADMUX&=ADMUX_MASK;

	/*Set the required channel into MUX bits*/
	ADMUX|=Copy_u8Channel;

	/*Start conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/* Polling (busyWAting )until the conversion complete flag is set */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)== 0 && Local_u32Counter== ADC_u32TIMEOUT)
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter == ADC_u32TIMEOUT)
	{
		// loop is broken because the timeout is reached*/
		Local_u8Errorstatus = 0;
	}
	else
	{
		/*loop is broken because flag is raised*/
		/*Clear the conversion  compete flag*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);


		/*read the result*/
		*Copy_pu8Reading =  ADCH;
	}

	return Local_u8Errorstatus;


}

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
 *@return  error state

  **************************************************************************************************************************/

uint8_t ADC_u8StartConversionAsync(uint8_t Copy_u8Channel,uint8_t *Copy_pu8Reading,void(*Copy_pvNotification(void)))
{
	uint8_t Local_u8ErrorState = 1;
	if(ADC_u8BusyState != BUSY)
	{

		if((Copy_pu8Reading == NULL)||(Copy_pvNotification == NULL))
		{
			Local_u8ErrorState = 0;
		}
		else
		{
			/* make ADC Busy*/
			ADC_u8BusyState = BUSY;

			/*MAKE ISR SOURCE : SINGLE CHANNEL ASYNCHROUNOUS */
			ADC_u8ISRSource = SINGLE_CHANNEL;

			/*initailize reading values globally*/

			ADC_pu8Reading = Copy_pu8Reading;

			/*Initialize callback function  globally*/
			ADC_pvCallBackNotification = Copy_pvNotification;

			/*Clear the MUX bits in ADMUX register */
			ADMUX&=ADMUX_MASK;

			/*Set the required channel into MUX bits*/
			ADMUX|=Copy_u8Channel;

			/*Start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable Interrupt */

			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		return Local_u8ErrorState = 3;
	}
	return Local_u8ErrorState;
}


uint8_t ADC_u8StartChainAsync(Chain_t * Copy_Chain)
{
	uint8_t Local_u8ErrorState =1;

	/*check Null Pointer */
	if(Copy_Chain == NULL)
	{
		Local_u8ErrorState = 0;
	}
	if(ADC_u8BusyState == IDLE )
	{

		/* make ADC Busy*/
		ADC_u8BusyState = BUSY;

		/*INTIALIZE CHAIN CHANEEL ARRAY */
		ADC_pu8ChainChannelArr = Copy_Chain->Channel;

		/*iNTAILZE RESULT ARRAY*/

		ADC_pu8ChainResultArr = Copy_Chain->Result;

		/* INTIALIZE CHAIN SIZE */
		ADC_u8ChainSize = Copy_Chain->Size;

		/* INTIALIZE CHAIN SIZE */
		ADC_pvCallBackNotification = Copy_Chain->NotificationFunc;

		/* INTIALIZE index with zero */

		ADC_u8Index = 0;

		/*Set required channel*/
		ADMUX &= ADMUX_MASK;
		ADMUX|=ADC_pu8ChainChannelArr[ADC_u8Index];

		/*start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/* enable conversion complete interrupt */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

	}

	return Local_u8ErrorState;
}


/**
 * interrupt vector for ADC
 */
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{


	/*Read ADC result */
	*ADC_pu8Reading = ADCH;
	/*ADC return IDLE because it is finished */
	ADC_u8BusyState = IDLE;

	/*Invoking the callback notification function */

	ADC_pvCallBackNotification();

	/*Disable ADC conversion complete interrupt */

	CLR_BIT(ADCSRA,ADCSRA_ADIE);

}



