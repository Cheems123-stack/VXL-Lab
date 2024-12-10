#include <command_fsm.h>


#define MAX_BUFFER_SIZE 30

char line_of_command[50] ="";
char INDEX = 0;
char FINISH = 0;
int  state_parser =0;


UART_HandleTypeDef huart2;
uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t buffer[MAX_BUFFER_SIZE];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart){
	if(huart->Instance == USART2){
		buffer[index_buffer++] = temp ;
		HAL_UART_Transmit (&huart2 ,&temp ,1,50) ;
		if(index_buffer >= MAX_BUFFER_SIZE) index_buffer = 0;
		buffer_flag = 1;
	    HAL_UART_Receive_IT(&huart2,&temp,1);
	}
}


void command_parser_fsm(){
	switch(state_parser){
	case 0:
		if(buffer[index_buffer-1] =='!'){
			state_parser = 1;
			INDEX = 0;
		}
		break;
	case 1:
		if(buffer[index_buffer-1]=='#'){
			state_parser = 0;
			FINISH = 1;
		}
		if(buffer[index_buffer-1]!='#'){
			line_of_command[INDEX++] =  buffer[index_buffer-1];
		}
		break;
	default:
		break;
	}

}
