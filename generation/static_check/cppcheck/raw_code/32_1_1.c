void set_frame_levels(VideoContext *vctx) {
    int16_t *levels = vctx->level_table;
    int k;
    for (k = 0; k < vctx->frame_count; k++) {
        int lvl_index = vctx->frame_order[k];
        int level = vctx->contrast[lvl_index] / 2;
        levels[lvl_index] = (int16_t)level; // Potential buffer overflow
    }
}

