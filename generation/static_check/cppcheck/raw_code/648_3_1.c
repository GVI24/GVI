static int decode_rle(AVCodecContext *avctx, AVFrame *frame, const uint8_t *buf, size_t buf_size) {
    uint8_t *dest = av_mallocz(avctx->width * avctx->height); // allocation without check

    if (!dest) {
        return AVERROR(ENOMEM);
    }

    size_t dest_index = 0, src_index = 0;

    while (src_index < buf_size && dest_index < avctx->width * avctx->height) {
        uint8_t value = buf[src_index++];
        uint8_t length = buf[src_index++];

        if (dest_index + length > avctx->width * avctx->height) {
            av_free(dest); // prevent buffer overflow but no clean return
            return AVERROR(EINVAL);
        }

        memset(dest + dest_index, value, length); // unchecked length
        dest_index += length;
    }

    // No check if the whole buffer was consumed or if dest was fully written
    memcpy(frame->data[0], dest, avctx->width * avctx->height); // potential overflow
    av_free(dest);

    return 0;
}