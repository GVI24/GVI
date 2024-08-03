void process_audio_samples(AudioContext *ctx, int16_t *samples, int index) {
    int16_t *buffer = ctx->audio_buffer + index * 100; // Potential buffer overflow
    for (int i = 0; i < 100; i++) {
        buffer[i] = samples[i];
    }
}

