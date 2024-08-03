// Vulnerable due to lack of bounds checking
#include <stdint.h>
#include <stdlib.h>

#define VIDEO_FRAME_WIDTH 1920
#define VIDEO_FRAME_HEIGHT 1080
#define BUFFER_SIZE 4096
void process_frame(uint8_t *frame_buffer, int frame_num, int total_frames) {
    int frame_size = VIDEO_FRAME_WIDTH * VIDEO_FRAME_HEIGHT;
    if(frame_buffer == NULL) {
        return;
    }

    // Vulnerability: No bounds checking on frame_num, potential integer overflow
    uint8_t *current_frame = &frame_buffer[frame_size * frame_num];

    // Simulated frame processing
    for (int i = 0; i < frame_size; i++) {
        current_frame[i] = (current_frame[i] + 128) % 256;  // In-place modification
    }
}
