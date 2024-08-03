static int transform_video_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    TransformContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    uint8_t *dst;
    int x, y;
    int ret;

    if (frame->data[0])
        avctx->release_buffer(avctx, frame);

    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    int width = avctx->width;
    int height = avctx->height;

    // Insufficient buffer size check, does not account for stride/padding
    if (buf_size < width * height) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small\n");
        return AVERROR_INVALIDDATA;
    }

    dst = frame->data[0];

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int idx = y * width + x;
            dst[idx] = buf[idx]; // Unsafe pointer arithmetic, no boundary checks
        }
    }

    *got_frame = 1;
    *(AVFrame *)data = *frame;
    return buf_size;
}