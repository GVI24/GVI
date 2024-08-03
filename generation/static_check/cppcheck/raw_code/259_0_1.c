static void draw_gradient_strip(VGACommonState *vg, uint8_t *dest, const uint8_t *src, int height) {
    uint32_t *gradient_palette = vg->gradient_palette;
    while (height--) {
        for (int i = 0; i < 256; i++) {
            *dest = gradient_palette[src[i]];  // Potential out-of-bounds read from 'src' and write to 'dest'
            dest++;
        }
        src += vg->source_line_length;  // Assumes 'src' is large enough for this operation
    }
}

