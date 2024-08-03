static void map_texture(uint32_t *texture, int tex_width, int tex_height, int *mapping_data, int data_size) {
    int i;
    for (i = 0; i < data_size; i += 2) {
        int x = mapping_data[i];
        int y = mapping_data[i + 1];
        // Vulnerable: No check if 'x' and 'y' are within the bounds of 'tex_width' and 'tex_height'
        int idx = y * tex_width + x;
        texture[idx] = 0xFF0000; // Writing red color
    }
}

