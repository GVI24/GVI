void unsafe_strcpy(char *dest, const char *src, size_t max_copy_length) {
    size_t i;
    for (i = 0; src[i] && i < max_copy_length; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Potentially writes beyond the buffer if max_copy_length is not properly validated.
}

