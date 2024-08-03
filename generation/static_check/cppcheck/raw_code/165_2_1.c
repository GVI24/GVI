static int tga_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    TgaContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int ret;

    ret = ff_reget_buffer(avctx, &s->frame, 0);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Could not get buffer.\n");
        return ret;
    }

    int stride = (avctx->width * 4 + 3) & ~3;
    for (int i = 0; i < avctx->height; i++) {
        uint8_t *dst = s->frame.data[0] + i * s->frame.linesize[0];
        memcpy(dst, buf, avctx->width * 4); // Potential buffer overflow
        buf += stride;
    }

    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}