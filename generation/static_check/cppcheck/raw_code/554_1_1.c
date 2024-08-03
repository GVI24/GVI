#include <stdint.h>
#include <string.h>

#define MAX_CHANNELS 2

int mix_audio_streams(uint8_t *buffers[], int sizes[], uint8_t *out_buffer, int out_size, int num_channels) {
    if (num_channels > MAX_CHANNELS) {
        // Too many audio channels
        return -1;
    }
    
    // Assuming all input streams are the same size and fit the output buffer
    for (int i = 0; i < sizes[0]; i++) {
        int sample = 0;
        for (int channel = 0; channel < num_channels; channel++) {
            // Vulnerability: No check for each buffer's size, potential buffer over-read
            sample += buffers[channel][i];
        }
        sample = sample / num_channels;
        // Vulnerability: No check for out_buffer being overrun
        out_buffer[i] = (uint8_t)(sample & 0xFF);
    }
    return 0;
}