static void update_texture(TextureContext *tex_ctx, const unsigned char *texture_data, int tex_x, int tex_y) {
    int tex_stride = tex_ctx->texture_width;
    unsigned char *tex_buffer = tex_ctx->texture_data;
    int buffer_size = tex_ctx->texture_size;
    int index = tex_y * tex_stride + tex_x;

    // Vulnerable: Assumes that texture_data is always the correct size
    if (tex_x < tex_ctx->texture_width && tex_y < tex_ctx->texture_height && index < buffer_size) {
        memcpy(tex_buffer + index, texture_data, tex_ctx->texture_width); // May write out of bounds
    }
}