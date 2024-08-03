static int decode_video_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = avpkt->data + avpkt->size;
    int frame_width = 640, frame_height = 480; // Assume fixed frame size
    uint8_t *frame_data = data;
    
    // Check for minimum buffer size
    if (buf_end - buf < frame_width * frame_height * 2) return AVERROR_INVALIDDATA;

    for (int y = 0; y < frame_height; y++) {
        for (int x = 0; x < frame_width; x++) {
            if (buf_end - buf < 2) return AVERROR_INVALIDDATA;
            // Process YUV pixels ...
            buf += 2;
        }
    }

    *got_frame = 1;
    return avpkt->size;
}

