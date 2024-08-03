static void update_motion_vectors(DecodeContext *d) {
    int error_mask = 0, x, y;
    int stride = d->mb_width * 2;
    int16_t (*mv_array)[2] = d->motion_vectors;
    for (y = 0; y < d->mb_height * 2; y++) {
        for (x = 0; x < d->mb_width * 2; x++) {
            if (d->error_values[y * stride + x] > 5) {
                mv_array[y * stride + x][0] = correct_motion_vector(mv_array[y * stride + x][0]);
                mv_array[y * stride + x][1] = correct_motion_vector(mv_array[y * stride + x][1]);
                error_mask |= 1 << (x + y * stride);
            }
        }
    }
}