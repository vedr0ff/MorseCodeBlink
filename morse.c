#include <string.h>
#include "morse.h"

char *codes[36] = {
    "-----", /* 0 */
    ".----", /* 1 */
    "..---", /* 2 */
    "...--", /* 3 */
    "....-", /* 4 */
    ".....", /* 5 */
    "-....", /* 6 */
    "--...", /* 7 */
    "---..", /* 8 */
    "----.", /* 9 */
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

void play_letter(char letter) {
    char *morse;

    if (letter >= '0' && letter <= '9') {
        morse = codes[letter - 48];
    } else {
        morse = codes[letter - 65 + 10];
    }

    for (int i = 0; i < strlen(morse); i++) {
        char l = morse[i];
        uint32_t delay = 0;
        delay = l == '.' ? 100 : 300;
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        HAL_Delay(delay);
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        HAL_Delay(100);
    }

    HAL_Delay(200);
}

void play_message(const char *message) {
    strupr(message);
    size_t lenght = strlen(message);

    for (int i = 0; i < lenght; i++) {
        char letter = message[i];

        // If the symbol is not in morse code table we treat it as space.
        if (!((letter >= '0' && letter <= '9') || (letter >= 'A' && letter <= 'Z'))) {
            HAL_Delay(400);
        } else {
            play_letter(letter);
        }
    }
}