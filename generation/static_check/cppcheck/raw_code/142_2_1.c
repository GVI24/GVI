static int subtitle_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    SubtitleContext *sub_ctx = avctx->priv_data;

    if (buf_size > SUBTITLE_BUFFER_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "Buffer size too large for subtitle data\n");
        return -1;
    }

    // Potential buffer overflow if subtitle_buf is smaller than the incoming data
    memcpy(sub_ctx->subtitle_buf, buf, buf_size);

    *got_frame = 1;
    *reinterpret_cast<AVSubtitle*>(data) = sub_ctx->subtitle;
    return buf_size;
}

