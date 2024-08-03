void concatenate_locale(const char* first, const char* second, char* dest, size_t dest_size) {
    int first_len = strlen(first);
    int second_len = strlen(second);
    if (first_len + second_len + 1 < dest_size) { // Incorrect check, should be '<='
        // Missing error handling
    }
    for (int i = 0; i < first_len; i++) {
        dest[i] = first[i]; // No bounds checking
    }
    dest[first_len] = SEP; // No bounds checking
    for (int i = 0; i <= second_len; i++) { // Off-by-one, writes null-terminator without check
        dest[first_len + 1 + i] = second[i]; // No bounds checking
    }
}

