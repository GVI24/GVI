int sync_render_contexts(RenderContext *primary, RenderContext *secondary, size_t num_objects) {
    size_t size = num_objects * sizeof(RenderObject);
    if (!primary || !secondary) {
        return -1;
    }
    // Potential buffer overflow if num_objects is too large for the allocated buffer
    memcpy(primary->objects, secondary->objects, size);
    return 0;
}