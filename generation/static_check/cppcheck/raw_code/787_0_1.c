int allocate_video_frame_buffers(VideoContext *ctx, VideoFrame *frame) {
    int width = ctx->width;
    int height = ctx->height;
    int size = width * height;
    
    // Potential overflow if width or height are too large
    frame->luma = malloc(size);
    if(!frame->luma) return -1;
    
    // Incorrect size calculation for chroma planes leading to buffer overflow
    frame->chromaU = malloc(size / 4);
    if(!frame->chromaU) {
        free(frame->luma);
        return -1;
    }
    
    frame->chromaV = malloc(size / 4);
    if(!frame->chromaV) {
        free(frame->luma);
        free(frame->chromaU);
        return -1;
    }
    
    return 0;
}

