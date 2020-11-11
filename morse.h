#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "stm32f1xx_hal.h"
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC

void play_message(const char *message);

#endif  // MORSE_CODE_H