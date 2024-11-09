#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NUMBER_BUTTON	3

extern int button_flag[];
extern int button_pressed_1s_flag[];

void getKeyInput();
void KeyProcess(int index);

#endif
