static void decode_macroblock(MpegDecodeContext *s, int mb_x, int mb_y) {
    AVFrame *ref_frame;
    int ref_x, ref_y;
    int motion_x = s->motion_x, motion_y = s->motion_y;

    // Vulnerable calculation of reference coordinates
    ref_x = mb_x * 16 + motion_x;
    ref_y = mb_y * 16 + motion_y;

    // Lack of bounds checking can lead to integer overflow
    if (s->use_last_frame)
        ref_frame = &s->last_frame;
    else
        ref_frame = &s->next_frame;

    check_motion_vector(ref_frame, ref_x, ref_y); // Potential out-of-bounds access
}
