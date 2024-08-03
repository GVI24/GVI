static int decode_frame_data(FrameContext *ctx) {
    int i, j;
    unsigned char color_indices[2];
    bytestream2_get_buffer(&ctx->stream_ptr, color_indices, 2);

    for (i = 0; i < ctx->frame_height; i++) {
        int line_flag = bytestream2_get_le16(&ctx->stream_ptr);
        for (j = 0; j < ctx->frame_width; j++, line_flag >>= 1) {
            *ctx->frame_ptr++ = color_indices[line_flag & 0x01];
        }
        ctx->frame_ptr += ctx->line_stride - ctx->frame_width;
    }
    return 0;
}