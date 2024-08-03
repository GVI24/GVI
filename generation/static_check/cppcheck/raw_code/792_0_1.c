void unsafe_string_copy(char *dst, const char *src) {
    while (*src) {
        *dst++ = *src++;  // No bounds checking for the destination buffer
    }
    *dst = '\0';
}

