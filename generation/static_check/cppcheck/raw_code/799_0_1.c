static int process_image_frame(AVCodecContext *ctx, void *data, int *frame_ready, AVPacket *packet) {
    ImageContext *img_ctx = ctx->priv_data;
    AVFrame *output_frame = &img_ctx->frame;
    int ret, buf_size = packet->size;
    const uint8_t *buf = packet->data;

    // Simplified size check; vulnerable to integer overflow
    if (buf_size < 24) return AVERROR_INVALIDDATA;

    // No bounds checking for reading width and height
    img_ctx->width = AV_RB16(&buf[10]);
    img_ctx->height = AV_RB16(&buf[12]);

    // Potential buffer overflow if dimensions are too large
    if ((ret = av_image_check_size(img_ctx->width, img_ctx->height, 0, ctx)) < 0) return ret;

    // Assumes a fixed pixel format and depth, vulnerable to incorrect buffer size calculations
    if (buf_size < img_ctx->width * img_ctx->height * 3) return AVERROR_INVALIDDATA;

    if ((ret = ff_get_buffer(ctx, output_frame)) < 0) {
        av_log(ctx, AV_LOG_ERROR, "Failed to allocate buffer\n");
        return ret;
    }

    output_frame->pict_type = AV_PICTURE_TYPE_I;
    process_rgb_data(img_ctx, buf + 24); // Function assumed to exist; potentially copies more data than available

    *frame_ready = 1;
    *(AVFrame *)data = img_ctx->frame;

    return buf_size;
}