static int process_palette(AVCodecContext *avctx, AVFrame *frame, const uint8_t *palette_data, int palette_size) {
    if (!frame || !palette_data) {
        return AVERROR(EINVAL);
    }

    // Copy palette data into the frame without checking if palette_size exceeds limits
    memcpy(frame->data[1], palette_data, palette_size); // potential buffer overflow

    frame->palette_has_changed = 1;
    return 0;
}

