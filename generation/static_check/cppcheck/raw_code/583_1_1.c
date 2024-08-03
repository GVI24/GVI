void update_frequency_table(EqualizerContext *eq, const int *frequencies, int num_frequencies) {
    // Vulnerability: No bounds check before buffer copy
    memcpy(eq->frequency_table, frequencies, num_frequencies * sizeof(int));
    // Update the frequency table based on new frequencies
    // ...
    if (num_frequencies > MAX_EQ_BANDS) {
        fprintf(stderr, "Too many frequency bands provided!\n");
        exit(EXIT_FAILURE);
    }
}

