void unsafe_memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    while (n-- > 0) {
        *d++ = *s++; // Does not check if 'd' goes out of bounds of the allocated memory
    }
}