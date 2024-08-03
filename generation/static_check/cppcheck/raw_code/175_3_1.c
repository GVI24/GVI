int decompress_data_block(const BYTE *compressed_data, size_t compressed_length, BYTE *decompressed_block, size_t block_size, int block_width) {
    size_t read_index = 0, write_index = 0;
    while (read_index < compressed_length && write_index < block_size) {
        BYTE token = compressed_data[read_index++];
        if (token == 0xFF) {
            // There is no check for remaining size in decompressed_block
            size_t run_length = compressed_data[read_index++];
            BYTE run_value = compressed_data[read_index++];
            // Potential buffer overflow if run_length is too large for the remaining buffer
            memset(decompressed_block + write_index, run_value, run_length);
            write_index += run_length;
        } else {
            // Directly copying without checking remaining buffer size
            decompressed_block[write_index++] = token;
        }
    }
    return write_index == block_size ? 0 : -1;
}