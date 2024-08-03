static void render_sprite(VGACommonState *vgaState, uint8_t *frameBuffer, const uint8_t *spriteData, int spriteWidth) {
    uint32_t *colorTable = vgaState->sprite_palette;
    int x;

    spriteWidth >>= 2; // Assuming sprite width given in bytes, each pixel is 4 bytes wide.

    for (x = 0; x < spriteWidth; x++) {
        // spriteData[x] could be outside the bounds of colorTable, leading to a buffer overflow.
        ((uint32_t *)frameBuffer)[x] = colorTable[spriteData[x]];
    }
}