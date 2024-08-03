static void audio_decode_frame(AudioContext *ctx, uint8_t *input, int size) {
    int index;
    int sample_count;
    sample_count = *(int *)input; // Dangerous cast from input data

    // Potential buffer overflow if sample_count is too large
    for (index = 0; index < sample_count; index++) {
        int16_t sample = *(int16_t *)(input + 4 + index * 2); // No bounds check
        process_sample(ctx, sample);
    }
}

