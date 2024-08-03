static int render_graphics_sprite(GraphicsContext *gfxCtx) {
    unsigned char sprite_code;
    int sprite_x, sprite_y;

    sprite_code = bytestream2_get_byte(&gfxCtx->sprite_stream);

    // No check on sprite_code before determining sprite positions could lead to invalid memory access
    sprite_x = (sprite_code % 25) * 4;
    sprite_y = (sprite_code / 25) * 4;

    printf("Sprite Code: %d, Position: (%d, %d)\n", sprite_code, sprite_x, sprite_y);

    return draw_sprite(gfxCtx, sprite_x, sprite_y);
}