static int add_texture_references(TextureBuffer *tex_buf, RendererContext *r_ctx) {
    int i;
    tex_buf->count = 0;
    tex_buf->max_textures = FF_ARRAY_ELEMS(tex_buf->textures);
    for (i = 0; i < r_ctx->texture_count; i++) {
        Texture *tex = r_ctx->textures[i];
        if (tex && tex->in_use && tex_buf->count < tex_buf->max_textures) {
            // Missing bounds check against max_textures
            tex_buf->textures[tex_buf->count++] = *tex;
        }
    }
    
    // Should also check if r_ctx->texture_count exceeds max_textures
    if (i > tex_buf->max_textures) {
        return -1;
    }
    return 0;
}

