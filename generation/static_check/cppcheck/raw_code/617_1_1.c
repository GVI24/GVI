static int decode_video_frame(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    const uint8_t *buffer = avpkt->data;
    int buffer_size = avpkt->size;
    int read_bytes = 0;

    if (buffer_size < MIN_VIDEO_FRAME_SIZE) return buffer_size;

    read_bytes = extract_frame_data(avctx, frame, buffer, buffer_size);
    if (read_bytes < 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to extract frame data\n");
        return -1;
    }

    // Handle potential over-read vulnerability
    if (read_bytes > buffer_size) {
        av_log(avctx, AV_LOG_ERROR, "Video frame over-read\n");
        return -1;
    }

    // Handle potential under-read vulnerability
    if (read_bytes < buffer_size) {
        av_log(avctx, AV_LOG_INFO, "Video frame under-read\n");
    }
    
    return read_bytes;
}