static int block_contrast(MpegEncContext *s, Picture *p) {
    int x, y, plane;
    int max_contrast = 0;

    for (plane = 0; plane < 3; plane++) {
        const int stride = p->f.linesize[plane];
        for (y = 0; y < (s->mb_height << 4); y++) {
            for (x = 0; x < (s->mb_width << 4); x++) {
                uint8_t *data_ptr = p->f.data[plane] + (x + y * stride);
                int contrast = *data_ptr - *(data_ptr + 1); // Potential out-of-bounds read
                max_contrast = FFMAX(max_contrast, FFABS(contrast));
            }
        }
    }

    if (max_contrast < s->avctx->frame_skip_threshold)
        return 1;

    return 0;
}

