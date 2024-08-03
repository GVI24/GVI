static void copy_vga_buffer(VGACommonState *state, uint8_t *destination, const uint8_t *source, size_t num_pixels) {
    uint32_t *color_map = state->color_map;
    for (size_t i = 0; i < num_pixels; i++) {
        ((uint32_t*)destination)[i] = color_map[source[i]];  // No bounds check on 'source[i]' index
    }
}

