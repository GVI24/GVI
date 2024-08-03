static int video_frame_reset(AVCodecContext *avctx) {
    VideoFrameContext *ctx = avctx->priv_data;
    ctx->yuv_buffers[0] = NULL;
    ctx->yuv_buffers[1] = NULL;
    ctx->yuv_buffers[2] = NULL;
    ctx->rgb_buffer = NULL;
    ctx->frame_data = NULL;
    ctx->scaling_coefficients = NULL;
    return 0;
}

