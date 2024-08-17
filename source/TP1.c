/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    TP1.c
 * @brief   Application entry point.
 */
#include "L1/Application.h"
#include "string.h"
#include "stdio.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

char adc_string[40], time_string[4];
uint32_t time_delay=10;
float temp = 0;
uint8_t unidad = 0;

void LED_ON(uint8_t led){
	GPIO_PinWrite(GPIO, 1, led, 0);
}

void LED_OFF(uint8_t led){
	GPIO_PinWrite(GPIO, 1, led, 1);
}

void LED_TEMP(void){
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


void SEND_TEMP(void){

	sprintf(adc_string, "%d %d", unidad,(int) temp);

	if(unidad == 0)strcat(adc_string, "C ");
	if(unidad == 1)strcat(adc_string, "K ");
	if(unidad == 2)strcat(adc_string, "F ");
	sprintf(time_string, "%d", (int)(time/1000));
	strcat(adc_string, time_string);
	strcat(adc_string, "ms");


	usart1_write(adc_string);
	usart1_write("\r\n");

}



int main(void) {

	CONFIG();

	INIT();

	usart1_write("Medidor de temperatura\r\n");

	time = 0;

	while(1) {

		if(GPIO_PinRead(GPIO, 0, USER_BTN)==0){
			unidad++;
		}

		READ_ADC();

		temp = adc_struct.result * (3.3/4096) * (200/3.3);

		temp = temp - 20;

		if(unidad == 1){
			temp = temp + 273;
		}
		if(unidad == 2){
			temp = temp * 1.8 + 32;
		}
		if(unidad >= 3){
			unidad = 0;
		}

		LED_TEMP();

		SEND_TEMP();

		delay_ms(5000);
    }
    return 0 ;
}



