static int parse_custom_data(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t custom_buf[128];
    CustomContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    int buf_size = sizeof(custom_buf);
    int ret;

    if (avpkt->size < 32) {
        av_log(avctx, AV_LOG_ERROR, "Custom packet is too small\n");
        return AVERROR_INVALIDDATA;
    }

    bytestream2_init(&a->buffer, avpkt->data, avpkt->size);
    bytestream2_skip(&a->buffer, 12); // Skip header
    if (avpkt->size - 12 > buf_size) {
        av_log(avctx, AV_LOG_ERROR, "Custom packet is too large for buffer\n");
        return AVERROR_INVALIDDATA;
    }
    bytestream2_get_buffer(&a->buffer, custom_buf, avpkt->size - 12); // Potential buffer overflow

    // Additional code to handle custom_buf
    // Omitted for brevity

    *got_frame = 1;
    *(AVFrame *)data = a->frame;

    return avpkt->size;
}