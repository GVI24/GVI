#include <stdint.h>
#include <string.h>

int invert_image_data(uint8_t *image_data, int data_size, uint8_t *inverted_image, int max_inverted_size) {
    if (data_size > max_inverted_size) {
        // Output buffer too small
        return -1;
    }
    
    for (int i = 0; i < data_size; i++) {
        // Vulnerability: No check for inverted_image being overrun
        inverted_image[i] = ~image_data[i];
    }
    return 0;
}