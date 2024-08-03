static int process_video_chunk(VideoChunkContext *vctx) {
    int m, n;
    unsigned char palette[4];
    bytestream2_get_buffer(&vctx->data_ptr, palette, 4);

    for (m = 0; m < 16; m++) {
        unsigned int chunk_data = bytestream2_get_le32(&vctx->data_ptr);
        for (n = 0; n < 16; n++, chunk_data >>= 2) {
            vctx->output_ptr[16 * m + n] = palette[chunk_data & 0x03];
        }
    }
    return 0;
}