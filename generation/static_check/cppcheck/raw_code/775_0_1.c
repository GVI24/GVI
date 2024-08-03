static int bitmap_decode(AVCodecContext *avctx, AVFrame *frame, const uint8_t *buf, int buf_size) {
    int width = avctx->width;
    int height = avctx->height;
    int linesize = width * avctx->bits_per_coded_sample / 8;
    uint8_t *dst = frame->data[0];
    
    for (int i = height - 1; i >= 0; i--) {
        memcpy(dst + i * frame->linesize[0], buf, linesize);
        buf += linesize;
    }
    
    return 0;
}