static int decode_subtitle_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t subtitle_buf[512];
    SubtitleContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    int ret;

    if (avpkt->size < 16) {
        av_log(avctx, AV_LOG_ERROR, "Subtitle packet is too small\n");
        return AVERROR_INVALIDDATA;
    }

    bytestream2_init(&a->buffer, avpkt->data, avpkt->size);
    bytestream2_skip(&a->buffer, 6); // Skip header
    bytestream2_get_buffer(&a->buffer, subtitle_buf, avpkt->size - 6); // Potential buffer overflow

    // Process subtitle buffer...
    // Omitted for brevity

    *got_frame = 1;
    *(AVFrame *)data = a->frame;

    return avpkt->size;
}

