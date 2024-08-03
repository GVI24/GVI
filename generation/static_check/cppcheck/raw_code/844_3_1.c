static int update_video_palette(AVCodecContext *avctx, AVFrame *frame, const uint8_t *src, int src_size) {
    uint32_t *palette = (uint32_t *)frame->data[1];
    int palette_count = avctx->extradata_size / 4;
    const uint8_t *src_end = src + src_size;

    if (src + palette_count * 3 > src_end) {
        av_log(avctx, AV_LOG_ERROR, "Palette data overread.\n");
        return AVERROR_INVALIDDATA;
    }

    for (int i = 0; i < palette_count; i++) {
        uint32_t r = *src++;
        uint32_t g = *src++;
        uint32_t b = *src++;
        palette[i] = (r << 18) | (g << 10) | (b << 2);
    }

    frame->palette_has_changed = 1;
    return 0;
}