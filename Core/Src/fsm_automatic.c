#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			setValueLocalNormalMode();
			status=NORMAL;
			setTimer3(1000);
			break;
		case NORMAL:
			if(timer3_flag==1){
				normalMode();
				setTimer3(500);
			}
			if(button_flag[0]==1 || button_pressed_1s_flag[0]==1){
				button_flag[0]=0;
				clear_all_traffic_led=0;
				status=RED;
				setTimer3(1000);
			}
			break;
		case RED :
			redMode();
			if(button_flag[0]==1 || button_pressed_1s_flag[0]==1){
				button_flag[0]=0;
				clear_all_traffic_led=0;
				status=GREEN;
				setTimer3(1000);
			}
			if(button_flag[2]==1 || button_pressed_1s_flag[2]==1){
				button_flag[2]=0;
				setTimeRed();
				status=INIT;
			}
			break;
		case GREEN:
			greenMode();
			if(button_flag[0]==1 || button_pressed_1s_flag[0]==1){
				button_flag[0]=0;
				clear_all_traffic_led=0;
				status=YELLOW;
				setTimer3(1000);
			}
			if(button_flag[2]==1|| button_pressed_1s_flag[2]==1){
				button_flag[2]=0;
				setTimeGreen();
				status=INIT;
			}
			break;
		case YELLOW:
			yellowMode();
			if(button_flag[0]==1 || button_pressed_1s_flag[0]==1){
				button_flag[0]=0;
				clear_all_traffic_led=0;
				status=INIT;
				setTimer3(1000);
			}
			if(button_flag[2]==1|| button_pressed_1s_flag[2]==1){
				button_flag[2]=0;
				setTimeYellow();
				status=INIT;
			}
			break;
		default:
			break;
		}
}
