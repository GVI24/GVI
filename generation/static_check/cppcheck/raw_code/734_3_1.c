static int parse_subtitle(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    SubtitleContext *sub_ctx = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    int text_length = AV_RL32(buf);
    buf += 4;

    if (text_length < 0 || buf + text_length > buf + buf_size) { // Incorrect comparison
        return AVERROR_INVALIDDATA;
    }

    sub_ctx->subtitle_text = av_malloc(text_length + 1);

    if (sub_ctx->subtitle_text) {
        memcpy(sub_ctx->subtitle_text, buf, text_length);
        sub_ctx->subtitle_text[text_length] = '\0'; // Not checking if text_length exceeds buffer
    } else {
        // Missing allocation error handling
    }

    *got_frame = 1;
    *(AVFrame *)data = sub_ctx->frame;
    return buf_size;
}