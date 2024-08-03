#include <stdint.h>

static void vulnerable_fdct4_underflow(int16_t *input, size_t input_size) {
    int16_t step[4];
    int temp1, temp2;
    size_t i;
    for (i = 0; i < input_size; i++) {
        step[i] = input[i] + input[i];
    }
    // Possible buffer underflow if input_size is less than 4
    temp1 = step[0] * (int16_t)0xFFFF + step[input_size]; // Underflow access here
    temp2 = step[1] * (int16_t)0xFFFF - step[input_size + 1]; // And here
    // Remaining function body...
}