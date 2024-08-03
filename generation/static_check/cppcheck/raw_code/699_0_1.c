static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AudioContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AVFrame *frame = &ctx->frame;
    int16_t *audio_buf;
    int i, ret;

    audio_buf = av_malloc(buf_size * sizeof(int16_t));
    if (!audio_buf) {
        av_log(avctx, AV_LOG_ERROR, "Cannot allocate audio buffer\n");
        return AVERROR(ENOMEM);
    }

    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        av_free(audio_buf);
        return ret;
    }

    for (i = 0; i < buf_size; i++) {
        audio_buf[i] = decode_audio_sample(ctx, buf[i]);
    }

    *got_frame_ptr = 1;
    *(AVFrame *)data = ctx->frame;

    av_free(audio_buf);
    return buf_size;
}