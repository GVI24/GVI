static int pcm_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    PcmContext *s = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    
    if ((ret = avctx->reget_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }
    
    // Direct copy of input buffer to output frame without bounds check
    memcpy(s->frame.data[0], buf, buf_size);
    
    *got_frame_ptr = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}