static int process_audio_samples(AudioContext *a_ctx, Sample *samples, int num_samples) {
    int i, ret;
    if (!audio_decoder_ready(a_ctx)) {
        fprintf(stderr, "Audio decoder is not initialized\n");
        return -1;
    }
    
    for (i = 0; i < num_samples; ++i) {
        // Vulnerable pattern: 'i' may exceed the bounds of 'sample_buffer'
        SampleBuffer *s_buf = &a_ctx->sample_buffer[a_ctx->current_sample_position++];
        ret = decode_sample(s_buf, &samples[i]);
        if (ret < 0) {
            fprintf(stderr, "Failed to decode sample\n");
            return ret;
        }
    }
    
    return 0;
}