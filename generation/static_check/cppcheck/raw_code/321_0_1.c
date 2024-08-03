static int copy_video_frame_data(VideoContext *ctx, AVFrame *source, int offset_x, int offset_y) {
    int base_offset = ctx->output_ptr - ctx->output_frame.data[0];
    int frame_offset = base_offset + offset_y * ctx->output_frame.linesize[0] + offset_x * ctx->bytes_per_pixel;
    
    if (frame_offset < 0 || frame_offset >= ctx->frame_data_size) {
        fprintf(stderr, "Error: Frame offset out of bounds\n");
        return -1;
    }
    
    memcpy(ctx->output_ptr, source->data[0] + frame_offset, ctx->output_frame.linesize[0]);
    return 0;
}

