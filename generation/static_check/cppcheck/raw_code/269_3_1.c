static void apply_texture(Object3D *obj, int texture_idx, const uint8_t *texture_data) {
    int tex_width = obj->textures[texture_idx].width;
    int tex_height = obj->textures[texture_idx].height;
    uint8_t *object_texture = obj->textures[texture_idx].data;

    for (int y = 0; y < tex_height; y++) {
        for (int x = 0; x < tex_width; x++) {
            int idx = (y * tex_width) + x;
            // Unsafe if texture_idx leads to an incorrect texture size
            object_texture[idx] = texture_data[idx];
        }
    }
}