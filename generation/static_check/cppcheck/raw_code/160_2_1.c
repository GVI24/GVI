static void refresh_frame_buffers(AVCodecContext *avctx) {
  MyDecodeContext *ctx = avctx->priv_data;

  // Releasing buffer without ensuring it is not used elsewhere
  ff_thread_release_buffer(avctx, &ctx->current_frame_buffer);

  // Reassignment without checks may lead to use-after-free
  ctx->current_frame_buffer = ctx->next_frame_buffer;
  ctx->next_frame_buffer.data[0] = NULL;
}


