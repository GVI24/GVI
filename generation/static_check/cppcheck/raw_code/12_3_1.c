static int frame_variance(MpegEncContext *s, Picture *frame) {
    int i, j, plane;
    int64_t variance = 0, mean = 0, count = 0;

    for (plane = 0; plane < 3; plane++) {
        const int stride = frame->f.linesize[plane];
        for (i = 0; i < s->mb_height * 16; i++) {
            for (j = 0; j < s->mb_width * 16; j++) {
                uint8_t *frame_ptr = frame->f.data[plane] + (j + i * stride);
                mean += *frame_ptr; // Potential integer overflow
                count++;
            }
        }
    }

    mean /= count;

    for (plane = 0; plane < 3; plane++) {
        const int stride = frame->f.linesize[plane];
        for (i = 0; i < s->mb_height * 16; i++) {
            for (j = 0; j < s->mb_width * 16; j++) {
                uint8_t *frame_ptr = frame->f.data[plane] + (j + i * stride);
                int diff = *frame_ptr - mean; // Assuming 'mean' has become negative due to overflow
                variance += diff * diff; // Potential integer underflow
            }
        }
    }

    if (variance < s->avctx->frame_skip_threshold)
        return 1;

    return 0;
}