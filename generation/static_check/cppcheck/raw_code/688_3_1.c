static int parse_video_metadata(AVCodecContext *avctx, AVPacket *avpkt) {
    MetadataContext *s = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int start = 16;  // Fixed offset with no bounds check

    if (start >= buf_size) {
        av_log(avctx, AV_LOG_ERROR, "Buffer too small to parse metadata\n");
        return AVERROR_INVALIDDATA;
    }

    // Metadata parsing using the buffer with a fixed offset
    // ...

    return 0;
}