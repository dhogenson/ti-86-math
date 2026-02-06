#include <stdio.h>
#include <conio.h>
#include "menu.h"
#include "input.h"

// Updates the screen by clearing the screen and then printing everthing again
void update_menu(int selected, char *names[], int names_length)
{
    clrscr();

    // Goes through each item in the name and then prints them out
    for (int i = 0; i < names_length; i++)
    {
        // If selected add a ">" symbol
        if (i == selected)
        {
            printf(">");
        }
        printf(names[i]);
        printf("\n");
    }
}

// Menu function, displays options to the user and then calls the function
// the user selected
int menu(func_p functions[], char *names[], int names_length)
{
    int selected_index = 0;

    update_menu(selected_index, names, names_length);

    while (1)
    {
        unsigned char key = lcd_getkey();

        if (key == DOWN_ARROW)
        {
            selected_index++;
            // Bounds check
            if (selected_index == names_length)
            {
                selected_index = 0;
            }

            update_menu(selected_index, names, names_length);
        } else if (key == UP_ARROW)
        {
            selected_index--;
            // Bounds check
            if (selected_index == -1)
            {
                selected_index = names_length - 1;
            }

            update_menu(selected_index, names, names_length);
        } else if (key == ENTER_KEY)
        {
            functions[selected_index]();
            break;
        }
    }

    clrscr();
    return selected_index;
}
