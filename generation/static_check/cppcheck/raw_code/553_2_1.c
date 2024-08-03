#include <stdint.h>

#define MAX_FRAME_SIZE 4096

void mix_audio_streams(uint16_t *dest, uint16_t *src1, uint16_t *src2, int num_samples) {
    // No bounds checking on num_samples

    for (int i = 0; i < num_samples; i++) {
        // Risk of buffer overflow if num_samples exceeds MAX_FRAME_SIZE
        dest[i] = (src1[i] / 2) + (src2[i] / 2); // Simple averaging mix
    }
}