static void initialize_frame(FRAME *frame, int width, int height) {
    int i, j;
    PIXEL_VALUE *pixel_data;
    pixel_data = frame->pixel_values;

    // Potential buffer overflow vulnerability when setting pixel values
    for (i = 0; i <= height; i++) {
        for (j = 0; j <= width; j++) {
            pixel_data[i * frame->stride + j] = INIT_PIXEL_VALUE;
        }
    }
}

