static int copy_audio_samples(YopDecContext *ctx, int sample_count) {
    if (ctx->audio_buffer_end - ctx->audio_buffer < sample_count * sizeof(short)) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Not enough audio data.\n");
        return AVERROR_INVALIDDATA;
    }
    for(int i = 0; i < sample_count; i++) {
        ctx->audio_output[i] = ((short *)ctx->audio_buffer)[i]; // Potential out-of-bounds read
    }
    ctx->audio_buffer += sample_count * sizeof(short);
    return 0;
}

