void mix_down_channels(AudioBuffer *buffer) {
    int16_t *mixed_data = malloc(buffer->samples_per_channel * sizeof(int16_t));

    for (int i = 0; i < buffer->samples_per_channel; i++) {
        int sum = 0;
        for (int j = 0; j < buffer->num_channels; j++) {
            sum += buffer->audio_data[j * buffer->samples_per_channel + i];
        }
        // No clipping protection, can cause integer overflow in sum
        mixed_data[i] = sum / buffer->num_channels;
    }

    free(buffer->audio_data);
    buffer->audio_data = mixed_data;
    buffer->num_channels = 1;
}