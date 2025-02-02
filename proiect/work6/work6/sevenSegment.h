/*
 * sevenSegment.h
 *
 * Created: 10.07.2024 13:36:24
 *  Author: dspproject
 */ 

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

static const uint8_t digitMap[10] = {
	0b11000000,
	0b11111001,
	0b10100100,
	0xB0,
	0b10011001,
	0b10010010,
	0b10000010,
	0xF8,
	0b10000000,
	0b10010000
};

void initDigit();
void displayDigit(uint8_t);
void clearDigit();

#endif /* SEVENSEGMENT_H_ */