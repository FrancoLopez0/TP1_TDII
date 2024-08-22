/*
 * TEMP.C
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#include "TEMP.h"

enum unit unity = u_Celsius;
float temp = 0;

void CHECK_UNIT(void){

	if(!GPIO_PinRead(GPIO, 0, CHANGE_UNIT)){

		if(unity<3) unity++;
		if(unity>=3) unity=0;
		usart1_write("Set unit in");
		usart1_write((unity==u_Celsius)?" C ":((unity==u_Fahrenheit)?" F ": " K "));
		usart1_write("\r\n");
		for(int i=0; i<500000;i++);
	}

}

void voltage_to_temp(uint32_t adc_value){
	temp = adc_value * (3.3/4096) * (200/3.3);

	temp = temp - 20;

}

void GET_TEMP(uint32_t adc_value){

	current_time = time;

	voltage_to_temp(adc_value);
}
