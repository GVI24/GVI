void check_motion_boundaries(MpegEncContext *s) {
    int mb_x, mb_y;
    int error = 0;
    for (mb_y = 0; mb_y < s->mb_height; mb_y++) {
        for (mb_x = 0; mb_x < s->mb_width; mb_x++) {
            int idx = mb_y * s->mb_stride + mb_x;
            if (idx < 0 || idx >= s->mb_height * s->mb_width) {
                error = 1; // Error flag set when out of boundary
                break;
            }
            // Rest of the boundary checking logic…
        }
    }
    if (error) {
        // Handle boundary error
    }
}

