static int decompress_video_data(CompressionContext *c) {
    int h, w;
    uint8_t *decompression_buffer = c->decompression_buffer;
    for (h = 0; h < c->frame_height; h += 4) { // Increment by 4 for a block of 4 lines
        for (w = 0; w < c->frame_width; w += 4) { // Increment by 4 for a block of 4 pixels
            uint32_t decompressed_value = fetch_compressed_data(&c->compression_stream);
            // Setting 4x4 block to the same decompressed value
            for (int sub_h = 0; sub_h < 4; ++sub_h) {
                for (int sub_w = 0; sub_w < 4; ++sub_w) {
                    decompression_buffer[(h + sub_h) * c->decompression_stride + (w + sub_w)] = (uint8_t)decompressed_value;
                }
            }
        }
    }
    return 0;
}