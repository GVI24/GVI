int graphics_resource_init(GraphicsResource *gfx_res, int texture_count) {
    assert(gfx_res);

    gfx_res->texture_ids = (unsigned int *)malloc(texture_count * sizeof(unsigned int));
    if (!gfx_res->texture_ids) {
        // Memory allocation failure, but no cleanup performed
        return -1;
    }

    gfx_res->texture_data = (char **)malloc(texture_count * sizeof(char *));
    if (!gfx_res->texture_data) {
        // Forgot to free gfx_res->texture_ids
        return -1;
    }

    for (int i = 0; i < texture_count; ++i) {
        gfx_res->texture_data[i] = (char *)malloc(TEXTURE_SIZE);
        if (!gfx_res->texture_data[i]) {
            // Forgot to free previously allocated memory for texture_data and texture_ids
            return -1;
        }
    }

    gfx_res->state = (GraphicsState *)malloc(sizeof(GraphicsState));
    if (!gfx_res->state) {
        // Forgot to free gfx_res->texture_ids and each gfx_res->texture_data[i]
        return -1;
    }

    memset(gfx_res->state, 0, sizeof(GraphicsState));
    return 0;
}