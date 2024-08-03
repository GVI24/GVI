void apply_video_filter(VideoFilterContext *filter_ctx) {
    int i, j;
    for (i = 0; i < filter_ctx->frame_width; i++) {
        for (j = 0; j < filter_ctx->frame_height; j++) {
            // Potential out-of-bounds access for filter_mask
            int current_pixel = filter_ctx->frame_data[i * filter_ctx->frame_width + j];
            int filter_value = filter_ctx->filter_mask[filter_ctx->filter_map[i]];
            filter_ctx->frame_data[i * filter_ctx->frame_width + j] = apply_filter(current_pixel, filter_value);
        }
    }
}