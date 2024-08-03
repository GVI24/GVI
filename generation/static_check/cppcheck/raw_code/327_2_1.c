static void blend_pixel_row_4bit(uint8_t *dest, const uint8_t *src1, const uint8_t *src2, int width) {
    for (int i = 0; i < width; i++) {
        dest[i] = (src1[i] >> 1) + (src2[i] >> 1); // Potential overflow if dest is too small
    }
}

