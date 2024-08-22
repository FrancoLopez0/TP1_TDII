/*
 * COM.h
 *
 *  Created on: 20 ago. 2024
 *      Author: Franco
 */

#ifndef L1_COM_H_
#define L1_COM_H_

#include "L2/CONFIG.h"
#include "string.h"
#include "TIME.h"
#include "INDICATOR.h"
#define MAX_BUFF 15
#define INIT_CHR 92
#define END_CHR 13 //   ---'!'=33--- \r = 13

//union buff{
//	char buffer[MAX_BUFF];
//	char function[5];
//	char option[5];
//	char value[5];
//};

void USART(void);
void usart_write_byte(uint8_t);
void usart1_write(char *);
#endif /* L1_COM_H_ */
