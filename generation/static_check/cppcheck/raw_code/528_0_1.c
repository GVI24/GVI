void set_motion_vectors(MotionVectorData *mv_data, int width, int height, int vec_value) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Potential for out-of-bounds write if width or height exceed allocated size
            mv_data->vectors[i * mv_data->max_width + j] = vec_value;
        }
    }
}