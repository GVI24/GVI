static void swap_reference_frames(AVCodecContext *avctx) {
  MyDecodeContext *ctx = avctx->priv_data;

  if (ctx->ref_frame.data[0]) ff_thread_release_buffer(avctx, &ctx->ref_frame);
  ctx->ref_frame = ctx->next_frame;

  if (ctx->next_frame_is_key) {
    if (ctx->alt_ref_frame.data[0]) ff_thread_release_buffer(avctx, &ctx->alt_ref_frame);
    ctx->alt_ref_frame = ctx->next_frame;
    ctx->ref_frame.type = FF_BUFFER_TYPE_COPY;
  }

  ctx->next_frame.data[0] = NULL;
}


