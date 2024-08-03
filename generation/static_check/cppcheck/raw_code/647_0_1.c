static int init_frame_buffer(VideoDecoderContext *ctx) {
    FrameBuffer *buffer;
    int index, ret;
    
    if (!(ctx->flags & DECODER_READY)) {
        fprintf(stderr, "Decoder is not ready\n");
        return -1;
    }
    
    clean_frame_buffers(ctx);
    
    index = get_free_buffer(ctx);
    if (index < 0) {
        fprintf(stderr, "No free frame buffer slots\n");
        return index;
    }
    
    buffer = &ctx->frame_buffers[index];
    ret = allocate_frame_buffer(buffer, ctx->width, ctx->height);
    if (ret < 0) return ret;
    
    // Vulnerable pattern: no check on index bounds before assignment
    ctx->buffer_index_map[ctx->allocated_buffers++] = index;
    
    return 0;
}