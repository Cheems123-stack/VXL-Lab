#include "normal_mode.h"

//status of traffic light
int state_led=0;
//the time of status of traffic light
int counter_second=-1;
//countdown the time of led_red
int counter_red=0;
//countdown the time of led_green
int counter_green=0;
//countdown the time of led_yellow
int counter_yellow=0;
//turn on or turn off 4 led7segment
int status_led7segment=0;
//count the time of led_green or led_yellow
int counter_second1=0;

void traffic_light(){
	if(state_led == 0){
		counter_second++;
		if(counter_second < time_green){
			  //trang thai 1: led_red_1,led_green_2: bat
			  //			led_yellow_1,led_green_1,led_red_2,led_yellow_2:tat
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin,1);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin,0);
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin,0);
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin,0);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin,1);
			  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin,0);
		}
		if(counter_second >= time_green){
			  //trang thai 2: led_red_1,led_yellow_2: bat
			  //			led_yellow_1,led_green_1,led_red_2,led_green_2:tat
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin,1);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin,0);
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin,0);
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin,0);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin,0);
			  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin,1);
		}
		if(counter_second == time_red){
			  // set lai gia tri cua state_led va counter_second
			  state_led=1;
			  counter_second=-1;
		}
	}
	  if(state_led==1){
		  counter_second++;
		  if(counter_second<time_green){
			  //trang thai 1: led_red_2,led_green_1: bat
			  //			led_yellow_1,led_green_2,led_red_1,led_yellow_2:tat
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin,0);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin,0);
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin,1);
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin,1);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin,0);
			  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin,0);
		  }
		  if(counter_second>=time_green){
			  //trang thai 2: led_red_2,led_yellow_1: bat
			  //			led_yellow_2,led_green_1,led_red_1,led_green_2:tat
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin,0);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin,1);
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin,0);
			  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin,1);
			  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin,0);
			  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin,0);
		  }
		  if(counter_second==time_red-1){
			  //set lại gia tri cua state_led va counter_second
			  state_led=0;
			  counter_second=-1;
		  }
	  }
}

void displayFour7Segemnt(){
	//display led7segment 1 and 3
	if(state_led==0&&status_led7segment==0){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7Segment12((time_red-counter_red)/10);
		if(counter_second1<time_green) display7Segment34((time_green-counter_green)/10);
		if(counter_second1>=time_green) display7Segment34((time_yellow-counter_yellow)/10);
	}
	//display led7segment 2 and 4
	if(state_led==0&&status_led7segment==1){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		display7Segment12(time_red-counter_red-((time_red-counter_red)/10)*10);
		if(counter_second1<time_green) {
			display7Segment34(time_green-counter_green-((time_green-counter_green)/10)*10);
			if(counter_green<time_green){
					counter_green++;
					if(counter_green>=time_green) counter_green=0;
			}
		}
		if(counter_second1>=time_green){
			display7Segment34(time_yellow-counter_yellow-((time_yellow-counter_yellow)/10)*10);
			if(counter_yellow<time_yellow){
					counter_yellow++;
					if(counter_yellow>=time_yellow) counter_yellow=0;
			}
		}
		if(counter_red<time_red){
				counter_red++;
				if(counter_red>=time_red) counter_red=0;
		}
		counter_second1++;
		if(counter_second1==time_red) counter_second1=0;
	}
	//display led7segment 1 and 3
	if(state_led==1&&status_led7segment==0){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7Segment34((time_red-counter_red)/10);
		if(counter_second1<time_green) display7Segment12((time_green-counter_green)/10);
		if(counter_second1>=time_green) display7Segment12((time_yellow-counter_yellow)/10);
	}
	//display led7segemnt 2 and 4
	if(state_led==1&&status_led7segment==1){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		display7Segment34(time_red-counter_red-((time_red-counter_red)/10)*10);
		if(counter_second1<time_green) {
			display7Segment12(time_green-counter_green-((time_green-counter_green)/10)*10);
			if(counter_green<time_green){
					counter_green++;
					if(counter_green>=time_green) counter_green=0;
			}
		}
		if(counter_second1>=time_green){
			display7Segment12(time_yellow-counter_yellow-((time_yellow-counter_yellow)/10)*10);
			if(counter_yellow<time_yellow){
					counter_yellow++;
					if(counter_yellow>=time_yellow) counter_yellow=0;
			}
		}
		if(counter_red<time_red){
				counter_red++;
				if(counter_red>=time_red) counter_red=0;
		}
		counter_second1++;
		if(counter_second1==time_red) counter_second1=0;
	}
	status_led7segment=1-status_led7segment;
}

void setValueLocalNormalMode(){
	//status of traffic light
	state_led=0;
	//the time of status of traffic light
	counter_second=-1;
	//countdown the time of led_red
	counter_red=0;
	//countdown the time of led_green
	counter_green=0;
	//countdown the time of led_yellow
	counter_yellow=0;
	//turn on or turn off 4 led7segment
	status_led7segment=0;
	//count the time of led_green or led_yellow
	counter_second1=0;
}

void normalMode(){
	if(timer1_flag == 1){
		setTimer1(1000);
		traffic_light();
	}
	if(timer2_flag == 1){
		setTimer2(250);
		displayFour7Segemnt();
	}
}
