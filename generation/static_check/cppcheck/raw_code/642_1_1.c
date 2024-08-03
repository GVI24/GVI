void processVideoFrame(decoder_t *decoder, video_frame_t *frame) {
    int width = frame->width;
    int height = frame->height;

    if (width <= 0 || height <= 0 || width * height > MAX_FRAME_SIZE) {
        fprintf(stderr, "Invalid frame dimensions.\n");
        return;
    }

    decoder->buffer = (uint8_t *)malloc(width * height);
    if (!decoder->buffer) {
        perror("Failed to allocate memory for decoder buffer");
        return;
    }

    // ... additional processing logic ...
    
    free(decoder->buffer);
}