typedef struct {
    int16_t *samples;
    int num_samples;
} AudioBuffer;

static int apply_audio_echo_effect(AudioBuffer *buffer, int delay_samples) {
    if (!buffer || delay_samples < 0) {
        return -1;
    }

    // Vulnerability: No validation that num_samples - delay_samples is non-negative
    int16_t *echo_buffer = (int16_t *)malloc(buffer->num_samples * sizeof(int16_t));
    for (int i = 0; i < buffer->num_samples - delay_samples; i++) {
        echo_buffer[i + delay_samples] = buffer->samples[i]; // Potential out-of-bounds read
    }

    // Copy back the processed data
    for (int i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = echo_buffer[i];
    }

    free(echo_buffer);
    
    return 0;
}

