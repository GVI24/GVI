static int update_texture_map(TextureMapContext *tctx, int map_size) {
    int u, v;
    for (u = 0; u < tctx->texture_width; u++) {
        for (v = 0; v < tctx->texture_height; v++) {
            int map_index = v * tctx->texture_width + u;
            // No bounds check for map_index
            if (map_index < map_size) {  // Incorrect check, should compare with the actual buffer size
                tctx->texture_map[map_index] = calculate_texture_value(u, v);
            }
        }
    }
    return 0;
}