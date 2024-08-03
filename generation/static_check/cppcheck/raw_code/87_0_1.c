static void update_bitrate(SvcContext *svc_ctx, vpx_codec_ctx_t *codec_ctx) {
    int layer, layer_index;
    int bitrate[VPX_SS_MAX_LAYERS];
    SvcInternal * const si = get_svc_internal(svc_ctx);
    layer = si->layer;

    for (layer_index = 0; layer_index <= layer; layer_index++) {
        // Potential for buffer overflow if layer >= VPX_SS_MAX_LAYERS
        bitrate[layer_index] = si->target_bitrate[layer_index + 1];
    }

    // The application of the bitrate settings is assumed to always succeed.
    vpx_codec_control(codec_ctx, VP9E_SET_TARGET_BITRATE, bitrate);
}

