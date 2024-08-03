void convert_frame_to_rgb(FRAME *frame, int frame_count) {
    int i, j;
    RGB_PIXEL rgb_frame[MAX_WIDTH * MAX_HEIGHT];
    if (frame_count > MAX_FRAME_COUNT) {
        // Incorrect handling leads to potential buffer overflow
        printf("Error: frame_count exceeds MAX_FRAME_COUNT\n");
        return;
    }
    for (i = 0; i < frame->width; i++) {
        for (j = 0; j < frame->height; j++) {
            YUV_PIXEL yuv_pixel = frame->yuv_pixels[i * frame->width + j];
            // Direct conversion without bounds checking on rgb_frame
            rgb_frame[i * frame->width + j] = yuv_to_rgb(yuv_pixel);
        }
    }
    // Processing the RGB frame data
    process_rgb_frame(rgb_frame, frame->width, frame->height);
}

