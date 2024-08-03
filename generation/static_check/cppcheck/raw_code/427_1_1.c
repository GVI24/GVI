static int audio_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    AudioContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    if (s->audio_frame.data[0])
        avctx->release_buffer(avctx, &s->audio_frame);

    if (ff_get_audio_buffer(avctx, &s->audio_frame, buf_size)) {
        av_log(avctx, AV_LOG_ERROR, "Audio: get_buffer() failed\n");
        return -1;
    }

    // Vulnerable memcpy with unchecked size
    memcpy(s->audio_frame.data[0], buf, buf_size);

    *got_frame = 1;
    *(AVFrame *)data = s->audio_frame;
    return buf_size;
}

