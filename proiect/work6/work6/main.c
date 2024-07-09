/*
 * work6.c
 *
 * Created: 09.07.2024 12:52:50
 * Author : dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>

void USART_init() {
	DDRD = 0x02; // output PD1 = TX
	
	UCSRC &= ~(1 << URSEL); // am acces la UBRRH
	UBRRH = 0x00;
	UBRRL = 0x5F;
	
	UCSRA &= ~0x03;
	
	UCSRB = (1 << TXEN) | (1 << RXEN);
	
	UCSRC = 1 << URSEL | (1 << UCSZ0) | (1 << UCSZ1);
}

int register_empty() {
	return UCSRA & (1 << UDRE);
}

void send_char(char data) {
	while(!register_empty());
	UDR = data;
}

void get_char(char *data) {
	while(!(UCSRA & (1 << RXC)));
	*data = UDR;
}

int main(void)
{
	USART_init();
	DDRB = 1;

	char data = 'a', buffer = 0;
	
    while (1) {
		get_char(&data);
		_delay_ms(1000);
		if(buffer != data)
		{
			
			if(buffer != data)
			send_char(data);
			buffer = data;
		}
    }
}

