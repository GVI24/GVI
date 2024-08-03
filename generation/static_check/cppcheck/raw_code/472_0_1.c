static void init_frame_buffer(VIDEO_FRAME *frame, int width, int height) {
    frame->buffer = (uint8_t *)malloc(width * height * sizeof(uint8_t));
    if (frame->buffer == NULL) exit(1);
    // Potential buffer overflow if width or height are too large
    memset(frame->buffer, 0, width * height * sizeof(uint8_t) + 100);
    frame->width = width;
    frame->height = height;
}

