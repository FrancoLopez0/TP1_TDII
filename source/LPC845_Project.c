///*
// * Copyright 2016-2024 NXP
// * All rights reserved.
// *
// * SPDX-License-Identifier: BSD-3-Clause
// */
//
///**
// * @file    TP1.c
// * @brief   Application entry point.
// */
//#include "L1/Application.h"
//#include "string.h"
//#include "stdio.h"
///* TODO: insert other definitions and declarations here. */
//
///*
// * @brief   Application entry point.
// */
//
//char adc_string[40], time_string[4];
//uint32_t time_delay=10;
//float temp = 0;
//
//void LED_ON(uint8_t led){
//	GPIO_PinWrite(GPIO, 1, led, 0);
//}
//
//void LED_OFF(uint8_t led){
//	GPIO_PinWrite(GPIO, 1, led, 1);
//}
//
//void LED_TEMP(void){
//	if(temp < 10.00){
//		LED_OFF(LED_G);
//		LED_OFF(LED_R);
//		LED_ON(LED_B);
//	}
//
//	if(temp > 10.00 && temp <90.00){
//		LED_OFF(LED_B);
//		LED_OFF(LED_R);
//		LED_ON(LED_G);
//	}
//
//
//	if(temp > 90.00){
//		LED_OFF(LED_G);
//		LED_OFF(LED_B);
//		LED_ON(LED_R);
//	}
//}
//
//
//void SEND_TEMP(void){
//	sprintf(adc_string, "%f", temp);
//	strcat(adc_string, "°C ");
//	sprintf(time_string, "%d", time_delay);
//	strcat(adc_string, time_string);
//	strcat(adc_string, "ms");
//
//	usart1_write(adc_string);
//	usart1_write("\r\n");
//
//}
//
//
//
//int main(void) {
//
//	CONFIG();
//
//	INIT();
//
//	usart1_write("Medidor de temperatura\n");
//
//	while(1) {
//
//		READ_ADC();
//
//		temp = adc_struct.result * (3.3/4096) * (200/3.3);
//		temp = temp - 20;
//
//		LED_TEMP();
////
//		SEND_TEMP();
//
//		delay_ms(10);
////		delay_ms(500);
//		//USART_TX();
//
//    }
//    return 0 ;
//}
//


