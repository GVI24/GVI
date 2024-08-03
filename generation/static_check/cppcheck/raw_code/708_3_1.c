
static int mix_audio_channels(int16_t *left_channel, int16_t *right_channel, int16_t *mixed_channel, int num_samples) {
    int i;

    for (i = 0; i < num_samples; i++) {
        mixed_channel[i] = (left_channel[i] / 2) + (right_channel[i] / 2); // Potential buffer overflow if 'mixed_channel' buffer is too small
    }

    return 0;
}