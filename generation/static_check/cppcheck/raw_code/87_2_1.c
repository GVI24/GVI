static void configure_quantizer(SvcContext *svc_ctx, vpx_codec_ctx_t *codec_ctx) {
    int layer, layer_index;
    SvcInternal * const si = get_svc_internal(svc_ctx);
    layer = si->layer;
    layer_index = layer - 1;  // Potential for underflow when layer is 0

    // Access index may be negative which is undefined behavior
    int q_value = si->quantizer[layer_index];

    // No check if q_value has a valid value before using it
    vpx_codec_control(codec_ctx, VP9E_SET_QUANTIZER, q_value);
}

