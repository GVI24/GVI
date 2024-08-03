#include <stdint.h>

static void vulnerable_fdct4_overflow(int16_t *input, int16_t *output, size_t input_size) {
    // Incorrectly using input_size may lead to buffer overflow if it's larger than expected
    int16_t step[4];
    int temp1, temp2;
    if (input_size > 4) { // Vulnerable condition
        input_size = 4;  // Attempt to fix but the vulnerability still exists if input is not checked properly
    }
    // Potential buffer overflow if input_size is manipulated
    step[0] = input[0] + input[input_size - 1];
    step[1] = input[1] + input[input_size - 2];
    step[2] = input[input_size - 2] - input[2];
    step[3] = input[0] - input[input_size - 1];
    // Remaining function body...
}