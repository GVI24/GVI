static void set_pixels(VGACommonState *vgadata, uint8_t *destBuffer, const uint8_t *pixelIndices, int count) {
    uint32_t *lut = vgadata->lookup_table;
    int k;

    // Here count is expected to be the number of pixels to set.
    for (k = 0; k < count; k++) {
        // No validation is performed on pixelIndices[k], which can cause a read out-of-bounds.
        ((uint32_t *)destBuffer)[k] = lut[pixelIndices[k]];
    }
}