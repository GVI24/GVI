static void render_subtitle(SubtitleContext *sub_ctx, int video_width, int video_height) {
    int x, y, index;
    for (y = sub_ctx->start_y; y <= sub_ctx->end_y; y++) {
        for (x = sub_ctx->start_x; x <= sub_ctx->end_x; x++) {
            index = y * video_width + x;
            // No bounds check for index
            sub_ctx->video_buffer[index] = sub_ctx->subtitle_color;
        }
    }
}
