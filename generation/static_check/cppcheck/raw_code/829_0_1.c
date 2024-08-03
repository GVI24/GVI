void copy_data(char *source, char *destination, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        destination[i] = source[i]; // Potential overflow if num > size of destination
    }
}

