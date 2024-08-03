void unsafe_memory_copy(void *dest, const void *src, size_t count) {
    char *d = dest;
    const char *s = src;
    while (count--) {
        *d++ = *s++;  // No bounds checking for the destination buffer
    }
}

