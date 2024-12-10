

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"
#include "main.h"

extern int timer0_flag;
extern int timer1_flag;

void timer_run();
void timer_run1();
void setTimer0(int duration);
void setTimer1(int duration);

#endif /* TIMER_H_ */
