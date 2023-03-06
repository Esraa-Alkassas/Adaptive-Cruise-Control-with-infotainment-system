/**
 * @file ACC_prog.c
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief the program file of all system functions implementation
 * @version 0.2
 * @date 2023-02-15
 *
 * @copyright Copyright (c) 2023
 *
 */

/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/***************************************************************************************/
/*                                     MCAL Layer                                      */
/***************************************************************************************/
#include "MRCC_interface.h"
#include "MSTK_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "TMR_interface.h"
#include "MUSART_interface.h"
/***************************************************************************************/
/*                                     HAL Layer                                       */
/***************************************************************************************/
#include "ACC_interface.h"
/***************************************************************************************/
/*                         Global Variables                                            */
/***************************************************************************************/
extern volatile u8 Global_Data_Received;
extern volatile s8 speed_level;
extern volatile u16 speed;
extern volatile u8 speed_selected;
extern volatile u8 mode;
extern volatile u8 range;
extern volatile u8 upper_limit;
extern volatile u8 lower_limit;
extern volatile u32 Distance;

//Converted Distance value array
u8 D[10];
//Converted Speed value array
u8 S[10];
//received data array
u8 array[22];
/***************************************************************************************/
/*                                  System Functions                                   */
/***************************************************************************************/

/**
 * @brief initialize all the peripherals that is used in the system
 * @param void
 * @return void
 */
void sys_init()
{
	/*System Clock initialization*/
	MRCC_voidInitSystemClock();
	/*--------------------------------------- Timer 3 ----------------------------------------------------*/
	/*GPIO pins initialization*/
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERIAL_EN_GPIOA);
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERIAL_EN_GPIOB);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN6, MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN6, AF2);
	MRCC_voidEnablePeripheralClock(APB1, MRCC_PERIPHERIAL_EN_TIM3);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN5, MGPIO_PIN_OUTPUT);

	/*Interrupt initialization*/
	MNVIC_voidEnableInterrupt(29); // Enable Timer3 Global Interrupt

	/*Timer initialization*/
	Timer3_voidCapture_Compare_Init();

	/*------------------------------------ Timer 2 ------------------------------------------------------ */

	/* GPIO pins initialization for DC motor PWM Timer 2*/
	MRCC_voidEnablePeripheralClock(APB1, MRCC_PERIPHERIAL_EN_TIM2);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN0, MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN0, AF1);

	/* speed init */
	TMR_voidSetPrescaler(TMR2, 64);
	TMR_voidSetARR(TMR2, 10000 - 1);
	TMR_voidSetChannelOutput(TMR2, PWM_MODE1, CH1);

	/*--------------------------------- Motors -----------------------------------------------------------*/

	/* Set Mode for Motor Input Pins */
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN1, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN2, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN3, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN4, MGPIO_PIN_OUTPUT);

	/*----------------------------------------- UART ----------------------------------------------------- */

	/*Enable RCC For USART1*/
	MRCC_voidEnablePeripheralClock(APB2, MRCC_PERIPHERIAL_EN_USART1); // Enable CLK Of UART1   At APB2

	/*Configure UART1 ,UART2  Pins*/
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN9, MGPIO_PIN_ALTF);  // TX-->UART1
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN10, MGPIO_PIN_ALTF); // RX-->UART1
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN9, AF7);	  // TX-->UART1
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN10, AF7);	  // RX-->UART1

	/*Enable Peripherials interrupt from NVIC */
	MNVIC_voidEnableInterrupt(37); // Enable uart1 from NVIC

	/*Initialize USART1*/
	MSUART_voidInit();

	/*initialize system Peripherials*/
	MUSART_voidEnable(1); // Enable UART 1

	/*------------------------------------------- LEDS ---------------------------------------------- */
	/* leds */
	MGPIO_voidSetPinMode(MGPIO_PortB, PIN0, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortB, PIN1, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortB, PIN2, MGPIO_PIN_OUTPUT);
}


/**
 * @brief used to start the motors and enable it to speed up by the PWM signal
 * @param void
 * @return void
 */
void start_motor()
{
	/* Set Value for Motor Input Pins to START MOTOR */
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN1, MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN2, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN3, MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN4, MGPIO_PIN_LOW);
}

/**
 * @brief used to stop the motors completely by giving it zero voltage on all its pins
 * @param void
 * @return void
 */
void stop_motor()
{
	/* Set Value for Motor Input Pins to START MOTOR */
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN1, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN2, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN3, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN4, MGPIO_PIN_LOW);
}

/**
 * @brief used to make the configurations of the system flags by switching on the data received from the raspberry
 * @param void
 * @return void
 */
void config()
{
	switch (Global_Data_Received)
	{
	case 'A':
		if (mode == OFFCC)
		{
			speed_level += 5;
		}
		else
		{
			// ACC or NCC are ON
			if (speed_level < speed_selected)
			{
				speed_level += 5;
			}
			else
			{
				// do not increase the speed beyond the selected speed
			}
		}
		break;
	case 'D':
		if (mode == ACC)
		{
			mode = NCC;
		}
		speed_level -= 5;
		break;
	case 'S':
		mode = OFFCC;
		speed_level = 0;
		break;
	case 'O':
		mode = OFFCC;
		break;
	case 'N':
		mode = NCC;
		speed_selected = speed_level;
		break;
	case 'P':
		mode = ACC;
		speed_selected = speed_level;
		break;
	case 'C':
		range = CLOSE;
		break;
	case 'M':
		range = MEDIUM;
		break;
	case 'F':
		range = FAR;
		break;
	default:
		break;
	}
	Global_Data_Received = ' ';
}

/**
 * @brief used to control the motor speed according to the speed flag using PWM signal
 * @param void
 * @return void
 */
void App_u8SetSpeedLevel()
{
	u32 counter;

	// checking speed level
	if (speed_level >= 100)
	{
		speed_level = 100; // to handle the case of speed_level exceeding 100%
	}
	else if (speed_level <= 10)
	{
		stop_motor();
		speed_level = 10;
	}
	else if (speed_level >= 15)
	{
		start_motor();
	}
	else
	{
		// do nothing
	}

	// calculating speed
	speed = (speed_level - 10) / 2;

	// generating PWM signal with the required duty cycle
	counter = 100 * speed_level;
	TMR_voidSetCMPVal(TMR2, CH1, counter - 1);
	TMR_voidStart(TMR2);
	MSTK_voidDelay_ms(100);
}

/**
 * @brief used to turn on the Adaptive Cruise Control Mode ON and set the required range according to the range selected by the user
 * @param void
 * @return void
 */
void ACC_MODE()
{
	switch (range)
	{
	case FAR:
		upper_limit = UPPER_FAR;
		lower_limit = LOWER_FAR;
		break;
	case MEDIUM:
		upper_limit = UPPER_MEDIUM;
		lower_limit = LOWER_MEDIUM;
		break;
	case CLOSE:
		upper_limit = UPPER_CLOSE;
		lower_limit = LOWER_CLOSE;
		break;
	default:
		break;
	}

	range = ' ';
	// checking distance
	if (Distance > upper_limit)
	{
		speed_level++;
	}
	else if (Distance < lower_limit && Distance > DANGER_DISTANCE)
	{
		speed_level--;
	}
	else if (Distance <= DANGER_DISTANCE)
	{
		speed_level = 10;
		mode = OFFCC;
	}
	else
	{
		// the car within the selected range -> do nothing
	}

	// checking speed level
	if (speed_level > speed_selected)
	{
		speed_level = speed_selected;
	}
	else
	{
		// speed level within range
	}
}

/**
 * @brief used to turn ON the Normal Cruise Control Mode
 * @param void
 * @return void
 */
void NCC_MODE()
{
	if (speed_level > speed_selected)
	{
		speed_level = speed_selected; // to handle the case of speed_level exceeding speed_selected
	}
	else
	{
		// speed level within range
	}
	if (Distance <= DANGER_DISTANCE)
	{
		speed_level = 10;
		mode = OFFCC;
	}
	else
	{
		// car within the safe zone
	}
}

/**
 * @brief this function is used to send distance & speed to raspberry pi
 * @param void
 * @return void
 */
void send_data()
{
	u8 loop, index, S_len, D_len;

	S_len = D_len = 10;

	index = 0;

	itoa(speed, S, 10);
	for (loop = 0; loop < S_len; loop++)
	{
		array[index] = S[loop];
		index++;
	}

	array[index] = ' ';
	index++;

	itoa(Distance, D, 10);
	for (loop = 0; loop < D_len; loop++)
	{
		array[index] = D[loop];
		index++;
	}
	array[index] = '\r';
	index++;

	MUSART_u8SendData(1, array, 22);
	array[0] = '\0';
	S[0] = '\0';
	D[0] = '\0';
}
