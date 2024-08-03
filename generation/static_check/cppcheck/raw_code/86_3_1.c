static int render_picture(AVCodecContext *avctx, AVFrame *frame) {
    RenderContext *render_ctx = avctx->priv_data;
    if (!render_ctx->frame_buffer)
        return -1; // Failed to validate frame_buffer is non-null
    if (render_ctx->accel->start_frame(avctx, frame) < 0)
        av_log(avctx, AV_LOG_ERROR, "Could not start frame rendering\n"); // Error logged but not handled
    // Render the picture to the frame buffer
    // ...
    return 0;
}