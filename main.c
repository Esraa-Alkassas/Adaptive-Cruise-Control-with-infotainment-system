/**
 * @file main.c
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief the main application of the project
 * @version 0.3
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"
/***************************************************************************************/
/*                                     MCAL Layer                                      */
/***************************************************************************************/
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MNVIC_interface.h"
#include "MUSART_interface.h"
#include "TMR_interface.h"
/***************************************************************************************/
/*                                     HAL Layer                                       */
/***************************************************************************************/
#include "Ultrasonic_interface.h"
#include "ACC_interface.h"
/**************************************************************************************/

// GLOBAL VARIABLES
volatile u8 Global_Data_Received;
volatile u16 speed;
volatile s8 speed_level;
volatile u8 speed_selected;
volatile u8 mode;
volatile u8 range;
volatile u8 upper_limit;
volatile u8 lower_limit;
volatile u32 Distance;

/**
 * @brief the main entry point of the program
 * @param void
 * @return void
 */
void main (void)
{
	sys_init();
	TMR_voidStart(TMR3);
	speed_level=10;
	mode = OFFCC;
	range= CLOSE;

	while(1)
	{

		Ultrasonic_Trigger();
		config();

		if (mode == ACC)
		{
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN1,MGPIO_PIN_HIGH); // light up a led to indicate that the ACC mode is on
			ACC_MODE();
		}
		else if (mode == NCC)
		{
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN0,MGPIO_PIN_HIGH); // light up a led to indicate that the NCC mode is on
			NCC_MODE();
		}
		else
		{
			// system is in normal driving mode -> speed_level changed manually
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN2,MGPIO_PIN_HIGH);
		}
		App_u8SetSpeedLevel();
		send_data();
	}
}











