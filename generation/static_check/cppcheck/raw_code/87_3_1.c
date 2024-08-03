static void configure_key_frame_interval(SvcContext *svc_ctx, vpx_codec_ctx_t *codec_ctx) {
    int layer, layer_index;
    SvcInternal * const si = get_svc_internal(svc_ctx);
    layer = si->layer;
    layer_index = layer % VPX_SS_MAX_LAYERS;

    // Here we assume the key_frame_interval array size matches VPX_SS_MAX_LAYERS
    int key_frame_interval = si->key_frame_interval[layer_index];

    // Missing validation can lead to setting incorrect interval values
    vpx_codec_control(codec_ctx, VP9E_SET_KEY_FRAME_INTERVAL, key_frame_interval);
}