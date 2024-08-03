#include <stdlib.h>

void fill_frame_data(uint8_t *frame_data, int num_elements) {
    int i;
    // Integer overflow if num_elements is very large, resulting in a small allocation.
    uint8_t *buffer = (uint8_t *)malloc(num_elements * sizeof(uint8_t));

    // Heap buffer overflow if integer overflow occurred during malloc.
    for (i = 0; i < num_elements; i++) {
        buffer[i] = 0xFF; // <- Potential heap buffer overflow.
    }

    // Omitted: code to use buffer in further processing.

    free(buffer); 
}