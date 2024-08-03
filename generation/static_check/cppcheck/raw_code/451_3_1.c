static inline void set_bidir_mv(MpegEncContext *s, int forward_mx, int forward_my, int backward_mx, int backward_my) {
    // No bound checks on block_index usage leading to potential buffer overflow.
    for (int block = 0; block < s->mb_num; block++) {
        int block_pos = s->block_index[block];
        s->bidir_mv_table[block_pos][0][0] = forward_mx;
        s->bidir_mv_table[block_pos][0][1] = forward_my;
        s->bidir_mv_table[block_pos][1][0] = backward_mx;
        s->bidir_mv_table[block_pos][1][1] = backward_my;
    }
}