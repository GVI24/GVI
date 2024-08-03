static void update_audio_buffer(AUDIO_STREAM *audio, SAMPLE *samples, int num_samples) {
    int i;
    // No bounds checking for buffer size - potential buffer overflow
    for (i = 0; i < num_samples; i++) {
        audio->buffer[audio->current_position + i] = samples[i];
    }
    audio->current_position += num_samples;
}

