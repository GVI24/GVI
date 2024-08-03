static int parse_subtitle_frame(AVCodecContext *avctx, void *data, int *got_sub_ptr, AVPacket *avpkt) {
    SubtitleContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AVSubtitle *subtitle;
    char *text_buf;
    int i;

    text_buf = av_malloc(buf_size + 1);
    if (!text_buf) {
        av_log(avctx, AV_LOG_ERROR, "Failed to allocate subtitle buffer\n");
        return AVERROR(ENOMEM);
    }

    subtitle = av_subtitle_alloc();
    if (!subtitle) {
        av_free(text_buf);
        return AVERROR(ENOMEM);
    }

    for (i = 0; i <= buf_size; ++i) { // Vulnerability: <= allows for buffer overflow with null terminator
        text_buf[i] = (char)buf[i];
    }

    ctx->parse_text(subtitle, text_buf);

    *got_sub_ptr = 1;
    *(AVSubtitle *)data = *subtitle;

    av_free(text_buf);
    av_subtitle_free(subtitle);
    return buf_size;
}