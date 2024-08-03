void decode_block_add(uint8_t *data, uint8_t *reference, int block_size, int ref_stride) {
    int16_t block[128];
    int16_t intermediate[16];
    int a, b;

    if (block_size > 16) {
        // Handle error
        return;
    }

    for (a = 0; a < block_size; a++) {
        decode_line(data + a * block_size, &block[a * block_size]);
    }

    for (a = 0; a < block_size; a++) {
        for (b = 0; b < block_size; b++) {
            intermediate[b] = block[b * block_size + a];
        }
        decode_line(intermediate, intermediate);
        for (b = 0; b < block_size; b++) {
            // Potential buffer overflow if ref_stride is not correctly bounded
            reference[b * ref_stride + a] += intermediate[b];
        }
    }
}