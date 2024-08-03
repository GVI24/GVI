static void copy_UTF16BE_string(uint8_t *dest, const uint8_t *src, size_t srcSize, UErrorCode *err) {
    const uint8_t *s = src;
    uint8_t *d = dest;

    while (s < src + srcSize) {
        // Vulnerability: No check for end of destination buffer
        *d++ = *s++;
        *d++ = *s++;
        
        if (U_IS_SURROGATE_PAIR(*s, *(s+1))) {
            *d++ = *s++;
            *d++ = *s++;
        }
    }

    // Should have a way to communicate the copied size and check against the destination buffer size
    *err = U_ZERO_ERROR;
}

