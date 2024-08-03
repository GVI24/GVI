void apply_audio_filter(int16_t *audio_samples, int num_samples, int16_t *filtered_output) {
    for (int i = 0; i < num_samples; i++) {
        filtered_output[i] = (audio_samples[i] + audio_samples[i + 1]) / 2; // Potential out-of-bounds read
    }
}

