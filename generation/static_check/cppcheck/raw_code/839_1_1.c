static int decode_image(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    ImageContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    uint8_t *pixels;
    int i;
    int ret;
    int width, height;

    if (frame->data[0])
        avctx->release_buffer(avctx, frame);

    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    width = avctx->width;
    height = avctx->height;

    if (buf_size < width * height * 3) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small\n");
        return AVERROR_INVALIDDATA;
    }

    pixels = frame->data[0];

    for (i = 0; i < width * height; i++) {
        pixels[i * 3] = buf[i * 3];       // Red channel
        pixels[i * 3 + 1] = buf[i * 3 + 1]; // Green channel
        pixels[i * 3 + 2] = buf[i * 3 + 2]; // Blue channel
        // No consideration for buffer size, possible overflow
    }

    *got_frame = 1;
    *(AVFrame *)data = *frame;
    return buf_size;
}

