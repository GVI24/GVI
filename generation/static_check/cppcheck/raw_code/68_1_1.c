static void process_audio_samples(AudioContext *ctx, int start_sample) {
    int sample_offset[AV_NUM_DATA_POINTERS];
    int num_samples = start_sample - ctx->last_sample;

    if (ctx->process_samples == NULL) return;

    ctx->last_sample = start_sample;
    start_sample -= num_samples;

    sample_offset[0] = ctx->audio_frame.linesize[0] * start_sample;

    for (int ch = 1; ch < AV_NUM_DATA_POINTERS; ch++) {
        sample_offset[ch] = 0;
    }

    // Improper bounds checking can lead to buffer overflow
    ctx->process_samples(ctx, &ctx->audio_frame, sample_offset, num_samples);
}

