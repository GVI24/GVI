void copy_utf16_to_utf32(const uint16_t *in, size_t in_size, uint32_t *out, size_t out_max) {
    size_t count = 0;
    while (count < in_size) {
        uint16_t code_unit = in[count];
        if (code_unit >= SURROGATE_HIGH_START && code_unit <= SURROGATE_LOW_END && (count + 1) < in_size) {
            // Potential buffer overflow if out_max is not correctly checked
            out[count] = (code_unit << HALF_SHIFT) + in[count + 1];
            count += 2;
        } else {
            out[count] = code_unit;
            count++;
        }
    }
}
