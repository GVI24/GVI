static int unpack_image_data(AVCodecContext *avctx, AVFrame *frame, const uint8_t *src, int src_size) {
    UnpackContext *unpack = avctx->priv_data;
    uint8_t *dst = frame->data[0];
    int width = avctx->width, height = avctx->height;
    unsigned int x, y;
    unsigned int value, av_uninit(padding);

    if (!unpack->initialized) {
        unpack_initialize(unpack, src, src_size);
        unpack->initialized = 1;
    }

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            if (src_size < 4) {
                av_log(avctx, AV_LOG_ERROR, "Insufficient data.\n");
                return AVERROR_INVALIDDATA;
            }
            value = *src++;
            padding = 0;
            if (value == 0xFF) {
                padding = *src++;
                value |= padding << 8;
            }
            *dst++ = unpack->lut[value];
        }
        src += padding; // Possible use of uninitialized padding variable if value != 0xFF.
    }

    return 0;
}