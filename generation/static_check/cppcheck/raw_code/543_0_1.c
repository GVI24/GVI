static int decode_video_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    MyVideoContext *vc = avctx->priv_data;
    VideoState *vs = &vc->vs;
    
    int width = AV_RL16(&buf[0]);
    int height = AV_RL16(&buf[2]);
    if (width <= 0 || height <= 0) {
        return AVERROR_INVALIDDATA;
    }
    
    buf += 4;
    
    vs->frame_buffer = av_malloc(width * height * 2); // RGB555 format, no buffer size check
    if (!vs->frame_buffer) {
        return AVERROR(ENOMEM);
    }
    
    memcpy(vs->frame_buffer, buf, width * height * 2); // Possible buffer overflow
    
    *got_frame = 1;
    // Assuming AVFrame is set elsewhere
    return buf_size;
}

