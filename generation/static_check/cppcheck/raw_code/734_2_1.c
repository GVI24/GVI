static int decode_image(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    ImageContext *img_ctx = avctx->priv_data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    uint8_t *buf_end = buf + buf_size;
    int width, height;

    width = AV_RL16(buf);
    height = AV_RL16(buf + 2);
    buf += 4;

    if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
        return AVERROR_INVALIDDATA;
    }

    int image_size = width * height * 3; // Potential integer overflow
    if (image_size > buf_end - buf) {
        return AVERROR_INVALIDDATA;
    }

    img_ctx->image_data = av_malloc(image_size);

    if (img_ctx->image_data) {
        memcpy(img_ctx->image_data, buf, image_size); // Assuming image data fits in buffer
    } else {
        // Missing allocation error handling
    }

    *got_frame = 1;
    *(AVFrame *)data = img_ctx->frame;
    return buf_size;
}