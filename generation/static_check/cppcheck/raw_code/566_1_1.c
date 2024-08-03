// Vulnerable due to unchecked buffer size and pointer arithmetic
#include <stdint.h>
#include <stdlib.h>

#define VIDEO_FRAME_WIDTH 1920
#define VIDEO_FRAME_HEIGHT 1080
#define BUFFER_SIZE 4096
void copy_frame(uint8_t *source, uint8_t *destination, int width, int height) {
    if (source == NULL || destination == NULL) {
        return;
    }

    // Vulnerability: No check for source buffer size
    // Vulnerability: Potential integer overflow in width * height
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            destination[i * width + j] = source[i * width + j];
        }
    }
}
