/*
 * INDICATOR.c
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#include "INDICATOR.h"

int lim_temp_0 = 10, lim_temp_1 = 90;

void LED_ON(uint8_t led){
	GPIO_PinWrite(GPIO, 1, led, 0);
}

void LED_OFF(uint8_t led){
	GPIO_PinWrite(GPIO, 1, led, 1);
}

void LED_TEMP(float temp){
	if(temp < lim_temp_0){
		LED_OFF(LED_G);
		LED_OFF(LED_R);
		LED_ON(LED_B);
	}

	if(temp > lim_temp_0 && temp <lim_temp_1){
		LED_OFF(LED_B);
		LED_OFF(LED_R);
		LED_ON(LED_G);
	}


	if(temp > lim_temp_1){
		LED_OFF(LED_G);
		LED_OFF(LED_B);
		LED_ON(LED_R);
	}
}

