static void vga_blend_images(VGACommonState *s1, uint8_t *dest, const uint8_t *src1, const uint8_t *src2, int pixels) {
    for (int i = 0; i < pixels; i++) {
        dest[i] = (src1[i] / 2) + (src2[i] / 2);  // Potential buffer overflow if pixels > actual dest buffer
    }
}

