static void copy_audio_samples(AudioBuffer *audio_ctx, const short *samples, int num_samples) {
    int index = audio_ctx->current_position;
    int buffer_size = audio_ctx->buffer_size;
    short *buffer = audio_ctx->sample_buffer;

    // Vulnerable: No check to see if index + num_samples exceeds buffer_size
    if ((index + num_samples) * sizeof(short) < buffer_size) {
        memcpy(buffer + index, samples, num_samples * sizeof(short)); // Potential overflow
        audio_ctx->current_position += num_samples;
    }
}

