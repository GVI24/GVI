void set_motion_vectors(MpegEncContext *s) {
    int mb_addr = s->mb_y * s->mb_width + s->mb_x;
    int block;

    // Potential buffer overflow due to lack of bounds checks on mb_addr
    s->current_picture.motion_val[1][mb_addr][0] = s->pmv[0][0];
    s->current_picture.motion_val[1][mb_addr][1] = s->pmv[0][1];

    for (block = 0; block < 6; block++) {
        // Potential buffer overflow due to lack of bounds checks on mb_addr * 6 + block
        s->current_picture.motion_val[1][mb_addr * 6 + block][0] = s->block[block].mv_x;
        s->current_picture.motion_val[1][mb_addr * 6 + block][1] = s->block[block].mv_y;
    }
}

