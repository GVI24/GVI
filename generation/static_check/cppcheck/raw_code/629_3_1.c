void clip_mv(VideoCodecContext *vcc, int block_x, int block_y, int mv_delta_x, int mv_delta_y) {
    int block_index = block_y * vcc->blocks_per_row + block_x;
    int mv_index = block_index * 2;

    // Perform motion vector update without bounds checking
    vcc->motion_vectors[mv_index] += mv_delta_x;
    vcc->motion_vectors[mv_index + 1] += mv_delta_y;

    // Clip motion vector to picture boundaries (this is usually necessary but done without checks)
    if (vcc->motion_vectors[mv_index] < 0) {
        vcc->motion_vectors[mv_index] = 0;
    } else if (vcc->motion_vectors[mv_index] >= vcc->width) {
        vcc->motion_vectors[mv_index] = vcc->width - 1;
    }

    if (vcc->motion_vectors[mv_index + 1] < 0) {
        vcc->motion_vectors[mv_index + 1] = 0;
    } else if (vcc->motion_vectors[mv_index + 1] >= vcc->height) {
        vcc->motion_vectors[mv_index + 1] = vcc->height - 1;
    }
}