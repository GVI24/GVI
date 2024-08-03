static void process_audio_frame(AudioContext *ctx, int frame_number, const int16_t *samples) {
    int buffer_size = ctx->buffer_size;
    int16_t *audio_buffer = ctx->audio_data + (frame_number * buffer_size);

    for (int i = 0; i < buffer_size; i++) {
        // Apply some audio processing and write back to the buffer
        audio_buffer[i] = process_sample(samples[i]);
    }
}

