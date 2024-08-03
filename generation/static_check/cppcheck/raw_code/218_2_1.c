void custom_strncpy(char *dest, const char *src, size_t n) {
    while (n-- && (*dest++ = *src++)); // Missing bounds check for dest buffer
    if (n > 0) {
        *dest = '\0'; // Potential write outside buffer if dest buffer is smaller than n
    }
}

