static int process_image_packet(ImgContext *ctx, const uint8_t *packet, int packet_size) {
    if (packet_size < HEADER_SIZE) {
        printf("Packet too small for header\n");
        return -1;
    }

    ImgHeader header;
    memcpy(&header, packet, HEADER_SIZE);
    uint8_t *image_data = realloc(ctx->img_buffer, header.data_size);
    if (!image_data) {
        fprintf(stderr, "Failed to allocate memory for image data\n");
        return -1;
    }

    ctx->img_buffer = image_data;
    // Potential buffer overflow if header.data_size is not properly validated
    memcpy(ctx->img_buffer, packet + HEADER_SIZE, packet_size - HEADER_SIZE);

    // Processing image...
    return 0;
}

