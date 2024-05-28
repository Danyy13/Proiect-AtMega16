/*
 * CFile1.c
 *
 * Created: 28.05.2024 12:43:44
 *  Author: dspproject
 */ 

unsigned char timer1_match() {
	return ((TIFR >> OCF1A) & 1) == 1;
}

void timer1_resetAfterMatch() {
	TIFR |= 1 << OCF1A;
}

void timer1_init() {
	TIMSK |= 1 << OCIE1A;
}

ISR(TIMER1_COMPA_vect) {
	PORTA = ~PORTA;
}