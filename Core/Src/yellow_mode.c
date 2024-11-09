#include "green_mode.h"
void yellowBlinking(){
	//turn off all led
	if(clear_all_traffic_led==0){
		clear_all_traffic_led=1;
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin,0);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin,0);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin,0);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin,0);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin,0);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin,0);
	}
	//blinking led-green
	if(clear_all_traffic_led==1){
		HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
		HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
	}
}

//turn on or turn off 4 led7segment
int statusLed7SegmentMode4=0;
void displayLed7SegmentYellowMode(){
	//turn on led7segment 1 and 3
		if(statusLed7SegmentMode4==0){
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7Segment12(time_yellow/10);
			display7Segment34(0);
		}
		//turn on led7segment 2 and 4
		if(statusLed7SegmentMode4==1){
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			display7Segment12(time_yellow-10*(time_yellow/10));
			display7Segment34(4);
		}
		statusLed7SegmentMode4=1-statusLed7SegmentMode4;
}

//increase the timer of led-green when press button 2(button_flag[1]=1)
void addTimeYellow(){
	if(button_flag[1]==1 || button_pressed_1s_flag[1]==1){
		button_flag[1]=0;
		button_pressed_1s_flag[1]=0;
		time_yellow++;
		if(time_green>99) time_yellow=1;
	}
}

void setTimeYellow(){
		if(time_green+time_yellow>99) {
			time_red=99;
			time_green=time_red-time_yellow;
		}
		if(time_green+time_yellow<=99) {
			time_red=time_green+time_yellow;
	    }
}

void yellowMode(){
	addTimeYellow();
	if(timer1_flag==1){
		setTimer1(250);
		yellowBlinking();
		displayLed7SegmentYellowMode();
	}

}
