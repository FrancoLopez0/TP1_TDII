/*
 * TEMP.h
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#ifndef L1_TEMP_H_
#define L1_TEMP_H_

#include "L2/CONFIG.h"
#include "TIME.h"

enum unit {u_Celsius, u_Fahrenheit , u_Kelvin};
extern enum unit unity;
extern float temp;


void CHECK_UNIT(void);

void voltage_to_temp(uint32_t);

void GET_TEMP(uint32_t);


#endif /* TEMP_H_ */
