#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAMPLES 1024

int convert_sample_rate(uint8_t *in_buf, int in_size, uint8_t *out_buf, int out_buf_size, int *converted_size) {
    int sample_count = in_size / 2; // each sample is 2 bytes
    if (sample_count * 4 > out_buf_size) {
        // Output buffer is not large enough
        return -1;
    }
    
    int16_t *in_samples = (int16_t *)in_buf;
    *converted_size = 0;
    for (int i = 0; i < sample_count; i++) {
        // Upsample from 22.05kHz to 44.1kHz by duplicating each sample
        int16_t sample = in_samples[i];
        // Vulnerability: No check for out_buf being overrun
        memcpy(out_buf + (*converted_size), &sample, sizeof(sample));
        *converted_size += sizeof(sample);
        memcpy(out_buf + (*converted_size), &sample, sizeof(sample));
        *converted_size += sizeof(sample);
    }
    return 0;
}