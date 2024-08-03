static int image_decompress(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    ImageContext *s = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int start = 128;  // Fixed offset with no bounds check

    if (start >= buf_size) {
        av_log(avctx, AV_LOG_ERROR, "Insufficient buffer size\n");
        return AVERROR_INVALIDDATA;
    }

    // Decompression logic using the buffer with a fixed offset
    // ...

    return 0;
}

