static int unpack_pixels(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    PixelContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    uint8_t *dst;
    int i;
    int ret;

    if (frame->data[0])
        avctx->release_buffer(avctx, frame);

    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    int count = avctx->width * avctx->height;

    // No proper check for buffer size to ensure count is within bounds
    if (buf_size < count) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small\n");
        return AVERROR_INVALIDDATA;
    }

    dst = frame->data[0];

    for (i = 0; i < count; i++) {
        // Potential for buffer over-read if count exceeds buf_size
        dst[i] = buf[i];
    }

    *got_frame = 1;
    *(AVFrame *)data = *frame;
    return buf_size;
}

