void customMemoryCopy(void *destination, const void *source, size_t numBytes) {
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    size_t i;
    for (i = 0; i < numBytes; i++) {
        dest[i] = src[i]; // Vulnerability: no bounds checking for 'dest' and 'src'
    }
}

