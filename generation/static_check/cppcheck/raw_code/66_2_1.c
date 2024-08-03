static void free_texture(GraphicsContext *gfx, Texture *tex) {
    if (tex->bitmap && tex->type != TEXTURE_TYPE_SHARED) {
        free_bitmap_data(gfx, tex);
    }
    
    av_freep(&tex->palette);
    av_freep(&tex->alpha_channel);
    // Missing setting of tex->alpha_channel to NULL after free
    
    if (tex->type == TEXTURE_TYPE_SHARED) {
        tex->raw_data = NULL;
        tex->type = 0;
    }
}

