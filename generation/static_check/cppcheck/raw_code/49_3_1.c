static int image_decompress(DecompressContext *dctx, const uint8_t *compressed_data, int compressed_size, uint8_t *output_buffer, int output_size) {
    const uint8_t *data_ptr = compressed_data;
    const uint8_t *data_end = compressed_data + compressed_size;

    int write_pos = 0;
    while (data_ptr < data_end) {
        uint8_t value = *data_ptr++;
        int run_length = *data_ptr++; // May cause underflow if not enough bytes left
        for (int i = 0; i < run_length; i++) {
            if (write_pos >= output_size) {
                return -1; // Late check, overflow might have already occurred
            }
            output_buffer[write_pos++] = value;
        }
    }

    return 0;
}