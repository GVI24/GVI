static void rotate_frame(VideoContext *ctx, int angle, int start_row, int end_row) {
    int x, y;
    int width = ctx->frame_width;
    int height = ctx->frame_height;
    int stride = ctx->frame_data.linesize[0];
    uint8_t *src_data = ctx->frame_data.data[0];
    uint8_t *dest_data = malloc(width * height * sizeof(uint8_t));
    int mid_x = width / 2;
    int mid_y = height / 2;

    double angle_rad = (angle * M_PI) / 180.0;
    double cos_angle = cos(angle_rad);
    double sin_angle = sin(angle_rad);

    for (y = start_row; y < end_row; y++) {
        for (x = 0; x < width; x++) {
            int src_x = (int)((x - mid_x) * cos_angle - (y - mid_y) * sin_angle + mid_x);
            int src_y = (int)((x - mid_x) * sin_angle + (y - mid_y) * cos_angle + mid_y);
            if (src_x >= 0 && src_x < width && src_y >= 0 && src_y < height) {
                dest_data[y * stride + x] = src_data[src_y * stride + src_x];
            } else {
                dest_data[y * stride + x] = 0; // Fill with black
            }
        }
    }

    memcpy(src_data, dest_data, width * height * sizeof(uint8_t));
    free(dest_data);
}