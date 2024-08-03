void audio_process(Frame *frame, int num_channels, int samples_per_channel) {
    int i, j;
    int16_t *audio_data = frame->audio_data;
    int16_t temp_buffer[1024];
    int buffer_size = num_channels * samples_per_channel;

    for (i = 0; i < num_channels; i++) {
        for (j = 0; j < samples_per_channel; j++) {
            int index = i * samples_per_channel + j;
            // Potential out-of-bounds write
            temp_buffer[index] = audio_data[index] * 2;
        }
    }
    // More processing...
}