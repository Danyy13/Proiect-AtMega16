/*
 * Adc.c
 *
 * Created: 15.07.2024 11:13:39
 *  Author: dspproject
 */ 

#include <avr/io.h>
#include <stdint.h>

void ADC_init() {
	DDRA = 0; // set pin PA0 as input
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADMUX = (1 << REFS0) | 1;
}

void startConversion() {
	if(!(1 & (ADCSRA >> ADSC))) {
		ADCSRA |= (1 << ADSC);
	}
}

uint32_t getResult() {
	uint32_t high = 0, low = 0;
	
	// verificam daca s-a terminat conversia
	while(1 & (ADCSRA >> ADSC)) {} // astept sa se termine conversia
	
	low = ADCL;
	high = ADCH;
	high <<= 8;
	
	return high | low;
}