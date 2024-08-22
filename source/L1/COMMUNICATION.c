/*
 * COMMUNICATION.c
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#ifndef L1_COMMUNICATION_C_
#define L1_COMMUNICATION_C_

#include "COMMUNICATION.h"
char function[5], option[10], value[10];
char adc_string[40], time_string[4];

void SEND_TEMP(float temp, enum unit unity, uint32_t current_time){

	if(unity == u_Kelvin){
			temp = temp + 273;
		}
		if(unity == u_Fahrenheit){
			temp = temp * 1.8 + 32;
		}
		if(unity >= 4){
			unity = u_Celsius;
		}

	sprintf(adc_string, "%.2f", temp);
	strcat(adc_string, (unity==u_Celsius)?" C ":((unity==u_Fahrenheit)?" F ": " K "));
	sprintf(time_string, "%d", (uint32_t)(current_time/1000));
	strcat(adc_string, time_string);
	strcat(adc_string, "s");

	usart1_write(adc_string);
	usart1_write("\r\n");
}

#endif /* L1_COMMUNICATION_C_ */
