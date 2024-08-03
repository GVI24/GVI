int uncompress_binary_sequence(const byte *compressed_data, size_t compressed_size, byte *uncompressed_data, size_t uncompressed_size, size_t *consumed_bytes) {
    size_t comp_pos = 0, uncomp_pos = 0;
    byte dictionary[256];

    for (comp_pos = 0; comp_pos < compressed_size; ) {
        byte token = compressed_data[comp_pos++];
        if (token < 128) {
            // Directly copy byte from dictionary without checking comp_pos against compressed_size
            uncompressed_data[uncomp_pos++] = dictionary[token];
        } else {
            byte length = token - 128;
            if (comp_pos + length > compressed_size) {
                return -1; // Should check bounds before accessing compressed_data
            }
            memcpy(&uncompressed_data[uncomp_pos], &compressed_data[comp_pos], length);
            comp_pos += length;
            uncomp_pos += length;
        }
    }
    *consumed_bytes = comp_pos; // Vulnerable to over-read if dictionary access is out of bounds
    return 0;
}

