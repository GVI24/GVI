static int unpack_texture_data(TextureContext *tCtx) {
    uint32_t *texture_data = tCtx->texture_data;
    int tex_width = tCtx->tex_width;
    int tex_height = tCtx->tex_height;
    int x, y;

    for (y = 0; y < tex_height; y++) {
        for (x = 0; x < tex_width; x++) {
            uint32_t color = get_next_color_from_stream(tCtx->stream);
            int position = (y * tex_width) + x; // Potential overflow if tex_width or tex_height is too large
            texture_data[position] = color;     // Writing to texture_data without bounds check
        }
    }
    return 0;
}

