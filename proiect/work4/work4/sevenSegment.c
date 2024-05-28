/*
 * CFile1.c
 *
 * Created: 28.05.2024 12:34:22
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
