#include "fixed_point.h"

/* Integer square root - binary search method
 * Safe for large values, no floating point
 */
unsigned int int_sqrt(unsigned long n)
{
    unsigned long x = n;
    unsigned long y = 1;

    /* Initial guess - half the bits */
    while (x > y) {
        x = (x + y) >> 1;
        y = n / x;
    }

    return (unsigned int)x;
}

/* Fixed-point square root in 16.16 format
 * Uses Newton-Raphson iteration for precision
 */
unsigned long fp_sqrt(unsigned long x)
{
    unsigned long res;

    /* Handle edge cases */
    if (x == 0) {
        return 0;
    }
    if (x == 65536) {
        return 65536;
    }

    /* Initial approximation using integer sqrt
     * We want sqrt(x) where x is in 16.16 format
     * Start with integer sqrt and shift appropriately */
    res = (unsigned long)int_sqrt(x) << 8;  /* Multiply by 256 to get into 16.16 range */

    /* Newton-Raphson iterations: res_new = (res + x/res) / 2
     * Where x is our 16.16 fixed point input
     * To divide x by res in fixed point: (x << 16) / res */
    for (unsigned int i = 0; i < 7; i++) {
        if (res > 0) {
            /* Avoid overflow: compute (x << 16) / res carefully */
            unsigned long x_div_res = ((x << 8) / (res >> 8));
            res = (res + x_div_res) >> 1;
        }
    }

    return res;
}
