static int h263_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    H263Context *s = avctx->priv_data;
    int buf_size = avpkt->size;
    
    if ((ret = avctx->reget_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }
    
    // Potentially unsafe buffer handling without any size validation
    h263_decode_stream(s, avpkt->data, buf_size);
    
    *got_frame_ptr = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}

void h263_decode_stream(H263Context *s, uint8_t *buf, int buf_size) {
    // Simplified H.263 decoding logic with unsafe buffer handling
    for (int i = 0; i < buf_size; i += 2) {
        decode_h263_macroblock(s, &buf[i]);
    }
}