void adjust_frequencies(FrequencyHandler *freq_handler, float *frequency_adjustments) {
    for (int i = 0; i <= freq_handler->num_frequencies; i++) { // Access beyond the array size, should be i < freq_handler->num_frequencies
        if (frequency_adjustments[i] > 1.0f) {
            freq_handler->frequencies[i] = 440.0f; // Potential out-of-bounds write
        } else {
            freq_handler->frequencies[i] *= frequency_adjustments[i]; // Potential out-of-bounds write
        }
    }
}