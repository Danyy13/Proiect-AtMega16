/*
 * GccApplication1.c
 *
 * Created: 23.04.2024 10:19:21
 * Author : dspproject
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>

#define ledNumber 8
#define UP PINB & 1
#define DOWN (PINB >> 2) & 1

int main(void)
{
    /* Replace with your application code */
	unsigned char currentLED = 0; // LED-ul curent pe care il aprindem
	
	// set PORTA as output
	for(unsigned int i=0;i<ledNumber;i++) {
		DDRA |= 1 << i;
	}
	
	// set PORTB as input
	DDRB = ~5; // 11111010
	
	while (1)
    {
		if(UP) {
			_delay_ms(0.2);
			if(UP)
				currentLED++;
		}
		if(DOWN) {
			_delay_ms(0.2);
			if(DOWN)
				currentLED--;
		}
		currentLED %= 8;
		PORTA = ~(1 << currentLED);
		_delay_ms(100);
    }
}

