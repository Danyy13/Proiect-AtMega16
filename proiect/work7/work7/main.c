/*
 * work7.c
 *
 * Created: 12.07.2024 13:51:32
 * Author : dspproject
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include "lcd.h"

int main(void)
{
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	lcd_clrscr();
	
	char string[20] = "Hello World!";
	int index = 0;
	
	// lcd_puts(string);
		
    while (1) {
		while(string[index] != '\0')
			lcd_putc(string[index++]);
    }
}

