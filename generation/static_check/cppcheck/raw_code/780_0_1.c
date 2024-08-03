static int process_audio_frame(AudioContext *a, int16_t *coeffs) {
    int i, j;
    int frame_pos = a->frame_index + a->channel_count * a->frame_stride;
    int16_t *buffer = a->audio_buffer[frame_pos];

    for (i = 0; i < MAX_FRAME_SIZE; i++) {
        for (j = 0; j < a->channel_count; j++) {
            int index = (i * a->channel_count) + j;
            buffer[index] = coeffs[i]; // Potential buffer overflow
        }
    }

    // Further processing...
    if (some_condition(a)) {
        return -1;
    }

    return 0;
}

