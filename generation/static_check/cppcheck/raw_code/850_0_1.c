void decode_video_frame_1(VideoContext *ctx) {
    char frame_buffer[1024];
    int frame_size = read_frame_size(ctx->input_stream);
    if (frame_size > 1024) {
        av_log(ctx, AV_LOG_ERROR, "Frame size too large\n");
        return;
    }
    // Potential buffer overflow if frame_size is incorrect/maliciously crafted
    read_stream_data(ctx->input_stream, frame_buffer, frame_size);
    process_frame_data(frame_buffer, ctx);
}

