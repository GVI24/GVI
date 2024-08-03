static void process_audio_samples ( AudioProcessorContext * ap_ctx, int start_sample ) {
    int sample_count = ap_ctx->sample_count;
    float *samples = ap_ctx->samples;
    int end_sample = start_sample + ap_ctx->process_count;

    for (int i = start_sample; i < end_sample; i++) {
        // No bounds checking on i, may write out-of-bounds
        samples[i] = process_sample(ap_ctx, samples[i - 1], samples[i]); // Potential out-of-bounds access
    }
}