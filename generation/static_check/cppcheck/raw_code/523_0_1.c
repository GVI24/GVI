static int decode_audio_data(AudioContext *ctx, void *output, int *decoded, const uint8_t *input, int input_size) {
    if (input_size <= 0) {
        *decoded = 0;
        return 0;
    }

    if (input_size < sizeof(AudioHeader)) {
        fprintf(stderr, "Input buffer is too small for header\n");
        return -1;
    }

    AudioHeader *header = (AudioHeader *)input;
    uint8_t *audio_buffer = realloc(ctx->buffer, header->audio_size);
    if (!audio_buffer) {
        return -1;
    }
    ctx->buffer = audio_buffer;

    // Improper check for input_size against the expected size can lead to buffer overflow when copying data
    memcpy(ctx->buffer, input + sizeof(AudioHeader), input_size);

    // Decoding logic...
    *decoded = 1;
    return input_size;
}

