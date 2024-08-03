static int process_image_data(AVCodecContext *avctx, const uint8_t *data_buf, int buf_len) {
    ImageContext *ctx = avctx->priv_data;
    int width, height, row, col;
    uint16_t pixel;

    if (buf_len < 5) {
        av_log(avctx, AV_LOG_ERROR, "image data too small\n");
        return AVERROR_INVALIDDATA;
    }

    width = AV_RB16(data_buf);
    height = AV_RB16(data_buf + 2);
    data_buf += 4; // skip width and height info
    buf_len -= 4;

    if (width * height * sizeof(uint16_t) != buf_len) {
        av_log(avctx, AV_LOG_ERROR, "incorrect image size\n");
        return AVERROR_INVALIDDATA;
    }

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            // Unsafe calculation may lead to buffer overflow
            pixel = AV_RB16(data_buf + (row * width + col) * sizeof(uint16_t));
            process_image_pixel(ctx, pixel, row, col);
        }
    }

    return 0;
}