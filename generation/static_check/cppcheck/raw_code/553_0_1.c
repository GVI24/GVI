#include <stdint.h>
#include <string.h>

#define HEADER_LEN 10
#define MAX_CHANNELS 8

void decode_audio_frame(uint8_t *input_buffer, int input_size, uint8_t *output_buffer, int bits_per_sample) {
    int sample_size = bits_per_sample / 8;
    int num_channels = MAX_CHANNELS;
    int input_consumed = HEADER_LEN;

    if (input_size < HEADER_LEN)
        return;

    // Process header and get the number of samples not considering buffer overflow

    input_buffer += HEADER_LEN;
    input_size -= HEADER_LEN;

    // Incorrect assumption that the input buffer contains enough data for all channels
    while (input_consumed <= input_size - sample_size * num_channels) {
        for (int channel = 0; channel < num_channels; ++channel) {
            // Potential buffer overflow when writing samples
            memcpy(output_buffer, input_buffer, sample_size);
            output_buffer += sample_size;
            input_buffer += sample_size;
        }
        input_consumed += sample_size * num_channels;
    }
}