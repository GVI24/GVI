static void draw_sprite(SpriteContext *sprite_ctx, const unsigned char *sprite_data, int x, int y) {
    int sprite_stride = sprite_ctx->sprite_width;
    int screen_stride = sprite_ctx->screen_width;
    unsigned char *screen = sprite_ctx->screen_data;
    int pixel_size = sprite_ctx->pixel_size;
    int index = y * screen_stride + x;

    // Vulnerable: Not validating if sprite data fits on the screen buffer
    for (int i = 0; i < sprite_ctx->sprite_height && index < sprite_ctx->screen_size; i++) {
        memcpy(screen + index, sprite_data, sprite_stride * pixel_size); // Possible overflow
        sprite_data += sprite_stride * pixel_size;
        index += screen_stride;
    }
}

