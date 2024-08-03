static int process_video_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t *buffer = avpkt->data;
    int buffer_size = avpkt->size;
    VideoContext *video = avctx->priv_data;
    uint8_t *buffer_end = buffer + buffer_size;
    int frame_type, ret;

    frame_type = AV_RL32(buffer);
    buffer += HEADER_SIZE; // Assume defined elsewhere

    if (frame_type == FRAME_TYPE_I) {
        int width = AV_RL16(buffer);
        int height = AV_RL16(buffer + 2);
        buffer += 8;

        if (buffer + width * height > buffer_end) {
            // Possible buffer overflow if width or height is too large
            return AVERROR_INVALIDDATA;
        }

        // ... (processing continues, omitted for brevity) ...
        
        memcpy(video->frame.data, buffer, width * height); // Vulnerable to buffer overflow
    }

    *got_frame = 1;
    *(AVFrame *)data = video->frame;
    return buffer_size;
}