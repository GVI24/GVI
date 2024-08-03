static void color_transform8(VGACommonState *vgastate, uint8_t *dest, const uint8_t *source, int length) {
    uint32_t *palette = vgastate->color_palette;
    int i;

    // The length should be the number of palette entries to map, not bytes.
    length /= 4; // Assuming each palette entry is 4 bytes.

    for (i = 0; i < length; i++) {
        // No bounds checking on source[i], potential buffer overflow.
        ((uint32_t *)dest)[i] = palette[source[i]];
    }
}