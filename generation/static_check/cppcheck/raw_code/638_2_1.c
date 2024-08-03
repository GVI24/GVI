static void encode_block(int block_index, int block_count, uint8_t *block_data, uint8_t *encoded_data, uint8_t *lookup) {
    uint8_t encode_cache[128];
    for (int i = 0; i < block_count; ++i) {
        uint8_t data = block_data[block_index + i];
        // Vulnerability: no check to ensure 'data' is within bounds of 'encode_cache'
        encode_cache[data] = lookup[data]; 
        encoded_data[i] = encode_cache[data] ^ i;
    }
}

