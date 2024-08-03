#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

void process_video_frame(uint8_t *frame_data, size_t width, size_t height) {
    // Vulnerable: Integer overflow could occur here if width or height are too large.
    size_t total_pixels = width * height;

    uint8_t *new_frame_data = (uint8_t*)malloc(total_pixels);
    if (new_frame_data == NULL) {
        perror("Allocation failed");
        return;
    }

    for (size_t i = 0; i < total_pixels; i++) {
        new_frame_data[i] = frame_data[i] / 2; // Simulate processing.
    }

    // Vulnerable: No bounds checking when copying back to frame_data.
    for (size_t i = 0; i < total_pixels; i++) {
        frame_data[i] = new_frame_data[i];
    }

    free(new_frame_data); // Cleanup.
}

int main() {
    uint8_t frame_data[800 * 600];
    process_video_frame(frame_data, 800, 600);
    return 0;
}