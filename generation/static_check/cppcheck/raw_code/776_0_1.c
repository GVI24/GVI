static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t audio_buf[256];
    AudioContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    int ret;

    if (avpkt->size < 10) {
        av_log(avctx, AV_LOG_ERROR, "Audio packet is too small\n");
        return AVERROR_INVALIDDATA;
    }

    bytestream2_init(&a->buffer, avpkt->data, avpkt->size);
    bytestream2_skip(&a->buffer, 2); // Skip header
    bytestream2_get_buffer(&a->buffer, audio_buf, sizeof(audio_buf));

    // Process audio buffer...
    // Omitted for brevity

    *got_frame = 1;
    *(AVFrame *)data = a->frame;

    return avpkt->size;
}

