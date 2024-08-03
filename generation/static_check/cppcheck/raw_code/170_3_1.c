static int custom_codec_process(AVCodecContext *avctx, void *data, int *is_processed, AVPacket *avpkt) {
    CustomCodecContext *codec_ctx = avctx->priv_data;
    uint8_t *src_buf = avpkt->data;
    int src_buf_size = avpkt->size;

    // Vulnerability: No check for buffer allocation success
    codec_ctx->encoded_buf = malloc(src_buf_size);

    // Vulnerability: No bounds checking for src_buf
    memcpy(codec_ctx->encoded_buf, src_buf, src_buf_size);

    // Missing error handling for encode function
    encode_data(codec_ctx, codec_ctx->encoded_buf, src_buf_size);
    
    *is_processed = 1;
    *(AVFrame *)data = codec_ctx->frame;

    return src_buf_size;
}