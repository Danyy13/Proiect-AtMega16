/*
 * work3.c
 *
 * Created: 23.04.2024 11:24:41
 * Author : dspproject
 */ 

#include <avr/io.h>
#include "timer.h"

#define F_CPU 14745600UL

int main(void) {
	
	DDRA = 0x03;
	
	TCCR1B = (1<< WGM12) | (1 << CS12);
	OCR1A = 0xE100; // 0xE100 = valoare pentru t = 1 secunda
	PORTA = 2;
	
	TCNT1 = 0;
	
	while (1)
    {
		if(timer1_match()) {
			PORTA = ~PORTA;
			timer1_resetAfterMatch();
		}
    }
}