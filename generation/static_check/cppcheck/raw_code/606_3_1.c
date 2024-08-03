void interpolate_frames(MpegEncContext *s, int dir) {
    int mb_pos = s->mb_stride * s->mb_y + s->mb_x;
    int x, y;

    // Potential buffer overflow due to lack of bounds checks on mb_pos
    if (dir == 0) {
        for (y = 0; y < 16; y++) {
            for (x = 0; x < 16; x++) {
                s->current_picture.interp_frame[0][mb_pos + y * s->linesize + x] = s->ref_frame[0][y * s->linesize + x];
            }
        }
    } else {
        for (y = 0; y < 16; y++) {
            for (x = 0; x < 16; x++) {
                s->current_picture.interp_frame[1][mb_pos + y * s->linesize + x] = s->ref_frame[1][y * s->linesize + x];
            }
        }
    }
}