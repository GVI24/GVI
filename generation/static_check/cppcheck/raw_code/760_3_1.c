void copy_texture_coords(TextureMappingContext *tex_ctx) {
    int vertex, coord_set;
    for (coord_set = 0; coord_set < tex_ctx->num_sets; coord_set++) {
        for (vertex = 0; vertex < tex_ctx->vertex_count[coord_set]; vertex++) {
            TextureCoords *orig_coords = &tex_ctx->coords[coord_set][vertex];
            TextureCoords *extra_coords = &tex_ctx->extra_coords[coord_set][256 + vertex]; // Potential out-of-bounds write
            extra_coords->u = orig_coords->u;
            extra_coords->v = orig_coords->v;
        }
    }
}