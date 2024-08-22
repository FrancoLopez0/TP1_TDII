/*
 * USART.c
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#include "USART.h"


uint8_t flagReceived=0 , buff_data_usart[MAX_BUFF_SIZE], counter=0, aux;


void write_byte(uint8_t data){
	while (!(USART1->STAT & 0x4));
	USART_WriteByte(USART1, data);
	while (!(USART1->STAT & 0x8));
}

void usart1_write(char *p){

	while(*p != 0){
		USART_WriteByte(USART1, *(p++));
		while (!(USART1->STAT & USART_STAT_TXIDLE_MASK));
	}

}

void clean_buffer(void){
	for(int i = 0; i<MAX_BUFF_SIZE; i++)
	{
		buff_data_usart[i] = 0;
	}
}
