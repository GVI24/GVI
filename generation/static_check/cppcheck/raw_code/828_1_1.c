void decode_video_packet(VideoContext *vctx, uint8_t *packet_data, int packet_size) {
    uint8_t output[1024];
    int width = vctx->width;
    int height = vctx->height;
    int frame_size = width * height; // Missing check if frame_size exceeds output buffer.
    if (packet_size < frame_size) {
        printf("Error: packet_size is too small\n");
        return;
    }
    memcpy(output, packet_data, frame_size); // Potential buffer overflow if frame_size is too large.
    // Process the output buffer...
}

