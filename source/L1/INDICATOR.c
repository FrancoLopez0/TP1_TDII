/*
 * INDICATOR.c
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#include "INDICATOR.h"

void LED_ON(uint8_t led){
	GPIO_PinWrite(GPIO, 1, led, 0);
}

void LED_OFF(uint8_t led){
	GPIO_PinWrite(GPIO, 1, led, 1);
}

void LED_TEMP(float temp){
	if(temp < 10.00){
		LED_OFF(LED_G);
		LED_OFF(LED_R);
		LED_ON(LED_B);
	}

	if(temp > 10.00 && temp <90.00){
		LED_OFF(LED_B);
		LED_OFF(LED_R);
		LED_ON(LED_G);
	}


	if(temp > 90.00){
		LED_OFF(LED_G);
		LED_OFF(LED_B);
		LED_ON(LED_R);
	}
}

