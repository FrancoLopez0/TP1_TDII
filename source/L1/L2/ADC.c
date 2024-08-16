/*
 * ADC.c
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */


#include "ADC.h"

uint32_t frequency;
adc_result_info_t adc_struct;

void CONFIG_ADC(void){

	CLOCK_Select(kADC_Clk_From_Fro);
	CLOCK_SetClkDivider(kCLOCK_DivAdcClk, 1U);

	POWER_DisablePD(kPDRUNCFG_PD_ADC0);
	frequency = CLOCK_GetFreq(kCLOCK_Fro) / CLOCK_GetClkDivider(kCLOCK_DivAdcClk);
	(void) ADC_DoSelfCalibration(ADC0, frequency);

	adc_config_t adcConfigStruct;
	adc_conv_seq_config_t adcConvSeqConfigStruct;
	adcConfigStruct.clockMode = kADC_ClockSynchronousMode;
	adcConfigStruct.clockDividerNumber = 1;
	adcConfigStruct.enableLowPowerMode = false;
	adcConfigStruct.voltageRange = kADC_HighVoltageRange;
	ADC_Init(ADC0, &adcConfigStruct);

	adcConvSeqConfigStruct.channelMask = 1 << ADC0_CH0;
	adcConvSeqConfigStruct.triggerMask = 0;
	adcConvSeqConfigStruct.triggerPolarity = kADC_TriggerPolarityPositiveEdge;
	adcConvSeqConfigStruct.enableSingleStep = false;
	adcConvSeqConfigStruct.enableSyncBypass = false;
	adcConvSeqConfigStruct.interruptMode = kADC_InterruptForEachSequence;
	ADC_SetConvSeqAConfig(ADC0, &adcConvSeqConfigStruct);
	ADC_EnableConvSeqA(ADC0, true);
	ADC_DoSoftwareTriggerConvSeqA(ADC0);
}

void READ_ADC(void){
	if(ADC_GetChannelConversionResult(ADC0, ADC0_CH0, &adc_struct)){
		ADC_DoSoftwareTriggerConvSeqA(ADC0);
	}
}
