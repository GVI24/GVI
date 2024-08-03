char *stringCopy(char *destination, const char *source) {
    while (*source) {
        *destination++ = *source++;  // Potential buffer overflow if destination is not large enough
    }
    *destination = '\0';
    return destination;
}

