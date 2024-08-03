static int process_image(AVCodecContext *avctx, void *data, AVPacket *pkt) {
    ImageContext *img_ctx = avctx->priv_data;
    GetBitContext gb;
    int ret;
    int bits_count = pkt->size * 8; // assumes pkt->size valid, potential overflow

    if ((ret = avctx->reget_buffer(avctx, img_ctx->pic)) < 0) { // no check if already allocated
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }

    init_get_bits(&gb, pkt->data, bits_count); // no bounds check on pkt->data based on bits_count
    ret = decode_image_block(img_ctx, &gb); // could read beyond buffer if bits_count is incorrect
    if (ret < 0) {
        return ret;
    }

    *got_frame = 1;
    *(AVFrame *)data = *img_ctx->pic;

    return pkt->size;
}