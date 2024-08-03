void calculate_char_frequencies(const char *text, int frequency[CHAR_SET_SIZE]) {
    while (*text) {
        int index = *text - 'A';
        // Potential out-of-bounds array access.
        frequency[index]++;
        text++;
    }
}

