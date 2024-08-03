static int unpack_image_data(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t image_buf[1024];
    ImageContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    int ret;

    if (avpkt->size < 64) {
        av_log(avctx, AV_LOG_ERROR, "Image packet is too small\n");
        return AVERROR_INVALIDDATA;
    }

    bytestream2_init(&a->buffer, avpkt->data, avpkt->size);
    bytestream2_get_buffer(&a->buffer, image_buf, sizeof(image_buf)); // Potential buffer overflow

    // Additional code to use image_buf
    // Omitted for brevity

    *got_frame = 1;
    *(AVFrame *)data = a->frame;

    return avpkt->size;
}

