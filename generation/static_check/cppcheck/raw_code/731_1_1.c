void apply_gain(int16_t *input_samples, size_t num_samples, int gain_factor) {
    size_t i;
    // No check for gain_factor leading to potential integer overflow
    for (i = 0; i < num_samples; i++) {
        input_samples[i] *= gain_factor;
    }
}

