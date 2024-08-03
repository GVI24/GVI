static void init_audio_buffer(AUDIO_DECODER *decoder, int num_samples) {
    const int num_channels = 2; // Stereo

    decoder->sample_buffer = (int16_t **)malloc(num_channels * sizeof(int16_t *));

    // Vulnerability pattern: no check for NULL after malloc
    for (int i = 0; i < num_channels; ++i) {
        decoder->sample_buffer[i] = (int16_t *)malloc(num_samples * sizeof(int16_t));
        memset(decoder->sample_buffer[i], 0, num_samples * sizeof(int16_t));
    }
}