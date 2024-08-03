static int decode_frame_metadata(AVCodecContext *avctx, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int metadata_size;

    if (buf_size < 4) {
        return AVERROR_INVALIDDATA; // Not enough data
    }

    metadata_size = *(int *)buf; // Vulnerability: Type cast without checking buffer size
    buf += 4;
    buf_size -= 4;

    if (metadata_size > buf_size) {
        return AVERROR_INVALIDDATA; // Not checking if metadata_size leads to buffer overread
    }

    // Process metadata here...

    return 0;
}

