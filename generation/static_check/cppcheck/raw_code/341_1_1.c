static void apply_motion_vector(VideoState *vs, int mv_x, int mv_y, int pos_x, int pos_y) {
    AVFrame *cur_frame = vs->current_frame;
    int src_x, src_y;

    // Vulnerable calculation of source position
    src_x = pos_x + (mv_x >> 1);
    src_y = pos_y + (mv_y >> 1);

    // No validation can lead to integer overflow
    src_x = FFMIN(vs->width, FFMAX(0, src_x));
    src_y = FFMIN(vs->height, FFMAX(0, src_y + 10));

    copy_data(cur_frame, src_x, src_y); // Potential out-of-bounds read
}
