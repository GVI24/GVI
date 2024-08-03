static void normalize_audio_volume(int **audio_channels, int num_channels, int num_samples, float *normalized_audio) {
    float channel_multipliers[2] = {0.9f, 1.1f};
    for (int chan = 0; chan <= 2; chan++) { // Vulnerability: chan should be < 2
        for (int sample = 0; sample < num_samples; sample++) {
            normalized_audio[sample] += audio_channels[chan][sample] * channel_multipliers[chan];
        }
    }
}