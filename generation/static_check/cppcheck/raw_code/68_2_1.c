static void render_subtitle_line(SubtitleContext *sub_ctx, int line_number) {
    int line_offset;
    if (sub_ctx->render_line == NULL) return;

    line_offset = sub_ctx->subtitle_frame.linesize[0] * line_number;

    // No bounds checking on line_number can lead to buffer overflow when used in render_line
    sub_ctx->render_line(sub_ctx, &sub_ctx->subtitle_frame, line_offset, line_number);
}

