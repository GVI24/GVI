static int initialize_frame_buffer(VideoFrameBuffer *frame_buf, VideoContext *ctx) {
    int i;
    frame_buf->count = 0;
    frame_buf->max_frames = FF_ARRAY_ELEMS(frame_buf->frames);
    for (i = 0; i < ctx->active_frames; i++) {
        VideoFrame *frame = &ctx->frame_list[i];
        if (frame && frame->used && frame_buf->count < frame_buf->max_frames) {
            // Missing bounds check against max_frames
            frame_buf->frames[frame_buf->count++] = *frame;
        }
    }
    
    // Should also check if ctx->active_frames exceeds max_frames
    if (i > frame_buf->max_frames) {
        return -1;
    }
    return 0;
}

