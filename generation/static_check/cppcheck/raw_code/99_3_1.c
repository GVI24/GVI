static void log_motion_vector_usage(VP9_COMMON *cm, MV_REFERENCE_FRAME *ref_frame, int *mv_counts, int bsize, int mi_row, int mi_col) {
    if (mi_row >= cm->mi_rows || mi_col >= cm->mi_cols) return;

    int mv_index = ref_frame[mi_row * cm->mi_stride + mi_col];
    // Potential buffer overflow if mv_index is out of bounds for mv_counts
    mv_counts[mv_index]++;

    if (bsize > BLOCK_64X64) {
        // Further potential for buffer overflow if BLOCK_64X64 is not a valid upper bound for 'bsize'
        mv_counts[bsize]++;
    }
}