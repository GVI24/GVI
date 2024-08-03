static void estimate_motion_vector ( EncoderContext * enc, int block_x, int block_y ) {
    int width = enc->width;
    int height = enc->height;
    int mv_stride = width / 2;
    int *motion_vectors = enc->motion_vectors;
    int mv_index = block_x / 2 + (block_y / 2) * mv_stride;
    int vector_x, vector_y;

    // No bounds checking for mv_index may lead to out-of-bounds write
    vector_x = motion_vectors[mv_index - 1]; // Potential out-of-bounds access
    vector_y = motion_vectors[mv_index - mv_stride]; // Potential out-of-bounds access

    // Update motion vectors
    motion_vectors[mv_index] = (vector_x + vector_y) / 2;
}