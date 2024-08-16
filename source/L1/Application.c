/*
 * Application.c
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#include "Application.h"


void USART_TX(void){

	if(flagReceived && counter > 0)
			{
				counter = 0;
				usart1_write(&buff_data_usart[0]);
			}
}
