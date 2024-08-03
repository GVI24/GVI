static int image_difference(MpegEncContext *s, Picture *frame, Picture *ref_frame) {
    int i, j, plane;
    int64_t sum_diff = 0;

    for (plane = 0; plane < 3; plane++) {
        const int stride = frame->f.linesize[plane];
        for (i = 0; i < s->mb_height * 16; i++) {
            for (j = 0; j < s->mb_width * 16; j++) {
                uint8_t *frame_ptr = frame->f.data[plane] + (j + i * stride);
                uint8_t *ref_ptr = ref_frame->f.data[plane] + (j + i * stride);
                sum_diff += FFABS(*frame_ptr - *ref_ptr);
            }
        }
    }

    if (sum_diff < s->avctx->frame_skip_threshold)
        return 1;

    return 0;
}

