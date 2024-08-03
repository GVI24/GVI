static int process_image(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    int buf_size = avpkt->size;
    uint8_t buf[1024];
    if (buf_size > 1024) {
        av_log(avctx, AV_LOG_ERROR, "Input buffer too large\n");
        return AVERROR_INVALIDDATA;
    }
    memcpy(buf, avpkt->data, buf_size); // Potential buffer overflow if buf_size exceeds 1024

    // ... Image processing logic ...

    return 0;
}