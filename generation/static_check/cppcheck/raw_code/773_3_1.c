static int decode_image_block(ImageContext *ictx) {
    int a, b;
    unsigned char block_colors[4];
    bytestream2_get_buffer(&ictx->block_stream, block_colors, 4);

    for (a = 0; a < 8; a++) {
        uint64_t block_flag = bytestream2_get_le64(&ictx->block_stream);
        for (b = 0; b < 8; b++, block_flag >>= 2) {
            ictx->image_data[a * ictx->image_width + b] = block_colors[block_flag & 0x03];
        }
    }
    return 0;
}