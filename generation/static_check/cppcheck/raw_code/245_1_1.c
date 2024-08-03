static int process_video_block_8x8(TextureDecoder *dec) {
    int row, col;
    uint32_t *texture_ptr = (uint32_t*)dec->texture_ptr;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col += 4) { // Writing four pixels at a time
            uint32_t value = read_stream_32bit(&dec->data_stream);
            texture_ptr[col] = texture_ptr[col + 1] = texture_ptr[col + 2] = texture_ptr[col + 3] = value;
        }
        texture_ptr += dec->texture_stride;
    }
    return 0;
}

