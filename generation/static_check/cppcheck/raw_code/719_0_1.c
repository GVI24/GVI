void unsafe_string_copy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++; // Potential buffer overflow if dest is smaller than src
    }
    *dest = '\0';
}