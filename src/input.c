#include <stdio.h>
#include <conio.h>
#include "input.h"

int get_number(char *prompt)
{
    // Get vars ready
    char buffer[10];
    int i = 0;
    unsigned char key;

    printf(prompt);

    while (1)
    {
        key = lcd_getkey(); // Get key

        if (key == DELETE_KEY && i > 0)
        {
            i--;
            buffer[i] = '\0';

            // Move cursor back, print space, move back again
            printf("\b");
            printf(" ");
            printf("\b");

            continue;
        }

        // Break if enter key pressed
        if (key == ENTER_KEY && i > 0)
        {
            break;
        }

        // Add any key through 0 - 9 to the buffer
        if (key >= KEY_0 && key <= KEY_9 && i < 9)
        {
            char digit = '0' + (key - KEY_0);
            buffer[i++] = digit;
            putchar(digit);
        } else if ((key == MINI_MINUS_KEY || key == MINUS_KEY) && i < 1)
        {
            char digit = '-';
            buffer[i++] = digit;
            putchar(digit);
        }
    }

    return atoi(buffer); // Turns the buffer list into a number
}
