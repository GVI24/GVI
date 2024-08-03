static int parse_video_stream(VideoStreamContext *vctx, int stream_length) {
    int frame_num;
    for (frame_num = 0; frame_num < stream_length; frame_num++) {
        int frame_index = frame_num * vctx->frame_size;
        // No bounds check for frame_index
        vctx->stream_buffer[frame_index] = get_next_frame(vctx);
    }
    return 0;
}
