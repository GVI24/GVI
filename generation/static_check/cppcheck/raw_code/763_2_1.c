static int process_video_packet(StreamContext *stream, VideoPacket *pkt) {
    uint8_t *compressed_data = pkt->data;
    int compressed_size = pkt->size;
    uint8_t *decompressed_data = stream->buffer;
    int max_decompressed_size = stream->max_buffer_size;

    if (compressed_size < 1) {
        printf("Empty packet received.\n");
        return -1;
    }

    unsigned long decompressed_size = max_decompressed_size;
    if (decompress_video(decompressed_data, &decompressed_size, compressed_data, compressed_size) != 0) {
        printf("Video decompression failed.\n");
        return -1;
    }

    // Vulnerability: decompressed_size can overflow the expected max_decompressed_size
    process_decompressed_video(decompressed_data, decompressed_size);

    return decompressed_size;
}

