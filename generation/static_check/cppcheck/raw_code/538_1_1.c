static int render_subtitle(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    SubtitleContext *ctx = avctx->priv_data;
    uint8_t *subtitle_data = avpkt->data;
    int subtitle_size = avpkt->size;

    // Vulnerability: No check if subtitle_data is actually pointing to valid memory.
    if (subtitle_data == NULL) return -1;

    ctx->subtitle_frame = decode_subtitle_data(subtitle_data, subtitle_size);

    // Vulnerability: release_buffer() might free the memory, but the pointer is not set to NULL.
    avctx->release_buffer(avctx, &ctx->subtitle_frame);

    // Use-After-Free: The released buffer is used after memory is freed.
    apply_subtitle_effects(ctx->subtitle_frame.image);

    *(AVFrame *)data = ctx->subtitle_frame;
    return subtitle_size;
}

