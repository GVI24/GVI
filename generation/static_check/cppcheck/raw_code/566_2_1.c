// Vulnerable due to use of unchecked external input for memory operations
#include <stdint.h>
#include <stdlib.h>

#define VIDEO_FRAME_WIDTH 1920
#define VIDEO_FRAME_HEIGHT 1080
#define BUFFER_SIZE 4096
void transform_video(uint8_t *input_stream, uint8_t *output_stream, int stream_size, int effect) {
    if (input_stream == NULL || output_stream == NULL) {
        return;
    }

    // Vulnerability: No bounds checking on stream_size
    for (int i = 0; i < stream_size; i++) {
        switch(effect) {
            case 1: // Invert effect
                output_stream[i] = ~input_stream[i];
                break;
            case 2: // Grayscale effect
                output_stream[i] = (input_stream[i] * 30 + input_stream[i + 1] * 59 + input_stream[i + 2] * 11) / 100;
                i += 2; // Vulnerability: Possible out-of-bounds write
                break;
            default:
                output_stream[i] = input_stream[i]; // Direct copy
        }
    }
}
