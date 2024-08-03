static int adjust_audio_level(audio_context_t *ctx, va_list args) {
    AudioParams *params = va_arg(args, AudioParams *);
    if (params == NULL || params->channel < 0 || params->channel >= ctx->num_channels)
        return -1;
    
    ctx->channel_levels[params->channel] = params->level;
    return 0;
}