/*
 * CONFIG.h
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#ifndef L1_L2_CONFIG_H_
#define L1_L2_CONFIG_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC845.h"
#include "fsl_debug_console.h"

#include "fsl_swm.h"
#include "fsl_gpio.h"
#include "fsl_power.h"
#include "MyLibs/DELAY.h"
#include "USART.h"
#include "ADC.h"

#define LED_R 2
#define LED_B 1
#define LED_G 0
#define CHANGE_UNIT 4


void CONFIG(void);

void CONFIG_SWM(void);

void CONFIG_PINS(void);

void CONFIG_USART(void);

void INIT(void);

#endif /* L1_L2_CONFIG_H_ */
