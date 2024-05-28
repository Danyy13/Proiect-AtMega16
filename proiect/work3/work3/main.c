/*
 * work3.c
 *
 * Created: 23.04.2024 11:24:41
 * Author : dspproject
 */

#define F_CPU 14745600UL

#include <avr/interrupt.h>
#include <avr/io.h>

int main(void) {
	
	DDRA = 0x03;
	
	TCCR1B = (1<< WGM12) | (1 << CS12);
	// OCR1A = 0x7080; // 0xE100 = valoare pentru t = 1 secunda // OCR1AH L
	OCR1AH = 0x70;
	OCR1AL = 0x80;
	PORTA = 2;
	
	timer1_init();
	sei();
	while(1) {
		
	}
	cli();
	
	// polling
	/*while (1)
    {
		if(timer1_match()) {
			PORTA = ~PORTA;
			timer1_resetAfterMatch();
		}
    } */
	
}