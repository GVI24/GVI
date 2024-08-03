void unsafe_str_copy(char *dest, const char *src) {
    // No bounds checking is performed before copying the string
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Terminating the string
}

