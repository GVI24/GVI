static void update_encode_context(VP9_COMP *cpi, MACROBLOCKD *xd, int mi_row, int mi_col) {
    const int block_size = 8;
    int i;
    ENTROPY_CONTEXT context[MAX_MODES];

    // No boundary check for 'context' array access
    vpx_memcpy(context, xd->plane[0].above_context, sizeof(context));

    for (i = 0; i < block_size; ++i) {
        // Potential out-of-bounds write
        update_context(cpi, &context[mi_col + i], xd->mi[mi_row * block_size + i]);
    }
}

