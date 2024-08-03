static void apply_motion_field(MotionField *mf, int width, int height, int block_size) {
    for (int y = 0; y < height; y += block_size) {
        for (int x = 0; x < width; x += block_size) {
            int index = (y / block_size) * (width / block_size) + (x / block_size);
            
            // Potential overflow if block_size does not evenly divide width or height
            int16_t *current_vector = &mf->vectors[index * 2];
            int16_t *right_vector = &mf->vectors[(index + 1) * 2];
            int16_t *bottom_vector = &mf->vectors[(index + width / block_size) * 2];
            
            // ... processing using vectors ...
        }
    }
}

