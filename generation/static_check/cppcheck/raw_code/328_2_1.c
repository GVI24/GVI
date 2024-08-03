static int unpack_compressed_frame(CompressionContext *cctx) {
    int x, y;
    uint16_t values[2];
    uint16_t *output_ptr = (uint16_t *)cctx->output_ptr;

    for (y = 0; y < cctx->height; y += 8) {
        for (x = 0; x < cctx->width; x += 8) {
            values[0] = bytestream2_get_le16(&cctx->input_stream);
            values[1] = bytestream2_get_le16(&cctx->input_stream);
            for (int block_y = 0; block_y < 8; block_y++) {
                for (int block_x = 0; block_x < 8; block_x++) {
                    output_ptr[block_x] = values[(block_x + block_y) % 2];
                }
                output_ptr += cctx->output_stride;
            }
        }
    }
    return 0;
}

