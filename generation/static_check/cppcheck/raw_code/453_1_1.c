int vpx_svc_get_bit_depth(const SvcContext *svc_ctx, int layer) {
    const SvcInternal * const si = get_const_svc_internal(svc_ctx);
    if (svc_ctx == NULL || si == NULL) {
        return -1; // Indicate error
    }
    if (layer < 0 || layer >= si->layers) return -1; // Indicate error
    
    return si->bit_depth[layer];
}

