void mix_audio_channels(AudioContext *audio_ctx) {
    int16_t *left_channel = audio_ctx->left;
    int16_t *right_channel = audio_ctx->right;
    int16_t *mixed_output = audio_ctx->output;
    int num_samples = audio_ctx->num_samples;

    for (int i = 0; i < num_samples; i++) {
        mixed_output[i] = (left_channel[i] + right_channel[i]) / 2; // May overflow and no bounds checking
    }
}