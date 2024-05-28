/*
 * CFile1.c
 *
 * Created: 28.05.2024 12:43:44
 *  Author: dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "sevenSegment.h"

void timer1_setCompareValue(uint8_t high, uint8_t low) {
	// OCR1A = 0x7080; // 0xE100 = valoare pentru t = 1 secunda // OCR1AH L
	OCR1AH = high;
	OCR1AL = low;
}

uint8_t timer1_match() {
	return ((TIFR >> OCF1A) & 1) == 1;
}

void timer1_resetAfterMatch() {
	TIFR |= 1 << OCF1A;
}

void timer1_init() {
	TIMSK |= 1 << OCIE1A;
}