/*
 * timer.h
 *
 * Created: 28.05.2024 12:45:07
 *  Author: dspproject
 */ 

#ifndef TIMER_H_
#define TIMER_H_

uint8_t timer1_setCompareValue(uint8_t, uint8_t);
uint8_t timer1_match();
void timer1_resetAfterMatch();
void timer1_init();

#endif /* TIMER_H_ */