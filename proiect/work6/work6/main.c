/*
 * work6.c
 *
 * Created: 09.07.2024 12:52:50
 * Author : dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include "Serial.h"
#include "sevenSegment.h"

extern unsigned char data;
extern unsigned char flag;

int main(void)
{
	USART_init();
	initDigit();
	
	// char string[512] = "";
	// uint32_t index = 0;
	
    while (1) {
		/*sprintf(string, "ana are mere %lu\n", index);
		index++;
		sendString(string); */
		
		sei();
		
		while(!flag);
		// data = getChar();
		_delay_ms(500);
		sendChar(data);
		if(data >= '0' && data <= '9') {
			clearDigit();
			displayDigit(digitMap[data - '0']);
		}
		flag = 0;
		
		cli();
		
		/*if(buffer != data) {
			//if(buffer != data)
			sendChar(data);
			buffer = data;
		}*/
    }
}

