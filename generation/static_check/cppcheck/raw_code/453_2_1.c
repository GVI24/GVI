vpx_codec_err_t vpx_svc_initialize_layer(SvcContext *svc_ctx, int layer, int width, int height) {
    SvcInternal *si = get_svc_internal(svc_ctx);
    if (svc_ctx == NULL || si == NULL) {
        return VPX_CODEC_INVALID_PARAM;
    }
    if (layer < 0 || layer >= si->layers) return VPX_CODEC_INVALID_PARAM;
    
    si->layer_contexts[layer].width = width;
    si->layer_contexts[layer].height = height;
    
    return VPX_CODEC_OK;
}

