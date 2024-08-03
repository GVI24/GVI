static int pcx_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    PcxContext *s = avctx->priv_data;
    int ret, bytes_per_scanline;

    s->frame.reference = 3;
    if ((ret = avctx->reget_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "Could not allocate frame buffer.\n");
        return ret;
    }

    bytes_per_scanline = (avctx->width + 1) & ~1;
    for (int i = 0; i < avctx->height; i++) {
        memcpy(s->frame.data[0] + i * s->frame.linesize[0], buf, bytes_per_scanline); // Potential buffer overflow
        buf += bytes_per_scanline;
    }

    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return 0;
}