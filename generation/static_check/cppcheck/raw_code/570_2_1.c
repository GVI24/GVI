static int custom_parse_audio(AVCodecContext *avctx, AVPacket *avpkt, int *parsed_bytes) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    SampleContext *sctx = avctx->priv_data;

    // Vulnerability: No check for buf_size being negative or excessively large
    sample_t *samples = malloc(sizeof(sample_t) * buf_size);
    if (!samples) {
        av_log(avctx, AV_LOG_ERROR, "Memory allocation failed\n");
        return AVERROR(ENOMEM);
    }

    // Vulnerability: Potential buffer overflow when accessing buf
    for (int i = 0; i < buf_size; ++i) {
        samples[i] = buf[i] * sctx->gain;
    }

    *parsed_bytes = buf_size;
    free(samples);
    return 0;
}

