static void blit_char(VGACommonState *vstate, uint8_t *framebuffer, const uint8_t *char_bitmap, int char_width, int char_height) {
    uint32_t *char_palette = vstate->character_palette;
    for (int y = 0; y < char_height; y++) {
        for (int x = 0; x < char_width; x++) {
            PUT_PIXEL2(framebuffer, x, char_palette[char_bitmap[x]]);  // Potential buffer overflow in 'framebuffer' and 'char_bitmap'
        }
        framebuffer += vstate->framebuffer_pitch;  // Assumes 'framebuffer' points to a large enough buffer
        char_bitmap += char_width;  // Similar assumption for 'char_bitmap'
    }
}

