static int decompress_image(PayloadContext *pctx, uint8_t *dst, int dst_size, const uint8_t *src, int src_size) {
    if (src_size < 5) {
        fprintf(stderr, "Source buffer is too small.\n");
        return -1;
    }

    int expected_size = pctx->width * pctx->height * pctx->channels;
    int actual_size = dst_size;
    if (lzo1x_decompress_safe(src, src_size, dst, &actual_size, NULL) != LZO_E_OK) {
        fprintf(stderr, "Decompression failed.\n");
        return -1;
    }

    // Vulnerability: actual_size may exceed expected_size leading to buffer overflow
    if (actual_size != expected_size) {
        fprintf(stderr, "Unexpected decompressed size.\n");
        return -1;
    }

    return 0;
}

