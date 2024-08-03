#include <stdint.h>
#include <stdlib.h>

#define DATA_OFFSET 5
#define SAMPLE_BLOCK_SIZE 4

void convert_samples(uint8_t *in_buf, int in_size, int16_t *out_buf) {
    int i = DATA_OFFSET;

    if (in_size <= DATA_OFFSET)
        return;

    // Move past the data offset
    in_buf += DATA_OFFSET;
    in_size -= DATA_OFFSET;

    // Assuming each block contains SAMPLE_BLOCK_SIZE samples without validating
    while (i < in_size) {
        // Potential overflow if in_buf doesn't hold enough data for SAMPLE_BLOCK_SIZE samples
        for (int j = 0; j < SAMPLE_BLOCK_SIZE; j++) {
            // Direct assignment without bounds check can lead to buffer overflow
            *out_buf++ = (int16_t)(*in_buf++); // Assuming 8-bit to 16-bit conversion
        }
        i += SAMPLE_BLOCK_SIZE;
    }
}