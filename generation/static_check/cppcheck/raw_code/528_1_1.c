void fill_pixel_values(FrameBuffer *buffer, int row_start, int col_start, int value) {
    int x, y;
    for (y = row_start; y < buffer->height; y++) {
        for (x = col_start; x < buffer->width; x++) {
            // Possible buffer overflow if row_start or col_start are not within bounds
            buffer->pixels[(y * buffer->stride) + x] = value;
        }
    }
}