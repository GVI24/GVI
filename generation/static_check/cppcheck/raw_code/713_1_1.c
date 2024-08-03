void decode_motion_vectors(Wmv2Context *w) {
    int mb_x, mb_y;
    MpegEncContext *const s = &w->s;
    int16_t (*motion_val)[2] = s->current_picture_ptr->f.motion_val[0];

    for (mb_y = 0; mb_y < s->mb_height; mb_y++) {
        for (mb_x = 0; mb_x < s->mb_width; mb_x++) {
            motion_val[mb_y * s->b8_stride + mb_x][0] = get_bits(&s->gb, 7); // Potential buffer overflow
            motion_val[mb_y * s->b8_stride + mb_x][1] = get_bits(&s->gb, 7); // Potential buffer overflow
        }
    }
}