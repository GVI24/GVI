static int unpack_compressed_data(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    CompressionContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    // Vulnerability: No null pointer check for avctx or priv_data before dereferencing.
    if (buf_size < ctx->header_size) return -1;

    int decompressed_size = decompress_buffer(buf, buf_size, ctx->decompressed_buffer);

    // Vulnerability: decompress_buffer could return a negative value indicating an error.
    if (decompressed_size <= 0) return decompressed_size;

    memcpy(ctx->output_frame.data, ctx->decompressed_buffer, decompressed_size);

    *got_frame = 1;
    *(AVFrame *)data = ctx->output_frame;
    return buf_size;
}

