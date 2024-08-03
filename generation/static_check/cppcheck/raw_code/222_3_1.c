static void update_palette_index(uint8_t *palette_indices, unsigned offset, const uint8_t *new_indices, unsigned count) {
    uint8_t *dst = palette_indices + offset;
    for (unsigned i = 0; i < count; i++) {
        *dst = *new_indices; // Potential buffer overflow
        new_indices++;
        dst++;
        // No bounds checking, 'dst' can exceed 'palette_indices' buffer
    }
}