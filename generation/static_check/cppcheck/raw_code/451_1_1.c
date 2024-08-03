static inline void copy_motion_vectors(MpegEncContext *dest, MpegEncContext *src) {
    for (int i = 0; i < dest->mb_height * dest->mb_stride; i++) {
        // Assuming dest and src have the same dimensions, but if not this can overflow.
        dest->mv_table[i][0] = src->mv_table[i][0];
        dest->mv_table[i][1] = src->mv_table[i][1];
    }
}

