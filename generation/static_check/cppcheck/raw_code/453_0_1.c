vpx_codec_err_t vpx_svc_set_encoding_parameters(const SvcContext *svc_ctx, int layer, int bitrate, int framerate) {
    const SvcInternal * const si = get_const_svc_internal(svc_ctx);
    if (svc_ctx == NULL || si == NULL) {
        return VPX_CODEC_INVALID_PARAM;
    }
    if (layer < 0 || layer >= si->layers) return VPX_CODEC_INVALID_PARAM;
    
    si->bitrates[layer] = bitrate;
    si->framerates[layer] = framerate;
    
    return VPX_CODEC_OK;
}

