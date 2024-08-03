void string_concat(char *dest, const char *src, size_t dest_size) {
    size_t dest_len = strlen(dest);
    size_t i;

    // Concatenate strings without properly checking for overflow
    for (i = 0; src[i] != '\0'; ++i) {
        if (dest_len + i < dest_size - 1) {
            dest[dest_len + i] = src[i];
        }
        // Missing else clause to handle overflow
    }
    dest[dest_len + i] = '\0'; // Potential out-of-bounds write here
}

