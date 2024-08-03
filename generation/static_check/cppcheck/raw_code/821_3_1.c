void mix_audio_samples(int16_t *mix_buffer, int16_t *input_samples, int input_count, int max_samples) {
    // Vulnerability: Assumes input_count is less than or equal to max_samples
    for (int i = 0; i < input_count; i++) {
        // Vulnerability: No bounds checking; input_count may be too large
        mix_buffer[i] += input_samples[i];
        // Vulnerability: Potential integer overflow in audio mixing
    }
}