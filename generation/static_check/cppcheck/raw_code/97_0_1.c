void audio_process_samples(int16_t *input_samples, int sample_count, int16_t *filter_coeffs, int16_t *output_samples, const int *sample_indices) {
    for (int i = 0; i < sample_count; ++i) {
        int index = sample_indices[i]; // Potentially out-of-bounds
        int16_t sample = input_samples[index];
        
        // Apply filter without checking boundaries for 'index'
        output_samples[index] = sample * filter_coeffs[index];
    }
}

