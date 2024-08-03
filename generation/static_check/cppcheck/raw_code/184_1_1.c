#include <stdint.h>

static void vulnerable_fdct4_int_overflow(const int16_t *input, int16_t *output) {
    int16_t step[4];
    long temp1, temp2; // changed to long to make overflow less likely but still possible
    step[0] = input[0] + input[3];
    step[1] = input[1] + input[2];
    step[2] = input[1] - input[2];
    step[3] = input[0] - input[3];
    // Integer overflow vulnerability when large values are multiplied
    temp1 = ((long)step[0] + step[1]) * INT16_MAX;
    temp2 = ((long)step[0] - step[1]) * INT16_MAX;
    output[0] = (int16_t)((temp1 >> 16) & 0xFFFF); // Manual shift to imitate rounding
    output[2] = (int16_t)((temp2 >> 16) & 0xFFFF);
    // Remaining function body...
}