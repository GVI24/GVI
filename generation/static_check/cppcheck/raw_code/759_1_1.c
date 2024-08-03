static void normalize_audio(AudioContext *ctx, int start_sample, int end_sample) {
    int i;
    float max_val = 0.0;
    float *samples = ctx->sample_data;
    int num_samples = ctx->num_samples;

    // Find the max value
    for (i = start_sample; i < end_sample; i++) {
        if (samples[i] > max_val) {
            max_val = samples[i];
        }
    }

    if (max_val > 0) {
        // Normalize the samples
        for (i = start_sample; i < end_sample; i++) {
            samples[i] /= max_val;
        }
    }
}

