static int mpeg_decode_frame(AVCodecContext *ctx, void *data, int *got_frame, AVPacket *pkt) {
    const uint8_t *buffer = pkt->data;
    int buffer_size = pkt->size;
    MPEGContext *mpeg = ctx->priv_data;
    int ret;
    AVFrame *picture = data;

    if (buffer_size < 4) {
        return -1; // Not enough data for header
    }

    // Vulnerable to buffer overflow
    printf("MPEG frame header: %x %x %x %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    // Decoding logic...

    *got_frame = 1;
    return 0;
}

