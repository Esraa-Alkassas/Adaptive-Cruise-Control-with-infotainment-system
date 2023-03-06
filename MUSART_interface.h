/**
 * @file MUSART_interface.h
 * @author Alaa Ashraf (alaaashraffawzyelsaid@gmail.com)
 * @brief MUSART_Interface.c --> functions prototype
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



void MSUART_voidInit(void);

void MUSART_voidEnable(u8 copy_u8Index);

void MUSART_voidDisable(u8 copy_u8Index);

void MUSART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len);

u8 MUSART_u8ReadData(u8 copy_u8Index);

void gets1USART(u8 copy_u8Index,char *buffer, unsigned char len);

#endif //UART_INTERFACE_H_
