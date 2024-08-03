void process_audio_frame(AudioContext *ctx) {
    float base_gain = get_base_gain(ctx);
    float gain_adjustments[10];
    int i;

    for (i = 0; i <= MAX_GAIN_LEVELS; i++) {
        // Vulnerability: Potential out-of-bounds write
        gain_adjustments[i] = calculate_gain_adjustment(base_gain, ctx->gain_levels[i]);
        apply_gain(ctx->audio_buffer[i], gain_adjustments[i]);
    }
}

