static int parse_audio_data(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    AudioContext *s = avctx->priv_data;
    int buf_size = avpkt->size;
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = buf + buf_size;
    int audio_size;

    audio_size = AV_RL32(buf);
    buf += 4;
    if (audio_size > 0) {
        if (audio_size > buf_end - buf) {
            av_log(avctx, AV_LOG_ERROR, "Buffer size is too small for audio data\n");
            return -1;
        }
        int16_t *output = (int16_t *)data;
        for (int i = 0; i < audio_size / 2 && buf + 1 < buf_end; i++) {
            output[i] = AV_RL16(buf);
            buf += 2;
        }
    }
    return 0;
}

