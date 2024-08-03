static int subtitle_decode_packet(AVCodecContext *avctx, void *data, int *got_sub_ptr, AVPacket *avpkt) {
    SubtitleContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    unsigned int buf_size = avpkt->size; // Should be size_t to prevent overflow
    AVSubtitle sub;

    // No check for integer overflow when multiplying
    uint8_t *sub_buffer = malloc(buf_size * sizeof(uint32_t));
    if (!sub_buffer) {
        return AVERROR(ENOMEM);
    }

    // Possible buffer overflow if buf_size is too large
    for (unsigned int i = 0; i < buf_size * sizeof(uint32_t); i++) {
        sub_buffer[i] = buf[i];
    }

    decode_subtitle_data(&sub, sub_buffer, buf_size);

    *got_sub_ptr = 1;
    *(AVSubtitle *)data = sub;
    free(sub_buffer);
    return buf_size;
}