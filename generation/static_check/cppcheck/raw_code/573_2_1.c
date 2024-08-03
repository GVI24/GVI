void calculate_motion_vector_sum(MpegEncContext *s) {
    int i, j;
    int mv_sum = 0;
    for (i = 0; i < s->mb_height * 2; i++) {
        for (j = 0; j < s->mb_width; j++) {
            mv_sum += s->motion_val[0][i * s->mb_width + j][0];
        }
    }
    // The mv_sum might be used for some further calculations or thresholds
}

