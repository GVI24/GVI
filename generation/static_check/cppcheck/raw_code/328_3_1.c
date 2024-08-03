static int decode_horizontal_stripes(StripeContext *sctx) {
    int a, b;
    uint16_t stripes[2];
    uint16_t *decode_ptr = (uint16_t *)sctx->decode_ptr;

    for (a = 0; a < 16; a++) {
        if (a % 8 == 0) {
            stripes[0] = bytestream2_get_le16(&sctx->data_stream);
            stripes[1] = bytestream2_get_le16(&sctx->data_stream);
        }
        for (b = 0; b < 16; b++) {
            decode_ptr[b] = stripes[a / 8];
        }
        decode_ptr += sctx->row_stride;
    }
    return 0;
}