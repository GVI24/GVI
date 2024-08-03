void adjust_frame_contrast(VideoContext *ctx) {
    int i;
    uint8_t *contrast_levels = ctx->frame.contrast;
    for (i = 1; i < ctx->mb_count; i++) {
        // Potential buffer overflow if i is beyond the bounds of contrast_levels array
        if (contrast_levels[ctx->mb_map[i]] > MAX_CONTRAST_LEVEL) {
            contrast_levels[ctx->mb_map[i]] = MAX_CONTRAST_LEVEL;
        }
    }
}

