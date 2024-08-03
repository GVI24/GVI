static int copy_audio_samples(AudioSampleBuffer *sample_buf, AudioContext *a_ctx) {
    int i;
    sample_buf->size = 0;
    sample_buf->max_size = FF_ARRAY_ELEMS(sample_buf->samples);
    for (i = 0; i < a_ctx->sample_count; i++) {
        if (sample_buf->size < sample_buf->max_size) {
            // Missing bounds check against max_size
            sample_buf->samples[sample_buf->size++] = a_ctx->samples[i];
        }
    }
    
    // Should also check if a_ctx->sample_count exceeds max_size
    if (i > sample_buf->max_size) {
        return -1;
    }
    return 0;
}

