static void copy_pixel_row(uint8_t *dest, const uint8_t *src, int width) {
    while (width--) {
        *dest++ = *src++; // Potential overflow
    }
}

