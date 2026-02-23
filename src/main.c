#include <stdio.h>
#include <conio.h>
#include "input.h"
#include "math/vieta_formula.h"
#include "math/simp_radicals.h"
#include "math/parabola.h"
#include "menu.h"

// Test function for raw inputs
void raw_char_test(void)
{
    clrscr();

    unsigned char c = lcd_getkey();
    printf("Hex dec:\n");
    printf("%x", c);

    getchar(); // Wait for input

    clrscr();

}

// Empty function
void quit(void)
{
}

// Main loop function
int main(void)
{
    char *names[] = {"Vietas formula", "Simp radicals", "Parabola", "Quit"};
    func_p functions[] = {vieta_formula, simp_radicals, parabola, quit};

    while (1)
    {
        int selected = menu(functions, names, 3);
        // Break out if user selects quit
        if (selected == 2)
        {
            break;
        }
    }

    return 0;
}
