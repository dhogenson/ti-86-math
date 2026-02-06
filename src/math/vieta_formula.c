#include <stdio.h>
#include <conio.h>
#include "the_game.h"
#include "input.h"
#include "fixed_point.h"


void vieta_formula(void)
{
    int s;
    int p;
    long disc;
    unsigned int sqrt_disc;
    int x1, x2;

    clrscr();

    s = get_number("Add number: ");
    p = get_number("Mult number: ");

    /* Solve x^2 - Sx + P = 0, discriminant = S^2 - 4P */
    disc = (long)s * s - 4L * p;

    if (disc < 0)
    {
        printf("No match found\n");
        getchar();
        return;
    }

    sqrt_disc = int_sqrt((unsigned long)disc);

    /* Only valid if discriminant is a perfect square */
    if ((long)sqrt_disc * sqrt_disc != disc)
    {
        printf("No match found\n");
    }
    else if ((s + (int)sqrt_disc) % 2 != 0)
    {
        /* Roots aren't integers if (S +/- sqrt) is odd */
        printf("No match found\n");
    }
    else
    {
        x1 = (s + (int)sqrt_disc) / 2;
        x2 = (s - (int)sqrt_disc) / 2;
        printf("Found match: %d, %d\n", x1, x2);
    }


    getchar();
    clrscr();
}
