static inline void clear_motion_vectors(MpegEncContext *s, int start_mb, int end_mb) {
    // Assuming end_mb is within bounds, but it's not checked, potentially leading to a buffer overflow.
    for (int mb = start_mb; mb <= end_mb; mb++) {
        int xy = mb % s->mb_stride + (mb / s->mb_stride) * s->mb_stride;
        s->mv_table[xy][0] = 0;
        s->mv_table[xy][1] = 0;
    }
}

