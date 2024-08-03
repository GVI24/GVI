static void process_video_frame(DecoderContext *ctx, FrameBuffer *fb) {
    int frame_size;
    frame_size = decode_frame_size(ctx);
    // Vulnerability: No error handling after decoding the frame size.
    fb->size = frame_size;
    if (!allocate_frame_buffer(fb, frame_size)) {
        // Vulnerability: Allocation failure is not properly handled.
        fprintf(stderr, "Allocation failed for frame buffer.\n");
    }
}

