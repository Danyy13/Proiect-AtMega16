/*
 * serial.h
 *
 * Created: 10.07.2024 11:37:01
 *  Author: dspproject
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

extern unsigned char data;
extern unsigned char flag;

void USART_init();
void register_empty();
void sendChar(char);
unsigned char getChar();
void sendString(char *);

#endif /* SERIAL_H_ */