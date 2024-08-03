void log_frame_details(FrameContext *frame_ctx) {
    FrameDetails *details = frame_ctx->details;
    if (frame_ctx == NULL) {
        printf("Frame context is null.\n");
        return;
    }
    // Use frame_ctx for logging
    printf("Frame number: %d\n", frame_ctx->frame_number);
    printf("Resolution: %dx%d\n", details->width, details->height);
    printf("Bitrate: %dkbps\n", details->bitrate);
    for (int i = 0; i < frame_ctx->layers; ++i) {
        printf("Layer %d bitrate: %dkbps\n", i, details->layer_bitrates[i]);
    }
}