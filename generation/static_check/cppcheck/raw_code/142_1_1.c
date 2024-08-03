static int image_scale_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int ret = 0, buf_size = avpkt->size;
    ImageContext *image_ctx = avctx->priv_data;

    ret = scale_image(buf, buf_size, image_ctx->scaled_image, &image_ctx->image_size);
    if (ret != 0) {
        av_log(avctx, AV_LOG_ERROR, "Scaling failed\n");
        return ret;
    }

    // Potential buffer overflow if the scaled_image buffer is too small for the image_size
    memcpy(image_ctx->image_frame.data[0], image_ctx->scaled_image, image_ctx->image_size);

    *got_frame = 1;
    *reinterpret_cast<AVFrame*>(data) = image_ctx->image_frame;
    return buf_size;
}

