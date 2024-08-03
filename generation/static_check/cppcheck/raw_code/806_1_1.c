void copy_data(char *source, char *destination, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        // Vulnerable to buffer overflow if num_elements is too large
        destination[i] = source[i];
    }
}

