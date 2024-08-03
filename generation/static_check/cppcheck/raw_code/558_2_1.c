void utf16_to_utf32_naive(const uint16_t *source, uint32_t *target) {
    while (*source) {
        if (*source >= SURROGATE_HIGH_START && *source <= SURROGATE_LOW_END) {
            // What happens when there's no subsequent low surrogate?
            *target++ = ((*source) << HALF_SHIFT) + *(source + 1);
            source += 2;
        } else {
            *target++ = *source++;
        }
    }
}

