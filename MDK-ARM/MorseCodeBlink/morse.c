#include <string.h>
#include "morse.h"

char *codes[26] = {
    ".-",    /* A */
    "-...",  /* B */
    "-.-.",  /* C */
    "-..",   /* D */
    ".",     /* E */
    "..-.",  /* F */
    "--.",   /* G */
    "....",  /* H */
    "..",    /* I */
    ".---",  /* J */
    "-.-",   /* K */
    ".-..",  /* L */
    "--",    /* M */
    "-.",    /* N */
    "---",   /* O */
    ".--.",  /* P */
    "--.-",  /* Q */
    ".-.",   /* R */
    "...",   /* S */
    "-",     /* T */
    "..-",   /* U */
    "...-",  /* V */
    ".--",   /* W */
    "-..-",  /* X */
    "-.--",  /* Y */
    "--.."   /* Z */
};

void play_symbol(char symbol) 
{
    char *morse;
    morse = codes[symbol - 65];

    for (int i = 0; i < strlen(morse); i++) 
				{
         char l = morse[i];
         uint32_t delay = 0;
				 
				 if(l == '.')
						delay = 100;
					else
						  delay = 300;
					
         HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
         HAL_Delay(delay);
         HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
         HAL_Delay(100);
				}

    HAL_Delay(200);
}

void play_message(const char *message) 
{
    size_t lenght = strlen(message);

    for (int i = 0; i < lenght; i++) 
				{
         char symbol = message[i];
         if (!(symbol >= 'A' && symbol <= 'Z')) 
					 {
            HAL_Delay(400);
					 } 
					else 
							{
							 play_symbol(symbol);
							}
				}
}
