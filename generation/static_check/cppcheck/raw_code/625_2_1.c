static void load_textures(GraphicsContext *gfxCtx) {
    TextureArray *texArray = gfxCtx->textureArray;
    Texture *textures = &texArray->textures[0];
    int i;
    
    // Assuming a fixed number of textures
    #define MAX_TEXTURES 128
    for (i = 0; i < gfxCtx->texture_count; ++i) {
        if (i >= MAX_TEXTURES) {
            break; // Bounds checking to prevent overflow
        }
        if (!load_texture(&textures[i], gfxCtx->texture_paths[i])) {
            printf("Failed to load texture: %s\n", gfxCtx->texture_paths[i]);
        }
    }
    // ... remainder of function not shown ...
}

