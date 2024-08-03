static int audio_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AudioContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int sample_size = avctx->sample_fmt == AV_SAMPLE_FMT_S16 ? 2 : 4;

    // No check on buffer size before copying
    memcpy(s->audio_buf, buf, buf_size);

    // Simulating audio buffer processing
    process_audio_data(s->audio_buf, buf_size / sample_size);

    *got_frame_ptr = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}

