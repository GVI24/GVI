void copy_macroblock_data(DecoderContext *dec, int16_t (*block_data)[64]) {
    int offset_x = dec->mb_offset_x * 16;
    int offset_y = dec->mb_offset_y * 16;
    int line_size = dec->decoded_frame.line_size[0];
    uint8_t *buffer = dec->decoded_frame.data[0];

    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            int idx = (offset_y + y) * line_size + offset_x + x;
            buffer[idx] = block_data[y / 4][x / 4]; // Assuming a 4x4 blocks within a macroblock
        }
    }
}

