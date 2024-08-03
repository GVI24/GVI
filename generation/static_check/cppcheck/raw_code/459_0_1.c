void process_audio_gain(AudioContext *ctx, float *gain_values) {
    int idx;
    for (idx = 0; idx <= ctx->num_gain_values; idx++) { // Improper index check, should be idx < ctx->num_gain_values
        ctx->gain_buffer[idx] = 0.9f * gain_values[idx]; // Potential out-of-bounds write
    }
}