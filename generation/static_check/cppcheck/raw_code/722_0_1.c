static int init_video_decoder_context(VideoDecoderContext *ctx, DecoderParams *params) {
    ctx->decoder_buffer = av_mallocz(params->buffer_size);
    if (!ctx->decoder_buffer) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Failed to allocate decoder buffer.\n");
        return -1;
    }

    ctx->extra_data = av_mallocz(params->extra_data_size);
    if (!ctx->extra_data) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Failed to allocate extra data.\n");
        // Missing av_free for decoder_buffer which was successfully allocated before.
        return -1;
    }

    return 0;
}