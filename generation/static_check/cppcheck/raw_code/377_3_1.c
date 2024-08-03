static void raw_image_copy(VGACommonState *s, uint8_t *dest, const uint8_t *src, int num_pixels) {
    while (num_pixels--) {
        *dest++ = *src++; // Both pointers 'dest' and 'src' lack boundary checks leading to potential buffer overflows
        *dest++ = *src++; // Repeated without checking for buffer overflows per iteration
        *dest++ = *src++;
    }
}