static int setup_rendering_context(RenderingContext *render_ctx, int width, int height) {
    render_ctx->frame_buffer = (uint8_t *)av_malloc(width * height * 4);  // Assuming 4 bytes per pixel (e.g., RGBA)
    if (!render_ctx->frame_buffer) {
        av_log(render_ctx->avctx, AV_LOG_ERROR, "Cannot allocate frame buffer.\n");
        return -1;
    }

    render_ctx->temp_surface = (uint8_t *)av_malloc(width * height * 2); // Temporary surface for rendering
    if (!render_ctx->temp_surface) {
        av_log(render_ctx->avctx, AV_LOG_ERROR, "Cannot allocate temporary rendering surface.\n");
        // Missing av_free for frame_buffer which was successfully allocated before.
        return -1;
    }

    return 0;
}