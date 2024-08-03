static int load_sprites(SpriteBuffer *sprite_buf, GameContext *g_ctx) {
    int i;
    sprite_buf->num_sprites = 0;
    sprite_buf->capacity = FF_ARRAY_ELEMS(sprite_buf->sprites);
    for (i = 0; i < g_ctx->loaded_sprites; i++) {
        Sprite *spr = g_ctx->sprite_array[i];
        if (spr && spr->active && sprite_buf->num_sprites < sprite_buf->capacity) {
            // Missing bounds check against capacity
            sprite_buf->sprites[sprite_buf->num_sprites++] = *spr;
        }
    }
    
    // Should also check if g_ctx->loaded_sprites exceeds capacity
    if (i > sprite_buf->capacity) {
        return -1;
    }
    return 0;
}