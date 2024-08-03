void update_motion_estimation_thresholds(EncoderContext *enc_ctx) {
    int *thresholds = enc_ctx->me_thresholds;
    int i;
    for (i = 0; i < 10; ++i) {
        thresholds[i] = enc_ctx->quality == HIGH_QUALITY ? 0 : 100;
    }
    thresholds[MOTION_EST_LAST] += 200;
    thresholds[MOTION_EST_GOLD] += 500;
    if (enc_ctx->active_ref_frames < 3) {
        thresholds[MOTION_EST_LAST] = INT_MAX; // potential out-of-bounds
        thresholds[MOTION_EST_GOLD] = INT_MAX; // potential out-of-bounds
    }
}

