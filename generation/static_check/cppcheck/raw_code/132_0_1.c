void apply_filter_to_frame(FrameContext *fc, int16_t (*coefficients)[64]) {
    VideoContext *vc = &fc->vctx;
    int stride = fc->current_frame.stride[0];
    uint8_t *dest = fc->current_frame.data[0] + (vc->frame_y * stride * 16) + vc->frame_x * 16;

    for (int i = 0; i < 64; i++) {
        int index = (vc->frame_y + i / 8) * stride + (vc->frame_x + i % 8);
        dest[index] = coefficients[0][i];
    }
}

