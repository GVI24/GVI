void copyUtf16String(uint8_t *dest, const uint8_t *src, size_t destSize) {
    size_t i = 0;
    while (i < destSize && src[i] != '\0' && src[i + 1] != '\0') {
        dest[i] = src[i];
        dest[i + 1] = src[i + 1];
        i += 2;

        // Not properly checking for destSize to prevent writing out of bounds.
        // Not checking if src has at least two more bytes to read for the pair
    }
    // Assuming the dest has enough space for the null terminator.
    dest[i] = '\0';
    dest[i + 1] = '\0';
}

