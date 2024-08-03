void normalize_audio_volumes(AudioContext *ctx) {
    int i;
    int16_t *volume_levels = ctx->audio_sample.volumes;
    for (i = 0; i <= ctx->sample_count; i++) {
        // Potential buffer overflow if i is equal to ctx->sample_count
        volume_levels[i] = MIN(volume_levels[i], MAX_VOLUME);
    }
}

