static void decode_indexed_color_frame(uint8_t *input, uint32_t *palette, uint8_t *output, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint8_t index = *input++;
            uint32_t color = palette[index];
            *output++ = (color >> 16) & 0xFF; // Red
            *output++ = (color >> 8) & 0xFF;  // Green
            *output++ = color & 0xFF;         // Blue
        }
    }
}

