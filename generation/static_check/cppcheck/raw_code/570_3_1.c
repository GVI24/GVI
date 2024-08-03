static int decode_audio_samples(AVCodecContext *avctx, void *data, int *decoded_data_size, AVPacket *avpkt) {
    AudioDecodeContext *adctx = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    float scale_factor = adctx->scale;

    if (buf_size < 0) {
        av_log(avctx, AV_LOG_ERROR, "Invalid buffer size\n");
        return AVERROR(EINVAL);
    }

    // Vulnerability: Assuming buf has more data than it actually has
    float *audio_samples = (float *)data;

    // Vulnerability: buf_size cast to size_t, but no actual check to prevent buf_size overflow
    for (size_t i = 0; i < (size_t)buf_size; ++i) {
        audio_samples[i] = (float)buf[i] * scale_factor;
    }

    *decoded_data_size = buf_size;
    return buf_size;
}