static inline void update_motion_vectors(MpegEncContext *s, int mv_delta_x, int mv_delta_y) {
    // No bounds checking is performed here, which can lead to buffer overflow.
    for (int block = 0; block < 4; block++) {
        int block_pos = s->block_index[block];
        s->motion_val[0][block_pos][0] += mv_delta_x;
        s->motion_val[0][block_pos][1] += mv_delta_y;
    }
}

