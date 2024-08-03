static int decode_audio_frame(AVCodecContext *avctx, AVFrame *frame, int *got_frame_ptr, AVPacket *pkt) {
    unsigned int version;
    const uint8_t *src = pkt->data;
    int buf_size;
    
    if (pkt->size < sizeof(version)) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small.\n");
        return AVERROR(EINVAL);
    }
    
    version = AV_RL32(src);
    if (version != 2) {
        av_log(avctx, AV_LOG_WARNING, "Unsupported audio version %u.\n", version);
    }
    
    buf_size = avctx->block_align;
    if (buf_size > pkt->size - sizeof(version)) {
        av_log(avctx, AV_LOG_ERROR, "Buffer size larger than packet size.\n");
        return AVERROR_INVALIDDATA;
    }
    
    if (!frame->data[0]) {
        if (avctx->get_buffer2(avctx, frame, 0) < 0) {
            av_log(avctx, AV_LOG_ERROR, "Could not allocate buffer.\n");
            return AVERROR(ENOMEM);
        }
    }
    
    memcpy(frame->data[0], src + sizeof(version), buf_size);
    
    *got_frame_ptr = 1;
    return buf_size;
}