// File name stands for simplifying radicals

#include <stdio.h>
#include <conio.h>
#include "../input.h"
#include "simp_radicals.h"

void simp_radicals(void)
{

    int number, i, largest_sq = 1, coef, radicand;

    clrscr();

    number = get_number("sqrt(");

    // Find largest perfect square factor
    for (i = 2; i * i <= number; i++) {
        if (number % (i * i) == 0) {
            largest_sq = i * i;
        }
    }

    coef = 1;
    radicand = number;

    // Extract perfect squares
    for (i = 2; i * i <= radicand; i++) {
        while (radicand % (i * i) == 0) {
            coef *= i;
            radicand /= (i * i);
        }
    }

    // Display result
    if (radicand == 1) {
        printf(")=%d\n", coef);
    } else if (coef == 1) {
        printf(")=sqrt(%d)\n", radicand);
    } else {
        printf(")=%d*sqrt(%d)\n", coef, radicand);
    }

    getchar();
}
