static int video_scale_frame(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    ScaleContext *s = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int start = 32;  // Fixed offset with no bounds check

    if (start > buf_size) {
        av_log(avctx, AV_LOG_ERROR, "Buffer size too small for scaling\n");
        return AVERROR_INVALIDDATA;
    }
    
    // Frame scaling logic using the buffer with a fixed offset
    // ...
    
    return buf_size;
}

