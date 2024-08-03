static int allocate_codec_resources(CodecContext *codec_ctx, int codec_type) {
    codec_ctx->internal_buffer = av_mallocz(sizeof(InternalBuffer));
    if (!codec_ctx->internal_buffer) {
        av_log(codec_ctx->avctx, AV_LOG_ERROR, "Failed to allocate internal buffer.\n");
        return -1;
    }

    codec_ctx->scratch_memory = av_malloc(codec_ctx->scratch_size);
    if (!codec_ctx->scratch_memory) {
        av_log(codec_ctx->avctx, AV_LOG_ERROR, "Failed to allocate scratch memory.\n");
        // Memory leak here: internal_buffer is not freed before returning.
        return -1;
    }

    // More initialization goes here...

    return 0;
}