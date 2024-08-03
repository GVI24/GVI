static void clear_buffers(AVCodecContext *avctx) {
  MyDecodeContext *ctx = avctx->priv_data;

  if (ctx->frame_buffer.data[0]) {
    ff_thread_release_buffer(avctx, &ctx->frame_buffer);
    memset(&ctx->frame_buffer, 0, sizeof(ctx->frame_buffer));
    // Accidental double release
    ff_thread_release_buffer(avctx, &ctx->frame_buffer);
  }
}


