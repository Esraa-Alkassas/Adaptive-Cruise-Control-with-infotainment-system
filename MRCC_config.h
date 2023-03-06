/**
 * @file MRCC_config.h
 * @author Mohamed Ashraf (ma8831422@gmail.com)
 * @brief MRCC_Config.h -> Configuration file for RCC peripheral
 * @version 0.1
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/***************************************************************************************/
/* Author               : Mohamed Ashraf                                               */
/* Version              : V0.0.0                                                       */
/* Date                 : 17 - 1 -2023                                                 */
/* Description          : MRCC_Config.h -> Configuration                               */
/***************************************************************************************/
/***************************************************************************************/
/*  The Options which Developer Choose which what is suitable to App                   */
/***************************************************************************************/


/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/*Select the Clock Source From The Following :
 * Options :
 *          1) HSI
 *          2) HSE
 *          3) PLL
 **/

#define MRCC_CLKSRC      HSI


/*Select the  Source of HSE From The Following :
 * Options :
 *          1) HSE_MECH
 *          2) HSE_RC
 **/

#define MRCC_HSE_SRC     HSE_MECH


/*Select the  Source of PLL From The Following :
 * Options :
 *          1) HSE_PLL
 *          2) HSI_PLL
 **/

#define MRCC_PLL_SRC     HSE_PLL

#endif /* MRCC_CONFIG_H_ */
