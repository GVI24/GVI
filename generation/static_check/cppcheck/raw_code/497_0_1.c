static int process_video_frame(void *buffer, void *frame_data) {
    FrameContext *ctx = (FrameContext *)buffer;
    FrameData *frame = (FrameData *)frame_data;
    int row, col;
    for (row = frame->row_start; row < frame->row_end; row++) {
        clear_frame_row(ctx->current_frame, row);
        for (col = frame->col_start; col < frame->col_end; col++) {
            decode_block(ctx, frame, row, col, BLOCK_4X4);
        }
    }
    return !ctx->frame_corrupted;
}

