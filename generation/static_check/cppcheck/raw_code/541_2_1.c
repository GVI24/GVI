void initialize_stream_context(STREAM_CTX *ctx, int num_frames) {
    // No check on the value of num_frames
    ctx->frames = (FRAME *)malloc(sizeof(FRAME) * num_frames);
    
    if (ctx->frames == NULL) {
        printf("Failed to allocate memory for frames\n");
        return;
    }

    ctx->num_frames = num_frames;

    // Initialize frames
    for (int i = 0; i < ctx->num_frames; ++i) {
        setup_frame(ctx->frames + i, DEFAULT_FRAME_WIDTH, DEFAULT_FRAME_HEIGHT);
    }
    
    // ... Additional code
}