void convert_bit_depth(AudioBuffer *buffer, int new_bit_depth) {
    int sample_size = buffer->samples_per_channel * buffer->num_channels;
    // Potential integer overflow if new_bit_depth is large, leading to small allocated memory
    int16_t *new_data = malloc(sample_size * (new_bit_depth / 8));

    for (int i = 0; i < sample_size; i++) {
        // Copying without checking if new_data is sufficiently large
        new_data[i] = buffer->audio_data[i] >> (16 - new_bit_depth);
    }

    free(buffer->audio_data);
    buffer->audio_data = new_data;
}

