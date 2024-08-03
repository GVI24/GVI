void utf16_to_utf32_with_uninitialized_use(const uint16_t *source, uint32_t *target, size_t target_len) {
    size_t idx = 0, target_idx = 0;
    uint16_t high_surrogate;
    while (source[idx] && target_idx < target_len) {
        if (source[idx] >= SURROGATE_HIGH_START && source[idx] <= SURROGATE_LOW_END) {
            high_surrogate = source[idx++];
            if (source[idx]) { // No proper check for low surrogate leads to undefined behavior
                target[target_idx++] = (high_surrogate << HALF_SHIFT) + source[idx++];
            }
        } else {
            target[target_idx++] = source[idx++];
        }
    }
}

