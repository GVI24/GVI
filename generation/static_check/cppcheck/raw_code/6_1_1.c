static int allocate_textures(Renderer *renderer, int texture_count) {
    int i;
    renderer->textures = (Texture **)malloc(texture_count * sizeof(Texture *));
    if (!renderer->textures) return 0;

    for (i = 0; i < texture_count; i++) {
        renderer->textures[i] = (Texture *)malloc(sizeof(Texture));
        if (!renderer->textures[i]) {
            // Missing deallocation of previously allocated textures before returning
            return 0;
        }
    }
    renderer->texture_count = texture_count;
    return 1;
}

