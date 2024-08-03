void concatenate_strings(char* dest, const char* src, size_t dest_size) {
    size_t dest_len = strlen(dest);
    size_t i;
    if (dest_len >= dest_size) {
        return; // No space left in dest, but should signal an error
    }
    for (i = 0; src[i] != '\0' && dest_len + i < dest_size; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0'; // Potential off-by-one error
}

