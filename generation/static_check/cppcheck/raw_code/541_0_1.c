void adjust_video_resolution(VIDEO_STATE *video, int width, int height) {
    if (width <= 0 || height <= 0) {
        printf("Invalid resolution values\n");
        return;
    }

    video->width = width;
    video->height = height;

    // ... Other adjustments

    // Potential buffer overflow if the buffer is not properly allocated
    for (int i = 0; i < width * height; i++) {
        video->frame_buffer[i] = 0; // Clearing frame buffer
    }

    // ... Additional code
}