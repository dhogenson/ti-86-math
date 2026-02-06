#ifndef FIXED_POINT_H
#define FIXED_POINT_H

/* Fixed-point square root using 16.16 format (16 bits integer, 16 bits fraction)
 * Range: 0 to 65535.99998 with ~0.000015 precision
 * Stored as 32-bit integer where value = real_value * 65536
 */

/* Integer square root - helper function
 * Returns floor(sqrt(n)) for n >= 0
 */
unsigned int int_sqrt(unsigned long n);

/* Fixed-point square root
 * Input: fixed-point number in 16.16 format (real_value * 65536)
 * Output: sqrt(input) in 16.16 format
 * Example: fp_sqrt(65536) = 65536 (meaning sqrt(1.0) = 1.0)
 * Example: fp_sqrt(262144) = 131072 (meaning sqrt(4.0) = 2.0)
 */
unsigned long fp_sqrt(unsigned long x);

#endif
