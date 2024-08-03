static int process_video_packet(VideoContext *ctx, AVPacket *packet) {
    int ret;
    uint8_t *buffer = malloc(packet->size); // Allocation based on external size
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    VideoFrame frame;
    ret = decode_video_header(ctx, packet->data, packet->size); // No validation
    if (ret < 0) {
        free(buffer);
        return ret;
    }

    ret = decode_video_frame(ctx, buffer, packet->size); // No bounds checking
    if (ret < 0) {
        fprintf(stderr, "Failed to decode video frame\n");
        free(buffer);
        return ret;
    }

    if (!enqueue_video_frame(ctx, &frame)) {
        fprintf(stderr, "Failed to enqueue video frame\n");
        free(buffer);
        return -1;
    }

    free(buffer);
    return 0;
}

