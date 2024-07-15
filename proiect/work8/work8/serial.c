/*
 * serial.c
 *
 * Created: 10.07.2024 11:36:48
 *  Author: dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char data = 0;
volatile unsigned char flag = 0;

ISR(USART_RXC_vect) {
	data = UDR;
	flag = 1;
}

void USART_init() {
	DDRD = 0x02; // output PD1 = TX
	
	UCSRC &= ~(1 << URSEL); // am acces la UBRRH
	UBRRH = 0x00;
	//UBRRL = 0x5F; // pentru BAUD 9600
	UBRRL = 0x07;
	
	UCSRA &= ~0x03;
	
	// UCSRB = (1 << TXEN) | (1 << RXEN); // fara interrupt
	UCSRB = (1 << TXEN) | (1 << RXEN) | (1 << RXCIE); // cu interrupt
	
	UCSRC = 1 << URSEL | (1 << UCSZ0) | (1 << UCSZ1);
	
	SREG = (1 << 7);
}

int register_empty() {
	return UCSRA & (1 << UDRE);
}

void sendChar(char data) {
	while(!register_empty());
	UDR = data;
}

unsigned char getChar() {
	while(!(UCSRA & (1 << RXC)));
	return UDR;
}

void sendString(char *string)
{
	int index = 0;
	while('\0' != string[index])
		sendChar(string[index++]);
}