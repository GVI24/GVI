void configure_video_dimensions(int width, int height, struct VideoContext *ctx) {
    // Vulnerability: No check to ensure width and height are within acceptable ranges.
    ctx->width = width;
    ctx->height = height;
    if (ctx->width * ctx->height > MAX_VIDEO_RESOLUTION) {
        printf("Error: Video resolution is too high!\n");
        exit(1); // Improper way to handle the error; abrupt termination.
    }
}