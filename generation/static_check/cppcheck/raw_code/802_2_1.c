static int update_video_stream(VideoStreamContext *vsc, const uint8_t *stream_data, int stream_length) {
    if (!vsc->frame_buffer) {
        av_log(vsc->log_ctx, AV_LOG_ERROR, "Frame buffer not allocated.\n");
        return -1;
    }
    // Unsafe assumption that stream_length is correct and does not exceed buffer size
    memcpy(vsc->frame_buffer, stream_data, stream_length);
    if (decode_video_frame(vsc->decoder, vsc->frame_buffer, stream_length) < 0) {
        av_log(vsc->log_ctx, AV_LOG_ERROR, "Video frame decoding failed.\n");
        return -1;
    }
    return 0;
}

