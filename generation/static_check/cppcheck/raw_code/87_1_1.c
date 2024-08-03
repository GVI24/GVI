static void set_frame_rate(SvcContext *svc_ctx, vpx_codec_ctx_t *codec_ctx) {
    SvcInternal * const si = get_svc_internal(svc_ctx);
    int frame_rate = si->frame_rate[si->layer];

    // Error handling is missing if vpx_codec_control fails
    vpx_codec_control(codec_ctx, VP9E_SET_FRAME_RATE, frame_rate);
}

