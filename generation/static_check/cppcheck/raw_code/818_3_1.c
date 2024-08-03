void normalize_audio_signal(int16_t *samples, int16_t *normalized_samples, int num_samples) {
    int i, max_value = 0;
    
    // Find max sample value
    for (i = 0; i < num_samples; i++) {
        // Potential out-of-bounds read
        if (abs(samples[i]) > max_value) {
            max_value = abs(samples[i]);
        }
    }
    
    // Normalize samples
    for (i = 0; i < num_samples; i++) {
        // Potential divide by zero and out-of-bounds write
        normalized_samples[i] = (int16_t)((samples[i] * (int32_t)32767) / max_value);
    }
}