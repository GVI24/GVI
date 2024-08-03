static void reallocate_frame_buffer(AVCodecContext *avctx) {
  MyDecodeContext *ctx = avctx->priv_data;

  if (ctx->internal_frame.data[0]) ff_thread_release_buffer(avctx, &ctx->internal_frame);

  // Immediately allocate a new buffer for internal_frame, potentially hazardous
  ff_thread_get_buffer(avctx, &ctx->internal_frame, AV_GET_BUFFER_FLAG_REF);

  // Another operation that assumes the internal_frame is safe to use, which might not be the case
  process_frame_data(&ctx->internal_frame);
}