/*
 * TIME.C
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#include "TIME.h"

uint32_t current_time=0;
uint32_t delta_time_seconds=5;

void RESTART_TIME(void){
	time = 0;
	flag_tick = 0;
	current_time = 0;
}

