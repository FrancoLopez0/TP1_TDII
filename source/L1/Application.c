/*
 * Application.c
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#include "L1/Application.h"

bool first_init = true;
uint32_t last_time = 0;

void APP(void){

	if(first_init){
		RESTART_TIME();
		last_time = time;
	}

	if((time-last_time)>= delta_time_seconds * 1000 || first_init)
	{
		READ_ADC();
		GET_TEMP(adc_struct.result);
		LED_TEMP(temp);
		SEND_TEMP(temp, unity, current_time);
		last_time = time;
		first_init = false;
	}

	USART();
	CHECK_UNIT();
}
