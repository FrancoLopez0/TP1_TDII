/*
 * TIME.h
 *
 *  Created on: 19 ago. 2024
 *      Author: Franco
 */

#ifndef L1_TIME_H_
#define L1_TIME_H_

#include "L2/CONFIG.h"

extern uint32_t current_time;
extern uint32_t delta_time_seconds;

void RESTART_TIME(void);

#endif /* L1_TIME_H_ */
