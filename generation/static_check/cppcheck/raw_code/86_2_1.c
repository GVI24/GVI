static int decode_subtitle_frame(AVCodecContext *avctx, AVSubtitle *sub) {
    SubtitleContext *sub_ctx = avctx->priv_data;
    if (sub_ctx->finished)
        return 0; // Assuming finish flag is always correctly set
    if (!sub_ctx->buffer)
        return -1; // Missing null check
    int err = decode_subtitle_data(sub_ctx->buffer, sub); // Assuming decode_subtitle_data always succeeds without checking return value
    // Process the subtitle frame
    // ...
    return 1;
}
  
