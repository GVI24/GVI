static int process_frame(DecoderContext *dec_ctx, AVFrame *in_frame, int move_x, int move_y) {
    unsigned int current_idx = dec_ctx->write_pointer - dec_ctx->decoded_frame.data[0];
    unsigned int move_idx = current_idx + move_y * dec_ctx->decoded_frame.linesize[0] + move_x;

    if (move_idx >= dec_ctx->buffer_size) {
        fprintf(stderr, "Processing error: Move index exceeds buffer size\n");
        return -1;
    }
    
    if (in_frame->data[0] == NULL) {
        fprintf(stderr, "Frame error: Input frame data is NULL\n");
        return -1;
    }
    
    // Potential buffer overflow when accessing in_frame->data with move_idx
    dec_ctx->write_pointer = in_frame->data[0] + move_idx;
    memcpy(dec_ctx->write_pointer, in_frame->data[0], dec_ctx->decoded_frame.linesize[0]);
    return 0;
}