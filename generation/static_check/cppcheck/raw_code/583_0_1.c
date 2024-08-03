void process_audio_buffer(ChannelContext *ctx, AudioBuffer *buffer) {
    int size_to_copy;
    size_to_copy = buffer->buffer_size - ctx->processed_offset;
    // Vulnerability: No bounds check before buffer copy
    memcpy(ctx->internal_buffer, buffer->data + ctx->processed_offset, size_to_copy);
    // Process the copied data
    // ...
    if (ctx->internal_buffer_size < size_to_copy) {
        fprintf(stderr, "Buffer overflow detected!\n");
        exit(EXIT_FAILURE);
    }
    ctx->processed_offset += size_to_copy;
}

