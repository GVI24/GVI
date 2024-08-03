#include <stdint.h>

static void vulnerable_fdct4_uninitialized(int16_t *input, int16_t *output, int init_flag) {
    int16_t step[4];
    int temp1, temp2;
    // Conditional initialization leads to use of uninitialized memory
    if (init_flag) {
        for (int i = 0; i < 4; i++) {
            step[i] = 0;
        }
    }
    // If init_flag is false, step array contains garbage values leading to undefined behavior
    temp1 = (step[0] + step[1]) * cospi_16_64;
    temp2 = (step[0] - step[1]) * cospi_16_64;
    output[0] = temp1 /* missing rounding operation */;
    output[2] = temp2 /* missing rounding operation */;
    // Remaining function body...
}