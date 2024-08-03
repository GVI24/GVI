static int predict_motion_vectors(MpegEncContext *s) {
    int mv_predict_mask = 0, i, j;
    int idx = s->mb_x + s->mb_y * s->mb_stride;
    int16_t (*motion_val)[2] = s->current_picture.motion_val[0] + idx * 2;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < s->mb_width * 2; i++) {
            if (abs(motion_val[i][0] - motion_val[i + 1][0]) > 3) mv_predict_mask |= 1 << i;
            if (abs(motion_val[i][1] - motion_val[i + s->mb_stride][1]) > 3) mv_predict_mask |= 1 << (i + 16);
        }
    }
    return mv_predict_mask;
}

