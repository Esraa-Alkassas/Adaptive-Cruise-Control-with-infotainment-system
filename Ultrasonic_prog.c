/**
 * @file Ultrasonic_prog.c
 * @author Mohamed Ashraf (ma8831422@gmail.com)
 * @brief functions implementations for ultrasonic
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MNVIC_interface.h"
#include "TMR_interface.h"
#include "Ultrasonic_interface.h"
#include "Ultrasonic_config.h"

extern u32 volatile Distance;
u32 IC_Val1;
u32 IC_Val2;
u32 Time;
u8 flag;

/**
 * @brief interrupt function for ultrasonic
 * @param void
 * @return void
 */
void TIM3_IRQHandler(void)
{

	if (flag == 0)
	{
		IC_Val1 = TMR_voidReadCapture(TMR3, CH1);
		flag = 1;
	}
	else if (flag == 1)
	{
		IC_Val2 = TMR_voidReadCapture(TMR3, CH1);
		TMR_voidClearCount(TMR3);
		flag = 0;
		Time = IC_Val2 - IC_Val1;
		Distance = Time * .343 / 3.85;
	}
}

/**
 * @brief trigger function for ultrasonic
 * @param void
 * @return void
 *
 */
void Ultrasonic_Trigger(void)
{
	MGPIO_voidSetPinValue(UltraPort, Trigger_Pin, MGPIO_PIN_HIGH);
	MSTK_voidDelay_us(15);
	MGPIO_voidSetPinValue(UltraPort, Trigger_Pin, MGPIO_PIN_LOW);
}
