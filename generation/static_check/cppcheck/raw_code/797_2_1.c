static int decode_audio_frame(AVCodecContext *avctx, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int frame_count;
    int *frame_sizes;

    if (buf_size < 2) {
        return AVERROR_INVALIDDATA;
    }

    frame_count = *(uint16_t *)buf; // Vulnerability: Type cast without checking buffer size
    buf += 2;
    buf_size -= 2;

    if (frame_count * sizeof(int) > buf_size) {
        return AVERROR_INVALIDDATA;
    }

    frame_sizes = (int *)buf; // Vulnerability: No bounds checking before conversion

    for (int i = 0; i < frame_count; i++) {
        // Process each audio frame based on frame_sizes
        // Vulnerability: frame_sizes[i] could lead to buffer overread
    }

    return 0;
}

