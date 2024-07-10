/*
 * sevenSegment.c
 *
 * Created: 10.07.2024 13:37:28
 *  Author: dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void initDigit() {
	DDRA = 0xFF;
}

void displayDigit(uint8_t digit) {
	PORTA = digit;
}

void clearDigit() {
	PORTA = 0xFF;
}
