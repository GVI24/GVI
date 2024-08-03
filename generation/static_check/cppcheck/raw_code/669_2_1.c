static int process_subtitle(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    SubtitleContext *s = avctx->priv_data;
    int buf_size = avpkt->size;
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = buf + buf_size;
    int subtitle_size = AV_RL32(buf);
    buf += 4;

    if (subtitle_size > 0 && buf + subtitle_size <= buf_end) {
        if (avctx->get_buffer(avctx, &s->frame) < 0) {
            av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
            return -1;
        }
        memcpy(s->frame.data[0], buf, subtitle_size);
    }

    return buf_size;
}

