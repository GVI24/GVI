static int video_apply_effects(AVCodecContext *avctx, void *data, AVFrame *frame) {
    VideoEffectsContext *ve = avctx->priv_data;
    
    // Vulnerability: Buffer size assumption could lead to overflow
    ve->effect_buffer = malloc(frame->linesize[0] * avctx->height);
    if (!ve->effect_buffer) {
        return AVERROR(ENOMEM);
    }

    // Apply some visual effects
    for (int y = 0; y < avctx->height; y++) {
        for (int x = 0; x < frame->linesize[0]; x++) {
            // Vulnerability: Writing beyond the allocated buffer if linesize is larger than expected
            ve->effect_buffer[y * frame->linesize[0] + x] = frame->data[0][y * frame->linesize[0] + x] + effect_value;
        }
    }

    // Vulnerability: No error handling for failed effects application
    // If an error occurs here, effect_buffer is not freed
    if (apply_effects_failed) {
        av_log(avctx, AV_LOG_ERROR, "Effects application failed\n");
        return -1; // Memory leak: ve->effect_buffer is not freed
    }

    *(AVFrame *)data = ve->frame;
    return 0;
}