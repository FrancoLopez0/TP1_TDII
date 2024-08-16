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

void usart1_write(uint8_t *p){
	while(*p != 0){
		USART_WriteByte(USART1, *(p++));
		while (!(USART1->STAT & USART_STAT_TXIDLE_MASK));
	}
}

void USART1_IRQHandler(void){
	aux = USART_ReadByte(USART1);
	if(aux != END_TX){
		buff_data_usart[counter] = aux;
		counter++;
	}
	if(aux == END_TX && counter>0){
		flagReceived = 1;
	}
}
