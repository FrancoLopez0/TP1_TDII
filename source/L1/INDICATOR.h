/*
 * INDICATOR.h
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#ifndef L1_INDICATOR_H_
#define L1_INDICATOR_H_

#include "L2/CONFIG.h"

extern int lim_temp_0, lim_temp_1;

void LED_ON(uint8_t);

void LED_OFF(uint8_t);

void LED_TEMP(float);

#endif /* L1_INDICATOR_H_ */
