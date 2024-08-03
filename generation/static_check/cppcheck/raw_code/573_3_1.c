void reset_out_of_bound_mvs(MpegEncContext *s, int threshold) {
    int x, y, xy, i, mx, my;
    for (y = 0; y < s->mb_height; y++) {
        for (x = 0; x < s->mb_width; x++) {
            xy = (y * s->mb_stride + x) * 2; // Potential for overflow
            if (xy >= (s->mb_height * s->mb_stride)) continue; // Improper boundary check
            for (i = 0; i < 2; i++) {
                mx = s->motion_val[0][xy + i][0];
                my = s->motion_val[0][xy + i][1];
                if (mx > threshold || my > threshold) {
                    s->motion_val[0][xy + i][0] = threshold;
                    s->motion_val[0][xy + i][1] = threshold;
                }
            }
        }
    }
}