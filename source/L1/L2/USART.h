/*
 * USART.h
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#ifndef L1_L2_USART_H_
#define L1_L2_USART_H_

#include "fsl_usart.h"
#include "board.h"
#define MAX_BUFF_SIZE 64
#define END_TX '.'

extern uint8_t flagReceived , buff_data_usart[MAX_BUFF_SIZE], counter, aux;

void write_byte(uint8_t);

void usart1_write(uint8_t *);

#endif /* L1_L2_USART_H_ */
