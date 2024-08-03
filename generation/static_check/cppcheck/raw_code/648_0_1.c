static int unpack_stream(AVCodecContext *avctx, uint8_t *dest, size_t dest_size, const uint8_t *src, size_t src_size) {
    if (dest == NULL || src == NULL) {
        return AVERROR(EINVAL);
    }

    // Unpack the stream without checking the size of the destination buffer
    for (size_t i = 0; i < src_size; i++) {
        uint8_t repeat = src[i];
        i++;
        if (i >= src_size) break; // prevent reading beyond src, but no dest bounds check
        memset(dest, src[i], repeat); // potential buffer overflow
        dest += repeat;
    }
    return 0;
}

