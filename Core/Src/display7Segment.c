#include "display7Segment.h"

void display(int led, GPIO_PinState a, GPIO_PinState b, GPIO_PinState c,
		GPIO_PinState d, GPIO_PinState e, GPIO_PinState f,GPIO_PinState g) {
	if(led == LED_7SEG_12){
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, a);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, b);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, c);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, d);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, e);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, f);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, g);
	}
	if(led == LED_7SEG_34){
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, a);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, b);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, c);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, d);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, e);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, f);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, g);
	}
  }

void display7Segment12(int state){

	 switch (state) {
	        case 0:
	            display(LED_7SEG_12, 0, 0, 0, 0, 0, 0, 1);
	            break;
	        case 1:
	            display(LED_7SEG_12, 1, 0, 0, 1, 1, 1, 1);
	            break;
	        case 2:
	            display(LED_7SEG_12, 0, 0, 1, 0, 0, 1, 0);
	            break;
	        case 3:
	            display(LED_7SEG_12, 0, 0, 0, 0, 1, 1, 0);
	            break;
	        case 4:
	            display(LED_7SEG_12, 1, 0, 0, 1, 1, 0, 0);
	            break;
	        case 5:
	            display(LED_7SEG_12, 0, 1, 0, 0, 1, 0, 0);
	            break;
	        case 6:
	            display(LED_7SEG_12, 0, 1, 0, 0, 0, 0, 0);
	            break;
	        case 7:
	            display(LED_7SEG_12, 0, 0, 0, 1, 1, 1, 1);
	            break;
	        case 8:
	            display(LED_7SEG_12, 0, 0, 0, 0, 0, 0, 0);
	            break;
	        case 9:
	            display(LED_7SEG_12, 0, 0, 0, 0, 1, 0, 0);
	            break;
	        default:
	            display(LED_7SEG_12, 1, 1, 1, 1, 1, 1, 1);
	        }

}

void display7Segment34(int state ){
	 switch (state) {
	        case 0:
	            display(LED_7SEG_34, 0, 0, 0, 0, 0, 0, 1);
	            break;
	        case 1:
	            display(LED_7SEG_34, 1, 0, 0, 1, 1, 1, 1);
	            break;
	        case 2:
	            display(LED_7SEG_34, 0, 0, 1, 0, 0, 1, 0);
	            break;
	        case 3:
	            display(LED_7SEG_34, 0, 0, 0, 0, 1, 1, 0);
	            break;
	        case 4:
	            display(LED_7SEG_34, 1, 0, 0, 1, 1, 0, 0);
	            break;
	        case 5:
	            display(LED_7SEG_34, 0, 1, 0, 0, 1, 0, 0);
	            break;
	        case 6:
	            display(LED_7SEG_34, 0, 1, 0, 0, 0, 0, 0);
	            break;
	        case 7:
	            display(LED_7SEG_34, 0, 0, 0, 1, 1, 1, 1);
	            break;
	        case 8:
	            display(LED_7SEG_34, 0, 0, 0, 0, 0, 0, 0);
	            break;
	        case 9:
	            display(LED_7SEG_34, 0, 0, 0, 0, 1, 0, 0);
	            break;
	        default:
	            display(LED_7SEG_34, 1, 1, 1, 1, 1, 1, 1);
	        }

}
