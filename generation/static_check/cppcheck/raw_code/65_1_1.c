static void restore_audio_samples(int16_t *samples, int num_samples, int restore_factor) {
    int i;
    for (i = 0; i <= num_samples; i++) { // Vulnerable: Should be 'i < num_samples'
        // Vulnerable: No check to ensure 'i' is within array bounds
        samples[i] = (samples[i] / 2) * restore_factor;
    }
}

