/*
 * COM.c
 *
 *  Created on: 20 ago. 2024
 *      Author: Franco
 */
#include "COM.h"

uint32_t to_modify=0;
bool flag_data = false, init_rx = false;
uint8_t buffer_data[MAX_BUFF], buff_position = 0, usart;

void usart_write_byte(uint8_t data){
	while (!(USART1->STAT & 0x4));
	USART_WriteByte(USART1, data);
	while (!(USART1->STAT & 0x8));
}

uint8_t get_word(char *string, uint8_t finish)
{
	for(int i=0; buffer_data[finish]!=' ' && buffer_data[finish]!=END_CHR; i++){
		string[i]=buffer_data[finish];
		finish++;
	}
	finish++;
	return finish;
}

uint8_t get_number_string(char *value, uint8_t finish)
{
	for(int i=0; buffer_data[finish]!=' ' && buffer_data[finish]!=END_CHR; i++){
		if((buffer_data[finish]<'0' || buffer_data[finish]>'9') && buffer_data[finish]!='-')
		{
			usart1_write("Error: Value is not integer number\r\n");
			return 0;
		}
		value[i]=buffer_data[finish];
		finish++;
	}
	return finish++;
}

uint32_t get_num_from_string_unsigned(char *p){

	uint32_t num = 0;
	uint8_t len = strlen(p);
//	uint8_t c = 0;


//	while(p[c] != 0){
//		len++;
//		c++;
//	}

	for(int i = 0; p[i] >=48 && p[i]<=57; i++){
		num += (p[i]-48) * pow(10, len - i - 1);
	}

	return (uint32_t) num;
}

int get_num_from_string(char *p){

	int sign = 1;
	int num = 0;
//	uint8_t c = 0;


//	while(p[c] != 0){
//		len++;
//		c++;
//	}
	if(p[0]=='-')
	{
		sign=-1;
		p++;
	}

	uint8_t len = strlen(p);

	for(int i = 0; p[i] >=48 && p[i]<=57; i++){
		num += (p[i]-48) * pow(10, len - i - 1);
	}

	num *= sign;

	return num;
}

void action(void){
	uint8_t finish = 0;
	char str_to_send[64] = " ";
	char function[5]=" ";
	char option[15]= " ";
	char value[6]= " ";

	finish = get_word(function, finish);

	if(strcmp("set", function)==0){
		finish = get_word(option, finish);

		if(strcmp("time", option)==0){

			finish = get_number_string(value, finish);

			if(finish == 0) return;

			uint32_t number = get_num_from_string_unsigned(value);


			if(number>0)
			{
				delta_time_seconds = number;
				sprintf(str_to_send, "set %s in %d seconds\r\n", option, delta_time_seconds);
				usart1_write(str_to_send);
				return;
			}
			else
			{
				usart1_write("Error: The number must be greater than 0\r\n");
				return;
			}

		}
		else if(strcmp("lim_0", option)==0){
			finish = get_number_string(value, finish);

			if(finish == 0) return;

			int number = get_num_from_string(value);

			lim_temp_0 = number;

			sprintf(str_to_send, "set %s in %d C\r\n", option, lim_temp_0);
			usart1_write(str_to_send);
			return;
			}
		else if(strcmp("lim_1", option)==0){
			finish = get_number_string(value, finish);

			if(finish == 0) return;

			int number = get_num_from_string(value);

			lim_temp_1 = number;

			sprintf(str_to_send, "set %s in %d C\r\n", option, lim_temp_1);
			usart1_write(str_to_send);
			return;
		}
		else
		{
			usart1_write("Error: Unknown option\r\n");
		}
		}
	if(strcmp("get", function)==0){
		finish = get_word(option, finish);
		if(strcmp("limits", option)==0){
			sprintf(str_to_send, "limit 0: %d C\r\nlimit 1: %d C\r\n", lim_temp_0, lim_temp_1);
			usart1_write(str_to_send);
		}
		else if(strcmp("time", option)==0){
			sprintf(str_to_send, "time: %d seconds\r\n", delta_time_seconds);
			usart1_write(str_to_send);
		}
		else
		{
			usart1_write("Error: Unknown option\r\n");
		}
	}
	else if(strcmp("help", function)==0){
		usart1_write("set: \r\n\t-time\r\n\t-lim_0\r\n\t-lim_1 \r\n get: \r\n\t-time\r\n\t-limits\r\n");
	}
	else
	{
		usart1_write("Error: Unknown function\r\n");
	}

}

void USART(void){

	if(flag_data){
		action();
		clean_buffer();
		flag_data = false;
	}
}

void USART1_IRQHandler(void){

	usart=USART_ReadByte(USART1);

	if(usart == INIT_CHR)
	{
		clean_buffer();
		init_rx = true;
		return;
	}
	if(init_rx)
	{
		buffer_data[(buff_position<MAX_BUFF)?(buff_position++):0] = USART_ReadByte(USART1);
		if(usart == END_CHR)
		{
			buff_position = 0;
			flag_data = true;
			init_rx = false;
			return;
		}
	}

}

