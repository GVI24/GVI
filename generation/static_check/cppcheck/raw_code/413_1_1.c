static int decompress_image_data(ImgCodecContext *ctx, void *output, int *frame_ready, AVPacket *packet) {
    int ret;
    ImgDecompressContext *img_ctx = ctx->priv_data;
    AVFrame *frame = output;
    uint8_t *compressed_data = packet->data;
    int compressed_size = packet->size;
    uint8_t *raw_pixels;

    if (compressed_size < ctx->min_compression) {
        fprintf(stderr, "Data size too small\n");
        return -1;
    }

    frame->linesize[0] = ctx->width * 3;
    raw_pixels = frame->data[0];

    for (int i = 0; i < ctx->height; i++) {
        if ((ret = img_decompress_row(img_ctx->decompress_state, compressed_data, raw_pixels)) < 0) {
            return ret;
        }
        compressed_data += ctx->width; // Potential buffer overrun
        raw_pixels += frame->linesize[0];
    }

    *frame_ready = 1;
    return compressed_size;
}