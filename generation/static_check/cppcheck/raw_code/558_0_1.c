void convert_to_utf32_unchecked(const uint16_t *input, size_t input_len, uint32_t *output) {
    size_t i;
    for (i = 0; i < input_len; i++) {
        if (input[i] >= SURROGATE_HIGH_START && input[i] <= SURROGATE_LOW_END) {
            // Surrogate pair handling - but what if input[i + 1] is out of bounds?
            output[i] = (input[i] << HALF_SHIFT) + input[++i];
        } else {
            output[i] = input[i];
        }
    }
}

