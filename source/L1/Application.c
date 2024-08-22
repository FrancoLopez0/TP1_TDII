/*
 * Application.c
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#include "L1/Application.h"

bool first_init = false;

void APP(void){
	if(!first_init){
		RESTART_TIME();
		first_init = true;
	}
	READ_ADC();
	GET_TEMP(adc_struct.result);
	LED_TEMP(temp);
	SEND_TEMP(temp, unity, current_time);
	on_wait_ms(callback_on_wait, delta_time_seconds * 1000);
}

void callback_on_wait(void){
	USART();
	CHECK_UNIT();
}
