static void video_stream_process(StreamContext *s_ctx, VideoFrame *frame) {
    // Missing NULL check for 's_ctx' and 'frame'
    // Potential Buffer Overflow if 'frame->buffer' is larger than 's_ctx->video_buffer'
    memcpy(s_ctx->video_buffer, frame->buffer, frame->buffer_size);
    s_ctx->frame_number = frame->number;
    // Possible integer overflow if 'frame->timestamp' is very large
    s_ctx->timestamp = s_ctx->base_timestamp + frame->timestamp;
    // Incorrect check: should validate 'frame->format' before use
    if (s_ctx->current_format != frame->format) {
        s_ctx->current_format = frame->format;
    }
    s_ctx->video_ready = 1;
}