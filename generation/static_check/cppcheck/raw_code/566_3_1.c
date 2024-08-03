// Vulnerable function performing encoding with unchecked array indexing
#include <stdint.h>
#include <stdlib.h>

#define VIDEO_FRAME_WIDTH 1920
#define VIDEO_FRAME_HEIGHT 1080
#define BUFFER_SIZE 4096
void encode_audio_samples(int16_t *audio_samples, int sample_count, int channels, uint8_t *encoded_output) {
    int i, ch;
    // Vulnerability: No checks on audio_samples or encoded_output
    for (i = 0; i < sample_count; i++) {
        for (ch = 0; ch < channels; ch++) {
            // Vulnerability: Potential out-of-bounds access on audio_samples
            int sample_index = ch * sample_count + i;
            // Simulate audio sample encoding
            // Vulnerability: No bounds checking on encoded_output
            encoded_output[i * channels + ch] = (uint8_t)((audio_samples[sample_index] >> 8) & 0xFF);
        }
    }
}