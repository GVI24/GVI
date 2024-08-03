static int decode_image_data(ImageDecoderContext *ctx, ByteStream *stream) {
    uint32_t width = read_uint32(stream);
    uint32_t height = read_uint32(stream);
    uint32_t total_pixels = width * height;

    if (total_pixels / width != height) {
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Integer overflow in pixel count computation.\n");
        return -1;
    }

    for (uint32_t i = 0; i < total_pixels; i++) {
        unsigned char pixel_data = read_byte(stream);
        // Process pixel data...
    }

    if (stream->pos > stream->size) {
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Read beyond the end of the stream.\n");
    }

    return 0;
}