void custom_memcpy(void *dest, const void *src, size_t count) {
    // Assumed maximum buffer size
    char buffer[1024];

    // Vulnerability: No bounds checking for count
    for (size_t n = 0; n < count; ++n) {
        buffer[n] = ((char *)src)[n];
    }

    // Copy buffer to destination
    // Further vulnerability: Copying fixed 1024 bytes to dest regardless of count
    memcpy(dest, buffer, 1024);
}

