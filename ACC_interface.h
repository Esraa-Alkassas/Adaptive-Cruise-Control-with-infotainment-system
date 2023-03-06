/**
 * @file ACC_interface.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief ACC_interface.h -> functions prototype
 * @version 0.3
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ACC_INTERFACE_H_
#define ACC_INTERFACE_H_


/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"
/***************************************************************************************/
/************************************** Functions **************************************/
void sys_init();
void App_u8SetSpeedLevel();
void start_motor();
void stop_motor();
void config();
void ACC_MODE();
void NCC_MODE();
void send_data();
/*******************************************************************************************************/
/*                                           MODES & RANGES     	                                   */
/*******************************************************************************************************/
typedef enum
{
	OFFCC,
	NCC,
	ACC
}CCmode_t;

typedef enum
{
	CLOSE,
	MEDIUM,
	FAR
}range_t;

typedef enum
{
	// FAR LIMITS
	UPPER_FAR = 100,
	LOWER_FAR = 70,
	// MEDIUM LIMITS
	UPPER_MEDIUM = 70,
	LOWER_MEDIUM = 40,
	// CLOSE LIMITS
	UPPER_CLOSE = 40,
	LOWER_CLOSE = 10,

	DANGER_DISTANCE = 5

}distance_t;
#endif /* ACC_INTERFACE_H_ */
