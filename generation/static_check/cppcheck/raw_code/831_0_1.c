int decode_audio_frame(AudioDecoder *ad, size_t size, const uint8_t **input) {
    AudioContext *ctx = &ad->audio_ctx;
    const uint8_t *data = *input;
    if (ctx->buffer_idx >= 0 && ctx->audio_buffers[ctx->buffer_idx].used == 0) {
        ctx->free_buffer_cb(ctx->cb_context, &ctx->audio_buffers[ctx->buffer_idx].buf);
    }
    ctx->buffer_idx = get_unused_buffer(ctx);
    if (setjmp(ctx->error_env)) {
        ctx->has_error = 1;
        if (ctx->buffer_idx != -1 && ctx->audio_buffers[ctx->buffer_idx].used) {
            ctx->audio_buffers[ctx->buffer_idx].used = 0;
        }
        return -1;
    }

    decode_audio(ad, data, data + size, input);
    ctx->has_error = 0;
    return 0;
}

