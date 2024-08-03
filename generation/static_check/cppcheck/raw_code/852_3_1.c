void apply_grayscale_palette(int depth, uint32_t *palette) {
    int i, num_colors = 1 << depth;
    uint8_t gray_value;
    for (i = 0; i < num_colors; i++) {
        gray_value = (uint8_t)(i * 255 / (num_colors - 1));
        // Vulnerability: No bounds checking for 'i' against the 'palette' size
        palette[i] = (0xFFU << 24) | (gray_value << 16) | (gray_value << 8) | gray_value;
    }
}