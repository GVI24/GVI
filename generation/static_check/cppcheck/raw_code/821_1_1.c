void custom_str_copy(char *dest, const char *src, size_t dest_size) {
    size_t i;
    // Vulnerability: No bounds checking, potential overflow of dest
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    // Vulnerability: If src is longer than dest, dest won't be null-terminated
    dest[i] = '\0';
}