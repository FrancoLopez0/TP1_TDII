/*
 * ADC.h
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#ifndef L1_L2_ADC_H_
#define L1_L2_ADC_H_

#include "fsl_power.h"
#include "fsl_adc.h"
#include "board.h"

#define ADC0_CH0 0

extern adc_result_info_t adc_struct;

void CONFIG_ADC(void);

void READ_ADC(void);

#endif /* L1_L2_ADC_H_ */
