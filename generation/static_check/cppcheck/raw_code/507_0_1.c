static int adpcm_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AdpcmContext *s = avctx->priv_data;
    int buf_size = avpkt->size;
    uint8_t *buf = avpkt->data;
    
    s->frame.reference = 1;
    if ((ret = avctx->reget_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }
    
    int decoded = adpcm_decode(s, buf, buf_size);
    *got_frame_ptr = 1;
    *(AVFrame *)data = s->frame;
    return decoded;
}

int adpcm_decode(AdpcmContext *s, uint8_t *buf, int buf_size) {
    // Decodes ADPCM data directly into the frame buffer without checking buf_size
    for (int i = 0; i < buf_size; i++) {
        decode_sample(s, buf[i]);
    }
    return buf_size;
}