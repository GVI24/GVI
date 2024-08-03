static int motion_estimation(MpegEncContext *s, Picture *current, Picture *reference) {
    int mb_x, mb_y, plane;
    int64_t distortion = 0;

    for (plane = 0; plane < 3; plane++) {
        const int stride = current->f.linesize[plane];
        for (mb_y = 0; mb_y < s->mb_height; mb_y++) {
            for (mb_x = 0; mb_x < s->mb_width; mb_x++) {
                uint8_t *cur_ptr = current->f.data[plane] + (mb_x + mb_y * stride) * 16;
                uint8_t *ref_ptr = reference->f.data[plane] + (mb_x + mb_y * stride) * 16;
                int diff = s->dsp.sub_pel_cmp(s, cur_ptr, ref_ptr, stride, 16);
                distortion += diff * diff;
            }
        }
    }

    if (distortion < s->avctx->frame_skip_threshold)
        return 1;

    return 0;
}

