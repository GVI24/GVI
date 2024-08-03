void copy_block_data(FrameContext *frame_ctx) {
    int block_idx = frame_ctx->current_block_idx;

    // Out-of-bounds read and write if current_block_idx is too large
    frame_ctx->current_frame_blocks[block_idx] = frame_ctx->prev_frame_blocks[block_idx];
    frame_ctx->prev_frame_blocks[block_idx] = 0;

    // Other block copy operations
    // ...
}

