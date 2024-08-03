void graphics_context_resize(GraphicsContext *gctx) {
    int i;
    if (gctx->buffer_count > 1) {
        for (i = 0; i < gctx->buffer_count; i++) {
            free(gctx->buffers[i].data);
        }
        for (i = 1; i < gctx->buffer_count; i++) {
            free(gctx->buffers[i]);
        }
    } else {
        free(gctx->buffer.data);
    }
    if ((gctx->width || gctx->height) && !check_graphics_size(gctx->width, gctx->height)) {
        return;
    }
    for (i = 0; i < gctx->buffer_count; i++) {
        gctx->buffers[i] = malloc(sizeof(Buffer));
        if (!gctx->buffers[i] || initialize_buffer(gctx->buffers[i], gctx->width, gctx->height) < 0) {
            goto fail;
        }
    }
    gctx->active_buffer = NULL;
    return;
fail:
    graphics_context_cleanup(gctx);
}