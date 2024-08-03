void update_audio_samples(int sample_rate, int64_t *sample_cache, int cache_length, int index_multiplier) {
    int index = sample_rate * index_multiplier; // Potential integer overflow

    // Check for integer overflow before using 'index'
    if (sample_rate > 0 && index_multiplier > 0 && index < 0) {
        // Handle error condition: Integer overflow detected
        printf("Error: Integer overflow in calculating sample index!\n");
        return;
    }

    // Bounds checking for 'sample_cache'
    if (index < 0 || index >= cache_length) {
        // Handle error condition: Index out of bounds
        printf("Error: Sample cache index out of bounds!\n");
        return;
    }

    // Update sample cache
    sample_cache[index] = get_audio_sample(sample_rate);
}

