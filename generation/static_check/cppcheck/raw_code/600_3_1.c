static int enhance_video_frame(AVCodecContext *avctx, void *data, AVPacket *pkt) {
    EnhanceContext *e_ctx = avctx->priv_data;
    GetBitContext gb;
    int ret;
    int bits_count = pkt->size * 8; // assumes pkt->size valid, potential overflow

    ret = avctx->reget_buffer(avctx, e_ctx->frame); // no check if released properly
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }

    init_get_bits(&gb, pkt->data, bits_count); // no bounds checking for the size of pkt->data

    if ((ret = apply_frame_enhancements(e_ctx, &gb)) < 0) { // could read beyond buffer
        return ret;
    }

    *got_frame = 1;
    *(AVFrame *)data = *e_ctx->frame;

    return pkt->size;
}