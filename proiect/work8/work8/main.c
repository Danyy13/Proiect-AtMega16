/*
 * work8.c
 *
 * Created: 15.07.2024 10:36:46
 * Author : dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/delay.h>
#include "Adc.h"
#include "serial.h"
 
int main(void)
{
	USART_init();
    ADC_init();
	
	uint32_t result = 0;
	char rez[120]="";
    while (1) 
    {
		//sendString("adaffg");
		startConversion();
		
		result = getResult();
		
		sprintf(rez,"%03X\n",result);
		sendString(rez);
		_delay_ms(200);
		
    }
	
}

