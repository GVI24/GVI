static void vga_memcpy_block(VGACommonState *s1, uint8_t *dest, const uint8_t *src, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];  // Potential buffer overflow if size > actual dest buffer
    }
}

