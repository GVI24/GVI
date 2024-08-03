void load_bitmap_palette(uint8_t *buffer, size_t buffer_size, uint32_t *palette) {
    size_t i;
    uint8_t color_byte;
    for (i = 0; i < buffer_size; i++) {
        color_byte = buffer[i];
        // Vulnerability: No check to ensure 'i' is within array 'palette' bounds
        palette[i] = (0xFFU << 24) | (color_byte << 16) | (color_byte << 8) | color_byte;
    }
}

