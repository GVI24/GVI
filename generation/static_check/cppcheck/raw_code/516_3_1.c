#include <stdint.h>

int decode_custom_stream(uint8_t *input_stream, int stream_length, uint8_t *decoded_data) {
    if (input_stream == NULL || decoded_data == NULL || stream_length < 1) {
        return -1;
    }

    int decode_index = 0;
    for (int i = 0; i < stream_length; i++) {
        uint8_t flags = input_stream[i++];
        for (int j = 0; j < (flags & 0x07); j++) {
            // Vulnerability: decode_index could be incremented beyond the buffer bounds
            decoded_data[decode_index++] = (flags >> 3) * input_stream[i];
        }
    }

    return 0;
}