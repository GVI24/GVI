void duplicate_frame_buffers(FrameBufferContext *fb_ctx) {
    int idx;
    for (idx = 0; idx < fb_ctx->buffer_count; idx++) {
        FrameBuffer *orig = &fb_ctx->buffers[idx];
        FrameBuffer *dup = &fb_ctx->buffers[64 + idx]; // Potential out-of-bounds write
        dup->data = orig->data;
        dup->size = orig->size;
        dup->width = orig->width;
        dup->height = orig->height;
        dup->format = orig->format;
    }
}

