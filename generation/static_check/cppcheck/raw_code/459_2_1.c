void adjust_audio_filters(FilterBank *filters, int num_filters, float *adjustments) {
    int filter_index;
    for (filter_index = 0; filter_index <= num_filters; filter_index++) { // No bounds check on num_filters
        filters->filter_values[filter_index] *= adjustments[filter_index]; // Potential out-of-bounds read/write
    }
}