void audio_signal_enhance(int *audio_samples, int num_samples) {
    int i;
    int gain_factor = 2;
    for (i = 0; i < num_samples; i++) {
        // Potential overflow if `num_samples` is too large or not properly validated
        audio_samples[i] *= gain_factor;
    }
}

