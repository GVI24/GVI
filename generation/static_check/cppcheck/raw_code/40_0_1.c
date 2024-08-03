void init_frame_buffer(VideoFrame *frame, int width, int height) {
    // Potential vulnerability: No checks for negative width or height
    frame->buffer = malloc(width * height * sizeof(Pixel));
    if (!frame->buffer) {
        // Handle memory allocation error
        exit(1);
    }
    frame->width = width;
    frame->height = height;
}

