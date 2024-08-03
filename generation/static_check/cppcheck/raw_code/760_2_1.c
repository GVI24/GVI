void init_audio_channels(AudioProcessorContext *ap_ctx) {
    int ch, coeff;
    for (ch = 0; ch < ap_ctx->channels; ch++) {
        for (coeff = 0; coeff < ap_ctx->coeff_count; coeff++) {
            float *channel_coeffs = &ap_ctx->coeffs[ch][coeff];
            float *backup_coeffs = &ap_ctx->backup_coeffs[ch][128 + coeff]; // Potential out-of-bounds write
            *backup_coeffs = *channel_coeffs;
        }
    }
}

