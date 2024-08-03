static int decode_subtitles(AVCodecContext *avctx, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int sub_count, i;

    if (buf_size < 1) {
        return AVERROR_INVALIDDATA;
    }

    sub_count = *buf++;
    buf_size--;

    for (i = 0; i < sub_count; i++) {
        int sub_length, sub_offset;

        if (buf_size < 2) {
            return AVERROR_INVALIDDATA;
        }

        sub_offset = *(uint16_t *)buf; // Vulnerability: No bounds checking on sub_offset
        buf += 2;
        buf_size -= 2;

        if (sub_offset >= buf_size) {
            return AVERROR_INVALIDDATA;
        }

        // Assuming a terminating null byte for subtitle text
        sub_length = strlen((char *)buf + sub_offset); // Vulnerability: Potential buffer overread

        // Process subtitles here...
    }

    return 0;
}

