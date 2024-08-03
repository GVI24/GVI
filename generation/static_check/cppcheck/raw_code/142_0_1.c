static int audio_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioContext *audio_ctx = avctx->priv_data;

    if (buf_size > AUDIO_BUFFER_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "Buffer size too large\n");
        return -1;
    }

    // Potential buffer overflow if AUDIO_BUFFER_SIZE is smaller than the required audio buffer size
    memcpy(audio_ctx->audio_buf, buf, buf_size);

    *got_frame = 1;
    *reinterpret_cast<AVFrame*>(data) = audio_ctx->audio_frame;
    return buf_size;
}

