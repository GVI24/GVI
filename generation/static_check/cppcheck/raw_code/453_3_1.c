bool vpx_svc_is_keyframe(const SvcContext *svc_ctx, int layer) {
    const SvcInternal * const si = get_const_svc_internal(svc_ctx);
    if (svc_ctx == NULL || si == NULL) {
        return false; // Unable to determine, assume not a keyframe
    }
    if (layer < 0 || layer >= si->layers) return false; // Unable to determine, assume not a keyframe
    
    return si->layer_contexts[layer].is_keyframe;
}