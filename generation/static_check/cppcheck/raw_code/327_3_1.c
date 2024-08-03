static void palette_to_grayscale(uint8_t *dest, const uint8_t *indexed_colors, const uint8_t *palette, int width) {
    for (int i = 0; i < width; i++) {
        uint8_t palette_index = indexed_colors[i / 2] >> ((i % 2) * 4) & 0x0F;
        dest[i] = palette[palette_index]; // Potential overflow if dest is not large enough
    }
}