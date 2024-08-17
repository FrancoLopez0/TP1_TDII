/*
 * DELAY.c
 *
 *  Created on: 6 jul. 2024
 *      Author: Franco
 */
#include "DELAY.h"

volatile uint32_t flag_tick;
volatile uint32_t time;

//uint32_t time_ant = 0;
//uint32_t delta_time_ms = 0;
//
//uint32_t get_deta_t(void){
//	delta_time_ms = (time - time_ant);
//	time_ant = time;
//	return delta_time_ms;
//}


void SYSTICK_INIT(void){
	SysTick_Config(SystemCoreClock/1000);
	flag_tick = 0;
}

void SysTick_Handler(void){
	flag_tick++;
	time++;
}

void delay_ms(int final){
	while(flag_tick <= final);
	flag_tick = 0;
}
