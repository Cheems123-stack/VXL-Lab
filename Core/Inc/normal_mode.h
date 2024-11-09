#ifndef INC_NORMAL_MODE_H_
#define INC_NORMAL_MODE_H_

#include "main.h"


//status of traffic light
int state_led;
//the time of status of traffic light
int counter_second;
//countdown the time of led_red
int counter_red;
//countdown the time of led_green
int counter_green;
//countdown the time of led_yellow
int counter_yellow;
//turn on or turn off 4 led7segment
int status_led7segment;
//count the time of led_green or led_yellow
int counter_second1;

void normalMode();
void setValueLocalNormalMode();


#endif
