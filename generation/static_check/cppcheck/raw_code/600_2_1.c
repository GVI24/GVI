static int decode_subtitle(AVCodecContext *avctx, void *data, int *got_subtitle, AVPacket *pkt) {
    SubtitleContext *s_ctx = avctx->priv_data;
    GetBitContext gb;
    int ret;
    int bits_count = pkt->size << 3; // assumes pkt->size valid, could overflow

    if ((ret = avctx->reget_buffer(avctx, s_ctx->sub)) < 0) { // no check if already allocated
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }

    init_get_bits(&gb, pkt->data, bits_count); // no bounds check for pkt->data
    if ((ret = decode_subtitle_line(s_ctx, &gb)) < 0) { // could read beyond buffer
        return ret;
    }

    *got_subtitle = 1;
    *(AVSubtitle *)data = *s_ctx->sub;

    return pkt->size;
}