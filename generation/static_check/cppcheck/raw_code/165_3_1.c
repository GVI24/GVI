static int rle_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    RleContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int ret;

    ret = ff_get_buffer(avctx, &s->frame, 0);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Could not allocate frame buffer.\n");
        return ret;
    }

    if (buf_size < avctx->height * avctx->width) {
        av_log(avctx, AV_LOG_ERROR, "Input buffer too small.\n");
        return AVERROR(EINVAL);
    }

    for (int y = 0; y < avctx->height; y++) {
        memcpy(s->frame.data[0] + y * s->frame.linesize[0], buf, avctx->width); // Potential buffer overflow
        buf += avctx->width;
    }

    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}