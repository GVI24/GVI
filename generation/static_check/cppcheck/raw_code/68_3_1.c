static void apply_custom_filter(ImageContext *img_ctx, int start_row) {
    int buffer_offset;
    int filter_height = start_row - img_ctx->last_filter_row;

    if (img_ctx->apply_filter == NULL) return;

    img_ctx->last_filter_row = start_row;
    start_row -= filter_height;

    buffer_offset = img_ctx->image_frame.linesize[0] * start_row;

    // Potential for buffer overflow if start_row is beyond buffer bounds
    img_ctx->apply_filter(img_ctx, &img_ctx->image_frame, buffer_offset, filter_height);
}