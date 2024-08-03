void update_texture_coords(float *coords, int num_vertices) {
    float texture_map[200];
    for (int i = 0; i < num_vertices * 2; i++) {
        texture_map[i] = coords[i]; // Vulnerability: No check on num_vertices leading to potential overflow
    }
}

