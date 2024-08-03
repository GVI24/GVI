#include <string.h>

void copy_frame_data(uint8_t *dest, const uint8_t *src, int size, int offset) {
    // Incorrect validation: doesn't prevent negative offset, can lead to buffer underflow.
    if (offset < size) { 
        // Buffer underflow if offset is negative.
        memcpy(dest + offset, src, size); // <- Possible buffer underflow if offset is negative.
    }
}