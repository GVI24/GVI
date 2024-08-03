#include <stdint.h>
#include <stdlib.h>

#define MAX_AUDIO_FRAME_SIZE 1024

int process_audio_signal(uint8_t *input_buffer, int input_size, int16_t *output_buffer) {
    if (input_size < 1 || input_buffer == NULL || output_buffer == NULL) {
        return -1;
    }

    int signal_strength;
    int output_index = 0;

    for (int i = 0; i < input_size; i += 2) {
        signal_strength = input_buffer[i];
        for (int j = 0; j < signal_strength; j++) {
            // Vulnerability: output_index could exceed MAX_AUDIO_FRAME_SIZE
            output_buffer[output_index++] = (int16_t)(input_buffer[i+1] - 128) * 256;
        }
    }

    return 0;
}