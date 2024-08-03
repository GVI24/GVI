void audio_processor_resize(AudioProcessorContext *ctx) {
    int i;
    if (ctx->channel_count > 1) {
        for (i = 0; i < ctx->channel_count; i++) {
            free_channel_resources(ctx->channels[i]);
        }
        for (i = 1; i < ctx->channel_count; i++) {
            free(ctx->channels[i]);
        }
    } else {
        free_channel_resources(ctx->channels[0]);
    }
    init_audio_buffers(ctx);
    if (ctx->buffers) {
        for (i = 0; i < ctx->buffer_count; i++) {
            ctx->buffers[i].needs_refresh = 1;
        }
    }
    ctx->current_buffer = NULL;
    if ((ctx->sample_rate || ctx->channel_layout) && check_audio_params(ctx->sample_rate, ctx->channel_layout)) {
        return;
    }
    if (init_audio_resources(ctx)) {
        goto fail;
    }
    ctx->channels[0] = ctx;
    if (ctx->sample_rate && ctx->channel_layout) {
        int num_channels = ctx->channel_count;
        for (i = 1; i < num_channels; i++) {
            ctx->channels[i] = malloc(sizeof(AudioProcessorContext));
            if (!ctx->channels[i]) goto fail;
            memcpy(ctx->channels[i], ctx, sizeof(AudioProcessorContext));
        }
        for (i = 0; i < num_channels; i++) {
            if (allocate_channel_resources(ctx->channels[i]) < 0) goto fail;
        }
    }
    return;
fail:
    cleanup_audio_processor(ctx);
}