static void blit_sprite(RenderState *rs, unsigned x, unsigned y, Sprite *sprite) {
    uint8_t *dst = rs->canvas + y * rs->canvas_width + x;
    for (unsigned i = 0; i < sprite->height; i++) {
        for (unsigned j = 0; j < sprite->width; j++) {
            *dst = sprite->pixels[i * sprite->width + j]; // Potential buffer overflow
            dst++;
        }
        dst += rs->canvas_width - sprite->width;
        // Increment jumps back to the start of the next line without validation
    }
}

