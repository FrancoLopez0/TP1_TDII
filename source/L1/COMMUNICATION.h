/*
 * COMMUNICATION.h
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#ifndef L1_COMMUNICATION_H_
#define L1_COMMUNICATION_H_

#include "string.h"
#include "stdio.h"
#include "TEMP.h"
extern char function[5], option[10], value[10];

void SEND_TEMP(float, enum unit, uint32_t);

void USART_RX(void);

#endif /* L1_COMMUNICATION_H_ */
