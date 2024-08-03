static int bmp_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    BmpContext *s = avctx->priv_data;
    int ret;

    if ((ret = ff_get_buffer(avctx, &s->frame, 0)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to get buffer.\n");
        return ret;
    }

    int width = avctx->width;
    int height = avctx->height;
    for (int y = height - 1; y >= 0; y--) {
        uint8_t *dst = s->frame.data[0] + y * s->frame.linesize[0];
        memcpy(dst, buf, width * 3); // Potential buffer overflow
        buf += width * 3;
    }

    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}