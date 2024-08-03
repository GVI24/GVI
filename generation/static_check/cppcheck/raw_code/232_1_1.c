static void update_screen_buffer(VGACommonState *vga, uint8_t *buffer, const uint8_t *indices, int size) {
    uint32_t *color_map = vga->color_conversion_table;
    int pos;

    for (pos = 0; pos < (size >> 2); pos++) {
        // No checking if the index is within the valid range.
        ((uint32_t *)buffer)[pos] = color_map[indices[pos]];
    }
}