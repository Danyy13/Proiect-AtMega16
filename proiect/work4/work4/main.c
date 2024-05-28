/*
 * work4.c
 *
 * Created: 28.05.2024 10:34:07
 * Author : dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "sevenSegment.h"
#include "timer.h"

uint8_t digit = 0, flag = 0;

ISR(TIMER1_COMPA_vect) {
	//displayDigit(digitMap[digit++]);
	//if(digit == 10) digit = 0;
	flag++;
}

int main(void)
{
	initDigit();
	timer1_init();
	
	TCCR1B = (1<< WGM12) | (1 << CS12);
	
	timer1_setCompareValue(0x70, 0x80);
	// OCR1A = 0x7080; // 0xE100 = valoare pentru t = 1 secunda // OCR1AH L
	
	sei();
    while (1) {
		if(flag)
		{
			displayDigit(digitMap[digit++]);
			if(digit == 10) digit = 0;
			flag=0;
		}
	}
	cli();
}

