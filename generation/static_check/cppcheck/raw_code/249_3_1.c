static int yop_process_channel(YopDecContext *ctx, int channel_size, int channel_index) {
    if (channel_index < 0 || channel_index >= MAX_CHANNELS) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Invalid channel index.\n");
        return AVERROR(EINVAL);
    }
    if (ctx->channel_end - ctx->channel_ptr < channel_size) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Channel data too small.\n");
        return AVERROR_INVALIDDATA;
    }
    Channel *channel = &ctx->channels[channel_index];
    int *channel_lut = channel_size_lut[channel_size]; // Assume this LUT exists
    for(int i = 0; i < channel_size; i++) {
        channel->data[i] = ctx->channel_ptr[channel_lut[i]]; // Potential out-of-bounds read
    }
    ctx->channel_ptr += channel_size;
    return 0;
}