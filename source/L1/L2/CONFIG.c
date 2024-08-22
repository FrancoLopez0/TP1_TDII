/*
 * CONFIG.c
 *
 *  Created on: 16 ago. 2024
 *      Author: Franco
 */

#include "CONFIG.h"

usart_config_t config;


void CONFIG_SWM(void){
	CLOCK_EnableClock(kCLOCK_Swm);
	SWM_SetMovablePinSelect(SWM0, kSWM_USART1_TXD, kSWM_PortPin_P0_25);
	SWM_SetMovablePinSelect(SWM0, kSWM_USART1_RXD, kSWM_PortPin_P0_24);
	SWM_SetFixedPinSelect(SWM0, kSWM_ADC_CHN0, true);
	CLOCK_DisableClock(kCLOCK_Swm);
}

void CONFIG_PINS(void){
	gpio_pin_config_t out_config = {kGPIO_DigitalOutput,1};
	gpio_pin_config_t in_config = {kGPIO_DigitalInput};
	GPIO_PortInit(GPIO,1);
	GPIO_PortInit(GPIO,0);


	GPIO_PinInit(GPIO,1,LED_R,&out_config);
	GPIO_PinInit(GPIO,1,LED_G,&out_config);
	GPIO_PinInit(GPIO,1,LED_B,&out_config);

	GPIO_PinInit(GPIO,0,CHANGE_UNIT,&in_config);

	GPIO_PinWrite(GPIO, 1, LED_R, 1);
	GPIO_PinWrite(GPIO, 1, LED_G, 1);
	GPIO_PinWrite(GPIO, 1, LED_B, 1);

	GPIO_PinWrite(GPIO, 1, LED_R, 0);
	delay_ms(500);
	GPIO_PinWrite(GPIO, 1, LED_R, 1);

	GPIO_PinWrite(GPIO, 1, LED_G, 0);
	delay_ms(500);
	GPIO_PinWrite(GPIO, 1, LED_G, 1);

	GPIO_PinWrite(GPIO, 1, LED_B, 0);
	delay_ms(500);
	GPIO_PinWrite(GPIO, 1, LED_B, 1);
}

void CONFIG_USART(void){

	CLOCK_Select(kUART1_Clk_From_MainClk);

	USART_GetDefaultConfig(&config);
	config.enableRx = true;
	config.enableTx = true;

}

void INIT(void){

	USART_Init(USART1, &config, CLOCK_GetFreq(kCLOCK_MainClk));
	USART_EnableInterrupts(USART1, kUSART_RxReadyInterruptEnable);
	NVIC_EnableIRQ(USART1_IRQn);

//	ADC_EnableInterrupts(ADC0, kADC_ConvSeqAInterruptEnable);
//	NVIC_EnableIRQ(ADC0_SEQA_IRQn);
	usart1_write("Medidor de temperatura\r\n");

}

void CONFIG(void){

	BOARD_BootClockFRO24M();

	CONFIG_SWM();

	CONFIG_USART();

	SYSTICK_INIT();

	CONFIG_PINS();

	CONFIG_ADC();

}


