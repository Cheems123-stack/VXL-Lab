#include "button.h"


int KeyReg0[NUMBER_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUMBER_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUMBER_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUMBER_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimerForKeyPress[NUMBER_BUTTON] =  {100,100,100};
int button_flag[NUMBER_BUTTON] =  {0,0,0};
int button_pressed_1s_flag[NUMBER_BUTTON] =  {0,0,0};

void subKeyProcess(int i){
	button_flag[i] = 1;
}
void getKeyInput() {
    for(int i = 0; i < NUMBER_BUTTON; i++) {  // Step 1: Loop over each button
        KeyReg0[i] = KeyReg1[i];  // Step 2: Shift debouncing register values
        KeyReg1[i] = KeyReg2[i];

        // Step 3: Read the current state of the button i
        if(i == 0) KeyReg2[i] = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
        if(i == 1) KeyReg2[i] = HAL_GPIO_ReadPin(MODIFY_GPIO_Port, MODIFY_Pin);
        if(i == 2) KeyReg2[i] = HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);

        // Step 4: Check if the button state is stable (debounced)
        if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
            // Step 5: Detect a change in the button state
            if(KeyReg3[i] != KeyReg2[i]) {
                KeyReg3[i] = KeyReg2[i];  // Update the stable button state

                // Step 6: If button is pressed, set the flag and reset the timer
                if(KeyReg2[i] == PRESSED_STATE) {
                    subKeyProcess(i);
                    TimerForKeyPress[i] = 100;  // Reset the timer for 1s press
                } else {
                    // Step 7: If button is released, reset the long press flag
                    button_pressed_1s_flag[i] = 0;
                }
            } else {
                // Step 8: If button state hasn't changed, decrease the timer
                TimerForKeyPress[i]--;

                // Step 9: If timer reaches 0, check if button is still pressed
                if(TimerForKeyPress[i] == 0) {
                    if(KeyReg2[i] == PRESSED_STATE) {
                        button_pressed_1s_flag[i] = 1;  // Set long press flag
                    } else {
                        button_pressed_1s_flag[i] = 0;
                    }
                    TimerForKeyPress[i] = 100;  // Reset timer
                }
            }
        }
    }




}
